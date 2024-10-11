/*
 * Description: Classe permettant de dessiner une carte du parcours sur un terminal via transmission RS232 selon les informations récoltées par les 2 robots. 
 * Identifications matérielles : Broches PD2,PD3 ou PB2 en mode entrée et reliée au bouton poussoir                           
 */

/*
 * Description: Class used to draw a map of the course on a terminal via RS232 transmission according to the information collected by the 2 robots. 
 * Hardware identification: PD2, PD3 or PB2 pins in input mode and connected to the pushbutton.                           
 */



#pragma once

#include "Transmission.h"
#include "memoire_24.h"
#include <util/delay.h>

const int FRAME_WIDTH = 100;
const int FRAME_HEIGHT = 26;
const int TAPE_WIDTH = 50;
const int TAPE_HEIGHT = 15;

const char newline = '\n';
const char frameHorizontal[] = u8"\u2500";
const char frameVertical[] = u8"\u2502";
const char frameTopLeftCorner[] = u8"\u250C";
const char frameTopRightCorner[] = u8"\u2510";
const char frameBottomLeftCorner[] = u8"\u2514";
const char frameBottomRightCorner[] = u8"\u2518";

const char tapeHorizontal[] = u8"\u2550";
const char tapeVertical[] = u8"\u2551";
const char tapeTopLeftCorner[] = u8"\u2554";
const char tapeTopRightCorner[] = u8"\u2557";
const char tapeBottomLeftCorner[] = u8"\u255A";
const char tapeBottomRightCorner[] = u8"\u255D";

const char boxVertical[] = u8"\u2503";
const char boxHorizontal[] = u8"\u2501";
const char boxTopLeftCorner[] = u8"\u250F";
const char boxTopRightCorner[] = u8"\u2513";
const char boxBottomRightCorner[] = u8"\u251B";
const char boxBottomLeftCorner[] = u8"\u2517";

const int RECTANGLE_2_X_OFFSET = FRAME_WIDTH / 3 + 10;
const int RECTANGLE_2_Y_OFFSET = FRAME_HEIGHT / 5;

class MapTransmitter
{

private:
    Memoire24CXXX _memory;
    Transmission _transmitter;
    uint8_t _segmentsInfo[6][3];
    

public:
    MapTransmitter();
    void readSegmentsFromMemory();
    bool isASegment(uint8_t x, uint8_t y);
    void transmitMap();
};

