cmake_minimum_required(VERSION 3.5)

project(NedoRello VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

include_directories(
    src/passBD

    src/windowsNedoRello/firstWindow
    src/windowsNedoRello/registrationWindow
    src/windowsNedoRello/combiningSecondaryWindows
    src/windowsNedoRello/accountWindow
        src/windowsNedoRello/accountWindow/createBoard
        src/windowsNedoRello/accountWindow/inputBoard

    src/windowsNedoRello/List
        src/windowsNedoRello/List/windowCreateOrEditing
    src/windowsNedoRello/Board
        src/windowsNedoRello/Board/windowCreatedList
    src/windowsNedoRello/Cards
)
set(PROJECT_SOURCES
        src/main.cpp

        src/passBD/passdb.cpp
        src/passBD/passdb.h

        src/windowsNedoRello/firstWindow/firstwindow.cpp
        src/windowsNedoRello/firstWindow/firstwindow.h
        src/windowsNedoRello/firstWindow/firstwindow.ui

        src/windowsNedoRello/registrationWindow/registrationwindow.cpp
        src/windowsNedoRello/registrationWindow/registrationwindow.h
        src/windowsNedoRello/registrationWindow/registrationwindow.ui

        src/windowsNedoRello/combiningSecondaryWindows/combiningwindows.cpp
        src/windowsNedoRello/combiningSecondaryWindows/combiningwindows.h

        src/windowsNedoRello/accountWindow/accountwindow.cpp
        src/windowsNedoRello/accountWindow/accountwindow.h
        src/windowsNedoRello/accountWindow/accountwindow.ui
            src/windowsNedoRello/accountWindow/createBoard/createboard.cpp
            src/windowsNedoRello/accountWindow/createBoard/createboard.h
            src/windowsNedoRello/accountWindow/createBoard/createboard.ui
                src/windowsNedoRello/accountWindow/createBoard/confirmationwindow.cpp
                src/windowsNedoRello/accountWindow/createBoard/confirmationwindow.h
                src/windowsNedoRello/accountWindow/createBoard/confirmationwindow.ui

            src/windowsNedoRello/accountWindow/inputBoard/inputboard.cpp
            src/windowsNedoRello/accountWindow/inputBoard/inputboard.h
            src/windowsNedoRello/accountWindow/inputBoard/inputboard.ui

        src/windowsNedoRello/List/listnedorello.cpp
        src/windowsNedoRello/List/listnedorello.h
        src/windowsNedoRello/List/listnedorello.ui
            src/windowsNedoRello/List/windowCreateOrEditing/windowcreateoreditingcard.cpp
            src/windowsNedoRello/List/windowCreateOrEditing/windowcreateoreditingcard.h
            src/windowsNedoRello/List/windowCreateOrEditing/windowcreateoreditingcard.ui

        src/windowsNedoRello/Board/boardnedorello.cpp
        src/windowsNedoRello/Board/boardnedorello.h
        src/windowsNedoRello/Board/boardnedorello.ui
            src/windowsNedoRello/Board/windowCreatedList/windowcreatedlist.cpp
            src/windowsNedoRello/Board/windowCreatedList/windowcreatedlist.h
            src/windowsNedoRello/Board/windowCreatedList/windowcreatedlist.ui

        src/windowsNedoRello/Board/popup.cpp
        src/windowsNedoRello/Board/popup.h

        src/windowsNedoRello/Cards/cardnedorello.cpp
        src/windowsNedoRello/Cards/cardnedorello.h
        src/windowsNedoRello/Cards/cardnedorello.ui

        Assets/resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(NedoRello
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_link_libraries(NedoRello PRIVATE Qt6::Sql)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET NedoRello APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(NedoRello SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(NedoRello
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(NedoRello PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.NedoRello)
endif()
set_target_properties(NedoRello PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS NedoRello
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(NedoRello)
endif()
