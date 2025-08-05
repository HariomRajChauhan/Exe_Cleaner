# 📦 EXE Cleaner Releases

## Latest Release - v1.0.0 (August 2025)

🎉 **Initial Release** - Complete EXE File Management Solution

It is an **executable file cleaner**, written in C++.
We can write the command in the terminal and then enjoy, this will do that itself.

### What's New

- ✨ **Automatic Cleaner (`cexe.exe`)** - One-click recursive cleanup of all executable files
- ✨ **Selective Cleaner (`csexe.exe`)** - Interactive tool for precise file management
- 🔒 **Self-Protection** - Tools won't delete themselves during cleanup
- 📊 **Detailed Feedback** - Real-time deletion progress and error reporting
- 🎯 **Batch Operations** - Select multiple files with space-separated numbers
- ⚡ **PowerShell Integration** - Reliable file operations across Windows systems

### Download Options

| Tool | Description | Download | Size |
|------|-------------|----------|------|
| `cexe.exe` | Automatic cleaner (High-risk, fast cleanup) | [Download](../../releases/latest/download/cexe.exe) | ~50KB |
| `csexe.exe` | Interactive cleaner (Safe, user-controlled) | [Download](../../releases/latest/download/csexe.exe) | ~75KB |
| **Complete Package** | Both tools + source code | [Download ZIP](../../archive/refs/heads/main.zip) | ~25KB |

### Quick Start

> `.\cexe` or `cexe` - Automatic cleanup (USE WITH CAUTION!)
>
> `.\csexe` or `csexe` - Interactive cleanup (RECOMMENDED)

```powershell
# Download and run automatic cleaner (USE WITH CAUTION!)
.\cexe.exe

# Or use the safer interactive cleaner (RECOMMENDED)
.\csexe.exe
```

### Release Requirements

- **OS**: Windows 7/8/10/11
- **Architecture**: x64/x86
- **Dependencies**: PowerShell (pre-installed on Windows)
- **Permissions**: Standard user (Admin for system directories)

### What's Fixed/Improved

- 🐛 Fixed recursive scanning in deeply nested directories
- 🛡️ Enhanced self-protection mechanism
- 📝 Improved error messages and user feedback
- 🎨 Better console output formatting
- ⚠️ Added confirmation prompts for safety

### Known Issues

- May require administrator privileges for system directories
- PowerShell execution policy restrictions may apply
- Large directories (1000+ files) may take longer to scan

### Verification

```powershell
# Verify file integrity (optional)
Get-FileHash cexe.exe -Algorithm SHA256
Get-FileHash csexe.exe -Algorithm SHA256
```

### Source Code

Build from source using any C++ compiler:

```powershell
# Clone repository
git clone https://github.com/HariomRajChauhan/Exe_Cleaner.git
cd Exe_Cleaner

# Compile automatic cleaner
g++ cexeho.cpp -o cexe.exe

# Compile selective cleaner  
g++ selective_exe_cleaner.cpp -o csexe.exe
```

**Full Changelog**: <https://github.com/HariomRajChauhan/Exe_Cleaner/commits/main>

---

## Previous Releases

This is the initial release - no previous versions available

---

## Installation Guide

### Method 1: Direct Download

1. Go to [Releases](https://github.com/HariomRajChauhan/Exe_Cleaner/releases)
2. Download the latest version
3. Extract to your desired location
4. Run the executable

### Method 2: Build from Source

1. Clone the repository
2. Compile using your preferred C++ compiler
3. Run the generated executable

---

## Support

- **Issues**: [GitHub Issues](https://github.com/HariomRajChauhan/Exe_Cleaner/issues)
- **Discussions**: [GitHub Discussions](https://github.com/HariomRajChauhan/Exe_Cleaner/discussions)
- **Documentation**: [Main README](README.md)

---

**⚠️ Important**: Always backup important files before running any cleanup tool!
