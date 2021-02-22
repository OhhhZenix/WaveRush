function(SetupVcpkg p_ListDeps)
    if (NOT DEFINED ${CMAKE_TOOLCHAIN_FILE})
        if (NOT DEFINED ENV{VCPKG_ROOT})
            set(VCPKG_ROOT ${CMAKE_SOURCE_DIR}/vcpkg)
        else ()
            set(VCPKG_ROOT $ENV{VCPKG_ROOT})
        endif ()

        if (NOT EXISTS ${VCPKG_ROOT})
            message("Cloning vcpkg in ${VCPKG_ROOT}")
            execute_process(COMMAND git clone https://github.com/Microsoft/vcpkg.git ${VCPKG_ROOT})
            # If a reproducible build is desired (and potentially old libraries are # ok), uncomment the
            # following line and pin the vcpkg repository to a specific githash.
            # execute_process(COMMAND git checkout 745a0aea597771a580d0b0f4886ea1e3a94dbca6 WORKING_DIRECTORY ${VCPKG_ROOT})
        else ()
            # The following command has no effect if the vcpkg repository is in a detached head state.
            message("Auto-updating vcpkg in ${VCPKG_ROOT}")
            execute_process(COMMAND git pull WORKING_DIRECTORY ${VCPKG_ROOT})
        endif ()

        if (NOT EXISTS ${VCPKG_ROOT}/README.md)
            message(FATAL_ERROR "***** FATAL ERROR: Could not clone vcpkg *****")
        endif ()

        if (WIN32)
            set(VCPKG_EXEC ${VCPKG_ROOT}/vcpkg.exe)
            set(VCPKG_BOOTSTRAP ${VCPKG_ROOT}/bootstrap-vcpkg.bat)
        else ()
            set(VCPKG_EXEC ${VCPKG_ROOT}/vcpkg)
            set(VCPKG_BOOTSTRAP ${VCPKG_ROOT}/bootstrap-vcpkg.sh)
        endif ()

        if (NOT EXISTS ${VCPKG_EXEC})
            message("Bootstrapping vcpkg in ${VCPKG_ROOT}")
            execute_process(COMMAND ${VCPKG_BOOTSTRAP} WORKING_DIRECTORY ${VCPKG_ROOT})
        endif ()

        if (NOT EXISTS ${VCPKG_EXEC})
            message(FATAL_ERROR "***** FATAL ERROR: Could not bootstrap vcpkg *****")
        endif ()

        set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "")

        message(STATUS "***** Checking project third party dependencies in ${VCPKG_ROOT} *****")
        execute_process(COMMAND ${VCPKG_EXEC} install ${p_ListDeps} WORKING_DIRECTORY ${VCPKG_ROOT})
    endif ()
endfunction()