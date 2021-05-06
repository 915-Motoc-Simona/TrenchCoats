cmake_minimum_required(VERSION 3.17)
project(a89-915-Motoc-Simona)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_32/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(Business)
include_directories(Database)
include_directories(DynamicVectorDir)
include_directories(Persistence)
include_directories(Testing)
include_directories(Presentation)

add_executable(a89-915-Motoc-Simona
        Presentation/AdminGUI.cpp
        Presentation/AdminGUI.h
        Presentation/UserGUI.cpp
        Presentation/UserGUI.h
        Business/AdministratorController.cpp
        Business/AdministratorController.h
        Database/TrenchCoat.cpp
        Database/TrenchCoat.h
        DynamicVectorDir/dynamicVector.h
        Persistence/MyException.h
        Persistence/AdminFileRepository.cpp
        Persistence/AdminFileRepository.h
        Persistence/AdminRepository.cpp
        Persistence/AdminRepository.h
        Testing/tests.cpp
        Testing/tests.h
        Presentation/GUI.cpp
        Presentation/GUI.h
        Starting/appStart.cpp
        Persistence/UserFileRepository.cpp Persistence/UserFileRepository.h Persistence/AdminHTMLRepository.cpp Persistence/AdminHTMLRepository.h Persistence/UserHTMLRepository.cpp Persistence/UserHTMLRepository.h Persistence/UserRepository.cpp Persistence/UserRepository.h Business/UserController.cpp Business/UserController.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})