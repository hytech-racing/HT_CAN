// Generator version : v3.1
// DBC filename      : hytech_fd.dbc
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// DBC file version
#define VER_HYTECH_MAJ (6U)
#define VER_HYTECH_MIN (0U)

// include current dbc-driver compilation config
#include "hytech-config.h"

#ifdef HYTECH_USE_DIAG_MONITORS
// This file must define:
// base monitor struct
#include "canmonitorutil.h"

#endif // HYTECH_USE_DIAG_MONITORS


// DLC maximum value which is used as the limit for frame's data buffer size.
// Client can set its own value (not sure why) in driver-config
// or can test it on some limit specified by application
// e.g.: static_assert(TESTDB_MAX_DLC_VALUE <= APPLICATION_FRAME_DATA_SIZE, "Max DLC value in the driver is too big")
#ifndef HYTECH_MAX_DLC_VALUE
// The value which was found out by generator (real max value)
#define HYTECH_MAX_DLC_VALUE 8U
#endif

// The limit is used for setting frame's data bytes
#define HYTECH_VALIDATE_DLC(msgDlc) (((msgDlc) <= (HYTECH_MAX_DLC_VALUE)) ? (msgDlc) : (HYTECH_MAX_DLC_VALUE))

// Initial byte value to be filles in data bytes of the frame before pack signals
// User can define its own custom value in driver-config file
#ifndef HYTECH_INITIAL_BYTE_VALUE
#define HYTECH_INITIAL_BYTE_VALUE 0U
#endif


// def @INV3_STATUS CAN Message (112  0x70)
#define INV3_STATUS_IDE (0U)
#define INV3_STATUS_DLC (8U)
#define INV3_STATUS_CANID (0x70U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t system_ready : 1;                  //      Bits= 1

  uint8_t error : 1;                         //      Bits= 1

  uint8_t warning : 1;                       //      Bits= 1

  uint8_t quit_dc_on : 1;                    //      Bits= 1

  uint8_t dc_on : 1;                         //      Bits= 1

  uint8_t quit_inverter_on : 1;              //      Bits= 1

  uint8_t inverter_on : 1;                   //      Bits= 1

  uint8_t derating_on : 1;                   //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#else

  uint8_t system_ready;                      //      Bits= 1

  uint8_t error;                             //      Bits= 1

  uint8_t warning;                           //      Bits= 1

  uint8_t quit_dc_on;                        //      Bits= 1

  uint8_t dc_on;                             //      Bits= 1

  uint8_t quit_inverter_on;                  //      Bits= 1

  uint8_t inverter_on;                       //      Bits= 1

  uint8_t derating_on;                       //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_STATUS_t;

// def @INV3_TEMPS CAN Message (113  0x71)
#define INV3_TEMPS_IDE (0U)
#define INV3_TEMPS_DLC (6U)
#define INV3_TEMPS_CANID (0x71U)
// signal: @motor_temp_ro
#define HYTECH_motor_temp_ro_CovFactor (0.1)
#define HYTECH_motor_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_motor_temp_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )
// signal: @inverter_temp_ro
#define HYTECH_inverter_temp_ro_CovFactor (0.1)
#define HYTECH_inverter_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_inverter_temp_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )
// signal: @igbt_temp_ro
#define HYTECH_igbt_temp_ro_CovFactor (0.1)
#define HYTECH_igbt_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_igbt_temp_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_TEMPS_t;

// def @INV3_DYNAMICS CAN Message (114  0x72)
#define INV3_DYNAMICS_IDE (0U)
#define INV3_DYNAMICS_DLC (8U)
#define INV3_DYNAMICS_CANID (0x72U)
// signal: @actual_torque_nm_ro
#define HYTECH_actual_torque_nm_ro_CovFactor (0.0098)
#define HYTECH_actual_torque_nm_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.0098)) )
#define HYTECH_actual_torque_nm_ro_fromS(x) ( (((x) * (0.0098)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#else

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_DYNAMICS_t;

// def @INV3_POWER CAN Message (115  0x73)
#define INV3_POWER_IDE (0U)
#define INV3_POWER_DLC (8U)
#define INV3_POWER_CANID (0x73U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#else

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_POWER_t;

// def @INV3_FEEDBACK CAN Message (116  0x74)
#define INV3_FEEDBACK_IDE (0U)
#define INV3_FEEDBACK_DLC (8U)
#define INV3_FEEDBACK_CANID (0x74U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_FEEDBACK_t;

// def @INV4_STATUS CAN Message (117  0x75)
#define INV4_STATUS_IDE (0U)
#define INV4_STATUS_DLC (8U)
#define INV4_STATUS_CANID (0x75U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t system_ready : 1;                  //      Bits= 1

  uint8_t error : 1;                         //      Bits= 1

  uint8_t warning : 1;                       //      Bits= 1

  uint8_t quit_dc_on : 1;                    //      Bits= 1

  uint8_t dc_on : 1;                         //      Bits= 1

  uint8_t quit_inverter_on : 1;              //      Bits= 1

  uint8_t inverter_on : 1;                   //      Bits= 1

  uint8_t derating_on : 1;                   //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#else

  uint8_t system_ready;                      //      Bits= 1

  uint8_t error;                             //      Bits= 1

  uint8_t warning;                           //      Bits= 1

  uint8_t quit_dc_on;                        //      Bits= 1

  uint8_t dc_on;                             //      Bits= 1

  uint8_t quit_inverter_on;                  //      Bits= 1

  uint8_t inverter_on;                       //      Bits= 1

  uint8_t derating_on;                       //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_STATUS_t;

// def @INV4_TEMPS CAN Message (118  0x76)
#define INV4_TEMPS_IDE (0U)
#define INV4_TEMPS_DLC (6U)
#define INV4_TEMPS_CANID (0x76U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_TEMPS_t;

// def @INV4_DYNAMICS CAN Message (119  0x77)
#define INV4_DYNAMICS_IDE (0U)
#define INV4_DYNAMICS_DLC (8U)
#define INV4_DYNAMICS_CANID (0x77U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#else

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_DYNAMICS_t;

// def @INV4_POWER CAN Message (120  0x78)
#define INV4_POWER_IDE (0U)
#define INV4_POWER_DLC (8U)
#define INV4_POWER_CANID (0x78U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#else

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_POWER_t;

// def @INV4_FEEDBACK CAN Message (121  0x79)
#define INV4_FEEDBACK_IDE (0U)
#define INV4_FEEDBACK_DLC (8U)
#define INV4_FEEDBACK_CANID (0x79U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_FEEDBACK_t;

// def @INV1_STATUS CAN Message (128  0x80)
#define INV1_STATUS_IDE (0U)
#define INV1_STATUS_DLC (8U)
#define INV1_STATUS_CANID (0x80U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t system_ready : 1;                  //      Bits= 1

  uint8_t error : 1;                         //      Bits= 1

  uint8_t warning : 1;                       //      Bits= 1

  uint8_t quit_dc_on : 1;                    //      Bits= 1

  uint8_t dc_on : 1;                         //      Bits= 1

  uint8_t quit_inverter_on : 1;              //      Bits= 1

  uint8_t inverter_on : 1;                   //      Bits= 1

  uint8_t derating_on : 1;                   //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#else

  uint8_t system_ready;                      //      Bits= 1

  uint8_t error;                             //      Bits= 1

  uint8_t warning;                           //      Bits= 1

  uint8_t quit_dc_on;                        //      Bits= 1

  uint8_t dc_on;                             //      Bits= 1

  uint8_t quit_inverter_on;                  //      Bits= 1

  uint8_t inverter_on;                       //      Bits= 1

  uint8_t derating_on;                       //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_STATUS_t;

// def @INV1_TEMPS CAN Message (129  0x81)
#define INV1_TEMPS_IDE (0U)
#define INV1_TEMPS_DLC (6U)
#define INV1_TEMPS_CANID (0x81U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_TEMPS_t;

// def @INV1_DYNAMICS CAN Message (130  0x82)
#define INV1_DYNAMICS_IDE (0U)
#define INV1_DYNAMICS_DLC (8U)
#define INV1_DYNAMICS_CANID (0x82U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#else

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_DYNAMICS_t;

// def @INV1_POWER CAN Message (131  0x83)
#define INV1_POWER_IDE (0U)
#define INV1_POWER_DLC (8U)
#define INV1_POWER_CANID (0x83U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#else

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_POWER_t;

// def @INV1_FEEDBACK CAN Message (132  0x84)
#define INV1_FEEDBACK_IDE (0U)
#define INV1_FEEDBACK_DLC (8U)
#define INV1_FEEDBACK_CANID (0x84U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_FEEDBACK_t;

// def @INV2_STATUS CAN Message (133  0x85)
#define INV2_STATUS_IDE (0U)
#define INV2_STATUS_DLC (8U)
#define INV2_STATUS_CANID (0x85U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t system_ready : 1;                  //      Bits= 1

  uint8_t error : 1;                         //      Bits= 1

  uint8_t warning : 1;                       //      Bits= 1

  uint8_t quit_dc_on : 1;                    //      Bits= 1

  uint8_t dc_on : 1;                         //      Bits= 1

  uint8_t quit_inverter_on : 1;              //      Bits= 1

  uint8_t inverter_on : 1;                   //      Bits= 1

  uint8_t derating_on : 1;                   //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#else

  uint8_t system_ready;                      //      Bits= 1

  uint8_t error;                             //      Bits= 1

  uint8_t warning;                           //      Bits= 1

  uint8_t quit_dc_on;                        //      Bits= 1

  uint8_t dc_on;                             //      Bits= 1

  uint8_t quit_inverter_on;                  //      Bits= 1

  uint8_t inverter_on;                       //      Bits= 1

  uint8_t derating_on;                       //      Bits= 1

  uint16_t dc_bus_voltage;                   //      Bits=16 Unit:'V'

  uint16_t diagnostic_number;                //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_STATUS_t;

// def @INV2_TEMPS CAN Message (134  0x86)
#define INV2_TEMPS_IDE (0U)
#define INV2_TEMPS_DLC (6U)
#define INV2_TEMPS_CANID (0x86U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t motor_temp_ro;                     //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t inverter_temp_ro;                  //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t igbt_temp_ro;                      //  [-] Bits=16 Factor= 0.1             Unit:'C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t igbt_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_TEMPS_t;

// def @INV2_DYNAMICS CAN Message (135  0x87)
#define INV2_DYNAMICS_IDE (0U)
#define INV2_DYNAMICS_DLC (8U)
#define INV2_DYNAMICS_CANID (0x87U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#else

  uint32_t actual_power_w;                   //      Bits=32

  int16_t actual_torque_nm_ro;               //  [-] Bits=16 Factor= 0.0098

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t actual_torque_nm_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t actual_speed_rpm;                  //  [-] Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_DYNAMICS_t;

// def @INV2_POWER CAN Message (136  0x88)
#define INV2_POWER_IDE (0U)
#define INV2_POWER_DLC (8U)
#define INV2_POWER_CANID (0x88U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#else

  int32_t active_power_w;                    //  [-] Bits=32

  int32_t reactive_power_var;                //  [-] Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_POWER_t;

// def @INV2_FEEDBACK CAN Message (137  0x89)
#define INV2_FEEDBACK_IDE (0U)
#define INV2_FEEDBACK_DLC (8U)
#define INV2_FEEDBACK_CANID (0x89U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_FEEDBACK_t;

// def @INV3_CONTROL_WORD CAN Message (144  0x90)
#define INV3_CONTROL_WORD_IDE (0U)
#define INV3_CONTROL_WORD_DLC (2U)
#define INV3_CONTROL_WORD_CANID (0x90U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t inverter_enable : 1;               //      Bits= 1

  uint8_t hv_enable : 1;                     //      Bits= 1

  uint8_t driver_enable : 1;                 //      Bits= 1

  uint8_t remove_error : 1;                  //      Bits= 1

#else

  uint8_t inverter_enable;                   //      Bits= 1

  uint8_t hv_enable;                         //      Bits= 1

  uint8_t driver_enable;                     //      Bits= 1

  uint8_t remove_error;                      //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_CONTROL_WORD_t;

// def @INV4_CONTROL_WORD CAN Message (145  0x91)
#define INV4_CONTROL_WORD_IDE (0U)
#define INV4_CONTROL_WORD_DLC (2U)
#define INV4_CONTROL_WORD_CANID (0x91U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t inverter_enable : 1;               //      Bits= 1

  uint8_t hv_enable : 1;                     //      Bits= 1

  uint8_t driver_enable : 1;                 //      Bits= 1

  uint8_t remove_error : 1;                  //      Bits= 1

