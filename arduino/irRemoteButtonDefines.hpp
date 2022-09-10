#ifndef IRREMOTEBUTTONDEFINES_HPP
#define IRREMOTEBUTTONDEFINES_HPP

#include <Arduino.h>
#include <stdint.h>

//******************************************************//
// This file contains information about the IR remote buttons.
// 
//
//
//******************************************************//
namespace IRremote
{

    // The pin that will be hooked up to the IR receiver.
    const uint32_t IR_PIN = 2;
    
    // The hex code that the IR remote transmits per button.
    const uint32_t POWER_BUTTON_HEX_CODE  = 0xB946FF00;
    const uint32_t A_BUTTON_HEX_CODE      = 0xBB44FF00; 
    const uint32_t B_BUTTON_HEX_CODE      = 0xBF40FF00; 
    const uint32_t C_BUTTON_HEX_CODE      = 0xBC43FF00; 
    const uint32_t UP_BUTTON_HEX_CODE     = 0xE619FF00;
    const uint32_t RIGHT_BUTTON_HEX_CODE  = 0xA15EFF00;
    const uint32_t DOWN_BUTTON_HEX_CODE   = 0xE31CFF00;
    const uint32_t LEFT_BUTTON_HEX_CODE   = 0xF30CFF00;
    const uint32_t CENTER_BUTTON_HEX_CODE = 0xE718FF00;

    // An enum assigned per button so we can easily save the current state.
    enum RemoteStates
    {
        POWER_BUTTON = 0,
        A_BUTTON,
        B_BUTTON,
        C_BUTTON,
        UP_BUTTON,
        RIGHT_BUTTON,
        DOWN_BUTTON,
        LEFT_BUTTON,
        CENTER_BUTTON,
        NONE
    };

    // Map the button string to the enum position above. 0 is POWER, A is 1, ..., CENTER is 8.
    const String buttonStringMap[] = { "POWER","A", "B","C","UP", "RIGHT", "DOWN","LEFT","CENTER"};

    // Reads in a signal form the IR pin and returns an enum representing the button press.
    RemoteStates decodeIRSignal( uint32_t inputSignal );
}

#endif
