file(GLOB SOURCES "*.cc")

add_library(sim
        STATIC
        ${SOURCES}
        )

include_directories(${PROJECT_SOURCE_DIR}/src)
message( ${PROJECT_SOURCE_DIR}/src)
if(APPLE)
    target_link_libraries(
            sim
            fasta
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(
            sim
            fasta
    )
endif()