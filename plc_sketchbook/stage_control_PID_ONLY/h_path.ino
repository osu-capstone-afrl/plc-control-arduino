// ---------------
// Calculate Path
// ---------------

uint32_t calculate_path()  {

  // Data Pre-Processing //
  // Check for Danger

  // Calculate Error
  // Always wants to go to desired_offset for PID only, so that distance is error
  error[histPointer] = distance_hist[histPointer] - desired_offset;
 
  // PID & Feed-Forward Tuning
  uint32_t Der_error = (error[last_pointer] - error[histPointer]) / (dt);
  Int_error = error[last_pointer] * dt + Int_error;
  
  uint32_t P_Effort = P * error[histPointer];
  uint32_t I_Effort = I * Int_error;
  uint32_t D_Effort = D * Der_error;

  // Calculate Command
  uint32_t requested_control = command_hist[histPointer] + P_Effort + I_Effort + D_Effort;
  command_hist[histPointer] = requested_control;
  return requested_control;
}
