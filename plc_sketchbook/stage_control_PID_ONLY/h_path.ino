// ---------------
// Calculate Path
// ---------------

float calculate_path()  {

  // Data Pre-Processing //
  // Check for Danger

  // Calculate Error
  // Always wants to go to desired_offset for PID only, so that distance is error
  error[histPointer] = distance_hist[histPointer] - desired_offset;

 
  // PID & Feed-Forward Tuning
  float Der_error = (error[last_pointer] - error[histPointer]) / (dt);
  Int_error = error[last_pointer] * dt + Int_error;
  
  float P_Effort = P * error[histPointer];
  float I_Effort = I * Int_error; // BE SURE TO ADD RE-ZEROING BEFORE USE
  float D_Effort = D * Der_error;

  // Calculate Command //NOTE THIS IS NOW IN COUNTS
  float requested_control = command_hist[histPointer] + P_Effort + I_Effort + D_Effort;
  command_hist[histPointer] = requested_control;
  return requested_control;
}
