// Biblioteca do Display LCD
#include <LiquidCrystal.h>

int inches = 0;
int cm = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  lcd.begin(16, 2);
 
  lcd.setCursor(2, 0);                     

  lcd.print("NAVAR M M N");               
  
  lcd.setCursor(0, 1);
  
  lcd.print("HC-SR04 + LCD");
  
  delay(2000); 
  
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  lcd.clear();
  
}

void loop() {

  lcd.clear();
  
  cm = 0.01723 * readUltrasonicDistance(7, 8);
  
  lcd.setCursor(0, 0);                    

  lcd.print("Distancia em"); 
  
  lcd.setCursor(0, 1);
 
  lcd.print("Centimetro: ");
  
  lcd.print(cm);
  
  delay(100);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
