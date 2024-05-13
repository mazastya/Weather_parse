#cmake_minimum_required(VERSION 3.25)
#set(PROJECT_NAME "lab10")
#project(PROJECT_NAME)
#
#set(CMAKE_CXX_STANDARD 17)
#
#include(FetchContent)
#FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
#FetchContent_MakeAvailable(cpr)
#
#add_executable(PROJECT_NAME main.cpp)
#target_link_libraries(PROJECT_NAME PRIVATE cpr::cpr)
cmake_minimum_required(VERSION 3.25)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v3.0.0
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


project(lab10_2sem_c__)

set(CMAKE_CXX_STANDARD 17)
find_package(CURL REQUIRED)
#include(FetchContent)
#FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
#FetchContent_MakeAvailable(cpr)

#find_package(cpr::cpr REQUIRED)
#add_executable(lab10_2sem_c__ main.cpp)
#target_link_libraries(lab10_2sem_c__ PRIVATE cpr::cpr)

add_executable(lab10_2sem_c__ main.cpp
        graphic_interface.cpp graphic_interface.h
        json_parse.cpp json_parse.h)


#
#add_executable(test test_ftxui.cpp)
#target_link_libraries(test
#        PRIVATE ftxui::screen
#        PRIVATE ftxui::dom
#        PRIVATE ftxui::component
#        ${CURL_LIBRARIES})


include_directories(${CURL_INCLUDE_DIR})
target_include_directories(lab10_2sem_c__ PRIVATE src)

target_link_libraries(lab10_2sem_c__
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        ${CURL_LIBRARIES})

#add_executable(graphic graphic_interface.cpp)


find_package(nlohmann_json REQUIRED)

#cmake_minimum_required(VERSION 3.1)
#project(ExampleProject LANGUAGES CXX)
#
## If you only include this third party in PRIVATE source files, you do not need to install it
## when your main project gets installed.
#set(JSON_Install OFF CACHE INTERNAL "")
#
#add_subdirectory(nlohmann_json)
#
#add_executable(example example.cpp)
#target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)