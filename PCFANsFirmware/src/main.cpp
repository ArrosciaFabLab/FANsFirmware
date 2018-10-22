#include "PCFANs.hpp"   // Libreria di gestione delle ventole
#include <Arduino.h>    // Su un file .ino non è necessario

/*
Schetch di test sulle ventole per PC
*/

// PIN a cui è collegato il cavo + che alimenta la ventola 1
#define FAN1_PIN             10
// PIN a cui è collegato il cavo + che alimenta la ventola 2
#define FAN2_PIN             11

// La dichiarazione delle funzioni non è necessaria nel file .ino

void DebugSetup();

// Setup inizale di Arduino
void setup()
{
    // Inizializzo il logging sul monitor seriale
    DebugSetup();

    Serial.println( "--- Sto inizializzando la scheda Arduino" );

	// Configurazione iniziale delle ventole
    PCFANSetup( FAN1_PIN );
	PCFANSetup( FAN2_PIN );

    Serial.println( "--- Ho finito di inizializzare la scheda Arduino" );
}

// Loop standard di Arduino
void loop()
{
    Serial.println( "--- Inizio il loop principale della scheda Arduino" );

    Serial.println( "Accendo ventola 1 alla velocità di defalt" );

    // Accendo la ventola 1 alla velocità di defalt
    PCFANRotate( FAN1_PIN );

	delay( 10000 );

    Serial.println( "Spengo la ventola 1" );

    // Spengo la ventola 1
	PCFANStop( FAN1_PIN );

	Serial.println( "Accendo ventola 2 alla velocità definita" );

    // Accendo la ventola 1 alla velocità definita
    PCFANRotate( FAN2_PIN, FAN_MANUAL_MODE, 1000 );

	delay( 10000 );

    Serial.println( "Spengo la ventola 2" );

    // Spengo la ventola 2
	PCFANStop( FAN2_PIN );
}

void DebugSetup()
{
    Serial.begin( 9600 );
    Serial.println( "Ho inizializzato il debug su monitor seriale");
}
