// ------------------------------------------
// Function Implementations: Data Interfaces
// ------------------------------------------

// Updates all historical arrays
void update_path_history(float current_position)  {

  Serial.println(current_position);
  
  // Calculate Dt
  unsigned long time_past = time_now;
  time_now = millis();
  uint32_t dt = time_now-time_past;

  //Store New Data Points
  distance_hist[histPointer] = current_position;
  velocity_hist[histPointer] = (distance_hist[histPointer]-distance_hist[last_pointer])/dt;
  acceleration_hist[histPointer] = (acceleration_hist[histPointer]-acceleration_hist[last_pointer])/dt;

  //Display Data in Serial Monitor
  for (int i=0; i<histSize-1; i=i+1) {
    Serial.print(distance_hist[i]);
    Serial.print(", ");
  }
  Serial.println(distance_hist[histSize-1]);

  // Modify Pointer
  last_pointer = histPointer;
  histPointer = histPointer + 1;
  if (histPointer >= histSize) {
    histPointer = 0;
  }
}
