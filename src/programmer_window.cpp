#include "programmer_window.hpp"

ProgrammerWindow::ProgrammerWindow()
{
    widgetWidth = 20; widgetHeight = 40;
    currentValue = 0;

    // Set window stuff
    set_title("bcalc");
    set_default_size(200, 200);

    Gtk::Grid* grid = Gtk::make_managed<Gtk::Grid>();
    
    currentValueLabel.set_text(std::to_string(currentValue));
    currentValueLabel.set_halign(Gtk::Align::END);

    // Create buttons
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

    // Make display screen
    Gtk::Box* vbox = Gtk::make_managed<Gtk::Box>();
    vbox->set_orientation(Gtk::Orientation::VERTICAL);
    vbox->append(currentValueLabel);
    vbox->append(*grid);

    vbox->set_halign(Gtk::Align::CENTER);
    vbox->set_valign(Gtk::Align::CENTER);

    set_child(*vbox);

    std::cout << "Succesfully started." << std::endl;
}

void ProgrammerWindow::digit_pressed(int id)
{
    if (currentValue >= 0)
    {
        currentValue = currentValue * 10 + id;
    }
    else
    {
        currentValue = currentValue * 10 - id;
    }

    currentValueLabel.set_text(std::to_string(currentValue));
}
