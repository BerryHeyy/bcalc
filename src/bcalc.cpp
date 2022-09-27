#include "main_window.hpp"

int main(int argc, char* argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("io.github.berryheyy.bcalc");

    return app->make_window_and_run<MainWindow>(argc, argv);
}