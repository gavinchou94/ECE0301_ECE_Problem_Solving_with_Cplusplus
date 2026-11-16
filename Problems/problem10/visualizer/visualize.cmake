# Problem 10 circuit visualizer (provided, do not edit; not graded).
# Run by the "visualize" build target. It compiles your classes one stage at a time,
# runs a small probe program for each stage, and writes circuit_trace.txt in your
# Problem 10 folder (next to CMakeLists.txt).
# Load that file in the circuit visualizer embedded in the Problem 10 statement on Canvas.

set(WORK "${BIN}/visualizer_work")
file(REMOVE_RECURSE "${WORK}")
file(MAKE_DIRECTORY "${WORK}")

set(STUDENT VoltageSource CurrentSource Resistor VoltageDivider CurrentDivider PracticalVsCircuit)
foreach(name Node Component ${STUDENT})
    foreach(ext hpp cpp)
        if(EXISTS "${SRC}/${name}.${ext}")
            file(COPY "${SRC}/${name}.${ext}" DESTINATION "${WORK}")
        endif()
    endforeach()
endforeach()
# the visualizer's own Network (same behavior, plus a log of every call) and probe program
file(COPY "${SRC}/visualizer/Network.hpp" "${SRC}/visualizer/Network.cpp" "${SRC}/visualizer/driver.cpp"
     DESTINATION "${WORK}")

set(FLAGS -std=c++17 -g)
if(SYSROOT)
    list(APPEND FLAGS -isysroot "${SYSROOT}")
endif()
set(BASE Node.cpp Component.cpp Network.cpp VoltageSource.cpp CurrentSource.cpp Resistor.cpp driver.cpp)
set(EXTRA_1 "")
set(EXTRA_2 VoltageDivider.cpp)
set(EXTRA_3 CurrentDivider.cpp)
set(EXTRA_4 VoltageDivider.cpp PracticalVsCircuit.cpp)

set(OUT "P10VIZ\t1\n")
set(SUMMARY "")
foreach(stage 1 2 3 4)
    execute_process(
        COMMAND "${CXX}" ${FLAGS} -DSTAGE=${stage} ${BASE} ${EXTRA_${stage}} -o "viz${stage}"
        WORKING_DIRECTORY "${WORK}"
        RESULT_VARIABLE rc OUTPUT_VARIABLE out ERROR_VARIABLE err)
    if(NOT rc EQUAL 0)
        set(log "${out}${err}")
        string(REPLACE "${WORK}/" "" log "${log}")
        string(LENGTH "${log}" len)
        if(len GREATER 6000)
            string(SUBSTRING "${log}" 0 6000 log)
        endif()
        string(REPLACE "\n" "\nLOG\t" log "${log}")
        set(OUT "${OUT}STAGE\t${stage}\tbuildfail\nLOG\t${log}\n")
        set(SUMMARY "${SUMMARY}  Stage ${stage}: does not compile yet\n")
    else()
        execute_process(
            COMMAND "${WORK}/viz${stage}"
            WORKING_DIRECTORY "${WORK}" TIMEOUT 10
            RESULT_VARIABLE rc OUTPUT_VARIABLE out ERROR_VARIABLE err)
        set(OUT "${OUT}STAGE\t${stage}\trun\n${out}\nEXIT\t${rc}\n")
        set(SUMMARY "${SUMMARY}  Stage ${stage}: ran\n")
    endif()
endforeach()

file(WRITE "${SRC}/circuit_trace.txt" "${OUT}")
message("\nCircuit trace written to:\n  ${SRC}/circuit_trace.txt\n${SUMMARY}Load this file in the circuit visualizer on the Problem 10 Canvas page to see the circuits your code builds.\n")