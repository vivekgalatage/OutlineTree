{
    "variables": {
        "build_mode%": "static_library"
    },

    "target_defaults": {
        "default_configuration": "Release",
        "configurations": {
            "Debug": {
                "defines": [
                    "DEBUG"
                ],
                "conditions": [
                    [
                    "build_mode=='shared_library'", {
                        "cflags": ["-Wall", "-g", "-fPIC", "-std=c++11"]
                    }]
                ]
            },
            "Release": {
                "defines": [
                    "DEBUG"
                ],
                "cflags": ["-Wall", "-std=c++11"]
            }
        }
    },

    "targets": [
        {
            "target_name": "libotree",
            "type": "<(build_mode)",
            "sources": [
            ]
        },
        {
            "target_name": "otree",
            "type": "executable",
            "sources": [
                "src/app/main.cpp",
                "src/app/CommandLine.cpp"
            ],
            "include_dirs": [
                "src"
            ]
        },
        {
            "target_name": "unitTestRunner",
            "type": "executable",
            "dependencies": [
                "libotree"
            ],
            "sources": [
                "src/testing/TestFramework.cpp",
                "tests/UnitTestRunner.cpp"
            ],
            "include_dirs": [
                "src"
            ]
        }
    ]
}

