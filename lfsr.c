#include "lfsr.h"						//we use lfsr

//from Maximum appnote 4400
/*
Table 3. Sample Masks and First Four Values Output after Initializing LFSR with One
Degree Typical Mask First Four Values in LFSR After Consecutive Shifts
3 0x5 0x5 0x7 0x6 0x3
4 0x9 0x9 0xD 0xF 0xE
5 0x1D 0x1D 0x13 0x14 0xA
6 0x36 0x36 0x1B 0x3B 0x2B
7 0x69 0x69 0x5D 0x47 0x4A
8 0xA6 0xA6 0x53 0x8F 0xE1
9 0x17C 0x17C 0xBE 0x5F 0x153
10 0x32D 0x32D 0x2BB 0x270 0x138
11 0x4F2 0x4F2 0x279 0x5CE 0x2E7
12 0xD34 0xD34 0x69A 0x34D 0xC92
13 0x1349 0x1349 0x1AED 0x1E3F 0x1C56
14 0x2532 0x2532 0x1299 0x2C7E 0x163F
15 0x6699 0x6699 0x55D5 0x4C73 0x40A0
16 0xD295 0xD295 0xBBDF 0x8F7A 0x47BD
17 0x12933 0x12933 0x1BDAA 0xDED5 0x14659
18 0x2C93E 0x2C93E 0x1649F 0x27B71 0x3F486
19 0x593CA 0x593CA 0x2C9E5 0x4F738 0x27B9C
20 0xAFF95 0xAFF95 0xF805F 0xD3FBA 0x69FDD
21 0x12B6BC 0x12B6BC 0x95B5E 0x4ADAF 0x10E06B
22 0x2E652E 0x2E652E 0x173297 0x25FC65 0x3C9B1C
23 0x5373D6 0x5373D6 0x29B9EB 0x47AF23 0x70A447
24 0x9CCDAE 0x9CCDAE 0x4E66D7 0xBBFEC5 0xC132CC
25 0x12BA74D 0x12BA74D 0x1BE74EB 0x1F49D38 0xFA4E9C
26 0x36CD5A7 0x36CD5A7 0x2DABF74 0x16D5FBA 0xB6AFDD
27 0x4E5D793 0x4E5D793 0x6973C5A 0x34B9E2D 0x5401885
28 0xF5CDE95 0xF5CDE95 0x8F2B1DF 0xB25867A 0x592C33D
29 0x1A4E6FF2 0x1A4E6FF2 0xD2737F9 0x1CDDF40E 0xE6EFA07
30 0x29D1E9EB 0x29D1E9EB 0x3D391D1E 0x1E9C8E8F 0x269FAEAC
31 0x7A5BC2E3 0x7A5BC2E3 0x47762392 0x23BB11C9 0x6B864A07
32 0xB4BCD35C 0xB4BCD35C 0x5A5E69AE 0x2D2F34D7 0xA22B4937
*/

//lfsr32-32bit
//galois algorithm
char lfsr32(void) {
    static uint32_t lfsr = 0x5429ace1;          //initial value
    char lsb = lfsr & 0x01;                 //least significant bit
    //static uint32_t period = 0;           //to test period
    
    lfsr = lfsr >> 1;
    if (lsb) lfsr ^= 0xb4bcd35c;            //x16+x14+x13+x11+1. other options are: 0x7A5BC2E3, 0x29D1E9EB, 0x1A4E6FF2, 
    //period+=1; while (lfsr == 0x5429ace1) continue;
    return lsb;
}

//lfsr16-16bit
//galois algorithm
char lfsr16(void) {
    static uint16_t lfsr = 0xace1;          //initial value
    char lsb = lfsr & 0x01;                 //least significant bit
    //static uint32_t period = 0;             //to test period
    
    lfsr = lfsr >> 1;
    if (lsb) lfsr ^= 0xb400;                //x16+x14+x13+x11+1
    //period+=1; while (lfsr == 0xace1) continue;
    return lsb;
}

//lfsr8-8bit
//galois algorithm
char lfsr8(void) {
    static uint8_t lfsr = 0xac;             //initial value
    char lsb = lfsr & 0x01;                 //least significant bit
    //static uint32_t period = 0;           //to test period
    
    lfsr = lfsr >> 1;
    if (lsb) lfsr ^= 0x2d;                  //x6+x4+x3+x1+1. other options are 0x21, 0x30, 0x33, 0x39, 0x36, 
    //period+=1; while (lfsr == 0xac) continue; 
    return lsb;
}
