include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(
    test_vcf
        tests.cc
    )

target_link_libraries(
        test_fasta
        gtest_main
        vcf
    )

add_test(
  NAME
    test_vcf_1
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/test_vcf
  )