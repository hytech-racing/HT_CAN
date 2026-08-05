// Generator version : v3.1
// DBC filename      : hytech_fd.dbc
#include "hytech.h"


// DBC file version
#if (VER_HYTECH_MAJ != (6U)) || (VER_HYTECH_MIN != (0U))
#error The HYTECH dbc source files have different versions
#endif

#ifdef HYTECH_USE_DIAG_MONITORS
// Function prototypes to be called each time CAN frame is unpacked
// FMon function may detect RC, CRC or DLC violation
#include "hytech-fmon.h"

#endif // HYTECH_USE_DIAG_MONITORS

// This macro guard for the case when you need to enable
// using diag monitors but there is no necessity in proper
// SysTick provider. For providing one you need define macro
// before this line - in dbccodeconf.h

#ifndef GetSystemTick
#define GetSystemTick() (0u)
#endif

// This macro guard is for the case when you want to build
// app with enabled optoin auto CSM, but don't yet have
// proper getframehash implementation

#ifndef GetFrameHash
#define GetFrameHash(a,b,c,d,e) (0u)
#endif

// This function performs extension of sign for the signals
// whose bit width value is not aligned to one of power of 2 or less than 8.
// The types 'bitext_t' and 'ubitext_t' define the biggest bit width which
// can be correctly handled. You need to select type which can contain
// n+1 bits where n is the largest signed signal width. For example if
// the most wide signed signal has a width of 31 bits you need to set
// bitext_t as int32_t and ubitext_t as uint32_t
// Defined these typedefs in @dbccodeconf.h or locally in 'dbcdrvname'-config.h
static bitext_t __ext_sig__(ubitext_t val, uint8_t bits)
{
  ubitext_t const m = (ubitext_t) (1u << (bits - 1u));
  return ((val ^ m) - m);
}

