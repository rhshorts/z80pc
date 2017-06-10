// Z80 Interface
// Created Saturday 10th June 2017

//// 10-06-17
// Defined connections
// Created contructor
// Created MemHigh() to set and get high address bus
// Created MemLow()  to set and get low address bus
// Created Data()  to set and get data bus

//// Z80 Board connection layout
//     Top Row ||    VCC    A10     A9     A8     A7     A6     A5     A4     A3     A2     A1     A0   RFSH     M1  RESET BUSREQ   WAIT BUSACK     WR     RD  
//  Bottom Row ||    A11    A12    A13    A14    A15    CLK     D4     D3     D5     D6     D2     D7     D0     D1    INT    NMI   HALT   MREQ   IORQ    GND

//// Arduino Connections to Z80
// Address Bus (Low)
// PIN    ||   D29,    D28,    D27,    D26,    D25,    D24,    D23,    D22
// Port A ||   PA7,    PA6,    PA5,    PA4,    PA3,    PA2,    PA1,    PA0
// Z80    ||    A7,     A6,     A5,     A4,     A3,     A2,     A1,     A0

// Address Bus (High) 
// PIN    ||   D30,    D31,    D32,    D33,    D34,    D35,    D36,    D37
// Port C ||   PC7,    PC6,    PC5,    PC4,    PC3,    PC2,    PC1,    PC0
// Z80    ||   A15,    A14,    A13,    A12,    A11,    A10,     A9,     A8

// Data Bus (High) 
// PIN    ||   D42,    D43,    D44,    D45,    D46,    D47,    D48,    D49
// Port L ||   PL7,    PL6,    PL5,    PL4,    PL3,    PL2,    PL1,    PL0
// Z80    ||    D7,     D6,     D5,     D4,     D3,     D2,     D1,     D0

// Clock
// PIN    ||   N/A,    N/A,     D3,     D2,     D5,    N/A,     D1,     D0    
// Port E ||   PE7,    PE6,    PE5,    PE4,    PE3,    PE2,    PE1,    PE0
// Z80    ||                           CLK

// Control Bus lines
// PIN    ||    A7,     A6,     A5,     A4,     A3,     A2,     A1,     A0
// Port F ||   PF7,    PF6,    PF5,    PF4,    PF3,    PF2,    PF1,    PF0
// Z80    ||    RD,     WR, BUSACK,   IORQ,   MREQ,   WAIT,   HALT,     M1

// PIN    ||   A15,    A14,    A13,    A12,    A11,    A10,     A9,     A8
// Port K ||   PK7,    PK6,    PK5,    PK4,    PK3,    PK2,    PK1,    PK0
// Z80    ||                                   NMI,    INT, BUSREQ,  RESET

#ifndef   Z80Interface_h
#define   Z80Interface_h

#include "Arduino.h"

class Z80Interface {
  public:
                Z80Interface();
                
  inline byte   MemHigh()                         { DDRC = B00000000; return PINC;}
  inline void   MemHigh( byte hAddr)              { DDRC = B11111111; PORTC = hAddr;}
  
  inline byte   MemLow()                          { DDRA = B00000000; return PINA;}
  inline void   MemLow( byte lAddr)               { DDRA = B11111111; PORTA = lAddr;}
  
  inline byte   Data()                            { DDRL = B00000000; return PINL;}
  inline void   Data( byte data)                  { DDRL = B11111111; PORTL = data;}
  
  private:
};

#endif    // Z80Interface_h