#else

  uint8_t inverter_enable;                   //      Bits= 1

  uint8_t hv_enable;                         //      Bits= 1

  uint8_t driver_enable;                     //      Bits= 1

  uint8_t remove_error;                      //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_CONTROL_WORD_t;

// def @INV1_CONTROL_WORD CAN Message (146  0x92)
#define INV1_CONTROL_WORD_IDE (0U)
#define INV1_CONTROL_WORD_DLC (2U)
#define INV1_CONTROL_WORD_CANID (0x92U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t inverter_enable : 1;               //      Bits= 1

  uint8_t hv_enable : 1;                     //      Bits= 1

  uint8_t driver_enable : 1;                 //      Bits= 1

  uint8_t remove_error : 1;                  //      Bits= 1

#else

  uint8_t inverter_enable;                   //      Bits= 1

  uint8_t hv_enable;                         //      Bits= 1

  uint8_t driver_enable;                     //      Bits= 1

  uint8_t remove_error;                      //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_CONTROL_WORD_t;

// def @INV2_CONTROL_WORD CAN Message (147  0x93)
#define INV2_CONTROL_WORD_IDE (0U)
#define INV2_CONTROL_WORD_DLC (2U)
#define INV2_CONTROL_WORD_CANID (0x93U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t inverter_enable : 1;               //      Bits= 1

  uint8_t hv_enable : 1;                     //      Bits= 1

  uint8_t driver_enable : 1;                 //      Bits= 1

  uint8_t remove_error : 1;                  //      Bits= 1

#else

  uint8_t inverter_enable;                   //      Bits= 1

  uint8_t hv_enable;                         //      Bits= 1

  uint8_t driver_enable;                     //      Bits= 1

  uint8_t remove_error;                      //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_CONTROL_WORD_t;

// def @INV3_CONTROL_INPUT CAN Message (151  0x97)
#define INV3_CONTROL_INPUT_IDE (0U)
#define INV3_CONTROL_INPUT_DLC (6U)
#define INV3_CONTROL_INPUT_CANID (0x97U)
// signal: @positive_torque_limit_ro
#define HYTECH_positive_torque_limit_ro_CovFactor (0.0098)
#define HYTECH_positive_torque_limit_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.0098)) )
#define HYTECH_positive_torque_limit_ro_fromS(x) ( (((x) * (0.0098)) + (0.0)) )
// signal: @negative_torque_limit_ro
#define HYTECH_negative_torque_limit_ro_CovFactor (0.0098)
#define HYTECH_negative_torque_limit_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.0098)) )
#define HYTECH_negative_torque_limit_ro_fromS(x) ( (((x) * (0.0098)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_CONTROL_INPUT_t;

// def @INV4_CONTROL_INPUT CAN Message (152  0x98)
#define INV4_CONTROL_INPUT_IDE (0U)
#define INV4_CONTROL_INPUT_DLC (6U)
#define INV4_CONTROL_INPUT_CANID (0x98U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_CONTROL_INPUT_t;

// def @INV1_CONTROL_INPUT CAN Message (153  0x99)
#define INV1_CONTROL_INPUT_IDE (0U)
#define INV1_CONTROL_INPUT_DLC (6U)
#define INV1_CONTROL_INPUT_CANID (0x99U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_CONTROL_INPUT_t;

// def @PEDALS_SYSTEM_DATA CAN Message (192  0xc0)
#define PEDALS_SYSTEM_DATA_IDE (0U)
#define PEDALS_SYSTEM_DATA_DLC (5U)
#define PEDALS_SYSTEM_DATA_CANID (0xc0U)
// signal: @accel_pedal_ro
#define HYTECH_accel_pedal_ro_CovFactor (0.000015259)
#define HYTECH_accel_pedal_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.000015259)) )
#define HYTECH_accel_pedal_ro_fromS(x) ( (((x) * (0.000015259)) + (0.0)) )
// signal: @brake_pedal_ro
#define HYTECH_brake_pedal_ro_CovFactor (0.000015259)
#define HYTECH_brake_pedal_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.000015259)) )
#define HYTECH_brake_pedal_ro_fromS(x) ( (((x) * (0.000015259)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t accel_implausible : 1;               //      Bits= 1

  uint8_t brake_implausible : 1;               //      Bits= 1

  uint8_t brake_pedal_active : 1;              //      Bits= 1

  uint8_t accel_pedal_active : 1;              //      Bits= 1

  uint8_t mechanical_brake_active : 1;         //      Bits= 1

  // brake and accel are pressed
  uint8_t brake_accel_implausibility : 1;      //      Bits= 1

  // a pedal implausibility has been present for longer than allowed
  uint8_t implaus_exceeded_max_duration : 1;   //      Bits= 1

  // the scaled accelerator pedal value
  uint16_t accel_pedal_ro;                     //      Bits=16 Factor= 0.000015259

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t accel_pedal_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the scaled brake pedal value between 0 and 1
  uint16_t brake_pedal_ro;                     //      Bits=16 Factor= 0.000015259

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_pedal_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint8_t accel_implausible;                   //      Bits= 1

  uint8_t brake_implausible;                   //      Bits= 1

  uint8_t brake_pedal_active;                  //      Bits= 1

  uint8_t accel_pedal_active;                  //      Bits= 1

  uint8_t mechanical_brake_active;             //      Bits= 1

  // brake and accel are pressed
  uint8_t brake_accel_implausibility;          //      Bits= 1

  // a pedal implausibility has been present for longer than allowed
  uint8_t implaus_exceeded_max_duration;       //      Bits= 1

  // the scaled accelerator pedal value
  uint16_t accel_pedal_ro;                     //      Bits=16 Factor= 0.000015259

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t accel_pedal_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the scaled brake pedal value between 0 and 1
  uint16_t brake_pedal_ro;                     //      Bits=16 Factor= 0.000015259

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_pedal_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} PEDALS_SYSTEM_DATA_t;

// def @BMS_BOARD_DETAILED_TEMPS CAN Message (214  0xd6)
#define BMS_BOARD_DETAILED_TEMPS_IDE (0U)
#define BMS_BOARD_DETAILED_TEMPS_DLC (5U)
#define BMS_BOARD_DETAILED_TEMPS_CANID (0xd6U)
// signal: @temp_0_ro
#define HYTECH_temp_0_ro_CovFactor (0.01)
#define HYTECH_temp_0_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_temp_0_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @temp_1_ro
#define HYTECH_temp_1_ro_CovFactor (0.01)
#define HYTECH_temp_1_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_temp_1_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t ic_id : 4;                         //      Bits= 4

  int16_t temp_0_ro;                         //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t temp_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t temp_1_ro;                         //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t temp_1_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint8_t ic_id;                             //      Bits= 4

  int16_t temp_0_ro;                         //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t temp_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t temp_1_ro;                         //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t temp_1_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_BOARD_DETAILED_TEMPS_t;

// def @BMS_VOLTAGES CAN Message (215  0xd7)
#define BMS_VOLTAGES_IDE (0U)
#define BMS_VOLTAGES_DLC (8U)
#define BMS_VOLTAGES_CANID (0xd7U)
// signal: @average_cell_voltage_ro
#define HYTECH_average_cell_voltage_ro_CovFactor (0.0001)
#define HYTECH_average_cell_voltage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_average_cell_voltage_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @min_cell_voltage_ro
#define HYTECH_min_cell_voltage_ro_CovFactor (0.0001)
#define HYTECH_min_cell_voltage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_min_cell_voltage_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @max_cell_voltage_ro
#define HYTECH_max_cell_voltage_ro_CovFactor (0.0001)
#define HYTECH_max_cell_voltage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_max_cell_voltage_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @total_pack_voltage_ro
#define HYTECH_total_pack_voltage_ro_CovFactor (0.01)
#define HYTECH_total_pack_voltage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_total_pack_voltage_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t average_cell_voltage_ro;          //      Bits=16 Factor= 0.0001          Unit:'V'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t average_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t min_cell_voltage_ro;              //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t max_cell_voltage_ro;              //      Bits=16 Factor= 0.0001          Unit:'V'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t total_pack_voltage_ro;            //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t total_pack_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t average_cell_voltage_ro;          //      Bits=16 Factor= 0.0001          Unit:'V'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t average_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t min_cell_voltage_ro;              //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t max_cell_voltage_ro;              //      Bits=16 Factor= 0.0001          Unit:'V'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_cell_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t total_pack_voltage_ro;            //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t total_pack_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_VOLTAGES_t;

// def @BMS_DETAILED_VOLTAGES CAN Message (216  0xd8)
#define BMS_DETAILED_VOLTAGES_IDE (0U)
#define BMS_DETAILED_VOLTAGES_DLC (7U)
#define BMS_DETAILED_VOLTAGES_CANID (0xd8U)
// signal: @voltage_0_ro
#define HYTECH_voltage_0_ro_CovFactor (0.0001)
#define HYTECH_voltage_0_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_voltage_0_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @voltage_1_ro
#define HYTECH_voltage_1_ro_CovFactor (0.0001)
#define HYTECH_voltage_1_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_voltage_1_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @voltage_2_ro
#define HYTECH_voltage_2_ro_CovFactor (0.0001)
#define HYTECH_voltage_2_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_voltage_2_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t group_id : 4;                      //      Bits= 4

  uint8_t ic_id : 4;                         //      Bits= 4

  uint16_t voltage_0_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t voltage_1_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t voltage_2_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_2_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint8_t group_id;                          //      Bits= 4

  uint8_t ic_id;                             //      Bits= 4

  uint16_t voltage_0_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t voltage_1_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t voltage_2_ro;                     //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t voltage_2_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_DETAILED_VOLTAGES_t;

// def @BMS_TEMPS CAN Message (217  0xd9)
#define BMS_TEMPS_IDE (0U)
#define BMS_TEMPS_DLC (6U)
#define BMS_TEMPS_CANID (0xd9U)
// signal: @max_board_temp_ro
#define HYTECH_max_board_temp_ro_CovFactor (0.01)
#define HYTECH_max_board_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_max_board_temp_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @min_cell_temp_ro
#define HYTECH_min_cell_temp_ro_CovFactor (0.01)
#define HYTECH_min_cell_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_min_cell_temp_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @max_cell_temp_ro
#define HYTECH_max_cell_temp_ro_CovFactor (0.01)
#define HYTECH_max_cell_temp_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_max_cell_temp_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t max_board_temp_ro;                 //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_board_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t min_cell_temp_ro;                  //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t max_cell_temp_ro;                  //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_cell_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t max_board_temp_ro;                 //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_board_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t min_cell_temp_ro;                  //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t max_cell_temp_ro;                  //  [-] Bits=16 Factor= 0.01            Unit:'Deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t max_cell_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_TEMPS_t;

// def @BMS_DETAILED_TEMPS CAN Message (218  0xda)
#define BMS_DETAILED_TEMPS_IDE (0U)
#define BMS_DETAILED_TEMPS_DLC (7U)
#define BMS_DETAILED_TEMPS_CANID (0xdaU)
// signal: @thermistor_id_0_ro
#define HYTECH_thermistor_id_0_ro_CovFactor (0.01)
#define HYTECH_thermistor_id_0_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_thermistor_id_0_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @thermistor_id_1_ro
#define HYTECH_thermistor_id_1_ro_CovFactor (0.01)
#define HYTECH_thermistor_id_1_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_thermistor_id_1_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @thermistor_id_2_ro
#define HYTECH_thermistor_id_2_ro_CovFactor (0.01)
#define HYTECH_thermistor_id_2_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_thermistor_id_2_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t group_id : 4;                      //      Bits= 4

  uint8_t ic_id : 4;                         //      Bits= 4

  int16_t thermistor_id_0_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t thermistor_id_1_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t thermistor_id_2_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_2_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint8_t group_id;                          //      Bits= 4

  uint8_t ic_id;                             //      Bits= 4

  int16_t thermistor_id_0_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t thermistor_id_1_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t thermistor_id_2_ro;                //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_id_2_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_DETAILED_TEMPS_t;

// def @BMS_STATUS CAN Message (219  0xdb)
#define BMS_STATUS_IDE (0U)
#define BMS_STATUS_DLC (1U)
#define BMS_STATUS_CANID (0xdbU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t acu_state;                         //      Bits= 8

