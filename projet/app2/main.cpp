#include "Robot.h"

enum class Robot2States
{
    INIT,
    STANDBY,
    IR_TRANSMISSION,
    RS232_TRANSMISSION,
};

Robot robot2;

ISR(INT0_vect)
{

    _delay_ms(30);

    if (PIND & robot2.BUTTON2_MASK)
        robot2.gButton1Pressed = true;
    else
        robot2.gButton1Pressed = false;
    EIFR |= (1 << INTF0);
}

ISR(INT1_vect)
{

    _delay_ms(30);

    if (PIND & robot2.BUTTON2_MASK)
        robot2.gButton2Pressed = true;
    else
        robot2.gButton2Pressed = false;
    EIFR |= (1 << INTF1);
}

void initialisation(void)
{

    cli();
    robot2.interruptEnableButton1();
    robot2.interruptAnyEdgeButton1();
    robot2.interruptEnableButton2();
    robot2.interruptAnyEdgeButton2();

    sei();
}
ISR(TIMER1_COMPA_vect)
{
    robot2.turnOnLedGreen();
    _delay_ms(50);
    robot2.turnOffLed();
}

void BlinkLedInterrupt()
{
    DDRD |= (1 << PD4) | (1 << PD5);
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
    OCR1A = (8000000 / 1024 / 5) - 1;
    TIMSK1 |= (1 << OCIE1A);
}

void runCycle()
{
    Robot2States currentState = Robot2States::INIT;
    while (true)
    {
        switch (currentState)
        {
        case Robot2States::INIT:
            robot2.followLine();
            currentState = Robot2States::STANDBY;
            break;
        case Robot2States::STANDBY:
            robot2.turnOnLedRed();
            if (robot2.gButton1Pressed)
            {
                for (uint8_t i = 0; i < 3; i++)
                {
                    robot2.playNote(45);
                    _delay_ms(50);
                    robot2.stopNote();
                    _delay_ms(50);
                }
                currentState = Robot2States::IR_TRANSMISSION;
            }
            if (robot2.gButton2Pressed)
            {
                currentState = Robot2States::RS232_TRANSMISSION;
            }

            break;
        case Robot2States::IR_TRANSMISSION:
            robot2.turnOffLed();
            _delay_ms(2000);
            currentState = Robot2States::STANDBY;

            break;
        case Robot2States::RS232_TRANSMISSION:
            BlinkLedInterrupt();
            robot2.transmitMap();
            currentState = Robot2States::STANDBY;
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
