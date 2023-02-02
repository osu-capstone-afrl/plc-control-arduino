// ---------------------------------
// Function Implementations: Sensor
// ---------------------------------

void set_distance_sensor_power(bool state)
{
  //ADD CODE HERE, this runs at startup
  //Set IP Address, subnet mask, default gateway? Maybe do this permanantly at a computer
}

uint32_t read_distance(){ //############################################NOT DOING ANYTHING############################################################
  uint32_t inputCounts = P1.readAnalog(2, 1); //Slot 2, Channel 1,     0 to 8191, with 2.44μA per count

//  String i = "input read from amp measurer (raw)- "; //Reports raw input reading
//  report_serial_number(i, inputCounts);
  
  float inputDistance = inputCounts * calibration_mm_per_increment - calibration_mm_to_subtract; //converts to mm. Check Design Document for details.

//  String j = "input read from amp measurer (mm) - "; //Reports converted input reading
//  report_serial_number(j, inputDistance);

  return inputDistance;
}
