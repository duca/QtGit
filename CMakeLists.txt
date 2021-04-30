cmake_minimum_required(VERSION 3.5)

project(QtGit LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_ROOT_DIR  "/opt/Qt/Tools/OpenSSL/binary/")

find_package(Qt5 COMPONENTS Core Quick Qml Widgets)


set(Qt5_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake")
set(Qt5Core_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake")
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

add_subdirectory(ext/cppgit2)

add_subdirectory(src)

set(TS_FILES QtGit_en_US.ts)
# qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
