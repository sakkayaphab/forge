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
            vcf
            ${TBB_IMPORTED_TARGETS}
            ${YAML_CPP_LIBRARIES}
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(
            sim
            fasta
            vcf
            ${TBB_IMPORTED_TARGETS}
            ${YAML_CPP_LIBRARIES}
    )
endif()