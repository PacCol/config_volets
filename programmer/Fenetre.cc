#include <curl/curl.h>

#include "Fenetre.h"
#include "../prototype.h"

using namespace std;

Fenetre::Fenetre() : tableau(4, 3), case_a_cocher_activer_heure("  Programmer l'heure d'ouverture et de fermeture   \n  avec les sélecteurs ci-dessous   "), case_a_cocher_activer_auto("  Ouvrir et fermer les volets suivant l'heure   \n  du lever et du coucher du soleil"), bouton_ok("Valider"), ouverture("Heure d'ouverture :"), fermeture("Heure de fermeture :"), heure_ouverture(ajustement_heure_ouverture), minute_ouverture(ajustement_minute_ouverture), heure_fermeture(ajustement_heure_fermeture), minute_fermeture(ajustement_minute_fermeture) {
    set_title("Configuration des volets");
    set_icon_from_file("icone.png");
    set_size_request(360, 180);
    set_resizable(false);
    set_position(Gtk::WIN_POS_CENTER);
    set_border_width(10);

    heure_ouverture.set_can_focus(false);
    heure_ouverture.set_numeric();
    minute_ouverture.set_can_focus(false);
    minute_ouverture.set_numeric();
    heure_fermeture.set_can_focus(false);
    heure_fermeture.set_numeric();
    minute_fermeture.set_can_focus(false);
    minute_fermeture.set_numeric();
    case_a_cocher_activer_heure.set_can_focus(false);
    bouton_ok.set_can_focus(false);

    tableau.attach(case_a_cocher_activer_auto, 0, 2, 0, 1);
    tableau.attach(bouton_ok, 2, 3, 0, 1, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(case_a_cocher_activer_heure, 0, 2, 1, 2);
    tableau.attach(ouverture, 0, 1, 2, 3, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(fermeture, 0, 1, 3, 4, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(heure_ouverture, 1, 2, 2, 3, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(minute_ouverture, 2, 3, 2, 3, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(heure_fermeture, 1, 2, 3, 4, Gtk::SHRINK, Gtk::SHRINK);
    tableau.attach(minute_fermeture, 2, 3, 3, 4, Gtk::SHRINK, Gtk::SHRINK);

    case_a_cocher_activer_heure.signal_toggled().connect(sigc::mem_fun(*this, &Fenetre::case_heure));
    case_a_cocher_activer_auto.signal_toggled().connect(sigc::mem_fun(*this, &Fenetre::case_auto));
    bouton_ok.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::valider));

    add(tableau);
    tableau.show();
    case_a_cocher_activer_heure.show();
    case_a_cocher_activer_auto.show();
    bouton_ok.show();
}

void Fenetre::case_heure() {
    if(case_a_cocher_activer_heure.get_active()) {
        case_a_cocher_activer_auto.set_active(false);
        ouverture.show();
        fermeture.show();
        heure_ouverture.show();
        minute_ouverture.show();
        heure_fermeture.show();
        minute_fermeture.show();
    }
    else {
        ouverture.hide();
        fermeture.hide();
        heure_ouverture.hide();
        minute_ouverture.hide();
        heure_fermeture.hide();
        minute_fermeture.hide();
    }
}

void Fenetre::case_auto() {
    if(case_a_cocher_activer_auto.get_active()) {
        case_a_cocher_activer_heure.set_active(false);
    }
}

void Fenetre::valider() {
    if(case_a_cocher_activer_heure.get_active()) {
        int success = 0;
        char ip[13];
        FILE* Ip = NULL;
        Ip = fopen("ip.txt", "r");

        if (Ip != NULL) {
            fgets(ip, 13, Ip);
            fclose(Ip);

            char* heure = (char*) heure_ouverture.get_text().c_str();
            int __heure_ouverture = atoi(heure);
            heure = (char*) minute_ouverture.get_text().c_str();
            int __minute_ouverture = atoi(heure);
            heure = (char*) heure_fermeture.get_text().c_str();
            int __heure_fermeture = atoi(heure);
            heure = (char*) minute_fermeture.get_text().c_str();
            int __minute_fermeture = atoi(heure);

            if (__heure_fermeture == __heure_ouverture) {
                Gtk::MessageDialog dialogue("Erreur", false, Gtk::MESSAGE_ERROR);
                dialogue.set_title("Erreur");
                dialogue.set_secondary_text("Les horaires d'ouverture et de fermeture des volets sont trop proches... Veuillez rentrer des horaires valides.");
                dialogue.run();
            }
            else {

                success = programmer_heure(ip, 1, __heure_ouverture, __minute_ouverture, __heure_fermeture, __minute_fermeture);

                if (success == 0) {
                    Gtk::MessageDialog dialogue("Opération valide", false, Gtk::MESSAGE_INFO);
                    dialogue.set_title("Opération valide");
                    dialogue.set_secondary_text("Les paramètres ont bien été enregistré.");
                    dialogue.run();
                }
                else if (success == 1) {
                    Gtk::MessageDialog dialogue("Erreur", false, Gtk::MESSAGE_ERROR);
                    dialogue.set_title("Erreur");
                    dialogue.set_secondary_text("Vérifiez votre connexion au réseau... Si le problème persiste, essayer de redéfinir l'IP de la machine.");
                    dialogue.run();
                }
            }
        }
        else {
            Gtk::MessageDialog dialogue("Erreur fatale !", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
            dialogue.set_title("Erreur fatale");
            dialogue.set_secondary_text("Veuillez réinstaller le logiciel...");
            dialogue.run();
        }
    }
    else if (case_a_cocher_activer_auto.get_active()) {
        int success = 0;
        char ip[13];
        char action[] = "programmer_soleil";
        FILE* Ip = NULL;
        Ip = fopen("ip.txt", "r");

        if (Ip != NULL) {
            fgets(ip, 13, Ip);
            fclose(Ip);
            success = send_post_request(ip, action);

            if (success == 0) {
                Gtk::MessageDialog dialogue("Opération valide", false, Gtk::MESSAGE_INFO);
                dialogue.set_title("Opération valide");
                dialogue.set_secondary_text("Les paramètres ont bien été enregistré.");
                dialogue.run();
              }
            else if (success == 1) {
                Gtk::MessageDialog dialogue("Erreur", false, Gtk::MESSAGE_ERROR);
                dialogue.set_title("Erreur");
                dialogue.set_secondary_text("Vérifiez votre connexion au réseau... Si le problème persiste, essayer de redéfinir l'IP de la machine.");
                dialogue.run();
            }
        }
        else {
            Gtk::MessageDialog dialogue("Erreur fatale !", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
            dialogue.set_title("Erreur fatale");
            dialogue.set_secondary_text("Veuillez réinstaller le logiciel...");
            dialogue.run();
        }
    }
    else {
        int success = 0;
        char ip[13];
        FILE* Ip = NULL;
        Ip = fopen("ip.txt", "r");

        if (Ip != NULL) {
            fgets(ip, 13, Ip);
            fclose(Ip);
            success = programmer_heure(ip, 0, 0, 0, 0, 0);

            if (success == 0) {
                Gtk::MessageDialog dialogue("Opération valide", false, Gtk::MESSAGE_INFO);
                dialogue.set_title("Opération valide");
                dialogue.set_secondary_text("Les paramètres ont bien été enregistré.");
                dialogue.run();
            }
            else if (success == 1) {
                Gtk::MessageDialog dialogue("Erreur", false, Gtk::MESSAGE_ERROR);
                dialogue.set_title("Erreur");
                dialogue.set_secondary_text("Vérifiez votre connexion au réseau... Si le problème persiste, essayer de redéfinir l'IP de la machine.");
                dialogue.run();
            }
        }
        else {
            Gtk::MessageDialog dialogue("Erreur fatale !", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
            dialogue.set_title("Erreur fatale");
            dialogue.set_secondary_text("Veuillez réinstaller le logiciel...");
            dialogue.run();
        }
    }
}
