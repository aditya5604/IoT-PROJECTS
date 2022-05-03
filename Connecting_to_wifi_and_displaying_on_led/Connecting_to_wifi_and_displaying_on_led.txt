#include <WiFi.h> // declare the wifi library
#include <LiquidCrystal.h> //declare the library for lcd

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
const char* ssid = "124 AP"; // enter the wifi name
const char* password = "02999033"; // enter the wifi password

void wificonnec();

void setup() 
{
WiFi.begin(ssid, password); // start searching for wifi with the given name and password
lcd.begin(16,2); // start the lcd screen and give the coordinate system
lcd.setCursor(0,0); //set the sursor in led screen to zero
lcd.print("Device Started");
delay(1000);
lcd.clear(); //clear the led screen for next command
lcd.setCursor(0,0);
wificonnec();
}

void wificonnec()
{
lcd.print("Connecting");
delay(1000);

while (WiFi.status() != WL_CONNECTED) // loop to check if the board is connected to wifi
{
  lcd.blink();
  delay(100);
  lcd.noBlink();
}

lcd.noBlink();

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Connected");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("IP ADDRESS");
delay(1000);
lcd.setCursor(0,1);
lcd.print(WiFi.localIP()); // print the IP address of wifi on the lcd 
}

void loop() {

 if(WiFi.status() != WL_CONNECTED ) //if statement to check if wifi is disconnected
 {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Disconnected");
  delay(10000);
  lcd.clear();
  wificonnec(); // passing to setup function again to reconnect to wifi
 }

}
