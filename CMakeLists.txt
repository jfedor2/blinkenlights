cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/pico-sdk")
set(PICO_TINYUSB_PATH "${CMAKE_CURRENT_LIST_DIR}/tinyusb")

include(pico_sdk_import.cmake)

project(blinkenlights)

pico_sdk_init()

add_compile_options(-Wall)

add_executable(blinkenlights src/blinkenlights.cc src/descriptor.cc src/tinyusb_stuff.cc)

target_include_directories(blinkenlights PRIVATE src)

target_link_libraries(blinkenlights pico_stdlib tinyusb_device tinyusb_board)

pico_add_extra_outputs(blinkenlights)
