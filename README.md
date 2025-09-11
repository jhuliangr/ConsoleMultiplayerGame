# Console Point collector game

### For compiling the game in vscode make the tasks.json to look like this: 

```JSON
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Compile program",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}\\classes\\Player.cpp",
                "${fileDirname}\\globals\\globals.cpp",
                "${fileDirname}\\loop\\loop.cpp",
                "${fileDirname}\\rendering\\render.cpp",
                "${fileDirname}\\utils\\utils.cpp",
                "${fileDirname}\\utils\\colors.cpp",
                "${fileDirname}\\main.cpp",
                "-o",
                "${fileDirname}\\executable.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe build active file",
            "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build",
            "detail": "compiler: C:\\msys64\\ucrt64\\bin\\g++.exe"
        }
    ],
    "version": "2.0.0"
}

```
