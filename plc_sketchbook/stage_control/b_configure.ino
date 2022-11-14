// --------------------
// Control Definitions
// --------------------

// Calibration Data - Light Position Sensor
// Constants go here
int AO_Slot = 1; //Analog Out
int DIO_Slot = 2; //Digital In/Out
int histPointer = 0; //Index of historical Array
int histSize = 10; //Length of historical Array

// Calibration Data - Linear Stage
// Constants go here

// byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // NIC mac address


//  //Timer for position update over serial
//  const int period = 500;                   //Time between serial monitor updates [ms]
unsigned long time_now = millis();

// Global constants for use in code
uint32_t desired_offset = 12345;              // FIX THIS /////// 100 microns with 50 micron tolerance, 2 deg sway allowance from perpendicular
uint32_t command_hist[histSize];
uint32_t distance_hist[histSize];
uint32_t velocity_hist[histSize];
uint32_t acceleration_hist[histSize];
