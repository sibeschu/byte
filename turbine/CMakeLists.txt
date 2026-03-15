add_library(Turbine STATIC
    src/test.cpp
)

target_include_directories(Turbine PUBLIC include)

# if(WIN32)
#     target_sources(Turbine PRIVATE src/platform/windows/window.cpp src/platform/windows/input.cpp)
# elseif(UNIX)
#     target_sources(Turbine PRIVATE src/platform/linux/window.cpp src/platform/linux/input.cpp)
# endif()