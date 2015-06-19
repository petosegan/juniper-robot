// with help from: http://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string

#include <SoftwareSerial.h>
//#include <AFMotor.h>
//#define INPUT_SIZE 10

#define rxPin 14
#define txPin 15

SoftwareSerial mySerial(rxPin, txPin); // RX, TX


//AF_DCMotor motor1(1);

//char * pch;
//char this_ping[INPUT_SIZE+1];
//byte this_size;

void setup()  
{
  pinMode(txPin, OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Uno Online!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  
  //motor1.setSpeed(200);
  //motor1.run(RELEASE);
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}

