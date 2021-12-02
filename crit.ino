#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //LDC ports
int buttonstate = 0;
int buttonpressed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //green LED
  pinMode(10, OUTPUT); //Red LED
  pinMode(8, INPUT); //button
  lcd.begin(16,2);
  lcd.print("Rmb to eat your"); 
  lcd.setCursor(0,1);
  lcd.print("morning meds");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstate = digitalRead(8);
  if (buttonstate == 1) {     //if button is pressed, user has ate their meds
   buttonpressed = buttonpressed + 1;
    digitalWrite(10,LOW); //turn off the Red LED
    digitalWrite(9,HIGH); //turn on the Green LED
    lcd.clear(); //clear the LCD before displaying anything
    lcd.print("Great! U ate");  //display the msg
    lcd.setCursor(0,1); //move to the next line
    lcd.print("them!"); //display the rest of the msg
    delay(10000); //delay for 10sec
    digitalWrite(9,LOW); //turn off the Green LED
    lcd.clear(); //clear the LCD
  }
   if (buttonpressed%2 > 0){  //if button pressed is an odd number, then it means the user has ate the morning med
    lcd.clear();
    lcd.print("Rmb to eat your");
    lcd.setCursor(0,1);
    lcd.print("night meds"); 
    }
    else{     //if buttonpressed is an even number, then it means the user has ate the night med
    lcd.clear();
    lcd.print("Rmb to eat your");
    lcd.setCursor(0,1);
    lcd.print("morning meds");
    }
    
    digitalWrite(10,HIGH);  //Flash the Red LED
    delay(150);
    digitalWrite(10,LOW);
    delay(150); 

   
}
