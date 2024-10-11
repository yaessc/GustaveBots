#define F_CPU 8000000UL

#include "memoire_24.h"
#include "can.h"
#include "Robot.h"
Robot robot1;
enum class Robot1States
{
    INIT,
    STANDBY,
    IR_RECEPTION,
    RS232_TRANSMISSION,
};

ISR(INT0_vect)
{

    _delay_ms(30);

    if (PIND & robot1.BUTTON1_MASK)
        robot1.gButton1Pressed = true;
    else
        robot1.gButton1Pressed = false;
    EIFR |= (1 << INTF0);
}

void initialisation(void)
{
    cli();
    robot1.interruptEnableButton1();
    robot1.interruptAnyEdgeButton1();
    sei();
}

ISR(TIMER1_COMPA_vect)
{
    robot1.turnOnLedGreen();
    _delay_ms(50);
    robot1.turnOffLed();
}

void blinkLedInterrupt()
{
    DDRD |= (1 << PD4) | (1 << PD5);
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
    OCR1A = (8000000 / 1024 / 5) - 1;
    TIMSK1 |= (1 << OCIE1A);
}
void runCycle()
{
    Robot1States currentState = Robot1States::INIT;
    while (true)
    {
        switch (currentState)
        {
        case Robot1States::INIT:
            robot1.stopNote();
            robot1.moveToCenter();
            robot1.faceExit();
            currentState = Robot1States::STANDBY;
            break;

        case Robot1States::STANDBY:
            robot1.turnOnLedRed();
            if (robot1.gButton1Pressed)
            {
                for (uint8_t i = 0; i < 3; i++)
                {
                    robot1.playNote(45);
                    _delay_ms(50);
                    robot1.stopNote();
                    _delay_ms(50);
                }
                currentState = Robot1States::IR_RECEPTION;
            }
            break;

        case Robot1States::IR_RECEPTION:
            robot1.turnOffLed();
            robot1.playNote(80);
            _delay_ms(1000);
            robot1.stopNote();
            currentState = Robot1States::STANDBY;

            break;

        case Robot1States::RS232_TRANSMISSION:
            robot1.turnOnLedGreen();
            if (robot1.gButton1Pressed)
            {
                blinkLedInterrupt();
                robot1.transmitMap();
            }
            break;

        default:
            break;
        }
    }
}

int main()
{
    initialisation();
    runCycle();
}
