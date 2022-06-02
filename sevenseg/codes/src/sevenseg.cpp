
//Code by GVV Sharma
//April 29, 2022
//https://www.gnu.org/licenses/gpl-3.0.en.html
//
//Seven segment diplay OTA
//
//----------------------Skeleton Code--------------------//

//           LCD interfacing With ESP32     //


#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// set the LCD number of columns and rows
 
//    Can be client or even host   //
#ifndef STASSID
#define STASSID "ssid"  // Replace with your network credentials
#define STAPSK  "password"  
#endif


const char* ssid = STASSID;
const char* password = STAPSK;




void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(13, a); 
  digitalWrite(15, b); 
  digitalWrite(17, c); 
  digitalWrite(19, d); 
  digitalWrite(21, e); 
  digitalWrite(23, f);     
  digitalWrite(25, g); 
}
void setup(){
  OTAsetup();
    pinMode(13, OUTPUT);  
    pinMode(15, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(25, OUTPUT);            
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  sevenseg(1,0,0,1,1,1,1); 
}
