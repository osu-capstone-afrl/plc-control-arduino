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
void stage(float requested_position);

// Distance Sensor
void set_distance_sensor_power(bool state);
uint32_t read_distance();

// Data Maintenance
void update_path_history(float current_position);
uint32_t calculate_path();

// CPU I/O
String status_check(uint8_t Slot);
void analog_out(uint32_t data, uint8_t slot, uint8_t channel);
void digital_out(bool data, uint8_t slot, uint8_t channel);
uint32_t digital_in(uint8_t slot, uint8_t channel);
