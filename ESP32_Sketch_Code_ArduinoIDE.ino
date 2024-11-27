#include <LiquidCrystal.h>

// LCD pin configuration
#define RS 19
#define EN 23
#define D4 18
#define D5 17
#define D6 16
#define D7 15

// LED pin configuration
#define LED1 14
#define LED2 13
#define LED3 12
#define LED4 25
#define LED5 33

// MCB input pin
#define MCB_PIN 26  // Adjust to your MCB pin

// Initialize the LCD
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  // LCD setup
  lcd.begin(16, 2); // Initialize 16x2 LCD
  
  // MCB input pin setup
  pinMode(MCB_PIN, INPUT_PULLUP);

  // LED pin setup
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  // Display initialization
  lcd.setCursor(0, 0);
  lcd.print("Checking MCB...");
}

void loop() {
  int mcbState = digitalRead(MCB_PIN);

  // Update LCD based on MCB state
  lcd.clear();
  lcd.setCursor(0, 0);
  if (mcbState == HIGH) {
    lcd.print("MCB: TRIPPED !");
    stopLeds();
  } else {
    lcd.print("MCB: CLOSED");
    randomBlinkPattern(); 
  }

  delay(1000); // 3-second delay
}

void randomBlinkPattern() {
  // Turn off all LEDs initially
  stopLeds();

  // Randomly choose an LED to turn on
  int ledIndex = random(1, 6); // Generate a random number between 1 and 5
  switch (ledIndex) {
    case 1:
      digitalWrite(LED1, HIGH);
      break;
    case 2:
      digitalWrite(LED2, HIGH);
      break;
    case 3:
      digitalWrite(LED3, HIGH);
      break;
    case 4:
      digitalWrite(LED4, HIGH);
      break;
    case 5:
      digitalWrite(LED5, HIGH);
      break;
  }

  delay(500); // Brief on-time for the LED
  stopLeds(); // Turn off all LEDs after the delay
}

void stopLeds() {
  // Ensure all LEDs are turned off
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}
