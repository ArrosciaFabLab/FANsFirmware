#include "PCFANs.hpp"
#include <Arduino.h>

/*
 *    Funzione che imposta i parametri di inizializzazione della ventola
 */
void PCFANSetup( int nGate )
{
	// Imposto il PIN di uscita da Arduino a cui è collegato il
	// cavo di alimentazione + in ingresso alla ventola
	pinMode( nGate, OUTPUT );

	// Di default la ventola è spenta
	PCFANStop( nGate );
}

/*
 *    Funzione che imposta la modalità di funzionamento e la velocità di rotazione della ventola
 */
void PCFANRotate( int nGate, int nMode, int nSpeed )
{
	analogWrite( nGate, nSpeed );
}

/*
 *    Funzione che ferma la ventola
 */
void PCFANStop( int nGate )
{
	digitalWrite( nGate, LOW );
}
