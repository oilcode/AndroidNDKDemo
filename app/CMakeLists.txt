# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/AnCpp2JavaLibNative.cpp
             src/main/cpp/AndroidAdepter.cpp
			 src/main/cpp/AnFileAsset.cpp
			 src/main/cpp/AnFileExternal.cpp
			 src/main/cpp/AnFileInternal.cpp

             # mycode
             src/main/cpp/GLLogicFlowHelp.cpp
             src/main/cpp/GLManager.cpp
             src/main/cpp/GLModelRect.cpp
             src/main/cpp/GLModelTriangle.cpp
             src/main/cpp/GLShaderBase.cpp
             src/main/cpp/GLShaderHelp.cpp
             src/main/cpp/GLShaderManager.cpp
             src/main/cpp/GLShaderSimple.cpp
             src/main/cpp/GLShaderTexture.cpp
             src/main/cpp/GLTextureManager.cpp

             # SoBase
             src/main/cpp/SoFile.cpp
			 src/main/cpp/SoFileHelp.cpp
			 src/main/cpp/SoImageHelp.cpp
			 src/main/cpp/SoImagePNG.cpp
            )


add_library( png
             STATIC
             src/main/thirdparty/02_png/png.c
             src/main/thirdparty/02_png/pngerror.c
             src/main/thirdparty/02_png/pngget.c
             src/main/thirdparty/02_png/pngmem.c
             src/main/thirdparty/02_png/pngpread.c
             src/main/thirdparty/02_png/pngread.c
             src/main/thirdparty/02_png/pngrio.c
             src/main/thirdparty/02_png/pngrtran.c
             src/main/thirdparty/02_png/pngrutil.c
             src/main/thirdparty/02_png/pngset.c
             src/main/thirdparty/02_png/pngtest.c
             src/main/thirdparty/02_png/pngtrans.c
             src/main/thirdparty/02_png/pngwio.c
             src/main/thirdparty/02_png/pngwrite.c
             src/main/thirdparty/02_png/pngwtran.c
             src/main/thirdparty/02_png/pngwutil.c
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
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # 这里奇怪的参数，是让PNG这个库直接拷贝到NativeLib里面。
                       "-Wl,--whole-archive"
                       png
                       "-Wl,--no-whole-archive"


                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       android
                       GLESv2
                       z           # zlib
                      )
