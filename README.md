# arduino-rf-neopixel

Both the WORKING_RemoteControlWithInterrupt.ino and WORKING_strandtest.ino files are working, so we know that the neopoixel works independently from the remote and the remote works independently from the neopixel (the wiring is right).

However, when we combine the two and try to create an if statement using the value (current_rx) that Serial prints (which looks like '1 0 0 1' with the "\n" and " "), we have no luck. I've tried a lot of combinations of the if statement, so I have a feeling I'm probably writing it wrong.

      if (current_rx == 1001) {
        pixels.setPixelColor(0, pixels.Color(0, 150, 0));
        pixels.show();
        delay(delayval);
      }

Do you have any insight?
