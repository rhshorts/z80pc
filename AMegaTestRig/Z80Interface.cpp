// Z80 Interface
// Created Saturday 10th June 2017

//// 10-06-17
// Defined contructor
// Updated contructor: Set Arduiono pins connected to the Z80 address bus to input

#ifndef   Z80Interface_cpp
#define   Z80Interface_cpp

#include  "Z80Interface.h"

            Z80Interface::Z80Interface() {
  DDRC = B00000000;                             // Set pins connected to the higher byte of the Z80 address bus to input
  DDRA = B00000000;                             // Set pins connected to the lower byte of the Z80 address bus to input

  DDRL = B11111111;                             // Set pins connected to Z80 data bus to output
  PORTL = 0x00;                                 // Sets the data bus to 0x00
}

#endif    // Z80Interface_cpp
