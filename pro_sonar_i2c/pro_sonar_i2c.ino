
#include <Wire.h>
#include <NewPing.h>

#define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     8  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

}

void loop()
{
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(uS / US_ROUNDTRIP_CM);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  Serial.println(uS / US_ROUNDTRIP_CM);

  delay(500);
  
  /*
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  mySerial.print("From Pro: ");
  mySerial.print("Ping: ");
  mySerial.print(uS / US_ROUNDTRIP_CM);
  mySerial.println("cm");
  */
}
