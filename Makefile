all:
	g++ main.cc programmer.cc prototype.h -o main `pkg-config gtkmm-3.0 --cflags --libs`
