#include "PCFANs.hpp"   // Libreria di gestione delle ventole
#include <Arduino.h>    // Su un file .ino non è necessario

/*
Schetch di test sulle ventole per PC di input e ourput
*/

// PIN a cui è collegato il cavo + che alimenta la ventola 1
#define INPUT_FAN_PIN             10
// PIN a cui è collegato il cavo + che alimenta la ventola 2
#define OUTPUT_FAN_PIN            11

// La dichiarazione delle funzioni non è necessaria nel file .ino

void DebugSetup();

// Setup inizale di Arduino
void setup()
{
    // Inizializzo il logging sul monitor seriale
    DebugSetup();

    Serial.println( "--- Sto inizializzando la scheda Arduino" );

	// Configurazione iniziale delle ventole
    PCFANSetup( INPUT_FAN_PIN );
	PCFANSetup( OUTPUT_FAN_PIN );

    Serial.println( "--- Ho finito di inizializzare la scheda Arduino" );
}

// Loop standard di Arduino
void loop()
{
    Serial.println( "--- Inizio il loop principale della scheda Arduino" );

    Serial.println( "Accendo ventola di input alla velocità di defalt" );

    // Accendo la ventola di input alla velocità di defalt
    PCFANRotate( INPUT_FAN_PIN );

	delay( 10000 );

    Serial.println( "Spengo la ventola di input" );

    // Spengo la ventola di input
	PCFANStop( INPUT_FAN_PIN );

	Serial.println( "Accendo ventola di output alla velocità definita" );

    // Accendo la ventola di output alla velocità definita
    PCFANRotate( OUTPUT_FAN_PIN, FAN_MANUAL_MODE, 1000 );

	delay( 10000 );

    Serial.println( "Spengo la ventola di output" );

    // Spengo la ventola di output
	PCFANStop( OUTPUT_FAN_PIN );

    Serial.println( "Accendo ventola di input alla velocità di defalt" );

    // Accendo la ventola di input alla velocità impostata automaticamente
    // a seconda della temperatura rilevata all'interno del Maslow Control Box
    PCFANRotate( INPUT_FAN_PIN, FAN_AUTO_MODE );

	delay( 10000 );

    Serial.println( "Spengo la ventola di input" );

    // Spengo la ventola di input
	PCFANStop( INPUT_FAN_PIN );
}

void DebugSetup()
{
    Serial.begin( 9600 );
    Serial.println( "Ho inizializzato il debug su monitor seriale");
}
