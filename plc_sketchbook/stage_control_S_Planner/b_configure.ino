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
int desired_offset = 12345;              // FIX THIS /////// 100 microns with 50 micron tolerance, 2 deg sway allowance from perpendicular
int command_hist[10]; //Try histSize
int distance_hist[10];
int velocity_hist[10];
int acceleration_hist[10];


// Path Planning Constants
int max_v = 1;                // m/s
int max_a = 1;              // m/s^2
int time_to_max_a = 15;       // s
int PLC_dt = 5;               // s
int xf = 0;                  // m
int x0 = 500;                // m, and this is for a single direction. Deadband is actually twice as wide
int timestamps[7];
