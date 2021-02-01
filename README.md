
# LEOPARD

---

## Project LEOPARD Description

Project LEOPARD is a CubeSat project developed by the University of Cincinnati CubeCats, a student-led organization designed to give students hands-on engineering experience with space systems. LEOPARD stands for Low Earth Orbit Project for Aerospace Research and Development.

LEOPARD is a research project to determine the efficacy of various materials of radiation mitigation in the space environment. It uses 8 RADFET radiation sensors shielded with carbon-carbon composites, polyethylene and carbon-carbon, or unshielded to determine the effect of these materials on radiation protection over time.

This repository is used for the main computing system of the satellite. It is intended to run on an Arduino Uno R3. This repository includes the arduino sketch; for the libraries used in LEOPARD, please check out the [LEOPARD libraries repository](https://github.com/uccubecats/libraries).

## Setting Up Your Development Environment

The following steps should get you set up with a dev environment:

### Download Software

* [Git](https://git-scm.com/downloads)
* [Arduino IDE](https://www.arduino.cc/en/Main/Software?)
* [Visual Studio Code](https://code.visualstudio.com/download)
* [VSCode Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)
* [VSCode C++ Extension](https://code.visualstudio.com/docs/languages/cpp)

### Pull This Repo

This repo should be pulled into your root Arduino directory set when you installed the Arduino IDE, where Arduino sketches are located. For Macs, this would be `/Users/$(AppleID)/Documents/Arduino/`. For Windows, this would be `C:\Program Files (x86)\Arduino\`.

### Configure VSCode Settings

Once you open this directory in VSCode, you will need to configure settings before you are ready to begin. There should be a .vscode/ directory already created in your base directory. In it, edit the following documents (or create them if they do not yet exist):

1. `arduino.json`

    Add or modify the configuration to match the following:

    ```json
    {
        "board": "arduino:avr:uno",
        "sketch": "LEOPARD.ino",
        "port": "/dev/cu.usbmodem1421",
        "output": "$(YourDir)"
    }
    ```

   where $(YourDir) is the relative path where build information should be located.

2. `settings.json`

    On the right hand side of the file, add the following configuration:

    ```json
    {
        "C_Cpp.intelliSenseEngine": "Tag Parser",
        "C_Cpp.default.cppStandard": "c++11",
        "C_Cpp.default.browse.path": [
            "$(WorkingDir)/libraries"
        ],
    }
    ```

    where $(WorkingDir) is the directory for your LEOPARD repo.
    If you are on a Mac, include the following line as well:

    ```json
    {
        "clang.cxxflags": [
            "-std=c++11"
        ],
    }
    ```

    If you are on a PC, include the following line as well:

    ```json
    {
        "arduino.path": "$(ArduinoIDEPath)"
    }
    ```

## Team Roster

| Member | Position |
| --- | --- |
| Todd Herron | Lead Software Engineer |
| Sarah Hudson | Software Engineer |
| Ryan Hardy | Software Engineer