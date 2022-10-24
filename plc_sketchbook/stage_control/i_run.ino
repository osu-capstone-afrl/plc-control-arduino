// ----------
// Main Loop
// ----------


void loop()
{
  // Read Sensors
  uint32_t current_distance = read_distance();
  
  // Control Brains
  update_path_history(current_distance);
  uint32_t requested_control = calculate_path();

  // Serial Interface
  report_serial();

  // Motion Control
  stage(requested_control);
}

// EOF
