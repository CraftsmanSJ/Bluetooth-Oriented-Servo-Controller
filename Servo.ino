#include <ESP32Servo.h>
#include <BluetoothSerial.h>
Servo s1, s2;
BluetoothSerial bt;

void setup() {
  s1.attach(17);  // Attach servo s1 to pin 17
  s2.attach(18);  // Attach servo s2 to pin 18
  Serial.begin(115200); // Initialize serial communication
  bt.begin("ESP");
}

void loop() {
    if(bt.available()) {
    char input = bt.read();

    if(input == 'A')
    {
      int x = bt.parseInt();
      s1.write(x);
    }
    if(input == 'B')
    {
      int y = bt.parseInt();
      s2.write(y);
    }
    }
}
