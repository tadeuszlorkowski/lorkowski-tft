#include "LorkowskiTFT.h"

#include <Touch.h>
#include <LCD.h>
#include <XPT2046.h>
#include <stdlib.h>

// uruchamia sterowniki wyświetlacza i panelu dotykowego
void uruchom() {
  Tft.lcd_init();
  Tp.tp_init();
}

// wypisuje podany tekst o podanej barwie, na współrzędnych x,y
void tekst(uint16_t x, uint16_t y, uint8_t *tekst, uint16_t barwa) {
  Tft.lcd_display_string(x, y, tekst, FONT_1608, barwa);
}

// zmienia barwę punktu o współrzędnych x,y
void punkt(uint16_t x, uint16_t y, uint16_t barwa) {
  Tft.lcd_draw_point(x, y, barwa);
}

// rysuje linię od współrzędnych x1,y1 do x2,y2 o podanej barwie
void linia(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t barwa) {
  Tft.lcd_draw_line(x1, y1, x2, y2, barwa);
}

// rysuje prostokąt o wymiarach w na h px, na współrzędnych x,y, o podanej barwie
void okrag(uint16_t x, uint16_t y, uint16_t r, uint16_t barwa) {
  Tft.lcd_draw_circle(x,y,r,barwa);
}

// rysuje prostokąt o wymiarach w na h px, na współrzędnych x,y, o podanej barwie
void prostokat(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t barwa) {
  Tft.lcd_draw_rect(x, y, w, h, barwa);
}

// rysuje wypełniony prostokąt o wymiarach w na h px, na współrzędnych x,y, o podanej barwie
void wypelniony_prostokat(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t barwa) {
  for(int i=0; i<w; i++)
    Tft.lcd_draw_v_line(x+i,y,h,barwa);
}

// rysuje wypełniony okrąg o promieniu r, na współrzędnych x,y, o podanej barwie
void wypelniony_okrag(uint16_t x, uint16_t y, uint16_t r, uint16_t barwa) {
  for(int i=0; i<r; i++)
    Tft.lcd_draw_circle(x,y,i,barwa);
  for(int i=0; i<r-1; i++)
    Tft.lcd_draw_circle(x-1,y,i,barwa);
  for(int i=0; i<r-1; i++)
    Tft.lcd_draw_circle(x+1,y,i,barwa);
}

// wypełnia ekran podaną barwą
void tlo(uint16_t barwa) {
  wypelniony_prostokat(0,0,240,320,barwa);
}

// czy dotknięto ekranu?
bool dotyk() {
  return Tp.tp_scan(1)>0 && znajdzX() < 1000 && znajdzY() < 1000;
}

// zwraca aktualnie dotykaną współrzędną x (od 0 do 240)
uint16_t znajdzX() {
  return  240-(uint16_t)((Tp.s_tTouch.hwXpos-112)/((float)7.46));
}

// zwraca aktualnie dotykaną współrzędną y (od 0 do 320)
uint16_t znajdzY() {
  return  320-(uint16_t)((Tp.s_tTouch.hwYpos-160)/((float)5.6));
}