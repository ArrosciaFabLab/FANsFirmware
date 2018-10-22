#ifndef PCFANS_H_
#define PCFANS_H_

/*

*/

// Velocità di rotatazione di default della ventola
#define FAN_DEAFULT_SPEED    300
// Modo di funzionamento automatico della ventola
#define FAN_AUTO_MODE        1
// Modo di funzionamento automatico della ventola
#define FAN_MANUAL_MODE      2

// La dichiarazione delle funzioni non è necessaria nel file .ino

/*
 *    Funzione che imposta i parametri di inizializzazione della ventola
 */
void PCFANSetup( int nGate );

/*
 *    Funzione che imposta la modalità di funzionamento e la velocità di rotazione della ventola
 */
void PCFANRotate( int nGate, int nMode = FAN_MANUAL_MODE, int nSpeed = FAN_DEAFULT_SPEED );

/*
 *    Funzione che ferma la ventola
 */
void PCFANStop( int nGate );

#endif
