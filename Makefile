all:
	cp ./arduigames.ino tmp.cpp
	g++ -o games ./tmp.cpp
	rm ./tmp.cpp
