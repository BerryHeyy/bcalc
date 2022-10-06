#ifndef BCALC_MAIN_WINDOW
#define BCALC_MAIN_WINDOW

#include <gtkmm-4.0/gtkmm.h>
#include <cstdint>
#include <iostream>

class ProgrammerWindow : public Gtk::Window
{
public:
    ProgrammerWindow();

private:
    int_fast64_t currentValue;
    int_fast64_t lastValue;

    Gtk::Button digitButtons[10],
        additionButton,
        subtractionButton,
        commaButton,
        negateButton;

    Gtk::Label currentValueLabel;

    int widgetHeight;
    int widgetWidth;

    void digit_pressed(int id);
    void operator_pressed(int id);
    
    void configure_callback();
};

#endif