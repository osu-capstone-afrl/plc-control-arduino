// ---------------------------------------------------
// Function Implementations: Communication Interfaces
// ---------------------------------------------------


void report_serial(String i) {
  Serial.print(i);
}

void report_serial_number(String i, float j) {
  Serial.print(i);
  Serial.println(j,8);
}

void report_serial_inputs(uint32_t i, float j) {
  Serial.print("Input ---- Counts = ");
  Serial.print(i);
  Serial.print(", Distance = ");
  Serial.print(j, 6);
  Serial.println(" mm");
}


void clearSerialBuffer() {
  while (Serial.available() > 0) {
    char q = Serial.read();
  }
}



//Module Status Check Functions
String status_check(uint8_t Slot) {                                       //Do I need to worry about int vs uint? ASK ADAM
  String message = "";
  if (Slot == 2) {                                                        // For P1-04DAL-2 module in slot 1
    //char P1.readStatus(3, Slot);                                        // Note that I don't think the other module (P1-15CDD1 module in slot 2) has diagnostics
    if (bitRead(P1.readStatus(3, Slot), 0) == 1) {
      message.concat("Module Diagnstics Failure for Slot ");
      message.concat(Slot);
      message.concat("\n");
    }
    if (bitRead(P1.readStatus(3, Slot), 1) == 1) {
      message.concat("Lost 24V Error for Slot ");
      message.concat(Slot);
      message.concat("\n");
    }
    // Check for slot power
    if (P1.check24V(Slot) == 1) {
      message.concat("Loss of Power to Slot ");
      message.concat(Slot);
      message.concat("\n");
    }
  }
  return message;
}



///////////
//CPU I/O
///////////

// OUTPUT FUNCTIONS
void analog_out(int data, int slot, int channel) {         //Intended for P1-04DAL-2 module in slot 1
  P1.writeAnalog(data, slot, channel);                                      //data output range is 0->4095
}                                                                           //channels are [1-4]

void digital_out(bool data, int slot, int channel) {            //Intended for P1-15CDD1 module in slot 2
  P1.writeDiscrete(data, slot, channel);                                    //data should be HIGH or LOW
}                                                                           //channels are [1-7] (writing to 8 will have no effect)

// INPUT FUNCTIONS
uint32_t digital_in(int slot, int channel) {                    //Intended for P1-15CDD1 module in slot 2
  return P1.readDiscrete(slot, channel);                                    //channels are [1-8]
}                                                                           //specify channel 0 to read all values as hex [ex. 0x7f]













// The following code could be used for the GPIO block, but this project had no use for the GPIO pins

//boolean pro_digital_read(int pin_number) {
//  pinMode(pin_number, INPUT);
//  return digitalRead(pin_number);
//}
//
//boolean pro_analog_read(int pin_number) {
//  pinMode(pin_number, INPUT);
//  return analogRead(pin_number);
//}
//
//void pro_digital_write(int pin_number, boolean value) {
//  pinMode(pin_number, OUTPUT);
//  digitalWrite(pin_number, value);
//}
//
//void pro_analog_write(int pin_number, int value) { //Note "value" has range of 0->255, and will PWM to a specific value, not hold constant voltage
//  pinMode(pin_number, OUTPUT);
//  analogWrite(pin_number, value);
//}



///// The following code would be used if ethernet module is required
//void setup_ethernet() {
//  // Wait for Ethernet Shield to finish initializing
//  while (Ethernet.linkStatus() != LinkON) {
//    Serial.println("Ethernet Disconnected. Retrying..");
//    delay(500);
//  }
//
//  // Report Info
//  Serial.println("");
//  Serial.println("Ethernet Connected");
//  Serial.print("DNS:              ");     Serial.println(Ethernet.dnsServerIP());
//  Serial.print("IPv4 addrss:      ");     Serial.println(Ethernet.localIP());
//  Serial.println("");
//}
