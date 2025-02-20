# Git commit SHA1
execute_process(COMMAND
    git rev-parse HEAD
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE BUILDINFO_GIT_SHA1
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# Git commit hash
execute_process(COMMAND
    git rev-parse --short HEAD
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE BUILDINFO_GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# Git commit branch name
execute_process(COMMAND
    git symbolic-ref --short HEAD
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE BUILDINFO_GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE)

if(NOT BUILDINFO_GIT_BRANCH)
  set(BUILDINFO_GIT_BRANCH $ENV{BRANCH_NAME})
endif()

STRING(TIMESTAMP BUILDINFO_DATE %Y-%m-%d)
STRING(TIMESTAMP BUILDINFO_TIME %H:%M:%S)
STRING(TIMESTAMP BUILDINFO_TIMESTAMP UTC)

#execute_process(COMMAND "date" "+%F %H:%M:%S" OUTPUT_VARIABLE date OUTPUT_STRIP_TRAILING_WHITESPACE)
	
set(BUILDINFO_SYSTEM "${CMAKE_SYSTEM}")
set(BUILDINFO_SYSTEM "${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Getting build info")
message(STATUS "==============================================================")

