// --------------------------------
// Function Implementations: Stage
// --------------------------------
void set_stage_power(bool state)  {
  //ADD CODE HERE, this runs at startup
}

void stage(float requested_position)  {                   //in mm, needs to be rescaled to 0->4095
  // float signal_voltage = requested_position*3.3/100;
  int signal_voltage = 4095;
  analog_out(signal_voltage, 1, 2);                       //Output from slot 1 channel 2, note channel 1 may be broken
}
