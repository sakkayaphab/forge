
file(GLOB SOURCES "*.cc")

add_executable(forge ${SOURCES})

include_directories(variant)
include_directories(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(variant)
add_subdirectory(shortread)
add_subdirectory(fasta)
add_subdirectory(vcf)

target_link_libraries(forge
#        shortread
        ##        fasta
        ##        vcf
        variant
  )

if (NOT ${INSTALL_BIN_PREFIX} STREQUAL "")
    message("INSTALL BINARY PATH : " ${INSTALL_BIN_PREFIX})
    set(INSTALL_BIN_DIR ${INSTALL_BIN_PREFIX} CACHE PATH "Installation directory for executables")
    install(TARGETS forge DESTINATION ${INSTALL_BIN_DIR})
else()
    message("INSTALL BINARY PATH : " "/usr/local/bin")
    set(INSTALL_BIN_DIR "/usr/local/bin" CACHE PATH "Installation directory for executables")
    install(TARGETS forge DESTINATION ${INSTALL_BIN_DIR})
endif()