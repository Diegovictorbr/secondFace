# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)
include_directories(C:/Users/Administrador/Desktop/Programas/opencv-3.4.3-android-sdk/sdk/native/jni/include)
include_directories(C:/Users/Administrador/Downloads/Test16/app/src/main/h)
add_library(lib_opencv SHARED IMPORTED)
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)
set(DLIB_DIR dlib-19.1)
include_directories(${DLIB_DIR} include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp
        src/main/cpp/Detector.cpp
        src/main/cpp/Swapper.cpp
        ${DLIB_DIR}/dlib/threads/threads_kernel_shared.cpp
        ${DLIB_DIR}/dlib/entropy_decoder/entropy_decoder_kernel_2.cpp
        ${DLIB_DIR}/dlib/base64/base64_kernel_1.cpp
        ${DLIB_DIR}/dlib/threads/threads_kernel_1.cpp
        ${DLIB_DIR}/dlib/threads/threads_kernel_2.cpp
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

find_library( # Sets the name of the path variable.
        android-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        android)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib lib_opencv

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        ${android-lib})