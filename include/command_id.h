#ifndef COMMAND_ID_H
#define COMMAND_ID_H
#include "inttypes.h"

namespace nitrokey {
namespace proto {
    namespace stick20 {
      enum class device_status : uint8_t {
        idle = 0,
        ok,
        busy,
        wrong_password,
        busy_progressbar,
        password_matrix_ready,
        no_user_password_unlock,
        smartcard_error,
        security_bit_active
      };
      const int CMD_START_VALUE = 0x20;
      const int CMD_END_VALUE = 0x60;
    }
    namespace stick10 {
      enum class command_status : uint8_t {
          ok = 0,
      };
      enum class device_status : uint8_t {
        ok = 0,
        busy = 1,
        wrong_password  = 4,
      };
    }


enum class CommandID : uint8_t {
  GET_STATUS = 0x00,
  WRITE_TO_SLOT = 0x01,
  READ_SLOT_NAME = 0x02,
  READ_SLOT = 0x03,
  GET_CODE = 0x04,
  WRITE_CONFIG = 0x05,
  ERASE_SLOT = 0x06,
  FIRST_AUTHENTICATE = 0x07,
  AUTHORIZE = 0x08,
  GET_PASSWORD_RETRY_COUNT = 0x09,
  CLEAR_WARNING = 0x0A,
  SET_TIME = 0x0B,
  TEST_COUNTER = 0x0C,
  TEST_TIME = 0x0D,
  USER_AUTHENTICATE = 0x0E,
  GET_USER_PASSWORD_RETRY_COUNT = 0x0F,
  USER_AUTHORIZE = 0x10,
  UNLOCK_USER_PASSWORD = 0x11,
  LOCK_DEVICE = 0x12,
  FACTORY_RESET = 0x13,
  CHANGE_USER_PIN = 0x14,
  CHANGE_ADMIN_PIN = 0x15,

  STICK20_CMD_SEND_PASSWORD = stick20::CMD_START_VALUE + 18,
  STICK20_CMD_SEND_NEW_PASSWORD = stick20::CMD_START_VALUE + 19,

  ENABLE_CRYPTED_PARI = 0x20,
  DISABLE_CRYPTED_PARI,
  ENABLE_HIDDEN_CRYPTED_PARI,
  DISABLE_HIDDEN_CRYPTED_PARI,
  ENABLE_FIRMWARE_UPDATE,
  EXPORT_FIRMWARE_TO_FILE,
  GENERATE_NEW_KEYS,
  FILL_SD_CARD_WITH_RANDOM_CHARS,

  WRITE_STATUS_DATA,
  ENABLE_READONLY_UNCRYPTED_LUN,
  ENABLE_READWRITE_UNCRYPTED_LUN,

  SEND_PASSWORD_MATRIX,
  SEND_PASSWORD_MATRIX_PINDATA,
  SEND_PASSWORD_MATRIX_SETUP,

  GET_DEVICE_STATUS,
  SEND_DEVICE_STATUS,

  SEND_HIDDEN_VOLUME_PASSWORD,
  SEND_HIDDEN_VOLUME_SETUP,
  SEND_PASSWORD,
  SEND_NEW_PASSWORD,
  CLEAR_NEW_SD_CARD_FOUND,

  SEND_STARTUP,
  SEND_CLEAR_STICK_KEYS_NOT_INITIATED,
  SEND_LOCK_STICK_HARDWARE,

  PRODUCTION_TEST,
  SEND_DEBUG_DATA,

  CHANGE_UPDATE_PIN,

  GET_PW_SAFE_SLOT_STATUS = 0x60,
  GET_PW_SAFE_SLOT_NAME = 0x61,
  GET_PW_SAFE_SLOT_PASSWORD = 0x62,
  GET_PW_SAFE_SLOT_LOGINNAME = 0x63,
  SET_PW_SAFE_SLOT_DATA_1 = 0x64,
  SET_PW_SAFE_SLOT_DATA_2 = 0x65,
  PW_SAFE_ERASE_SLOT = 0x66,
  PW_SAFE_ENABLE = 0x67,
  PW_SAFE_INIT_KEY = 0x68,
  PW_SAFE_SEND_DATA = 0x69,
  SD_CARD_HIGH_WATERMARK = 0x70,
  DETECT_SC_AES = 0x6a,
  NEW_AES_KEY = 0x6b
};

const char *commandid_to_string(CommandID id);
}
}
#endif
