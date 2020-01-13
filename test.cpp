#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

int main(int argc, char* argv[]) {
    
    Gtk::Main app(argc, argv);
    Gtk::Window fenetre;
    fenetre.set_title("Configuration des volets");
    fenetre.set_icon_from_file("icone.png");
    fenetre.set_default_size(400, 200);
    fenetre.set_position(Gtk::WIN_POS_CENTER);
    fenetre.set_border_width(10);
    
    Gtk::HButtonBox boiteBoutonsH(Gtk::BUTTONBOX_END, 10);
    
    Gtk::Button boutonOuvrir("Options");
    boutonOuvrir.set_can_focus(false);
    Gtk::Button boutonFermer("Aide");
    boutonFermer.set_can_focus(false);
    
    boiteBoutonsH.pack_start(boutonOuvrir);
    boiteBoutonsH.pack_start(boutonFermer);

    boiteBoutonsH.set_child_secondary(boutonOptions);
    
    fenetre.add(boiteBoutonsH);
    
    fenetre.show_all();
    
    Gtk::Main::run(fenetre);
    
    
    return 0;
}
