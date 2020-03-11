#ifndef PROTOTYPE_H
#define PROTOTYPE_H

extern void programmer();
extern void ouvrir();
extern void fermer();
extern unsigned int send_post_request(char* ip, char* action);
unsigned int programmer_heure(char* ip, int activation, int heure_ouverture, int minute_ouverture, int heure_fermeture, int minute_fermeture);
extern void ouvrir();
extern void fermer();
extern void set_ip();

#endif
