/*
Two Sensor Compare

Builds on twoSensorSerial.
The two sensors are compared against each other. Whichever one has the
HIGHER reading wins, and only that sensor's LED turns on.
If neither sensor is above the minimum, both LEDs stay off.

Pin A1 : Sensor 1  ->  Pin 12 : LED 1
Pin A2 : Sensor 2  ->  Pin 27 : LED 2

Remember: analogRead() on the ESP32 gives a value from 0 - 4095
analogWrite() takes a value from 0 - 255
Set the Serial Monitor to 9600 baud to see the values.
*/

//Sensor variables
int sensor1Pin = A1;
int sensor1Value;

int sensor2Pin = A2;
int sensor2Value;

//Below this, both sensors count as untouched and nothing lights up
//Raise it if the LEDs flicker back and forth on their own
int minimumValue1 = 500;
int minimumValue2 = 150;

//LED variables
int led1Pin = 27;
int led1Value;

int led2Pin = 12;
int led2Value;

//The brightness for a winning and a losing LED (0 - 255)
int onBrightness = 255;
int offBrightness = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop()
{
  //read both sensors (0 - 4095)
  sensor1Value = analogRead(sensor1Pin);
  sensor2Value = analogRead(sensor2Pin);

  //compare the two readings and decide which LED wins
  if (sensor1Value < minimumValue1 || sensor2Value < minimumValue2)
  {
    //neither sensor is active
    led1Value = onBrightness;
    led2Value = onBrightness;
  }

  else 
  {
    //both sensors active
    led1Value = offBrightness;
    led2Value = offBrightness;
  }

  //set the LEDs
  analogWrite(led1Pin, led1Value);
  analogWrite(led2Pin, led2Value);

  //print the sensor and LED values on one line
  Serial.print("Sensor 1: ");
  Serial.print(sensor1Value);
  Serial.print("   LED 1: ");
  Serial.print(led1Value);
  Serial.print("   Sensor 2: ");
  Serial.print(sensor2Value);
  Serial.print("   LED 2: ");
  Serial.println(led2Value);
}
