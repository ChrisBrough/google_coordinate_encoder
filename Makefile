all: libgglenc test

libgglenc: map.cpp
	clang++ -o libgglenc.so -g -shared map.cpp

test: main.cpp
	clang++ -o test main.cpp -L ./ -lgglenc
