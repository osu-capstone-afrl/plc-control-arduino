// ----------------------
// Function Declarations
// ----------------------

// Setup Declarations

// Conversions

// Ethernet Interface
void setup_ethernet();

// Feedback
void report_serial();
void clearSerialBuffer();

// External Indicators

// Stage Motion
void set_stage_power(bool state);
void stage(int requested_position);

// Distance Sensor
void set_distance_sensor_power(bool state);
float read_distance();

// Data Maintenance
void update_path_history(float current_position);
float calculate_path();
