{
    "variables": {
        "build_mode%": "static_library"
    },

    "target_defaults": {
        "default_configuration": "Release",
        "configurations": {
            "Debug": {
                "conditions": [
                    [
                    "build_mode=='shared_library'", {
                        "cflags": ["-Wall", "-g", "-fPIC"]
                    }]
                ]
            },
            "Release": {
                "cflags": ["-Wall"]
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