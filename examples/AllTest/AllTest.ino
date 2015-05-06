/*
AllTest.ino

Tests the LEDBarGraphOHA8494 library

Demonstrates the methods:
  begin();
  graphicWrite(int, int);
  barWrite(int, int, int);

If you're unsure which pins to use to connect the graphic equaliser display to on your
Arduino model, check the readme that came with this package or the documentation 
at https://github.com/greenonline/

This example code is in the public domain.

Created by Mark G. Jenkins March 13 2015
Modified 5 Apr 2015
Released into the public domain.
-------------------------------------------------------------------------------
Copyright (c) 2015, Greenonline, coded by Mark Graham Jenkins.
http://greenonline.co.uk

LEDBarGraphOHA8494 Library is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

LEDBarGraphOHA8494 Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This file needs the following Libraries:

    LEDBarGraphOHA8494
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Special Thanks:
Bangkok Food stalls and Thai Beer
Ban Mo district for the inspiration.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Version:
0.1 Rudimentary Direct Draw
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BugList of the current version:

Please report any!
 */
 
#include "LEDBarGraphOHA8494.h"

#define defaultDelay 500
#define on 1
#define off 0

LEDBarGraphOHA8494 graphicEqualiser;

// the setup function runs once when you press reset or power the board
void setup() {
  graphicEqualiser.begin(); // set the (default) pins to output
}

// the loop function runs over and over again forever
void loop() {

  // Light each bar and then switch off and move to next bar
  for (int currentColumn = 1; currentColumn <= maxColumn; currentColumn++)
    for (int currentRow = 1; currentRow <= maxRow; currentRow++) {
      graphicEqualiser.barWrite(currentColumn, currentRow, on);
      delay(defaultDelay);
      graphicEqualiser.barWrite(currentColumn, currentRow, off);
      delay(defaultDelay);      
    }

  // Grow column and then reduce and move to next column
  for (int currentColumn = 1; currentColumn <= maxColumn; currentColumn++) {
    for (int currentRow = 1; currentRow <= maxRow; currentRow++) {
      graphicEqualiser.graphicWrite(currentColumn, currentRow);
      delay(defaultDelay);
    }
    for (int currentRow = maxRow-1; currentRow >= 0; currentRow--) {
      graphicEqualiser.graphicWrite(currentColumn, currentRow);
      delay(defaultDelay);      
    }
  }
}