cmake_minimum_required(VERSION 3.5)
project(newShell)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp help.h proccess.h proccess.cpp help.cpp builtin.cpp builtin.h filescript.cpp filescript.h)

add_executable(newShell ${SOURCE_FILES})

FIND_PACKAGE( Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries( newShell ${Boost_LIBRARIES} -lboost_regex)

project(rm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES rm.cpp)
add_executable(rm ${SOURCE_FILES})

FIND_PACKAGE(Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries(rm ${Boost_LIBRARIES})

project(cp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES cp.cpp)
add_executable(cp ${SOURCE_FILES})

FIND_PACKAGE(Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries(cp ${Boost_LIBRARIES})

project(mv)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES mv.cpp)
add_executable(mv ${SOURCE_FILES})

FIND_PACKAGE(Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries(mv ${Boost_LIBRARIES})

project(ls)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES ls.cpp)
add_executable(ls ${SOURCE_FILES})

FIND_PACKAGE(Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries(ls ${Boost_LIBRARIES} -lboost_regex)

project(mkdir)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES mkdir.cpp)
add_executable(mkdir ${SOURCE_FILES})

FIND_PACKAGE(Boost COMPONENTS program_options filesystem system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
target_link_libraries(mkdir ${Boost_LIBRARIES} -lboost_regex)