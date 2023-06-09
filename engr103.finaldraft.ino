#include <Adafruit_CircuitPlayground.h>

volatile bool buttonAFlag = false;
volatile bool buttonBFlag = false;
volatile bool switchFlag = true;


float midi[127];
int A_four = 440; // a is 440 hz...
int c_major[8] = {55, 59, 60, 62, 65, 72, 74, 79}; // c_major scale on C4
int c_minor[8] = {55, 59, 60, 62, 65, 72, 74, 79}; // c_minor scale on C4
// will need to add a potential change in range 

// music

volatile bool leftButtonPressed=0;
volatile bool rightButtonPressed=0;
// sound global, may also be used to play the game

int light=0;
int switchSide = 0;
int buttonPin = 2;
int ledPin = 13;
bool on = false;
int buttonState = 0;

// light controls 

float tempC, tempF; // global variables for blowing


// global variables are used to pass data between an ISR and the main program. To make sure variables are shared between an ISR and the main program are updated correctly, declare them as volatile.

void setup() {
  CircuitPlayground.begin();
  //Serial.begin(9600); // may not be able to use cause it doesn't agree with interrupts 
  //delay_2s.start(2000, AsyncDelay::MILLIS);
  //asyncDelay(2000);
  //attachinterrupt(D7, switchInterrupts, LOW) //does not return anything, 
  pinMode(ledPin,OUTPUT); // may switch to 13
  pinMode(buttonPin, INPUT); // sets the digital pin as input
  //next line of code is for the rainbow
  attachInterrupt(digitalPinToInterrupt(4), buttonA, FALLING);
  attachInterrupt(digitalPinToInterrupt(5), buttonB, FALLING);
  attachInterrupt(digitalPinToInterrupt(7), switchFunction, CHANGE);
}



void loop() {
  rainbowCycle(100, 10);
  buttonState = digitalread(buttonPin);
  if (buttonState == HIGH){
    if (on==true){
      on=false;
  } else{
    on=true;
    }
  }

  if (on ==true){
    digitalWrite(ledPin, HIGH);
  }
  else {
      digitalWrite(ledPin, LOW);
  }
  delay (500); // states a pause before allowing the game to start
  }
  // } // ask how long the for loop bracket is open for?

if (buttonAFlag) {
  buttonAFlag = false; 
  light++;
}


if (buttonBFlag){
  buttonBFlag = false;
  light--;
}
void buttonA(){
buttonAFlag = true;
}

void buttonB(){
buttonBFlag = true;
}

void switchFunction(){
  switchFlag = true;
}


void rainbowCycle(int currentSpeed, int stripLen) {
  uint32_t offset = millis() / currentSpeed;
  // Loop through each pixel and set it to an incremental color wheel value.
  for(int i=0; i<10; ++i) {
    
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / stripLen) + offset) & 255));

  }

}
// rainbow code to initalize the game has begun complete
          for(int i = 8; i<10; i++); // ask TA if they would advise you to use the for loop before or after the switch on your board

//plays various of songs, first tone played is the tone the player will have to press in order to earn a point.
