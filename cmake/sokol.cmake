include(FetchContent)

FetchContent_Declare(
    sokol
    GIT_REPOSITORY https://github.com/floooh/sokol
    GIT_TAG master
)

FetchContent_MakeAvailable(sokol)

add_library(sokol INTERFACE)

target_include_directories(sokol INTERFACE ${sokol_SOURCE_DIR} ${sokol_SOURCE_DIR}/util)

if(APPLE)
    if(IOS)
        target_link_libraries(
            sokol INTERFACE
            "$<LINK_LIBRARY:FRAMEWORK,Foundation>"
            "$<LINK_LIBRARY:FRAMEWORK,GLKit>"
            "$<LINK_LIBRARY:FRAMEWORK,Metal>"
            "$<LINK_LIBRARY:FRAMEWORK,MetalKit>"
            "$<LINK_LIBRARY:FRAMEWORK,OpenGLES>"
            "$<LINK_LIBRARY:FRAMEWORK,UIKit>"
            "$<LINK_LIBRARY:FRAMEWORK,AudioToolbox>"
            "$<LINK_LIBRARY:FRAMEWORK,AVFoundation>"
        )
    else()
        target_link_libraries(
            sokol INTERFACE
            "$<LINK_LIBRARY:FRAMEWORK,Cocoa>"
            "$<LINK_LIBRARY:FRAMEWORK,Metal>"
            "$<LINK_LIBRARY:FRAMEWORK,MetalKit>"
            "$<LINK_LIBRARY:FRAMEWORK,OpenGL>"
            "$<LINK_LIBRARY:FRAMEWORK,QuartzCore>"
            "$<LINK_LIBRARY:FRAMEWORK,AudioToolbox>"
        )
    endif()
elseif(LINUX)
    find_package(Threads REQUIRED)
    target_link_libraries(
        sokol INTERFACE
        X11
        Xi
        Xcursor
        GL
        asound
        dl
        m
        Threads::Threads
    )
elseif(WIN32)
    target_link_libraries(
        sokol INTERFACE
        opengl32
        gdi32
        user32
        shell32
        kernel32
        ole32
    )
endif()
