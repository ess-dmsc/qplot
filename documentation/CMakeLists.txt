#============================================================================
# Building the API documentation using doxygen
#============================================================================
configure_file(Doxyfile.in Doxyfile @ONLY)
configure_file(groups.dox groups.dox COPYONLY)
configure_file(mainpage.dox mainpage.dox COPYONLY)
configure_file(namespaces.dox namespaces.dox COPYONLY)
set_source_files_properties(Doxyfile groups.dox mainpage.dox namespaces.dox
	PROPERTIES GENERATED TRUE)

add_custom_command(OUTPUT doxygen.stamp
                   COMMAND doxygen
                   COMMAND echo "timestamp" > doxygen.stamp
                   DEPENDS Doxyfile groups.dox mainpage.dox namespaces.dox
                           ${CMAKE_DOXYGEN_BUILD_DEPENDENCIES}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_custom_target(api_doc DEPENDS doxygen.stamp)

#==============================================================================
# need to remove some additional files after building the documentation
#==============================================================================
#set(CLEANFILES doxygen.stamp sphinx.stamp api_doc build)
#set_directory_properties(PROPERTIES
#    ADDITIONAL_MAKE_CLEAN_FILES ${CLEANFILES})

