file(GLOB SOURCES "*.cc")

add_library(shortread
        STATIC
        ${SOURCES}
        )

