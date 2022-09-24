//***************************************//
// Author:  Alberto Heras
// Date:    10 September 2022
// Purpose: 
//***************************************//

#include "IRremoteStates.hpp"


//**************************************************************//
//  decodeIRSignal()
//  Reads in the uint32_t signal return by the IRreceiver object
//  and returns an enum that maps to a button instead.
//**************************************************************//
IRremoteStates::RemoteStates IRremoteStates::decodeIRSignal( uint32_t inputSignal )
{
    // Create a variable holding the state that we will return.
    IRremoteStates::RemoteStates irState( IRremoteStates::NONE );

    // Switch statement to set the irState variable to the corresponding button press.
    switch( inputSignal )
    {
        case( IRremoteStates::POWER_BUTTON_HEX_CODE  ): irState = IRremoteStates::POWER_BUTTON;  break;
        case( IRremoteStates::A_BUTTON_HEX_CODE      ): irState = IRremoteStates::A_BUTTON;      break;
        case( IRremoteStates::B_BUTTON_HEX_CODE      ): irState = IRremoteStates::B_BUTTON;      break;
        case( IRremoteStates::C_BUTTON_HEX_CODE      ): irState = IRremoteStates::C_BUTTON;      break;
        case( IRremoteStates::UP_BUTTON_HEX_CODE     ): irState = IRremoteStates::UP_BUTTON;     break;
        case( IRremoteStates::RIGHT_BUTTON_HEX_CODE  ): irState = IRremoteStates::RIGHT_BUTTON;  break;
        case( IRremoteStates::DOWN_BUTTON_HEX_CODE   ): irState = IRremoteStates::DOWN_BUTTON;   break;
        case( IRremoteStates::LEFT_BUTTON_HEX_CODE   ): irState = IRremoteStates::LEFT_BUTTON;   break;
        case( IRremoteStates::CENTER_BUTTON_HEX_CODE ): irState = IRremoteStates::CENTER_BUTTON; break;
    }

    // Return that enum.
    return( irState );
}
