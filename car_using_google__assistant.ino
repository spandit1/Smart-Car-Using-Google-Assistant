/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "95b953fcccb44df8a6b9f11a1fb5864b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VIBE K5 NOTE";
char pass[] = "soumya12345";

void forward()
{
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(15, LOW);
}

void left()
{
  digitalWrite(14, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(15, LOW);
}

void right()
{
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, HIGH);
}

void back()
{
  digitalWrite(14, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(15, HIGH);
}

void pause()
{
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
}
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(13, OUTPUT);
}

//FORWARD
BLYNK_WRITE(V1)
{
  int x = param.asInt();
  if (x == 1)
  {
    forward();
  }
  else
    pause();
}

//LEFT
BLYNK_WRITE(V2)
{
  int y = param.asInt();
  if (y == 1)
  {
    left();
  }
  else
    pause();
}

//RIGHT
BLYNK_WRITE(V3)
{
  int z = param.asInt();
  if (z == 1)
  {
    right();
  }
  else
    pause();
}

//BACK
BLYNK_WRITE(V4)
{
  int w = param.asInt();
  if (w == 1)
  {
    back();
  }
  else
    pause();
}

BLYNK_WRITE(V5)
{
  int v = param.asInt();
  if (v == 1)
  {
    pause();
  }
}
void loop()
{
  Blynk.run();
}
