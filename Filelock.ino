#include <LiquidCrystal_I2C.h>
#include <Wire.h>
String paragraph = "Mars, the Red Planet, has captivated humanity for centuries with its mysteries and potential for life. Its geological features, thin atmosphere, and the search for water make it a prime target for exploration and scientific research, propelling us closer to uncovering the secrets of our neighboring planet.             ";
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Piezo = 1;
int Buttons[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
char values[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int LEDS[] = {13, 12};
int offButton = 11;
String passwordGuess = "";
String password = "1111";

void setup() {
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < 10; i++) {
    pinMode(Buttons[i], INPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(offButton, INPUT);
  pinMode(Piezo, OUTPUT);
}

void loop(){
  digitalWrite(LEDS[0], HIGH);
  lcd.setCursor(0, 0);
  lcd.println("The password: ");
  if (digitalRead(Buttons[0]) == HIGH) {
    passwordGuess += values[0];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[1]) == HIGH) {
    passwordGuess += values[1];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[2]) == HIGH) {
    passwordGuess += values[2];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password: ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[3]) == HIGH) {
    passwordGuess += values[3];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[4]) == HIGH) {
    passwordGuess += values[4];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[5]) == HIGH) {
    passwordGuess += values[5];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[6]) == HIGH) {
    passwordGuess += values[6];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[7]) == HIGH) {
    passwordGuess += values[7];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (digitalRead(Buttons[8]) == HIGH) {
    passwordGuess += values[8];
    delay(1250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("The password:    ");
    lcd.setCursor(0, 1);
    lcd.print(passwordGuess);
  }

  if (passwordGuess == password){
    correctGuess();
    passwordGuess = "";
  }

  if (password.length() == 16){
    lcd.setCursor(0, 0);
    lcd.println("The password: ");
    lcd.setCursor(0, 1);
    lcd.print("try Again");
    delay(250);
    lcd.clear();
  }
}

void correctGuess(){
    lcd.setCursor(0, 0);
    lcd.println("The password: ");
    lcd.setCursor(0, 1);
    lcd.print("correct");
    lcd.clear();
    tone(1, 500, 3000);
    digitalWrite(LEDS[0], LOW);
    delay(100);
    digitalWrite(LEDS[1], HIGH);
    for (int i = 0; i < 300; i += 32){
      lcd.setCursor(0, 0);
      lcd.println(paragraph.substring(i, i + 16));
      lcd.setCursor(0, 1);
      lcd.println(paragraph.substring(i + 16, i + 32));
      delay(2000);
    }
    delay(2000);
    digitalWrite(LEDS[1], LOW);
    delay(100);
    digitalWrite(LEDS[0], HIGH);
    lcd.clear();
}