#else

  uint8_t acu_state;                         //      Bits= 8

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BMS_STATUS_t;

// def @CCU_STATUS CAN Message (221  0xdd)
#define CCU_STATUS_IDE (0U)
#define CCU_STATUS_DLC (1U)
#define CCU_STATUS_CANID (0xddU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t charger_enabled : 1;               //      Bits= 1

#else

  uint8_t charger_enabled;                   //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} CCU_STATUS_t;

// def @REAR_SUSPENSION CAN Message (228  0xe4)
#define REAR_SUSPENSION_IDE (0U)
#define REAR_SUSPENSION_DLC (8U)
#define REAR_SUSPENSION_CANID (0xe4U)
// signal: @rl_shock_pot_ro
#define HYTECH_rl_shock_pot_ro_CovFactor (0.01)
#define HYTECH_rl_shock_pot_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_rl_shock_pot_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @rr_shock_pot_ro
#define HYTECH_rr_shock_pot_ro_CovFactor (0.01)
#define HYTECH_rr_shock_pot_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_rr_shock_pot_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t rl_load_cell;                     //      Bits=16

  uint16_t rr_load_cell;                     //      Bits=16

  uint16_t rl_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t rl_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t rr_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t rr_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t rl_load_cell;                     //      Bits=16

  uint16_t rr_load_cell;                     //      Bits=16

  uint16_t rl_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t rl_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t rr_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t rr_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} REAR_SUSPENSION_t;

// def @FRONT_SUSPENSION CAN Message (237  0xed)
#define FRONT_SUSPENSION_IDE (0U)
#define FRONT_SUSPENSION_DLC (8U)
#define FRONT_SUSPENSION_CANID (0xedU)
// signal: @fl_shock_pot_ro
#define HYTECH_fl_shock_pot_ro_CovFactor (0.01)
#define HYTECH_fl_shock_pot_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_fl_shock_pot_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @fr_shock_pot_ro
#define HYTECH_fr_shock_pot_ro_CovFactor (0.01)
#define HYTECH_fr_shock_pot_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_fr_shock_pot_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t fl_load_cell;                     //      Bits=16

  uint16_t fl_shock_pot_ro;                  //      Bits=16 Factor= 0.01            Unit:'mm'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t fl_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t fr_load_cell;                     //      Bits=16

  uint16_t fr_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t fr_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t fl_load_cell;                     //      Bits=16

  uint16_t fl_shock_pot_ro;                  //      Bits=16 Factor= 0.01            Unit:'mm'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t fl_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t fr_load_cell;                     //      Bits=16

  uint16_t fr_shock_pot_ro;                  //      Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t fr_shock_pot_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FRONT_SUSPENSION_t;

// def @REAR_THERMISTORS_DATA CAN Message (238  0xee)
#define REAR_THERMISTORS_DATA_IDE (0U)
#define REAR_THERMISTORS_DATA_DLC (8U)
#define REAR_THERMISTORS_DATA_CANID (0xeeU)
// signal: @thermistor_0_deg_C_ro
#define HYTECH_thermistor_0_deg_C_ro_CovFactor (0.005)
#define HYTECH_thermistor_0_deg_C_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_0_deg_C_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )
// signal: @thermistor_1_deg_C_ro
#define HYTECH_thermistor_1_deg_C_ro_CovFactor (0.005)
#define HYTECH_thermistor_1_deg_C_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_1_deg_C_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )
// signal: @thermistor_2_deg_C_ro
#define HYTECH_thermistor_2_deg_C_ro_CovFactor (0.005)
#define HYTECH_thermistor_2_deg_C_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_2_deg_C_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )
// signal: @thermistor_3_deg_C_ro
#define HYTECH_thermistor_3_deg_C_ro_CovFactor (0.005)
#define HYTECH_thermistor_3_deg_C_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_3_deg_C_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t thermistor_0_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_0_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_1_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_1_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_2_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_2_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_3_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_3_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t thermistor_0_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_0_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_1_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_1_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_2_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_2_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t thermistor_3_deg_C_ro;            //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_3_deg_C_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} REAR_THERMISTORS_DATA_t;

// def @DRIVEBRAIN_TORQUE_LIM_INPUT CAN Message (241  0xf1)
#define DRIVEBRAIN_TORQUE_LIM_INPUT_IDE (0U)
#define DRIVEBRAIN_TORQUE_LIM_INPUT_DLC (8U)
#define DRIVEBRAIN_TORQUE_LIM_INPUT_CANID (0xf1U)
// signal: @drivebrain_torque_fl_ro
#define HYTECH_drivebrain_torque_fl_ro_CovFactor (0.01)
#define HYTECH_drivebrain_torque_fl_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_drivebrain_torque_fl_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @drivebrain_torque_fr_ro
#define HYTECH_drivebrain_torque_fr_ro_CovFactor (0.01)
#define HYTECH_drivebrain_torque_fr_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_drivebrain_torque_fr_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @drivebrain_torque_rl_ro
#define HYTECH_drivebrain_torque_rl_ro_CovFactor (0.01)
#define HYTECH_drivebrain_torque_rl_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_drivebrain_torque_rl_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @drivebrain_torque_rr_ro
#define HYTECH_drivebrain_torque_rr_ro_CovFactor (0.01)
#define HYTECH_drivebrain_torque_rr_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_drivebrain_torque_rr_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t drivebrain_torque_fl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_fr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t drivebrain_torque_fl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_fr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_TORQUE_LIM_INPUT_t;

// def @DRIVEBRAIN_SPEED_SET_INPUT CAN Message (242  0xf2)
#define DRIVEBRAIN_SPEED_SET_INPUT_IDE (0U)
#define DRIVEBRAIN_SPEED_SET_INPUT_DLC (8U)
#define DRIVEBRAIN_SPEED_SET_INPUT_CANID (0xf2U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t drivebrain_set_rpm_fl;            //      Bits=16

  uint16_t drivebrain_set_rpm_fr;            //      Bits=16

  uint16_t drivebrain_set_rpm_rl;            //      Bits=16

  uint16_t drivebrain_set_rpm_rr;            //      Bits=16

#else

  uint16_t drivebrain_set_rpm_fl;            //      Bits=16

  uint16_t drivebrain_set_rpm_fr;            //      Bits=16

  uint16_t drivebrain_set_rpm_rl;            //      Bits=16

  uint16_t drivebrain_set_rpm_rr;            //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_SPEED_SET_INPUT_t;

// def @DRIVEBRAIN_DESIRED_TORQUE_INPUT CAN Message (243  0xf3)
#define DRIVEBRAIN_DESIRED_TORQUE_INPUT_IDE (0U)
#define DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC (8U)
#define DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID (0xf3U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t drivebrain_torque_fl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_fr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t drivebrain_torque_fl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_fr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rl_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t drivebrain_torque_rr_ro;           //  [-] Bits=16 Factor= 0.01

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_torque_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_DESIRED_TORQUE_INPUT_t;

// def @DRIVEBRAIN_STEERING_INPUT CAN Message (244  0xf4)
#define DRIVEBRAIN_STEERING_INPUT_IDE (0U)
#define DRIVEBRAIN_STEERING_INPUT_DLC (2U)
#define DRIVEBRAIN_STEERING_INPUT_CANID (0xf4U)
// signal: @drivebrain_steering_ro
#define HYTECH_drivebrain_steering_ro_CovFactor (0.01)
#define HYTECH_drivebrain_steering_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_drivebrain_steering_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t drivebrain_steering_ro;            //  [-] Bits=16 Factor= 0.01            Unit:'degrees'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_steering_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t drivebrain_steering_ro;            //  [-] Bits=16 Factor= 0.01            Unit:'degrees'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t drivebrain_steering_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_STEERING_INPUT_t;

// def @FRONT_THERMISTORS CAN Message (245  0xf5)
#define FRONT_THERMISTORS_IDE (0U)
#define FRONT_THERMISTORS_DLC (8U)
#define FRONT_THERMISTORS_CANID (0xf5U)
// signal: @thermistor_motor_fl_ro
#define HYTECH_thermistor_motor_fl_ro_CovFactor (0.005)
#define HYTECH_thermistor_motor_fl_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_motor_fl_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )
// signal: @thermistor_motor_fr_ro
#define HYTECH_thermistor_motor_fr_ro_CovFactor (0.005)
#define HYTECH_thermistor_motor_fr_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.005)) )
#define HYTECH_thermistor_motor_fr_ro_fromS(x) ( (((x) * (0.005)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // Motor cooling loop temperature
  uint16_t thermistor_motor_fl_ro;           //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_motor_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  // Motor cooling loop temperature
  uint16_t thermistor_motor_fr_ro;           //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_motor_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // Motor cooling loop temperature
  uint16_t thermistor_motor_fl_ro;           //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_motor_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  // Motor cooling loop temperature
  uint16_t thermistor_motor_fr_ro;           //      Bits=16 Factor= 0.005           Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t thermistor_motor_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FRONT_THERMISTORS_t;

// Contains the voltage and current readings from the Energy Meter. Sent by the AMS.
// def @EM_MEASUREMENT CAN Message (256  0x100)
#define EM_MEASUREMENT_IDE (0U)
#define EM_MEASUREMENT_DLC (8U)
#define EM_MEASUREMENT_CANID (0x100U)
// signal: @em_current_ro
#define HYTECH_em_current_ro_CovFactor (0.000015259)
#define HYTECH_em_current_ro_toS(x) ( (int32_t) (((x) - (0.0)) / (0.000015259)) )
#define HYTECH_em_current_ro_fromS(x) ( (((x) * (0.000015259)) + (0.0)) )
// signal: @em_voltage_ro
#define HYTECH_em_voltage_ro_CovFactor (0.000015259)
#define HYTECH_em_voltage_ro_toS(x) ( (int32_t) (((x) - (0.0)) / (0.000015259)) )
#define HYTECH_em_voltage_ro_fromS(x) ( (((x) * (0.000015259)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // The current draw, in amps, measured by the Energy Meter.
  int32_t em_current_ro;                     //  [-] Bits=32 Factor= 0.000015259     Unit:'Coulombs'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_current_phys;
#endif // HYTECH_USE_SIGFLOAT

  // The voltage, in Volts, measured by the Energy Meter.
  int32_t em_voltage_ro;                     //  [-] Bits=32 Factor= 0.000015259     Unit:'Volts'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // The current draw, in amps, measured by the Energy Meter.
  int32_t em_current_ro;                     //  [-] Bits=32 Factor= 0.000015259     Unit:'Coulombs'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_current_phys;
#endif // HYTECH_USE_SIGFLOAT

  // The voltage, in Volts, measured by the Energy Meter.
  int32_t em_voltage_ro;                     //  [-] Bits=32 Factor= 0.000015259     Unit:'Volts'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_voltage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} EM_MEASUREMENT_t;

// def @INV2_CONTROL_INPUT CAN Message (258  0x102)
#define INV2_CONTROL_INPUT_IDE (0U)
#define INV2_CONTROL_INPUT_DLC (6U)
#define INV2_CONTROL_INPUT_CANID (0x102U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t speed_setpoint_rpm;                //  [-] Bits=16 Unit:'rpm'

  // Made up units from AMK
  int16_t positive_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t positive_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

  // AMK made up unit
  int16_t negative_torque_limit_ro;          //  [-] Bits=16 Factor= 0.0098          Unit:'Mn'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t negative_torque_limit_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_CONTROL_INPUT_t;

// def @INV3_CONTROL_PARAMETER CAN Message (259  0x103)
#define INV3_CONTROL_PARAMETER_IDE (0U)
#define INV3_CONTROL_PARAMETER_DLC (8U)
#define INV3_CONTROL_PARAMETER_CANID (0x103U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_CONTROL_PARAMETER_t;

// def @INV4_CONTROL_PARAMETER CAN Message (260  0x104)
#define INV4_CONTROL_PARAMETER_IDE (0U)
#define INV4_CONTROL_PARAMETER_DLC (8U)
#define INV4_CONTROL_PARAMETER_CANID (0x104U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_CONTROL_PARAMETER_t;

// def @INV1_CONTROL_PARAMETER CAN Message (261  0x105)
#define INV1_CONTROL_PARAMETER_IDE (0U)
#define INV1_CONTROL_PARAMETER_DLC (8U)
#define INV1_CONTROL_PARAMETER_CANID (0x105U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_CONTROL_PARAMETER_t;

