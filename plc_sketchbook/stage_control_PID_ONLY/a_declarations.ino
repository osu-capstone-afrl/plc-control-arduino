// ----------------------
// Function Declarations
// ----------------------

// Setup Declarations

// Conversions

// Ethernet Interface
// void setup_ethernet();

// Feedback
void report_serial(String i);
void report_serial_number(String i, float j);
void clearSerialBuffer();

// External Indicators

// Stage Motion
void set_stage_power(bool state);
void stage(float requested_position);

// Distance Sensor
void set_distance_sensor_power(bool state);
float read_distance();

// Data Maintenance
void update_path_history(float current_position);
float calculate_path();

// CPU I/O
String status_check(uint8_t Slot);
void analog_out(int data, int slot, int channel);
void digital_out(bool data, int slot, int channel);
uint32_t digital_in(int slot, int channel);
bool read_Estop();
bool read_Scan();
