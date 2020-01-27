file(GLOB SOURCES "*.cc")


add_library(vcf
        STATIC
    ${SOURCES}
)