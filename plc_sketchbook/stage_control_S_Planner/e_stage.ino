// --------------------------------
// Function Implementations: Stage
// --------------------------------
void set_stage_power(bool state)  {
  //ADD CODE HERE, this runs at startup
}

void stage(float requested_position)  {                   //0-100
  uint32_t signal_voltage = requested_position*3.3/100;
  analog_out(signal_voltage, 1, 1);                       //Output from slot 1 channel 1
}
