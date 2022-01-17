cmake_minimum_required(VERSION 3.14)

project(qtserverclient LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)


file(GLOB SOURCES socketserver/*.cpp socketclient/*.cpp)
file(GLOB HEADERS socketserver/*.h socketclient/*.h)



add_executable(socketserver
  socketserver/socketserver.cpp
  socketserver/main.cpp
)

add_executable(socketclient
  socketclient/socketclient.cpp
  socketclient/main.cpp
)

target_link_libraries(socketserver  Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(socketserver  Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries( socketclient Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries( socketclient Qt${QT_VERSION_MAJOR}::Network)

