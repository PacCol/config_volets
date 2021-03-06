#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/entry.h>
#include <gtkmm/messagedialog.h>

#include <stdlib.h>
#include <stdio.h>

class FenetreIp : public Gtk::Window {
    public :
        FenetreIp();
    private :
        Gtk::Button bouton_ok;
    protected :
        void save_ip();
        Gtk::Entry champ_ip;
        Gtk::HButtonBox boiteBoutonsH;
};

#endif
