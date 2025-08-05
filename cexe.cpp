#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    std::cout << "Starting cleanup of all .exe files recursively (except cexeho.exe)..." << std::endl;
    std::cout << "Searching in current directory and all subdirectories..." << std::endl;

    // PowerShell command to find and delete all .exe files recursively, excluding cexeho.exe
    // -Recurse ensures it searches all subdirectories
    std::string command = "powershell -Command \"Get-ChildItem -Path . -Filter *.exe -Recurse | Where-Object {$_.Name -ne 'cexeho.exe'} | ForEach-Object { Write-Host 'Deleting:' $_.FullName; Remove-Item $_.FullName -Force }\"";

    // Execute the command
    int result = system(command.c_str());

    if (result == 0)
    {
        std::cout << "Successfully cleaned all .exe files (except cexeho.exe) from current directory and ALL subdirectories!" << std::endl;
    }
    else
    {
        std::cout << "There was an issue during cleanup. Error code: " << result << std::endl;
    }

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}