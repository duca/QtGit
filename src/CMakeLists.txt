set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

qt5_add_resources(QT_RESOURCES QtGit.qrc)

add_executable(QtGit
    main.cpp    
    logModel.cpp
    logModel.hpp
    logController.cpp
    logController.hpp
    ${PROJECT_SOURCE_DIR}/${TS_FILES}
    ${QT_RESOURCES}
    )

target_include_directories(QtGit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include/QtGit>  # <prefix>/include/QtGit
)

find_package(QT NAMES Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

target_link_libraries(QtGit PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Qml Qt${QT_VERSION_MAJOR}::Quick ssh2 ssl cppgit2 git2)
