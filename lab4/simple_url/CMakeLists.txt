project(simple_url)

set(HEDEAR_FILES SimpleUrl.h)
set(SOURCE_FILES SimpleUrl.cpp)

add_library(libsimpleurl STATIC ${SOURCE_FILES})
target_include_directories(libsimpleurl PUBLIC .)

add_executable(simple_url ${SOURCE_FILES} main.cpp)

target_link_libraries(simple_url libsimpleurl)