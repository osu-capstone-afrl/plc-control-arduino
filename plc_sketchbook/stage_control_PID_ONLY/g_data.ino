// ------------------------------------------
// Function Implementations: Data Interfaces
// ------------------------------------------

// Updates all historical arrays
void update_path_history(float current_position)  {
  
  // Calculate Dt
  unsigned long time_past = time_now;
  time_now = millis();
  dt = time_now-time_past;

  // Modify Pointer
  last_pointer = histPointer;
  histPointer = histPointer + 1;
  if (histPointer >= histSize) {
    histPointer = 0;
  }

  //Store New Data Points
  distance_hist[histPointer] = current_position;
  velocity_hist[histPointer] = (distance_hist[histPointer]-distance_hist[last_pointer])/dt;
  acceleration_hist[histPointer] = (velocity_hist[histPointer]-velocity_hist[last_pointer])/dt;

  // Display Distance Data in Serial Monitor
  //  for (int i=0; i<histSize; i=i+1) {
  //    Serial.print(distance_hist[i], 5);
  //    Serial.print(", ");
  //  }
  //  Serial.print("    Current Position: ");
  //  Serial.println(current_position, 8);

  // Display Velocity Data in Serial Monitor
  //  for (int i=0; i<histSize; i=i+1) {
  //    Serial.print(velocity_hist[i], 5);
  //    Serial.print(", ");
  //  }
  //  Serial.print("    Current Velocity: ");
  //  Serial.println(velocity_hist[histPointer]);

}
