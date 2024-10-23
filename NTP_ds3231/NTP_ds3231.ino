#include <GyverOLED.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DS3231.h>
#include <Wire.h>

DS3231 myRTC;
byte year;
byte month;
byte date;
byte dow;
byte hour;
byte minute;
byte second;
bool century = false;
bool h12Flag;
bool pmFlag;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//int hour, minute, second;
String fullTime;
const char *ssid     = "Magavert";
const char *password = "07026645";
GyverOLED<SSH1106_128x64> oled;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  timeClient.begin();
  timeClient.setTimeOffset(10800);
  myRTC.setClockMode(false);  // set to 24h
  Connect();

  
  oled.init();              // инициализация
}

void loop() {
  
  Serial.print(timeClient.getFormattedTime());
  Serial.print(myRTC.getHour(h12Flag, pmFlag), DEC); //24-hr
  Serial.print(":");
  Serial.print(myRTC.getMinute(), DEC);
  Serial.print(":");
  Serial.println(myRTC.getSecond(), DEC);
  display();
  delay(100);
}

void Connect(){
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.update();
  timeClient.setTimeOffset(10800);
  fullTime = timeClient.getFormattedTime();

  myRTC.setHour(fullTime.substring(0,2).toInt());
  myRTC.setMinute(fullTime.substring(3,5).toInt());
  myRTC.setSecond(fullTime.substring(6,8).toInt());
}
void display() {
  oled.clear();
  oled.setScale(2);
  
  oled.home();
  fullTime = timeClient.getFormattedTime();
  oled.print(" " + fullTime);
  
  oled.setCursor(0, 3);
  oled.print(myRTC.getHour(h12Flag, pmFlag));
  oled.print("_");
  oled.print(myRTC.getMinute());
  oled.print("_");
  oled.print(myRTC.getSecond());  
  
  oled.update();
}