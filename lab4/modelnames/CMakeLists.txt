
project(modelnames)

set(HEDEAR_FILES ModelNames.h)
set(SOURCE_FILES ModelNames.cpp)

add_library(libmodelnames STATIC ${SOURCE_FILES})
target_include_directories(libmodelnames PUBLIC .)

add_executable(modelnames ${SOURCE_FILES} main.cpp)

target_link_libraries(modelnames libmodelnames)