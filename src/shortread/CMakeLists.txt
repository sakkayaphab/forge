file(GLOB SOURCES "*.cc")

add_library(shortread
        STATIC
        ${SOURCES}
)

if(APPLE)
    target_link_libraries(
            shortread
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(
            shortread
    )
endif()
