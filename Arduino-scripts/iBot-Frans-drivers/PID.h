#ifndef PID_h
#define PID_h

class PID
{
    public:
        /*controller gains */
        double Kp; // propotrional gain
        double Ki; // inegrator gain
        double Kd; // derivator gain

        /* derivator lowpass filter time constant (in seconds) */
        double tau; // the time constant

        /* output limits */
        double limMin; //minimum output value
        double limMax; //maximum output value

        // sample time (in seconds)
        double T; //small t for continuous time, large T for discrete time

        /* controller "memory" */
        double integrator; //integrating part of the output value
        double prevError; //the previous error
        double differentiator; //the differentiating part of the output value
        double prevMeassurement; //the previous meassurement

        //Controller output
        double Out;

        double update(double setPoint, double meassurement);
        PID(double Kp, double Ki, double Kd, double tau, double limMin, double limMax, double T);
};

#endif