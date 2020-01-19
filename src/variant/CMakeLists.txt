file(GLOB SOURCES "*.cc")

add_library(variant
        STATIC
        ${SOURCES}
)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)
message( ${PROJECT_SOURCE_DIR}/src)
if(APPLE)
    target_link_libraries(
            variant
            fasta
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(
            variant
            fasta
    )
endif()
