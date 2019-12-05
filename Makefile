all:
	cp ./arduigames.ino tmp.cpp
	g++ -o arduigames ./tmp.cpp
	rm ./tmp.cpp