// def @INV2_CONTROL_PARAMETER CAN Message (262  0x106)
#define INV2_CONTROL_PARAMETER_IDE (0U)
#define INV2_CONTROL_PARAMETER_DLC (8U)
#define INV2_CONTROL_PARAMETER_CANID (0x106U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#else

  uint16_t speed_control_kp;                 //      Bits=16

  uint16_t speed_control_ki;                 //      Bits=16

  uint16_t speed_control_kd;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_CONTROL_PARAMETER_t;

// def @ENERGY_METER_MEAS CAN Message (269  0x10d)
#define ENERGY_METER_MEAS_IDE (0U)
#define ENERGY_METER_MEAS_DLC (8U)
#define ENERGY_METER_MEAS_CANID (0x10dU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t current_A;                        //      Bits=32

  uint32_t voltage_V;                        //      Bits=32

#else

  uint32_t current_A;                        //      Bits=32

  uint32_t voltage_V;                        //      Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} ENERGY_METER_MEAS_t;

// def @INV3_OVERLOAD CAN Message (310  0x136)
#define INV3_OVERLOAD_IDE (0U)
#define INV3_OVERLOAD_DLC (4U)
#define INV3_OVERLOAD_CANID (0x136U)
// signal: @inverter_overload_percentage_ro
#define HYTECH_inverter_overload_percentage_ro_CovFactor (0.1)
#define HYTECH_inverter_overload_percentage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_inverter_overload_percentage_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )
// signal: @motor_overload_percentage_ro
#define HYTECH_motor_overload_percentage_ro_CovFactor (0.1)
#define HYTECH_motor_overload_percentage_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_motor_overload_percentage_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV3_OVERLOAD_t;

// def @INV4_OVERLOAD CAN Message (320  0x140)
#define INV4_OVERLOAD_IDE (0U)
#define INV4_OVERLOAD_DLC (4U)
#define INV4_OVERLOAD_CANID (0x140U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV4_OVERLOAD_t;

// def @INV1_OVERLOAD CAN Message (330  0x14a)
#define INV1_OVERLOAD_IDE (0U)
#define INV1_OVERLOAD_DLC (8U)
#define INV1_OVERLOAD_CANID (0x14aU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV1_OVERLOAD_t;

// def @INV2_OVERLOAD CAN Message (340  0x154)
#define INV2_OVERLOAD_IDE (0U)
#define INV2_OVERLOAD_DLC (4U)
#define INV2_OVERLOAD_CANID (0x154U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // the current overload of the inverter according to the i2t calc
  uint16_t inverter_overload_percentage_ro;      //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t inverter_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

  // the current overload of the motor according to the i2t calc
  uint16_t motor_overload_percentage_ro;         //      Bits=16 Factor= 0.1

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t motor_overload_percentage_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} INV2_OVERLOAD_t;

// def @CAR_STATES CAN Message (519  0x207)
#define CAR_STATES_IDE (0U)
#define CAR_STATES_DLC (3U)
#define CAR_STATES_CANID (0x207U)

// Value tables for @vehicle_state signal

#ifndef vehicle_state_CAR_STATES_TRACTIVE_SYSTEM_NOT_ACTIVE
#define vehicle_state_CAR_STATES_TRACTIVE_SYSTEM_NOT_ACTIVE (0)
#endif

#ifndef vehicle_state_CAR_STATES_TRACTIVE_SYSTEM_ACTIVE
#define vehicle_state_CAR_STATES_TRACTIVE_SYSTEM_ACTIVE (1)
#endif

#ifndef vehicle_state_CAR_STATES_WANTING_READY_TO_DRIVE
#define vehicle_state_CAR_STATES_WANTING_READY_TO_DRIVE (2)
#endif

#ifndef vehicle_state_CAR_STATES_READY_TO_DRIVE
#define vehicle_state_CAR_STATES_READY_TO_DRIVE (3)
#endif

#ifndef vehicle_state_CAR_STATES_WANTING_RECALIBRATE_PEDALS
#define vehicle_state_CAR_STATES_WANTING_RECALIBRATE_PEDALS (4)
#endif

#ifndef vehicle_state_CAR_STATES_RECALIBRATING_PEDALS
#define vehicle_state_CAR_STATES_RECALIBRATING_PEDALS (5)
#endif

#ifndef vehicle_state_CAR_STATES_WANTING_RECALIBRATE_STEERING
#define vehicle_state_CAR_STATES_WANTING_RECALIBRATE_STEERING (6)
#endif

#ifndef vehicle_state_CAR_STATES_RECALIBRATING_STEERING
#define vehicle_state_CAR_STATES_RECALIBRATING_STEERING (7)
#endif


// Value tables for @drivetrain_state signal

#ifndef drivetrain_state_CAR_STATES_NOT_CONNECTED
#define drivetrain_state_CAR_STATES_NOT_CONNECTED (0)
#endif

#ifndef drivetrain_state_CAR_STATES_NOT_ENABLED_NO_HV_PRESENT
#define drivetrain_state_CAR_STATES_NOT_ENABLED_NO_HV_PRESENT (1)
#endif

#ifndef drivetrain_state_CAR_STATES_NOT_ENABLED_HV_PRESENT
#define drivetrain_state_CAR_STATES_NOT_ENABLED_HV_PRESENT (2)
#endif

#ifndef drivetrain_state_CAR_STATES_INVERTERS_READY
#define drivetrain_state_CAR_STATES_INVERTERS_READY (3)
#endif

#ifndef drivetrain_state_CAR_STATES_INVERTERS_HV_ENABLED
#define drivetrain_state_CAR_STATES_INVERTERS_HV_ENABLED (4)
#endif

#ifndef drivetrain_state_CAR_STATES_ENABLED_DRIVE_MODE
#define drivetrain_state_CAR_STATES_ENABLED_DRIVE_MODE (5)
#endif

#ifndef drivetrain_state_CAR_STATES_ERROR
#define drivetrain_state_CAR_STATES_ERROR (6)
#endif

#ifndef drivetrain_state_CAR_STATES_CLEARING_ERRORS
#define drivetrain_state_CAR_STATES_CLEARING_ERRORS (7)
#endif


typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  //  0 : "TRACTIVE_SYSTEM_NOT_ACTIVE"
  //  1 : "TRACTIVE_SYSTEM_ACTIVE"
  //  2 : "WANTING_READY_TO_DRIVE"
  //  3 : "READY_TO_DRIVE"
  //  4 : "WANTING_RECALIBRATE_PEDALS"
  //  5 : "RECALIBRATING_PEDALS"
  //  6 : "WANTING_RECALIBRATE_STEERING"
  //  7 : "RECALIBRATING_STEERING"
  uint8_t vehicle_state;                     //      Bits= 8

  //  0 : "NOT_CONNECTED"
  //  1 : "NOT_ENABLED_NO_HV_PRESENT"
  //  2 : "NOT_ENABLED_HV_PRESENT"
  //  3 : "INVERTERS_READY"
  //  4 : "INVERTERS_HV_ENABLED"
  //  5 : "ENABLED_DRIVE_MODE"
  //  6 : "ERROR"
  //  7 : "CLEARING_ERRORS"
  uint8_t drivetrain_state;                  //      Bits= 8

  uint8_t drivebrain_in_control : 1;         //      Bits= 1

#else

  //  0 : "TRACTIVE_SYSTEM_NOT_ACTIVE"
  //  1 : "TRACTIVE_SYSTEM_ACTIVE"
  //  2 : "WANTING_READY_TO_DRIVE"
  //  3 : "READY_TO_DRIVE"
  //  4 : "WANTING_RECALIBRATE_PEDALS"
  //  5 : "RECALIBRATING_PEDALS"
  //  6 : "WANTING_RECALIBRATE_STEERING"
  //  7 : "RECALIBRATING_STEERING"
  uint8_t vehicle_state;                     //      Bits= 8

  //  0 : "NOT_CONNECTED"
  //  1 : "NOT_ENABLED_NO_HV_PRESENT"
  //  2 : "NOT_ENABLED_HV_PRESENT"
  //  3 : "INVERTERS_READY"
  //  4 : "INVERTERS_HV_ENABLED"
  //  5 : "ENABLED_DRIVE_MODE"
  //  6 : "ERROR"
  //  7 : "CLEARING_ERRORS"
  uint8_t drivetrain_state;                  //      Bits= 8

  uint8_t drivebrain_in_control;             //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} CAR_STATES_t;

// def @DASH_INPUT CAN Message (768  0x300)
#define DASH_INPUT_IDE (0U)
#define DASH_INPUT_DLC (3U)
#define DASH_INPUT_CANID (0x300U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t led_dimmer_button : 1;               //      Bits= 1

  uint8_t preset_button : 1;                   //      Bits= 1

  uint8_t motor_controller_cycle_button : 1;   //      Bits= 1

  uint8_t mode_button : 1;                     //      Bits= 1

  uint8_t start_button : 1;                    //      Bits= 1

  uint8_t data_button_is_pressed : 1;          //      Bits= 1

  uint8_t left_shifter_button : 1;             //      Bits= 1

  uint8_t right_shifter_button : 1;            //      Bits= 1

  // Dashboard dial position
  uint8_t dash_dial_mode;                      //      Bits= 8

  // Dim button on dash
  uint8_t dim_button : 1;                      //      Bits= 1

#else

  uint8_t led_dimmer_button;                   //      Bits= 1

  uint8_t preset_button;                       //      Bits= 1

  uint8_t motor_controller_cycle_button;       //      Bits= 1

  uint8_t mode_button;                         //      Bits= 1

  uint8_t start_button;                        //      Bits= 1

  uint8_t data_button_is_pressed;              //      Bits= 1

  uint8_t left_shifter_button;                 //      Bits= 1

  uint8_t right_shifter_button;                //      Bits= 1

  // Dashboard dial position
  uint8_t dash_dial_mode;                      //      Bits= 8

  // Dim button on dash
  uint8_t dim_button;                          //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DASH_INPUT_t;

// def @AERO_PRESSURE_SENSOR_22 CAN Message (800  0x320)
#define AERO_PRESSURE_SENSOR_22_IDE (0U)
#define AERO_PRESSURE_SENSOR_22_DLC (8U)
#define AERO_PRESSURE_SENSOR_22_CANID (0x320U)
// signal: @aero_channel_4_ro
#define HYTECH_aero_channel_4_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_4_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_4_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_5_ro
#define HYTECH_aero_channel_5_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_5_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_5_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_6_ro
#define HYTECH_aero_channel_6_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_6_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_6_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_7_ro
#define HYTECH_aero_channel_7_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_7_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_7_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_22_t;

// def @AERO_PRESSURE_SENSOR_32 CAN Message (816  0x330)
#define AERO_PRESSURE_SENSOR_32_IDE (0U)
#define AERO_PRESSURE_SENSOR_32_DLC (8U)
#define AERO_PRESSURE_SENSOR_32_CANID (0x330U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_32_t;

// def @AERO_PRESSURE_SENSOR_42 CAN Message (832  0x340)
#define AERO_PRESSURE_SENSOR_42_IDE (0U)
#define AERO_PRESSURE_SENSOR_42_DLC (8U)
#define AERO_PRESSURE_SENSOR_42_CANID (0x340U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_42_t;

// def @AERO_PRESSURE_SENSOR_11 CAN Message (1008 0x3f0)
#define AERO_PRESSURE_SENSOR_11_IDE (0U)
#define AERO_PRESSURE_SENSOR_11_DLC (8U)
#define AERO_PRESSURE_SENSOR_11_CANID (0x3f0U)
// signal: @aero_channel_0_ro
#define HYTECH_aero_channel_0_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_0_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_0_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_1_ro
#define HYTECH_aero_channel_1_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_1_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_1_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_2_ro
#define HYTECH_aero_channel_2_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_2_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_2_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )
// signal: @aero_channel_3_ro
#define HYTECH_aero_channel_3_ro_CovFactor (0.142857142)
#define HYTECH_aero_channel_3_ro_toS(x) ( (uint16_t) (((x) - (-53000.0)) / (0.142857142)) )
#define HYTECH_aero_channel_3_ro_fromS(x) ( (((x) * (0.142857142)) + (-53000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_11_t;

// def @AERO_PRESSURE_SENSOR_12 CAN Message (1012 0x3f4)
#define AERO_PRESSURE_SENSOR_12_IDE (0U)
#define AERO_PRESSURE_SENSOR_12_DLC (8U)
#define AERO_PRESSURE_SENSOR_12_CANID (0x3f4U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_4_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_5_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_6_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_7_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_12_t;

