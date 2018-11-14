#include "PCFANs.hpp"
//#include "ThermistorModule.hpp"
#include <Arduino.h>

/*
    Libreria che gestisce il funzionamento delle ventole per PC utilizzate
    per stabilizzare la temperatura interna al Maslow Control Box
*/

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
	int nRealSpeedValue = 0;

	// Distinguo fra funzionalità in modalità manuale e automatica
	switch ( nMode )
	{

		// Funzionamento automatico della ventola:
		// La velocità viene impostata automaticamente a seconda della temperatura
		// rilevata internamente al Maslow Control Box
		case FAN_AUTO_MODE:

			// Impostazione del valore della velocità a seconda della temperatura interna qui
			//ThermistorModuleGetTemp( 5 );
			analogWrite( nGate, nSpeed );
			break;

		// Funzionamento manuale della ventola:
		// La velocità viene impostata al valore in percentuale passato alla funzione (da 0 a 100)
		case FAN_MANUAL_MODE:

			// Conversione della velocità dal valore % passato al numero
			// intero da passare alla porta della ventola
			nRealSpeedValue = ( ( nSpeed * FAN_MAX_SPEED ) / 100 );
			analogWrite( nGate, nRealSpeedValue );
			break;

		default:
			break;
	}
}

/*
 *    Funzione che ferma la ventola
 */
void PCFANStop( int nGate )
{
	digitalWrite( nGate, LOW );
}
