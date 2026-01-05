#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledpin = 2;
int button_pin = A0;
int reset_button = A1;
int reset_state;
int ledstate = 0;
int oldstate = 0;
int newstate = 0;
int delay_time = 1000;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.backlight();
pinMode(ledpin, OUTPUT);
pinMode(button_pin, INPUT);
pinMode(reset_button, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
newstate = digitalRead(button_pin);
reset_state = digitalRead(reset_button);

if(newstate == 1 && oldstate == 0){
  if(ledstate == 1){
    ledstate = 0;
  }
  else{
    ledstate = 1;
  }
  digitalWrite(ledpin, ledstate);
}
oldstate = newstate;


if(ledstate == 1){
  if(reset_state == 1){
  counter = 0;
}
  counter = counter + 1;
  lcd.setCursor(1, 0);
  lcd.print("timer: \t");
  lcd.setCursor(3, 1);
  lcd.print(counter);
  lcd.setCursor(8, 1);
  lcd.print("sec");
  delay(delay_time);
  lcd.clear();
}
else{
  if(reset_state == 1){
  counter = 0;
}
  lcd.setCursor(0, 0);
  lcd.print("led duration: ");
  lcd.setCursor(5, 1);
  lcd.print(counter);
  lcd.setCursor(8, 1);
  lcd.print("sec");
  delay(delay_time);
  lcd.clear();
}



}
