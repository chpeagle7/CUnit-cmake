cmake_minimum_required(VERSION 3.17)

project(cunit C)

include_directories(Headers)

configure_file (
        "Headers/CUnit.h.in"
        "${PROJECT_SOURCE_DIR}/Headers/CUnit.h"
)

set (source_files
        Sources/Automated/Automated.c
        Sources/Basic/Basic.c
        Sources/Console/Console.c
        Sources/Framework/CUError.c
        Sources/Framework/TestDB.c
        Sources/Framework/TestRun.c
        Sources/Framework/Util.c
        )

add_library(cunit ${source_files})

install(TARGETS cunit DESTINATION .)
install(DIRECTORY CUnit/Headers/ DESTINATION . FILES_MATCHING PATTERN "*.h")