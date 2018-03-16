# Copy files from source directory to destination directory, substituting any
# variables.  Create destination directory if it does not exist.

macro(configure_files srcDir destDir)
   # message(STATUS "Configuring directory ${destDir}")
    make_directory(${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} ${srcDir}/*)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
#            message(STATUS "Configuring file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    COPYONLY IMMEDIATE)
		else(NOT IS_DIRECTORY ${srcTemplatePath})
			make_directory(${destDir}/${templateFile})
			configure_files(${srcTemplatePath} ${destDir}/${templateFile})
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(configure_files)

macro(source_group_by_dir source_files)
    set(sgbd_cur_dir ${CMAKE_CURRENT_BINARY_DIR})
    foreach(sgbd_file ${${source_files}})
        #message("sgbd_fpath=${sgbd_fpath}")
        string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
        string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
        string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
        string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
        if(sgbd_nogroup)
            set(sgbd_group_name "\\")
        endif()
        #message("group name=${sgbd_group_name}")
        source_group(${sgbd_group_name} FILES ${sgbd_file})
    endforeach()
endmacro(source_group_by_dir)