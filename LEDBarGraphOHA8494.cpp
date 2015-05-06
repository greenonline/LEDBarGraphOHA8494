/*
LEDBarGraphOHA8494.cpp - Library for the:
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

#include "Arduino.h"
#include "LEDBarGraphOHA8494.h"

uint8_t LEDBarGraphOHA8494::_columns[maxColumn];// = {alphanum_0, alphanum_1, alphanum_2, alphanum_3, alphanum_4, alphanum_5, alphanum_6, alphanum_7, alphanum_8, alphanum_9, alphanum_A, alphanum_b, alphanum_C, alphanum_d, alphanum_E, alphanum_F}; //for hexWrite()
uint8_t LEDBarGraphOHA8494::_rows[maxRow];// = {alphanum_0, alphanum_1, alphanum_2, alphanum_3, alphanum_4, alphanum_5, alphanum_6, alphanum_7, alphanum_8, alphanum_9}; //for decWrite()

//Default Constructor
LEDBarGraphOHA8494::LEDBarGraphOHA8494(void){
  init();
}


//Constructor for columns and rows
LEDBarGraphOHA8494::LEDBarGraphOHA8494(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7){
  init(column1, column2, column3, column4, column5, column6, column7, row1, row2, row3, row4, row5, row6, row7);
}

//Constructor for columns and rows and on and off values
LEDBarGraphOHA8494::LEDBarGraphOHA8494(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7, uint8_t onColumnValue, uint8_t offColumnValue, uint8_t onRowValue, uint8_t offRowValue){
  init(column1, column2, column3, column4, column5, column6, column7, row1, row2, row3, row4, row5, row6, row7, onColumnValue, offColumnValue, onRowValue, offRowValue);
}

//Initialiser called by default constructor
void LEDBarGraphOHA8494::init(void) {
  init(default_column1, default_column2, default_column3, default_column4, default_column5, default_column6, default_column7, default_row1, default_row2, default_row3, default_row4, default_row5, default_row6, default_row7);
}


//Initialiser called by constructor for columns and rows
void LEDBarGraphOHA8494::init(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7){
  init(column1, column2, column3, column4, column5, column6, column7, row1, row2, row3, row4, row5, row6, row7, default_onColumnValue, default_offColumnValue, default_onRowValue, default_offRowValue);
}

//Initialiser called by constructor for columns and rows and logical On Value and Off Value
void LEDBarGraphOHA8494::init(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4, uint8_t column5, uint8_t column6, uint8_t column7, uint8_t row1, uint8_t row2, uint8_t row3, uint8_t row4, uint8_t row5, uint8_t row6, uint8_t row7, uint8_t onColumnValue, uint8_t offColumnValue, uint8_t onRowValue, uint8_t offRowValue) {
//  _column1=column1;
//  _column2=column2;
//  _column3=column3;
//  _column4=column4;
//  _column5=column5;
//  _column6=column6;
//  _column7=column7;

  _columns[0]=column1;
  _columns[1]=column2;
  _columns[2]=column3;
  _columns[3]=column4;
  _columns[4]=column5;
  _columns[5]=column6;
  _columns[6]=column7;

//  _row1=row1;
//  _row2=row2;
//  _row3=row3;
//  _row4=row4;
//  _row5=row5;
//  _row6=row6;
//  _row7=row7;

  _rows[0]=row1;
  _rows[1]=row2;
  _rows[2]=row3;
  _rows[3]=row4;
  _rows[4]=row5;
  _rows[5]=row6;
  _rows[6]=row7;

  _onColumnValue=onColumnValue;
  _offColumnValue=offColumnValue;
  _onRowValue=onRowValue;
  _offRowValue=offRowValue;
}

// Default begin() method, to set the pins defined by the constructor to be outputs
void LEDBarGraphOHA8494::begin(void) {
//  pinMode(_column1, OUTPUT);
//  pinMode(_column2, OUTPUT);
//  pinMode(_column3, OUTPUT);
//  pinMode(_column4, OUTPUT);
//  pinMode(_column5, OUTPUT);
//  pinMode(_column6, OUTPUT);
//  pinMode(_column7, OUTPUT);

//  pinMode(_row1, OUTPUT);
//  pinMode(_row2, OUTPUT);
//  pinMode(_row3, OUTPUT);
//  pinMode(_row4, OUTPUT);
//  pinMode(_row5, OUTPUT);
//  pinMode(_row6, OUTPUT);
//  pinMode(_row7, OUTPUT);

  //Set all columns and bars to OUTPUT
  for (int current_column=0; current_column<maxColumn; current_column++) {
    pinMode(_columns[current_column], OUTPUT);
  }
  for (int currentRow=0; currentRow<maxRow; currentRow++) {
    pinMode(_rows[currentRow], OUTPUT);
  }
  //Turn off all columns and bars
  for (int currentColumn = 1; currentColumn <= maxColumn; currentColumn++)
    digitalWrite(_columns[currentColumn-1], _offColumnValue);
  for (int currentRow = 1; currentRow <= maxRow; currentRow++)
    digitalWrite(_rows[currentRow-1], _offRowValue);
}

// To light a segment, Column has to be LOW and Row has to be HIGH
// if row == 0 => entire column is off
void LEDBarGraphOHA8494::graphicWrite(int column, int row) {
  int currentRow = 0;
  // Perform sanity check on row and column
  // to avoid out of bounds array
  if ((column > 0 && column <= maxColumn) && (row > 0 && row <= maxRow)) {
	// Turn off unrequired columns
	for (int currentColumn = 1; currentColumn <= maxColumn; currentColumn++) {

// Only write _onColumnValue if column is currentColumn, else write _offColumnValue (using if)
//	  if (currentColumn == column) {
//		digitalWrite(_columns[column-1],_onColumnValue);
//		break;
//      } else {
//	    digitalWrite(_columns[currentColumn-1],_offColumnValue);
//      }

// Only write HIGH if column is currentColumn, else write off (using logic)
//	  digitalWrite(_columns[currentColumn-1],(currentColumn==column));

// Only write _onColumnValue if column is currentColumn, else write _offColumnValue (using XNOR)
// (XNOR)
// _onColumnValue   column==currentColumn   Output
//		0						0				1
//		0						1				0
//		1						0				0
//		1						1				1
	  digitalWrite(_columns[currentColumn-1],!((_onColumnValue || (currentColumn==column)) && !(_onColumnValue && (currentColumn==column))));
    }
//	// Turn on required column (but doesn't turn off previous column)
//	digitalWrite(_columns[column-1],_onColumnValue);
	// Turn on required bars
	for (currentRow = 1; currentRow <= row; currentRow++) {
	  digitalWrite(_rows[currentRow-1],_onRowValue);
	}
  }
  // Turn off the remaining bars
  // Note: It could be more efficient to have a "oldState" variable,
  // to remember if the bars are already off, so no need to turn
  // them off again. For example, if the previous graphic was set
  // to level 2 and the new in level 4, then no need to turn off 5,
  // 6 and 7 as they are already off. Conversely, if the oldState
  // was level 4 and the new is level 2, then only need to turn off 3 and 4.
  while (currentRow <= maxRow) {
	digitalWrite(_rows[currentRow-1], _offRowValue);
	currentRow++;
  }
}

// To light a segment, Column has to be LOW and Row has to be HIGH
// Does not turn off unrequired columns
/*void GraphicEqualiser::barWrite(int column, int row, int state) {
  // Perform sanity check on row and column
  // to avoid out of bounds array
  if ((column > 0 && column <= maxColumn) && (row > 0 && row <= maxRow)) {
	if (state) {
	  digitalWrite(_columns[column-1],_onColumnValue);
	  digitalWrite(_rows[row-1], _onRowValue);
    } else {
	  digitalWrite(_columns[column-1],_onColumnValue);
	  digitalWrite(_rows[row-1], _offRowValue);
	}
  }
}*/

