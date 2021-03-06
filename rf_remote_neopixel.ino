/*
   \brief Get data from wireless remote controller asynchronously (interrupts)

   This example is using the trigger signal from the remote controller to
   asynchronously launch a function every time a data is received.

   \author Quentin Comte-Gaz <quentin@comte-gaz.com>
   \date 1 July June 2016
   \license MIT License (contact me if too restrictive)
   \copyright Copyright (c) 2016 Quentin Comte-Gaz
   \version 1.0
*/

#include <WirelessRemoteController.h>
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 13

#define PIXEL_COUNT 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500;

// Create wireless remote controller instance with D3, D4, D5, D6 pins as data pins
WirelessRemoteController remote_controller(2, 3, 4, 5);


void receiveFromRemoteController()
{
  bool current_rx[4];
  if (remote_controller.getCurrentValue(current_rx)) {
    //    Serial.print("Data received: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(current_rx[i]);


      if (current_rx == 1001) {
        pixels.setPixelColor(0, pixels.Color(0, 150, 0));
        pixels.show();
        delay(delayval);
      }

      if (current_rx == 1100) {
        pixels.setPixelColor(0, pixels.Color(150, 150, 0));
        pixels.show();
        delay(delayval);
      }

      if (current_rx == 1000) {
        pixels.setPixelColor(0, pixels.Color(150, 150, 200));
        pixels.show();
        delay(delayval);
      }

      if (current_rx == "1010") {
        pixels.setPixelColor(0, pixels.Color(100, 0, 0));
        pixels.show();
        delay(delayval);
      }
            Serial.print(" ");
    }
        Serial.print("\n");


  } else {
    Serial.print("No data received (!!should not happen!!)\n");
  }
}

void setup(void)
{

  Serial.begin(9600);

  // Trigger interrupt by putting D2 pin as DT remote controller pin (trigger)
  remote_controller.addTrigger(2, receiveFromRemoteController);

  Serial.print("Data sent from remote controller will be printed when received.\n");
  pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'
}

void loop()
{

}
