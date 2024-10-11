#include "MapTransmitter.h"

MapTransmitter::MapTransmitter()
{
    _segmentsInfo[0][2] = 10;
    _segmentsInfo[1][2] = 20;
    _segmentsInfo[2][2] = 30;
    _segmentsInfo[3][2] = 10;
    _segmentsInfo[4][2] = 20;
    _segmentsInfo[5][2] = 30;
}

void MapTransmitter::readSegmentsFromMemory()
{
    uint8_t readValue = 0;
    uint16_t currentAddress = 0;

    for (uint8_t i = 0; i < 6; i++)
    {

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][0] = readValue;
        _delay_ms(5);

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][1] = readValue;
        _delay_ms(5);

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][2] = readValue;
        _delay_ms(5);
    }
}

bool MapTransmitter::isASegment(uint8_t x, uint8_t y)
{
    for (uint8_t i = 0; i < 6; i++)
    {
        if (x == _segmentsInfo[i][2] + RECTANGLE_2_X_OFFSET)
        {
            if (_segmentsInfo[i][0] == 1 && y <= RECTANGLE_2_Y_OFFSET + _segmentsInfo[i][1])
            {
                return true;
            }
            else if (_segmentsInfo[i][0] == 2)
            {
                int tapeMidpointY = RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT / 2;
                int bottomY = RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT - 1;

                if (y >= tapeMidpointY && y <= bottomY)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void MapTransmitter::transmitMap()
{
    readSegmentsFromMemory();
    for (uint8_t i = 0; i < FRAME_WIDTH; ++i) {
        _transmitter.transmit(' ');
    }
    _transmitter.transmit(newline); 

    _transmitter.transmit(frameTopLeftCorner);

    for (uint8_t i = 0; i < FRAME_WIDTH - 2; ++i)
    {
        _transmitter.transmit(frameHorizontal);
    }

    _transmitter.transmit(frameTopRightCorner);
    _transmitter.transmit(newline);

    for (uint8_t i = 0; i < FRAME_HEIGHT - 2; ++i)
    {
        _transmitter.transmit(frameVertical);

        for (uint8_t j = 0; j < FRAME_WIDTH - 2; ++j)
        {
            if (i == FRAME_HEIGHT / 2 && j >= RECTANGLE_2_X_OFFSET - 7 && j < RECTANGLE_2_X_OFFSET - 9 + 9)
            {
                _transmitter.transmit(tapeHorizontal);
            }
            else if (j == 5 && i > FRAME_HEIGHT / 8 && i < 7 * FRAME_HEIGHT / 8)
            {
                _transmitter.transmit(boxVertical);
            }
            else if (j == FRAME_WIDTH / 3 && i > FRAME_HEIGHT / 8 && i < 7 * FRAME_HEIGHT / 8)
            {
                if (i == FRAME_HEIGHT / 2 || i == FRAME_HEIGHT / 2 - 1)
                {
                    _transmitter.transmit(' ');
                }
                else
                {
                    _transmitter.transmit(boxVertical);
                }
            }
            else if (i == FRAME_HEIGHT / 8 && j >= 5 && j <= FRAME_WIDTH / 3)
            {
                if (j == 5)
                {
                    _transmitter.transmit(boxTopLeftCorner);
                }
                else if (j == FRAME_WIDTH / 3)
                {
                    _transmitter.transmit(boxTopRightCorner);
                }
                else
                {
                    _transmitter.transmit(boxHorizontal);
                }
            }
            else if (i == 7 * FRAME_HEIGHT / 8 && j >= 5 && j <= FRAME_WIDTH / 3)
            {
                if (j == 5)
                {
                    _transmitter.transmit(boxBottomLeftCorner);
                }
                else if (j == FRAME_WIDTH / 3)
                {
                    _transmitter.transmit(boxBottomRightCorner);
                }
                else
                {
                    _transmitter.transmit(boxHorizontal);
                }
            }
            else if ((i == RECTANGLE_2_Y_OFFSET || i == RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT - 1) && (j >= RECTANGLE_2_X_OFFSET && j < RECTANGLE_2_X_OFFSET + TAPE_WIDTH))
            {
                if (j == RECTANGLE_2_X_OFFSET)
                {
                    if (i == RECTANGLE_2_Y_OFFSET)
                    {
                        _transmitter.transmit(tapeTopLeftCorner);
                    }
                    else if (i == RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT - 1)
                    {
                        _transmitter.transmit(tapeBottomLeftCorner);
                    }
                }
                else if (j == RECTANGLE_2_X_OFFSET + TAPE_WIDTH - 1)
                {
                    if (i == RECTANGLE_2_Y_OFFSET)
                    {
                        _transmitter.transmit(tapeTopRightCorner);
                    }
                    else if (i == RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT - 1)
                    {
                        _transmitter.transmit(tapeBottomRightCorner);
                    }
                }
                else
                {
                    _transmitter.transmit(tapeHorizontal);
                }
            }
            else if ((j == RECTANGLE_2_X_OFFSET || j == RECTANGLE_2_X_OFFSET + TAPE_WIDTH - 1) && (i > RECTANGLE_2_Y_OFFSET && i < RECTANGLE_2_Y_OFFSET + TAPE_HEIGHT - 1))
            {
                _transmitter.transmit(tapeVertical);
            }
            else if (((i > RECTANGLE_2_Y_OFFSET && i < 20) && ((j == RECTANGLE_2_X_OFFSET || j == RECTANGLE_2_X_OFFSET + TAPE_WIDTH - 1))) || (isASegment(j, i) && (i > RECTANGLE_2_Y_OFFSET && i < 20)))
            {
                _transmitter.transmit(tapeVertical);
            }
            else
            {
                _transmitter.transmit(' ');
            }
        }

        _transmitter.transmit(frameVertical);
        _transmitter.transmit(newline);
    }

    _transmitter.transmit(frameBottomLeftCorner);

    for (uint8_t i = 0; i < FRAME_WIDTH - 2; ++i)
    {
        _transmitter.transmit(frameHorizontal);
    }

    _transmitter.transmit(frameBottomRightCorner);
    _transmitter.transmit(newline);
}
