add_executable(Lab2CPP main.cpp)
target_include_directories(Lab2CPP PRIVATE
        ${PROJECT_SOURCE_DIR}/LibraryCPP
)

target_link_libraries(Lab2CPP PRIVATE LibraryCPP)

function(add_minipig_test name script)

    set(input_file "${CMAKE_CURRENT_SOURCE_DIR}/input.txt")

    if(ARGC GREATER 2)
        set(input_file "${CMAKE_CURRENT_SOURCE_DIR}/${ARGV2}")
    endif()

    add_test(
            NAME MiniPig_${name}
            COMMAND ${CMAKE_COMMAND}
            "-DPROGRAM=$<TARGET_FILE:Lab2CPP>"
            "-DSCRIPT=${CMAKE_CURRENT_SOURCE_DIR}/${script}"
            "-DINPUT=${input_file}"
            "-DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/Tests/${name}.expected"
            -P "${CMAKE_CURRENT_SOURCE_DIR}/Tests/check.cmake"
    )

endfunction()

add_minipig_test(basic example.mpg)
add_minipig_test(register Tests/register.mp)
add_minipig_test(subtract Tests/subtract.mp)
add_minipig_test(swap Tests/swap.mp)
add_minipig_test(switch Tests/switch.mp)
add_minipig_test(push_symbol Tests/push_symbol.mp)
add_minipig_test(push_letter Tests/push_letter.mp)
add_minipig_test(switch_symbol Tests/switch_symbol.mp)
add_minipig_test(switch_letter Tests/switch_letter.mp)
add_minipig_test(register_symbol Tests/register_symbol.mp)
add_minipig_test(register_letter Tests/register_letter.mp)
add_minipig_test(swap_symbol Tests/swap_symbol.mp Tests/swap_symbol.input)
add_minipig_test(swap_letter Tests/swap_letter.mp Tests/swap_letter.input)
add_minipig_test(subtract_symbol Tests/subtract_symbol.mp Tests/subtract_symbol.input)
add_minipig_test(subtract_letter Tests/subtract_letter.mp Tests/subtract_letter.input)
add_minipig_test(reverse_symbol Tests/reverse_symbol.mp Tests/reverse_symbol.input)
add_minipig_test(reverse_letter Tests/reverse_letter.mp Tests/reverse_letter.input)
add_minipig_test(number_io_symbol Tests/number_io_symbol.mp Tests/number_io_symbol.input)
add_minipig_test(number_io_letter Tests/number_io_letter.mp Tests/number_io_letter.input)
add_minipig_test(char_io_symbol Tests/char_io_symbol.mp Tests/char_io_symbol.input)
add_minipig_test(char_io_letter Tests/char_io_letter.mp Tests/char_io_letter.input)
add_minipig_test(jump_forward_symbol Tests/jump_forward_symbol.mp)
add_minipig_test(jump_forward_letter Tests/jump_forward_letter.mp)
add_minipig_test(jump_backward_symbol Tests/jump_backward_symbol.mp Tests/jump_backward_symbol.input)
add_minipig_test(jump_backward_letter Tests/jump_backward_letter.mp Tests/jump_backward_letter.input)
add_minipig_test(jump_two_forward Tests/jump_two_forward.mp)
add_minipig_test(jump_two_backward Tests/jump_two_backward.mp Tests/jump_two_backward.input)
add_minipig_test(two_stacks_register Tests/two_stacks_register.mp Tests/two_stacks_register.input)
add_minipig_test(empty_pop Tests/empty_pop.mp)
add_minipig_test(empty_reverse Tests/empty_reverse.mp)
add_minipig_test(jump_zero Tests/jump_zero.mp Tests/jump_zero.input)
