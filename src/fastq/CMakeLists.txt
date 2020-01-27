file(GLOB SOURCES "*.cc")

add_library(fastq
        STATIC
        ${SOURCES}
        )