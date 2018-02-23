#ifndef PID_fj_h
#define PID_fj_h
#define LIBRARY_VERSION	1.0.0

class PID
{
  public:
   #define ON	1
   #define OFF	0
   #define DIRECT  0
   #define REVERSE  1

   PID(double*, double*, double*, double, double, double, int, int*, int* );
   void SetMode(int Mode);               // * sets PID to either Manual (0) or Auto (non-0)
   bool Compute();                       // * performs the PID calculation.
   void SetTunings(double, double, double, int);
   void Run(int);
   //Display functions ****************************************************************
   double GetKp();			// These functions query the pid for internal values.
   double GetKi();			//  they were created mainly for the pid front-end,
   double GetKd();			// where it's important to know what is actually 
   int GetState();			//  inside the PID.

  private:
   double kp;               // * (P)roportional Tuning Parameter
   double ki;               // * (I)ntegral Tuning Parameter (must include *T/2)
   double kd;               // * (D)erivative Tuning Parameter (must include /T)
   int direction;

   double *iInput;
   double *iOutput; 
   double *iSetpoint;
   int *iOmin;
   int *iOmax;
   double ITerm, lastInput, lastError;

   bool RUNNING;
};
#endif