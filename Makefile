all:
	g++ main.cc request.cc set_status.cc ip/main.cc ip/Fenetre.h ip/Fenetre.cc programmer/main.cc programmer/Fenetre.h programmer/Fenetre.cc prototype.h -o main `pkg-config gtkmm-3.0 --cflags --libs` -lcurl
