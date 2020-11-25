cmake_minimum_required(VERSION 3.17)
project(DinnerPlanner_Gui)

set(CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS} )

include_directories(${GTKMM_INCLUDE_DIRS})

include_directories(sqlite)

add_executable(DinnerPlanner_Gui main.cpp sqlite/sqlite3.c DB.cpp Recipe_View.cpp Network.cpp)

target_link_libraries(DinnerPlanner_Gui PRIVATE Threads::Threads ${CMAKE_DL_LIBS} ${GTKMM_LIBRARIES} curl)