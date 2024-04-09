#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "../dev/types.h"
#include "../hardware/ps2.h"

// Command responses 

enum KB_Response
{
    KB_ERROR = 0x00,
    KB_TEST_PASSED = 0xAA,
    KB_ECHO = 0xEE,
    KB_ACK = 0xFA,
    KB_TEST_FAIL = 0xFC,
    KB_TEST_FAIL_ALT = 0xFD,
    KB_RESEND = 0xFE,
    KB_IDENTIFY_KB = 0xF2,
    KB_ERROR_ALT = 0xFF
};

enum KB_Command
{
    KB_CMD_SET_LED = 0xED,
    KB_CMD_ECHO = 0xEE,
    KB_CMD_SCANCODE = 0xF0,
    KB_CMD_IDENTIFY_KEYBOARD = 0xF2,
    KB_CMD_SET_TYPEMATIC_RATE = 0xF3,
    KB_CMD_ENABLE_SCAN = 0xF4,
    KB_CMD_DISABLE_SCAN = 0xF5,
    KB_CMD_SET_DEFAULT_PARAMS = 0xF6,
    KB_CMD_SET_ALL_KEYS_TYPEMATIC_ONLY = 0xF7,
    KB_CMD_SET_ALL_KEYS_MAKE_RELEASE_ONLY = 0xF8,
    KB_CMD_SET_ALL_KEYS_MAKE_ONLY = 0xF9,
    KB_CMD_SET_ALL_KEYS_ALL = 0xFA,
    KB_CMD_SET_KEY_TYPEMATIC_ONLY = 0xFB,
    KB_CMD_SET_KEY_MAKE_RELEASE_ONLY = 0xFC,
    KB_CMD_SET_KEY_MAKE_ONLY = 0xFD,
    KB_CMD_RESEND_LAST_BYTE = 0xFE,
    KB_CMD_SELF_TEST = 0xFF
};

int KB_SetLEDs(u8_t state);
int KB_Echo();
int KB_GetCurrentScancodeSet();
int KB_SetScancodeSet(u8_t set);
int KB_IdentifyKeyboard();
int KB_SetTypematicRate(u8_t rate, u8_t delay);
int KB_EnableScan();
int KB_DisableScan();
int KB_SetDefaultParams();

int KB_SetAllKeysTypematicOnly();
int KB_SetAllKeysMakeReleaseOnly();
int KB_SetAllKeysMakeOnly();
int KB_SetAllKeysAll();

int KB_SetKeyTypematicOnly(u8_t scancode);
int KB_SetKeyMakeReleaseOnly(u8_t scancode);
int KB_SetKeyMakeOnly(u8_t scancode);

int KB_ResendLastByte();
int KB_SelfTest();


#endif