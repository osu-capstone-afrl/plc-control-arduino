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

// Calibration Data - Linear Stage
// Constants go here

// byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // NIC mac address


//  //Timer for position update over serial
//  const int period = 500;                   //Time between serial monitor updates [ms]
unsigned long time_now = millis();
uint32_t dt = 0;                              //Time between previous cycles

// Global constants for use in code
uint32_t desired_offset = 12345;              // FIX THIS /////// 100 microns with 50 micron tolerance, 2 deg sway allowance from perpendicular
uint32_t command_hist[histSize]; //Try histSize
uint32_t distance_hist[histSize];
uint32_t velocity_hist[histSize];
uint32_t acceleration_hist[histSize];
uint32_t error[histSize];

// PID Tuning Parameters
uint32_t Int_error = 0;
uint32_t P = 1;
uint32_t I = 0;
uint32_t D = 0;
