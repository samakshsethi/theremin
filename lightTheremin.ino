int reading; 
int low = 1023;
int high = 0;
const int ledPin = 9;
const int buzzerPin = 10;
int pitch;
int brightness;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 255);
  while (millis() < 6000) {   //Loop to calibrate the value for the photoresistor
    reading = analogRead(A0);
    
    if (reading > high) {
      high = reading;    //Takes the highest value for the sensor in the current conditions
    }
    if (reading < low) {
      low = reading;    //Takes the lowest value for the sensor in the current conditions
    }
  }
  analogWrite(ledPin, 0);
 }
void loop() {
  reading=analogRead(A0);
  pitch=map(reading, low, high, 50, 4000);    //Photoresistor reading is mapped to value for a (passive) buzzer
  brightness=map(reading, low, high, 0, 2000);   //Photoresistor reading is mapped to value for an led
  if(brightness>0){
    analogWrite(ledPin, brightness/10);
    Serial.println(brightness);
  }
  tone(buzzerPin, pitch, 20);
  delay(10);
 }
