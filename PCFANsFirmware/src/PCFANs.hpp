#ifndef PCFANS_H_
#define PCFANS_H_

/*
    Libreria che gestisce il funzionamento delle ventole per PC utilizzate
    per stabilizzare la temperatura interna al Maslow Control Box
*/

// Velocità di rotatazione minima della ventola perchè si muova
#define FAN_MIN_SPEED       300 // da misurare con laser
// Velocità di rotatazione di default della ventola (50%)
#define FAN_DEAFULT_SPEED   300 // medà di FAN_MAX_SPEED
// Velocità di rotatazione massima della ventola (100%)
#define FAN_MAX_SPEED       300 // da misurare con laser
// Modo di funzionamento automatico della ventola
#define FAN_AUTO_MODE       1
// Modo di funzionamento manuale della ventola
#define FAN_MANUAL_MODE     2

// La dichiarazione delle funzioni non è necessaria nel file .ino

/*
 *    Funzione che imposta i parametri di inizializzazione della ventola
 */
void PCFANSetup( int nGate );

/*
 *    Funzione che imposta la modalità di funzionamento e la velocità di rotazione della ventola
 *    La velocità è espressa in % (0-100)
 */
void PCFANRotate( int nGate, int nMode = FAN_MANUAL_MODE, int nSpeed = FAN_DEAFULT_SPEED );

/*
 *    Funzione che ferma la ventola
 */
void PCFANStop( int nGate );

#endif
