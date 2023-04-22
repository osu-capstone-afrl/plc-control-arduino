// ----------
// Main Loop
// ----------


void loop()
{
  // Read Sensors
  uint32_t current_distance = read_distance();

  // Update Data
  update_path_history(current_distance);
  
  // Control Brains
  uint32_t requested_control = calculate_path();  //In future put this directly inside motion control input

  // Serial Interface
  report_serial();

  // Motion Control
  stage(requested_control);
}

// EOF
