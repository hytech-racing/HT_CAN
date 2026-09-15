cmake_minimum_required(VERSION 3.13)
project(ht_can LANGUAGES CXX)

include(GNUInstallDirs)

set(PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(DBC_FILE "${PROTO_BINARY_DIR}/hytech.dbc")
set(PROTO_SCHEMA_DIR "${PROTO_BINARY_DIR}/proto")
set(PROTO_FILE "${PROTO_SCHEMA_DIR}/hytech.proto")
set(LEGACY_PROTO_FILE "${CMAKE_CURRENT_SOURCE_DIR}/proto/hytech.proto")
set(LIBRARY hytech_can_msgs_cpp_lib)
set(OBJECT_LIBRARY hytech_can_msgs_cpp_lib_object)

find_package(Protobuf REQUIRED CONFIG)

if(EXISTS "${LEGACY_PROTO_FILE}")
    # The legacy Drivebrain release archive ships a pre-generated schema.
    set(PROTO_SCHEMA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
    set(PROTO_FILE "${LEGACY_PROTO_FILE}")
else()
    find_package(Python3 REQUIRED COMPONENTS Interpreter)

    add_custom_command(
        OUTPUT "${PROTO_FILE}"
        BYPRODUCTS "${DBC_FILE}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${PROTO_BINARY_DIR}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${PROTO_SCHEMA_DIR}"
        COMMAND Python3::Interpreter -m cantools convert
                "${CMAKE_CURRENT_SOURCE_DIR}/PCAN_project/hytech.sym"
                "${DBC_FILE}"
        COMMAND Python3::Interpreter
                "${CMAKE_CURRENT_SOURCE_DIR}/dbc_to_proto/dbc_to_proto.py"
                "${DBC_FILE}"
                "${PROTO_FILE}"
        DEPENDS
                "${CMAKE_CURRENT_SOURCE_DIR}/PCAN_project/hytech.sym"
                "${CMAKE_CURRENT_SOURCE_DIR}/dbc_to_proto/dbc_to_proto.py"
        VERBATIM
    )

    set_source_files_properties("${PROTO_FILE}" PROPERTIES GENERATED TRUE)
endif()

add_library(${OBJECT_LIBRARY} OBJECT "${PROTO_FILE}")

target_include_directories(${OBJECT_LIBRARY} 
    PUBLIC $<BUILD_INTERFACE:${PROTO_BINARY_DIR}>)

target_link_libraries(${OBJECT_LIBRARY} 
    PUBLIC protobuf::libprotobuf)

protobuf_generate(TARGET ${OBJECT_LIBRARY} IMPORT_DIRS "${PROTO_SCHEMA_DIR}"
                PROTOC_OUT_DIR "${PROTO_BINARY_DIR}")

add_library(${LIBRARY} STATIC $<TARGET_OBJECTS:${OBJECT_LIBRARY}>)

target_include_directories(
        ${LIBRARY} PUBLIC $<BUILD_INTERFACE:${PROTO_BINARY_DIR}>
                        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(${LIBRARY} PUBLIC protobuf::libprotobuf)

install(
    FILES "${PROTO_BINARY_DIR}/hytech.pb.h"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    TARGETS ${LIBRARY}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
