/*
 * File:   main.c
 * Author: 20187263
 *
 * Created on 27 de Setembro de 2021, 13:10
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "eusart.h"
#include "ihm.h"
#include "keyboard.h"

unsigned char vetor[17] = "                 ";
void main(void)
{
    print.init();
    keyboard.init();
    eusart.initEUART(115200);
       
    unsigned char i = 0;
    
    while(1)
    { 
        print.print("EUSART           ");
        
        if(eusart.rxSTATUS())
        {
            switch(eusart.rxERROR())
            {
                    case 2: print.printpos(1,0, "Overrun Error");
                            eusart.rxERROR();
                            break;
                    case 1: print.printpos(1,0, "Framing Error");
                            eusart.rxERROR();
                            break;
                    default:
                    case 0:
                           vetor[i] = eusart.rxEUART();
                           i = ++i % 16;
                           print.printpos(1,0,vetor);
                           break;
            
          } 
        }
    }
    
}
