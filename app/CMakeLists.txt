# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

## Oboe Library ##
set (OBOE_DIR ../../oboe)
add_subdirectory (${OBOE_DIR} ./oboe)

# Make the Oboe public headers available to our app
include_directories (${OBOE_DIR}/include)

# App specific sources
set (APP_DIR src/main/cpp)
file (
    GLOB_RECURSE APP_SOURCES
    ${APP_DIR}/Oscillator.cpp
    ${APP_DIR}/AudioEngine.cpp
    ${APP_DIR}/native-lib.cpp
)

# Build the native-lib library
add_library(
    native-lib
    SHARED
    ${APP_SOURCES}
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}

        #oboe
        oboe
        OpenSLES)
