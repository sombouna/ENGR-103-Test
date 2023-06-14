#include <Adafruit_CircuitPlayground.h>

// for buttons
const int leftButtonPin = A3;
const int rightButtonPin = A4;

// the pin # for RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Array of tones
int tones[] = {999, 1050};  


int score = 0;
bool isGameStarted = false;

void setup() {
  CircuitPlayground.begin();

  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  for(int i = 8; i<10; i++)
    if (!isGameStarted) {
    // Game start 
    playRainbow(300, 100);
    isGameStarted = true;
  }

  
  int randomIndex = random(2);  // generates random number from 0 to 1

  // selects tone based on the random 
  int tone = tones[randomIndex];

  // Play the tone
  CircuitPlayground.playTone(tone, 800);  // Play the tone for 1000 milliseconds

  
  if (tone == tones[1]) {
    // Read the left button
    bool isLeftButtonPressed = CircuitPlayground.leftButton();

    if (isLeftButtonPressed) {
      score += 1;
      greenLeds();
    } else {
      score -= 1;
    }
  } else {
    // Read the right button
    bool isRightButtonPressed = CircuitPlayground.rightButton();

    if (isRightButtonPressed) {
      score += 1;
      greenLeds();
    } else {
      score -= 1;
      redLeds();
    }
  }

  // Check if score reaches a certain threshold
  if (score >= 8) {
    playHappySong();
    resetGame();
  }
}

void playRainbow(int currentSpeed, int stripLen) {
  uint32_t offset = millis() / currentSpeed;
  // Loop through each pixel and set it to an incremental color wheel value.
  for(int i=0; i<10; ++i) {
    
   CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 4096 / stripLen) + offset) & 255));
  
  delay(500);  
  }}

void greenLeds() {
  CircuitPlayground.setPixelColor(0, 0, 255, 0);  // Set pixel color to green

}

void redLeds() {
  CircuitPlayground.setPixelColor(0, 255, 0, 0);  // Set pixel color to red

}

void playHappySong() {
  // Your code to play the happy song goes here
}

void resetGame() {
  score = 0;
  isGameStarted = false;

  
  CircuitPlayground.clearPixels();

}
