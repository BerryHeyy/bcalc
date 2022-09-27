#ifndef BCALC_MAIN_WINDOW
#define BCALC_MAIN_WINDOW

#include <gtkmm-4.0/gtkmm.h>

class ProgrammerWindow : public Gtk::Window
{
public:
    ProgrammerWindow();

private:


    void digit_pressed(int id);

};

#endif