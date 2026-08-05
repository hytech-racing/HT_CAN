// Generator version : v3.1
// DBC filename      : hytech_fd.dbc
#include "hytech-binutil.h"

// DBC file version
#if (VER_HYTECH_MAJ != (6U)) || (VER_HYTECH_MIN != (0U))
#error The HYTECH binutil source file has inconsistency with core dbc lib!
#endif

#ifdef __DEF_HYTECH__

hytech_rx_t hytech_rx;

#endif // __DEF_HYTECH__

uint32_t hytech_Receive(hytech_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if ((_id >= 0x70U) && (_id < 0x330U)) {
  if ((_id >= 0x70U) && (_id < 0xD6U)) {
   if ((_id >= 0x70U) && (_id < 0x84U)) {
    if ((_id >= 0x70U) && (_id < 0x77U)) {
     if ((_id >= 0x70U) && (_id < 0x73U)) {
      if (_id == 0x70U) {
       recid = Unpack_INV3_STATUS_hytech(&(_m->INV3_STATUS), _d, dlc_);
      } else {
       if (_id == 0x71U) {
        recid = Unpack_INV3_TEMPS_hytech(&(_m->INV3_TEMPS), _d, dlc_);
       } else if (_id == 0x72U) {
        recid = Unpack_INV3_DYNAMICS_hytech(&(_m->INV3_DYNAMICS), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x73U) && (_id < 0x75U)) {
       if (_id == 0x73U) {
        recid = Unpack_INV3_POWER_hytech(&(_m->INV3_POWER), _d, dlc_);
       } else if (_id == 0x74U) {
        recid = Unpack_INV3_FEEDBACK_hytech(&(_m->INV3_FEEDBACK), _d, dlc_);
       }
      } else {
       if (_id == 0x75U) {
        recid = Unpack_INV4_STATUS_hytech(&(_m->INV4_STATUS), _d, dlc_);
       } else if (_id == 0x76U) {
        recid = Unpack_INV4_TEMPS_hytech(&(_m->INV4_TEMPS), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x77U) && (_id < 0x80U)) {
      if (_id == 0x77U) {
       recid = Unpack_INV4_DYNAMICS_hytech(&(_m->INV4_DYNAMICS), _d, dlc_);
      } else {
       if (_id == 0x78U) {
        recid = Unpack_INV4_POWER_hytech(&(_m->INV4_POWER), _d, dlc_);
       } else if (_id == 0x79U) {
        recid = Unpack_INV4_FEEDBACK_hytech(&(_m->INV4_FEEDBACK), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x80U) && (_id < 0x82U)) {
       if (_id == 0x80U) {
        recid = Unpack_INV1_STATUS_hytech(&(_m->INV1_STATUS), _d, dlc_);
       } else if (_id == 0x81U) {
        recid = Unpack_INV1_TEMPS_hytech(&(_m->INV1_TEMPS), _d, dlc_);
       }
      } else {
       if (_id == 0x82U) {
        recid = Unpack_INV1_DYNAMICS_hytech(&(_m->INV1_DYNAMICS), _d, dlc_);
       } else if (_id == 0x83U) {
        recid = Unpack_INV1_POWER_hytech(&(_m->INV1_POWER), _d, dlc_);
       }
      }
     }
    }
   } else {
    if ((_id >= 0x84U) && (_id < 0x91U)) {
     if ((_id >= 0x84U) && (_id < 0x87U)) {
      if (_id == 0x84U) {
       recid = Unpack_INV1_FEEDBACK_hytech(&(_m->INV1_FEEDBACK), _d, dlc_);
      } else {
       if (_id == 0x85U) {
        recid = Unpack_INV2_STATUS_hytech(&(_m->INV2_STATUS), _d, dlc_);
       } else if (_id == 0x86U) {
        recid = Unpack_INV2_TEMPS_hytech(&(_m->INV2_TEMPS), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x87U) && (_id < 0x89U)) {
       if (_id == 0x87U) {
        recid = Unpack_INV2_DYNAMICS_hytech(&(_m->INV2_DYNAMICS), _d, dlc_);
       } else if (_id == 0x88U) {
        recid = Unpack_INV2_POWER_hytech(&(_m->INV2_POWER), _d, dlc_);
       }
      } else {
       if (_id == 0x89U) {
        recid = Unpack_INV2_FEEDBACK_hytech(&(_m->INV2_FEEDBACK), _d, dlc_);
       } else if (_id == 0x90U) {
        recid = Unpack_INV3_CONTROL_WORD_hytech(&(_m->INV3_CONTROL_WORD), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x91U) && (_id < 0x97U)) {
      if (_id == 0x91U) {
       recid = Unpack_INV4_CONTROL_WORD_hytech(&(_m->INV4_CONTROL_WORD), _d, dlc_);
      } else {
       if (_id == 0x92U) {
        recid = Unpack_INV1_CONTROL_WORD_hytech(&(_m->INV1_CONTROL_WORD), _d, dlc_);
       } else if (_id == 0x93U) {
        recid = Unpack_INV2_CONTROL_WORD_hytech(&(_m->INV2_CONTROL_WORD), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x97U) && (_id < 0x99U)) {
       if (_id == 0x97U) {
        recid = Unpack_INV3_CONTROL_INPUT_hytech(&(_m->INV3_CONTROL_INPUT), _d, dlc_);
       } else if (_id == 0x98U) {
        recid = Unpack_INV4_CONTROL_INPUT_hytech(&(_m->INV4_CONTROL_INPUT), _d, dlc_);
       }
      } else {
       if (_id == 0x99U) {
        recid = Unpack_INV1_CONTROL_INPUT_hytech(&(_m->INV1_CONTROL_INPUT), _d, dlc_);
       } else if (_id == 0xC0U) {
        recid = Unpack_PEDALS_SYSTEM_DATA_hytech(&(_m->PEDALS_SYSTEM_DATA), _d, dlc_);
       }
      }
     }
    }
   }
  } else {
   if ((_id >= 0xD6U) && (_id < 0xF5U)) {
    if ((_id >= 0xD6U) && (_id < 0xE4U)) {
     if ((_id >= 0xD6U) && (_id < 0xD9U)) {
      if (_id == 0xD6U) {
       recid = Unpack_BMS_BOARD_DETAILED_TEMPS_hytech(&(_m->BMS_BOARD_DETAILED_TEMPS), _d, dlc_);
      } else {
       if (_id == 0xD7U) {
        recid = Unpack_BMS_VOLTAGES_hytech(&(_m->BMS_VOLTAGES), _d, dlc_);
       } else if (_id == 0xD8U) {
        recid = Unpack_BMS_DETAILED_VOLTAGES_hytech(&(_m->BMS_DETAILED_VOLTAGES), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0xD9U) && (_id < 0xDBU)) {
       if (_id == 0xD9U) {
        recid = Unpack_BMS_TEMPS_hytech(&(_m->BMS_TEMPS), _d, dlc_);
       } else if (_id == 0xDAU) {
        recid = Unpack_BMS_DETAILED_TEMPS_hytech(&(_m->BMS_DETAILED_TEMPS), _d, dlc_);
       }
      } else {
       if (_id == 0xDBU) {
        recid = Unpack_BMS_STATUS_hytech(&(_m->BMS_STATUS), _d, dlc_);
       } else if (_id == 0xDDU) {
        recid = Unpack_CCU_STATUS_hytech(&(_m->CCU_STATUS), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0xE4U) && (_id < 0xF1U)) {
      if (_id == 0xE4U) {
       recid = Unpack_REAR_SUSPENSION_hytech(&(_m->REAR_SUSPENSION), _d, dlc_);
      } else {
       if (_id == 0xEDU) {
        recid = Unpack_FRONT_SUSPENSION_hytech(&(_m->FRONT_SUSPENSION), _d, dlc_);
       } else if (_id == 0xEEU) {
        recid = Unpack_REAR_THERMISTORS_DATA_hytech(&(_m->REAR_THERMISTORS_DATA), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0xF1U) && (_id < 0xF3U)) {
       if (_id == 0xF1U) {
        recid = Unpack_DRIVEBRAIN_TORQUE_LIM_INPUT_hytech(&(_m->DRIVEBRAIN_TORQUE_LIM_INPUT), _d, dlc_);
       } else if (_id == 0xF2U) {
        recid = Unpack_DRIVEBRAIN_SPEED_SET_INPUT_hytech(&(_m->DRIVEBRAIN_SPEED_SET_INPUT), _d, dlc_);
       }
      } else {
       if (_id == 0xF3U) {
        recid = Unpack_DRIVEBRAIN_DESIRED_TORQUE_INPUT_hytech(&(_m->DRIVEBRAIN_DESIRED_TORQUE_INPUT), _d, dlc_);
       } else if (_id == 0xF4U) {
        recid = Unpack_DRIVEBRAIN_STEERING_INPUT_hytech(&(_m->DRIVEBRAIN_STEERING_INPUT), _d, dlc_);
       }
      }
     }
    }
   } else {
    if ((_id >= 0xF5U) && (_id < 0x10DU)) {
     if ((_id >= 0xF5U) && (_id < 0x103U)) {
      if (_id == 0xF5U) {
       recid = Unpack_FRONT_THERMISTORS_hytech(&(_m->FRONT_THERMISTORS), _d, dlc_);
      } else {
       if (_id == 0x100U) {
        recid = Unpack_EM_MEASUREMENT_hytech(&(_m->EM_MEASUREMENT), _d, dlc_);
       } else if (_id == 0x102U) {
        recid = Unpack_INV2_CONTROL_INPUT_hytech(&(_m->INV2_CONTROL_INPUT), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x103U) && (_id < 0x105U)) {
       if (_id == 0x103U) {
        recid = Unpack_INV3_CONTROL_PARAMETER_hytech(&(_m->INV3_CONTROL_PARAMETER), _d, dlc_);
       } else if (_id == 0x104U) {
        recid = Unpack_INV4_CONTROL_PARAMETER_hytech(&(_m->INV4_CONTROL_PARAMETER), _d, dlc_);
       }
      } else {
       if (_id == 0x105U) {
        recid = Unpack_INV1_CONTROL_PARAMETER_hytech(&(_m->INV1_CONTROL_PARAMETER), _d, dlc_);
       } else if (_id == 0x106U) {
        recid = Unpack_INV2_CONTROL_PARAMETER_hytech(&(_m->INV2_CONTROL_PARAMETER), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x10DU) && (_id < 0x154U)) {
      if ((_id >= 0x10DU) && (_id < 0x140U)) {
       if (_id == 0x10DU) {
        recid = Unpack_ENERGY_METER_MEAS_hytech(&(_m->ENERGY_METER_MEAS), _d, dlc_);
       } else if (_id == 0x136U) {
        recid = Unpack_INV3_OVERLOAD_hytech(&(_m->INV3_OVERLOAD), _d, dlc_);
       }
      } else {
       if (_id == 0x140U) {
        recid = Unpack_INV4_OVERLOAD_hytech(&(_m->INV4_OVERLOAD), _d, dlc_);
       } else if (_id == 0x14AU) {
        recid = Unpack_INV1_OVERLOAD_hytech(&(_m->INV1_OVERLOAD), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x154U) && (_id < 0x300U)) {
       if (_id == 0x154U) {
        recid = Unpack_INV2_OVERLOAD_hytech(&(_m->INV2_OVERLOAD), _d, dlc_);
       } else if (_id == 0x207U) {
        recid = Unpack_CAR_STATES_hytech(&(_m->CAR_STATES), _d, dlc_);
       }
      } else {
       if (_id == 0x300U) {
        recid = Unpack_DASH_INPUT_hytech(&(_m->DASH_INPUT), _d, dlc_);
       } else if (_id == 0x320U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_22_hytech(&(_m->AERO_PRESSURE_SENSOR_22), _d, dlc_);
       }
      }
     }
    }
   }
  }
 } else {
  if ((_id >= 0x330U) && (_id < 0x438U)) {
   if ((_id >= 0x330U) && (_id < 0x429U)) {
    if ((_id >= 0x330U) && (_id < 0x41EU)) {
     if ((_id >= 0x330U) && (_id < 0x3F4U)) {
      if (_id == 0x330U) {
       recid = Unpack_AERO_PRESSURE_SENSOR_32_hytech(&(_m->AERO_PRESSURE_SENSOR_32), _d, dlc_);
      } else {
       if (_id == 0x340U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_42_hytech(&(_m->AERO_PRESSURE_SENSOR_42), _d, dlc_);
       } else if (_id == 0x3F0U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_11_hytech(&(_m->AERO_PRESSURE_SENSOR_11), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x3F4U) && (_id < 0x40DU)) {
       if (_id == 0x3F4U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_12_hytech(&(_m->AERO_PRESSURE_SENSOR_12), _d, dlc_);
       } else if (_id == 0x400U) {
        recid = Unpack_EM_STATUS_hytech(&(_m->EM_STATUS), _d, dlc_);
       }
      } else {
       if (_id == 0x40DU) {
        recid = Unpack_ENERGY_METER_STATUS_hytech(&(_m->ENERGY_METER_STATUS), _d, dlc_);
       } else if (_id == 0x41DU) {
        recid = Unpack_STATE_OF_ENERGY_hytech(&(_m->STATE_OF_ENERGY), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x41EU) && (_id < 0x425U)) {
      if (_id == 0x41EU) {
       recid = Unpack_STATE_OF_CHARGE_hytech(&(_m->STATE_OF_CHARGE), _d, dlc_);
      } else {
       if (_id == 0x41FU) {
        recid = Unpack_STEERING_DATA_hytech(&(_m->STEERING_DATA), _d, dlc_);
       } else if (_id == 0x424U) {
        recid = Unpack_LF_TTPMS_1_hytech(&(_m->LF_TTPMS_1), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x425U) && (_id < 0x427U)) {
       if (_id == 0x425U) {
        recid = Unpack_LF_TTPMS_2_hytech(&(_m->LF_TTPMS_2), _d, dlc_);
       } else if (_id == 0x426U) {
        recid = Unpack_LF_TTPMS_3_hytech(&(_m->LF_TTPMS_3), _d, dlc_);
       }
      } else {
       if (_id == 0x427U) {
        recid = Unpack_LF_TTPMS_4_hytech(&(_m->LF_TTPMS_4), _d, dlc_);
       } else if (_id == 0x428U) {
        recid = Unpack_LF_TTPMS_5_hytech(&(_m->LF_TTPMS_5), _d, dlc_);
       }
      }
     }
    }
   } else {
    if ((_id >= 0x429U) && (_id < 0x430U)) {
     if ((_id >= 0x429U) && (_id < 0x42CU)) {
      if (_id == 0x429U) {
       recid = Unpack_LF_TTPMS_6_hytech(&(_m->LF_TTPMS_6), _d, dlc_);
      } else {
       if (_id == 0x42AU) {
        recid = Unpack_RF_TTPMS_1_hytech(&(_m->RF_TTPMS_1), _d, dlc_);
       } else if (_id == 0x42BU) {
        recid = Unpack_RF_TTPMS_2_hytech(&(_m->RF_TTPMS_2), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x42CU) && (_id < 0x42EU)) {
       if (_id == 0x42CU) {
        recid = Unpack_RF_TTPMS_3_hytech(&(_m->RF_TTPMS_3), _d, dlc_);
       } else if (_id == 0x42DU) {
        recid = Unpack_RF_TTPMS_4_hytech(&(_m->RF_TTPMS_4), _d, dlc_);
       }
      } else {
       if (_id == 0x42EU) {
        recid = Unpack_RF_TTPMS_5_hytech(&(_m->RF_TTPMS_5), _d, dlc_);
       } else if (_id == 0x42FU) {
        recid = Unpack_RF_TTPMS_6_hytech(&(_m->RF_TTPMS_6), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x430U) && (_id < 0x434U)) {
      if ((_id >= 0x430U) && (_id < 0x432U)) {
       if (_id == 0x430U) {
        recid = Unpack_LR_TTPMS_1_hytech(&(_m->LR_TTPMS_1), _d, dlc_);
       } else if (_id == 0x431U) {
        recid = Unpack_LR_TTPMS_2_hytech(&(_m->LR_TTPMS_2), _d, dlc_);
       }
      } else {
       if (_id == 0x432U) {
        recid = Unpack_LR_TTPMS_3_hytech(&(_m->LR_TTPMS_3), _d, dlc_);
       } else if (_id == 0x433U) {
        recid = Unpack_LR_TTPMS_4_hytech(&(_m->LR_TTPMS_4), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x434U) && (_id < 0x436U)) {
       if (_id == 0x434U) {
        recid = Unpack_LR_TTPMS_5_hytech(&(_m->LR_TTPMS_5), _d, dlc_);
       } else if (_id == 0x435U) {
        recid = Unpack_LR_TTPMS_6_hytech(&(_m->LR_TTPMS_6), _d, dlc_);
       }
      } else {
       if (_id == 0x436U) {
        recid = Unpack_RR_TTPMS_1_hytech(&(_m->RR_TTPMS_1), _d, dlc_);
       } else if (_id == 0x437U) {
        recid = Unpack_RR_TTPMS_2_hytech(&(_m->RR_TTPMS_2), _d, dlc_);
       }
      }
     }
    }
   }
  } else {
   if ((_id >= 0x438U) && (_id < 0x500U)) {
    if ((_id >= 0x438U) && (_id < 0x4C7U)) {
     if ((_id >= 0x438U) && (_id < 0x43BU)) {
      if (_id == 0x438U) {
       recid = Unpack_RR_TTPMS_3_hytech(&(_m->RR_TTPMS_3), _d, dlc_);
      } else {
       if (_id == 0x439U) {
        recid = Unpack_RR_TTPMS_4_hytech(&(_m->RR_TTPMS_4), _d, dlc_);
       } else if (_id == 0x43AU) {
        recid = Unpack_RR_TTPMS_5_hytech(&(_m->RR_TTPMS_5), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x43BU) && (_id < 0x4C5U)) {
       if (_id == 0x43BU) {
        recid = Unpack_RR_TTPMS_6_hytech(&(_m->RR_TTPMS_6), _d, dlc_);
       } else if (_id == 0x4C4U) {
        recid = Unpack_FL_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(&(_m->FL_BRAKE_ROTOR_TEMP_CH1_CH4), _d, dlc_);
       }
      } else {
       if (_id == 0x4C5U) {
        recid = Unpack_FL_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(&(_m->FL_BRAKE_ROTOR_TEMP_CH5_CH8), _d, dlc_);
       } else if (_id == 0x4C6U) {
        recid = Unpack_FL_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(&(_m->FL_BRAKE_ROTOR_TEMP_CH9_CH12), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x4C7U) && (_id < 0x4CAU)) {
      if (_id == 0x4C7U) {
       recid = Unpack_FL_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(&(_m->FL_BRAKE_ROTOR_TEMP_CH13_CH16), _d, dlc_);
      } else {
       if (_id == 0x4C8U) {
        recid = Unpack_FL_BRAKE_ROTOR_SENSOR_TEMP_hytech(&(_m->FL_BRAKE_ROTOR_SENSOR_TEMP), _d, dlc_);
       } else if (_id == 0x4C9U) {
        recid = Unpack_FR_BRAKE_ROTOR_TEMP_CH1_CH4_hytech(&(_m->FR_BRAKE_ROTOR_TEMP_CH1_CH4), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x4CAU) && (_id < 0x4CCU)) {
       if (_id == 0x4CAU) {
        recid = Unpack_FR_BRAKE_ROTOR_TEMP_CH5_CH8_hytech(&(_m->FR_BRAKE_ROTOR_TEMP_CH5_CH8), _d, dlc_);
       } else if (_id == 0x4CBU) {
        recid = Unpack_FR_BRAKE_ROTOR_TEMP_CH9_CH12_hytech(&(_m->FR_BRAKE_ROTOR_TEMP_CH9_CH12), _d, dlc_);
       }
      } else {
       if (_id == 0x4CCU) {
        recid = Unpack_FR_BRAKE_ROTOR_TEMP_CH13_CH16_hytech(&(_m->FR_BRAKE_ROTOR_TEMP_CH13_CH16), _d, dlc_);
       } else if (_id == 0x4CDU) {
        recid = Unpack_FR_BRAKE_ROTOR_SENSOR_TEMP_hytech(&(_m->FR_BRAKE_ROTOR_SENSOR_TEMP), _d, dlc_);
       }
      }
     }
    }
   } else {
    if ((_id >= 0x500U) && (_id < 0x640U)) {
     if ((_id >= 0x500U) && (_id < 0x503U)) {
      if (_id == 0x500U) {
       recid = Unpack_ACU_OK_hytech(&(_m->ACU_OK), _d, dlc_);
      } else {
       if (_id == 0x501U) {
        recid = Unpack_DRIVEBRAIN_LATENCY_TIMES_hytech(&(_m->DRIVEBRAIN_LATENCY_TIMES), _d, dlc_);
       } else if (_id == 0x502U) {
        recid = Unpack_DRIVEBRAIN_LATENCY_STATUSES_hytech(&(_m->DRIVEBRAIN_LATENCY_STATUSES), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x503U) && (_id < 0x620U)) {
       if (_id == 0x503U) {
        recid = Unpack_FLOWMETER_DATA_hytech(&(_m->FLOWMETER_DATA), _d, dlc_);
       } else if (_id == 0x60DU) {
        recid = Unpack_ENERGY_METER_TEMP_hytech(&(_m->ENERGY_METER_TEMP), _d, dlc_);
       }
      } else {
       if (_id == 0x620U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_21_hytech(&(_m->AERO_PRESSURE_SENSOR_21), _d, dlc_);
       } else if (_id == 0x630U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_31_hytech(&(_m->AERO_PRESSURE_SENSOR_31), _d, dlc_);
       }
      }
     }
    } else {
     if ((_id >= 0x640U) && (_id < 0x7F2U)) {
      if ((_id >= 0x640U) && (_id < 0x7EFU)) {
       if (_id == 0x640U) {
        recid = Unpack_AERO_PRESSURE_SENSOR_41_hytech(&(_m->AERO_PRESSURE_SENSOR_41), _d, dlc_);
       } else if (_id == 0x667U) {
        recid = Unpack_BRAKE_PRESSURE_hytech(&(_m->BRAKE_PRESSURE), _d, dlc_);
       }
      } else {
       if (_id == 0x7EFU) {
        recid = Unpack_VEHM_BETA_hytech(&(_m->VEHM_BETA), _d, dlc_);
       } else if (_id == 0x7F1U) {
        recid = Unpack_DASHBOARD_BUZZER_CONTROL_hytech(&(_m->DASHBOARD_BUZZER_CONTROL), _d, dlc_);
       }
      }
     } else {
      if ((_id >= 0x7F2U) && (_id < 0x1806E5F4U)) {
       if (_id == 0x7F2U) {
        recid = Unpack_FD_TEST_hytech(&(_m->FD_TEST), _d, dlc_);
       } else if (_id == 0x7FFU) {
        recid = Unpack_VEHM_ALPHA_hytech(&(_m->VEHM_ALPHA), _d, dlc_);
       }
      } else {
       if (_id == 0x1806E5F4U) {
        recid = Unpack_CHARGER_CONTROL_hytech(&(_m->CHARGER_CONTROL), _d, dlc_);
       } else if (_id == 0x18FF50E5U) {
        recid = Unpack_CHARGER_DATA_hytech(&(_m->CHARGER_DATA), _d, dlc_);
       }
      }
     }
    }
   }
  }
 }

 return recid;
}

