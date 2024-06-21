execute_process(
    COMMAND git log -1 --format=%h
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(DATE_CUSTOM_FORMAT date "+%Y-%m-%d %H:%M:%S")
execute_process(
    COMMAND ${DATE_CUSTOM_FORMAT}
    OUTPUT_VARIABLE COMPILE_TIME
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
    OUTPUT_VARIABLE GIT_BRANCH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(SYSTEM_VERSION_DESC "Copyright (c) 2019-2024,Motovis.")

configure_file(${configure_dir}/Version.h.in ${configure_dir}/Version.h @ONLY)