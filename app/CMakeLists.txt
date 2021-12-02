cmake_minimum_required(VERSION 3.10.2)

set(GLM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/3rdparty/libglm)
set(STBIMG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/3rdparty/libstbImage)

set(CPPDIR ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp)

include_directories(${GLM_DIR}/include)
include_directories(${STBIMG_DIR}/include)

set(LIB_SRC ${CPPDIR}/LCImage.cpp
            ${CPPDIR}/LCGLTexture.cpp
            ${CPPDIR}/LCOpenGLBuffer.cpp
            ${CPPDIR}/LCFrameBufferObject.cpp
            ${CPPDIR}/LCOpenGLVAO.cpp
            ${CPPDIR}/LCOpenGLShader.cpp
            ${CPPDIR}/LCOpenGLRender.cpp
            ${CPPDIR}/sample/TriangleSample.cpp
            ${CPPDIR}/sample/RectangleSample.cpp
            ${CPPDIR}/sample/LoadImageSample.cpp
            ${CPPDIR}/sample/CubeSample.cpp
            ${CPPDIR}/sample/CubeImageSample.cpp
            ${CPPDIR}/sample/TransitionSample.cpp
            ${CPPDIR}/sample/TransitionL2RSample.cpp)

add_library(LCOpenGLRender SHARED ${LIB_SRC})

set(native-libs
        android
        EGL
        GLESv3
        log
        )

target_link_libraries(LCOpenGLRender
        ${native-libs})