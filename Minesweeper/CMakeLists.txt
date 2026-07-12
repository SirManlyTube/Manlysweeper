add_executable(Minesweeper "main.cpp"  "minesweeper_action.h" "rendering/texture.h" "fps_counter.h" "precision_delay.h" "precision_delay.cpp" "rendering/shader.h" "rendering/shader.cpp" "rendering/text_renderer.h" "rendering/font.h" "rendering/font.cpp" "rendering/vertex.h" "tile_map.h" "tile.h" "tile_map.cpp" "rendering/texture.cpp" "rendering/text_renderer.cpp" "application.h" "application.cpp" "audio_loop_tracker.h" "rendering/texture_registry.h" "rendering/texture_registry.cpp")

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM64|arm64")
        set(ARCH_DIR "arm64")
    else()
        set(ARCH_DIR "x64")
    endif()
else()
    set(ARCH_DIR "x86")
endif()

set(LIB_ROOT "${CMAKE_SOURCE_DIR}/third_party")

target_include_directories(Minesweeper PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${LIB_ROOT}/include"
    "${LIB_ROOT}/freetype/include"
    "${LIB_ROOT}/SDL3/include"
)

target_link_libraries(Minesweeper PRIVATE
    "${LIB_ROOT}/freetype/lib/${ARCH_DIR}/freetype.lib"
    "${LIB_ROOT}/SDL3/lib/${ARCH_DIR}/SDL3.lib"
)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "${CMAKE_CURRENT_BINARY_DIR}/assets"
)
add_dependencies(Minesweeper copy_assets)

add_custom_command(TARGET Minesweeper POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${LIB_ROOT}/SDL3/bin/${ARCH_DIR}/SDL3.dll"
    $<TARGET_FILE_DIR:Minesweeper>
)

set_property(TARGET Minesweeper PROPERTY CXX_STANDARD 23)
set_target_properties(Minesweeper PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>)
