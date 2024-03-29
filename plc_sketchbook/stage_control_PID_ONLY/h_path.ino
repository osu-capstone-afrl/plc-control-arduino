// ---------------
// Calculate Path
// ---------------

int calculate_path()  {

  // Data Pre-Processing //
  // Check for Danger
  if(read_Estop()) { // Fully retract if E-Stop is toggled
    requested_control = MinVal;
  } else {
    
    if (distance_hist[histPointer]>1.398) { // Check if Outside Sensor Range
      OutsideRange = true;
    } else {
      OutsideRange = false;
    }
  
    if (OutsideRange) { // Do Nothing Unless Told to Scan
  
      // Check for scanning input
      if(read_Scan()) { // Initialize Scan
        Scanning = true;
      }
      
      if (Scanning) {
        requested_control = command_hist[last_pointer]+50; // Scan each possible stage output slowly
  
        if (requested_control > MaxVal) {//1351) { // If full range has been scanned to no avil
          requested_control = MinVal;
          Scanning = false;
        }
        
      } else {
        requested_control = 0; // Stay Fully Retracted
      }
  
    } else { //Operate on PID basis
      Scanning = false; // Ensure that when we lose the range again
      
      // Calculate Error
      // Always wants to go to desired_offset for PID only, so that distance is error
      error[histPointer] = distance_hist[histPointer] - desired_offset;
    
      // PID & Feed-Forward Tuning
      float Der_error = (error[last_pointer] - error[histPointer]) / (dt);
      Int_error = error[last_pointer] * dt + Int_error;
      
      float P_Effort = P * error[histPointer];
      //report_serial_number("Proportional Control Effort - ", P_Effort);
      float I_Effort = I * Int_error; // BE SURE TO ADD RE-ZEROING BEFORE USE
      float D_Effort = D * Der_error;
      //report_serial_number("Derivative Control Effort - ", D_Effort);
  
      // Calculate Command //NOTE THIS IS NOW IN COUNTS
      requested_control = command_hist[histPointer] - P_Effort - I_Effort - D_Effort;
      if (requested_control > MaxVal) {//1351) {
        requested_control = MaxVal; //1351; // Cap Max Output @ 3.3V
      }
    
    }
  
  
    if (requested_control < MinVal) {
      requested_control = MinVal; // Cap Min Output @ 0V
    }

  }
  command_hist[histPointer] = requested_control;
  return requested_control;
}
