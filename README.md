
# LEOPARD

---

## Setting Up Your Development Environment

The following steps should get you set up with a dev environment:

### Download Software

* [Arduino IDE](https://www.arduino.cc/en/Main/Software?)
* [Visual Studio Code](https://code.visualstudio.com/download)
* [VSCode Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)
* [VSCode C++ Extension](https://code.visualstudio.com/docs/languages/cpp)

### Pull This Repo

This repo should be pulled into your root Arduino directory set when you installed the Arduino IDE. For Macs, this would be `/Users/$(AppleID)/Documents/Arduino/`.

### Configure VSCode Settings

Once you open this directory in VSCode, you will need to configure settings before you are ready to begin. There should be a .vcode/ directory already created in your base directory. In it, edit the following documents (or create them if they do not yet exist):

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
            "$(WorkingDir)/LEOPARD",
            "$(WorkingDir)/LEOPARD/adcs",
            "$(WorkingDir)/LEOPARD/bqJunior",
            "$(WorkingDir)/LEOPARD/hamshield",
            "$(WorkingDir)/LEOPARD/leopard_common",
            "$(WorkingDir)/LEOPARD/payload"
        ],
    }
    ```

    where $(WorkingDir) is the directory for your LEOPARD repo.
    If you are on a mac, include the following line as well:

    ```json
    {
        "clang.cxxflags": [
            "-std=c++11"
        ],
    }
    ```json

## Acknowledgements of Technologies and Softwares Used

Project LEOPARD uses many open-sourced technologies for its development. We have included and/or modified arduino libraries from the following repos:

* [Sparkfun LSM9DS1 Arduino Library](https://github.com/sparkfun/SparkFun_LSM9DS1_Arduino_Library)
* [HamShield](https://github.com/EnhancedRadioDevices/HamShield)
* [Sparkfun 74HC4051 8-Channel Mux](https://github.com/sparkfun/74HC4051_8-Channel_Mux_Breakout)

## Team Roster

| Member | Position |
| --- | --- |
| Grace Gamstetter | Lead Software Engineer |
| Chris Morrison | Software Engineer |
| Wesley Bumpus | Software Engineer |
| Henry Voss | Software Engineer |
| Nathan Brown | Software Engineer |
| Jared Musser | Software Engineer |
