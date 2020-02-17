/*
***********************************************************************************************


									Module de l ecran 



************************************************************************************************
*/
#ifndef SCREEN_H_
#define SCREEN_H_


#include <LiquidCrystal_I2C.h>


class Screen : public LiquidCrystal_I2C
{
private:

    int8_t _index_char = 1;
    uint32_t _previous_millis;
    uint8_t _size_lcd;
    int8_t _index_lcd;

    void _scroll_one_line(char const* text_to_s_croll, uint8_t line, uint16_t delay_scroll = 500);
   


public:


    Screen(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
    

};



#endif // !SCREEN_H_