// Forwarded directly from the Energy Meter with no modifications. See datasheet for more specifications.
// def @EM_STATUS CAN Message (1024 0x400)
#define EM_STATUS_IDE (0U)
#define EM_STATUS_DLC (2U)
#define EM_STATUS_CANID (0x400U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t voltage_gain : 4;                  //      Bits= 4 Unit:'none'

  uint8_t current_gain : 4;                  //      Bits= 4 Unit:'none'

  // Whether or not the energy meter is reading an over-voltage error.
  uint8_t overvoltage_error : 1;             //      Bits= 1 Unit:'none'

  // Whether or not the Energy Meter is reading an over-power error.
  uint8_t overpower_error : 1;               //      Bits= 1 Unit:'none'

  // Whether or not the energy meter is currently logging data.
  uint8_t logging : 1;                       //      Bits= 1 Unit:'none'

#else

  uint8_t voltage_gain;                      //      Bits= 4 Unit:'none'

  uint8_t current_gain;                      //      Bits= 4 Unit:'none'

  // Whether or not the energy meter is reading an over-voltage error.
  uint8_t overvoltage_error;                 //      Bits= 1 Unit:'none'

  // Whether or not the Energy Meter is reading an over-power error.
  uint8_t overpower_error;                   //      Bits= 1 Unit:'none'

  // Whether or not the energy meter is currently logging data.
  uint8_t logging;                           //      Bits= 1 Unit:'none'

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} EM_STATUS_t;

// def @ENERGY_METER_STATUS CAN Message (1037 0x40d)
#define ENERGY_METER_STATUS_IDE (0U)
#define ENERGY_METER_STATUS_DLC (8U)
#define ENERGY_METER_STATUS_CANID (0x40dU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t em_violation : 1;                  //      Bits= 1

  uint8_t em_logging : 1;                    //      Bits= 1

  uint32_t em_energy_w_hr;                   //      Bits=32

#else

  uint8_t em_violation;                      //      Bits= 1

  uint8_t em_logging;                        //      Bits= 1

  uint32_t em_energy_w_hr;                   //      Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} ENERGY_METER_STATUS_t;

// def @STATE_OF_ENERGY CAN Message (1053 0x41d)
#define STATE_OF_ENERGY_IDE (0U)
#define STATE_OF_ENERGY_DLC (8U)
#define STATE_OF_ENERGY_CANID (0x41dU)
// signal: @lifetime_ah_throughput_ro
#define HYTECH_lifetime_ah_throughput_ro_CovFactor (0.02)
#define HYTECH_lifetime_ah_throughput_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.02)) )
#define HYTECH_lifetime_ah_throughput_ro_fromS(x) ( (((x) * (0.02)) + (0.0)) )
// signal: @SoH_ro
#define HYTECH_SoH_ro_CovFactor (0.5)
#define HYTECH_SoH_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_SoH_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @SoE_ro
#define HYTECH_SoE_ro_CovFactor (0.5)
#define HYTECH_SoE_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_SoE_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @remaining_pack_wh_ro
#define HYTECH_remaining_pack_wh_ro_CovFactor (0.1)
#define HYTECH_remaining_pack_wh_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.1)) )
#define HYTECH_remaining_pack_wh_ro_fromS(x) ( (((x) * (0.1)) + (0.0)) )
// signal: @V1_ro
#define HYTECH_V1_ro_CovFactor (0.0001)
#define HYTECH_V1_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_V1_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t lifetime_ah_throughput_ro;        //      Bits=16 Factor= 0.02            Unit:'Ah'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t lifetime_ah_throughput_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t SoH_ro;                            //      Bits= 8 Factor= 0.5             Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoH_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t SoE_ro;                            //      Bits= 8 Factor= 0.5             Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoE_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t remaining_pack_wh_ro;             //      Bits=16 Factor= 0.1             Unit:'Wh'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t remaining_pack_wh_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t V1_ro;                            //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t V1_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t lifetime_ah_throughput_ro;        //      Bits=16 Factor= 0.02            Unit:'Ah'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t lifetime_ah_throughput_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t SoH_ro;                            //      Bits= 8 Factor= 0.5             Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoH_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t SoE_ro;                            //      Bits= 8 Factor= 0.5             Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoE_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t remaining_pack_wh_ro;             //      Bits=16 Factor= 0.1             Unit:'Wh'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t remaining_pack_wh_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t V1_ro;                            //      Bits=16 Factor= 0.0001

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t V1_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} STATE_OF_ENERGY_t;

// def @STATE_OF_CHARGE CAN Message (1054 0x41e)
#define STATE_OF_CHARGE_IDE (0U)
#define STATE_OF_CHARGE_DLC (8U)
#define STATE_OF_CHARGE_CANID (0x41eU)
// signal: @SoC_ro
#define HYTECH_SoC_ro_CovFactor (0.01)
#define HYTECH_SoC_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.01)) )
#define HYTECH_SoC_ro_fromS(x) ( (((x) * (0.01)) + (0.0)) )
// signal: @min_cell_voltage_est_ro
#define HYTECH_min_cell_voltage_est_ro_CovFactor (0.0001)
#define HYTECH_min_cell_voltage_est_ro_toS(x) ( (uint16_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_min_cell_voltage_est_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )
// signal: @charge_coulombs_ro
#define HYTECH_charge_coulombs_ro_CovFactor (0.0001)
#define HYTECH_charge_coulombs_ro_toS(x) ( (uint32_t) (((x) - (0.0)) / (0.0001)) )
#define HYTECH_charge_coulombs_ro_fromS(x) ( (((x) * (0.0001)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // The charge in the accumulator, as a percentage.
  uint16_t SoC_ro;                           //      Bits=16 Factor= 0.01            Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoC_phys;
#endif // HYTECH_USE_SIGFLOAT

  // Lowest-cell-voltage estimate based on the state of charge, according to VOLTAGE_LOOKUP_TABLE. Ex: 87% SoC would display 3.798V.
  uint16_t min_cell_voltage_est_ro;          //      Bits=16 Factor= 0.0001          Unit:'volts'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_voltage_est_phys;
#endif // HYTECH_USE_SIGFLOAT

  // The charge in the accumulator, in Coulombs
  uint32_t charge_coulombs_ro;               //      Bits=32 Factor= 0.0001          Unit:'Coulombs'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t charge_coulombs_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // The charge in the accumulator, as a percentage.
  uint16_t SoC_ro;                           //      Bits=16 Factor= 0.01            Unit:'percent'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t SoC_phys;
#endif // HYTECH_USE_SIGFLOAT

  // Lowest-cell-voltage estimate based on the state of charge, according to VOLTAGE_LOOKUP_TABLE. Ex: 87% SoC would display 3.798V.
  uint16_t min_cell_voltage_est_ro;          //      Bits=16 Factor= 0.0001          Unit:'volts'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t min_cell_voltage_est_phys;
#endif // HYTECH_USE_SIGFLOAT

  // The charge in the accumulator, in Coulombs
  uint32_t charge_coulombs_ro;               //      Bits=32 Factor= 0.0001          Unit:'Coulombs'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t charge_coulombs_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} STATE_OF_CHARGE_t;

// Steering reading; system and sensor status
// def @STEERING_DATA CAN Message (1055 0x41f)
#define STEERING_DATA_IDE (0U)
#define STEERING_DATA_DLC (7U)
#define STEERING_DATA_CANID (0x41fU)
// signal: @steering_output_steering_angle_ro
#define HYTECH_steering_output_steering_angle_ro_CovFactor (0.01)
#define HYTECH_steering_output_steering_angle_ro_toS(x) ( (uint32_t) (((x) - (-360.0)) / (0.01)) )
#define HYTECH_steering_output_steering_angle_ro_fromS(x) ( (((x) * (0.01)) + (-360.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t steering_analog_oor : 1;                 //      Bits= 1

  // raw measurement as measured by bottom steering analog sensor
  uint16_t steering_analog_raw;                    //      Bits=12

  uint8_t steering_both_sensors_fail : 1;          //      Bits= 1

  uint8_t steering_digital_oor : 1;                //      Bits= 1

  // raw measurement by digital steering encoder
  uint16_t steering_digital_raw;                   //      Bits=14

  uint8_t steering_dtheta_exceeded_analog : 1;     //      Bits= 1

  uint8_t steering_dtheta_exceeded_digital : 1;    //      Bits= 1

  uint8_t steering_interface_sensor_error : 1;     //      Bits= 1

  // converted angle for best sensor
  uint32_t steering_output_steering_angle_ro;      //      Bits=17 Offset= -360.0             Factor= 0.01            Unit:'degrees'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t steering_output_steering_angle_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t steering_sensor_disagreement : 1;        //      Bits= 1

#else

  uint8_t steering_analog_oor;                     //      Bits= 1

  // raw measurement as measured by bottom steering analog sensor
  uint16_t steering_analog_raw;                    //      Bits=12

  uint8_t steering_both_sensors_fail;              //      Bits= 1

  uint8_t steering_digital_oor;                    //      Bits= 1

  // raw measurement by digital steering encoder
  uint16_t steering_digital_raw;                   //      Bits=14

  uint8_t steering_dtheta_exceeded_analog;         //      Bits= 1

  uint8_t steering_dtheta_exceeded_digital;        //      Bits= 1

  uint8_t steering_interface_sensor_error;         //      Bits= 1

  // converted angle for best sensor
  uint32_t steering_output_steering_angle_ro;      //      Bits=17 Offset= -360.0             Factor= 0.01            Unit:'degrees'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t steering_output_steering_angle_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t steering_sensor_disagreement;            //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} STEERING_DATA_t;

// def @LF_TTPMS_1 CAN Message (1060 0x424)
#define LF_TTPMS_1_IDE (0U)
#define LF_TTPMS_1_DLC (8U)
#define LF_TTPMS_1_CANID (0x424U)
// signal: @LF_TTPMS_P_ro
#define HYTECH_LF_TTPMS_P_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_P_ro_toS(x) ( (uint16_t) (((x) - (3000.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_P_ro_fromS(x) ( (((x) * (0.1)) + (3000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_SN;                      //      Bits=16

  uint16_t LF_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t LF_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#else

  uint16_t LF_TTPMS_SN;                      //      Bits=16

  uint16_t LF_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t LF_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_1_t;

// def @LF_TTPMS_2 CAN Message (1061 0x425)
#define LF_TTPMS_2_IDE (0U)
#define LF_TTPMS_2_DLC (8U)
#define LF_TTPMS_2_CANID (0x425U)
// signal: @LF_TTPMS_T1_ro
#define HYTECH_LF_TTPMS_T1_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T1_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T1_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T2_ro
#define HYTECH_LF_TTPMS_T2_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T2_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T2_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T3_ro
#define HYTECH_LF_TTPMS_T3_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T3_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T3_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T4_ro
#define HYTECH_LF_TTPMS_T4_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T4_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T4_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LF_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_2_t;

// def @LF_TTPMS_3 CAN Message (1062 0x426)
#define LF_TTPMS_3_IDE (0U)
#define LF_TTPMS_3_DLC (8U)
#define LF_TTPMS_3_CANID (0x426U)
// signal: @LF_TTPMS_T5_ro
#define HYTECH_LF_TTPMS_T5_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T5_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T5_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T6_ro
#define HYTECH_LF_TTPMS_T6_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T6_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T6_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T7_ro
#define HYTECH_LF_TTPMS_T7_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T7_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T7_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T8_ro
#define HYTECH_LF_TTPMS_T8_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T8_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T8_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LF_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_3_t;

// def @LF_TTPMS_4 CAN Message (1063 0x427)
#define LF_TTPMS_4_IDE (0U)
#define LF_TTPMS_4_DLC (8U)
#define LF_TTPMS_4_CANID (0x427U)
// signal: @LF_TTPMS_T9_ro
#define HYTECH_LF_TTPMS_T9_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T9_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T9_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T10_ro
#define HYTECH_LF_TTPMS_T10_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T10_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T10_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T11_ro
#define HYTECH_LF_TTPMS_T11_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T11_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T11_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T12_ro
#define HYTECH_LF_TTPMS_T12_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T12_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T12_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LF_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_4_t;

