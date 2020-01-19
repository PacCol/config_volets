#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

#include "prototype.h"

void set_ip() {
        Gtk::Window fenetreIP;
        fenetreIP.set_title("Configuration des volets");
        fenetreIP.set_icon_from_file("icone.png");
        fenetreIP.set_size_request(300, 80);
        fenetreIP.set_resizable(false);
        fenetreIP.set_position(Gtk::WIN_POS_CENTER);
        fenetreIP.set_border_width(10);

        Gtk::HButtonBox boiteBoutonsH(Gtk::BUTTONBOX_SPREAD, 10);

        Gtk::Entry IP;
        IP.set_max_length(12);

        Gtk::Button boutonOk("Définir l'IP");
        boutonOk.set_can_focus(false);

        boiteBoutonsH.pack_start(IP);
        boiteBoutonsH.pack_start(boutonOk);

        fenetreIP.add(boiteBoutonsH);
        fenetreIP.show_all();

        //boutonOk.signal_clicked().connect(sigc::ptr_fun(&xis));

        Gtk::Main::run(fenetreIP);
}
