#include "Fenetre.h"

using namespace std;

FenetreIp::FenetreIp() : boiteBoutonsH(Gtk::BUTTONBOX_SPREAD, 10), bouton_ok("Valider"), champ_ip() {
    set_title("Configuration des volets");
    set_icon_from_file("icone.png");
    set_size_request(300, 80);
    set_resizable(false);
    set_position(Gtk::WIN_POS_CENTER);
    set_border_width(10);

    champ_ip.set_max_length(12);
    
    bouton_ok.set_can_focus(false);

    boiteBoutonsH.pack_start(champ_ip);
    boiteBoutonsH.pack_start(bouton_ok);
    
    bouton_ok.signal_clicked().connect(sigc::mem_fun(*this, &FenetreIp::save_ip));
    bouton_ok.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
    
    add(boiteBoutonsH);
    show_all();
}

void FenetreIp::save_ip() {
    std::string contenu = champ_ip.get_text();
    const char* ip = contenu.c_str();
    
    FILE* fichier_ip = NULL;
    fichier_ip = fopen("ip.txt", "w+");
    fputs(ip, fichier_ip);
    fclose(fichier_ip);
}
