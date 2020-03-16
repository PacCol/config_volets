#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <string>

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include <gtkmm/table.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/label.h>

#include <gtkmm/adjustment.h>
#include <gtkmm/spinbutton.h>

#include <stdlib.h>
#include <stdio.h>

class Fenetre : public Gtk::Window {
    public :
        Fenetre();
    private :
        Gtk::CheckButton case_a_cocher_activer_heure;
        Gtk::CheckButton case_a_cocher_activer_auto;
        Gtk::Button bouton_ok;
        Gtk::Label ouverture;
        Gtk::Label fermeture;
        Glib::RefPtr<Gtk::Adjustment> ajustement_heure_ouverture = Gtk::Adjustment::create(7, 0, 23, 1);
        Glib::RefPtr<Gtk::Adjustment> ajustement_heure_fermeture = Gtk::Adjustment::create(19, 0, 23, 1);
        Glib::RefPtr<Gtk::Adjustment> ajustement_minute_ouverture = Gtk::Adjustment::create(0, 0, 50, 10);
        Glib::RefPtr<Gtk::Adjustment> ajustement_minute_fermeture = Gtk::Adjustment::create(0, 0, 50, 10);
        Gtk::SpinButton heure_ouverture;
        Gtk::SpinButton minute_ouverture;
        Gtk::SpinButton heure_fermeture;
        Gtk::SpinButton minute_fermeture;
    protected :
        void case_heure();
        void case_auto();
        void valider();
        Gtk::Table tableau;
};

#endif
