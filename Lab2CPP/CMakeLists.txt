add_executable(Lab2CPP main.cpp)

target_link_libraries(Lab2CPP PRIVATE LibraryCPP)

function(add_minipig_test name script)
    add_test(
        NAME MiniPig_${name}
        COMMAND ${CMAKE_COMMAND}
            "-DPROGRAM=$<TARGET_FILE:Lab2CPP>"
            "-DSCRIPT=${CMAKE_CURRENT_SOURCE_DIR}/${script}"
            "-DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/input.txt"
            "-DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/Tests/${name}.expected"
            -P "${CMAKE_CURRENT_SOURCE_DIR}/Tests/check.cmake"
    )
endfunction()

add_minipig_test(basic example.mpg)
add_minipig_test(register Tests/register.mp)
add_minipig_test(subtract Tests/subtract.mp)
add_minipig_test(swap Tests/swap.mp)
add_minipig_test(switch Tests/switch.mp)
