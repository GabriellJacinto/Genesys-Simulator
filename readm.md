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

## 3. Workaround for Missing Qt6 lrelease

Create a symlink so the build system can find `lrelease`:

```bash
sudo mkdir -p /usr/lib/qt6/bin
sudo ln -s /usr/bin/lrelease /usr/lib/qt6/bin/lrelease
```

## 4. Configure the Project

```bash
qmake6 GenesysQtGUI.pro
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

---

## Troubleshooting

- **Missing Qt modules:**  
  If you get errors about missing modules (like `printsupport` or `designer`), remove them from the `QT += ...` line in `GenesysQtGUI.pro` or install the corresponding Qt5 packages.
- **Translation errors:**  
  If you do not need translations, you can comment out or remove the `TRANSLATIONS` line in your `.pro` file.

---

## Docker Alternative

You can also build and run Genesys-Simulator using Docker. See the `docker/README.md` in the repository for details.