// To light a segment, Column has to be LOW and Row has to be HIGH
// Turns off unrequired columns
void LEDBarGraphOHA8494::barWrite(int column, int row, int state) {
  // Perform sanity check on row and column
  // to avoid out of bounds array
  if ((column > 0 && column <= maxColumn) && (row > 0 && row <= maxRow)) {
	// Turn off unrequired columns
	for (int currentColumn = 1; currentColumn <= maxColumn; currentColumn++) {
	  digitalWrite(_columns[currentColumn-1],!((_onColumnValue || (currentColumn==column)) && !(_onColumnValue && (currentColumn==column))));
	}
	if (state) {
//	  digitalWrite(_columns[column-1],_onColumnValue);
	  digitalWrite(_rows[row-1], _onRowValue);
    } else {
//	  digitalWrite(_columns[column-1],_onColumnValue);
	  digitalWrite(_rows[row-1], _offRowValue);
	}
  }
}

void LEDBarGraphOHA8494::graphicBlankColumn(int column) {
  graphicWrite(column, 0);
}

void LEDBarGraphOHA8494::graphicBlankRow(int row) {
  graphicWrite(0, row);
}

void LEDBarGraphOHA8494::graphicBlankAll(void) {
  for(int row=1; row<maxRow; row++) {
    graphicWrite(0, row);
  }
}

void LEDBarGraphOHA8494::graphicFillColumn(int column) {
  graphicWrite(column, maxRow);
}

void LEDBarGraphOHA8494::graphicFillRow(int row) {
  graphicWrite(maxColumn, row);
}

void LEDBarGraphOHA8494::graphicFillAll(void) {
  for(int row=1; row<maxRow; row++) {
    graphicWrite(maxColumn, row);
  }
}

void LEDBarGraphOHA8494::graphicFlashColumn(int column, int totaldelay) {
  graphicBlankColumn(column);
  delay (totaldelay/2);
  graphicFillColumn(column);
  delay (totaldelay/2);
}

void LEDBarGraphOHA8494::graphicFlashRow(int row, int totaldelay) {
  graphicBlankRow(row);
  delay (totaldelay/2);
  graphicFillRow(row);
  delay (totaldelay/2);
}

void LEDBarGraphOHA8494::graphicFlashAll(int totaldelay) {
  graphicBlankAll();
  delay (totaldelay/2);
  graphicFillAll();
  delay (totaldelay/2);
}

