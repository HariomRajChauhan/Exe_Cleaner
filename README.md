# EXE Cleaner - Executable File Management Tools

A comprehensive set of **executable file cleaners** written in C++, designed to help developers and system administrators manage and clean up executable files in their directories and subdirectories.

## 🚨 Problem Statement

### When Do You Need This?

1. **Development Environment Cleanup**: After building multiple C++ projects, your directories become cluttered with compiled `.exe` files
2. **Build Artifact Management**: Cleaning up temporary executables from various build processes
3. **Storage Management**: Removing old executable files to free up disk space
4. **Project Organization**: Maintaining clean project directories by removing unnecessary compiled binaries
5. **Security Cleanup**: Removing potentially unwanted executable files from downloaded or extracted archives
6. **CI/CD Pipeline Cleanup**: Automated cleanup in continuous integration environments

### Real-World Scenarios

- **Student Projects**: After coding multiple assignments, your folder is filled with `hello.exe`, `calculator.exe`, `assignment1.exe`, etc.
- **Multiple Build Configurations**: Debug and Release builds create multiple copies of executables
- **Downloaded Software**: Extracting archives often leaves behind multiple executable files
- **Legacy Project Cleanup**: Old projects with numerous compiled binaries that are no longer needed

## 🛠️ Available Tools

### 1. **Automatic Cleaner (`cexe.exe`)**

- **Purpose**: Automatically deletes ALL `.exe` files recursively (except itself)
- **Use Case**: When you want to quickly clean everything without manual selection
- **Risk Level**: ⚠️ **HIGH** - Deletes everything automatically

### 2. **Selective Cleaner (`csexe.exe`)**

- **Purpose**: Interactive tool that lets you choose which `.exe` files to delete
- **Use Case**: When you need precise control over what gets deleted
- **Risk Level**: ✅ **LOW** - User has full control with confirmation

## 🚀 How to Use

### Quick Commands

```powershell
# For automatic cleanup (USE WITH CAUTION!)
.\cexe.exe

# For selective cleanup (RECOMMENDED)
.\csexe.exe
```

### Automatic Cleaner Workflow

1. Run `.\cexe.exe`
2. Tool automatically scans current directory and ALL subdirectories
3. Finds all `.exe` files (except `cexe.exe` itself)
4. Deletes them immediately
5. Shows completion status

### Selective Cleaner Workflow

1. Run `.\csexe.exe`
2. Tool scans and displays all `.exe` files with numbers
3. Choose your deletion method:
   - Type `all` to delete everything
   - Type specific numbers: `1 3 5 8` to delete selected files
   - Press Enter to cancel
4. Confirm your selection (y/N)
5. Tool deletes selected files with detailed feedback

## 📋 Features

### Automatic Cleaner Features

- ✅ Recursive directory scanning
- ✅ Self-preservation (won't delete itself)
- ✅ PowerShell integration for reliable file operations
- ✅ Error handling and status reporting
- ✅ Cross-directory cleanup

### Selective Cleaner Features

- ✅ Interactive file selection
- ✅ Numbered list display with full paths
- ✅ Batch selection support (`1 3 5 7`)
- ✅ "Delete all" option
- ✅ Confirmation prompts for safety
- ✅ Detailed deletion feedback
- ✅ Input validation and error handling
- ✅ Operation cancellation support

## ⚠️ Safety Considerations

### Before Using Automatic Cleaner

- **BACKUP IMPORTANT FILES**: This tool deletes files permanently
- **Review Directory Contents**: Make sure no important executables are present
- **Test in Safe Environment**: Try in a test folder first
- **Administrator Rights**: May need elevated permissions for some directories

### Before Using Selective Cleaner

- **Review File List**: Carefully check the displayed files before selection
- **Understand Full Paths**: Pay attention to where files are located
- **Use Confirmation**: The tool asks for confirmation - read it carefully

## 🔧 Technical Details

### System Requirements

- **OS**: Windows (uses PowerShell commands)
- **Compiler**: Any C++ compiler (g++, MSVC, etc.)
- **Permissions**: May require administrator rights for system directories

### How It Works

1. **PowerShell Integration**: Uses `Get-ChildItem` with `-Recurse` flag
2. **File Filtering**: Filters for `*.exe` files only
3. **Self-Protection**: Excludes the running executable from deletion
4. **Error Handling**: Captures and reports system command results

### Building from Source

```powershell
# For automatic cleaner
g++ cexe.cpp -o cexe.exe

# For selective cleaner
g++ csexe.cpp -o csexe.exe
```

## 📊 Use Cases and Examples

### Example 1: Student Development Cleanup

```text
Before:
├── assignment1.exe
├── assignment2.exe
├── calculator.exe
├── hello_world.exe
├── project_final.exe
└── important_source.cpp

After automatic cleanup:
└── important_source.cpp
```

### Example 2: Selective Project Cleanup

```text
Found executables:
1. debug_version.exe
2. release_version.exe
3. old_backup.exe
4. current_project.exe

Selection: "1 3" (delete debug and backup versions)
Result: Keeps release_version.exe and current_project.exe
```

## 🚀 Advanced Usage

### Integration with Build Scripts

```powershell
# Clean before build
.\cexe.exe
# Your build commands here
make all
```

### Scheduled Cleanup

```powershell
# Add to Windows Task Scheduler for periodic cleanup
schtasks /create /tn "EXE_Cleanup" /tr "C:\path\to\cexe.exe" /sc weekly
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Test your changes thoroughly
4. Submit a pull request

## 📜 License

Open source - feel free to modify and distribute

## ⚡ Quick Reference

| Command | Purpose | Risk Level | Recommended For |
|---------|---------|------------|-----------------|
| `cexe.exe` | Auto-delete all exe files | HIGH ⚠️ | Experienced users, clean environments |
| `csexe.exe` | Interactive selective deletion | LOW ✅ | Everyone, production environments |

---

**Remember**: Always backup important files before running any cleanup tool! 🔒