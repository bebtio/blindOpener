//***************************************//
// Author:  Alberto Heras
// Date:    10 September 2022
// Purpose: 
//***************************************//

#include "irRemote.hpp"


//**************************************************************//
//  decodeIRSignal()
//  Reads in the uint32_t signal return by the IRreceiver object
//  and returns an enum that maps to a button instead.
//**************************************************************//
IRremote::RemoteStates IRremote::decodeIRSignal( uint32_t inputSignal )
{
    // Create a variable holding the state that we will return.
    IRremote::RemoteStates irState( IRremote::NONE );

    // Switch statement to set the irState variable to the corresponding button press.
    switch( inputSignal )
    {
        case( IRremote::POWER_BUTTON_HEX_CODE  ): irState = IRremote::POWER_BUTTON;  break;
        case( IRremote::A_BUTTON_HEX_CODE      ): irState = IRremote::A_BUTTON;      break;
        case( IRremote::B_BUTTON_HEX_CODE      ): irState = IRremote::B_BUTTON;      break;
        case( IRremote::C_BUTTON_HEX_CODE      ): irState = IRremote::C_BUTTON;      break;
        case( IRremote::UP_BUTTON_HEX_CODE     ): irState = IRremote::UP_BUTTON;     break;
        case( IRremote::RIGHT_BUTTON_HEX_CODE  ): irState = IRremote::RIGHT_BUTTON;  break;
        case( IRremote::DOWN_BUTTON_HEX_CODE   ): irState = IRremote::DOWN_BUTTON;   break;
        case( IRremote::LEFT_BUTTON_HEX_CODE   ): irState = IRremote::LEFT_BUTTON;   break;
        case( IRremote::CENTER_BUTTON_HEX_CODE ): irState = IRremote::CENTER_BUTTON; break;
    }

    // Return that enum.
    return( irState );
}
