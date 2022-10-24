// ---------------
// Calculate Path
// ---------------

uint32_t calculate_path()  {
  uint32_t requested_control = command_hist[0] + (distance_hist[0]-desired_offset);
  return requested_control; //UPGRADE CODE HERE
}
