if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM64|arm64")
        set(ARCH_DIR "arm64")
    else()
        set(ARCH_DIR "x64")
    endif()
else()
    set(ARCH_DIR "x86")
endif()

# Globs the source files so we don't need to manually add them to the executable

file(GLOB_RECURSE MINESWEEPER_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE MINESWEEPER_INCLUDES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(Minesweeper ${MINESWEEPER_SOURCES} ${MINESWEEPER_INCLUDES})

set(LIB_ROOT "${CMAKE_SOURCE_DIR}/third_party")

target_include_directories(Minesweeper PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${LIB_ROOT}/include"
)

set(LIB_DIR "${LIB_ROOT}/lib/${ARCH_DIR}")
set(DLL_DIR "${LIB_ROOT}/bin/${ARCH_DIR}")

file(GLOB_RECURSE GLOB_LIBS CONFIGURE_DEPENDS "${LIB_DIR}/*.lib" "${LIB_DIR}/*.a")
file(GLOB_RECURSE GLOB_DLLS CONFIGURE_DEPENDS "${LIB_DIR}/*.dll")

target_link_libraries(Minesweeper PRIVATE ${GLOB_LIBS})

foreach(FILE_PATH IN LISTS GLOB_DLLS)
    message(STATUS "Copying DLL: ${FILE_PATH}")

    get_filename_component(FILE_NAME "${FILE_PATH}" NAME)

    add_custom_command(TARGET Minesweeper POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FILE_PATH}"
        $<TARGET_FILE_DIR:Minesweeper>
    )
endforeach()

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "${CMAKE_CURRENT_BINARY_DIR}/assets"
)
add_dependencies(Minesweeper copy_assets)

set_property(TARGET Minesweeper PROPERTY CXX_STANDARD 23)
set_target_properties(Minesweeper PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>)
