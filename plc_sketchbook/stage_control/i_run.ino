// ----------
// Main Loop
// ----------


void loop()
{
  // Read Sensors
  float current_position = read_distance();
  
  // Control Brains
  update_path_history(current_position);
  float requested_position = calculate_path();

  // Serial Interface
  report_serial();

  // Motion Control
  stage(requested_position);
}

// EOF
