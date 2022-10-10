// ---------------------------------------------------
// Function Implementations: Communication Interfaces
// ---------------------------------------------------

void setup_ethernet() {
  // Wait for Ethernet Shield to finish initializing
  while (Ethernet.linkStatus() != LinkON) {
    Serial.println("Ethernet Disconnected. Retrying..");
    delay(500);
  }

  // Report Info
  Serial.println("");
  Serial.println("Ethernet Connected");
}

void report_serial() {
    Serial.print("HOUSTON - DO YOU COPY?");
}

void clearSerialBuffer() {
  while(Serial.available() > 0) {
    char q = Serial.read();
  }
}
