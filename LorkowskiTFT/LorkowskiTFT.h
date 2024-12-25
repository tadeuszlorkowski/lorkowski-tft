#ifndef LORKOWSKITFT_H
#define LORKOWSKITFT_H

#include <Touch.h>
#include <LCD.h>
#include <XPT2046.h>
#include <stdlib.h>

#define BIALY          0xFFFF
#define CZARNY          0x0000	  
#define NIEBIESKI           0x001F  
#define CZERWONY            0xF800
#define ROZOWY        0xF81F
#define ZIELONY          0x07E0
#define CYJAN           0x7FFF
#define ZOLTY         0xFFE0
#define BRAZOWY 		   0XBC40 
#define SZARY  		   0X8430

void uruchom();
void tekst(uint16_t x, uint16_t y, uint8_t *tekst, uint16_t barwa);
void punkt(uint16_t x, uint16_t y, uint16_t barwa);
void linia(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t barwa);
void prostokat(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t barwa);
void okrag(uint16_t x, uint16_t y, uint16_t r, uint16_t barwa);
void wypelniony_prostokat(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t barwa);
void wypelniony_okrag(uint16_t x, uint16_t y, uint16_t r, uint16_t barwa);
void tlo(uint16_t barwa);
bool dotyk();
uint16_t znajdzX();
uint16_t znajdzY();

#endif