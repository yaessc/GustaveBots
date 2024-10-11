/*
 * Description: Classe permettant la gestion du mécanisme de débogage.
 * Identifications matérielles : Broches PD0 et PD1.
 */
#pragma once    
#include "Transmission.h"

#ifdef DEBUG
#define DEBUG_INIT Debug::debugInit()
#define DEBUG_MESSAGE(message) Debug::debugMessage(message)
#define DEBUG_MESSAGE_VALUE(message, value) Debug::debugMessageValue(message, value)
#else
#define DEBUG_INIT do {} while (0)
#define DEBUG_MESSAGE do {} while (0)
#define DEBUG_MESSAGE_VALUE do {} while (0)
#endif

class Debug
{
public:
    static void debugInit();
    static void debugMessage(const char message[]);
    static void debugMessageValue(const char message[], uint8_t value);
};
