#include <SoftwareSerial.h>

SoftwareSerial mySerial(12, 13); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("GUno Online!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}

