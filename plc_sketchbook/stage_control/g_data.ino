// ------------------------------------------
// Function Implementations: Data Interfaces
// ------------------------------------------

void update_path_history(uint32_t current_position)  {
  //Shift old data
  for (int i=4; i>0; i--) { //Note that 4=5-1, with 5 being the length of stored data
    distance_hist[i] = distance_hist[i-1];
    velocity_hist[i] = velocity_hist[i-1];
    acceleration_hist[i] = acceleration_hist[i-1];
  }

  //Calculate dt
  unsigned long time_past = time_now;
  time_now = millis();
  uint32_t dt = time_now-time_past;

  //Add new data
  distance_hist[0] = current_position;
  velocity_hist[0] = (distance_hist[0]-distance_hist[1])/dt;
  acceleration_hist[0] = (acceleration_hist[0]-acceleration_hist[1])/dt;
}
