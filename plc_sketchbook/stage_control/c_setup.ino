// ------
// Setup
// ------

void setup() {

  // Initialize Serial Comm Sockets
  Serial.begin(115200);
  Serial.println("Setup Process Complete");

  // Initialize Stage and Sensor
  set_stage_power(true);
  set_distance_sensor_power(true);

  // Exteneral Remote Control Indicator
  pinMode(LED_BUILTIN, OUTPUT);

  // Report Setup Success
  Serial.println("Setup Process Complete");
}
