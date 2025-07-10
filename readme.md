# Installation

## Prerequisites

- **Ubuntu 22.04 or similar Linux distribution**
- **C++ compiler** (g++)
- **Qt6 development libraries** (or Qt5, see notes below)
- **Git** (if you want to clone the repository)

## 1. Install Required Packages

Open a terminal and run:

```bash
sudo apt-get update
sudo apt-get install build-essential git qt6-base-dev qt6-base-dev-tools qt6-tools-dev qt6-tools-dev-tools qttools5-dev-tools
```

> **Note:**  
> - `qttools5-dev-tools` is needed for the `lrelease` tool, which is missing from the Qt6 packages in Ubuntu 22.04.
> - If you want to use Qt5 instead, install `qtbase5-dev qttools5-dev qttools5-dev-tools` and use `qmake` instead of `qmake6`.

## 2. Clone the Repository

```bash
git clone https://github.com/rlcancian/Genesys-Simulator.git
cd Genesys-Simulator/source/applications/gui/qt/GenesysQtGUI
```

## 4. Configure the Project

```bash
qmake GenesysQtGUI.pro
```
> If you are using Qt5, use `qmake GenesysQtGUI.pro` instead.

## 5. Build the Project

```bash
make
```

## 6. Run the Application

After building, you should find the executable in the current directory or a `build` subdirectory. Run it with:

```bash
./GenesysQtGUI
```
