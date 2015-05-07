        *** LED Bar Graph OHA 8494 Library ***
       ========================================

        *** Readme ***
       ================

       Version : 0.5.0

Brief
=====

This is an Arduino Library for the LED Bar Graph OHA 8494.

Introduction
============

One day, in March 2015, whilst shopping for Arduino bits and pieces in Ban Mo, an electronics street market in BKK, I came across a cambodian couple selling various recalimed electronic bits and pieces. In teir collection was a display from what was, I presume, a graphic equaliser. When I enquired as to the price, the gentleman required 20 baht, but then his partner/girlfriend/wife corrected him and said that they wanted 10 baht. I purchased the LED Bar Graph display, took it home, and eventually realised that no specific libraries existed for this device.  So I promptly set about writing my own sketch, which then evolved into an Arduino Library that was developed over the course of a couple of weeks. That library is the LEDBarGraphOHA8494. 

Disclaimer
==========

No responsibility is taken for the usage of this code (or additional material such as this document). Most of the code has been tested. However, some parts may not be working, and some information herein may not be correct. Updates and backward/-forward compatibility are not guaranteed. Use it at your own risk. This library is provided free of charge for non-commercial purposes.

Synopsis
========

When the class is instantiated using the defaults then it will work with the OHA 8494 LED Bar Graph. The private members, _onColumnValue and _onRowValue, are HIGH and LOW espectively for the segments of these displays (and conversely the associated private members, _offColumnValue and _offRowValue, is HIGH).

The public methods supplied include the usual Arduino, begin() and write(), methods. A simple set of the methods is all that is required in order to get the library up and running with your display (constructor, begin and write).

Library Contents
================

    LEDBarGraphOHA8494.h
    LEDBarGraphOHA8494.cpp
    keywords.txt
    SevenSegmentMaps.h
    examples/AllTest/AllTest.ino
    examples/BarTest/BarTest.ino
    examples/GraphTest/GraphTest.ino
    examples/SpectrumBarTest/SpectrumBarTest.ino
    examples/SpectrumGraphTest/SpectrumGraphTest.ino
    documentation/Readme.txt
    documentation/QuickStart.txt
    documentation/MethodReference.txt
    documentation/photos/breadboard01.jpg
    documentation/photos/breadboard02.jpg
    documentation/photos/LEDBarGraph_Back.jpg
    documentation/photos/LEDBarGraph_Front.jpg
    documentation/schematics/LEDBarGraph_Nano_bb.jpg
    documentation/schematics/LEDBarGraph_Nano.fzz

Default Pinout
==============

    Arduino   Bar Graph pin

    pin 2  -> column 1
    pin 3  -> column 2
    pin 4  -> column 3
    pin 5  -> column 4
    pin 6  -> column 5
    pin 7  -> column 6
    pin 8  -> column 7
    pin 9  -> row 1
    pin 10 -> row 2
    pin 11 -> row 3
    pin 12 -> row 4
    pin 13 -> row 5
    pin 14 -> row 6
    pin 15 -> row 7

Naming Conventions/Terminology
==============================

The OHA8494 has fourteen connectors, seven of which are rows (along the bottom of the display) and the other seven are columns (along the right hand side of the display).

Method Reference
================

The file MethodReference.txt is a simplified form of the header file, LEDBarGraphOHA8494.h, and expands upon the method descriptions below.

Constructor Methods
===================

There are three various overridden constructors. Please note that all constructors configure the pins for both columns and rows. Here is a list of the constructor types:

Default
-------

Sets up the columns and rows using the default pins D2 through to D15, with D2 to D8 driving the columns and D9 to D15 driving the rows.

Columns and Rows
----------------

Sets up both the columns and the rows with user defined pins.

Columns and Rows with their respective on and off values
--------------------------------------------------------

Sets up the columns and the rows with user defined pins and allows the user to specify the LED on state (using the parameter onValue) to LOW or HIGH, and the LED off state (using the parameter offValue) should be set to the complement of the onValue, i.e. if onValue is LOW, the offValue should be HIGH.

Begin Method
============

This method defines the assigned pins of the Arduino as OUTPUTs, and should be called from the setup() function in the Arduino sketch.

Write Methods
=============

These methods enable the user display a filled column to a specific height or just a specific bar within that column.

Effects Methods
===============

These methods provide various visual effects that may be employed on the LED bar graph, relating to columns, rows or the entire display (all segments). For example, various methods exist which:
  - graphicBlankAll() the display (all segments are switched off), or;
  - graphicFillAll() the display (all segments are switched on), or;
  - graphicFlashAll() the lit segments (all segments are alternately switched on and then after a specified delay switched off).

The best way to understand them is to experiment with each of them to see what they do. The blank(), fill() and flash() methods are the simplest to understand, and are probably the most useful. 

A delay parameter can also be used, which effectively specifies the speed of the effect, i.e. the delay between successive segments being illuminated.

Note: This delay is not the total delay, i.e. the total duration of the effect, but the delay between the actuating of the individual segments of the effect. So the total duration of the effect becomes equal to the delay multiplied by the number of segments used in the effect. So, the total duration of some effects may be longer than that of others. 

Example Sketches
================

Some examples have been include to familiarise the user with the various methods available. These focus on the areas outlined in the Methods sections.

Conclusion
==========

Please enjoy using this library. 


Known Issues
============

None
