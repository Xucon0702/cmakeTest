cmake_minimum_required(VERSION 3.5)

project(cmake_test)

set(Utils_ROOT_DIR ${PROJECT_SOURCE_DIR}) #设置为./ 不行，需要绝对路径
set(Utils_HEAD_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

message("Utils_ROOT_DIR: ${Utils_ROOT_DIR}")
message("Utils_HEAD_INCLUDE_DIR: ${Utils_HEAD_INCLUDE_DIR}")
message("GitVersion path:${Utils_ROOT_DIR}/GitVersion.cmake")



include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)


link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

file(GLOB SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
# file(GLOB LIB_FILES
#     ${PROJECT_SOURCE_DIR}/src/Version.cpp
# )


add_custom_target(Always_check_git COMMAND ${CMAKE_COMMAND}
    -Dconfigure_dir=${Utils_HEAD_INCLUDE_DIR}
    -P ${Utils_ROOT_DIR}/GitVersion.cmake
    BYPRODUCTS ${Utils_HEAD_INCLUDE_DIR}/Version.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# add_library(mvutils SHARED
#     ${LIB_FILES}
# )

# target_link_libraries(${PROJECT_NAME}
        
# )
# target_link_libraries(mvutils
        
# )

add_dependencies(${PROJECT_NAME}
    Always_check_git
)

# install(TARGETS mvutils DESTINATION ${APP_LIB_INSTALL_PATH})