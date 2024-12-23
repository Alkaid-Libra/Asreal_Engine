set(TARGET_NAME ${SHADER_COMPILE_TARGET})
file(GLOB_RECURSE SHADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.vert"
                                                "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.frag"
                                                "${CMAKE_CURRENT_SOURCE_DIR}/glsl/*.geom")
        
SOURCE_GROUP("shaders" FILES ${SHADER_FILES})

set(SHADER_INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(GENERATED_SHADER_FOLDER "generated")
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER})
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER})
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER}/spv)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${GENERATED_SHADER_FOLDER}/spv)
endif()

include(${VIRTUALENGINE_ROOT_DIR}/cmake/ShaderCompile.cmake)

compile_shader(
    "${SHADER_FILES}"
    "${TARGET_NAME}"
    "${SHADER_INCLUDE_FOLDER}"
    "${GENERATED_SHADER_FOLDER}"
    "${glslangValidator_executable}"
)

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Engine")