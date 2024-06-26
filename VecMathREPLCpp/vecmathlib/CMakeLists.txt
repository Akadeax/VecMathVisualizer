
antlr_target(VecMathLexer ${VECMATH_COMMON_GRAMMAR_DIR}/VecMathLexer.g4 LEXER
             PACKAGE VecMath)
antlr_target(VecMathParser ${VECMATH_COMMON_GRAMMAR_DIR}/VecMathParser.g4 PARSER
             PACKAGE VecMath
             DEPENDS_ANTLR VecMathLexer
             COMPILE_FLAGS -lib ${ANTLR_VecMathLexer_OUTPUT_DIR} -listener)

include_directories(${ANTLR_VecMathLexer_OUTPUT_DIR})
include_directories(${ANTLR_VecMathParser_OUTPUT_DIR})

add_library(VecMathLib 
${VECMATH_COMMON_GRAMMAR_DIR}/VecMathLexer.g4
${VECMATH_COMMON_GRAMMAR_DIR}/VecMathParser.g4
${VECMATH_COMMON_RESOURCE_DIR}/help.txt
${VECMATH_COMMON_RESOURCE_DIR}/jokes.txt
               ${ANTLR_VecMathLexer_CXX_OUTPUTS}
               ${ANTLR_VecMathParser_CXX_OUTPUTS} 
               "VecMathListener.h" "VecMathListener.cpp" "IMatrix.h" "IMatrix.cpp" "Scalar.h" "Scalar.cpp" "Vector2D.h" "Vector2D.cpp" "Vector3D.h" "Vector3D.cpp" "Quaternion.h" "Quaternion.cpp" "JokeGenerator.h" "JokeGenerator.cpp" "Joke.h" "Joke.cpp"   "Complex.h" "Complex.cpp" "Console.h" "Console.cpp" "Signal.h" "Signal.cpp")
target_link_libraries(VecMathLib antlr4_static)
target_include_directories(VecMathLib INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    ${ANTLR_VecMathLexer_OUTPUT_DIR} 
    ${ANTLR_VecMathParser_OUTPUT_DIR}
)
#set(VecMathLibIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" ${ANTLR_VecMathLexer_OUTPUT_DIR} ${ANTLR_VecMathParser_OUTPUT_DIR} PARENT_SCOPE)
#set(VecMathLibIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" ${ANTLR_VecMathLexer_OUTPUT_DIR} ${ANTLR_VecMathParser_OUTPUT_DIR} PARENT_SCOPE)


message(${ANTLR_VecMathLexer_OUTPUT_DIR})

if (EMSCRIPTEN)
set_target_properties(VecMathLib PROPERTIES COMPILE_FLAGS
"-sNO_DISABLE_EXCEPTION_CATCHING")
endif()
    
install(DIRECTORY ${VECMATH_COMMON_RESOURCE_DIR} DESTINATION "bin")
install(DIRECTORY ${VECMATH_COMMON_RESOURCE_DIR} DESTINATION .)
