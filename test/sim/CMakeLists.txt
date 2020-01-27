include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(
    test_sim
        tests.cc
    )

target_link_libraries(
    test_sim
    gtest_main
        sim
    )

add_test(
  NAME
        test_sim_1
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/test_sim
  )