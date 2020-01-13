all:
	g++ main.cc -o main `pkg-config gtkmm-3.0 --cflags --libs`
