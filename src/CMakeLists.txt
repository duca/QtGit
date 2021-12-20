set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(QtGit
    QtGit.qrc
    main.cpp
    mainWindow.cpp
    logModel.cpp
    logModel.hpp
    logController.cpp
    logController.hpp
    stageModel.hpp
    stageModel.cpp
    ${PROJECT_SOURCE_DIR}/${TS_FILES}
    ${QT_RESOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/QtGit/mainWindow.hpp
    )

target_include_directories(QtGit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:include/QtGit>  # <prefix>/include/QtGit
)

find_package(Qt6 COMPONENTS Widgets LinguistTools Quick QuickControls2 REQUIRED)

target_link_libraries(QtGit PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Qml Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2 ssh2 ssl cppgit2 git2)
