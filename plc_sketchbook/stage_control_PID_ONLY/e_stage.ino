// --------------------------------
// Function Implementations: Stage
// --------------------------------
void set_stage_power(bool state)  {
  //ADD CODE HERE, this runs at startup
}

void stage(int requested_position)  {                   //in mm, needs to be rescaled to 0->4095*2
  // float signal_voltage = requested_position*3.3/100;
  int outCounts = requested_position;
  int signal_voltage[2] = {0,0};

  signal_voltage[0] = requested_position / 128;
  signal_voltage[1] = requested_position % 128;
  //report_serial_number("Control 1 - ", signal_voltage[0]);
  //report_serial_number("Control 2 - ", signal_voltage[1]);
  

  analog_out(2048, 1, 1);                       //Output from slot 1 channel 1, note channel 1 may be broken    P104DAL2
  analog_out(signal_voltage[0], 1, 2);                       //Output from slot 1 channel 2, note channel 1 may be broken    P104DAL2
  analog_out(signal_voltage[1], 1, 3);                       //Output from slot 1 channel 3, note channel 1 may be broken    P104DAL2

}

// Single Output Code (Depricated)
// void stage(float requested_position)  {                   //in mm, needs to be rescaled to 0->4095*2
//  // float signal_voltage = requested_position*3.3/100;
//  int signal_voltage = requested_position; //4095;
//  analog_out(signal_voltage, 1, 2);                       //Output from slot 1 channel 2, note channel 1 may be broken    P104DAL2
//}
