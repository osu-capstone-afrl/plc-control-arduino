// ------------------------------------------
// Function Implementations: Data Interfaces
// ------------------------------------------

int last_pointer(int current_pointer) {
  int lastPoint = current_pointer - 1;
  if (lastPoint < 0) {
    lastPoint = histSize - 1;
  }
  return lastPoint;
}


void update_path_history(int current_position)  {

  // Error Handling
  int lastPoint = last_pointer(histPointer);
  
  // Calculate Dt
  unsigned long time_past = time_now;
  time_now = millis();
  int dt = time_now-time_past;

  //Store New Data Points
  distance_hist[histPointer] = current_position;
  velocity_hist[histPointer] = (distance_hist[histPointer]-distance_hist[lastPoint])/dt;
  acceleration_hist[histPointer] = (acceleration_hist[histPointer]-acceleration_hist[lastPoint])/dt;

  // Modify Pointer
  histPointer = histPointer + 1;
  if (histPointer >= histSize) {
    histPointer = 0;
  }
}




//  //Shift old data
//  for (int i=4; i>0; i--) { //Note that 4=5-1, with 5 being the length of stored data
//    distance_hist[i] = distance_hist[i-1];
//    velocity_hist[i] = velocity_hist[i-1];
//    acceleration_hist[i] = acceleration_hist[i-1];
//  }
//
//  //Calculate dt
//  unsigned long time_past = time_now;
//  time_now = millis();
//  int dt = time_now-time_past;
//
//  //Add new data
//  distance_hist[0] = current_position;
//  velocity_hist[0] = (distance_hist[0]-distance_hist[1])/dt;
//  acceleration_hist[0] = (acceleration_hist[0]-acceleration_hist[1])/dt;
