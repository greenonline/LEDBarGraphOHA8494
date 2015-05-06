/*
LEDBarGraphOHA8494.h - Library for the:
						Graphic Equaliser LED display
Created by Mark G. Jenkins March 13 2015
Released into the public domain.
-------------------------------------------------------------------------------
Copyright (c) 2015, Greenonline, coded by Mark Graham Jenkins.

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

None
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

#ifndef LEDBarGraphOHA8494_h
#define LEDBarGraphOHA8494_h

#include "Arduino.h"

// Pin out: Column Segment Pin#
#define default_column1 2
#define default_column2 3
#define default_column3 4
#define default_column4 5
#define default_column5 6
#define default_column6 7
#define default_column7 8

// Pin out: Row Segment Pin#
#define default_row1 9
#define default_row2 10
#define default_row3 11
#define default_row4 12
#define default_row5 13
#define default_row6 14
#define default_row7 15

#define default_onColumnValue HIGH
#define default_offColumnValue LOW
#define default_onRowValue LOW
#define default_offRowValue HIGH

#define default_delay 500

#define maxColumn 7
#define maxRow 7

class LEDBarGraphOHA8494
{
    public:
      LEDBarGraphOHA8494();
      LEDBarGraphOHA8494(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7);
	  LEDBarGraphOHA8494(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7, uint8_t onColumnValue, uint8_t offColumnValue, uint8_t onRowValue, uint8_t offRowValue);

      void begin(void);

      void graphicWrite(int column, int row);
	  void barWrite(int column, int row, int state);

	  void graphicBlankColumn(int column);
	  void graphicBlankRow(int row);
	  void graphicBlankAll(void);

	  void graphicFillColumn(int column);
	  void graphicFillRow(int row);
	  void graphicFillAll(void);

	  void graphicFlashColumn(int column, int totaldelay);
	  void graphicFlashRow(int row, int totaldelay);
	  void graphicFlashAll(int totaldelay);


    private:
      void init(void);
      void init(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7);
      void init(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7, uint8_t onColumnValue, uint8_t offColumnValue, uint8_t onRowValue, uint8_t offRowValue);

	  // The Pins
	  // Columns
      uint8_t _column1;
      uint8_t _column2;
      uint8_t _column3;
      uint8_t _column4;
      uint8_t _column5;
      uint8_t _column6;
      uint8_t _column7;
	  static uint8_t _columns[maxColumn];

	  // Rows
      uint8_t _row1;
      uint8_t _row2;
      uint8_t _row3;
      uint8_t _row4;
      uint8_t _row5;
      uint8_t _row6;
      uint8_t _row7;
      static uint8_t _rows[maxRow];

      uint8_t _onColumnValue;
      uint8_t _offColumnValue;
      uint8_t _onRowValue;
      uint8_t _offRowValue;
};

#endif