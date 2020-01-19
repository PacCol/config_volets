all:
	g++ main.cc programmer.cc request.cc set_status.cc IP.cc prototype.h -o main `pkg-config gtkmm-3.0 --cflags --libs` -lcurl
