# Generate lexer and parser with ANTLR
list(APPEND CMAKE_MODULE_PATH "${ANTLR_RUNTIME}/cmake")

include(FindANTLR)

antlr_target(SysYGen SysY.g4
  LEXER PARSER
  OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  VISITOR
)

add_library(SysYParser SHARED ${ANTLR_SysYGen_CXX_OUTPUTS})
target_include_directories(SysYParser PUBLIC ${ANTLR_RUNTIME}/runtime/src)
target_link_libraries(SysYParser PUBLIC antlr4_shared)

