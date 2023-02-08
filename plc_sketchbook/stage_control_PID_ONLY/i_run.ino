// ----------
// Main Loop
// ----------


void loop()
{
  // Read Sensors
  float current_distance = read_distance();

  // Update Data
  update_path_history(current_distance);
  
  // Control Brainst requested_control
  float requested_control = calculate_path();  //In future put this directly inside motion control input

  // Serial Interface
  report_serial(status_check(1));
  report_serial(status_check(2));
  report_serial_number("Control Effort - ", requested_control);

  // Motion Control
  stage(requested_control);

}

// EOF
