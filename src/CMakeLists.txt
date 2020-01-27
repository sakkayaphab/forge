file(GLOB SOURCES "*.cc")

add_executable(forge ${SOURCES})

include_directories(variant)
include_directories(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(vcf)
add_subdirectory(sim)
add_subdirectory(fasta)
add_subdirectory(fastq)
target_link_libraries(forge
        sim
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