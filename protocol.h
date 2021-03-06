/*
 Copyright (c) 2017 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef GIMX_NETWORK_PROTOCOL_H_
#define GIMX_NETWORK_PROTOCOL_H_

#include <stdint.h>

#ifdef WIN32
#define PACKED __attribute__((gcc_struct, packed))
#else
#define PACKED __attribute__((packed))
#endif

typedef enum {
    E_NETWORK_PACKET_CONTROLLER,
    E_NETWORK_PACKET_IN_REPORT,
    E_NETWORK_PACKET_EXIT,
    E_NETWORK_PACKET_SETCONFIG,
    E_NETWORK_PACKET_GETCONFIG,
    E_NETWORK_PACKET_SAVECALIBRATION, 
} e_network_packet_type;

typedef struct PACKED
{
  uint8_t packet_type; // E_NETWORK_PACKET_IN_REPORT
  uint8_t nbAxes; // number of elements in the following array
  struct PACKED
  {
    uint8_t index; // 1 MSB: 0 = relative axis, 1 = absolute axis, 7 LSB = index
    uint32_t value; // network byte order
  } axes[0];
} s_network_packet_in_report;

typedef struct PACKED
{
  uint8_t packet_type; // E_NETWORK_PACKET_CONTROLLER
  uint8_t controller_type;
} s_network_packet_controller;

/**
 * When adding new attributes to this struct, add it to the end.
 */
typedef struct PACKED
{
  uint8_t packet_type;
  float sensibility;
  int16_t dead_zone_x;
  int16_t dead_zone_y;
  float yx_ratio;
  float exponent_x;
  float exponent_y;

}s_network_packet_config;

#endif /* GIMX_NETWORK_PROTOCOL_H_ */
