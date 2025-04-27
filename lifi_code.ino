#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x3F, 16, 2); // Set the LCD I2C address to 0x3F (adjust according to your LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define ldrPin 8

String duration;

void setup() {
  Serial.begin(9600);

  pinMode(ldrPin, INPUT_PULLUP);

  // Initialize the LCD with I2C address and dimensions
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.print("LiFi Project");
  delay(3000);
  lcd.clear();
  lcd.print("Send any message");
  lcd.setCursor(0, 1);
  lcd.print("from LiFi App..");
  delay(3000);
}

void loop() {
  int val = digitalRead(ldrPin);
  
  while (val == LOW) { // When LDR is blocked (LOW), receive message
    int val2 = digitalRead(ldrPin);
    duration += String(val2);
    
    // Compare received duration pattern with predefined patterns
    if (duration == "101") {
      Serial.println("Received message: hi");
      lcd.clear();
      lcd.print("hi");
    }
    else if (duration == "0001") {
      Serial.println("Received message: hello");
      lcd.clear();
      lcd.print("hello");
    }
    else if (duration == "00001") {
      Serial.println("Received message: how are you?");
      lcd.clear();
      lcd.print("how are you?");
    }
    else if (duration == "000001") {
      Serial.println("Received message: I am fine");
      lcd.clear();
      lcd.print("I am fine");
    }
    else if (duration == "0000001") {
      Serial.println("Received message: ok");
      lcd.clear();
      lcd.print("ok");
    }
    else if (duration == "00000001") {
      Serial.println("Received message: good morning");
      lcd.clear();
      lcd.print("good morning");
    }
    else if (duration == "000000001") {
      Serial.println("Received message: good afternoon");
      lcd.clear();
      lcd.print("good afternoon");
    }
    else if (duration == "0000000001") {
      Serial.println("Received message: good evening");
      lcd.clear();
      lcd.print("good evening");
    }
    else if (duration == "00000000001") {
      Serial.println("Received message: thank you");
      lcd.clear();
      lcd.print("thank you");
    }
    else if (duration == "000000000001") {
      Serial.println("Received message: sorry");
      lcd.clear();
      lcd.print("sorry");
    }

    // Reset duration and break the loop when LDR is unblocked (HIGH)
    if (val2 == HIGH) {
      duration = "";
      break;
    }

    delay(200);
  }
}

