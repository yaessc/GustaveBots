#include "Debug.h"

void Debug::debugInit(){
    Transmission::initialisation();
}

void Debug::debugMessage(const char message[]) {
    Transmission::transmitMessage(message);
}

void Debug::debugMessageValue(const char message[], uint8_t value) {
    Transmission::transmitMessageValue(message, value);
}
