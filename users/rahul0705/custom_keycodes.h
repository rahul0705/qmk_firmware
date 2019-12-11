#pragma once

#define USER_SAFE_RANGE SAFE_RANGE

enum user_keycodes {
    U_T_AUTO = USER_SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,                   //USB Toggle Automatic GCR control
    DBG_TOG,                    //DEBUG Toggle On / Off
    DBG_MTRX,                   //DEBUG Toggle Matrix Prints
    DBG_KBD,                    //DEBUG Toggle Keyboard Prints
    DBG_MOU,                    //DEBUG Toggle Mouse Prints
    MD_BOOT,                    //Restart into bootloader after hold timeout
    RAHUL,                      //Rahul
    SHRUG,                      //Shrug
    ANGRY,                      //Angry
    WIDETXT,                    //w i d e t e x t   f o r   a   w i d e   b o y
#ifndef TAP_DANCE_ENABLE
    TD_SFT,                    // `RSHFT` when held, `CTRL + B` when tapped
#endif
    KEYMAP_SAFE_RANGE,          //the starting point for keyboard specific macros
};
