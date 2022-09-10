
namespace IRremote
{
    const uint32_t POWER_BUTTON  = 0xB946FF00;
    const uint32_t A_BUTTON      = 0xBB44FF00; 
    const uint32_t B_BUTTON      = 0xBF40FF00; 
    const uint32_t C_BUTTON      = 0xBC43FF00; 
    const uint32_t UP_BUTTON     = 0xE619FF00;
    const uint32_t RIGHT_BUTTON  = 0xA15EFF00;
    const uint32_t DOWN_BUTTON   = 0xE31CFF00;
    const uint32_t LEFT_BUTTON   = 0xF30CFF00;
    const uint32_t CENTER_BUTTON = 0xE718FF00;
}

enum RemoteStates
{
    POWER_BUTTON,
    A_BUTTON,
    B_BUTTON,
    C_BUTTON,
    UP_BUTTON,
    RIGHT_BUTTON,
    DOWN_BUTTON,
    LEFT_BUTTON,
    CENTER_BUTTON
};