// def @LF_TTPMS_5 CAN Message (1064 0x428)
#define LF_TTPMS_5_IDE (0U)
#define LF_TTPMS_5_DLC (8U)
#define LF_TTPMS_5_CANID (0x428U)
// signal: @LF_TTPMS_T13_ro
#define HYTECH_LF_TTPMS_T13_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T13_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T13_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T14_ro
#define HYTECH_LF_TTPMS_T14_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T14_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T14_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T15_ro
#define HYTECH_LF_TTPMS_T15_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T15_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T15_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LF_TTPMS_T16_ro
#define HYTECH_LF_TTPMS_T16_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T16_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T16_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LF_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_5_t;

// def @LF_TTPMS_6 CAN Message (1065 0x429)
#define LF_TTPMS_6_IDE (0U)
#define LF_TTPMS_6_DLC (8U)
#define LF_TTPMS_6_CANID (0x429U)
// signal: @LF_TTPMS_T_ro
#define HYTECH_LF_TTPMS_T_ro_CovFactor (0.1)
#define HYTECH_LF_TTPMS_T_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LF_TTPMS_T_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LF_TTPMS_TC;                      //      Bits=16

  int16_t LF_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t LF_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_NODE_ID;                 //      Bits=16

#else

  uint16_t LF_TTPMS_TC;                      //      Bits=16

  int16_t LF_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t LF_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LF_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LF_TTPMS_NODE_ID;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LF_TTPMS_6_t;

// def @RF_TTPMS_1 CAN Message (1066 0x42a)
#define RF_TTPMS_1_IDE (0U)
#define RF_TTPMS_1_DLC (8U)
#define RF_TTPMS_1_CANID (0x42aU)
// signal: @RF_TTPMS_P_ro
#define HYTECH_RF_TTPMS_P_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_P_ro_toS(x) ( (uint16_t) (((x) - (3000.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_P_ro_fromS(x) ( (((x) * (0.1)) + (3000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_SN;                      //      Bits=16

  uint16_t RF_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t RF_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#else

  uint16_t RF_TTPMS_SN;                      //      Bits=16

  uint16_t RF_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t RF_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_1_t;

// def @RF_TTPMS_2 CAN Message (1067 0x42b)
#define RF_TTPMS_2_IDE (0U)
#define RF_TTPMS_2_DLC (8U)
#define RF_TTPMS_2_CANID (0x42bU)
// signal: @RF_TTPMS_T1_ro
#define HYTECH_RF_TTPMS_T1_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T1_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T1_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T2_ro
#define HYTECH_RF_TTPMS_T2_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T2_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T2_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T3_ro
#define HYTECH_RF_TTPMS_T3_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T3_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T3_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T4_ro
#define HYTECH_RF_TTPMS_T4_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T4_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T4_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RF_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_2_t;

// def @RF_TTPMS_3 CAN Message (1068 0x42c)
#define RF_TTPMS_3_IDE (0U)
#define RF_TTPMS_3_DLC (8U)
#define RF_TTPMS_3_CANID (0x42cU)
// signal: @RF_TTPMS_T5_ro
#define HYTECH_RF_TTPMS_T5_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T5_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T5_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T6_ro
#define HYTECH_RF_TTPMS_T6_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T6_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T6_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T7_ro
#define HYTECH_RF_TTPMS_T7_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T7_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T7_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T8_ro
#define HYTECH_RF_TTPMS_T8_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T8_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T8_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RF_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_3_t;

// def @RF_TTPMS_4 CAN Message (1069 0x42d)
#define RF_TTPMS_4_IDE (0U)
#define RF_TTPMS_4_DLC (8U)
#define RF_TTPMS_4_CANID (0x42dU)
// signal: @RF_TTPMS_T9_ro
#define HYTECH_RF_TTPMS_T9_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T9_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T9_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T10_ro
#define HYTECH_RF_TTPMS_T10_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T10_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T10_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T11_ro
#define HYTECH_RF_TTPMS_T11_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T11_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T11_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T12_ro
#define HYTECH_RF_TTPMS_T12_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T12_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T12_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RF_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_4_t;

// def @RF_TTPMS_5 CAN Message (1070 0x42e)
#define RF_TTPMS_5_IDE (0U)
#define RF_TTPMS_5_DLC (8U)
#define RF_TTPMS_5_CANID (0x42eU)
// signal: @RF_TTPMS_T13_ro
#define HYTECH_RF_TTPMS_T13_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T13_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T13_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T14_ro
#define HYTECH_RF_TTPMS_T14_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T14_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T14_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T15_ro
#define HYTECH_RF_TTPMS_T15_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T15_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T15_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RF_TTPMS_T16_ro
#define HYTECH_RF_TTPMS_T16_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T16_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T16_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RF_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_5_t;

// def @RF_TTPMS_6 CAN Message (1071 0x42f)
#define RF_TTPMS_6_IDE (0U)
#define RF_TTPMS_6_DLC (8U)
#define RF_TTPMS_6_CANID (0x42fU)
// signal: @RF_TTPMS_T_ro
#define HYTECH_RF_TTPMS_T_ro_CovFactor (0.1)
#define HYTECH_RF_TTPMS_T_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RF_TTPMS_T_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RF_TTPMS_TC;                      //      Bits=16

  int16_t RF_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t RF_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_NODE_ID;                 //      Bits=16

#else

  uint16_t RF_TTPMS_TC;                      //      Bits=16

  int16_t RF_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t RF_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RF_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RF_TTPMS_NODE_ID;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RF_TTPMS_6_t;

// def @LR_TTPMS_1 CAN Message (1072 0x430)
#define LR_TTPMS_1_IDE (0U)
#define LR_TTPMS_1_DLC (8U)
#define LR_TTPMS_1_CANID (0x430U)
// signal: @LR_TTPMS_P_ro
#define HYTECH_LR_TTPMS_P_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_P_ro_toS(x) ( (uint16_t) (((x) - (3000.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_P_ro_fromS(x) ( (((x) * (0.1)) + (3000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // Serial Number
  uint16_t LR_TTPMS_SN;                      //      Bits=16

  uint16_t LR_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t LR_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#else

  // Serial Number
  uint16_t LR_TTPMS_SN;                      //      Bits=16

  uint16_t LR_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t LR_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_1_t;

// def @LR_TTPMS_2 CAN Message (1073 0x431)
#define LR_TTPMS_2_IDE (0U)
#define LR_TTPMS_2_DLC (8U)
#define LR_TTPMS_2_CANID (0x431U)
// signal: @LR_TTPMS_T1_ro
#define HYTECH_LR_TTPMS_T1_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T1_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T1_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T2_ro
#define HYTECH_LR_TTPMS_T2_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T2_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T2_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T3_ro
#define HYTECH_LR_TTPMS_T3_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T3_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T3_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T4_ro
#define HYTECH_LR_TTPMS_T4_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T4_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T4_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LR_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LR_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_2_t;

// def @LR_TTPMS_3 CAN Message (1074 0x432)
#define LR_TTPMS_3_IDE (0U)
#define LR_TTPMS_3_DLC (8U)
#define LR_TTPMS_3_CANID (0x432U)
// signal: @LR_TTPMS_T5_ro
#define HYTECH_LR_TTPMS_T5_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T5_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T5_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T6_ro
#define HYTECH_LR_TTPMS_T6_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T6_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T6_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T7_ro
#define HYTECH_LR_TTPMS_T7_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T7_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T7_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T8_ro
#define HYTECH_LR_TTPMS_T8_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T8_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T8_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LR_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LR_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_3_t;

// def @LR_TTPMS_4 CAN Message (1075 0x433)
#define LR_TTPMS_4_IDE (0U)
#define LR_TTPMS_4_DLC (8U)
#define LR_TTPMS_4_CANID (0x433U)
// signal: @LR_TTPMS_T9_ro
#define HYTECH_LR_TTPMS_T9_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T9_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T9_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T10_ro
#define HYTECH_LR_TTPMS_T10_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T10_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T10_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T11_ro
#define HYTECH_LR_TTPMS_T11_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T11_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T11_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T12_ro
#define HYTECH_LR_TTPMS_T12_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T12_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T12_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LR_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LR_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_4_t;

// def @LR_TTPMS_5 CAN Message (1076 0x434)
#define LR_TTPMS_5_IDE (0U)
#define LR_TTPMS_5_DLC (8U)
#define LR_TTPMS_5_CANID (0x434U)
// signal: @LR_TTPMS_T13_ro
#define HYTECH_LR_TTPMS_T13_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T13_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T13_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T14_ro
#define HYTECH_LR_TTPMS_T14_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T14_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T14_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T15_ro
#define HYTECH_LR_TTPMS_T15_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T15_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T15_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @LR_TTPMS_T16_ro
#define HYTECH_LR_TTPMS_T16_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T16_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T16_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LR_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t LR_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_5_t;

// def @LR_TTPMS_6 CAN Message (1077 0x435)
#define LR_TTPMS_6_IDE (0U)
#define LR_TTPMS_6_DLC (8U)
#define LR_TTPMS_6_CANID (0x435U)
// signal: @LR_TTPMS_T_ro
#define HYTECH_LR_TTPMS_T_ro_CovFactor (0.1)
#define HYTECH_LR_TTPMS_T_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_LR_TTPMS_T_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t LR_TTPMS_TC;                      //      Bits=16

  int16_t LR_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t LR_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_NODE_ID;                 //      Bits=16

#else

  uint16_t LR_TTPMS_TC;                      //      Bits=16

  int16_t LR_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t LR_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t LR_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t LR_TTPMS_NODE_ID;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} LR_TTPMS_6_t;

// def @RR_TTPMS_1 CAN Message (1078 0x436)
#define RR_TTPMS_1_IDE (0U)
#define RR_TTPMS_1_DLC (8U)
#define RR_TTPMS_1_CANID (0x436U)
// signal: @RR_TTPMS_P_ro
#define HYTECH_RR_TTPMS_P_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_P_ro_toS(x) ( (uint16_t) (((x) - (3000.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_P_ro_fromS(x) ( (((x) * (0.1)) + (3000.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_SN;                      //      Bits=16

  uint16_t RR_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t RR_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#else

  uint16_t RR_TTPMS_SN;                      //      Bits=16

  uint16_t RR_TTPMS_BAT_V;                   //      Bits=16 Unit:'mV'

  uint16_t RR_TTPMS_P_ro;                    //      Bits=16 Offset= 3000.0             Factor= 0.1             Unit:'mbar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_P_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_P_GAUGE;                 //      Bits=16 Unit:'mbar'

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_1_t;

// def @RR_TTPMS_2 CAN Message (1079 0x437)
#define RR_TTPMS_2_IDE (0U)
#define RR_TTPMS_2_DLC (8U)
#define RR_TTPMS_2_CANID (0x437U)
// signal: @RR_TTPMS_T1_ro
#define HYTECH_RR_TTPMS_T1_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T1_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T1_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T2_ro
#define HYTECH_RR_TTPMS_T2_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T2_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T2_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T3_ro
#define HYTECH_RR_TTPMS_T3_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T3_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T3_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T4_ro
#define HYTECH_RR_TTPMS_T4_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T4_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T4_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RR_TTPMS_T1_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T2_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T3_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T4_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_2_t;

// def @RR_TTPMS_3 CAN Message (1080 0x438)
#define RR_TTPMS_3_IDE (0U)
#define RR_TTPMS_3_DLC (8U)
#define RR_TTPMS_3_CANID (0x438U)
// signal: @RR_TTPMS_T5_ro
#define HYTECH_RR_TTPMS_T5_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T5_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T5_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T6_ro
#define HYTECH_RR_TTPMS_T6_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T6_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T6_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T7_ro
#define HYTECH_RR_TTPMS_T7_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T7_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T7_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T8_ro
#define HYTECH_RR_TTPMS_T8_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T8_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T8_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RR_TTPMS_T5_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T5_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T6_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T6_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T7_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T7_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T8_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_3_t;

// def @RR_TTPMS_4 CAN Message (1081 0x439)
#define RR_TTPMS_4_IDE (0U)
#define RR_TTPMS_4_DLC (8U)
#define RR_TTPMS_4_CANID (0x439U)
// signal: @RR_TTPMS_T9_ro
#define HYTECH_RR_TTPMS_T9_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T9_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T9_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T10_ro
#define HYTECH_RR_TTPMS_T10_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T10_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T10_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T11_ro
#define HYTECH_RR_TTPMS_T11_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T11_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T11_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T12_ro
#define HYTECH_RR_TTPMS_T12_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T12_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T12_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RR_TTPMS_T9_ro;                   //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T9_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T10_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T10_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T11_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T11_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T12_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_4_t;

