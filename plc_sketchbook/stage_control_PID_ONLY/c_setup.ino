// ------
// Setup
// ------

void setup() {

  // Initialize Serial Comm Sockets
  Serial.begin(115200);
  Serial.println("Setup Process Complete");

  // Initializes the P1AM communications to the P1 modules
  // P1.init(); //returns type uint8_t for diagnostic. Implement?
  while (!P1.init()) {
    delay(100); //Wait for Modules to Sign on  
  }

  //Initialize Ethernet
//  Serial.println("Setup Configuration: Network enabled. Will now attempt to connect to network");
//  Ethernet.begin(mac);
  // setup_ethernet();

  // Initialize Stage and Sensor
  set_stage_power(true);
  set_distance_sensor_power(true);

  // Initialize Modules
  // while(0==P1.configureModule(P1_08ADL_1_CONFIG[], uint8_t 2)); // Slot 2

  // Exteneral Remote Control Indicator
  pinMode(LED_BUILTIN, OUTPUT);

  // Report Setup Success
  Serial.println("Setup Process Complete");
}
