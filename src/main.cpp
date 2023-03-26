#include <Arduino.h>
#include <script.h>

void setup() {
  Serial.begin(115200);
}

void loop(){
  SCRIPT::run(SCR::TEST);

  return;
}