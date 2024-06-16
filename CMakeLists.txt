cmake_minimum_required(VERSION 3.5)

project(WDS_BASIC VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH "C:/Qt/6.7.0/msvc2019_64")
#set(QT_DIR "C:/Qt/6.7.0/msvc2019_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt6 REQUIRED COMPONENTS Charts)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)
include_directories(/Documents/WDS_BASIC/libs)
include_directories(C:/Windows/system32)
set(TS_FILES translations/WDS_BASIC_pl_PL.ts)
qt_add_lrelease(WDS_BASIC TS_FILES ${TS_FILES})

# add_custom_target(copy_qm_files ALL
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${CMAKE_CURRENT_SOURCE_DIR}/translations/WDS_BASIC_pl_PL.qm
#     ${CMAKE_CURRENT_BINARY_DIR}/translations/WDS_BASIC_pl_PL.qm
# )

#add_dependencies(WDS_BASIC copy_qm_files)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Resources.qrc
        translations/WDS_BASIC_pl_PL.qm
        ${TS_FILES}
)
qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 5) #było 6
    qt_add_executable(WDS_BASIC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${SOURCES}
        ${MOC_SOURCES}
        ${QM_FILES}
        controller.h
        controller.cpp
        libs/comsuppw.lib libs/dxva2.lib
        libs/dxva2.dll
        imgs/dlon.jpg
        Resources.qrc
        imgs/hand.png
        dialog.h dialog.cpp dialog.ui
        achievements.h achievements.cpp achievements.ui
        imgs/cup.jpg
        translations/WDS_BASIC_pl_PL.ts
        translations/WDS_BASIC_pl_PL.qm
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET WDS_BASIC APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# Dodaj translację za pomocą qt_add_lupdate i qt_add_lrelease
    qt_add_lupdate(WDS_BASIC TS_FILES ${TS_FILES})
    qt_add_lrelease(WDS_BASIC TS_FILES ${TS_FILES})

    #qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
    #configure_file({$QM_FILES} ${CMAKE_SOURCE_DIR}COPYONLY)
else()
    if(ANDROID)
        add_library(WDS_BASIC SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(WDS_BASIC
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(WDS_BASIC PUBLIC winmm)
#target_link_libraries(WDS_BASIC PRIVATE comsuppw)
target_link_libraries(WDS_BASIC PUBLIC wbemuuid)
target_link_libraries(WDS_BASIC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/dxva2.lib)
target_link_libraries(WDS_BASIC PUBLIC dxva2)
target_link_libraries(WDS_BASIC PRIVATE kernel32)
target_link_libraries(WDS_BASIC PRIVATE Qt6::Charts)
target_link_libraries(WDS_BASIC PRIVATE Qt6::SerialPort)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.WDS_BASIC)
endif()
set_target_properties(WDS_BASIC PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS WDS_BASIC
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WDS_BASIC)
endif()
