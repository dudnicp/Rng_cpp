find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message("Doxygen not found, impossible to generate documentation")
else()
   configure_file(doxyfilerc Doxyfile)

   set(DOXYGEN_INPUT ${CMAKE_BINARY_DIR}/doc/Doxyfile)
   set(DOXYGEN_OUTPUT ${APIDOC_DIR}/html/index.html)

   add_custom_target(doc ALL
     COMMAND ${CMAKE_COMMAND} -E echo_append "Generation de la documentation..."
     COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT} > /dev/null
     COMMAND ${CMAKE_COMMAND} -E echo "Terminé."
     )

endif()