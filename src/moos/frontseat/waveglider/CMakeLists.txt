set(PROTOS waveglider_sv2_frontseat_driver.proto waveglider_sv2_frontseat_driver_config.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})

set(SRC waveglider_sv2_frontseat_driver.cpp waveglider_sv2_codecs.cpp)

add_library(goby_frontseat_waveglider_sv2 SHARED ${SRC} ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(goby_frontseat_waveglider_sv2
  goby_moos
  ${PROTOBUF_LIBRARIES})

configure_file(iFrontSeat_waveglider.in ${goby_BIN_DIR}/iFrontSeat_waveglider @ONLY)
goby_install_lib(goby_frontseat_waveglider_sv2)
