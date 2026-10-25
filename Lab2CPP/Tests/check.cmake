execute_process(
    COMMAND "${PROGRAM}" "${SCRIPT}" "${INPUT}"
    OUTPUT_VARIABLE result
    RESULT_VARIABLE code
)

if(NOT code EQUAL 0)
    message(FATAL_ERROR "Программа завершилась с ошибкой")
endif()

file(READ "${EXPECTED}" answer)

if(NOT result STREQUAL answer)
    message(FATAL_ERROR "Неправильный ответ")
endif()