// def @RR_TTPMS_5 CAN Message (1082 0x43a)
#define RR_TTPMS_5_IDE (0U)
#define RR_TTPMS_5_DLC (8U)
#define RR_TTPMS_5_CANID (0x43aU)
// signal: @RR_TTPMS_T13_ro
#define HYTECH_RR_TTPMS_T13_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T13_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T13_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T14_ro
#define HYTECH_RR_TTPMS_T14_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T14_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T14_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T15_ro
#define HYTECH_RR_TTPMS_T15_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T15_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T15_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @RR_TTPMS_T16_ro
#define HYTECH_RR_TTPMS_T16_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T16_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T16_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t RR_TTPMS_T13_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T13_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T14_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T14_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T15_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T15_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_T16_ro;                  //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_5_t;

// def @RR_TTPMS_6 CAN Message (1083 0x43b)
#define RR_TTPMS_6_IDE (0U)
#define RR_TTPMS_6_DLC (8U)
#define RR_TTPMS_6_CANID (0x43bU)
// signal: @RR_TTPMS_T_ro
#define HYTECH_RR_TTPMS_T_ro_CovFactor (0.1)
#define HYTECH_RR_TTPMS_T_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_RR_TTPMS_T_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t RR_TTPMS_TC;                      //      Bits=16

  int16_t RR_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t RR_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_NODE_ID;                 //      Bits=16

#else

  uint16_t RR_TTPMS_TC;                      //      Bits=16

  int16_t RR_TTPMS_RSSI;                     //  [-] Bits=16 Unit:'dBm'

  uint16_t RR_TTPMS_T_ro;                    //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'°C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t RR_TTPMS_T_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t RR_TTPMS_NODE_ID;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} RR_TTPMS_6_t;

// def @FL_BRAKE_ROTOR_TEMP_CH1_CH4 CAN Message (1220 0x4c4)
#define FL_BRAKE_ROTOR_TEMP_CH1_CH4_IDE (0U)
#define FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC (8U)
#define FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID (0x4c4U)
// signal: @brake_temp_channel_1_ro
#define HYTECH_brake_temp_channel_1_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_1_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_1_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_2_ro
#define HYTECH_brake_temp_channel_2_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_2_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_2_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_3_ro
#define HYTECH_brake_temp_channel_3_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_3_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_3_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_4_ro
#define HYTECH_brake_temp_channel_4_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_4_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_4_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_1_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_2_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_3_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_4_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_1_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_2_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_3_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_4_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FL_BRAKE_ROTOR_TEMP_CH1_CH4_t;

// def @FL_BRAKE_ROTOR_TEMP_CH5_CH8 CAN Message (1221 0x4c5)
#define FL_BRAKE_ROTOR_TEMP_CH5_CH8_IDE (0U)
#define FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC (8U)
#define FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID (0x4c5U)
// signal: @brake_temp_channel_5_ro
#define HYTECH_brake_temp_channel_5_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_5_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_5_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_6_ro
#define HYTECH_brake_temp_channel_6_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_6_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_6_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_7_ro
#define HYTECH_brake_temp_channel_7_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_7_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_7_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_8_ro
#define HYTECH_brake_temp_channel_8_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_8_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_8_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_5_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_6_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_7_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_8_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_5_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_6_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_7_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_8_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FL_BRAKE_ROTOR_TEMP_CH5_CH8_t;

// def @FL_BRAKE_ROTOR_TEMP_CH9_CH12 CAN Message (1222 0x4c6)
#define FL_BRAKE_ROTOR_TEMP_CH9_CH12_IDE (0U)
#define FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC (8U)
#define FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID (0x4c6U)
// signal: @brake_temp_channel_9_ro
#define HYTECH_brake_temp_channel_9_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_9_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_9_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_10_ro
#define HYTECH_brake_temp_channel_10_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_10_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_10_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_11_ro
#define HYTECH_brake_temp_channel_11_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_11_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_11_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_12_ro
#define HYTECH_brake_temp_channel_12_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_12_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_12_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_9_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_9_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_10_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_10_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_11_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_11_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_12_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_9_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_9_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_10_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_10_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_11_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_11_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_12_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FL_BRAKE_ROTOR_TEMP_CH9_CH12_t;

// def @FL_BRAKE_ROTOR_TEMP_CH13_CH16 CAN Message (1223 0x4c7)
#define FL_BRAKE_ROTOR_TEMP_CH13_CH16_IDE (0U)
#define FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC (8U)
#define FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID (0x4c7U)
// signal: @brake_temp_channel_13_ro
#define HYTECH_brake_temp_channel_13_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_13_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_13_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_14_ro
#define HYTECH_brake_temp_channel_14_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_14_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_14_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_15_ro
#define HYTECH_brake_temp_channel_15_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_15_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_15_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )
// signal: @brake_temp_channel_16_ro
#define HYTECH_brake_temp_channel_16_ro_CovFactor (0.1)
#define HYTECH_brake_temp_channel_16_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_temp_channel_16_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_13_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_13_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_14_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_14_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_15_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_15_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_16_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_13_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_13_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_14_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_14_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_15_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_15_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_16_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FL_BRAKE_ROTOR_TEMP_CH13_CH16_t;

// def @FL_BRAKE_ROTOR_SENSOR_TEMP CAN Message (1224 0x4c8)
#define FL_BRAKE_ROTOR_SENSOR_TEMP_IDE (0U)
#define FL_BRAKE_ROTOR_SENSOR_TEMP_DLC (8U)
#define FL_BRAKE_ROTOR_SENSOR_TEMP_CANID (0x4c8U)
// signal: @brake_rotor_sensor_temp_ro
#define HYTECH_brake_rotor_sensor_temp_ro_CovFactor (0.1)
#define HYTECH_brake_rotor_sensor_temp_ro_toS(x) ( (uint16_t) (((x) - (-100.0)) / (0.1)) )
#define HYTECH_brake_rotor_sensor_temp_ro_fromS(x) ( (((x) * (0.1)) + (-100.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // temperature internal to the sensor degrees C
  uint16_t brake_rotor_sensor_temp_ro;       //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_rotor_sensor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // temperature internal to the sensor degrees C
  uint16_t brake_rotor_sensor_temp_ro;       //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_rotor_sensor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FL_BRAKE_ROTOR_SENSOR_TEMP_t;

// def @FR_BRAKE_ROTOR_TEMP_CH1_CH4 CAN Message (1225 0x4c9)
#define FR_BRAKE_ROTOR_TEMP_CH1_CH4_IDE (0U)
#define FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC (8U)
#define FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID (0x4c9U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_1_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_2_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_3_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_4_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_1_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_2_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_3_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_4_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FR_BRAKE_ROTOR_TEMP_CH1_CH4_t;

// def @FR_BRAKE_ROTOR_TEMP_CH5_CH8 CAN Message (1226 0x4ca)
#define FR_BRAKE_ROTOR_TEMP_CH5_CH8_IDE (0U)
#define FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC (8U)
#define FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID (0x4caU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_5_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_6_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_7_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_8_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_8_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_5_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_5_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_6_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_6_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_7_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_7_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_8_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_8_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FR_BRAKE_ROTOR_TEMP_CH5_CH8_t;

// def @FR_BRAKE_ROTOR_TEMP_CH9_CH12 CAN Message (1227 0x4cb)
#define FR_BRAKE_ROTOR_TEMP_CH9_CH12_IDE (0U)
#define FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC (8U)
#define FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID (0x4cbU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_9_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_9_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_10_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_10_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_11_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_11_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_12_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_12_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_9_ro;          //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_9_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_10_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_10_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_11_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_11_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_12_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_12_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FR_BRAKE_ROTOR_TEMP_CH9_CH12_t;

// def @FR_BRAKE_ROTOR_TEMP_CH13_CH16 CAN Message (1228 0x4cc)
#define FR_BRAKE_ROTOR_TEMP_CH13_CH16_IDE (0U)
#define FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC (8U)
#define FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID (0x4ccU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_13_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_13_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_14_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_14_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_15_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_15_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_16_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_16_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_13_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_13_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_14_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_14_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_15_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_15_phys;
#endif // HYTECH_USE_SIGFLOAT

  // brake rotor temp sensor channel reading in degrees C
  uint16_t brake_temp_channel_16_ro;         //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_temp_channel_16_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FR_BRAKE_ROTOR_TEMP_CH13_CH16_t;

// def @FR_BRAKE_ROTOR_SENSOR_TEMP CAN Message (1229 0x4cd)
#define FR_BRAKE_ROTOR_SENSOR_TEMP_IDE (0U)
#define FR_BRAKE_ROTOR_SENSOR_TEMP_DLC (8U)
#define FR_BRAKE_ROTOR_SENSOR_TEMP_CANID (0x4cdU)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // temperature internal to the sensor degrees C
  uint16_t brake_rotor_sensor_temp_ro;       //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_rotor_sensor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  // temperature internal to the sensor degrees C
  uint16_t brake_rotor_sensor_temp_ro;       //      Bits=16 Offset= -100.0             Factor= 0.1             Unit:'deg C'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t brake_rotor_sensor_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FR_BRAKE_ROTOR_SENSOR_TEMP_t;

// def @ACU_OK CAN Message (1280 0x500)
#define ACU_OK_IDE (0U)
#define ACU_OK_DLC (1U)
#define ACU_OK_CANID (0x500U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t bms_ok : 1;                        //      Bits= 1

  uint8_t imd_ok : 1;                        //      Bits= 1

  uint8_t latch_ok : 1;                      //      Bits= 1

#else

  uint8_t bms_ok;                            //      Bits= 1

  uint8_t imd_ok;                            //      Bits= 1

  uint8_t latch_ok;                          //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} ACU_OK_t;

// def @DRIVEBRAIN_LATENCY_TIMES CAN Message (1281 0x501)
#define DRIVEBRAIN_LATENCY_TIMES_IDE (0U)
#define DRIVEBRAIN_LATENCY_TIMES_DLC (8U)
#define DRIVEBRAIN_LATENCY_TIMES_CANID (0x501U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t telem_latency_millis;             //      Bits=32

  uint32_t aux_latency_millis;               //      Bits=32

#else

  uint32_t telem_latency_millis;             //      Bits=32

  uint32_t aux_latency_millis;               //      Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_LATENCY_TIMES_t;

// def @DRIVEBRAIN_LATENCY_STATUSES CAN Message (1282 0x502)
#define DRIVEBRAIN_LATENCY_STATUSES_IDE (0U)
#define DRIVEBRAIN_LATENCY_STATUSES_DLC (8U)
#define DRIVEBRAIN_LATENCY_STATUSES_CANID (0x502U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t db_telem_timing_fault : 1;         //      Bits= 1

  uint8_t db_aux_timing_fault : 1;           //      Bits= 1

#else

  uint8_t db_telem_timing_fault;             //      Bits= 1

  uint8_t db_aux_timing_fault;               //      Bits= 1

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DRIVEBRAIN_LATENCY_STATUSES_t;

// def @FLOWMETER_DATA CAN Message (1283 0x503)
#define FLOWMETER_DATA_IDE (0U)
#define FLOWMETER_DATA_DLC (8U)
#define FLOWMETER_DATA_CANID (0x503U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t flow_rate;                        //      Bits=32

#else

  uint32_t flow_rate;                        //      Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FLOWMETER_DATA_t;

