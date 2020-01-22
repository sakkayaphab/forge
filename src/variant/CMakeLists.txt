file(GLOB SOURCES "*.cc")

add_library(variant
        STATIC
        ${SOURCES}
)

include_directories(${PROJECT_SOURCE_DIR}/src)
message( ${PROJECT_SOURCE_DIR}/src)
if(APPLE)
    target_link_libraries(
            variant
            fasta
            vcf
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(
            variant
            fasta
            vcf
    )
endif()
