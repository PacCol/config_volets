#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

void programmer();
void afficherTitre();

int main(int argc, char* argv[]) {
    
    Gtk::Main app(argc, argv);
    Gtk::Window fenetre;
    fenetre.set_title("Configuration des volets");
    fenetre.set_icon_from_file("icone.png");
    fenetre.set_size_request(80, 80);
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
    
    boiteBoutonsH.pack_start(boutonHeure);
    boiteBoutonsH.pack_start(boutonOuvrir);
    boiteBoutonsH.pack_start(boutonFermer);
    
    fenetre.add(boiteBoutonsH);
    
    fenetre.show_all();
    
    boutonHeure.signal_clicked().connect(sigc::ptr_fun(&programmer));
    
    Gtk::Main::run(fenetre);
    
    return 0;
}

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
    
    ActiverAutomatisme.signal_toggled().connect(sigc::mem_fun(*this, &afficherTitre));

    boiteElementsH.pack_start(ActiverAutomatisme);

    fenetre1.add(boiteElementsH);
    
    fenetre1.show_all();
    
    Gtk::Main::run(fenetre1);
}

void afficherTitre() {
    if(ActiverAutomatisme.get_active()) { //Si la case est cochée.
        printf("Boutococher");
    }
    else { //Si elle n'est pas cochée.
        printf("Bouton à cocher");
    }
}
