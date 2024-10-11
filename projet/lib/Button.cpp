#include "Button.h"

Button::Button(uint8_t nInt) : _nInt(nInt)
{
    switch (_nInt)
    {
    case 0:
        DDRD &= ~(1 << PD2);
        break;
    case 1:
        DDRD &= ~(1 << PD3);
        break;
    case 2:
        DDRB &= ~(1 << PB2);
        break;
    default:
        break;
    }
}

void Button::interruptReset()
{
    EICRA &= ~(1 << ISC00);
    EICRA &= ~(1 << ISC01);
}

void Button::interruptAnyEdge()
{
    interruptReset();
    EICRA |= (0 << ISC01) | (1 << ISC00);
}

void Button::interruptRisingEdge()
{
    interruptReset();
    EICRA |= (1 << ISC00) | (1 << ISC01);
}

void Button::interruptFallingEdge()
{
    interruptReset();
    EICRA |= (1 << ISC01) | (0 << ISC00);
}

void Button::interruptEnable()
{
    EIMSK |= (1 << _nInt);
}

void Button::interruptDisable()
{
    EIMSK &= ~(1 << _nInt);
}
