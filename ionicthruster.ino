#include <ESP32Servo.h>

int joyX = 34;
int joyY = 35; // (Not used yet but ready for future)
int joySW = 32;

Servo servo[3];
int servoPins[3] = {13, 14, 15};

int activeServo = 0;
int lastButtonState = HIGH;

// Each servo remembers its own last angle
int lastAngles[3] = {90, 90, 90};

void setup() {
  Serial.begin(115200);
  pinMode(joySW, INPUT_PULLUP);

  // Attach each servo
  for(int i = 0; i < 3; i++){
    servo[i].attach(servoPins[i]);
    servo[i].write(90);
  }

  Serial.println("System Ready - Servo 1 Active");
}

void loop() {

  // ------------------------------------------------
  // 1) BUTTON PRESS → Switch active servo
  // ------------------------------------------------
  int buttonState = digitalRead(joySW);
  if(buttonState == LOW && lastButtonState == HIGH){
    activeServo = (activeServo + 1) % 3;
    Serial.print("Now controlling servo: ");
    Serial.println(activeServo + 1);
    delay(250); 
  }
  lastButtonState = buttonState;

  // ------------------------------------------------
  // 2) READ Joystick X and convert to angle
  // ------------------------------------------------
  int xVal = analogRead(joyX);
  int angle = map(xVal, 0, 4095, 0, 180); // FULL follow joystick

  // ------------------------------------------------
  // 3) Write angle ONLY if it actually changes by > 2°
  // (Prevents unnecessary jitter)
  // ------------------------------------------------
  if (abs(angle - lastAngles[activeServo]) > 2) { 
    servo[activeServo].write(angle);
    lastAngles[activeServo] = angle;
  }

  // ------------------------------------------------
  // Debug (optional)
  // ------------------------------------------------
  Serial.print("Servo: ");
  Serial.print(activeServo + 1);
  Serial.print(" | Angle: ");
  Serial.println(angle);

  delay(10); 
}