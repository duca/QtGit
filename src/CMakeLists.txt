set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(QtGit
    brancheswidget.ui
    mainwindow.ui

    include/QtGit/brancheswidget.hpp
    include/QtGit/mainwindow.hpp

    main.cpp
    brancheswidget.cpp
    mainwindow.cpp
    ${PROJECT_SOURCE_DIR}/${TS_FILES}
    )

target_include_directories(QtGit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/QtGit>  # <prefix>/include/QtGit
)

find_package(QT NAMES Qt6 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

target_link_libraries(QtGit PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
