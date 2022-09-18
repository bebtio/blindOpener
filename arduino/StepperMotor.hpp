#ifndef _STEPPERMOTOR_HPP_
#define _STEPPERMOTOR_HPP_

// TODO: figure out which logic value defines the motor step direction 
//#define CLOCKWISE
// TODO: figure out which logic value defines the motor step direction 
//#define COUNTERCLOCKWISE

class StepperMotor
{
public:

    // Enumeration to define the directions the motor can spin.
    enum StepDirection
    {
        COUNTER_CLOCKWISE,
        CLOCKWISE,
    };

    // Based on values on pins MS1 and MS2 of Easy stepper motor board.
    // |-------------------------------------------------------------------------------|
    // | MS1  | MS2   | Microstep Resolution  |                                        |
    // |-------------------------------------------------------------------------------|
    // | LOW  | LOW   | FULL_STEP             |  Fastest rotation                      |
    // | HIGH | LOW   | HALF_STEP             |  ...                                   |
    // | LOW  | HIGH  | QUARTER_STEP          |  ...                                   |
    // | HIGH | HIGH  | EIGTH_STEP            |  Slowest: This is the default setting. |
    // |-------------------------------------------------------------------------------|
    enum StepSpeed
    {
        FULL_STEP,
        HALF_STEP,
        QUARTER_STEP,
        EIGHTH_STEP
    };

    StepperMotor();

    void init();
    void setDirection(  StepDirection direction );
    void step();
    void setStepSpeed( StepSpeed speed );
    
private:

};

#endif // _STEPPERMOTOR_HPP_