// def @ENERGY_METER_TEMP CAN Message (1549 0x60d)
#define ENERGY_METER_TEMP_IDE (0U)
#define ENERGY_METER_TEMP_DLC (8U)
#define ENERGY_METER_TEMP_CANID (0x60dU)
// signal: @em_min_temp_ro
#define HYTECH_em_min_temp_ro_CovFactor (0.5)
#define HYTECH_em_min_temp_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_min_temp_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_max_temp_ro
#define HYTECH_em_max_temp_ro_CovFactor (0.5)
#define HYTECH_em_max_temp_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_max_temp_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_temp_0_ro
#define HYTECH_em_temp_0_ro_CovFactor (0.5)
#define HYTECH_em_temp_0_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_temp_0_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_temp_1_ro
#define HYTECH_em_temp_1_ro_CovFactor (0.5)
#define HYTECH_em_temp_1_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_temp_1_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_temp_2_ro
#define HYTECH_em_temp_2_ro_CovFactor (0.5)
#define HYTECH_em_temp_2_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_temp_2_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_temp_3_ro
#define HYTECH_em_temp_3_ro_CovFactor (0.5)
#define HYTECH_em_temp_3_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_temp_3_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )
// signal: @em_temp_4_ro
#define HYTECH_em_temp_4_ro_CovFactor (0.5)
#define HYTECH_em_temp_4_ro_toS(x) ( (uint8_t) (((x) - (0.0)) / (0.5)) )
#define HYTECH_em_temp_4_ro_fromS(x) ( (((x) * (0.5)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t em_temp_sig_index : 3;             //      Bits= 3

  uint8_t em_num_sensors : 5;                //      Bits= 5

  uint8_t em_min_temp_ro;                    //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_min_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_max_temp_ro;                    //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_max_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_0_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_1_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_2_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_3_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_4_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint8_t em_temp_sig_index;                 //      Bits= 3

  uint8_t em_num_sensors;                    //      Bits= 5

  uint8_t em_min_temp_ro;                    //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_min_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_max_temp_ro;                    //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_max_temp_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_0_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_1_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_2_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_3_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_3_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint8_t em_temp_4_ro;                      //      Bits= 8 Factor= 0.5

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t em_temp_4_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} ENERGY_METER_TEMP_t;

// def @AERO_PRESSURE_SENSOR_21 CAN Message (1568 0x620)
#define AERO_PRESSURE_SENSOR_21_IDE (0U)
#define AERO_PRESSURE_SENSOR_21_DLC (8U)
#define AERO_PRESSURE_SENSOR_21_CANID (0x620U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_21_t;

// def @AERO_PRESSURE_SENSOR_31 CAN Message (1584 0x630)
#define AERO_PRESSURE_SENSOR_31_IDE (0U)
#define AERO_PRESSURE_SENSOR_31_DLC (8U)
#define AERO_PRESSURE_SENSOR_31_CANID (0x630U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_31_t;

// def @AERO_PRESSURE_SENSOR_41 CAN Message (1600 0x640)
#define AERO_PRESSURE_SENSOR_41_IDE (0U)
#define AERO_PRESSURE_SENSOR_41_DLC (8U)
#define AERO_PRESSURE_SENSOR_41_CANID (0x640U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  uint16_t aero_channel_0_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_0_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_1_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_1_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_2_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_2_phys;
#endif // HYTECH_USE_SIGFLOAT

  uint16_t aero_channel_3_ro;                //      Bits=16 Offset= -53000.0           Factor= 0.142857142     Unit:'uBar'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t aero_channel_3_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} AERO_PRESSURE_SENSOR_41_t;

// def @BRAKE_PRESSURE CAN Message (1639 0x667)
#define BRAKE_PRESSURE_IDE (0U)
#define BRAKE_PRESSURE_DLC (8U)
#define BRAKE_PRESSURE_CANID (0x667U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint16_t brake_pressure_1;                 //      Bits=16

  uint16_t brake_pressure_2;                 //      Bits=16

#else

  uint16_t brake_pressure_1;                 //      Bits=16

  uint16_t brake_pressure_2;                 //      Bits=16

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} BRAKE_PRESSURE_t;

// def @VEHM_BETA CAN Message (2031 0x7ef)
#define VEHM_BETA_IDE (0U)
#define VEHM_BETA_DLC (8U)
#define VEHM_BETA_CANID (0x7efU)
// signal: @vehm_beta_deg_ro
#define HYTECH_vehm_beta_deg_ro_CovFactor (0.001)
#define HYTECH_vehm_beta_deg_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.001)) )
#define HYTECH_vehm_beta_deg_ro_fromS(x) ( (((x) * (0.001)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t vehm_beta_deg_ro;                  //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_beta_deg_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t vehm_beta_deg_ro;                  //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_beta_deg_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} VEHM_BETA_t;

// def @DASHBOARD_BUZZER_CONTROL CAN Message (2033 0x7f1)
#define DASHBOARD_BUZZER_CONTROL_IDE (0U)
#define DASHBOARD_BUZZER_CONTROL_DLC (2U)
#define DASHBOARD_BUZZER_CONTROL_CANID (0x7f1U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t dash_buzzer_flag : 1;                //      Bits= 1

  uint8_t in_pedal_calibration_state : 1;      //      Bits= 1

  // Input from VCR to tell VCF if steering can calibrate or not
  uint8_t in_steering_calibration_state : 1;   //      Bits= 1

  uint8_t torque_limit_enum_value;             //      Bits= 8

#else

  uint8_t dash_buzzer_flag;                    //      Bits= 1

  uint8_t in_pedal_calibration_state;          //      Bits= 1

  // Input from VCR to tell VCF if steering can calibrate or not
  uint8_t in_steering_calibration_state;       //      Bits= 1

  uint8_t torque_limit_enum_value;             //      Bits= 8

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} DASHBOARD_BUZZER_CONTROL_t;

// def @FD_TEST CAN Message (2034 0x7f2)
#define FD_TEST_IDE (0U)
#define FD_TEST_DLC (64U)
#define FD_TEST_CANID (0x7f2U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint32_t fd_test_counter;                  //      Bits=32

  uint32_t fd_test_byte8;                    //      Bits=32

  uint32_t fd_test_byte32;                   //      Bits=32

  uint32_t fd_test_byte60;                   //      Bits=32

#else

  uint32_t fd_test_counter;                  //      Bits=32

  uint32_t fd_test_byte8;                    //      Bits=32

  uint32_t fd_test_byte32;                   //      Bits=32

  uint32_t fd_test_byte60;                   //      Bits=32

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} FD_TEST_t;

// def @VEHM_ALPHA CAN Message (2047 0x7ff)
#define VEHM_ALPHA_IDE (0U)
#define VEHM_ALPHA_DLC (8U)
#define VEHM_ALPHA_CANID (0x7ffU)
// signal: @vehm_alpha_deg_fl_ro
#define HYTECH_vehm_alpha_deg_fl_ro_CovFactor (0.001)
#define HYTECH_vehm_alpha_deg_fl_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.001)) )
#define HYTECH_vehm_alpha_deg_fl_ro_fromS(x) ( (((x) * (0.001)) + (0.0)) )
// signal: @vehm_alpha_deg_fr_ro
#define HYTECH_vehm_alpha_deg_fr_ro_CovFactor (0.001)
#define HYTECH_vehm_alpha_deg_fr_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.001)) )
#define HYTECH_vehm_alpha_deg_fr_ro_fromS(x) ( (((x) * (0.001)) + (0.0)) )
// signal: @vehm_alpha_deg_rl_ro
#define HYTECH_vehm_alpha_deg_rl_ro_CovFactor (0.001)
#define HYTECH_vehm_alpha_deg_rl_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.001)) )
#define HYTECH_vehm_alpha_deg_rl_ro_fromS(x) ( (((x) * (0.001)) + (0.0)) )
// signal: @vehm_alpha_deg_rr_ro
#define HYTECH_vehm_alpha_deg_rr_ro_CovFactor (0.001)
#define HYTECH_vehm_alpha_deg_rr_ro_toS(x) ( (int16_t) (((x) - (0.0)) / (0.001)) )
#define HYTECH_vehm_alpha_deg_rr_ro_fromS(x) ( (((x) * (0.001)) + (0.0)) )

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  int16_t vehm_alpha_deg_fl_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_fr_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_rl_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_rr_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#else

  int16_t vehm_alpha_deg_fl_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_fl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_fr_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_fr_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_rl_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_rl_phys;
#endif // HYTECH_USE_SIGFLOAT

  int16_t vehm_alpha_deg_rr_ro;              //  [-] Bits=16 Factor= 0.001           Unit:'deg'

#ifdef HYTECH_USE_SIGFLOAT
  sigfloat_t vehm_alpha_deg_rr_phys;
#endif // HYTECH_USE_SIGFLOAT

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} VEHM_ALPHA_t;

// def @CHARGER_CONTROL CAN Message (403105268 0x1806e5f4)
#define CHARGER_CONTROL_IDE (1U)
#define CHARGER_CONTROL_DLC (5U)
#define CHARGER_CONTROL_CANID (0x1806e5f4U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_voltage_high;         //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_voltage_low;          //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_current_high;         //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_current_low;          //      Bits= 8

  uint8_t control;                           //      Bits= 8

#else

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_voltage_high;         //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_voltage_low;          //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_current_high;         //      Bits= 8

  // Unused for any PCAN stuff only for Elcon Charger
  uint8_t max_charging_current_low;          //      Bits= 8

  uint8_t control;                           //      Bits= 8

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} CHARGER_CONTROL_t;

// def @CHARGER_DATA CAN Message (419385573 0x18ff50e5)
#define CHARGER_DATA_IDE (1U)
#define CHARGER_DATA_DLC (7U)
#define CHARGER_DATA_CANID (0x18ff50e5U)

typedef struct
{
#ifdef HYTECH_USE_BITS_SIGNAL

  uint8_t output_dc_voltage_high;            //      Bits= 8

  uint8_t output_dc_voltage_low;             //      Bits= 8

  uint8_t output_current_high;               //      Bits= 8

  uint8_t output_current_low;                //      Bits= 8

  uint8_t flags;                             //      Bits= 8

  uint8_t input_ac_voltage_high;             //      Bits= 8

  uint8_t input_ac_voltage_low;              //      Bits= 8

#else

  uint8_t output_dc_voltage_high;            //      Bits= 8

  uint8_t output_dc_voltage_low;             //      Bits= 8

  uint8_t output_current_high;               //      Bits= 8

  uint8_t output_current_low;                //      Bits= 8

  uint8_t flags;                             //      Bits= 8

  uint8_t input_ac_voltage_high;             //      Bits= 8

  uint8_t input_ac_voltage_low;              //      Bits= 8

#endif // HYTECH_USE_BITS_SIGNAL

#ifdef HYTECH_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // HYTECH_USE_DIAG_MONITORS

} CHARGER_DATA_t;

// Function signatures

uint32_t Unpack_INV3_STATUS_hytech(INV3_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_STATUS_hytech(INV3_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_STATUS_hytech(INV3_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_POWER_hytech(INV3_POWER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_POWER_hytech(INV3_POWER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_POWER_hytech(INV3_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_STATUS_hytech(INV4_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_STATUS_hytech(INV4_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_STATUS_hytech(INV4_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_POWER_hytech(INV4_POWER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_POWER_hytech(INV4_POWER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_POWER_hytech(INV4_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_STATUS_hytech(INV1_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_STATUS_hytech(INV1_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_STATUS_hytech(INV1_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_POWER_hytech(INV1_POWER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_POWER_hytech(INV1_POWER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_POWER_hytech(INV1_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_STATUS_hytech(INV2_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_STATUS_hytech(INV2_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_STATUS_hytech(INV2_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_POWER_hytech(INV2_POWER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_POWER_hytech(INV2_POWER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_POWER_hytech(INV2_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_STATUS_hytech(BMS_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BMS_STATUS_hytech(BMS_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BMS_STATUS_hytech(BMS_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CCU_STATUS_hytech(CCU_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_CCU_STATUS_hytech(CCU_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_CCU_STATUS_hytech(CCU_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CAR_STATES_hytech(CAR_STATES_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_CAR_STATES_hytech(CAR_STATES_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_CAR_STATES_hytech(CAR_STATES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DASH_INPUT_hytech(DASH_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DASH_INPUT_hytech(DASH_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DASH_INPUT_hytech(DASH_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_EM_STATUS_hytech(EM_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_EM_STATUS_hytech(EM_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_EM_STATUS_hytech(EM_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STEERING_DATA_hytech(STEERING_DATA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_STEERING_DATA_hytech(STEERING_DATA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_STEERING_DATA_hytech(STEERING_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ACU_OK_hytech(ACU_OK_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_ACU_OK_hytech(ACU_OK_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_ACU_OK_hytech(ACU_OK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_VEHM_BETA_hytech(VEHM_BETA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_VEHM_BETA_hytech(VEHM_BETA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_VEHM_BETA_hytech(VEHM_BETA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FD_TEST_hytech(FD_TEST_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_FD_TEST_hytech(FD_TEST_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_FD_TEST_hytech(FD_TEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, const uint8_t* _d, uint8_t dlc_);
#ifdef HYTECH_USE_CANSTRUCT
uint32_t Pack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, __CoderDbcCanFrame_t__* cframe);
#else
uint32_t Pack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);
#endif // HYTECH_USE_CANSTRUCT

#ifdef __cplusplus
}
#endif
