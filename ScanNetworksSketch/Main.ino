/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-led-blink
 */

#define OUTPUT_PIN 2

const int serialPort = 0;
const int baudRate = 9600;
const int parity = 0;

void setup() {
  // initialize digital pin GPIO18 as an output.
  pinMode(OUTPUT_PIN, OUTPUT);

  Serial.begin(9600);
  
  // wiFiSetup();
  matrixSetup();

  // delay(100);
  Serial.println("started....");
}

// the loop function runs over and over again forever
void loop() {
  // blinkPattern();

  networkScan();
  // matrixLoop();

  digitalWrite(OUTPUT_PIN, HIGH);
  delay(200);
  digitalWrite(OUTPUT_PIN, LOW);
}
