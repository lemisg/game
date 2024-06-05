#include <Adafruit_CircuitPlayground.h>

// Game variables
int score = 0;
int lives = 3;
float responseTime = 5000;  // initial response time in milliseconds
unsigned long startTime;
bool gameActive = false;

// Sounds
const int correctTone = 262;
const int incorrectTone = 131;
const int gameOverTone = 65;



void setup() {
  // Initialize the CircuitPlayground library
  CircuitPlayground.begin();
  Serial.begin(9600);

  // Set up button inputs and initial state
  pinMode(CPLAY_LEFTBUTTON, INPUT);
  pinMode(CPLAY_RIGHTBUTTON, INPUT);
  gameActive = false;
}

void loop() {


  Serial.println(score,lives);
  if (!gameActive && digitalRead(CPLAY_LEFTBUTTON) == HIGH) {
    startGame();
  }

  if (gameActive) {
    mainGameLoop();
  }
}

void startGame() {
  score = 0;
  lives = 3;
  responseTime = 5000;
  CircuitPlayground.clearPixels();
  CircuitPlayground.playTone(523, 500);
  gameActive = true;
  mainGameLoop();
}

void mainGameLoop() {
  while (lives > 0) {
    String color = randomColor();
    displayLED(color);
    startTime = millis();

    while (millis() - startTime < responseTime) {
      if (color == "red" && digitalRead(CPLAY_RIGHTBUTTON) == HIGH) {
        correctResponse();
        break;
      } else if (color == "blue" && CircuitPlayground.motionX() > 1.5) {
        correctResponse();
        break;
      } else if (color == "green" && CircuitPlayground.leftButton()) {
        correctResponse();
        break;
      }
    }

    if (millis() - startTime >= responseTime) {
      incorrectResponse();
    }

    delay(500);  // Brief delay before next round
  }

  gameOver();
}

void displayLED(String color) {
  if (color == "red") {
    for(int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
    }
  } else if (color == "blue") {
    for(int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i, 0, 0, 255);}
  } else if (color == "green") {
    for(int i=0; i<10; i++){
    CircuitPlayground.setPixelColor(i, 0, 255, 0);}
  }
  CircuitPlayground.clearPixels();
}

String randomColor() {
  int randIndex = random(0, 3);
  if (randIndex == 0) {
    return "red";
  } else if (randIndex == 1) {
    return "blue";
  } else {
    return "green";
  }
}

void correctResponse() {
  score++;
  responseTime *= 0.95;  // Decrease response time to increase difficulty
  CircuitPlayground.playTone(correctTone, 500);
}

void incorrectResponse() {
  lives--;
  CircuitPlayground.playTone(incorrectTone, 500);
}

void gameOver() {
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(0, 255, 0, 0);  // Red color for game over
  CircuitPlayground.clearPixels();
  CircuitPlayground.playTone(gameOverTone, 1000);
  Serial.print("Game Over! Your score: ");
  Serial.println(score);
  gameActive = false;
}


