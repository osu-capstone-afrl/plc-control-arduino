// --------------------
// Control Definitions
// --------------------

// Calibration Data - Light Position Sensor
// Constants go here
int AO_Slot = 1; //Analog Out
int DIO_Slot = 2; //Digital In/Out
int histPointer = 1; //Index of historical Array
int last_pointer = 0; //Index of historical Array
const int histSize = 10; //Length of historical Array


const float calibration_mm_per_increment = 0.00020469377; //21364912;  
const float calibration_mm_to_subtract = 0.27664670658;//0.35;  // A result of the input scale being from 0-20mA but the input data being from 4-20mA

// Calibration Data - Linear Stage
// Constants go here

// byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // NIC mac address


//  //Timer for position update over serial
//  const int period = 500;                   //Time between serial monitor updates [ms]
unsigned long time_now = millis();
float dt = 0;                              //Time between previous cycles

// Global constants for use in code
float desired_offset = 0.7;      //in mm        // MAYBE FIX THIS? /////// 100 microns with 50 micron tolerance, 2 deg sway allowance from perpendicular
float command_hist[histSize]; //Try histSize
float distance_hist[histSize];
float velocity_hist[histSize];
float acceleration_hist[histSize];
float error[histSize];
float requested_control = 0;
bool OutsideRange = true;
bool Scanning = false;

// PID Tuning Parameters
float Int_error = 0;
float P = 5;
float I = 0; // Be careful, the memory term already adds some form of this
float D = 0;

// Module Configuration
// const char P1_08ADL_1_CONFIG[] = { 0x40, 0x00 };
