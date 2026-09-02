# simpleHC\_SR04 Arduino library

This is a simple Arduino library that contains only one class, but <mark>none code blocking</mark>.

## examples (in the `examples` folder)

```cpp
//simpleDistancePranter.ino
//attach guide:
//HC-SR04 board
//Vcc     5V
//Trig    12
//Echo    2
//Gnd     Gnd

//define the pins
int trigPin = 12;
int echoPin = 2;

#include <simpleHC\_SR04.h> //include the lib

HC\_SR04 hc\_sr04(trigPin, echoPin); //define the class, and input the trig pin and the echo pin

void setup() {  //setup the board
  Serial.begin(9600); //begin the serial at 9600 baud
  Serial.println("===simpleDistancePranter.ino==="); //print the sketch name
  Serial.println();

  hc\_sr04.initAttach(); //attach the pinModes and the interrupt
}


void loop() { //allright, into the loop
  if (hc\_sr04.available()) { //chacking if the SR04 is ready
    float distance = hc\_sr04.getD(); //saving the distance in float
    Serial.print("distance: ");
    Serial.println(distance); //print it out
  }
}
```

> **Hint:** on Arduino uno, the echo pin needs to be 2 or 3. Look at https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/