#ifndef BCALC_MAIN_WINDOW
#define BCALC_MAIN_WINDOW

#include <gtkmm-4.0/gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
    MainWindow();

private:

    Gtk::Button digitButtons[10],
        additionButton,
        subtractionButton,
        commaButton,
        negateButton;

    void digit_pressed(int id);

};

#endif