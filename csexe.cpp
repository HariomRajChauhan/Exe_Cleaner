#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct ExeFile
{
    std::string name;
    std::string fullPath;
    int number;
};

std::vector<ExeFile> getExeFiles()
{
    std::vector<ExeFile> exeFiles;

    // PowerShell command to get all .exe files recursively with full paths
    std::string command = "powershell -Command \"Get-ChildItem -Path . -Filter *.exe -Recurse | ForEach-Object { Write-Output $_.FullName }\"";

    // Execute command and capture output
    FILE *pipe = _popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cout << "Error: Could not execute PowerShell command." << std::endl;
        return exeFiles;
    }

    char buffer[512];
    int fileNumber = 1;

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        std::string fullPath = buffer;
        // Remove newline character
        fullPath.erase(std::remove(fullPath.begin(), fullPath.end(), '\n'), fullPath.end());
        fullPath.erase(std::remove(fullPath.begin(), fullPath.end(), '\r'), fullPath.end());

        if (!fullPath.empty())
        {
            // Extract filename from full path
            size_t lastSlash = fullPath.find_last_of("\\");
            std::string fileName = (lastSlash != std::string::npos) ? fullPath.substr(lastSlash + 1) : fullPath;

            ExeFile exeFile;
            exeFile.name = fileName;
            exeFile.fullPath = fullPath;
            exeFile.number = fileNumber++;

            exeFiles.push_back(exeFile);
        }
    }

    _pclose(pipe);
    return exeFiles;
}

void displayExeFiles(const std::vector<ExeFile> &exeFiles)
{
    std::cout << "\n=== EXE FILES FOUND ===" << std::endl;
    std::cout << "No.\tFile Name\t\t\tFull Path" << std::endl;
    std::cout << "---\t---------\t\t\t---------" << std::endl;

    for (const auto &file : exeFiles)
    {
        std::cout << file.number << ".\t" << file.name;

        // Add padding for alignment
        int padding = 24 - file.name.length();
        for (int i = 0; i < std::max(1, padding); i++)
        {
            std::cout << " ";
        }

        std::cout << file.fullPath << std::endl;
    }

    std::cout << "\nTotal files found: " << exeFiles.size() << std::endl;
}

std::vector<int> parseSelection(const std::string &input, int maxFiles)
{
    std::vector<int> selectedNumbers;

    // Check for "all" command
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    if (lowerInput == "all")
    {
        for (int i = 1; i <= maxFiles; i++)
        {
            selectedNumbers.push_back(i);
        }
        return selectedNumbers;
    }

    // Parse individual numbers
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        try
        {
            int num = std::stoi(token);
            if (num >= 1 && num <= maxFiles)
            {
                selectedNumbers.push_back(num);
            }
            else
            {
                std::cout << "Warning: Number " << num << " is out of range (1-" << maxFiles << ")" << std::endl;
            }
        }
        catch (const std::exception &)
        {
            std::cout << "Warning: '" << token << "' is not a valid number" << std::endl;
        }
    }

    // Remove duplicates and sort
    std::sort(selectedNumbers.begin(), selectedNumbers.end());
    selectedNumbers.erase(std::unique(selectedNumbers.begin(), selectedNumbers.end()), selectedNumbers.end());

    return selectedNumbers;
}

void deleteSelectedFiles(const std::vector<ExeFile> &exeFiles, const std::vector<int> &selectedNumbers)
{
    std::cout << "\n=== DELETION PROCESS ===" << std::endl;

    int successCount = 0;
    int failureCount = 0;

    for (int num : selectedNumbers)
    {
        const ExeFile &file = exeFiles[num - 1]; // Convert to 0-based index

        std::cout << "Deleting [" << num << "]: " << file.name << "..." << std::endl;

        // Create PowerShell command to delete specific file
        std::string deleteCommand = "powershell -Command \"Remove-Item '" + file.fullPath + "' -Force\"";

        int result = system(deleteCommand.c_str());

        if (result == 0)
        {
            std::cout << "  ✓ Successfully deleted: " << file.name << std::endl;
            successCount++;
        }
        else
        {
            std::cout << "  ✗ Failed to delete: " << file.name << " (Error code: " << result << ")" << std::endl;
            failureCount++;
        }
    }

    std::cout << "\n=== DELETION SUMMARY ===" << std::endl;
    std::cout << "Successfully deleted: " << successCount << " files" << std::endl;
    std::cout << "Failed to delete: " << failureCount << " files" << std::endl;
}

int main()
{
    std::cout << "=== SELECTIVE EXE FILE CLEANER ===" << std::endl;
    std::cout << "Scanning for .exe files recursively..." << std::endl;

    // Get all exe files
    std::vector<ExeFile> exeFiles = getExeFiles();

    if (exeFiles.empty())
    {
        std::cout << "No .exe files found in current directory and subdirectories." << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        return 0;
    }

    // Display all exe files
    displayExeFiles(exeFiles);

    // Get user selection
    std::cout << "\n=== SELECTION OPTIONS ===" << std::endl;
    std::cout << "• Type 'all' to delete all files" << std::endl;
    std::cout << "• Type specific numbers separated by spaces (e.g., '1 3 4 7 8')" << std::endl;
    std::cout << "• Press Enter without typing anything to cancel" << std::endl;
    std::cout << "\nEnter your selection: ";

    std::string userInput;
    std::getline(std::cin, userInput);

    // Handle empty input (cancel)
    if (userInput.empty())
    {
        std::cout << "Operation cancelled." << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        return 0;
    }

    // Parse user selection
    std::vector<int> selectedNumbers = parseSelection(userInput, exeFiles.size());

    if (selectedNumbers.empty())
    {
        std::cout << "No valid selections made. Operation cancelled." << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        return 0;
    }

    // Show confirmation
    std::cout << "\nYou selected " << selectedNumbers.size() << " file(s) for deletion:" << std::endl;
    for (int num : selectedNumbers)
    {
        std::cout << "  [" << num << "] " << exeFiles[num - 1].name << std::endl;
    }

    std::cout << "\nAre you sure you want to delete these files? (y/N): ";
    std::string confirmation;
    std::getline(std::cin, confirmation);

    if (confirmation == "y" || confirmation == "Y" || confirmation == "yes" || confirmation == "YES")
    {
        deleteSelectedFiles(exeFiles, selectedNumbers);
    }
    else
    {
        std::cout << "Operation cancelled." << std::endl;
    }

    std::cout << "\nPress any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
