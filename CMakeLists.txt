cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(OPENSSL_ROOT_DIR  "/opt/Qt/Tools/OpenSSL/binary/")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_C_COMPILER "/usr/bin/clang")

project(QtGit VERSION 1.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.2.0/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS Widgets LinguistTools Quick REQUIRED)

add_subdirectory(ext/cppgit2)
add_subdirectory(src)

set(TS_FILES QtGit_en_US.ts)
# qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
