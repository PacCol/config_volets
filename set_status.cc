#include <gtkmm/messagedialog.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

#include "prototype.h"

void ouvrir() {
	int success = 0;
	char ip[13];
	char ouvrir[] = "ouvrir";
	FILE* Ip = NULL;
	Ip = fopen("ip.txt", "r");

	if (Ip != NULL) {
		fgets(ip, 13, Ip);
		fclose(Ip);
		success = send_post_request(ip, ouvrir);

		if (success == 0) {
			Gtk::MessageDialog dialogue("Opération valide", false, Gtk::MESSAGE_INFO);
			dialogue.set_title("Opération valide");
			dialogue.set_secondary_text("Les volets ont bien été ouverts...");
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

void fermer() {
	int success = 0;
	char ip[13];
	char fermer[] = "fermer";
	FILE* Ip = NULL;
	Ip = fopen("ip.txt", "r");

	if (Ip != NULL) {
		fgets(ip, 13, Ip);
		fclose(Ip);
		success = send_post_request(ip, fermer);

		if (success == 0) {
			Gtk::MessageDialog dialogue("Opération valide", false, Gtk::MESSAGE_INFO);
			dialogue.set_title("Opération valide");
			dialogue.set_secondary_text("Les volets ont bien été fermés...");
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
