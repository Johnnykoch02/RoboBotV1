#include <Drive.h>
#include <LiquidCrystal_I2C.h>
#include <ObjectDetection.h>


//const int in1 = 2;
//const int in2 = 4;
//const int enA = 3;

//const int in3 = 5;
//const int in4 = 7;
//const int enB =  6;

//const int encoder = 10;


float dt;
Drive drive(2, 4, 3, 5, 7, 6, 10);

//LiquidCrystal_I2C lcd(0x27, 16, 2);
ObjectDetection objd(12, 13, 8, 9);




// Main functions
void setup() {
   Serial.begin(9600);
   Serial.println("Initialized.");
  //lcd.begin();
  //lcd.backlight();
  drive.set_drive_motors();
  //  Serial.println("Done");

}

void loop() {
  int startTime = millis();
  //delay(5);
//  lcd.clear();
  drive.updateDrive(dt);
  drive.setDrive(30, objd.updateObjDetection(dt), 0);

  //lcd.setCursor(0, 1);
  //lcd.print(drive.speed());
  

  dt = (millis() - startTime) /1000.0;

}
