#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

#include "prototype.h"

int main(int argc, char* argv[]) {

        Gtk::Main app(argc, argv);
        Gtk::Window fenetre;
        fenetre.set_title("Configuration des volets");
        fenetre.set_icon_from_file("icone.png");
        fenetre.set_size_request(300, 80);
        fenetre.set_resizable(false);
        fenetre.set_position(Gtk::WIN_POS_CENTER);
        fenetre.set_border_width(10);

        Gtk::HButtonBox boiteBoutonsH(Gtk::BUTTONBOX_SPREAD, 10);

        Gtk::Button boutonHeure("Programmer une heure");
        boutonHeure.set_can_focus(false);
        Gtk::Button boutonOuvrir("Ouvrir les volets");
        boutonOuvrir.set_can_focus(false);
        Gtk::Button boutonFermer("Fermer les volets");
        boutonFermer.set_can_focus(false);
        Gtk::Button boutonIp("Définir l'adresse IP");
        boutonIp.set_can_focus(false);

        //boiteBoutonsH.pack_start(boutonHeure);
        boiteBoutonsH.pack_start(boutonOuvrir);
        boiteBoutonsH.pack_start(boutonFermer);
        boiteBoutonsH.pack_start(boutonIp);

        fenetre.add(boiteBoutonsH);

        fenetre.show_all();

        boutonHeure.signal_clicked().connect(sigc::ptr_fun(&programmer));
        boutonOuvrir.signal_clicked().connect(sigc::ptr_fun(&ouvrir));
        boutonFermer.signal_clicked().connect(sigc::ptr_fun(&fermer));
        boutonIp.signal_clicked().connect(sigc::ptr_fun(&set_ip));

        Gtk::Main::run(fenetre);

        return 0;
}
