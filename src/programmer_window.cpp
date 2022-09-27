#include "programmer_window.hpp"

ProgrammerWindow::ProgrammerWindow()
{
    // Set window stuff
    set_title("bcalc");
    set_default_size(200, 200);

    Gtk::Grid* grid = Gtk::make_managed<Gtk::Grid>();

    Gtk::Button digitButtons[10],
        additionButton,
        subtractionButton,
        commaButton,
        negateButton;

    // Create digit buttons
    for (int i = 0; i < 10; i++)
    {
        Gtk::Label* bLabel = Gtk::make_managed<Gtk::Label>(std::to_string(i));
        
        digitButtons[i].set_child(*bLabel);
        digitButtons[i].signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &ProgrammerWindow::digit_pressed), i));

        int column = i == 0 ? 1 : (i - 1) % 3;
        int row = i == 0 ? 3 : 2 - (i - 1) / 3;

        grid->attach(digitButtons[i], column, row);
    }

    negateButton.set_child(*Gtk::make_managed<Gtk::Label>("-"));
    commaButton.set_child(*Gtk::make_managed<Gtk::Label>(","));
    commaButton.set_sensitive(false);
    
    grid->attach(negateButton, 0, 3);
    grid->attach(commaButton, 2, 3);

    set_child(*grid);
}

void ProgrammerWindow::digit_pressed(int id)
{
    
}
