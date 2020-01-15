#include <gtkmm/buttonbox.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

#include "prototype.h"

void programmer() {
    Gtk::Window fenetre1;
    fenetre1.set_title("Configuration des volets");
    fenetre1.set_icon_from_file("icone.png");
    fenetre1.set_size_request(500, 160);
    fenetre1.set_resizable(false);
    fenetre1.set_position(Gtk::WIN_POS_CENTER);
    fenetre1.set_border_width(10);
    
    Gtk::HButtonBox boiteElementsH(Gtk::BUTTONBOX_SPREAD, 10);
    
    Gtk::CheckButton ActiverAutomatisme("Programmer une heure d'ouverture et de fermeture");
    ActiverAutomatisme.set_can_focus(false);
    
    ActiverAutomatisme.signal_toggled().connect(sigc::ptr_fun(&Gtk::Main::quit));

    boiteElementsH.pack_start(ActiverAutomatisme);

    fenetre1.add(boiteElementsH);
    
    fenetre1.show_all();
    
    Gtk::Main::run(fenetre1);
}
