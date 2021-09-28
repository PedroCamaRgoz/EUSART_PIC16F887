#ifndef IHM_H
#define IHM_H

#include "lcd.h"
#include "eusart.h"
#include "keyboard.h"

struct
{
    void (* init)(void);
    void (* print)( const char * str );
    void (* printpos)( unsigned char lin, unsigned char col, const char * str );
    void (* printv)(  unsigned char lin, unsigned char col, int num, unsigned char tam );
    void (* clr)( void );
    unsigned char (* B0)( void );
    unsigned char (* B1)( void );
} print = { dispLCD_init, dispLCDstr, dispLCD, dispLCD_num, dispLCD_clr, dispLCD_B0, dispLCD_B1 };

struct 
{
    unsigned char (* Tec_Ant) ( void );  // retorna Tecla Anterior.
    unsigned char (* Tec_Atual) ( void );   // retorna Tecla Atual.
    unsigned char (* Scan_Tec)( void ); // Varredura do teclado.
    void (* init )( void );     
    
} keyboard = { previousKey , currentKey , keyboard_scan , keyboard_init };

struct
{
    unsigned char (*rxEUART)( void );         // Ler o valor recebido pelo canal de comunicação serial
    unsigned char (*rxSTATUS)( void );   // Reinicializar/limpar os indicadores(flags) de erro.
    unsigned char (*rxERROR)( void );    // Reinicializar/limpar os indicadores(flags) de erro.
    void (* rxResetERROR) ( void );        // Verificar se algum dado foi recebido pelo canal de comunicação.
    void (* txEUSART)( unsigned char d );       // Transmitir um dado pelo canal de comunicação serial.
    unsigned char (* txSTATUS) ( void );   // Indicar que um dado está sendo transmitido.
    void (* initEUART)( unsigned long baudRate ); // Inicializar periférico de comunicação serial assíncrona.
} eusart = { rxEUSART, rxStatusEUSART , rxErrorEUSART , rxResetErrorEUSART , txEUSART , txStatusEUSART , initEUSART};


#endif
