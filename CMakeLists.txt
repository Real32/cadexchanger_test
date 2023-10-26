cmake_minimum_required(VERSION 3.14)

project(cadexchanger_test LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

# find OpenMP
find_package(OpenMP REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
            src/point3d.cpp

        include/point3d.h
            include/curve3d.h
                include/circle3d.h
                    include/ellipse3d.h
                        include/helix3d.h
)

add_executable(cadexchanger_test
    ${PROJECT_SOURCES}
)


if(OpenMP_CXX_FOUND)
    target_link_libraries(cadexchanger_test OpenMP::OpenMP_CXX)
endif()

install(TARGETS cadexchanger_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