uint32_t Unpack_INV3_STATUS_hytech(INV3_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->system_ready = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->error = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->warning = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->quit_dc_on = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );
  _m->dc_on = (uint8_t) ( ((_d[1] >> 4U) & (0x01U)) );
  _m->quit_inverter_on = (uint8_t) ( ((_d[1] >> 5U) & (0x01U)) );
  _m->inverter_on = (uint8_t) ( ((_d[1] >> 6U) & (0x01U)) );
  _m->derating_on = (uint8_t) ( ((_d[1] >> 7U) & (0x01U)) );
  _m->dc_bus_voltage = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->diagnostic_number = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_STATUS_hytech(&_m->mon1, INV3_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_STATUS_hytech(INV3_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  cframe->Data[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_STATUS_CANID;
  cframe->DLC = (uint8_t) INV3_STATUS_DLC;
  cframe->IDE = (uint8_t) INV3_STATUS_IDE;
  return INV3_STATUS_CANID;
}

#else

uint32_t Pack_INV3_STATUS_hytech(INV3_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  _d[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_STATUS_DLC;
  *_ide = (uint8_t) INV3_STATUS_IDE;
  return INV3_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->motor_temp_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_phys = (sigfloat_t)(HYTECH_motor_temp_ro_fromS(_m->motor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->inverter_temp_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_temp_phys = (sigfloat_t)(HYTECH_inverter_temp_ro_fromS(_m->inverter_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->igbt_temp_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->igbt_temp_phys = (sigfloat_t)(HYTECH_igbt_temp_ro_fromS(_m->igbt_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_TEMPS_hytech(&_m->mon1, INV3_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_TEMPS_CANID;
  cframe->DLC = (uint8_t) INV3_TEMPS_DLC;
  cframe->IDE = (uint8_t) INV3_TEMPS_IDE;
  return INV3_TEMPS_CANID;
}

#else

uint32_t Pack_INV3_TEMPS_hytech(INV3_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_TEMPS_DLC;
  *_ide = (uint8_t) INV3_TEMPS_IDE;
  return INV3_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->actual_power_w = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->actual_torque_nm_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_phys = (sigfloat_t)(HYTECH_actual_torque_nm_ro_fromS(_m->actual_torque_nm_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->actual_speed_rpm = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_DYNAMICS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_DYNAMICS_hytech(&_m->mon1, INV3_DYNAMICS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_DYNAMICS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_DYNAMICS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_DYNAMICS_CANID;
  cframe->DLC = (uint8_t) INV3_DYNAMICS_DLC;
  cframe->IDE = (uint8_t) INV3_DYNAMICS_IDE;
  return INV3_DYNAMICS_CANID;
}

#else

uint32_t Pack_INV3_DYNAMICS_hytech(INV3_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_DYNAMICS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_DYNAMICS_DLC;
  *_ide = (uint8_t) INV3_DYNAMICS_IDE;
  return INV3_DYNAMICS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_POWER_hytech(INV3_POWER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->active_power_w = (int32_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 32);
  _m->reactive_power_var = (int32_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 32);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_POWER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_POWER_hytech(&_m->mon1, INV3_POWER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_POWER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_POWER_hytech(INV3_POWER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_POWER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_POWER_CANID;
  cframe->DLC = (uint8_t) INV3_POWER_DLC;
  cframe->IDE = (uint8_t) INV3_POWER_IDE;
  return INV3_POWER_CANID;
}

#else

uint32_t Pack_INV3_POWER_hytech(INV3_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_POWER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  *_len = (uint8_t) INV3_POWER_DLC;
  *_ide = (uint8_t) INV3_POWER_IDE;
  return INV3_POWER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_FEEDBACK_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_FEEDBACK_hytech(&_m->mon1, INV3_FEEDBACK_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_FEEDBACK_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_FEEDBACK_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_FEEDBACK_CANID;
  cframe->DLC = (uint8_t) INV3_FEEDBACK_DLC;
  cframe->IDE = (uint8_t) INV3_FEEDBACK_IDE;
  return INV3_FEEDBACK_CANID;
}

#else

uint32_t Pack_INV3_FEEDBACK_hytech(INV3_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_FEEDBACK_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_FEEDBACK_DLC;
  *_ide = (uint8_t) INV3_FEEDBACK_IDE;
  return INV3_FEEDBACK_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_STATUS_hytech(INV4_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->system_ready = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->error = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->warning = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->quit_dc_on = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );
  _m->dc_on = (uint8_t) ( ((_d[1] >> 4U) & (0x01U)) );
  _m->quit_inverter_on = (uint8_t) ( ((_d[1] >> 5U) & (0x01U)) );
  _m->inverter_on = (uint8_t) ( ((_d[1] >> 6U) & (0x01U)) );
  _m->derating_on = (uint8_t) ( ((_d[1] >> 7U) & (0x01U)) );
  _m->dc_bus_voltage = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->diagnostic_number = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_STATUS_hytech(&_m->mon1, INV4_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_STATUS_hytech(INV4_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  cframe->Data[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_STATUS_CANID;
  cframe->DLC = (uint8_t) INV4_STATUS_DLC;
  cframe->IDE = (uint8_t) INV4_STATUS_IDE;
  return INV4_STATUS_CANID;
}

#else

uint32_t Pack_INV4_STATUS_hytech(INV4_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  _d[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_STATUS_DLC;
  *_ide = (uint8_t) INV4_STATUS_IDE;
  return INV4_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->motor_temp_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_phys = (sigfloat_t)(HYTECH_motor_temp_ro_fromS(_m->motor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->inverter_temp_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_temp_phys = (sigfloat_t)(HYTECH_inverter_temp_ro_fromS(_m->inverter_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->igbt_temp_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->igbt_temp_phys = (sigfloat_t)(HYTECH_igbt_temp_ro_fromS(_m->igbt_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_TEMPS_hytech(&_m->mon1, INV4_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_TEMPS_CANID;
  cframe->DLC = (uint8_t) INV4_TEMPS_DLC;
  cframe->IDE = (uint8_t) INV4_TEMPS_IDE;
  return INV4_TEMPS_CANID;
}

#else

uint32_t Pack_INV4_TEMPS_hytech(INV4_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_TEMPS_DLC;
  *_ide = (uint8_t) INV4_TEMPS_IDE;
  return INV4_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->actual_power_w = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->actual_torque_nm_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_phys = (sigfloat_t)(HYTECH_actual_torque_nm_ro_fromS(_m->actual_torque_nm_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->actual_speed_rpm = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_DYNAMICS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_DYNAMICS_hytech(&_m->mon1, INV4_DYNAMICS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_DYNAMICS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_DYNAMICS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_DYNAMICS_CANID;
  cframe->DLC = (uint8_t) INV4_DYNAMICS_DLC;
  cframe->IDE = (uint8_t) INV4_DYNAMICS_IDE;
  return INV4_DYNAMICS_CANID;
}

#else

uint32_t Pack_INV4_DYNAMICS_hytech(INV4_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_DYNAMICS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_DYNAMICS_DLC;
  *_ide = (uint8_t) INV4_DYNAMICS_IDE;
  return INV4_DYNAMICS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_POWER_hytech(INV4_POWER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->active_power_w = (int32_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 32);
  _m->reactive_power_var = (int32_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 32);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_POWER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_POWER_hytech(&_m->mon1, INV4_POWER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_POWER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_POWER_hytech(INV4_POWER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_POWER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_POWER_CANID;
  cframe->DLC = (uint8_t) INV4_POWER_DLC;
  cframe->IDE = (uint8_t) INV4_POWER_IDE;
  return INV4_POWER_CANID;
}

#else

uint32_t Pack_INV4_POWER_hytech(INV4_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_POWER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  *_len = (uint8_t) INV4_POWER_DLC;
  *_ide = (uint8_t) INV4_POWER_IDE;
  return INV4_POWER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_FEEDBACK_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_FEEDBACK_hytech(&_m->mon1, INV4_FEEDBACK_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_FEEDBACK_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_FEEDBACK_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_FEEDBACK_CANID;
  cframe->DLC = (uint8_t) INV4_FEEDBACK_DLC;
  cframe->IDE = (uint8_t) INV4_FEEDBACK_IDE;
  return INV4_FEEDBACK_CANID;
}

#else

uint32_t Pack_INV4_FEEDBACK_hytech(INV4_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_FEEDBACK_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_FEEDBACK_DLC;
  *_ide = (uint8_t) INV4_FEEDBACK_IDE;
  return INV4_FEEDBACK_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_STATUS_hytech(INV1_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->system_ready = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->error = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->warning = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->quit_dc_on = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );
  _m->dc_on = (uint8_t) ( ((_d[1] >> 4U) & (0x01U)) );
  _m->quit_inverter_on = (uint8_t) ( ((_d[1] >> 5U) & (0x01U)) );
  _m->inverter_on = (uint8_t) ( ((_d[1] >> 6U) & (0x01U)) );
  _m->derating_on = (uint8_t) ( ((_d[1] >> 7U) & (0x01U)) );
  _m->dc_bus_voltage = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->diagnostic_number = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_STATUS_hytech(&_m->mon1, INV1_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_STATUS_hytech(INV1_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  cframe->Data[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_STATUS_CANID;
  cframe->DLC = (uint8_t) INV1_STATUS_DLC;
  cframe->IDE = (uint8_t) INV1_STATUS_IDE;
  return INV1_STATUS_CANID;
}

#else

uint32_t Pack_INV1_STATUS_hytech(INV1_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  _d[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_STATUS_DLC;
  *_ide = (uint8_t) INV1_STATUS_IDE;
  return INV1_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->motor_temp_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_phys = (sigfloat_t)(HYTECH_motor_temp_ro_fromS(_m->motor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->inverter_temp_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_temp_phys = (sigfloat_t)(HYTECH_inverter_temp_ro_fromS(_m->inverter_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->igbt_temp_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->igbt_temp_phys = (sigfloat_t)(HYTECH_igbt_temp_ro_fromS(_m->igbt_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_TEMPS_hytech(&_m->mon1, INV1_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_TEMPS_CANID;
  cframe->DLC = (uint8_t) INV1_TEMPS_DLC;
  cframe->IDE = (uint8_t) INV1_TEMPS_IDE;
  return INV1_TEMPS_CANID;
}

#else

uint32_t Pack_INV1_TEMPS_hytech(INV1_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_TEMPS_DLC;
  *_ide = (uint8_t) INV1_TEMPS_IDE;
  return INV1_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->actual_power_w = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->actual_torque_nm_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_phys = (sigfloat_t)(HYTECH_actual_torque_nm_ro_fromS(_m->actual_torque_nm_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->actual_speed_rpm = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_DYNAMICS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_DYNAMICS_hytech(&_m->mon1, INV1_DYNAMICS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_DYNAMICS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_DYNAMICS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_DYNAMICS_CANID;
  cframe->DLC = (uint8_t) INV1_DYNAMICS_DLC;
  cframe->IDE = (uint8_t) INV1_DYNAMICS_IDE;
  return INV1_DYNAMICS_CANID;
}

#else

uint32_t Pack_INV1_DYNAMICS_hytech(INV1_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_DYNAMICS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_DYNAMICS_DLC;
  *_ide = (uint8_t) INV1_DYNAMICS_IDE;
  return INV1_DYNAMICS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_POWER_hytech(INV1_POWER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->active_power_w = (int32_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 32);
  _m->reactive_power_var = (int32_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 32);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_POWER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_POWER_hytech(&_m->mon1, INV1_POWER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_POWER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_POWER_hytech(INV1_POWER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_POWER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_POWER_CANID;
  cframe->DLC = (uint8_t) INV1_POWER_DLC;
  cframe->IDE = (uint8_t) INV1_POWER_IDE;
  return INV1_POWER_CANID;
}

#else

uint32_t Pack_INV1_POWER_hytech(INV1_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_POWER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  *_len = (uint8_t) INV1_POWER_DLC;
  *_ide = (uint8_t) INV1_POWER_IDE;
  return INV1_POWER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_FEEDBACK_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_FEEDBACK_hytech(&_m->mon1, INV1_FEEDBACK_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_FEEDBACK_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_FEEDBACK_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_FEEDBACK_CANID;
  cframe->DLC = (uint8_t) INV1_FEEDBACK_DLC;
  cframe->IDE = (uint8_t) INV1_FEEDBACK_IDE;
  return INV1_FEEDBACK_CANID;
}

#else

uint32_t Pack_INV1_FEEDBACK_hytech(INV1_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_FEEDBACK_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_FEEDBACK_DLC;
  *_ide = (uint8_t) INV1_FEEDBACK_IDE;
  return INV1_FEEDBACK_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_STATUS_hytech(INV2_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->system_ready = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->error = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->warning = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->quit_dc_on = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );
  _m->dc_on = (uint8_t) ( ((_d[1] >> 4U) & (0x01U)) );
  _m->quit_inverter_on = (uint8_t) ( ((_d[1] >> 5U) & (0x01U)) );
  _m->inverter_on = (uint8_t) ( ((_d[1] >> 6U) & (0x01U)) );
  _m->derating_on = (uint8_t) ( ((_d[1] >> 7U) & (0x01U)) );
  _m->dc_bus_voltage = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->diagnostic_number = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_STATUS_hytech(&_m->mon1, INV2_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_STATUS_hytech(INV2_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  cframe->Data[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_STATUS_CANID;
  cframe->DLC = (uint8_t) INV2_STATUS_DLC;
  cframe->IDE = (uint8_t) INV2_STATUS_IDE;
  return INV2_STATUS_CANID;
}

#else

uint32_t Pack_INV2_STATUS_hytech(INV2_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->system_ready & (0x01U)) | ((_m->error & (0x01U)) << 1U) | ((_m->warning & (0x01U)) << 2U) | ((_m->quit_dc_on & (0x01U)) << 3U) | ((_m->dc_on & (0x01U)) << 4U) | ((_m->quit_inverter_on & (0x01U)) << 5U) | ((_m->inverter_on & (0x01U)) << 6U) | ((_m->derating_on & (0x01U)) << 7U) );
  _d[2] |= (uint8_t) ( (_m->dc_bus_voltage & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->dc_bus_voltage >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->diagnostic_number & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->diagnostic_number >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_STATUS_DLC;
  *_ide = (uint8_t) INV2_STATUS_IDE;
  return INV2_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->motor_temp_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_phys = (sigfloat_t)(HYTECH_motor_temp_ro_fromS(_m->motor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->inverter_temp_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_temp_phys = (sigfloat_t)(HYTECH_inverter_temp_ro_fromS(_m->inverter_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->igbt_temp_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->igbt_temp_phys = (sigfloat_t)(HYTECH_igbt_temp_ro_fromS(_m->igbt_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_TEMPS_hytech(&_m->mon1, INV2_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_TEMPS_CANID;
  cframe->DLC = (uint8_t) INV2_TEMPS_DLC;
  cframe->IDE = (uint8_t) INV2_TEMPS_IDE;
  return INV2_TEMPS_CANID;
}

#else

uint32_t Pack_INV2_TEMPS_hytech(INV2_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_temp_ro = (int16_t) HYTECH_motor_temp_ro_toS(_m->motor_temp_phys);
  _m->inverter_temp_ro = (int16_t) HYTECH_inverter_temp_ro_toS(_m->inverter_temp_phys);
  _m->igbt_temp_ro = (int16_t) HYTECH_igbt_temp_ro_toS(_m->igbt_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->motor_temp_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->motor_temp_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->inverter_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->inverter_temp_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->igbt_temp_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->igbt_temp_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_TEMPS_DLC;
  *_ide = (uint8_t) INV2_TEMPS_IDE;
  return INV2_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->actual_power_w = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->actual_torque_nm_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_phys = (sigfloat_t)(HYTECH_actual_torque_nm_ro_fromS(_m->actual_torque_nm_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->actual_speed_rpm = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_DYNAMICS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_DYNAMICS_hytech(&_m->mon1, INV2_DYNAMICS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_DYNAMICS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_DYNAMICS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_DYNAMICS_CANID;
  cframe->DLC = (uint8_t) INV2_DYNAMICS_DLC;
  cframe->IDE = (uint8_t) INV2_DYNAMICS_IDE;
  return INV2_DYNAMICS_CANID;
}

#else

uint32_t Pack_INV2_DYNAMICS_hytech(INV2_DYNAMICS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_DYNAMICS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->actual_torque_nm_ro = (int16_t) HYTECH_actual_torque_nm_ro_toS(_m->actual_torque_nm_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->actual_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->actual_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->actual_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->actual_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->actual_torque_nm_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->actual_torque_nm_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->actual_speed_rpm & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->actual_speed_rpm >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_DYNAMICS_DLC;
  *_ide = (uint8_t) INV2_DYNAMICS_IDE;
  return INV2_DYNAMICS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_POWER_hytech(INV2_POWER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->active_power_w = (int32_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 32);
  _m->reactive_power_var = (int32_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 32);

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_POWER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_POWER_hytech(&_m->mon1, INV2_POWER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_POWER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_POWER_hytech(INV2_POWER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_POWER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_POWER_CANID;
  cframe->DLC = (uint8_t) INV2_POWER_DLC;
  cframe->IDE = (uint8_t) INV2_POWER_IDE;
  return INV2_POWER_CANID;
}

#else

uint32_t Pack_INV2_POWER_hytech(INV2_POWER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_POWER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->active_power_w & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->active_power_w >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->active_power_w >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->active_power_w >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->reactive_power_var & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->reactive_power_var >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->reactive_power_var >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->reactive_power_var >> 24U) & (0xFFU)) );

  *_len = (uint8_t) INV2_POWER_DLC;
  *_ide = (uint8_t) INV2_POWER_IDE;
  return INV2_POWER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_FEEDBACK_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_FEEDBACK_hytech(&_m->mon1, INV2_FEEDBACK_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_FEEDBACK_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_FEEDBACK_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_FEEDBACK_CANID;
  cframe->DLC = (uint8_t) INV2_FEEDBACK_DLC;
  cframe->IDE = (uint8_t) INV2_FEEDBACK_IDE;
  return INV2_FEEDBACK_CANID;
}

#else

uint32_t Pack_INV2_FEEDBACK_hytech(INV2_FEEDBACK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_FEEDBACK_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_FEEDBACK_DLC;
  *_ide = (uint8_t) INV2_FEEDBACK_IDE;
  return INV2_FEEDBACK_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_enable = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->hv_enable = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->driver_enable = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->remove_error = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_CONTROL_WORD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_CONTROL_WORD_hytech(&_m->mon1, INV3_CONTROL_WORD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_CONTROL_WORD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_WORD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  cframe->MsgId = (uint32_t) INV3_CONTROL_WORD_CANID;
  cframe->DLC = (uint8_t) INV3_CONTROL_WORD_DLC;
  cframe->IDE = (uint8_t) INV3_CONTROL_WORD_IDE;
  return INV3_CONTROL_WORD_CANID;
}

#else

uint32_t Pack_INV3_CONTROL_WORD_hytech(INV3_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_WORD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  *_len = (uint8_t) INV3_CONTROL_WORD_DLC;
  *_ide = (uint8_t) INV3_CONTROL_WORD_IDE;
  return INV3_CONTROL_WORD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_enable = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->hv_enable = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->driver_enable = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->remove_error = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_CONTROL_WORD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_CONTROL_WORD_hytech(&_m->mon1, INV4_CONTROL_WORD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_CONTROL_WORD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_WORD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  cframe->MsgId = (uint32_t) INV4_CONTROL_WORD_CANID;
  cframe->DLC = (uint8_t) INV4_CONTROL_WORD_DLC;
  cframe->IDE = (uint8_t) INV4_CONTROL_WORD_IDE;
  return INV4_CONTROL_WORD_CANID;
}

#else

uint32_t Pack_INV4_CONTROL_WORD_hytech(INV4_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_WORD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  *_len = (uint8_t) INV4_CONTROL_WORD_DLC;
  *_ide = (uint8_t) INV4_CONTROL_WORD_IDE;
  return INV4_CONTROL_WORD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_enable = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->hv_enable = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->driver_enable = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->remove_error = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_CONTROL_WORD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_CONTROL_WORD_hytech(&_m->mon1, INV1_CONTROL_WORD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_CONTROL_WORD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_WORD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  cframe->MsgId = (uint32_t) INV1_CONTROL_WORD_CANID;
  cframe->DLC = (uint8_t) INV1_CONTROL_WORD_DLC;
  cframe->IDE = (uint8_t) INV1_CONTROL_WORD_IDE;
  return INV1_CONTROL_WORD_CANID;
}

#else

uint32_t Pack_INV1_CONTROL_WORD_hytech(INV1_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_WORD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  *_len = (uint8_t) INV1_CONTROL_WORD_DLC;
  *_ide = (uint8_t) INV1_CONTROL_WORD_IDE;
  return INV1_CONTROL_WORD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_enable = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->hv_enable = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->driver_enable = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );
  _m->remove_error = (uint8_t) ( ((_d[1] >> 3U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_CONTROL_WORD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_CONTROL_WORD_hytech(&_m->mon1, INV2_CONTROL_WORD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_CONTROL_WORD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_WORD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  cframe->MsgId = (uint32_t) INV2_CONTROL_WORD_CANID;
  cframe->DLC = (uint8_t) INV2_CONTROL_WORD_DLC;
  cframe->IDE = (uint8_t) INV2_CONTROL_WORD_IDE;
  return INV2_CONTROL_WORD_CANID;
}

#else

uint32_t Pack_INV2_CONTROL_WORD_hytech(INV2_CONTROL_WORD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_WORD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[1] |= (uint8_t) ( (_m->inverter_enable & (0x01U)) | ((_m->hv_enable & (0x01U)) << 1U) | ((_m->driver_enable & (0x01U)) << 2U) | ((_m->remove_error & (0x01U)) << 3U) );

  *_len = (uint8_t) INV2_CONTROL_WORD_DLC;
  *_ide = (uint8_t) INV2_CONTROL_WORD_IDE;
  return INV2_CONTROL_WORD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_setpoint_rpm = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
  _m->positive_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_phys = (sigfloat_t)(HYTECH_positive_torque_limit_ro_fromS(_m->positive_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->negative_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->negative_torque_limit_phys = (sigfloat_t)(HYTECH_negative_torque_limit_ro_fromS(_m->negative_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_CONTROL_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_CONTROL_INPUT_hytech(&_m->mon1, INV3_CONTROL_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_CONTROL_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_CONTROL_INPUT_CANID;
  cframe->DLC = (uint8_t) INV3_CONTROL_INPUT_DLC;
  cframe->IDE = (uint8_t) INV3_CONTROL_INPUT_IDE;
  return INV3_CONTROL_INPUT_CANID;
}

#else

uint32_t Pack_INV3_CONTROL_INPUT_hytech(INV3_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_CONTROL_INPUT_DLC;
  *_ide = (uint8_t) INV3_CONTROL_INPUT_IDE;
  return INV3_CONTROL_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_setpoint_rpm = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
  _m->positive_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_phys = (sigfloat_t)(HYTECH_positive_torque_limit_ro_fromS(_m->positive_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->negative_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->negative_torque_limit_phys = (sigfloat_t)(HYTECH_negative_torque_limit_ro_fromS(_m->negative_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_CONTROL_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_CONTROL_INPUT_hytech(&_m->mon1, INV4_CONTROL_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_CONTROL_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_CONTROL_INPUT_CANID;
  cframe->DLC = (uint8_t) INV4_CONTROL_INPUT_DLC;
  cframe->IDE = (uint8_t) INV4_CONTROL_INPUT_IDE;
  return INV4_CONTROL_INPUT_CANID;
}

#else

uint32_t Pack_INV4_CONTROL_INPUT_hytech(INV4_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_CONTROL_INPUT_DLC;
  *_ide = (uint8_t) INV4_CONTROL_INPUT_IDE;
  return INV4_CONTROL_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_setpoint_rpm = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
  _m->positive_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_phys = (sigfloat_t)(HYTECH_positive_torque_limit_ro_fromS(_m->positive_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->negative_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->negative_torque_limit_phys = (sigfloat_t)(HYTECH_negative_torque_limit_ro_fromS(_m->negative_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_CONTROL_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_CONTROL_INPUT_hytech(&_m->mon1, INV1_CONTROL_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_CONTROL_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_CONTROL_INPUT_CANID;
  cframe->DLC = (uint8_t) INV1_CONTROL_INPUT_DLC;
  cframe->IDE = (uint8_t) INV1_CONTROL_INPUT_IDE;
  return INV1_CONTROL_INPUT_CANID;
}

#else

uint32_t Pack_INV1_CONTROL_INPUT_hytech(INV1_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_CONTROL_INPUT_DLC;
  *_ide = (uint8_t) INV1_CONTROL_INPUT_IDE;
  return INV1_CONTROL_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->accel_implausible = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->brake_implausible = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );
  _m->brake_pedal_active = (uint8_t) ( ((_d[0] >> 2U) & (0x01U)) );
  _m->accel_pedal_active = (uint8_t) ( ((_d[0] >> 3U) & (0x01U)) );
  _m->mechanical_brake_active = (uint8_t) ( ((_d[0] >> 4U) & (0x01U)) );
  _m->brake_accel_implausibility = (uint8_t) ( ((_d[0] >> 5U) & (0x01U)) );
  _m->implaus_exceeded_max_duration = (uint8_t) ( ((_d[0] >> 6U) & (0x01U)) );
  _m->accel_pedal_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->accel_pedal_phys = (sigfloat_t)(HYTECH_accel_pedal_ro_fromS(_m->accel_pedal_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_pedal_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_pedal_phys = (sigfloat_t)(HYTECH_brake_pedal_ro_fromS(_m->brake_pedal_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < PEDALS_SYSTEM_DATA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_PEDALS_SYSTEM_DATA_hytech(&_m->mon1, PEDALS_SYSTEM_DATA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return PEDALS_SYSTEM_DATA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(PEDALS_SYSTEM_DATA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->accel_pedal_ro = (uint16_t) HYTECH_accel_pedal_ro_toS(_m->accel_pedal_phys);
  _m->brake_pedal_ro = (uint16_t) HYTECH_brake_pedal_ro_toS(_m->brake_pedal_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->accel_implausible & (0x01U)) | ((_m->brake_implausible & (0x01U)) << 1U) | ((_m->brake_pedal_active & (0x01U)) << 2U) | ((_m->accel_pedal_active & (0x01U)) << 3U) | ((_m->mechanical_brake_active & (0x01U)) << 4U) | ((_m->brake_accel_implausibility & (0x01U)) << 5U) | ((_m->implaus_exceeded_max_duration & (0x01U)) << 6U) );
  cframe->Data[1] |= (uint8_t) ( (_m->accel_pedal_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->accel_pedal_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_pedal_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_pedal_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) PEDALS_SYSTEM_DATA_CANID;
  cframe->DLC = (uint8_t) PEDALS_SYSTEM_DATA_DLC;
  cframe->IDE = (uint8_t) PEDALS_SYSTEM_DATA_IDE;
  return PEDALS_SYSTEM_DATA_CANID;
}

#else

uint32_t Pack_PEDALS_SYSTEM_DATA_hytech(PEDALS_SYSTEM_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(PEDALS_SYSTEM_DATA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->accel_pedal_ro = (uint16_t) HYTECH_accel_pedal_ro_toS(_m->accel_pedal_phys);
  _m->brake_pedal_ro = (uint16_t) HYTECH_brake_pedal_ro_toS(_m->brake_pedal_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->accel_implausible & (0x01U)) | ((_m->brake_implausible & (0x01U)) << 1U) | ((_m->brake_pedal_active & (0x01U)) << 2U) | ((_m->accel_pedal_active & (0x01U)) << 3U) | ((_m->mechanical_brake_active & (0x01U)) << 4U) | ((_m->brake_accel_implausibility & (0x01U)) << 5U) | ((_m->implaus_exceeded_max_duration & (0x01U)) << 6U) );
  _d[1] |= (uint8_t) ( (_m->accel_pedal_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->accel_pedal_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_pedal_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_pedal_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) PEDALS_SYSTEM_DATA_DLC;
  *_ide = (uint8_t) PEDALS_SYSTEM_DATA_IDE;
  return PEDALS_SYSTEM_DATA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->ic_id = (uint8_t) ( (_d[0] & (0x0FU)) );
  _m->temp_0_ro = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->temp_0_phys = (sigfloat_t)(HYTECH_temp_0_ro_fromS(_m->temp_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->temp_1_ro = (int16_t) __ext_sig__(( ((_d[4] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->temp_1_phys = (sigfloat_t)(HYTECH_temp_1_ro_fromS(_m->temp_1_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_BOARD_DETAILED_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_BOARD_DETAILED_TEMPS_hytech(&_m->mon1, BMS_BOARD_DETAILED_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_BOARD_DETAILED_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_BOARD_DETAILED_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->temp_0_ro = (int16_t) HYTECH_temp_0_ro_toS(_m->temp_0_phys);
  _m->temp_1_ro = (int16_t) HYTECH_temp_1_ro_toS(_m->temp_1_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->ic_id & (0x0FU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->temp_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->temp_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->temp_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->temp_1_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_BOARD_DETAILED_TEMPS_CANID;
  cframe->DLC = (uint8_t) BMS_BOARD_DETAILED_TEMPS_DLC;
  cframe->IDE = (uint8_t) BMS_BOARD_DETAILED_TEMPS_IDE;
  return BMS_BOARD_DETAILED_TEMPS_CANID;
}

#else

uint32_t Pack_BMS_BOARD_DETAILED_TEMPS_hytech(BMS_BOARD_DETAILED_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_BOARD_DETAILED_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->temp_0_ro = (int16_t) HYTECH_temp_0_ro_toS(_m->temp_0_phys);
  _m->temp_1_ro = (int16_t) HYTECH_temp_1_ro_toS(_m->temp_1_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->ic_id & (0x0FU)) );
  _d[1] |= (uint8_t) ( (_m->temp_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->temp_0_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->temp_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->temp_1_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BMS_BOARD_DETAILED_TEMPS_DLC;
  *_ide = (uint8_t) BMS_BOARD_DETAILED_TEMPS_IDE;
  return BMS_BOARD_DETAILED_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->average_cell_voltage_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->average_cell_voltage_phys = (sigfloat_t)(HYTECH_average_cell_voltage_ro_fromS(_m->average_cell_voltage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->min_cell_voltage_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->min_cell_voltage_phys = (sigfloat_t)(HYTECH_min_cell_voltage_ro_fromS(_m->min_cell_voltage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->max_cell_voltage_ro = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->max_cell_voltage_phys = (sigfloat_t)(HYTECH_max_cell_voltage_ro_fromS(_m->max_cell_voltage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->total_pack_voltage_ro = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->total_pack_voltage_phys = (sigfloat_t)(HYTECH_total_pack_voltage_ro_fromS(_m->total_pack_voltage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_VOLTAGES_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_VOLTAGES_hytech(&_m->mon1, BMS_VOLTAGES_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_VOLTAGES_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_VOLTAGES_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->average_cell_voltage_ro = (uint16_t) HYTECH_average_cell_voltage_ro_toS(_m->average_cell_voltage_phys);
  _m->min_cell_voltage_ro = (uint16_t) HYTECH_min_cell_voltage_ro_toS(_m->min_cell_voltage_phys);
  _m->max_cell_voltage_ro = (uint16_t) HYTECH_max_cell_voltage_ro_toS(_m->max_cell_voltage_phys);
  _m->total_pack_voltage_ro = (uint16_t) HYTECH_total_pack_voltage_ro_toS(_m->total_pack_voltage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->average_cell_voltage_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->average_cell_voltage_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->min_cell_voltage_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->min_cell_voltage_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->max_cell_voltage_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->max_cell_voltage_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->total_pack_voltage_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->total_pack_voltage_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_VOLTAGES_CANID;
  cframe->DLC = (uint8_t) BMS_VOLTAGES_DLC;
  cframe->IDE = (uint8_t) BMS_VOLTAGES_IDE;
  return BMS_VOLTAGES_CANID;
}

#else

uint32_t Pack_BMS_VOLTAGES_hytech(BMS_VOLTAGES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_VOLTAGES_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->average_cell_voltage_ro = (uint16_t) HYTECH_average_cell_voltage_ro_toS(_m->average_cell_voltage_phys);
  _m->min_cell_voltage_ro = (uint16_t) HYTECH_min_cell_voltage_ro_toS(_m->min_cell_voltage_phys);
  _m->max_cell_voltage_ro = (uint16_t) HYTECH_max_cell_voltage_ro_toS(_m->max_cell_voltage_phys);
  _m->total_pack_voltage_ro = (uint16_t) HYTECH_total_pack_voltage_ro_toS(_m->total_pack_voltage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->average_cell_voltage_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->average_cell_voltage_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->min_cell_voltage_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->min_cell_voltage_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->max_cell_voltage_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->max_cell_voltage_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->total_pack_voltage_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->total_pack_voltage_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BMS_VOLTAGES_DLC;
  *_ide = (uint8_t) BMS_VOLTAGES_IDE;
  return BMS_VOLTAGES_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->group_id = (uint8_t) ( (_d[0] & (0x0FU)) );
  _m->ic_id = (uint8_t) ( ((_d[0] >> 4U) & (0x0FU)) );
  _m->voltage_0_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->voltage_0_phys = (sigfloat_t)(HYTECH_voltage_0_ro_fromS(_m->voltage_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->voltage_1_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->voltage_1_phys = (sigfloat_t)(HYTECH_voltage_1_ro_fromS(_m->voltage_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->voltage_2_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->voltage_2_phys = (sigfloat_t)(HYTECH_voltage_2_ro_fromS(_m->voltage_2_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_DETAILED_VOLTAGES_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_DETAILED_VOLTAGES_hytech(&_m->mon1, BMS_DETAILED_VOLTAGES_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_DETAILED_VOLTAGES_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_DETAILED_VOLTAGES_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->voltage_0_ro = (uint16_t) HYTECH_voltage_0_ro_toS(_m->voltage_0_phys);
  _m->voltage_1_ro = (uint16_t) HYTECH_voltage_1_ro_toS(_m->voltage_1_phys);
  _m->voltage_2_ro = (uint16_t) HYTECH_voltage_2_ro_toS(_m->voltage_2_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->group_id & (0x0FU)) | ((_m->ic_id & (0x0FU)) << 4U) );
  cframe->Data[1] |= (uint8_t) ( (_m->voltage_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->voltage_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->voltage_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->voltage_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->voltage_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->voltage_2_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_DETAILED_VOLTAGES_CANID;
  cframe->DLC = (uint8_t) BMS_DETAILED_VOLTAGES_DLC;
  cframe->IDE = (uint8_t) BMS_DETAILED_VOLTAGES_IDE;
  return BMS_DETAILED_VOLTAGES_CANID;
}

#else

uint32_t Pack_BMS_DETAILED_VOLTAGES_hytech(BMS_DETAILED_VOLTAGES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_DETAILED_VOLTAGES_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->voltage_0_ro = (uint16_t) HYTECH_voltage_0_ro_toS(_m->voltage_0_phys);
  _m->voltage_1_ro = (uint16_t) HYTECH_voltage_1_ro_toS(_m->voltage_1_phys);
  _m->voltage_2_ro = (uint16_t) HYTECH_voltage_2_ro_toS(_m->voltage_2_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->group_id & (0x0FU)) | ((_m->ic_id & (0x0FU)) << 4U) );
  _d[1] |= (uint8_t) ( (_m->voltage_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->voltage_0_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->voltage_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->voltage_1_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->voltage_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->voltage_2_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BMS_DETAILED_VOLTAGES_DLC;
  *_ide = (uint8_t) BMS_DETAILED_VOLTAGES_IDE;
  return BMS_DETAILED_VOLTAGES_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->max_board_temp_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->max_board_temp_phys = (sigfloat_t)(HYTECH_max_board_temp_ro_fromS(_m->max_board_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->min_cell_temp_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->min_cell_temp_phys = (sigfloat_t)(HYTECH_min_cell_temp_ro_fromS(_m->min_cell_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->max_cell_temp_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->max_cell_temp_phys = (sigfloat_t)(HYTECH_max_cell_temp_ro_fromS(_m->max_cell_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_TEMPS_hytech(&_m->mon1, BMS_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->max_board_temp_ro = (int16_t) HYTECH_max_board_temp_ro_toS(_m->max_board_temp_phys);
  _m->min_cell_temp_ro = (int16_t) HYTECH_min_cell_temp_ro_toS(_m->min_cell_temp_phys);
  _m->max_cell_temp_ro = (int16_t) HYTECH_max_cell_temp_ro_toS(_m->max_cell_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->max_board_temp_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->max_board_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->min_cell_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->min_cell_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->max_cell_temp_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->max_cell_temp_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_TEMPS_CANID;
  cframe->DLC = (uint8_t) BMS_TEMPS_DLC;
  cframe->IDE = (uint8_t) BMS_TEMPS_IDE;
  return BMS_TEMPS_CANID;
}

#else

uint32_t Pack_BMS_TEMPS_hytech(BMS_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->max_board_temp_ro = (int16_t) HYTECH_max_board_temp_ro_toS(_m->max_board_temp_phys);
  _m->min_cell_temp_ro = (int16_t) HYTECH_min_cell_temp_ro_toS(_m->min_cell_temp_phys);
  _m->max_cell_temp_ro = (int16_t) HYTECH_max_cell_temp_ro_toS(_m->max_cell_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->max_board_temp_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->max_board_temp_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->min_cell_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->min_cell_temp_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->max_cell_temp_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->max_cell_temp_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BMS_TEMPS_DLC;
  *_ide = (uint8_t) BMS_TEMPS_IDE;
  return BMS_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->group_id = (uint8_t) ( (_d[0] & (0x0FU)) );
  _m->ic_id = (uint8_t) ( ((_d[0] >> 4U) & (0x0FU)) );
  _m->thermistor_id_0_ro = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_id_0_phys = (sigfloat_t)(HYTECH_thermistor_id_0_ro_fromS(_m->thermistor_id_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_id_1_ro = (int16_t) __ext_sig__(( ((_d[4] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_id_1_phys = (sigfloat_t)(HYTECH_thermistor_id_1_ro_fromS(_m->thermistor_id_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_id_2_ro = (int16_t) __ext_sig__(( ((_d[6] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_id_2_phys = (sigfloat_t)(HYTECH_thermistor_id_2_ro_fromS(_m->thermistor_id_2_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_DETAILED_TEMPS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_DETAILED_TEMPS_hytech(&_m->mon1, BMS_DETAILED_TEMPS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_DETAILED_TEMPS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_DETAILED_TEMPS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_id_0_ro = (int16_t) HYTECH_thermistor_id_0_ro_toS(_m->thermistor_id_0_phys);
  _m->thermistor_id_1_ro = (int16_t) HYTECH_thermistor_id_1_ro_toS(_m->thermistor_id_1_phys);
  _m->thermistor_id_2_ro = (int16_t) HYTECH_thermistor_id_2_ro_toS(_m->thermistor_id_2_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->group_id & (0x0FU)) | ((_m->ic_id & (0x0FU)) << 4U) );
  cframe->Data[1] |= (uint8_t) ( (_m->thermistor_id_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->thermistor_id_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->thermistor_id_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->thermistor_id_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->thermistor_id_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->thermistor_id_2_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_DETAILED_TEMPS_CANID;
  cframe->DLC = (uint8_t) BMS_DETAILED_TEMPS_DLC;
  cframe->IDE = (uint8_t) BMS_DETAILED_TEMPS_IDE;
  return BMS_DETAILED_TEMPS_CANID;
}

#else

uint32_t Pack_BMS_DETAILED_TEMPS_hytech(BMS_DETAILED_TEMPS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_DETAILED_TEMPS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_id_0_ro = (int16_t) HYTECH_thermistor_id_0_ro_toS(_m->thermistor_id_0_phys);
  _m->thermistor_id_1_ro = (int16_t) HYTECH_thermistor_id_1_ro_toS(_m->thermistor_id_1_phys);
  _m->thermistor_id_2_ro = (int16_t) HYTECH_thermistor_id_2_ro_toS(_m->thermistor_id_2_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->group_id & (0x0FU)) | ((_m->ic_id & (0x0FU)) << 4U) );
  _d[1] |= (uint8_t) ( (_m->thermistor_id_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->thermistor_id_0_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->thermistor_id_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->thermistor_id_1_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->thermistor_id_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->thermistor_id_2_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BMS_DETAILED_TEMPS_DLC;
  *_ide = (uint8_t) BMS_DETAILED_TEMPS_IDE;
  return BMS_DETAILED_TEMPS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BMS_STATUS_hytech(BMS_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->acu_state = (uint8_t) ( (_d[0] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BMS_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BMS_STATUS_hytech(&_m->mon1, BMS_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BMS_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BMS_STATUS_hytech(BMS_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->acu_state & (0xFFU)) );

  cframe->MsgId = (uint32_t) BMS_STATUS_CANID;
  cframe->DLC = (uint8_t) BMS_STATUS_DLC;
  cframe->IDE = (uint8_t) BMS_STATUS_IDE;
  return BMS_STATUS_CANID;
}

#else

uint32_t Pack_BMS_STATUS_hytech(BMS_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BMS_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->acu_state & (0xFFU)) );

  *_len = (uint8_t) BMS_STATUS_DLC;
  *_ide = (uint8_t) BMS_STATUS_IDE;
  return BMS_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CCU_STATUS_hytech(CCU_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->charger_enabled = (uint8_t) ( (_d[0] & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < CCU_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_CCU_STATUS_hytech(&_m->mon1, CCU_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return CCU_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_CCU_STATUS_hytech(CCU_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CCU_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->charger_enabled & (0x01U)) );

  cframe->MsgId = (uint32_t) CCU_STATUS_CANID;
  cframe->DLC = (uint8_t) CCU_STATUS_DLC;
  cframe->IDE = (uint8_t) CCU_STATUS_IDE;
  return CCU_STATUS_CANID;
}

#else

uint32_t Pack_CCU_STATUS_hytech(CCU_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CCU_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->charger_enabled & (0x01U)) );

  *_len = (uint8_t) CCU_STATUS_DLC;
  *_ide = (uint8_t) CCU_STATUS_IDE;
  return CCU_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->rl_load_cell = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->rr_load_cell = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->rl_shock_pot_ro = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->rl_shock_pot_phys = (sigfloat_t)(HYTECH_rl_shock_pot_ro_fromS(_m->rl_shock_pot_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->rr_shock_pot_ro = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->rr_shock_pot_phys = (sigfloat_t)(HYTECH_rr_shock_pot_ro_fromS(_m->rr_shock_pot_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < REAR_SUSPENSION_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_REAR_SUSPENSION_hytech(&_m->mon1, REAR_SUSPENSION_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return REAR_SUSPENSION_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(REAR_SUSPENSION_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->rl_shock_pot_ro = (uint16_t) HYTECH_rl_shock_pot_ro_toS(_m->rl_shock_pot_phys);
  _m->rr_shock_pot_ro = (uint16_t) HYTECH_rr_shock_pot_ro_toS(_m->rr_shock_pot_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->rl_load_cell & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->rl_load_cell >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->rr_load_cell & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->rr_load_cell >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->rl_shock_pot_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->rl_shock_pot_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->rr_shock_pot_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->rr_shock_pot_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) REAR_SUSPENSION_CANID;
  cframe->DLC = (uint8_t) REAR_SUSPENSION_DLC;
  cframe->IDE = (uint8_t) REAR_SUSPENSION_IDE;
  return REAR_SUSPENSION_CANID;
}

#else

uint32_t Pack_REAR_SUSPENSION_hytech(REAR_SUSPENSION_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(REAR_SUSPENSION_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->rl_shock_pot_ro = (uint16_t) HYTECH_rl_shock_pot_ro_toS(_m->rl_shock_pot_phys);
  _m->rr_shock_pot_ro = (uint16_t) HYTECH_rr_shock_pot_ro_toS(_m->rr_shock_pot_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->rl_load_cell & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->rl_load_cell >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->rr_load_cell & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->rr_load_cell >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->rl_shock_pot_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->rl_shock_pot_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->rr_shock_pot_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->rr_shock_pot_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) REAR_SUSPENSION_DLC;
  *_ide = (uint8_t) REAR_SUSPENSION_IDE;
  return REAR_SUSPENSION_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->fl_load_cell = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->fl_shock_pot_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->fl_shock_pot_phys = (sigfloat_t)(HYTECH_fl_shock_pot_ro_fromS(_m->fl_shock_pot_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->fr_load_cell = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
  _m->fr_shock_pot_ro = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->fr_shock_pot_phys = (sigfloat_t)(HYTECH_fr_shock_pot_ro_fromS(_m->fr_shock_pot_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FRONT_SUSPENSION_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FRONT_SUSPENSION_hytech(&_m->mon1, FRONT_SUSPENSION_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FRONT_SUSPENSION_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FRONT_SUSPENSION_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->fl_shock_pot_ro = (uint16_t) HYTECH_fl_shock_pot_ro_toS(_m->fl_shock_pot_phys);
  _m->fr_shock_pot_ro = (uint16_t) HYTECH_fr_shock_pot_ro_toS(_m->fr_shock_pot_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->fl_load_cell & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->fl_load_cell >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->fl_shock_pot_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->fl_shock_pot_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->fr_load_cell & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->fr_load_cell >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->fr_shock_pot_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->fr_shock_pot_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) FRONT_SUSPENSION_CANID;
  cframe->DLC = (uint8_t) FRONT_SUSPENSION_DLC;
  cframe->IDE = (uint8_t) FRONT_SUSPENSION_IDE;
  return FRONT_SUSPENSION_CANID;
}

#else

uint32_t Pack_FRONT_SUSPENSION_hytech(FRONT_SUSPENSION_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FRONT_SUSPENSION_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->fl_shock_pot_ro = (uint16_t) HYTECH_fl_shock_pot_ro_toS(_m->fl_shock_pot_phys);
  _m->fr_shock_pot_ro = (uint16_t) HYTECH_fr_shock_pot_ro_toS(_m->fr_shock_pot_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->fl_load_cell & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->fl_load_cell >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->fl_shock_pot_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->fl_shock_pot_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->fr_load_cell & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->fr_load_cell >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->fr_shock_pot_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->fr_shock_pot_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) FRONT_SUSPENSION_DLC;
  *_ide = (uint8_t) FRONT_SUSPENSION_IDE;
  return FRONT_SUSPENSION_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->thermistor_0_deg_C_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_0_deg_C_phys = (sigfloat_t)(HYTECH_thermistor_0_deg_C_ro_fromS(_m->thermistor_0_deg_C_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_1_deg_C_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_1_deg_C_phys = (sigfloat_t)(HYTECH_thermistor_1_deg_C_ro_fromS(_m->thermistor_1_deg_C_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_2_deg_C_ro = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_2_deg_C_phys = (sigfloat_t)(HYTECH_thermistor_2_deg_C_ro_fromS(_m->thermistor_2_deg_C_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_3_deg_C_ro = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_3_deg_C_phys = (sigfloat_t)(HYTECH_thermistor_3_deg_C_ro_fromS(_m->thermistor_3_deg_C_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < REAR_THERMISTORS_DATA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_REAR_THERMISTORS_DATA_hytech(&_m->mon1, REAR_THERMISTORS_DATA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return REAR_THERMISTORS_DATA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(REAR_THERMISTORS_DATA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_0_deg_C_ro = (uint16_t) HYTECH_thermistor_0_deg_C_ro_toS(_m->thermistor_0_deg_C_phys);
  _m->thermistor_1_deg_C_ro = (uint16_t) HYTECH_thermistor_1_deg_C_ro_toS(_m->thermistor_1_deg_C_phys);
  _m->thermistor_2_deg_C_ro = (uint16_t) HYTECH_thermistor_2_deg_C_ro_toS(_m->thermistor_2_deg_C_phys);
  _m->thermistor_3_deg_C_ro = (uint16_t) HYTECH_thermistor_3_deg_C_ro_toS(_m->thermistor_3_deg_C_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->thermistor_0_deg_C_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->thermistor_0_deg_C_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->thermistor_1_deg_C_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->thermistor_1_deg_C_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->thermistor_2_deg_C_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->thermistor_2_deg_C_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->thermistor_3_deg_C_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->thermistor_3_deg_C_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) REAR_THERMISTORS_DATA_CANID;
  cframe->DLC = (uint8_t) REAR_THERMISTORS_DATA_DLC;
  cframe->IDE = (uint8_t) REAR_THERMISTORS_DATA_IDE;
  return REAR_THERMISTORS_DATA_CANID;
}

#else

uint32_t Pack_REAR_THERMISTORS_DATA_hytech(REAR_THERMISTORS_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(REAR_THERMISTORS_DATA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_0_deg_C_ro = (uint16_t) HYTECH_thermistor_0_deg_C_ro_toS(_m->thermistor_0_deg_C_phys);
  _m->thermistor_1_deg_C_ro = (uint16_t) HYTECH_thermistor_1_deg_C_ro_toS(_m->thermistor_1_deg_C_phys);
  _m->thermistor_2_deg_C_ro = (uint16_t) HYTECH_thermistor_2_deg_C_ro_toS(_m->thermistor_2_deg_C_phys);
  _m->thermistor_3_deg_C_ro = (uint16_t) HYTECH_thermistor_3_deg_C_ro_toS(_m->thermistor_3_deg_C_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->thermistor_0_deg_C_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->thermistor_0_deg_C_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->thermistor_1_deg_C_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->thermistor_1_deg_C_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->thermistor_2_deg_C_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->thermistor_2_deg_C_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->thermistor_3_deg_C_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->thermistor_3_deg_C_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) REAR_THERMISTORS_DATA_DLC;
  *_ide = (uint8_t) REAR_THERMISTORS_DATA_IDE;
  return REAR_THERMISTORS_DATA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->drivebrain_torque_fl_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_phys = (sigfloat_t)(HYTECH_drivebrain_torque_fl_ro_fromS(_m->drivebrain_torque_fl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_fr_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fr_phys = (sigfloat_t)(HYTECH_drivebrain_torque_fr_ro_fromS(_m->drivebrain_torque_fr_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_rl_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_rl_phys = (sigfloat_t)(HYTECH_drivebrain_torque_rl_ro_fromS(_m->drivebrain_torque_rl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_rr_ro = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_rr_phys = (sigfloat_t)(HYTECH_drivebrain_torque_rr_ro_fromS(_m->drivebrain_torque_rr_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_TORQUE_LIM_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(&_m->mon1, DRIVEBRAIN_TORQUE_LIM_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_TORQUE_LIM_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_TORQUE_LIM_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_ro = (int16_t) HYTECH_drivebrain_torque_fl_ro_toS(_m->drivebrain_torque_fl_phys);
  _m->drivebrain_torque_fr_ro = (int16_t) HYTECH_drivebrain_torque_fr_ro_toS(_m->drivebrain_torque_fr_phys);
  _m->drivebrain_torque_rl_ro = (int16_t) HYTECH_drivebrain_torque_rl_ro_toS(_m->drivebrain_torque_rl_phys);
  _m->drivebrain_torque_rr_ro = (int16_t) HYTECH_drivebrain_torque_rr_ro_toS(_m->drivebrain_torque_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->drivebrain_torque_fl_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->drivebrain_torque_fl_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->drivebrain_torque_fr_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->drivebrain_torque_fr_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->drivebrain_torque_rl_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->drivebrain_torque_rl_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->drivebrain_torque_rr_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->drivebrain_torque_rr_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_TORQUE_LIM_INPUT_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_TORQUE_LIM_INPUT_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_TORQUE_LIM_INPUT_IDE;
  return DRIVEBRAIN_TORQUE_LIM_INPUT_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(DRIVEBRAIN_TORQUE_LIM_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_TORQUE_LIM_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_ro = (int16_t) HYTECH_drivebrain_torque_fl_ro_toS(_m->drivebrain_torque_fl_phys);
  _m->drivebrain_torque_fr_ro = (int16_t) HYTECH_drivebrain_torque_fr_ro_toS(_m->drivebrain_torque_fr_phys);
  _m->drivebrain_torque_rl_ro = (int16_t) HYTECH_drivebrain_torque_rl_ro_toS(_m->drivebrain_torque_rl_phys);
  _m->drivebrain_torque_rr_ro = (int16_t) HYTECH_drivebrain_torque_rr_ro_toS(_m->drivebrain_torque_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->drivebrain_torque_fl_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->drivebrain_torque_fl_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->drivebrain_torque_fr_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->drivebrain_torque_fr_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->drivebrain_torque_rl_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->drivebrain_torque_rl_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->drivebrain_torque_rr_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->drivebrain_torque_rr_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) DRIVEBRAIN_TORQUE_LIM_INPUT_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_TORQUE_LIM_INPUT_IDE;
  return DRIVEBRAIN_TORQUE_LIM_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->drivebrain_set_rpm_fl = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->drivebrain_set_rpm_fr = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->drivebrain_set_rpm_rl = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
  _m->drivebrain_set_rpm_rr = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_SPEED_SET_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_SPEED_SET_INPUT_hytech(&_m->mon1, DRIVEBRAIN_SPEED_SET_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_SPEED_SET_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_SPEED_SET_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->drivebrain_set_rpm_fl & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->drivebrain_set_rpm_fl >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->drivebrain_set_rpm_fr & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->drivebrain_set_rpm_fr >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->drivebrain_set_rpm_rl & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->drivebrain_set_rpm_rl >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->drivebrain_set_rpm_rr & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->drivebrain_set_rpm_rr >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_SPEED_SET_INPUT_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_SPEED_SET_INPUT_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_SPEED_SET_INPUT_IDE;
  return DRIVEBRAIN_SPEED_SET_INPUT_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(DRIVEBRAIN_SPEED_SET_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_SPEED_SET_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->drivebrain_set_rpm_fl & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->drivebrain_set_rpm_fl >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->drivebrain_set_rpm_fr & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->drivebrain_set_rpm_fr >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->drivebrain_set_rpm_rl & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->drivebrain_set_rpm_rl >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->drivebrain_set_rpm_rr & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->drivebrain_set_rpm_rr >> 8U) & (0xFFU)) );

  *_len = (uint8_t) DRIVEBRAIN_SPEED_SET_INPUT_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_SPEED_SET_INPUT_IDE;
  return DRIVEBRAIN_SPEED_SET_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->drivebrain_torque_fl_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_phys = (sigfloat_t)(HYTECH_drivebrain_torque_fl_ro_fromS(_m->drivebrain_torque_fl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_fr_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fr_phys = (sigfloat_t)(HYTECH_drivebrain_torque_fr_ro_fromS(_m->drivebrain_torque_fr_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_rl_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_rl_phys = (sigfloat_t)(HYTECH_drivebrain_torque_rl_ro_fromS(_m->drivebrain_torque_rl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->drivebrain_torque_rr_ro = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_rr_phys = (sigfloat_t)(HYTECH_drivebrain_torque_rr_ro_fromS(_m->drivebrain_torque_rr_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(&_m->mon1, DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_ro = (int16_t) HYTECH_drivebrain_torque_fl_ro_toS(_m->drivebrain_torque_fl_phys);
  _m->drivebrain_torque_fr_ro = (int16_t) HYTECH_drivebrain_torque_fr_ro_toS(_m->drivebrain_torque_fr_phys);
  _m->drivebrain_torque_rl_ro = (int16_t) HYTECH_drivebrain_torque_rl_ro_toS(_m->drivebrain_torque_rl_phys);
  _m->drivebrain_torque_rr_ro = (int16_t) HYTECH_drivebrain_torque_rr_ro_toS(_m->drivebrain_torque_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->drivebrain_torque_fl_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->drivebrain_torque_fl_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->drivebrain_torque_fr_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->drivebrain_torque_fr_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->drivebrain_torque_rl_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->drivebrain_torque_rl_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->drivebrain_torque_rr_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->drivebrain_torque_rr_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_DESIRED_TORQUE_INPUT_IDE;
  return DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(DRIVEBRAIN_DESIRED_TORQUE_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_torque_fl_ro = (int16_t) HYTECH_drivebrain_torque_fl_ro_toS(_m->drivebrain_torque_fl_phys);
  _m->drivebrain_torque_fr_ro = (int16_t) HYTECH_drivebrain_torque_fr_ro_toS(_m->drivebrain_torque_fr_phys);
  _m->drivebrain_torque_rl_ro = (int16_t) HYTECH_drivebrain_torque_rl_ro_toS(_m->drivebrain_torque_rl_phys);
  _m->drivebrain_torque_rr_ro = (int16_t) HYTECH_drivebrain_torque_rr_ro_toS(_m->drivebrain_torque_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->drivebrain_torque_fl_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->drivebrain_torque_fl_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->drivebrain_torque_fr_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->drivebrain_torque_fr_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->drivebrain_torque_rl_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->drivebrain_torque_rl_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->drivebrain_torque_rr_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->drivebrain_torque_rr_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) DRIVEBRAIN_DESIRED_TORQUE_INPUT_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_DESIRED_TORQUE_INPUT_IDE;
  return DRIVEBRAIN_DESIRED_TORQUE_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->drivebrain_steering_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_steering_phys = (sigfloat_t)(HYTECH_drivebrain_steering_ro_fromS(_m->drivebrain_steering_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_STEERING_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_STEERING_INPUT_hytech(&_m->mon1, DRIVEBRAIN_STEERING_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_STEERING_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_STEERING_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_steering_ro = (int16_t) HYTECH_drivebrain_steering_ro_toS(_m->drivebrain_steering_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->drivebrain_steering_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->drivebrain_steering_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_STEERING_INPUT_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_STEERING_INPUT_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_STEERING_INPUT_IDE;
  return DRIVEBRAIN_STEERING_INPUT_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_STEERING_INPUT_hytech(DRIVEBRAIN_STEERING_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_STEERING_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->drivebrain_steering_ro = (int16_t) HYTECH_drivebrain_steering_ro_toS(_m->drivebrain_steering_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->drivebrain_steering_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->drivebrain_steering_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) DRIVEBRAIN_STEERING_INPUT_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_STEERING_INPUT_IDE;
  return DRIVEBRAIN_STEERING_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->thermistor_motor_fl_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_motor_fl_phys = (sigfloat_t)(HYTECH_thermistor_motor_fl_ro_fromS(_m->thermistor_motor_fl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->thermistor_motor_fr_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_motor_fr_phys = (sigfloat_t)(HYTECH_thermistor_motor_fr_ro_fromS(_m->thermistor_motor_fr_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FRONT_THERMISTORS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FRONT_THERMISTORS_hytech(&_m->mon1, FRONT_THERMISTORS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FRONT_THERMISTORS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FRONT_THERMISTORS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_motor_fl_ro = (uint16_t) HYTECH_thermistor_motor_fl_ro_toS(_m->thermistor_motor_fl_phys);
  _m->thermistor_motor_fr_ro = (uint16_t) HYTECH_thermistor_motor_fr_ro_toS(_m->thermistor_motor_fr_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->thermistor_motor_fl_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->thermistor_motor_fl_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->thermistor_motor_fr_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->thermistor_motor_fr_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) FRONT_THERMISTORS_CANID;
  cframe->DLC = (uint8_t) FRONT_THERMISTORS_DLC;
  cframe->IDE = (uint8_t) FRONT_THERMISTORS_IDE;
  return FRONT_THERMISTORS_CANID;
}

#else

uint32_t Pack_FRONT_THERMISTORS_hytech(FRONT_THERMISTORS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FRONT_THERMISTORS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->thermistor_motor_fl_ro = (uint16_t) HYTECH_thermistor_motor_fl_ro_toS(_m->thermistor_motor_fl_phys);
  _m->thermistor_motor_fr_ro = (uint16_t) HYTECH_thermistor_motor_fr_ro_toS(_m->thermistor_motor_fr_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->thermistor_motor_fl_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->thermistor_motor_fl_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->thermistor_motor_fr_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->thermistor_motor_fr_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) FRONT_THERMISTORS_DLC;
  *_ide = (uint8_t) FRONT_THERMISTORS_IDE;
  return FRONT_THERMISTORS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->em_current_ro = (int32_t) __ext_sig__(( ((_d[0] & (0xFFU)) << 24U) | ((_d[1] & (0xFFU)) << 16U) | ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 32);
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_current_phys = (sigfloat_t)(HYTECH_em_current_ro_fromS(_m->em_current_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_voltage_ro = (int32_t) __ext_sig__(( ((_d[4] & (0xFFU)) << 24U) | ((_d[5] & (0xFFU)) << 16U) | ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) ), 32);
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_voltage_phys = (sigfloat_t)(HYTECH_em_voltage_ro_fromS(_m->em_voltage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < EM_MEASUREMENT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_EM_MEASUREMENT_hytech(&_m->mon1, EM_MEASUREMENT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return EM_MEASUREMENT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(EM_MEASUREMENT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->em_current_ro = (int32_t) HYTECH_em_current_ro_toS(_m->em_current_phys);
  _m->em_voltage_ro = (int32_t) HYTECH_em_voltage_ro_toS(_m->em_voltage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->em_current_ro >> 24U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->em_current_ro >> 16U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->em_current_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->em_current_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->em_voltage_ro >> 24U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->em_voltage_ro >> 16U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->em_voltage_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->em_voltage_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) EM_MEASUREMENT_CANID;
  cframe->DLC = (uint8_t) EM_MEASUREMENT_DLC;
  cframe->IDE = (uint8_t) EM_MEASUREMENT_IDE;
  return EM_MEASUREMENT_CANID;
}

#else

uint32_t Pack_EM_MEASUREMENT_hytech(EM_MEASUREMENT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(EM_MEASUREMENT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->em_current_ro = (int32_t) HYTECH_em_current_ro_toS(_m->em_current_phys);
  _m->em_voltage_ro = (int32_t) HYTECH_em_voltage_ro_toS(_m->em_voltage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->em_current_ro >> 24U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->em_current_ro >> 16U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->em_current_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->em_current_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->em_voltage_ro >> 24U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->em_voltage_ro >> 16U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->em_voltage_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->em_voltage_ro & (0xFFU)) );

  *_len = (uint8_t) EM_MEASUREMENT_DLC;
  *_ide = (uint8_t) EM_MEASUREMENT_IDE;
  return EM_MEASUREMENT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_setpoint_rpm = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
  _m->positive_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_phys = (sigfloat_t)(HYTECH_positive_torque_limit_ro_fromS(_m->positive_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->negative_torque_limit_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->negative_torque_limit_phys = (sigfloat_t)(HYTECH_negative_torque_limit_ro_fromS(_m->negative_torque_limit_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_CONTROL_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_CONTROL_INPUT_hytech(&_m->mon1, INV2_CONTROL_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_CONTROL_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_CONTROL_INPUT_CANID;
  cframe->DLC = (uint8_t) INV2_CONTROL_INPUT_DLC;
  cframe->IDE = (uint8_t) INV2_CONTROL_INPUT_IDE;
  return INV2_CONTROL_INPUT_CANID;
}

#else

uint32_t Pack_INV2_CONTROL_INPUT_hytech(INV2_CONTROL_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->positive_torque_limit_ro = (int16_t) HYTECH_positive_torque_limit_ro_toS(_m->positive_torque_limit_phys);
  _m->negative_torque_limit_ro = (int16_t) HYTECH_negative_torque_limit_ro_toS(_m->negative_torque_limit_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->speed_setpoint_rpm & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_setpoint_rpm >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->positive_torque_limit_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->positive_torque_limit_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->negative_torque_limit_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->negative_torque_limit_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_CONTROL_INPUT_DLC;
  *_ide = (uint8_t) INV2_CONTROL_INPUT_IDE;
  return INV2_CONTROL_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_CONTROL_PARAMETER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_CONTROL_PARAMETER_hytech(&_m->mon1, INV3_CONTROL_PARAMETER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_CONTROL_PARAMETER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_PARAMETER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_CONTROL_PARAMETER_CANID;
  cframe->DLC = (uint8_t) INV3_CONTROL_PARAMETER_DLC;
  cframe->IDE = (uint8_t) INV3_CONTROL_PARAMETER_IDE;
  return INV3_CONTROL_PARAMETER_CANID;
}

#else

uint32_t Pack_INV3_CONTROL_PARAMETER_hytech(INV3_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_CONTROL_PARAMETER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_CONTROL_PARAMETER_DLC;
  *_ide = (uint8_t) INV3_CONTROL_PARAMETER_IDE;
  return INV3_CONTROL_PARAMETER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_CONTROL_PARAMETER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_CONTROL_PARAMETER_hytech(&_m->mon1, INV4_CONTROL_PARAMETER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_CONTROL_PARAMETER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_PARAMETER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_CONTROL_PARAMETER_CANID;
  cframe->DLC = (uint8_t) INV4_CONTROL_PARAMETER_DLC;
  cframe->IDE = (uint8_t) INV4_CONTROL_PARAMETER_IDE;
  return INV4_CONTROL_PARAMETER_CANID;
}

#else

uint32_t Pack_INV4_CONTROL_PARAMETER_hytech(INV4_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_CONTROL_PARAMETER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_CONTROL_PARAMETER_DLC;
  *_ide = (uint8_t) INV4_CONTROL_PARAMETER_IDE;
  return INV4_CONTROL_PARAMETER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_CONTROL_PARAMETER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_CONTROL_PARAMETER_hytech(&_m->mon1, INV1_CONTROL_PARAMETER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_CONTROL_PARAMETER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_PARAMETER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_CONTROL_PARAMETER_CANID;
  cframe->DLC = (uint8_t) INV1_CONTROL_PARAMETER_DLC;
  cframe->IDE = (uint8_t) INV1_CONTROL_PARAMETER_IDE;
  return INV1_CONTROL_PARAMETER_CANID;
}

#else

uint32_t Pack_INV1_CONTROL_PARAMETER_hytech(INV1_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_CONTROL_PARAMETER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_CONTROL_PARAMETER_DLC;
  *_ide = (uint8_t) INV1_CONTROL_PARAMETER_IDE;
  return INV1_CONTROL_PARAMETER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->speed_control_kp = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->speed_control_ki = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
  _m->speed_control_kd = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_CONTROL_PARAMETER_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_CONTROL_PARAMETER_hytech(&_m->mon1, INV2_CONTROL_PARAMETER_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_CONTROL_PARAMETER_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_PARAMETER_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_CONTROL_PARAMETER_CANID;
  cframe->DLC = (uint8_t) INV2_CONTROL_PARAMETER_DLC;
  cframe->IDE = (uint8_t) INV2_CONTROL_PARAMETER_IDE;
  return INV2_CONTROL_PARAMETER_CANID;
}

#else

uint32_t Pack_INV2_CONTROL_PARAMETER_hytech(INV2_CONTROL_PARAMETER_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_CONTROL_PARAMETER_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->speed_control_kp & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->speed_control_kp >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->speed_control_ki & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->speed_control_ki >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->speed_control_kd & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->speed_control_kd >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_CONTROL_PARAMETER_DLC;
  *_ide = (uint8_t) INV2_CONTROL_PARAMETER_IDE;
  return INV2_CONTROL_PARAMETER_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->current_A = (uint32_t) ( ((_d[0] & (0xFFU)) << 24U) | ((_d[1] & (0xFFU)) << 16U) | ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
  _m->voltage_V = (uint32_t) ( ((_d[4] & (0xFFU)) << 24U) | ((_d[5] & (0xFFU)) << 16U) | ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < ENERGY_METER_MEAS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_ENERGY_METER_MEAS_hytech(&_m->mon1, ENERGY_METER_MEAS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return ENERGY_METER_MEAS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_MEAS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( ((_m->current_A >> 24U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->current_A >> 16U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->current_A >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->current_A & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->voltage_V >> 24U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->voltage_V >> 16U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->voltage_V >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->voltage_V & (0xFFU)) );

  cframe->MsgId = (uint32_t) ENERGY_METER_MEAS_CANID;
  cframe->DLC = (uint8_t) ENERGY_METER_MEAS_DLC;
  cframe->IDE = (uint8_t) ENERGY_METER_MEAS_IDE;
  return ENERGY_METER_MEAS_CANID;
}

#else

uint32_t Pack_ENERGY_METER_MEAS_hytech(ENERGY_METER_MEAS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_MEAS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( ((_m->current_A >> 24U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->current_A >> 16U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->current_A >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->current_A & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->voltage_V >> 24U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->voltage_V >> 16U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->voltage_V >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->voltage_V & (0xFFU)) );

  *_len = (uint8_t) ENERGY_METER_MEAS_DLC;
  *_ide = (uint8_t) ENERGY_METER_MEAS_IDE;
  return ENERGY_METER_MEAS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_overload_percentage_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_phys = (sigfloat_t)(HYTECH_inverter_overload_percentage_ro_fromS(_m->inverter_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->motor_overload_percentage_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_overload_percentage_phys = (sigfloat_t)(HYTECH_motor_overload_percentage_ro_fromS(_m->motor_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV3_OVERLOAD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV3_OVERLOAD_hytech(&_m->mon1, INV3_OVERLOAD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV3_OVERLOAD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_OVERLOAD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV3_OVERLOAD_CANID;
  cframe->DLC = (uint8_t) INV3_OVERLOAD_DLC;
  cframe->IDE = (uint8_t) INV3_OVERLOAD_IDE;
  return INV3_OVERLOAD_CANID;
}

#else

uint32_t Pack_INV3_OVERLOAD_hytech(INV3_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV3_OVERLOAD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV3_OVERLOAD_DLC;
  *_ide = (uint8_t) INV3_OVERLOAD_IDE;
  return INV3_OVERLOAD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_overload_percentage_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_phys = (sigfloat_t)(HYTECH_inverter_overload_percentage_ro_fromS(_m->inverter_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->motor_overload_percentage_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_overload_percentage_phys = (sigfloat_t)(HYTECH_motor_overload_percentage_ro_fromS(_m->motor_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV4_OVERLOAD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV4_OVERLOAD_hytech(&_m->mon1, INV4_OVERLOAD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV4_OVERLOAD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_OVERLOAD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV4_OVERLOAD_CANID;
  cframe->DLC = (uint8_t) INV4_OVERLOAD_DLC;
  cframe->IDE = (uint8_t) INV4_OVERLOAD_IDE;
  return INV4_OVERLOAD_CANID;
}

#else

uint32_t Pack_INV4_OVERLOAD_hytech(INV4_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV4_OVERLOAD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV4_OVERLOAD_DLC;
  *_ide = (uint8_t) INV4_OVERLOAD_IDE;
  return INV4_OVERLOAD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_overload_percentage_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_phys = (sigfloat_t)(HYTECH_inverter_overload_percentage_ro_fromS(_m->inverter_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->motor_overload_percentage_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_overload_percentage_phys = (sigfloat_t)(HYTECH_motor_overload_percentage_ro_fromS(_m->motor_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV1_OVERLOAD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV1_OVERLOAD_hytech(&_m->mon1, INV1_OVERLOAD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV1_OVERLOAD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_OVERLOAD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV1_OVERLOAD_CANID;
  cframe->DLC = (uint8_t) INV1_OVERLOAD_DLC;
  cframe->IDE = (uint8_t) INV1_OVERLOAD_IDE;
  return INV1_OVERLOAD_CANID;
}

#else

uint32_t Pack_INV1_OVERLOAD_hytech(INV1_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV1_OVERLOAD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV1_OVERLOAD_DLC;
  *_ide = (uint8_t) INV1_OVERLOAD_IDE;
  return INV1_OVERLOAD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->inverter_overload_percentage_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_phys = (sigfloat_t)(HYTECH_inverter_overload_percentage_ro_fromS(_m->inverter_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->motor_overload_percentage_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->motor_overload_percentage_phys = (sigfloat_t)(HYTECH_motor_overload_percentage_ro_fromS(_m->motor_overload_percentage_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < INV2_OVERLOAD_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_INV2_OVERLOAD_hytech(&_m->mon1, INV2_OVERLOAD_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return INV2_OVERLOAD_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_OVERLOAD_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) INV2_OVERLOAD_CANID;
  cframe->DLC = (uint8_t) INV2_OVERLOAD_DLC;
  cframe->IDE = (uint8_t) INV2_OVERLOAD_IDE;
  return INV2_OVERLOAD_CANID;
}

#else

uint32_t Pack_INV2_OVERLOAD_hytech(INV2_OVERLOAD_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(INV2_OVERLOAD_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->inverter_overload_percentage_ro = (uint16_t) HYTECH_inverter_overload_percentage_ro_toS(_m->inverter_overload_percentage_phys);
  _m->motor_overload_percentage_ro = (uint16_t) HYTECH_motor_overload_percentage_ro_toS(_m->motor_overload_percentage_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->inverter_overload_percentage_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->inverter_overload_percentage_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->motor_overload_percentage_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->motor_overload_percentage_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) INV2_OVERLOAD_DLC;
  *_ide = (uint8_t) INV2_OVERLOAD_IDE;
  return INV2_OVERLOAD_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CAR_STATES_hytech(CAR_STATES_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->vehicle_state = (uint8_t) ( (_d[0] & (0xFFU)) );
  _m->drivetrain_state = (uint8_t) ( (_d[1] & (0xFFU)) );
  _m->drivebrain_in_control = (uint8_t) ( (_d[2] & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < CAR_STATES_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_CAR_STATES_hytech(&_m->mon1, CAR_STATES_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return CAR_STATES_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_CAR_STATES_hytech(CAR_STATES_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CAR_STATES_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->vehicle_state & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->drivetrain_state & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->drivebrain_in_control & (0x01U)) );

  cframe->MsgId = (uint32_t) CAR_STATES_CANID;
  cframe->DLC = (uint8_t) CAR_STATES_DLC;
  cframe->IDE = (uint8_t) CAR_STATES_IDE;
  return CAR_STATES_CANID;
}

#else

uint32_t Pack_CAR_STATES_hytech(CAR_STATES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CAR_STATES_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->vehicle_state & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->drivetrain_state & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->drivebrain_in_control & (0x01U)) );

  *_len = (uint8_t) CAR_STATES_DLC;
  *_ide = (uint8_t) CAR_STATES_IDE;
  return CAR_STATES_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DASH_INPUT_hytech(DASH_INPUT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->led_dimmer_button = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->preset_button = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );
  _m->motor_controller_cycle_button = (uint8_t) ( ((_d[0] >> 2U) & (0x01U)) );
  _m->mode_button = (uint8_t) ( ((_d[0] >> 3U) & (0x01U)) );
  _m->start_button = (uint8_t) ( ((_d[0] >> 4U) & (0x01U)) );
  _m->data_button_is_pressed = (uint8_t) ( ((_d[0] >> 5U) & (0x01U)) );
  _m->left_shifter_button = (uint8_t) ( ((_d[0] >> 6U) & (0x01U)) );
  _m->right_shifter_button = (uint8_t) ( ((_d[0] >> 7U) & (0x01U)) );
  _m->dash_dial_mode = (uint8_t) ( (_d[1] & (0xFFU)) );
  _m->dim_button = (uint8_t) ( (_d[2] & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DASH_INPUT_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DASH_INPUT_hytech(&_m->mon1, DASH_INPUT_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DASH_INPUT_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DASH_INPUT_hytech(DASH_INPUT_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DASH_INPUT_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->led_dimmer_button & (0x01U)) | ((_m->preset_button & (0x01U)) << 1U) | ((_m->motor_controller_cycle_button & (0x01U)) << 2U) | ((_m->mode_button & (0x01U)) << 3U) | ((_m->start_button & (0x01U)) << 4U) | ((_m->data_button_is_pressed & (0x01U)) << 5U) | ((_m->left_shifter_button & (0x01U)) << 6U) | ((_m->right_shifter_button & (0x01U)) << 7U) );
  cframe->Data[1] |= (uint8_t) ( (_m->dash_dial_mode & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->dim_button & (0x01U)) );

  cframe->MsgId = (uint32_t) DASH_INPUT_CANID;
  cframe->DLC = (uint8_t) DASH_INPUT_DLC;
  cframe->IDE = (uint8_t) DASH_INPUT_IDE;
  return DASH_INPUT_CANID;
}

#else

uint32_t Pack_DASH_INPUT_hytech(DASH_INPUT_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DASH_INPUT_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->led_dimmer_button & (0x01U)) | ((_m->preset_button & (0x01U)) << 1U) | ((_m->motor_controller_cycle_button & (0x01U)) << 2U) | ((_m->mode_button & (0x01U)) << 3U) | ((_m->start_button & (0x01U)) << 4U) | ((_m->data_button_is_pressed & (0x01U)) << 5U) | ((_m->left_shifter_button & (0x01U)) << 6U) | ((_m->right_shifter_button & (0x01U)) << 7U) );
  _d[1] |= (uint8_t) ( (_m->dash_dial_mode & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->dim_button & (0x01U)) );

  *_len = (uint8_t) DASH_INPUT_DLC;
  *_ide = (uint8_t) DASH_INPUT_IDE;
  return DASH_INPUT_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_4_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_phys = (sigfloat_t)(HYTECH_aero_channel_4_ro_fromS(_m->aero_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_5_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_5_phys = (sigfloat_t)(HYTECH_aero_channel_5_ro_fromS(_m->aero_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_6_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_6_phys = (sigfloat_t)(HYTECH_aero_channel_6_ro_fromS(_m->aero_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_7_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_7_phys = (sigfloat_t)(HYTECH_aero_channel_7_ro_fromS(_m->aero_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_22_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_22_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_22_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_22_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_22_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_22_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_22_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_22_IDE;
  return AERO_PRESSURE_SENSOR_22_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_22_hytech(AERO_PRESSURE_SENSOR_22_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_22_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_22_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_22_IDE;
  return AERO_PRESSURE_SENSOR_22_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_4_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_phys = (sigfloat_t)(HYTECH_aero_channel_4_ro_fromS(_m->aero_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_5_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_5_phys = (sigfloat_t)(HYTECH_aero_channel_5_ro_fromS(_m->aero_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_6_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_6_phys = (sigfloat_t)(HYTECH_aero_channel_6_ro_fromS(_m->aero_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_7_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_7_phys = (sigfloat_t)(HYTECH_aero_channel_7_ro_fromS(_m->aero_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_32_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_32_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_32_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_32_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_32_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_32_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_32_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_32_IDE;
  return AERO_PRESSURE_SENSOR_32_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_32_hytech(AERO_PRESSURE_SENSOR_32_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_32_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_32_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_32_IDE;
  return AERO_PRESSURE_SENSOR_32_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_4_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_phys = (sigfloat_t)(HYTECH_aero_channel_4_ro_fromS(_m->aero_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_5_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_5_phys = (sigfloat_t)(HYTECH_aero_channel_5_ro_fromS(_m->aero_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_6_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_6_phys = (sigfloat_t)(HYTECH_aero_channel_6_ro_fromS(_m->aero_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_7_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_7_phys = (sigfloat_t)(HYTECH_aero_channel_7_ro_fromS(_m->aero_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_42_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_42_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_42_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_42_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_42_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_42_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_42_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_42_IDE;
  return AERO_PRESSURE_SENSOR_42_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_42_hytech(AERO_PRESSURE_SENSOR_42_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_42_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_42_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_42_IDE;
  return AERO_PRESSURE_SENSOR_42_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_0_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_phys = (sigfloat_t)(HYTECH_aero_channel_0_ro_fromS(_m->aero_channel_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_1_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_1_phys = (sigfloat_t)(HYTECH_aero_channel_1_ro_fromS(_m->aero_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_2_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_2_phys = (sigfloat_t)(HYTECH_aero_channel_2_ro_fromS(_m->aero_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_3_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_3_phys = (sigfloat_t)(HYTECH_aero_channel_3_ro_fromS(_m->aero_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_11_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_11_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_11_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_11_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_11_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_11_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_11_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_11_IDE;
  return AERO_PRESSURE_SENSOR_11_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_11_hytech(AERO_PRESSURE_SENSOR_11_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_11_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_11_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_11_IDE;
  return AERO_PRESSURE_SENSOR_11_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_4_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_phys = (sigfloat_t)(HYTECH_aero_channel_4_ro_fromS(_m->aero_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_5_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_5_phys = (sigfloat_t)(HYTECH_aero_channel_5_ro_fromS(_m->aero_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_6_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_6_phys = (sigfloat_t)(HYTECH_aero_channel_6_ro_fromS(_m->aero_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_7_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_7_phys = (sigfloat_t)(HYTECH_aero_channel_7_ro_fromS(_m->aero_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_12_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_12_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_12_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_12_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_12_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_12_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_12_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_12_IDE;
  return AERO_PRESSURE_SENSOR_12_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_12_hytech(AERO_PRESSURE_SENSOR_12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_12_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_4_ro = (uint16_t) HYTECH_aero_channel_4_ro_toS(_m->aero_channel_4_phys);
  _m->aero_channel_5_ro = (uint16_t) HYTECH_aero_channel_5_ro_toS(_m->aero_channel_5_phys);
  _m->aero_channel_6_ro = (uint16_t) HYTECH_aero_channel_6_ro_toS(_m->aero_channel_6_phys);
  _m->aero_channel_7_ro = (uint16_t) HYTECH_aero_channel_7_ro_toS(_m->aero_channel_7_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_4_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_4_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_5_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_5_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_6_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_6_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_7_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_7_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_12_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_12_IDE;
  return AERO_PRESSURE_SENSOR_12_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_EM_STATUS_hytech(EM_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->voltage_gain = (uint8_t) ( (_d[0] & (0x0FU)) );
  _m->current_gain = (uint8_t) ( ((_d[0] >> 4U) & (0x0FU)) );
  _m->overvoltage_error = (uint8_t) ( (_d[1] & (0x01U)) );
  _m->overpower_error = (uint8_t) ( ((_d[1] >> 1U) & (0x01U)) );
  _m->logging = (uint8_t) ( ((_d[1] >> 2U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < EM_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_EM_STATUS_hytech(&_m->mon1, EM_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return EM_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_EM_STATUS_hytech(EM_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(EM_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->voltage_gain & (0x0FU)) | ((_m->current_gain & (0x0FU)) << 4U) );
  cframe->Data[1] |= (uint8_t) ( (_m->overvoltage_error & (0x01U)) | ((_m->overpower_error & (0x01U)) << 1U) | ((_m->logging & (0x01U)) << 2U) );

  cframe->MsgId = (uint32_t) EM_STATUS_CANID;
  cframe->DLC = (uint8_t) EM_STATUS_DLC;
  cframe->IDE = (uint8_t) EM_STATUS_IDE;
  return EM_STATUS_CANID;
}

#else

uint32_t Pack_EM_STATUS_hytech(EM_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(EM_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->voltage_gain & (0x0FU)) | ((_m->current_gain & (0x0FU)) << 4U) );
  _d[1] |= (uint8_t) ( (_m->overvoltage_error & (0x01U)) | ((_m->overpower_error & (0x01U)) << 1U) | ((_m->logging & (0x01U)) << 2U) );

  *_len = (uint8_t) EM_STATUS_DLC;
  *_ide = (uint8_t) EM_STATUS_IDE;
  return EM_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->em_violation = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->em_logging = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );
  _m->em_energy_w_hr = (uint32_t) ( ((_d[1] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[3] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < ENERGY_METER_STATUS_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_ENERGY_METER_STATUS_hytech(&_m->mon1, ENERGY_METER_STATUS_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return ENERGY_METER_STATUS_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_STATUS_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->em_violation & (0x01U)) | ((_m->em_logging & (0x01U)) << 1U) );
  cframe->Data[1] |= (uint8_t) ( ((_m->em_energy_w_hr >> 24U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->em_energy_w_hr >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->em_energy_w_hr >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->em_energy_w_hr & (0xFFU)) );

  cframe->MsgId = (uint32_t) ENERGY_METER_STATUS_CANID;
  cframe->DLC = (uint8_t) ENERGY_METER_STATUS_DLC;
  cframe->IDE = (uint8_t) ENERGY_METER_STATUS_IDE;
  return ENERGY_METER_STATUS_CANID;
}

#else

uint32_t Pack_ENERGY_METER_STATUS_hytech(ENERGY_METER_STATUS_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_STATUS_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->em_violation & (0x01U)) | ((_m->em_logging & (0x01U)) << 1U) );
  _d[1] |= (uint8_t) ( ((_m->em_energy_w_hr >> 24U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->em_energy_w_hr >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->em_energy_w_hr >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->em_energy_w_hr & (0xFFU)) );

  *_len = (uint8_t) ENERGY_METER_STATUS_DLC;
  *_ide = (uint8_t) ENERGY_METER_STATUS_IDE;
  return ENERGY_METER_STATUS_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->lifetime_ah_throughput_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->lifetime_ah_throughput_phys = (sigfloat_t)(HYTECH_lifetime_ah_throughput_ro_fromS(_m->lifetime_ah_throughput_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->SoH_ro = (uint8_t) ( (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->SoH_phys = (sigfloat_t)(HYTECH_SoH_ro_fromS(_m->SoH_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->SoE_ro = (uint8_t) ( (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->SoE_phys = (sigfloat_t)(HYTECH_SoE_ro_fromS(_m->SoE_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->remaining_pack_wh_ro = (uint16_t) ( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->remaining_pack_wh_phys = (sigfloat_t)(HYTECH_remaining_pack_wh_ro_fromS(_m->remaining_pack_wh_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->V1_ro = (uint16_t) ( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->V1_phys = (sigfloat_t)(HYTECH_V1_ro_fromS(_m->V1_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < STATE_OF_ENERGY_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_STATE_OF_ENERGY_hytech(&_m->mon1, STATE_OF_ENERGY_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return STATE_OF_ENERGY_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STATE_OF_ENERGY_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->lifetime_ah_throughput_ro = (uint16_t) HYTECH_lifetime_ah_throughput_ro_toS(_m->lifetime_ah_throughput_phys);
  _m->SoH_ro = (uint8_t) HYTECH_SoH_ro_toS(_m->SoH_phys);
  _m->SoE_ro = (uint8_t) HYTECH_SoE_ro_toS(_m->SoE_phys);
  _m->remaining_pack_wh_ro = (uint16_t) HYTECH_remaining_pack_wh_ro_toS(_m->remaining_pack_wh_phys);
  _m->V1_ro = (uint16_t) HYTECH_V1_ro_toS(_m->V1_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->lifetime_ah_throughput_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->lifetime_ah_throughput_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->SoH_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->SoE_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->remaining_pack_wh_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->remaining_pack_wh_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->V1_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->V1_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) STATE_OF_ENERGY_CANID;
  cframe->DLC = (uint8_t) STATE_OF_ENERGY_DLC;
  cframe->IDE = (uint8_t) STATE_OF_ENERGY_IDE;
  return STATE_OF_ENERGY_CANID;
}

#else

uint32_t Pack_STATE_OF_ENERGY_hytech(STATE_OF_ENERGY_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STATE_OF_ENERGY_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->lifetime_ah_throughput_ro = (uint16_t) HYTECH_lifetime_ah_throughput_ro_toS(_m->lifetime_ah_throughput_phys);
  _m->SoH_ro = (uint8_t) HYTECH_SoH_ro_toS(_m->SoH_phys);
  _m->SoE_ro = (uint8_t) HYTECH_SoE_ro_toS(_m->SoE_phys);
  _m->remaining_pack_wh_ro = (uint16_t) HYTECH_remaining_pack_wh_ro_toS(_m->remaining_pack_wh_phys);
  _m->V1_ro = (uint16_t) HYTECH_V1_ro_toS(_m->V1_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->lifetime_ah_throughput_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->lifetime_ah_throughput_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->SoH_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->SoE_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->remaining_pack_wh_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->remaining_pack_wh_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->V1_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->V1_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) STATE_OF_ENERGY_DLC;
  *_ide = (uint8_t) STATE_OF_ENERGY_IDE;
  return STATE_OF_ENERGY_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->SoC_ro = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->SoC_phys = (sigfloat_t)(HYTECH_SoC_ro_fromS(_m->SoC_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->min_cell_voltage_est_ro = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->min_cell_voltage_est_phys = (sigfloat_t)(HYTECH_min_cell_voltage_est_ro_fromS(_m->min_cell_voltage_est_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->charge_coulombs_ro = (uint32_t) ( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->charge_coulombs_phys = (sigfloat_t)(HYTECH_charge_coulombs_ro_fromS(_m->charge_coulombs_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < STATE_OF_CHARGE_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_STATE_OF_CHARGE_hytech(&_m->mon1, STATE_OF_CHARGE_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return STATE_OF_CHARGE_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STATE_OF_CHARGE_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->SoC_ro = (uint16_t) HYTECH_SoC_ro_toS(_m->SoC_phys);
  _m->min_cell_voltage_est_ro = (uint16_t) HYTECH_min_cell_voltage_est_ro_toS(_m->min_cell_voltage_est_phys);
  _m->charge_coulombs_ro = (uint32_t) HYTECH_charge_coulombs_ro_toS(_m->charge_coulombs_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->SoC_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->SoC_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->min_cell_voltage_est_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->min_cell_voltage_est_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->charge_coulombs_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) STATE_OF_CHARGE_CANID;
  cframe->DLC = (uint8_t) STATE_OF_CHARGE_DLC;
  cframe->IDE = (uint8_t) STATE_OF_CHARGE_IDE;
  return STATE_OF_CHARGE_CANID;
}

#else

uint32_t Pack_STATE_OF_CHARGE_hytech(STATE_OF_CHARGE_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STATE_OF_CHARGE_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->SoC_ro = (uint16_t) HYTECH_SoC_ro_toS(_m->SoC_phys);
  _m->min_cell_voltage_est_ro = (uint16_t) HYTECH_min_cell_voltage_est_ro_toS(_m->min_cell_voltage_est_phys);
  _m->charge_coulombs_ro = (uint32_t) HYTECH_charge_coulombs_ro_toS(_m->charge_coulombs_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->SoC_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->SoC_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->min_cell_voltage_est_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->min_cell_voltage_est_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->charge_coulombs_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->charge_coulombs_ro >> 24U) & (0xFFU)) );

  *_len = (uint8_t) STATE_OF_CHARGE_DLC;
  *_ide = (uint8_t) STATE_OF_CHARGE_IDE;
  return STATE_OF_CHARGE_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_STEERING_DATA_hytech(STEERING_DATA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->steering_analog_oor = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->steering_analog_raw = (uint16_t) ( ((_d[1] & (0x1FU)) << 7U) | ((_d[0] >> 1U) & (0x7FU)) );
  _m->steering_both_sensors_fail = (uint8_t) ( ((_d[1] >> 5U) & (0x01U)) );
  _m->steering_digital_oor = (uint8_t) ( ((_d[1] >> 6U) & (0x01U)) );
  _m->steering_digital_raw = (uint16_t) ( ((_d[3] & (0x1FU)) << 9U) | ((_d[2] & (0xFFU)) << 1U) | ((_d[1] >> 7U) & (0x01U)) );
  _m->steering_dtheta_exceeded_analog = (uint8_t) ( ((_d[3] >> 5U) & (0x01U)) );
  _m->steering_dtheta_exceeded_digital = (uint8_t) ( ((_d[3] >> 6U) & (0x01U)) );
  _m->steering_interface_sensor_error = (uint8_t) ( ((_d[3] >> 7U) & (0x01U)) );
  _m->steering_output_steering_angle_ro = (uint32_t) ( ((_d[6] & (0x01U)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->steering_output_steering_angle_phys = (sigfloat_t)(HYTECH_steering_output_steering_angle_ro_fromS(_m->steering_output_steering_angle_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->steering_sensor_disagreement = (uint8_t) ( ((_d[6] >> 1U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < STEERING_DATA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_STEERING_DATA_hytech(&_m->mon1, STEERING_DATA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return STEERING_DATA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_STEERING_DATA_hytech(STEERING_DATA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STEERING_DATA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->steering_output_steering_angle_ro = (uint32_t) HYTECH_steering_output_steering_angle_ro_toS(_m->steering_output_steering_angle_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->steering_analog_oor & (0x01U)) | ((_m->steering_analog_raw & (0x7FU)) << 1U) );
  cframe->Data[1] |= (uint8_t) ( ((_m->steering_analog_raw >> 7U) & (0x1FU)) | ((_m->steering_both_sensors_fail & (0x01U)) << 5U) | ((_m->steering_digital_oor & (0x01U)) << 6U) | ((_m->steering_digital_raw & (0x01U)) << 7U) );
  cframe->Data[2] |= (uint8_t) ( ((_m->steering_digital_raw >> 1U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->steering_digital_raw >> 9U) & (0x1FU)) | ((_m->steering_dtheta_exceeded_analog & (0x01U)) << 5U) | ((_m->steering_dtheta_exceeded_digital & (0x01U)) << 6U) | ((_m->steering_interface_sensor_error & (0x01U)) << 7U) );
  cframe->Data[4] |= (uint8_t) ( (_m->steering_output_steering_angle_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->steering_output_steering_angle_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->steering_output_steering_angle_ro >> 16U) & (0x01U)) | ((_m->steering_sensor_disagreement & (0x01U)) << 1U) );

  cframe->MsgId = (uint32_t) STEERING_DATA_CANID;
  cframe->DLC = (uint8_t) STEERING_DATA_DLC;
  cframe->IDE = (uint8_t) STEERING_DATA_IDE;
  return STEERING_DATA_CANID;
}

#else

uint32_t Pack_STEERING_DATA_hytech(STEERING_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(STEERING_DATA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->steering_output_steering_angle_ro = (uint32_t) HYTECH_steering_output_steering_angle_ro_toS(_m->steering_output_steering_angle_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->steering_analog_oor & (0x01U)) | ((_m->steering_analog_raw & (0x7FU)) << 1U) );
  _d[1] |= (uint8_t) ( ((_m->steering_analog_raw >> 7U) & (0x1FU)) | ((_m->steering_both_sensors_fail & (0x01U)) << 5U) | ((_m->steering_digital_oor & (0x01U)) << 6U) | ((_m->steering_digital_raw & (0x01U)) << 7U) );
  _d[2] |= (uint8_t) ( ((_m->steering_digital_raw >> 1U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->steering_digital_raw >> 9U) & (0x1FU)) | ((_m->steering_dtheta_exceeded_analog & (0x01U)) << 5U) | ((_m->steering_dtheta_exceeded_digital & (0x01U)) << 6U) | ((_m->steering_interface_sensor_error & (0x01U)) << 7U) );
  _d[4] |= (uint8_t) ( (_m->steering_output_steering_angle_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->steering_output_steering_angle_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->steering_output_steering_angle_ro >> 16U) & (0x01U)) | ((_m->steering_sensor_disagreement & (0x01U)) << 1U) );

  *_len = (uint8_t) STEERING_DATA_DLC;
  *_ide = (uint8_t) STEERING_DATA_IDE;
  return STEERING_DATA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_SN = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->LF_TTPMS_BAT_V = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
  _m->LF_TTPMS_P_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_P_phys = (sigfloat_t)(HYTECH_LF_TTPMS_P_ro_fromS(_m->LF_TTPMS_P_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_P_GAUGE = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_1_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_1_hytech(&_m->mon1, LF_TTPMS_1_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_1_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_1_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_P_ro = (uint16_t) HYTECH_LF_TTPMS_P_ro_toS(_m->LF_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_SN >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_SN & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_BAT_V & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_P_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_P_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_P_GAUGE & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_1_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_1_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_1_IDE;
  return LF_TTPMS_1_CANID;
}

#else

uint32_t Pack_LF_TTPMS_1_hytech(LF_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_1_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_P_ro = (uint16_t) HYTECH_LF_TTPMS_P_ro_toS(_m->LF_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_SN >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_SN & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_BAT_V & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_P_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_P_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_P_GAUGE & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_1_DLC;
  *_ide = (uint8_t) LF_TTPMS_1_IDE;
  return LF_TTPMS_1_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_T1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T1_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T1_ro_fromS(_m->LF_TTPMS_T1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T2_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T2_ro_fromS(_m->LF_TTPMS_T2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T3_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T3_ro_fromS(_m->LF_TTPMS_T3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T4_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T4_ro_fromS(_m->LF_TTPMS_T4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_2_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_2_hytech(&_m->mon1, LF_TTPMS_2_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_2_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_2_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T1_ro = (uint16_t) HYTECH_LF_TTPMS_T1_ro_toS(_m->LF_TTPMS_T1_phys);
  _m->LF_TTPMS_T2_ro = (uint16_t) HYTECH_LF_TTPMS_T2_ro_toS(_m->LF_TTPMS_T2_phys);
  _m->LF_TTPMS_T3_ro = (uint16_t) HYTECH_LF_TTPMS_T3_ro_toS(_m->LF_TTPMS_T3_phys);
  _m->LF_TTPMS_T4_ro = (uint16_t) HYTECH_LF_TTPMS_T4_ro_toS(_m->LF_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_T1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_T2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_T3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_T4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_2_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_2_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_2_IDE;
  return LF_TTPMS_2_CANID;
}

#else

uint32_t Pack_LF_TTPMS_2_hytech(LF_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_2_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T1_ro = (uint16_t) HYTECH_LF_TTPMS_T1_ro_toS(_m->LF_TTPMS_T1_phys);
  _m->LF_TTPMS_T2_ro = (uint16_t) HYTECH_LF_TTPMS_T2_ro_toS(_m->LF_TTPMS_T2_phys);
  _m->LF_TTPMS_T3_ro = (uint16_t) HYTECH_LF_TTPMS_T3_ro_toS(_m->LF_TTPMS_T3_phys);
  _m->LF_TTPMS_T4_ro = (uint16_t) HYTECH_LF_TTPMS_T4_ro_toS(_m->LF_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_T1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_T2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_T3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_T4_ro & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_2_DLC;
  *_ide = (uint8_t) LF_TTPMS_2_IDE;
  return LF_TTPMS_2_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_T5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T5_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T5_ro_fromS(_m->LF_TTPMS_T5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T6_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T6_ro_fromS(_m->LF_TTPMS_T6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T7_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T7_ro_fromS(_m->LF_TTPMS_T7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T8_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T8_ro_fromS(_m->LF_TTPMS_T8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_3_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_3_hytech(&_m->mon1, LF_TTPMS_3_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_3_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_3_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T5_ro = (uint16_t) HYTECH_LF_TTPMS_T5_ro_toS(_m->LF_TTPMS_T5_phys);
  _m->LF_TTPMS_T6_ro = (uint16_t) HYTECH_LF_TTPMS_T6_ro_toS(_m->LF_TTPMS_T6_phys);
  _m->LF_TTPMS_T7_ro = (uint16_t) HYTECH_LF_TTPMS_T7_ro_toS(_m->LF_TTPMS_T7_phys);
  _m->LF_TTPMS_T8_ro = (uint16_t) HYTECH_LF_TTPMS_T8_ro_toS(_m->LF_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_T5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_T6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_T7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_T8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_3_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_3_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_3_IDE;
  return LF_TTPMS_3_CANID;
}

#else

uint32_t Pack_LF_TTPMS_3_hytech(LF_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_3_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T5_ro = (uint16_t) HYTECH_LF_TTPMS_T5_ro_toS(_m->LF_TTPMS_T5_phys);
  _m->LF_TTPMS_T6_ro = (uint16_t) HYTECH_LF_TTPMS_T6_ro_toS(_m->LF_TTPMS_T6_phys);
  _m->LF_TTPMS_T7_ro = (uint16_t) HYTECH_LF_TTPMS_T7_ro_toS(_m->LF_TTPMS_T7_phys);
  _m->LF_TTPMS_T8_ro = (uint16_t) HYTECH_LF_TTPMS_T8_ro_toS(_m->LF_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_T5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_T6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_T7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_T8_ro & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_3_DLC;
  *_ide = (uint8_t) LF_TTPMS_3_IDE;
  return LF_TTPMS_3_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_T9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T9_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T9_ro_fromS(_m->LF_TTPMS_T9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T10_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T10_ro_fromS(_m->LF_TTPMS_T10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T11_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T11_ro_fromS(_m->LF_TTPMS_T11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T12_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T12_ro_fromS(_m->LF_TTPMS_T12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_4_hytech(&_m->mon1, LF_TTPMS_4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T9_ro = (uint16_t) HYTECH_LF_TTPMS_T9_ro_toS(_m->LF_TTPMS_T9_phys);
  _m->LF_TTPMS_T10_ro = (uint16_t) HYTECH_LF_TTPMS_T10_ro_toS(_m->LF_TTPMS_T10_phys);
  _m->LF_TTPMS_T11_ro = (uint16_t) HYTECH_LF_TTPMS_T11_ro_toS(_m->LF_TTPMS_T11_phys);
  _m->LF_TTPMS_T12_ro = (uint16_t) HYTECH_LF_TTPMS_T12_ro_toS(_m->LF_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_T9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_T10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_T11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_T12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_4_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_4_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_4_IDE;
  return LF_TTPMS_4_CANID;
}

#else

uint32_t Pack_LF_TTPMS_4_hytech(LF_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T9_ro = (uint16_t) HYTECH_LF_TTPMS_T9_ro_toS(_m->LF_TTPMS_T9_phys);
  _m->LF_TTPMS_T10_ro = (uint16_t) HYTECH_LF_TTPMS_T10_ro_toS(_m->LF_TTPMS_T10_phys);
  _m->LF_TTPMS_T11_ro = (uint16_t) HYTECH_LF_TTPMS_T11_ro_toS(_m->LF_TTPMS_T11_phys);
  _m->LF_TTPMS_T12_ro = (uint16_t) HYTECH_LF_TTPMS_T12_ro_toS(_m->LF_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_T9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_T10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_T11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_T12_ro & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_4_DLC;
  *_ide = (uint8_t) LF_TTPMS_4_IDE;
  return LF_TTPMS_4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_T13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T13_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T13_ro_fromS(_m->LF_TTPMS_T13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T14_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T14_ro_fromS(_m->LF_TTPMS_T14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T15_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T15_ro_fromS(_m->LF_TTPMS_T15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_T16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T16_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T16_ro_fromS(_m->LF_TTPMS_T16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_5_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_5_hytech(&_m->mon1, LF_TTPMS_5_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_5_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_5_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T13_ro = (uint16_t) HYTECH_LF_TTPMS_T13_ro_toS(_m->LF_TTPMS_T13_phys);
  _m->LF_TTPMS_T14_ro = (uint16_t) HYTECH_LF_TTPMS_T14_ro_toS(_m->LF_TTPMS_T14_phys);
  _m->LF_TTPMS_T15_ro = (uint16_t) HYTECH_LF_TTPMS_T15_ro_toS(_m->LF_TTPMS_T15_phys);
  _m->LF_TTPMS_T16_ro = (uint16_t) HYTECH_LF_TTPMS_T16_ro_toS(_m->LF_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_T13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_T14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_T15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_T16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_5_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_5_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_5_IDE;
  return LF_TTPMS_5_CANID;
}

#else

uint32_t Pack_LF_TTPMS_5_hytech(LF_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_5_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T13_ro = (uint16_t) HYTECH_LF_TTPMS_T13_ro_toS(_m->LF_TTPMS_T13_phys);
  _m->LF_TTPMS_T14_ro = (uint16_t) HYTECH_LF_TTPMS_T14_ro_toS(_m->LF_TTPMS_T14_phys);
  _m->LF_TTPMS_T15_ro = (uint16_t) HYTECH_LF_TTPMS_T15_ro_toS(_m->LF_TTPMS_T15_phys);
  _m->LF_TTPMS_T16_ro = (uint16_t) HYTECH_LF_TTPMS_T16_ro_toS(_m->LF_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_T13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_T14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_T15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_T16_ro & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_5_DLC;
  *_ide = (uint8_t) LF_TTPMS_5_IDE;
  return LF_TTPMS_5_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LF_TTPMS_TC = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->LF_TTPMS_RSSI = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
  _m->LF_TTPMS_T_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T_phys = (sigfloat_t)(HYTECH_LF_TTPMS_T_ro_fromS(_m->LF_TTPMS_T_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LF_TTPMS_NODE_ID = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LF_TTPMS_6_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LF_TTPMS_6_hytech(&_m->mon1, LF_TTPMS_6_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LF_TTPMS_6_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_6_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T_ro = (uint16_t) HYTECH_LF_TTPMS_T_ro_toS(_m->LF_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LF_TTPMS_TC >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LF_TTPMS_TC & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LF_TTPMS_RSSI >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LF_TTPMS_RSSI & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LF_TTPMS_T_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LF_TTPMS_T_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LF_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LF_TTPMS_NODE_ID & (0xFFU)) );

  cframe->MsgId = (uint32_t) LF_TTPMS_6_CANID;
  cframe->DLC = (uint8_t) LF_TTPMS_6_DLC;
  cframe->IDE = (uint8_t) LF_TTPMS_6_IDE;
  return LF_TTPMS_6_CANID;
}

#else

uint32_t Pack_LF_TTPMS_6_hytech(LF_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LF_TTPMS_6_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LF_TTPMS_T_ro = (uint16_t) HYTECH_LF_TTPMS_T_ro_toS(_m->LF_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LF_TTPMS_TC >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LF_TTPMS_TC & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LF_TTPMS_RSSI >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LF_TTPMS_RSSI & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LF_TTPMS_T_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LF_TTPMS_T_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LF_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LF_TTPMS_NODE_ID & (0xFFU)) );

  *_len = (uint8_t) LF_TTPMS_6_DLC;
  *_ide = (uint8_t) LF_TTPMS_6_IDE;
  return LF_TTPMS_6_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_SN = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->RF_TTPMS_BAT_V = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
  _m->RF_TTPMS_P_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_P_phys = (sigfloat_t)(HYTECH_RF_TTPMS_P_ro_fromS(_m->RF_TTPMS_P_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_P_GAUGE = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_1_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_1_hytech(&_m->mon1, RF_TTPMS_1_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_1_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_1_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_P_ro = (uint16_t) HYTECH_RF_TTPMS_P_ro_toS(_m->RF_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_SN >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_SN & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_BAT_V & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_P_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_P_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_P_GAUGE & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_1_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_1_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_1_IDE;
  return RF_TTPMS_1_CANID;
}

#else

uint32_t Pack_RF_TTPMS_1_hytech(RF_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_1_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_P_ro = (uint16_t) HYTECH_RF_TTPMS_P_ro_toS(_m->RF_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_SN >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_SN & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_BAT_V & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_P_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_P_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_P_GAUGE & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_1_DLC;
  *_ide = (uint8_t) RF_TTPMS_1_IDE;
  return RF_TTPMS_1_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_T1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T1_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T1_ro_fromS(_m->RF_TTPMS_T1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T2_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T2_ro_fromS(_m->RF_TTPMS_T2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T3_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T3_ro_fromS(_m->RF_TTPMS_T3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T4_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T4_ro_fromS(_m->RF_TTPMS_T4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_2_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_2_hytech(&_m->mon1, RF_TTPMS_2_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_2_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_2_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T1_ro = (uint16_t) HYTECH_RF_TTPMS_T1_ro_toS(_m->RF_TTPMS_T1_phys);
  _m->RF_TTPMS_T2_ro = (uint16_t) HYTECH_RF_TTPMS_T2_ro_toS(_m->RF_TTPMS_T2_phys);
  _m->RF_TTPMS_T3_ro = (uint16_t) HYTECH_RF_TTPMS_T3_ro_toS(_m->RF_TTPMS_T3_phys);
  _m->RF_TTPMS_T4_ro = (uint16_t) HYTECH_RF_TTPMS_T4_ro_toS(_m->RF_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_T1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_T2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_T3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_T4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_2_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_2_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_2_IDE;
  return RF_TTPMS_2_CANID;
}

#else

uint32_t Pack_RF_TTPMS_2_hytech(RF_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_2_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T1_ro = (uint16_t) HYTECH_RF_TTPMS_T1_ro_toS(_m->RF_TTPMS_T1_phys);
  _m->RF_TTPMS_T2_ro = (uint16_t) HYTECH_RF_TTPMS_T2_ro_toS(_m->RF_TTPMS_T2_phys);
  _m->RF_TTPMS_T3_ro = (uint16_t) HYTECH_RF_TTPMS_T3_ro_toS(_m->RF_TTPMS_T3_phys);
  _m->RF_TTPMS_T4_ro = (uint16_t) HYTECH_RF_TTPMS_T4_ro_toS(_m->RF_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_T1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_T2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_T3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_T4_ro & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_2_DLC;
  *_ide = (uint8_t) RF_TTPMS_2_IDE;
  return RF_TTPMS_2_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_T5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T5_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T5_ro_fromS(_m->RF_TTPMS_T5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T6_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T6_ro_fromS(_m->RF_TTPMS_T6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T7_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T7_ro_fromS(_m->RF_TTPMS_T7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T8_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T8_ro_fromS(_m->RF_TTPMS_T8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_3_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_3_hytech(&_m->mon1, RF_TTPMS_3_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_3_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_3_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T5_ro = (uint16_t) HYTECH_RF_TTPMS_T5_ro_toS(_m->RF_TTPMS_T5_phys);
  _m->RF_TTPMS_T6_ro = (uint16_t) HYTECH_RF_TTPMS_T6_ro_toS(_m->RF_TTPMS_T6_phys);
  _m->RF_TTPMS_T7_ro = (uint16_t) HYTECH_RF_TTPMS_T7_ro_toS(_m->RF_TTPMS_T7_phys);
  _m->RF_TTPMS_T8_ro = (uint16_t) HYTECH_RF_TTPMS_T8_ro_toS(_m->RF_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_T5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_T6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_T7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_T8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_3_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_3_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_3_IDE;
  return RF_TTPMS_3_CANID;
}

#else

uint32_t Pack_RF_TTPMS_3_hytech(RF_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_3_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T5_ro = (uint16_t) HYTECH_RF_TTPMS_T5_ro_toS(_m->RF_TTPMS_T5_phys);
  _m->RF_TTPMS_T6_ro = (uint16_t) HYTECH_RF_TTPMS_T6_ro_toS(_m->RF_TTPMS_T6_phys);
  _m->RF_TTPMS_T7_ro = (uint16_t) HYTECH_RF_TTPMS_T7_ro_toS(_m->RF_TTPMS_T7_phys);
  _m->RF_TTPMS_T8_ro = (uint16_t) HYTECH_RF_TTPMS_T8_ro_toS(_m->RF_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_T5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_T6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_T7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_T8_ro & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_3_DLC;
  *_ide = (uint8_t) RF_TTPMS_3_IDE;
  return RF_TTPMS_3_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_T9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T9_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T9_ro_fromS(_m->RF_TTPMS_T9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T10_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T10_ro_fromS(_m->RF_TTPMS_T10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T11_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T11_ro_fromS(_m->RF_TTPMS_T11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T12_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T12_ro_fromS(_m->RF_TTPMS_T12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_4_hytech(&_m->mon1, RF_TTPMS_4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T9_ro = (uint16_t) HYTECH_RF_TTPMS_T9_ro_toS(_m->RF_TTPMS_T9_phys);
  _m->RF_TTPMS_T10_ro = (uint16_t) HYTECH_RF_TTPMS_T10_ro_toS(_m->RF_TTPMS_T10_phys);
  _m->RF_TTPMS_T11_ro = (uint16_t) HYTECH_RF_TTPMS_T11_ro_toS(_m->RF_TTPMS_T11_phys);
  _m->RF_TTPMS_T12_ro = (uint16_t) HYTECH_RF_TTPMS_T12_ro_toS(_m->RF_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_T9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_T10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_T11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_T12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_4_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_4_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_4_IDE;
  return RF_TTPMS_4_CANID;
}

#else

uint32_t Pack_RF_TTPMS_4_hytech(RF_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T9_ro = (uint16_t) HYTECH_RF_TTPMS_T9_ro_toS(_m->RF_TTPMS_T9_phys);
  _m->RF_TTPMS_T10_ro = (uint16_t) HYTECH_RF_TTPMS_T10_ro_toS(_m->RF_TTPMS_T10_phys);
  _m->RF_TTPMS_T11_ro = (uint16_t) HYTECH_RF_TTPMS_T11_ro_toS(_m->RF_TTPMS_T11_phys);
  _m->RF_TTPMS_T12_ro = (uint16_t) HYTECH_RF_TTPMS_T12_ro_toS(_m->RF_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_T9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_T10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_T11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_T12_ro & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_4_DLC;
  *_ide = (uint8_t) RF_TTPMS_4_IDE;
  return RF_TTPMS_4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_T13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T13_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T13_ro_fromS(_m->RF_TTPMS_T13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T14_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T14_ro_fromS(_m->RF_TTPMS_T14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T15_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T15_ro_fromS(_m->RF_TTPMS_T15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_T16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T16_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T16_ro_fromS(_m->RF_TTPMS_T16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_5_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_5_hytech(&_m->mon1, RF_TTPMS_5_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_5_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_5_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T13_ro = (uint16_t) HYTECH_RF_TTPMS_T13_ro_toS(_m->RF_TTPMS_T13_phys);
  _m->RF_TTPMS_T14_ro = (uint16_t) HYTECH_RF_TTPMS_T14_ro_toS(_m->RF_TTPMS_T14_phys);
  _m->RF_TTPMS_T15_ro = (uint16_t) HYTECH_RF_TTPMS_T15_ro_toS(_m->RF_TTPMS_T15_phys);
  _m->RF_TTPMS_T16_ro = (uint16_t) HYTECH_RF_TTPMS_T16_ro_toS(_m->RF_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_T13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_T14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_T15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_T16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_5_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_5_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_5_IDE;
  return RF_TTPMS_5_CANID;
}

#else

uint32_t Pack_RF_TTPMS_5_hytech(RF_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_5_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T13_ro = (uint16_t) HYTECH_RF_TTPMS_T13_ro_toS(_m->RF_TTPMS_T13_phys);
  _m->RF_TTPMS_T14_ro = (uint16_t) HYTECH_RF_TTPMS_T14_ro_toS(_m->RF_TTPMS_T14_phys);
  _m->RF_TTPMS_T15_ro = (uint16_t) HYTECH_RF_TTPMS_T15_ro_toS(_m->RF_TTPMS_T15_phys);
  _m->RF_TTPMS_T16_ro = (uint16_t) HYTECH_RF_TTPMS_T16_ro_toS(_m->RF_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_T13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_T14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_T15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_T16_ro & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_5_DLC;
  *_ide = (uint8_t) RF_TTPMS_5_IDE;
  return RF_TTPMS_5_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RF_TTPMS_TC = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->RF_TTPMS_RSSI = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
  _m->RF_TTPMS_T_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T_phys = (sigfloat_t)(HYTECH_RF_TTPMS_T_ro_fromS(_m->RF_TTPMS_T_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RF_TTPMS_NODE_ID = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RF_TTPMS_6_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RF_TTPMS_6_hytech(&_m->mon1, RF_TTPMS_6_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RF_TTPMS_6_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_6_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T_ro = (uint16_t) HYTECH_RF_TTPMS_T_ro_toS(_m->RF_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RF_TTPMS_TC >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RF_TTPMS_TC & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RF_TTPMS_RSSI >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RF_TTPMS_RSSI & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RF_TTPMS_T_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RF_TTPMS_T_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RF_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RF_TTPMS_NODE_ID & (0xFFU)) );

  cframe->MsgId = (uint32_t) RF_TTPMS_6_CANID;
  cframe->DLC = (uint8_t) RF_TTPMS_6_DLC;
  cframe->IDE = (uint8_t) RF_TTPMS_6_IDE;
  return RF_TTPMS_6_CANID;
}

#else

uint32_t Pack_RF_TTPMS_6_hytech(RF_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RF_TTPMS_6_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RF_TTPMS_T_ro = (uint16_t) HYTECH_RF_TTPMS_T_ro_toS(_m->RF_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RF_TTPMS_TC >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RF_TTPMS_TC & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RF_TTPMS_RSSI >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RF_TTPMS_RSSI & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RF_TTPMS_T_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RF_TTPMS_T_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RF_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RF_TTPMS_NODE_ID & (0xFFU)) );

  *_len = (uint8_t) RF_TTPMS_6_DLC;
  *_ide = (uint8_t) RF_TTPMS_6_IDE;
  return RF_TTPMS_6_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_SN = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->LR_TTPMS_BAT_V = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
  _m->LR_TTPMS_P_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_P_phys = (sigfloat_t)(HYTECH_LR_TTPMS_P_ro_fromS(_m->LR_TTPMS_P_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_P_GAUGE = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_1_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_1_hytech(&_m->mon1, LR_TTPMS_1_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_1_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_1_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_P_ro = (uint16_t) HYTECH_LR_TTPMS_P_ro_toS(_m->LR_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_SN >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_SN & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_BAT_V & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_P_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_P_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_P_GAUGE & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_1_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_1_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_1_IDE;
  return LR_TTPMS_1_CANID;
}

#else

uint32_t Pack_LR_TTPMS_1_hytech(LR_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_1_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_P_ro = (uint16_t) HYTECH_LR_TTPMS_P_ro_toS(_m->LR_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_SN >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_SN & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_BAT_V & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_P_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_P_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_P_GAUGE & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_1_DLC;
  *_ide = (uint8_t) LR_TTPMS_1_IDE;
  return LR_TTPMS_1_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_T1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T1_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T1_ro_fromS(_m->LR_TTPMS_T1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T2_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T2_ro_fromS(_m->LR_TTPMS_T2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T3_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T3_ro_fromS(_m->LR_TTPMS_T3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T4_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T4_ro_fromS(_m->LR_TTPMS_T4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_2_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_2_hytech(&_m->mon1, LR_TTPMS_2_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_2_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_2_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T1_ro = (uint16_t) HYTECH_LR_TTPMS_T1_ro_toS(_m->LR_TTPMS_T1_phys);
  _m->LR_TTPMS_T2_ro = (uint16_t) HYTECH_LR_TTPMS_T2_ro_toS(_m->LR_TTPMS_T2_phys);
  _m->LR_TTPMS_T3_ro = (uint16_t) HYTECH_LR_TTPMS_T3_ro_toS(_m->LR_TTPMS_T3_phys);
  _m->LR_TTPMS_T4_ro = (uint16_t) HYTECH_LR_TTPMS_T4_ro_toS(_m->LR_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_T1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_T2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_T3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_T4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_2_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_2_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_2_IDE;
  return LR_TTPMS_2_CANID;
}

#else

uint32_t Pack_LR_TTPMS_2_hytech(LR_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_2_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T1_ro = (uint16_t) HYTECH_LR_TTPMS_T1_ro_toS(_m->LR_TTPMS_T1_phys);
  _m->LR_TTPMS_T2_ro = (uint16_t) HYTECH_LR_TTPMS_T2_ro_toS(_m->LR_TTPMS_T2_phys);
  _m->LR_TTPMS_T3_ro = (uint16_t) HYTECH_LR_TTPMS_T3_ro_toS(_m->LR_TTPMS_T3_phys);
  _m->LR_TTPMS_T4_ro = (uint16_t) HYTECH_LR_TTPMS_T4_ro_toS(_m->LR_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_T1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_T2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_T3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_T4_ro & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_2_DLC;
  *_ide = (uint8_t) LR_TTPMS_2_IDE;
  return LR_TTPMS_2_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_T5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T5_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T5_ro_fromS(_m->LR_TTPMS_T5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T6_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T6_ro_fromS(_m->LR_TTPMS_T6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T7_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T7_ro_fromS(_m->LR_TTPMS_T7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T8_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T8_ro_fromS(_m->LR_TTPMS_T8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_3_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_3_hytech(&_m->mon1, LR_TTPMS_3_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_3_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_3_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T5_ro = (uint16_t) HYTECH_LR_TTPMS_T5_ro_toS(_m->LR_TTPMS_T5_phys);
  _m->LR_TTPMS_T6_ro = (uint16_t) HYTECH_LR_TTPMS_T6_ro_toS(_m->LR_TTPMS_T6_phys);
  _m->LR_TTPMS_T7_ro = (uint16_t) HYTECH_LR_TTPMS_T7_ro_toS(_m->LR_TTPMS_T7_phys);
  _m->LR_TTPMS_T8_ro = (uint16_t) HYTECH_LR_TTPMS_T8_ro_toS(_m->LR_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_T5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_T6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_T7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_T8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_3_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_3_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_3_IDE;
  return LR_TTPMS_3_CANID;
}

#else

uint32_t Pack_LR_TTPMS_3_hytech(LR_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_3_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T5_ro = (uint16_t) HYTECH_LR_TTPMS_T5_ro_toS(_m->LR_TTPMS_T5_phys);
  _m->LR_TTPMS_T6_ro = (uint16_t) HYTECH_LR_TTPMS_T6_ro_toS(_m->LR_TTPMS_T6_phys);
  _m->LR_TTPMS_T7_ro = (uint16_t) HYTECH_LR_TTPMS_T7_ro_toS(_m->LR_TTPMS_T7_phys);
  _m->LR_TTPMS_T8_ro = (uint16_t) HYTECH_LR_TTPMS_T8_ro_toS(_m->LR_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_T5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_T6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_T7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_T8_ro & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_3_DLC;
  *_ide = (uint8_t) LR_TTPMS_3_IDE;
  return LR_TTPMS_3_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_T9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T9_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T9_ro_fromS(_m->LR_TTPMS_T9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T10_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T10_ro_fromS(_m->LR_TTPMS_T10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T11_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T11_ro_fromS(_m->LR_TTPMS_T11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T12_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T12_ro_fromS(_m->LR_TTPMS_T12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_4_hytech(&_m->mon1, LR_TTPMS_4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T9_ro = (uint16_t) HYTECH_LR_TTPMS_T9_ro_toS(_m->LR_TTPMS_T9_phys);
  _m->LR_TTPMS_T10_ro = (uint16_t) HYTECH_LR_TTPMS_T10_ro_toS(_m->LR_TTPMS_T10_phys);
  _m->LR_TTPMS_T11_ro = (uint16_t) HYTECH_LR_TTPMS_T11_ro_toS(_m->LR_TTPMS_T11_phys);
  _m->LR_TTPMS_T12_ro = (uint16_t) HYTECH_LR_TTPMS_T12_ro_toS(_m->LR_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_T9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_T10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_T11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_T12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_4_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_4_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_4_IDE;
  return LR_TTPMS_4_CANID;
}

#else

uint32_t Pack_LR_TTPMS_4_hytech(LR_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T9_ro = (uint16_t) HYTECH_LR_TTPMS_T9_ro_toS(_m->LR_TTPMS_T9_phys);
  _m->LR_TTPMS_T10_ro = (uint16_t) HYTECH_LR_TTPMS_T10_ro_toS(_m->LR_TTPMS_T10_phys);
  _m->LR_TTPMS_T11_ro = (uint16_t) HYTECH_LR_TTPMS_T11_ro_toS(_m->LR_TTPMS_T11_phys);
  _m->LR_TTPMS_T12_ro = (uint16_t) HYTECH_LR_TTPMS_T12_ro_toS(_m->LR_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_T9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_T10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_T11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_T12_ro & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_4_DLC;
  *_ide = (uint8_t) LR_TTPMS_4_IDE;
  return LR_TTPMS_4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_T13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T13_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T13_ro_fromS(_m->LR_TTPMS_T13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T14_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T14_ro_fromS(_m->LR_TTPMS_T14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T15_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T15_ro_fromS(_m->LR_TTPMS_T15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_T16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T16_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T16_ro_fromS(_m->LR_TTPMS_T16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_5_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_5_hytech(&_m->mon1, LR_TTPMS_5_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_5_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_5_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T13_ro = (uint16_t) HYTECH_LR_TTPMS_T13_ro_toS(_m->LR_TTPMS_T13_phys);
  _m->LR_TTPMS_T14_ro = (uint16_t) HYTECH_LR_TTPMS_T14_ro_toS(_m->LR_TTPMS_T14_phys);
  _m->LR_TTPMS_T15_ro = (uint16_t) HYTECH_LR_TTPMS_T15_ro_toS(_m->LR_TTPMS_T15_phys);
  _m->LR_TTPMS_T16_ro = (uint16_t) HYTECH_LR_TTPMS_T16_ro_toS(_m->LR_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_T13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_T14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_T15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_T16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_5_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_5_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_5_IDE;
  return LR_TTPMS_5_CANID;
}

#else

uint32_t Pack_LR_TTPMS_5_hytech(LR_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_5_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T13_ro = (uint16_t) HYTECH_LR_TTPMS_T13_ro_toS(_m->LR_TTPMS_T13_phys);
  _m->LR_TTPMS_T14_ro = (uint16_t) HYTECH_LR_TTPMS_T14_ro_toS(_m->LR_TTPMS_T14_phys);
  _m->LR_TTPMS_T15_ro = (uint16_t) HYTECH_LR_TTPMS_T15_ro_toS(_m->LR_TTPMS_T15_phys);
  _m->LR_TTPMS_T16_ro = (uint16_t) HYTECH_LR_TTPMS_T16_ro_toS(_m->LR_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_T13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_T14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_T15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_T16_ro & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_5_DLC;
  *_ide = (uint8_t) LR_TTPMS_5_IDE;
  return LR_TTPMS_5_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->LR_TTPMS_TC = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->LR_TTPMS_RSSI = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
  _m->LR_TTPMS_T_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T_phys = (sigfloat_t)(HYTECH_LR_TTPMS_T_ro_fromS(_m->LR_TTPMS_T_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->LR_TTPMS_NODE_ID = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < LR_TTPMS_6_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_LR_TTPMS_6_hytech(&_m->mon1, LR_TTPMS_6_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return LR_TTPMS_6_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_6_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T_ro = (uint16_t) HYTECH_LR_TTPMS_T_ro_toS(_m->LR_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->LR_TTPMS_TC >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->LR_TTPMS_TC & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->LR_TTPMS_RSSI >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->LR_TTPMS_RSSI & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->LR_TTPMS_T_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->LR_TTPMS_T_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->LR_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->LR_TTPMS_NODE_ID & (0xFFU)) );

  cframe->MsgId = (uint32_t) LR_TTPMS_6_CANID;
  cframe->DLC = (uint8_t) LR_TTPMS_6_DLC;
  cframe->IDE = (uint8_t) LR_TTPMS_6_IDE;
  return LR_TTPMS_6_CANID;
}

#else

uint32_t Pack_LR_TTPMS_6_hytech(LR_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(LR_TTPMS_6_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->LR_TTPMS_T_ro = (uint16_t) HYTECH_LR_TTPMS_T_ro_toS(_m->LR_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->LR_TTPMS_TC >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->LR_TTPMS_TC & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->LR_TTPMS_RSSI >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->LR_TTPMS_RSSI & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->LR_TTPMS_T_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->LR_TTPMS_T_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->LR_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->LR_TTPMS_NODE_ID & (0xFFU)) );

  *_len = (uint8_t) LR_TTPMS_6_DLC;
  *_ide = (uint8_t) LR_TTPMS_6_IDE;
  return LR_TTPMS_6_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_SN = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->RR_TTPMS_BAT_V = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
  _m->RR_TTPMS_P_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_P_phys = (sigfloat_t)(HYTECH_RR_TTPMS_P_ro_fromS(_m->RR_TTPMS_P_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_P_GAUGE = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_1_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_1_hytech(&_m->mon1, RR_TTPMS_1_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_1_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_1_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_P_ro = (uint16_t) HYTECH_RR_TTPMS_P_ro_toS(_m->RR_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_SN >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_SN & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_BAT_V & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_P_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_P_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_P_GAUGE & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_1_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_1_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_1_IDE;
  return RR_TTPMS_1_CANID;
}

#else

uint32_t Pack_RR_TTPMS_1_hytech(RR_TTPMS_1_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_1_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_P_ro = (uint16_t) HYTECH_RR_TTPMS_P_ro_toS(_m->RR_TTPMS_P_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_SN >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_SN & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_BAT_V >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_BAT_V & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_P_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_P_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_P_GAUGE >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_P_GAUGE & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_1_DLC;
  *_ide = (uint8_t) RR_TTPMS_1_IDE;
  return RR_TTPMS_1_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_T1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T1_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T1_ro_fromS(_m->RR_TTPMS_T1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T2_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T2_ro_fromS(_m->RR_TTPMS_T2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T3_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T3_ro_fromS(_m->RR_TTPMS_T3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T4_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T4_ro_fromS(_m->RR_TTPMS_T4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_2_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_2_hytech(&_m->mon1, RR_TTPMS_2_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_2_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_2_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T1_ro = (uint16_t) HYTECH_RR_TTPMS_T1_ro_toS(_m->RR_TTPMS_T1_phys);
  _m->RR_TTPMS_T2_ro = (uint16_t) HYTECH_RR_TTPMS_T2_ro_toS(_m->RR_TTPMS_T2_phys);
  _m->RR_TTPMS_T3_ro = (uint16_t) HYTECH_RR_TTPMS_T3_ro_toS(_m->RR_TTPMS_T3_phys);
  _m->RR_TTPMS_T4_ro = (uint16_t) HYTECH_RR_TTPMS_T4_ro_toS(_m->RR_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_T1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_T2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_T3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_T4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_2_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_2_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_2_IDE;
  return RR_TTPMS_2_CANID;
}

#else

uint32_t Pack_RR_TTPMS_2_hytech(RR_TTPMS_2_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_2_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T1_ro = (uint16_t) HYTECH_RR_TTPMS_T1_ro_toS(_m->RR_TTPMS_T1_phys);
  _m->RR_TTPMS_T2_ro = (uint16_t) HYTECH_RR_TTPMS_T2_ro_toS(_m->RR_TTPMS_T2_phys);
  _m->RR_TTPMS_T3_ro = (uint16_t) HYTECH_RR_TTPMS_T3_ro_toS(_m->RR_TTPMS_T3_phys);
  _m->RR_TTPMS_T4_ro = (uint16_t) HYTECH_RR_TTPMS_T4_ro_toS(_m->RR_TTPMS_T4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_T1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_T1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_T2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_T2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_T3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_T3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_T4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_T4_ro & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_2_DLC;
  *_ide = (uint8_t) RR_TTPMS_2_IDE;
  return RR_TTPMS_2_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_T5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T5_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T5_ro_fromS(_m->RR_TTPMS_T5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T6_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T6_ro_fromS(_m->RR_TTPMS_T6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T7_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T7_ro_fromS(_m->RR_TTPMS_T7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T8_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T8_ro_fromS(_m->RR_TTPMS_T8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_3_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_3_hytech(&_m->mon1, RR_TTPMS_3_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_3_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_3_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T5_ro = (uint16_t) HYTECH_RR_TTPMS_T5_ro_toS(_m->RR_TTPMS_T5_phys);
  _m->RR_TTPMS_T6_ro = (uint16_t) HYTECH_RR_TTPMS_T6_ro_toS(_m->RR_TTPMS_T6_phys);
  _m->RR_TTPMS_T7_ro = (uint16_t) HYTECH_RR_TTPMS_T7_ro_toS(_m->RR_TTPMS_T7_phys);
  _m->RR_TTPMS_T8_ro = (uint16_t) HYTECH_RR_TTPMS_T8_ro_toS(_m->RR_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_T5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_T6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_T7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_T8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_3_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_3_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_3_IDE;
  return RR_TTPMS_3_CANID;
}

#else

uint32_t Pack_RR_TTPMS_3_hytech(RR_TTPMS_3_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_3_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T5_ro = (uint16_t) HYTECH_RR_TTPMS_T5_ro_toS(_m->RR_TTPMS_T5_phys);
  _m->RR_TTPMS_T6_ro = (uint16_t) HYTECH_RR_TTPMS_T6_ro_toS(_m->RR_TTPMS_T6_phys);
  _m->RR_TTPMS_T7_ro = (uint16_t) HYTECH_RR_TTPMS_T7_ro_toS(_m->RR_TTPMS_T7_phys);
  _m->RR_TTPMS_T8_ro = (uint16_t) HYTECH_RR_TTPMS_T8_ro_toS(_m->RR_TTPMS_T8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_T5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_T5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_T6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_T6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_T7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_T7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_T8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_T8_ro & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_3_DLC;
  *_ide = (uint8_t) RR_TTPMS_3_IDE;
  return RR_TTPMS_3_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_T9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T9_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T9_ro_fromS(_m->RR_TTPMS_T9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T10_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T10_ro_fromS(_m->RR_TTPMS_T10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T11_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T11_ro_fromS(_m->RR_TTPMS_T11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T12_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T12_ro_fromS(_m->RR_TTPMS_T12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_4_hytech(&_m->mon1, RR_TTPMS_4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T9_ro = (uint16_t) HYTECH_RR_TTPMS_T9_ro_toS(_m->RR_TTPMS_T9_phys);
  _m->RR_TTPMS_T10_ro = (uint16_t) HYTECH_RR_TTPMS_T10_ro_toS(_m->RR_TTPMS_T10_phys);
  _m->RR_TTPMS_T11_ro = (uint16_t) HYTECH_RR_TTPMS_T11_ro_toS(_m->RR_TTPMS_T11_phys);
  _m->RR_TTPMS_T12_ro = (uint16_t) HYTECH_RR_TTPMS_T12_ro_toS(_m->RR_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_T9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_T10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_T11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_T12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_4_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_4_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_4_IDE;
  return RR_TTPMS_4_CANID;
}

#else

uint32_t Pack_RR_TTPMS_4_hytech(RR_TTPMS_4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T9_ro = (uint16_t) HYTECH_RR_TTPMS_T9_ro_toS(_m->RR_TTPMS_T9_phys);
  _m->RR_TTPMS_T10_ro = (uint16_t) HYTECH_RR_TTPMS_T10_ro_toS(_m->RR_TTPMS_T10_phys);
  _m->RR_TTPMS_T11_ro = (uint16_t) HYTECH_RR_TTPMS_T11_ro_toS(_m->RR_TTPMS_T11_phys);
  _m->RR_TTPMS_T12_ro = (uint16_t) HYTECH_RR_TTPMS_T12_ro_toS(_m->RR_TTPMS_T12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_T9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_T9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_T10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_T10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_T11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_T11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_T12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_T12_ro & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_4_DLC;
  *_ide = (uint8_t) RR_TTPMS_4_IDE;
  return RR_TTPMS_4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_T13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T13_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T13_ro_fromS(_m->RR_TTPMS_T13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T14_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T14_ro_fromS(_m->RR_TTPMS_T14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T15_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T15_ro_fromS(_m->RR_TTPMS_T15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_T16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T16_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T16_ro_fromS(_m->RR_TTPMS_T16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_5_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_5_hytech(&_m->mon1, RR_TTPMS_5_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_5_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_5_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T13_ro = (uint16_t) HYTECH_RR_TTPMS_T13_ro_toS(_m->RR_TTPMS_T13_phys);
  _m->RR_TTPMS_T14_ro = (uint16_t) HYTECH_RR_TTPMS_T14_ro_toS(_m->RR_TTPMS_T14_phys);
  _m->RR_TTPMS_T15_ro = (uint16_t) HYTECH_RR_TTPMS_T15_ro_toS(_m->RR_TTPMS_T15_phys);
  _m->RR_TTPMS_T16_ro = (uint16_t) HYTECH_RR_TTPMS_T16_ro_toS(_m->RR_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_T13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_T14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_T15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_T16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_5_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_5_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_5_IDE;
  return RR_TTPMS_5_CANID;
}

#else

uint32_t Pack_RR_TTPMS_5_hytech(RR_TTPMS_5_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_5_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T13_ro = (uint16_t) HYTECH_RR_TTPMS_T13_ro_toS(_m->RR_TTPMS_T13_phys);
  _m->RR_TTPMS_T14_ro = (uint16_t) HYTECH_RR_TTPMS_T14_ro_toS(_m->RR_TTPMS_T14_phys);
  _m->RR_TTPMS_T15_ro = (uint16_t) HYTECH_RR_TTPMS_T15_ro_toS(_m->RR_TTPMS_T15_phys);
  _m->RR_TTPMS_T16_ro = (uint16_t) HYTECH_RR_TTPMS_T16_ro_toS(_m->RR_TTPMS_T16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_T13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_T13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_T14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_T14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_T15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_T15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_T16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_T16_ro & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_5_DLC;
  *_ide = (uint8_t) RR_TTPMS_5_IDE;
  return RR_TTPMS_5_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->RR_TTPMS_TC = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
  _m->RR_TTPMS_RSSI = (int16_t) __ext_sig__(( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) ), 16);
  _m->RR_TTPMS_T_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T_phys = (sigfloat_t)(HYTECH_RR_TTPMS_T_ro_fromS(_m->RR_TTPMS_T_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->RR_TTPMS_NODE_ID = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < RR_TTPMS_6_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_RR_TTPMS_6_hytech(&_m->mon1, RR_TTPMS_6_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return RR_TTPMS_6_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_6_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T_ro = (uint16_t) HYTECH_RR_TTPMS_T_ro_toS(_m->RR_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->RR_TTPMS_TC >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->RR_TTPMS_TC & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->RR_TTPMS_RSSI >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->RR_TTPMS_RSSI & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->RR_TTPMS_T_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->RR_TTPMS_T_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->RR_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->RR_TTPMS_NODE_ID & (0xFFU)) );

  cframe->MsgId = (uint32_t) RR_TTPMS_6_CANID;
  cframe->DLC = (uint8_t) RR_TTPMS_6_DLC;
  cframe->IDE = (uint8_t) RR_TTPMS_6_IDE;
  return RR_TTPMS_6_CANID;
}

#else

uint32_t Pack_RR_TTPMS_6_hytech(RR_TTPMS_6_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(RR_TTPMS_6_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->RR_TTPMS_T_ro = (uint16_t) HYTECH_RR_TTPMS_T_ro_toS(_m->RR_TTPMS_T_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->RR_TTPMS_TC >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->RR_TTPMS_TC & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->RR_TTPMS_RSSI >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->RR_TTPMS_RSSI & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->RR_TTPMS_T_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->RR_TTPMS_T_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->RR_TTPMS_NODE_ID >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->RR_TTPMS_NODE_ID & (0xFFU)) );

  *_len = (uint8_t) RR_TTPMS_6_DLC;
  *_ide = (uint8_t) RR_TTPMS_6_IDE;
  return RR_TTPMS_6_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_phys = (sigfloat_t)(HYTECH_brake_temp_channel_1_ro_fromS(_m->brake_temp_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_2_phys = (sigfloat_t)(HYTECH_brake_temp_channel_2_ro_fromS(_m->brake_temp_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_3_phys = (sigfloat_t)(HYTECH_brake_temp_channel_3_ro_fromS(_m->brake_temp_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_4_phys = (sigfloat_t)(HYTECH_brake_temp_channel_4_ro_fromS(_m->brake_temp_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(&_m->mon1, FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_ro = (uint16_t) HYTECH_brake_temp_channel_1_ro_toS(_m->brake_temp_channel_1_phys);
  _m->brake_temp_channel_2_ro = (uint16_t) HYTECH_brake_temp_channel_2_ro_toS(_m->brake_temp_channel_2_phys);
  _m->brake_temp_channel_3_ro = (uint16_t) HYTECH_brake_temp_channel_3_ro_toS(_m->brake_temp_channel_3_phys);
  _m->brake_temp_channel_4_ro = (uint16_t) HYTECH_brake_temp_channel_4_ro_toS(_m->brake_temp_channel_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
  cframe->DLC = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC;
  cframe->IDE = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH1_CH4_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#else

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FL_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_ro = (uint16_t) HYTECH_brake_temp_channel_1_ro_toS(_m->brake_temp_channel_1_phys);
  _m->brake_temp_channel_2_ro = (uint16_t) HYTECH_brake_temp_channel_2_ro_toS(_m->brake_temp_channel_2_phys);
  _m->brake_temp_channel_3_ro = (uint16_t) HYTECH_brake_temp_channel_3_ro_toS(_m->brake_temp_channel_3_phys);
  _m->brake_temp_channel_4_ro = (uint16_t) HYTECH_brake_temp_channel_4_ro_toS(_m->brake_temp_channel_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_4_ro & (0xFFU)) );

  *_len = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH1_CH4_DLC;
  *_ide = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH1_CH4_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_phys = (sigfloat_t)(HYTECH_brake_temp_channel_5_ro_fromS(_m->brake_temp_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_6_phys = (sigfloat_t)(HYTECH_brake_temp_channel_6_ro_fromS(_m->brake_temp_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_7_phys = (sigfloat_t)(HYTECH_brake_temp_channel_7_ro_fromS(_m->brake_temp_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_8_phys = (sigfloat_t)(HYTECH_brake_temp_channel_8_ro_fromS(_m->brake_temp_channel_8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(&_m->mon1, FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_ro = (uint16_t) HYTECH_brake_temp_channel_5_ro_toS(_m->brake_temp_channel_5_phys);
  _m->brake_temp_channel_6_ro = (uint16_t) HYTECH_brake_temp_channel_6_ro_toS(_m->brake_temp_channel_6_phys);
  _m->brake_temp_channel_7_ro = (uint16_t) HYTECH_brake_temp_channel_7_ro_toS(_m->brake_temp_channel_7_phys);
  _m->brake_temp_channel_8_ro = (uint16_t) HYTECH_brake_temp_channel_8_ro_toS(_m->brake_temp_channel_8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
  cframe->DLC = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC;
  cframe->IDE = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH5_CH8_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#else

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FL_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_ro = (uint16_t) HYTECH_brake_temp_channel_5_ro_toS(_m->brake_temp_channel_5_phys);
  _m->brake_temp_channel_6_ro = (uint16_t) HYTECH_brake_temp_channel_6_ro_toS(_m->brake_temp_channel_6_phys);
  _m->brake_temp_channel_7_ro = (uint16_t) HYTECH_brake_temp_channel_7_ro_toS(_m->brake_temp_channel_7_phys);
  _m->brake_temp_channel_8_ro = (uint16_t) HYTECH_brake_temp_channel_8_ro_toS(_m->brake_temp_channel_8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_8_ro & (0xFFU)) );

  *_len = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH5_CH8_DLC;
  *_ide = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH5_CH8_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_phys = (sigfloat_t)(HYTECH_brake_temp_channel_9_ro_fromS(_m->brake_temp_channel_9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_10_phys = (sigfloat_t)(HYTECH_brake_temp_channel_10_ro_fromS(_m->brake_temp_channel_10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_11_phys = (sigfloat_t)(HYTECH_brake_temp_channel_11_ro_fromS(_m->brake_temp_channel_11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_12_phys = (sigfloat_t)(HYTECH_brake_temp_channel_12_ro_fromS(_m->brake_temp_channel_12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(&_m->mon1, FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_ro = (uint16_t) HYTECH_brake_temp_channel_9_ro_toS(_m->brake_temp_channel_9_phys);
  _m->brake_temp_channel_10_ro = (uint16_t) HYTECH_brake_temp_channel_10_ro_toS(_m->brake_temp_channel_10_phys);
  _m->brake_temp_channel_11_ro = (uint16_t) HYTECH_brake_temp_channel_11_ro_toS(_m->brake_temp_channel_11_phys);
  _m->brake_temp_channel_12_ro = (uint16_t) HYTECH_brake_temp_channel_12_ro_toS(_m->brake_temp_channel_12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
  cframe->DLC = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC;
  cframe->IDE = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH9_CH12_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#else

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FL_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_ro = (uint16_t) HYTECH_brake_temp_channel_9_ro_toS(_m->brake_temp_channel_9_phys);
  _m->brake_temp_channel_10_ro = (uint16_t) HYTECH_brake_temp_channel_10_ro_toS(_m->brake_temp_channel_10_phys);
  _m->brake_temp_channel_11_ro = (uint16_t) HYTECH_brake_temp_channel_11_ro_toS(_m->brake_temp_channel_11_phys);
  _m->brake_temp_channel_12_ro = (uint16_t) HYTECH_brake_temp_channel_12_ro_toS(_m->brake_temp_channel_12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_12_ro & (0xFFU)) );

  *_len = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH9_CH12_DLC;
  *_ide = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH9_CH12_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_phys = (sigfloat_t)(HYTECH_brake_temp_channel_13_ro_fromS(_m->brake_temp_channel_13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_14_phys = (sigfloat_t)(HYTECH_brake_temp_channel_14_ro_fromS(_m->brake_temp_channel_14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_15_phys = (sigfloat_t)(HYTECH_brake_temp_channel_15_ro_fromS(_m->brake_temp_channel_15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_16_phys = (sigfloat_t)(HYTECH_brake_temp_channel_16_ro_fromS(_m->brake_temp_channel_16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(&_m->mon1, FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_ro = (uint16_t) HYTECH_brake_temp_channel_13_ro_toS(_m->brake_temp_channel_13_phys);
  _m->brake_temp_channel_14_ro = (uint16_t) HYTECH_brake_temp_channel_14_ro_toS(_m->brake_temp_channel_14_phys);
  _m->brake_temp_channel_15_ro = (uint16_t) HYTECH_brake_temp_channel_15_ro_toS(_m->brake_temp_channel_15_phys);
  _m->brake_temp_channel_16_ro = (uint16_t) HYTECH_brake_temp_channel_16_ro_toS(_m->brake_temp_channel_16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
  cframe->DLC = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC;
  cframe->IDE = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH13_CH16_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#else

uint32_t Pack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FL_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_ro = (uint16_t) HYTECH_brake_temp_channel_13_ro_toS(_m->brake_temp_channel_13_phys);
  _m->brake_temp_channel_14_ro = (uint16_t) HYTECH_brake_temp_channel_14_ro_toS(_m->brake_temp_channel_14_phys);
  _m->brake_temp_channel_15_ro = (uint16_t) HYTECH_brake_temp_channel_15_ro_toS(_m->brake_temp_channel_15_phys);
  _m->brake_temp_channel_16_ro = (uint16_t) HYTECH_brake_temp_channel_16_ro_toS(_m->brake_temp_channel_16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_16_ro & (0xFFU)) );

  *_len = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH13_CH16_DLC;
  *_ide = (uint8_t) FL_BRAKE_ROTOR_TEMP_CH13_CH16_IDE;
  return FL_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_rotor_sensor_temp_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_phys = (sigfloat_t)(HYTECH_brake_rotor_sensor_temp_ro_fromS(_m->brake_rotor_sensor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FL_BRAKE_ROTOR_SENSOR_TEMP_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(&_m->mon1, FL_BRAKE_ROTOR_SENSOR_TEMP_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FL_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_SENSOR_TEMP_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_ro = (uint16_t) HYTECH_brake_rotor_sensor_temp_ro_toS(_m->brake_rotor_sensor_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_rotor_sensor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_rotor_sensor_temp_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FL_BRAKE_ROTOR_SENSOR_TEMP_CANID;
  cframe->DLC = (uint8_t) FL_BRAKE_ROTOR_SENSOR_TEMP_DLC;
  cframe->IDE = (uint8_t) FL_BRAKE_ROTOR_SENSOR_TEMP_IDE;
  return FL_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#else

uint32_t Pack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(FL_BRAKE_ROTOR_SENSOR_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FL_BRAKE_ROTOR_SENSOR_TEMP_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_ro = (uint16_t) HYTECH_brake_rotor_sensor_temp_ro_toS(_m->brake_rotor_sensor_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_rotor_sensor_temp_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_rotor_sensor_temp_ro & (0xFFU)) );

  *_len = (uint8_t) FL_BRAKE_ROTOR_SENSOR_TEMP_DLC;
  *_ide = (uint8_t) FL_BRAKE_ROTOR_SENSOR_TEMP_IDE;
  return FL_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_1_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_phys = (sigfloat_t)(HYTECH_brake_temp_channel_1_ro_fromS(_m->brake_temp_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_2_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_2_phys = (sigfloat_t)(HYTECH_brake_temp_channel_2_ro_fromS(_m->brake_temp_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_3_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_3_phys = (sigfloat_t)(HYTECH_brake_temp_channel_3_ro_fromS(_m->brake_temp_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_4_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_4_phys = (sigfloat_t)(HYTECH_brake_temp_channel_4_ro_fromS(_m->brake_temp_channel_4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(&_m->mon1, FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_ro = (uint16_t) HYTECH_brake_temp_channel_1_ro_toS(_m->brake_temp_channel_1_phys);
  _m->brake_temp_channel_2_ro = (uint16_t) HYTECH_brake_temp_channel_2_ro_toS(_m->brake_temp_channel_2_phys);
  _m->brake_temp_channel_3_ro = (uint16_t) HYTECH_brake_temp_channel_3_ro_toS(_m->brake_temp_channel_3_phys);
  _m->brake_temp_channel_4_ro = (uint16_t) HYTECH_brake_temp_channel_4_ro_toS(_m->brake_temp_channel_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_1_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_2_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_3_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_4_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
  cframe->DLC = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC;
  cframe->IDE = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH1_CH4_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#else

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(FR_BRAKE_ROTOR_TEMP_CH1_CH4_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_1_ro = (uint16_t) HYTECH_brake_temp_channel_1_ro_toS(_m->brake_temp_channel_1_phys);
  _m->brake_temp_channel_2_ro = (uint16_t) HYTECH_brake_temp_channel_2_ro_toS(_m->brake_temp_channel_2_phys);
  _m->brake_temp_channel_3_ro = (uint16_t) HYTECH_brake_temp_channel_3_ro_toS(_m->brake_temp_channel_3_phys);
  _m->brake_temp_channel_4_ro = (uint16_t) HYTECH_brake_temp_channel_4_ro_toS(_m->brake_temp_channel_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_1_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_1_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_2_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_2_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_3_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_3_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_4_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_4_ro & (0xFFU)) );

  *_len = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH1_CH4_DLC;
  *_ide = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH1_CH4_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH1_CH4_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_5_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_phys = (sigfloat_t)(HYTECH_brake_temp_channel_5_ro_fromS(_m->brake_temp_channel_5_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_6_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_6_phys = (sigfloat_t)(HYTECH_brake_temp_channel_6_ro_fromS(_m->brake_temp_channel_6_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_7_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_7_phys = (sigfloat_t)(HYTECH_brake_temp_channel_7_ro_fromS(_m->brake_temp_channel_7_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_8_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_8_phys = (sigfloat_t)(HYTECH_brake_temp_channel_8_ro_fromS(_m->brake_temp_channel_8_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(&_m->mon1, FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_ro = (uint16_t) HYTECH_brake_temp_channel_5_ro_toS(_m->brake_temp_channel_5_phys);
  _m->brake_temp_channel_6_ro = (uint16_t) HYTECH_brake_temp_channel_6_ro_toS(_m->brake_temp_channel_6_phys);
  _m->brake_temp_channel_7_ro = (uint16_t) HYTECH_brake_temp_channel_7_ro_toS(_m->brake_temp_channel_7_phys);
  _m->brake_temp_channel_8_ro = (uint16_t) HYTECH_brake_temp_channel_8_ro_toS(_m->brake_temp_channel_8_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_5_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_5_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_6_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_6_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_7_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_7_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_8_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_8_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
  cframe->DLC = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC;
  cframe->IDE = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH5_CH8_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#else

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(FR_BRAKE_ROTOR_TEMP_CH5_CH8_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_5_ro = (uint16_t) HYTECH_brake_temp_channel_5_ro_toS(_m->brake_temp_channel_5_phys);
  _m->brake_temp_channel_6_ro = (uint16_t) HYTECH_brake_temp_channel_6_ro_toS(_m->brake_temp_channel_6_phys);
  _m->brake_temp_channel_7_ro = (uint16_t) HYTECH_brake_temp_channel_7_ro_toS(_m->brake_temp_channel_7_phys);
  _m->brake_temp_channel_8_ro = (uint16_t) HYTECH_brake_temp_channel_8_ro_toS(_m->brake_temp_channel_8_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_5_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_5_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_6_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_6_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_7_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_7_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_8_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_8_ro & (0xFFU)) );

  *_len = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH5_CH8_DLC;
  *_ide = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH5_CH8_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH5_CH8_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_9_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_phys = (sigfloat_t)(HYTECH_brake_temp_channel_9_ro_fromS(_m->brake_temp_channel_9_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_10_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_10_phys = (sigfloat_t)(HYTECH_brake_temp_channel_10_ro_fromS(_m->brake_temp_channel_10_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_11_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_11_phys = (sigfloat_t)(HYTECH_brake_temp_channel_11_ro_fromS(_m->brake_temp_channel_11_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_12_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_12_phys = (sigfloat_t)(HYTECH_brake_temp_channel_12_ro_fromS(_m->brake_temp_channel_12_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(&_m->mon1, FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_ro = (uint16_t) HYTECH_brake_temp_channel_9_ro_toS(_m->brake_temp_channel_9_phys);
  _m->brake_temp_channel_10_ro = (uint16_t) HYTECH_brake_temp_channel_10_ro_toS(_m->brake_temp_channel_10_phys);
  _m->brake_temp_channel_11_ro = (uint16_t) HYTECH_brake_temp_channel_11_ro_toS(_m->brake_temp_channel_11_phys);
  _m->brake_temp_channel_12_ro = (uint16_t) HYTECH_brake_temp_channel_12_ro_toS(_m->brake_temp_channel_12_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_9_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_9_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_10_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_10_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_11_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_11_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_12_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_12_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
  cframe->DLC = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC;
  cframe->IDE = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH9_CH12_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#else

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(FR_BRAKE_ROTOR_TEMP_CH9_CH12_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_9_ro = (uint16_t) HYTECH_brake_temp_channel_9_ro_toS(_m->brake_temp_channel_9_phys);
  _m->brake_temp_channel_10_ro = (uint16_t) HYTECH_brake_temp_channel_10_ro_toS(_m->brake_temp_channel_10_phys);
  _m->brake_temp_channel_11_ro = (uint16_t) HYTECH_brake_temp_channel_11_ro_toS(_m->brake_temp_channel_11_phys);
  _m->brake_temp_channel_12_ro = (uint16_t) HYTECH_brake_temp_channel_12_ro_toS(_m->brake_temp_channel_12_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_9_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_9_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_10_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_10_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_11_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_11_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_12_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_12_ro & (0xFFU)) );

  *_len = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH9_CH12_DLC;
  *_ide = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH9_CH12_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH9_CH12_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_temp_channel_13_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_phys = (sigfloat_t)(HYTECH_brake_temp_channel_13_ro_fromS(_m->brake_temp_channel_13_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_14_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_14_phys = (sigfloat_t)(HYTECH_brake_temp_channel_14_ro_fromS(_m->brake_temp_channel_14_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_15_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_15_phys = (sigfloat_t)(HYTECH_brake_temp_channel_15_ro_fromS(_m->brake_temp_channel_15_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->brake_temp_channel_16_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_16_phys = (sigfloat_t)(HYTECH_brake_temp_channel_16_ro_fromS(_m->brake_temp_channel_16_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(&_m->mon1, FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_ro = (uint16_t) HYTECH_brake_temp_channel_13_ro_toS(_m->brake_temp_channel_13_phys);
  _m->brake_temp_channel_14_ro = (uint16_t) HYTECH_brake_temp_channel_14_ro_toS(_m->brake_temp_channel_14_phys);
  _m->brake_temp_channel_15_ro = (uint16_t) HYTECH_brake_temp_channel_15_ro_toS(_m->brake_temp_channel_15_phys);
  _m->brake_temp_channel_16_ro = (uint16_t) HYTECH_brake_temp_channel_16_ro_toS(_m->brake_temp_channel_16_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_temp_channel_13_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_temp_channel_13_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->brake_temp_channel_14_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->brake_temp_channel_14_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->brake_temp_channel_15_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->brake_temp_channel_15_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->brake_temp_channel_16_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->brake_temp_channel_16_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
  cframe->DLC = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC;
  cframe->IDE = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH13_CH16_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#else

uint32_t Pack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(FR_BRAKE_ROTOR_TEMP_CH13_CH16_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_temp_channel_13_ro = (uint16_t) HYTECH_brake_temp_channel_13_ro_toS(_m->brake_temp_channel_13_phys);
  _m->brake_temp_channel_14_ro = (uint16_t) HYTECH_brake_temp_channel_14_ro_toS(_m->brake_temp_channel_14_phys);
  _m->brake_temp_channel_15_ro = (uint16_t) HYTECH_brake_temp_channel_15_ro_toS(_m->brake_temp_channel_15_phys);
  _m->brake_temp_channel_16_ro = (uint16_t) HYTECH_brake_temp_channel_16_ro_toS(_m->brake_temp_channel_16_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_temp_channel_13_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_temp_channel_13_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->brake_temp_channel_14_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->brake_temp_channel_14_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->brake_temp_channel_15_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->brake_temp_channel_15_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->brake_temp_channel_16_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->brake_temp_channel_16_ro & (0xFFU)) );

  *_len = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH13_CH16_DLC;
  *_ide = (uint8_t) FR_BRAKE_ROTOR_TEMP_CH13_CH16_IDE;
  return FR_BRAKE_ROTOR_TEMP_CH13_CH16_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_rotor_sensor_temp_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_phys = (sigfloat_t)(HYTECH_brake_rotor_sensor_temp_ro_fromS(_m->brake_rotor_sensor_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FR_BRAKE_ROTOR_SENSOR_TEMP_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(&_m->mon1, FR_BRAKE_ROTOR_SENSOR_TEMP_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FR_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_SENSOR_TEMP_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_ro = (uint16_t) HYTECH_brake_rotor_sensor_temp_ro_toS(_m->brake_rotor_sensor_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->brake_rotor_sensor_temp_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->brake_rotor_sensor_temp_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) FR_BRAKE_ROTOR_SENSOR_TEMP_CANID;
  cframe->DLC = (uint8_t) FR_BRAKE_ROTOR_SENSOR_TEMP_DLC;
  cframe->IDE = (uint8_t) FR_BRAKE_ROTOR_SENSOR_TEMP_IDE;
  return FR_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#else

uint32_t Pack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(FR_BRAKE_ROTOR_SENSOR_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FR_BRAKE_ROTOR_SENSOR_TEMP_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->brake_rotor_sensor_temp_ro = (uint16_t) HYTECH_brake_rotor_sensor_temp_ro_toS(_m->brake_rotor_sensor_temp_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->brake_rotor_sensor_temp_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->brake_rotor_sensor_temp_ro & (0xFFU)) );

  *_len = (uint8_t) FR_BRAKE_ROTOR_SENSOR_TEMP_DLC;
  *_ide = (uint8_t) FR_BRAKE_ROTOR_SENSOR_TEMP_IDE;
  return FR_BRAKE_ROTOR_SENSOR_TEMP_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ACU_OK_hytech(ACU_OK_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->bms_ok = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->imd_ok = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );
  _m->latch_ok = (uint8_t) ( ((_d[0] >> 2U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < ACU_OK_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_ACU_OK_hytech(&_m->mon1, ACU_OK_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return ACU_OK_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_ACU_OK_hytech(ACU_OK_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ACU_OK_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->bms_ok & (0x01U)) | ((_m->imd_ok & (0x01U)) << 1U) | ((_m->latch_ok & (0x01U)) << 2U) );

  cframe->MsgId = (uint32_t) ACU_OK_CANID;
  cframe->DLC = (uint8_t) ACU_OK_DLC;
  cframe->IDE = (uint8_t) ACU_OK_IDE;
  return ACU_OK_CANID;
}

#else

uint32_t Pack_ACU_OK_hytech(ACU_OK_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ACU_OK_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->bms_ok & (0x01U)) | ((_m->imd_ok & (0x01U)) << 1U) | ((_m->latch_ok & (0x01U)) << 2U) );

  *_len = (uint8_t) ACU_OK_DLC;
  *_ide = (uint8_t) ACU_OK_IDE;
  return ACU_OK_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->telem_latency_millis = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->aux_latency_millis = (uint32_t) ( ((_d[7] & (0xFFU)) << 24U) | ((_d[6] & (0xFFU)) << 16U) | ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_LATENCY_TIMES_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_LATENCY_TIMES_hytech(&_m->mon1, DRIVEBRAIN_LATENCY_TIMES_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_LATENCY_TIMES_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_LATENCY_TIMES_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->telem_latency_millis & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->telem_latency_millis >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->telem_latency_millis >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->telem_latency_millis >> 24U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->aux_latency_millis & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->aux_latency_millis >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aux_latency_millis >> 16U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->aux_latency_millis >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_LATENCY_TIMES_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_LATENCY_TIMES_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_LATENCY_TIMES_IDE;
  return DRIVEBRAIN_LATENCY_TIMES_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_LATENCY_TIMES_hytech(DRIVEBRAIN_LATENCY_TIMES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_LATENCY_TIMES_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->telem_latency_millis & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->telem_latency_millis >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->telem_latency_millis >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->telem_latency_millis >> 24U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->aux_latency_millis & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->aux_latency_millis >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aux_latency_millis >> 16U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->aux_latency_millis >> 24U) & (0xFFU)) );

  *_len = (uint8_t) DRIVEBRAIN_LATENCY_TIMES_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_LATENCY_TIMES_IDE;
  return DRIVEBRAIN_LATENCY_TIMES_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->db_telem_timing_fault = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->db_aux_timing_fault = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DRIVEBRAIN_LATENCY_STATUSES_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DRIVEBRAIN_LATENCY_STATUSES_hytech(&_m->mon1, DRIVEBRAIN_LATENCY_STATUSES_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DRIVEBRAIN_LATENCY_STATUSES_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_LATENCY_STATUSES_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->db_telem_timing_fault & (0x01U)) | ((_m->db_aux_timing_fault & (0x01U)) << 1U) );

  cframe->MsgId = (uint32_t) DRIVEBRAIN_LATENCY_STATUSES_CANID;
  cframe->DLC = (uint8_t) DRIVEBRAIN_LATENCY_STATUSES_DLC;
  cframe->IDE = (uint8_t) DRIVEBRAIN_LATENCY_STATUSES_IDE;
  return DRIVEBRAIN_LATENCY_STATUSES_CANID;
}

#else

uint32_t Pack_DRIVEBRAIN_LATENCY_STATUSES_hytech(DRIVEBRAIN_LATENCY_STATUSES_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DRIVEBRAIN_LATENCY_STATUSES_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->db_telem_timing_fault & (0x01U)) | ((_m->db_aux_timing_fault & (0x01U)) << 1U) );

  *_len = (uint8_t) DRIVEBRAIN_LATENCY_STATUSES_DLC;
  *_ide = (uint8_t) DRIVEBRAIN_LATENCY_STATUSES_IDE;
  return DRIVEBRAIN_LATENCY_STATUSES_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->flow_rate = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FLOWMETER_DATA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FLOWMETER_DATA_hytech(&_m->mon1, FLOWMETER_DATA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FLOWMETER_DATA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FLOWMETER_DATA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->flow_rate & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->flow_rate >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->flow_rate >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->flow_rate >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) FLOWMETER_DATA_CANID;
  cframe->DLC = (uint8_t) FLOWMETER_DATA_DLC;
  cframe->IDE = (uint8_t) FLOWMETER_DATA_IDE;
  return FLOWMETER_DATA_CANID;
}

#else

uint32_t Pack_FLOWMETER_DATA_hytech(FLOWMETER_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FLOWMETER_DATA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->flow_rate & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->flow_rate >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->flow_rate >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->flow_rate >> 24U) & (0xFFU)) );

  *_len = (uint8_t) FLOWMETER_DATA_DLC;
  *_ide = (uint8_t) FLOWMETER_DATA_IDE;
  return FLOWMETER_DATA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->em_temp_sig_index = (uint8_t) ( (_d[0] & (0x07U)) );
  _m->em_num_sensors = (uint8_t) ( ((_d[0] >> 3U) & (0x1FU)) );
  _m->em_min_temp_ro = (uint8_t) ( (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_min_temp_phys = (sigfloat_t)(HYTECH_em_min_temp_ro_fromS(_m->em_min_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_max_temp_ro = (uint8_t) ( (_d[2] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_max_temp_phys = (sigfloat_t)(HYTECH_em_max_temp_ro_fromS(_m->em_max_temp_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_temp_0_ro = (uint8_t) ( (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_temp_0_phys = (sigfloat_t)(HYTECH_em_temp_0_ro_fromS(_m->em_temp_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_temp_1_ro = (uint8_t) ( (_d[4] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_temp_1_phys = (sigfloat_t)(HYTECH_em_temp_1_ro_fromS(_m->em_temp_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_temp_2_ro = (uint8_t) ( (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_temp_2_phys = (sigfloat_t)(HYTECH_em_temp_2_ro_fromS(_m->em_temp_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_temp_3_ro = (uint8_t) ( (_d[6] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_temp_3_phys = (sigfloat_t)(HYTECH_em_temp_3_ro_fromS(_m->em_temp_3_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->em_temp_4_ro = (uint8_t) ( (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->em_temp_4_phys = (sigfloat_t)(HYTECH_em_temp_4_ro_fromS(_m->em_temp_4_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < ENERGY_METER_TEMP_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_ENERGY_METER_TEMP_hytech(&_m->mon1, ENERGY_METER_TEMP_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return ENERGY_METER_TEMP_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_TEMP_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->em_min_temp_ro = (uint8_t) HYTECH_em_min_temp_ro_toS(_m->em_min_temp_phys);
  _m->em_max_temp_ro = (uint8_t) HYTECH_em_max_temp_ro_toS(_m->em_max_temp_phys);
  _m->em_temp_0_ro = (uint8_t) HYTECH_em_temp_0_ro_toS(_m->em_temp_0_phys);
  _m->em_temp_1_ro = (uint8_t) HYTECH_em_temp_1_ro_toS(_m->em_temp_1_phys);
  _m->em_temp_2_ro = (uint8_t) HYTECH_em_temp_2_ro_toS(_m->em_temp_2_phys);
  _m->em_temp_3_ro = (uint8_t) HYTECH_em_temp_3_ro_toS(_m->em_temp_3_phys);
  _m->em_temp_4_ro = (uint8_t) HYTECH_em_temp_4_ro_toS(_m->em_temp_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->em_temp_sig_index & (0x07U)) | ((_m->em_num_sensors & (0x1FU)) << 3U) );
  cframe->Data[1] |= (uint8_t) ( (_m->em_min_temp_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->em_max_temp_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->em_temp_0_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->em_temp_1_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->em_temp_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->em_temp_3_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->em_temp_4_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) ENERGY_METER_TEMP_CANID;
  cframe->DLC = (uint8_t) ENERGY_METER_TEMP_DLC;
  cframe->IDE = (uint8_t) ENERGY_METER_TEMP_IDE;
  return ENERGY_METER_TEMP_CANID;
}

#else

uint32_t Pack_ENERGY_METER_TEMP_hytech(ENERGY_METER_TEMP_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(ENERGY_METER_TEMP_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->em_min_temp_ro = (uint8_t) HYTECH_em_min_temp_ro_toS(_m->em_min_temp_phys);
  _m->em_max_temp_ro = (uint8_t) HYTECH_em_max_temp_ro_toS(_m->em_max_temp_phys);
  _m->em_temp_0_ro = (uint8_t) HYTECH_em_temp_0_ro_toS(_m->em_temp_0_phys);
  _m->em_temp_1_ro = (uint8_t) HYTECH_em_temp_1_ro_toS(_m->em_temp_1_phys);
  _m->em_temp_2_ro = (uint8_t) HYTECH_em_temp_2_ro_toS(_m->em_temp_2_phys);
  _m->em_temp_3_ro = (uint8_t) HYTECH_em_temp_3_ro_toS(_m->em_temp_3_phys);
  _m->em_temp_4_ro = (uint8_t) HYTECH_em_temp_4_ro_toS(_m->em_temp_4_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->em_temp_sig_index & (0x07U)) | ((_m->em_num_sensors & (0x1FU)) << 3U) );
  _d[1] |= (uint8_t) ( (_m->em_min_temp_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->em_max_temp_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->em_temp_0_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->em_temp_1_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->em_temp_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->em_temp_3_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->em_temp_4_ro & (0xFFU)) );

  *_len = (uint8_t) ENERGY_METER_TEMP_DLC;
  *_ide = (uint8_t) ENERGY_METER_TEMP_IDE;
  return ENERGY_METER_TEMP_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_0_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_phys = (sigfloat_t)(HYTECH_aero_channel_0_ro_fromS(_m->aero_channel_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_1_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_1_phys = (sigfloat_t)(HYTECH_aero_channel_1_ro_fromS(_m->aero_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_2_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_2_phys = (sigfloat_t)(HYTECH_aero_channel_2_ro_fromS(_m->aero_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_3_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_3_phys = (sigfloat_t)(HYTECH_aero_channel_3_ro_fromS(_m->aero_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_21_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_21_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_21_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_21_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_21_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_21_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_21_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_21_IDE;
  return AERO_PRESSURE_SENSOR_21_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_21_hytech(AERO_PRESSURE_SENSOR_21_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_21_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_21_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_21_IDE;
  return AERO_PRESSURE_SENSOR_21_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_0_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_phys = (sigfloat_t)(HYTECH_aero_channel_0_ro_fromS(_m->aero_channel_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_1_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_1_phys = (sigfloat_t)(HYTECH_aero_channel_1_ro_fromS(_m->aero_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_2_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_2_phys = (sigfloat_t)(HYTECH_aero_channel_2_ro_fromS(_m->aero_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_3_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_3_phys = (sigfloat_t)(HYTECH_aero_channel_3_ro_fromS(_m->aero_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_31_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_31_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_31_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_31_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_31_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_31_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_31_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_31_IDE;
  return AERO_PRESSURE_SENSOR_31_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_31_hytech(AERO_PRESSURE_SENSOR_31_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_31_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_31_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_31_IDE;
  return AERO_PRESSURE_SENSOR_31_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->aero_channel_0_ro = (uint16_t) ( ((_d[0] & (0xFFU)) << 8U) | (_d[1] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_phys = (sigfloat_t)(HYTECH_aero_channel_0_ro_fromS(_m->aero_channel_0_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_1_ro = (uint16_t) ( ((_d[2] & (0xFFU)) << 8U) | (_d[3] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_1_phys = (sigfloat_t)(HYTECH_aero_channel_1_ro_fromS(_m->aero_channel_1_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_2_ro = (uint16_t) ( ((_d[4] & (0xFFU)) << 8U) | (_d[5] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_2_phys = (sigfloat_t)(HYTECH_aero_channel_2_ro_fromS(_m->aero_channel_2_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->aero_channel_3_ro = (uint16_t) ( ((_d[6] & (0xFFU)) << 8U) | (_d[7] & (0xFFU)) );
#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_3_phys = (sigfloat_t)(HYTECH_aero_channel_3_ro_fromS(_m->aero_channel_3_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < AERO_PRESSURE_SENSOR_41_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_AERO_PRESSURE_SENSOR_41_hytech(&_m->mon1, AERO_PRESSURE_SENSOR_41_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return AERO_PRESSURE_SENSOR_41_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_41_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  cframe->MsgId = (uint32_t) AERO_PRESSURE_SENSOR_41_CANID;
  cframe->DLC = (uint8_t) AERO_PRESSURE_SENSOR_41_DLC;
  cframe->IDE = (uint8_t) AERO_PRESSURE_SENSOR_41_IDE;
  return AERO_PRESSURE_SENSOR_41_CANID;
}

#else

uint32_t Pack_AERO_PRESSURE_SENSOR_41_hytech(AERO_PRESSURE_SENSOR_41_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(AERO_PRESSURE_SENSOR_41_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->aero_channel_0_ro = (uint16_t) HYTECH_aero_channel_0_ro_toS(_m->aero_channel_0_phys);
  _m->aero_channel_1_ro = (uint16_t) HYTECH_aero_channel_1_ro_toS(_m->aero_channel_1_phys);
  _m->aero_channel_2_ro = (uint16_t) HYTECH_aero_channel_2_ro_toS(_m->aero_channel_2_phys);
  _m->aero_channel_3_ro = (uint16_t) HYTECH_aero_channel_3_ro_toS(_m->aero_channel_3_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( ((_m->aero_channel_0_ro >> 8U) & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->aero_channel_0_ro & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->aero_channel_1_ro >> 8U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->aero_channel_1_ro & (0xFFU)) );
  _d[4] |= (uint8_t) ( ((_m->aero_channel_2_ro >> 8U) & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->aero_channel_2_ro & (0xFFU)) );
  _d[6] |= (uint8_t) ( ((_m->aero_channel_3_ro >> 8U) & (0xFFU)) );
  _d[7] |= (uint8_t) ( (_m->aero_channel_3_ro & (0xFFU)) );

  *_len = (uint8_t) AERO_PRESSURE_SENSOR_41_DLC;
  *_ide = (uint8_t) AERO_PRESSURE_SENSOR_41_IDE;
  return AERO_PRESSURE_SENSOR_41_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->brake_pressure_1 = (uint16_t) ( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->brake_pressure_2 = (uint16_t) ( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < BRAKE_PRESSURE_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_BRAKE_PRESSURE_hytech(&_m->mon1, BRAKE_PRESSURE_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return BRAKE_PRESSURE_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BRAKE_PRESSURE_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->brake_pressure_1 & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->brake_pressure_1 >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->brake_pressure_2 & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->brake_pressure_2 >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) BRAKE_PRESSURE_CANID;
  cframe->DLC = (uint8_t) BRAKE_PRESSURE_DLC;
  cframe->IDE = (uint8_t) BRAKE_PRESSURE_IDE;
  return BRAKE_PRESSURE_CANID;
}

#else

uint32_t Pack_BRAKE_PRESSURE_hytech(BRAKE_PRESSURE_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(BRAKE_PRESSURE_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->brake_pressure_1 & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->brake_pressure_1 >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->brake_pressure_2 & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->brake_pressure_2 >> 8U) & (0xFFU)) );

  *_len = (uint8_t) BRAKE_PRESSURE_DLC;
  *_ide = (uint8_t) BRAKE_PRESSURE_IDE;
  return BRAKE_PRESSURE_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_VEHM_BETA_hytech(VEHM_BETA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->vehm_beta_deg_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_beta_deg_phys = (sigfloat_t)(HYTECH_vehm_beta_deg_ro_fromS(_m->vehm_beta_deg_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < VEHM_BETA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_VEHM_BETA_hytech(&_m->mon1, VEHM_BETA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return VEHM_BETA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_VEHM_BETA_hytech(VEHM_BETA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(VEHM_BETA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_beta_deg_ro = (int16_t) HYTECH_vehm_beta_deg_ro_toS(_m->vehm_beta_deg_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->vehm_beta_deg_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->vehm_beta_deg_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) VEHM_BETA_CANID;
  cframe->DLC = (uint8_t) VEHM_BETA_DLC;
  cframe->IDE = (uint8_t) VEHM_BETA_IDE;
  return VEHM_BETA_CANID;
}

#else

uint32_t Pack_VEHM_BETA_hytech(VEHM_BETA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(VEHM_BETA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_beta_deg_ro = (int16_t) HYTECH_vehm_beta_deg_ro_toS(_m->vehm_beta_deg_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->vehm_beta_deg_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->vehm_beta_deg_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) VEHM_BETA_DLC;
  *_ide = (uint8_t) VEHM_BETA_IDE;
  return VEHM_BETA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->dash_buzzer_flag = (uint8_t) ( (_d[0] & (0x01U)) );
  _m->in_pedal_calibration_state = (uint8_t) ( ((_d[0] >> 1U) & (0x01U)) );
  _m->in_steering_calibration_state = (uint8_t) ( ((_d[0] >> 2U) & (0x01U)) );
  _m->torque_limit_enum_value = (uint8_t) ( ((_d[1] & (0x07U)) << 5U) | ((_d[0] >> 3U) & (0x1FU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < DASHBOARD_BUZZER_CONTROL_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_DASHBOARD_BUZZER_CONTROL_hytech(&_m->mon1, DASHBOARD_BUZZER_CONTROL_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return DASHBOARD_BUZZER_CONTROL_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DASHBOARD_BUZZER_CONTROL_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->dash_buzzer_flag & (0x01U)) | ((_m->in_pedal_calibration_state & (0x01U)) << 1U) | ((_m->in_steering_calibration_state & (0x01U)) << 2U) | ((_m->torque_limit_enum_value & (0x1FU)) << 3U) );
  cframe->Data[1] |= (uint8_t) ( ((_m->torque_limit_enum_value >> 5U) & (0x07U)) );

  cframe->MsgId = (uint32_t) DASHBOARD_BUZZER_CONTROL_CANID;
  cframe->DLC = (uint8_t) DASHBOARD_BUZZER_CONTROL_DLC;
  cframe->IDE = (uint8_t) DASHBOARD_BUZZER_CONTROL_IDE;
  return DASHBOARD_BUZZER_CONTROL_CANID;
}

#else

uint32_t Pack_DASHBOARD_BUZZER_CONTROL_hytech(DASHBOARD_BUZZER_CONTROL_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(DASHBOARD_BUZZER_CONTROL_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->dash_buzzer_flag & (0x01U)) | ((_m->in_pedal_calibration_state & (0x01U)) << 1U) | ((_m->in_steering_calibration_state & (0x01U)) << 2U) | ((_m->torque_limit_enum_value & (0x1FU)) << 3U) );
  _d[1] |= (uint8_t) ( ((_m->torque_limit_enum_value >> 5U) & (0x07U)) );

  *_len = (uint8_t) DASHBOARD_BUZZER_CONTROL_DLC;
  *_ide = (uint8_t) DASHBOARD_BUZZER_CONTROL_IDE;
  return DASHBOARD_BUZZER_CONTROL_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_FD_TEST_hytech(FD_TEST_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->fd_test_counter = (uint32_t) ( ((_d[3] & (0xFFU)) << 24U) | ((_d[2] & (0xFFU)) << 16U) | ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) );
  _m->fd_test_byte8 = (uint32_t) ( ((_d[11] & (0xFFU)) << 24U) | ((_d[10] & (0xFFU)) << 16U) | ((_d[9] & (0xFFU)) << 8U) | (_d[8] & (0xFFU)) );
  _m->fd_test_byte32 = (uint32_t) ( ((_d[35] & (0xFFU)) << 24U) | ((_d[34] & (0xFFU)) << 16U) | ((_d[33] & (0xFFU)) << 8U) | (_d[32] & (0xFFU)) );
  _m->fd_test_byte60 = (uint32_t) ( ((_d[63] & (0xFFU)) << 24U) | ((_d[62] & (0xFFU)) << 16U) | ((_d[61] & (0xFFU)) << 8U) | (_d[60] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < FD_TEST_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_FD_TEST_hytech(&_m->mon1, FD_TEST_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return FD_TEST_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_FD_TEST_hytech(FD_TEST_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FD_TEST_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->fd_test_counter & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->fd_test_counter >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( ((_m->fd_test_counter >> 16U) & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->fd_test_counter >> 24U) & (0xFFU)) );
  cframe->Data[8] |= (uint8_t) ( (_m->fd_test_byte8 & (0xFFU)) );
  cframe->Data[9] |= (uint8_t) ( ((_m->fd_test_byte8 >> 8U) & (0xFFU)) );
  cframe->Data[10] |= (uint8_t) ( ((_m->fd_test_byte8 >> 16U) & (0xFFU)) );
  cframe->Data[11] |= (uint8_t) ( ((_m->fd_test_byte8 >> 24U) & (0xFFU)) );
  cframe->Data[32] |= (uint8_t) ( (_m->fd_test_byte32 & (0xFFU)) );
  cframe->Data[33] |= (uint8_t) ( ((_m->fd_test_byte32 >> 8U) & (0xFFU)) );
  cframe->Data[34] |= (uint8_t) ( ((_m->fd_test_byte32 >> 16U) & (0xFFU)) );
  cframe->Data[35] |= (uint8_t) ( ((_m->fd_test_byte32 >> 24U) & (0xFFU)) );
  cframe->Data[60] |= (uint8_t) ( (_m->fd_test_byte60 & (0xFFU)) );
  cframe->Data[61] |= (uint8_t) ( ((_m->fd_test_byte60 >> 8U) & (0xFFU)) );
  cframe->Data[62] |= (uint8_t) ( ((_m->fd_test_byte60 >> 16U) & (0xFFU)) );
  cframe->Data[63] |= (uint8_t) ( ((_m->fd_test_byte60 >> 24U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) FD_TEST_CANID;
  cframe->DLC = (uint8_t) FD_TEST_DLC;
  cframe->IDE = (uint8_t) FD_TEST_IDE;
  return FD_TEST_CANID;
}

#else

uint32_t Pack_FD_TEST_hytech(FD_TEST_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(FD_TEST_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->fd_test_counter & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->fd_test_counter >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( ((_m->fd_test_counter >> 16U) & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->fd_test_counter >> 24U) & (0xFFU)) );
  _d[8] |= (uint8_t) ( (_m->fd_test_byte8 & (0xFFU)) );
  _d[9] |= (uint8_t) ( ((_m->fd_test_byte8 >> 8U) & (0xFFU)) );
  _d[10] |= (uint8_t) ( ((_m->fd_test_byte8 >> 16U) & (0xFFU)) );
  _d[11] |= (uint8_t) ( ((_m->fd_test_byte8 >> 24U) & (0xFFU)) );
  _d[32] |= (uint8_t) ( (_m->fd_test_byte32 & (0xFFU)) );
  _d[33] |= (uint8_t) ( ((_m->fd_test_byte32 >> 8U) & (0xFFU)) );
  _d[34] |= (uint8_t) ( ((_m->fd_test_byte32 >> 16U) & (0xFFU)) );
  _d[35] |= (uint8_t) ( ((_m->fd_test_byte32 >> 24U) & (0xFFU)) );
  _d[60] |= (uint8_t) ( (_m->fd_test_byte60 & (0xFFU)) );
  _d[61] |= (uint8_t) ( ((_m->fd_test_byte60 >> 8U) & (0xFFU)) );
  _d[62] |= (uint8_t) ( ((_m->fd_test_byte60 >> 16U) & (0xFFU)) );
  _d[63] |= (uint8_t) ( ((_m->fd_test_byte60 >> 24U) & (0xFFU)) );

  *_len = (uint8_t) FD_TEST_DLC;
  *_ide = (uint8_t) FD_TEST_IDE;
  return FD_TEST_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->vehm_alpha_deg_fl_ro = (int16_t) __ext_sig__(( ((_d[1] & (0xFFU)) << 8U) | (_d[0] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_fl_phys = (sigfloat_t)(HYTECH_vehm_alpha_deg_fl_ro_fromS(_m->vehm_alpha_deg_fl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->vehm_alpha_deg_fr_ro = (int16_t) __ext_sig__(( ((_d[3] & (0xFFU)) << 8U) | (_d[2] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_fr_phys = (sigfloat_t)(HYTECH_vehm_alpha_deg_fr_ro_fromS(_m->vehm_alpha_deg_fr_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->vehm_alpha_deg_rl_ro = (int16_t) __ext_sig__(( ((_d[5] & (0xFFU)) << 8U) | (_d[4] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_rl_phys = (sigfloat_t)(HYTECH_vehm_alpha_deg_rl_ro_fromS(_m->vehm_alpha_deg_rl_ro));
#endif // HYTECH_USE_SIGFLOAT

  _m->vehm_alpha_deg_rr_ro = (int16_t) __ext_sig__(( ((_d[7] & (0xFFU)) << 8U) | (_d[6] & (0xFFU)) ), 16);
#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_rr_phys = (sigfloat_t)(HYTECH_vehm_alpha_deg_rr_ro_fromS(_m->vehm_alpha_deg_rr_ro));
#endif // HYTECH_USE_SIGFLOAT

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < VEHM_ALPHA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_VEHM_ALPHA_hytech(&_m->mon1, VEHM_ALPHA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return VEHM_ALPHA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(VEHM_ALPHA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_fl_ro = (int16_t) HYTECH_vehm_alpha_deg_fl_ro_toS(_m->vehm_alpha_deg_fl_phys);
  _m->vehm_alpha_deg_fr_ro = (int16_t) HYTECH_vehm_alpha_deg_fr_ro_toS(_m->vehm_alpha_deg_fr_phys);
  _m->vehm_alpha_deg_rl_ro = (int16_t) HYTECH_vehm_alpha_deg_rl_ro_toS(_m->vehm_alpha_deg_rl_phys);
  _m->vehm_alpha_deg_rr_ro = (int16_t) HYTECH_vehm_alpha_deg_rr_ro_toS(_m->vehm_alpha_deg_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  cframe->Data[0] |= (uint8_t) ( (_m->vehm_alpha_deg_fl_ro & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( ((_m->vehm_alpha_deg_fl_ro >> 8U) & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->vehm_alpha_deg_fr_ro & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( ((_m->vehm_alpha_deg_fr_ro >> 8U) & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->vehm_alpha_deg_rl_ro & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( ((_m->vehm_alpha_deg_rl_ro >> 8U) & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->vehm_alpha_deg_rr_ro & (0xFFU)) );
  cframe->Data[7] |= (uint8_t) ( ((_m->vehm_alpha_deg_rr_ro >> 8U) & (0xFFU)) );

  cframe->MsgId = (uint32_t) VEHM_ALPHA_CANID;
  cframe->DLC = (uint8_t) VEHM_ALPHA_DLC;
  cframe->IDE = (uint8_t) VEHM_ALPHA_IDE;
  return VEHM_ALPHA_CANID;
}

#else

uint32_t Pack_VEHM_ALPHA_hytech(VEHM_ALPHA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(VEHM_ALPHA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

#ifdef HYTECH_USE_SIGFLOAT
  _m->vehm_alpha_deg_fl_ro = (int16_t) HYTECH_vehm_alpha_deg_fl_ro_toS(_m->vehm_alpha_deg_fl_phys);
  _m->vehm_alpha_deg_fr_ro = (int16_t) HYTECH_vehm_alpha_deg_fr_ro_toS(_m->vehm_alpha_deg_fr_phys);
  _m->vehm_alpha_deg_rl_ro = (int16_t) HYTECH_vehm_alpha_deg_rl_ro_toS(_m->vehm_alpha_deg_rl_phys);
  _m->vehm_alpha_deg_rr_ro = (int16_t) HYTECH_vehm_alpha_deg_rr_ro_toS(_m->vehm_alpha_deg_rr_phys);
#endif // HYTECH_USE_SIGFLOAT

  _d[0] |= (uint8_t) ( (_m->vehm_alpha_deg_fl_ro & (0xFFU)) );
  _d[1] |= (uint8_t) ( ((_m->vehm_alpha_deg_fl_ro >> 8U) & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->vehm_alpha_deg_fr_ro & (0xFFU)) );
  _d[3] |= (uint8_t) ( ((_m->vehm_alpha_deg_fr_ro >> 8U) & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->vehm_alpha_deg_rl_ro & (0xFFU)) );
  _d[5] |= (uint8_t) ( ((_m->vehm_alpha_deg_rl_ro >> 8U) & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->vehm_alpha_deg_rr_ro & (0xFFU)) );
  _d[7] |= (uint8_t) ( ((_m->vehm_alpha_deg_rr_ro >> 8U) & (0xFFU)) );

  *_len = (uint8_t) VEHM_ALPHA_DLC;
  *_ide = (uint8_t) VEHM_ALPHA_IDE;
  return VEHM_ALPHA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->max_charging_voltage_high = (uint8_t) ( (_d[0] & (0xFFU)) );
  _m->max_charging_voltage_low = (uint8_t) ( (_d[1] & (0xFFU)) );
  _m->max_charging_current_high = (uint8_t) ( (_d[2] & (0xFFU)) );
  _m->max_charging_current_low = (uint8_t) ( (_d[3] & (0xFFU)) );
  _m->control = (uint8_t) ( (_d[4] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < CHARGER_CONTROL_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_CHARGER_CONTROL_hytech(&_m->mon1, CHARGER_CONTROL_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return CHARGER_CONTROL_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CHARGER_CONTROL_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->max_charging_voltage_high & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->max_charging_voltage_low & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->max_charging_current_high & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->max_charging_current_low & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->control & (0xFFU)) );

  cframe->MsgId = (uint32_t) CHARGER_CONTROL_CANID;
  cframe->DLC = (uint8_t) CHARGER_CONTROL_DLC;
  cframe->IDE = (uint8_t) CHARGER_CONTROL_IDE;
  return CHARGER_CONTROL_CANID;
}

#else

uint32_t Pack_CHARGER_CONTROL_hytech(CHARGER_CONTROL_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CHARGER_CONTROL_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->max_charging_voltage_high & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->max_charging_voltage_low & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->max_charging_current_high & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->max_charging_current_low & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->control & (0xFFU)) );

  *_len = (uint8_t) CHARGER_CONTROL_DLC;
  *_ide = (uint8_t) CHARGER_CONTROL_IDE;
  return CHARGER_CONTROL_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

uint32_t Unpack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  (void)dlc_;
  _m->output_dc_voltage_high = (uint8_t) ( (_d[0] & (0xFFU)) );
  _m->output_dc_voltage_low = (uint8_t) ( (_d[1] & (0xFFU)) );
  _m->output_current_high = (uint8_t) ( (_d[2] & (0xFFU)) );
  _m->output_current_low = (uint8_t) ( (_d[3] & (0xFFU)) );
  _m->flags = (uint8_t) ( (_d[4] & (0xFFU)) );
  _m->input_ac_voltage_high = (uint8_t) ( (_d[5] & (0xFFU)) );
  _m->input_ac_voltage_low = (uint8_t) ( (_d[6] & (0xFFU)) );

#ifdef HYTECH_USE_DIAG_MONITORS
  _m->mon1.dlc_error = (dlc_ < CHARGER_DATA_DLC);
  _m->mon1.last_cycle = GetSystemTick();
  _m->mon1.frame_cnt++;

  FMon_CHARGER_DATA_hytech(&_m->mon1, CHARGER_DATA_CANID);
#endif // HYTECH_USE_DIAG_MONITORS

  return CHARGER_DATA_CANID;
}

#ifdef HYTECH_USE_CANSTRUCT

uint32_t Pack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, __CoderDbcCanFrame_t__* cframe)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CHARGER_DATA_DLC); cframe->Data[i++] = HYTECH_INITIAL_BYTE_VALUE);

  cframe->Data[0] |= (uint8_t) ( (_m->output_dc_voltage_high & (0xFFU)) );
  cframe->Data[1] |= (uint8_t) ( (_m->output_dc_voltage_low & (0xFFU)) );
  cframe->Data[2] |= (uint8_t) ( (_m->output_current_high & (0xFFU)) );
  cframe->Data[3] |= (uint8_t) ( (_m->output_current_low & (0xFFU)) );
  cframe->Data[4] |= (uint8_t) ( (_m->flags & (0xFFU)) );
  cframe->Data[5] |= (uint8_t) ( (_m->input_ac_voltage_high & (0xFFU)) );
  cframe->Data[6] |= (uint8_t) ( (_m->input_ac_voltage_low & (0xFFU)) );

  cframe->MsgId = (uint32_t) CHARGER_DATA_CANID;
  cframe->DLC = (uint8_t) CHARGER_DATA_DLC;
  cframe->IDE = (uint8_t) CHARGER_DATA_IDE;
  return CHARGER_DATA_CANID;
}

#else

uint32_t Pack_CHARGER_DATA_hytech(CHARGER_DATA_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0u; i < HYTECH_VALIDATE_DLC(CHARGER_DATA_DLC); _d[i++] = HYTECH_INITIAL_BYTE_VALUE);

  _d[0] |= (uint8_t) ( (_m->output_dc_voltage_high & (0xFFU)) );
  _d[1] |= (uint8_t) ( (_m->output_dc_voltage_low & (0xFFU)) );
  _d[2] |= (uint8_t) ( (_m->output_current_high & (0xFFU)) );
  _d[3] |= (uint8_t) ( (_m->output_current_low & (0xFFU)) );
  _d[4] |= (uint8_t) ( (_m->flags & (0xFFU)) );
  _d[5] |= (uint8_t) ( (_m->input_ac_voltage_high & (0xFFU)) );
  _d[6] |= (uint8_t) ( (_m->input_ac_voltage_low & (0xFFU)) );

  *_len = (uint8_t) CHARGER_DATA_DLC;
  *_ide = (uint8_t) CHARGER_DATA_IDE;
  return CHARGER_DATA_CANID;
}

#endif // HYTECH_USE_CANSTRUCT

