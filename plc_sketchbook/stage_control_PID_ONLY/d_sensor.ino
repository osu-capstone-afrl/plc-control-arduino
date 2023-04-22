// ---------------------------------
// Function Implementations: Sensor
// ---------------------------------

void set_distance_sensor_power(bool state)
{
  //ADD CODE HERE, this runs at startup
  //Set IP Address, subnet mask, default gateway? Maybe do this permanantly at a computer
}

float read_distance(){
  uint32_t inputCounts = P1.readAnalog(2, 1); //Slot 2, Channel 1,     0 to 8191, with 2.44μA per count
  float inputDistance = inputCounts * calibration_mm_per_increment - calibration_mm_to_subtract; //converts to mm. Check Design Document for details.

//  report_serial_inputs(inputCounts, inputDistance);

  return inputDistance;
}


bool read_Estop(){
  bool Stop = P1.readDiscrete(3,1);
  return false;//!Stop;                 ##################################################FIX THIS#########################################################
}

bool read_Scan(){
  bool Scan = P1.readDiscrete(3,1);
  return !Scan;
}
