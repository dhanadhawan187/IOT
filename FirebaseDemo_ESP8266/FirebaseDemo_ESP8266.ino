//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "fir-bba82.firebaseio.com"
#define FIREBASE_AUTH "z3hlnCc5HyDedrhHiKyG7fT8iSjbEtcVFr3wFAaB"
#define WIFI_SSID "ASUS_X00PD"
#define WIFI_PASSWORD "123456789"

void setup() {
    pinMode(D0, OUTPUT);
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("LED","1");
}


void loop() {
String s=Firebase.getString("LED");
Serial.print(s);
if(s=="1")
{
  digitalWrite(D0,HIGH);
  Serial.print("high");
}
else
{
  digitalWrite(D0,LOW);
   Serial.print("low");
}

  
}
