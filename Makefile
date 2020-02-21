run: obj/main.o obj/spaces.o obj/elimination.o obj/matrix.o obj/fraction.o
	g++ obj/main.o obj/spaces.o obj/elimination.o obj/matrix.o obj/fraction.o -o run

obj/main.o: src/main.cpp include/spaces.hpp include/elimination.hpp include/matrix.hpp include/fraction.hpp
	g++ -c src/main.cpp -o obj/main.o

obj/spaces.o: src/spaces.cpp include/spaces.hpp include/elimination.hpp
	g++ -c src/spaces.cpp -o obj/spaces.o

obj/elimination.o: src/elimination.cpp include/matrix.hpp include/fraction.hpp
	g++ -c src/elimination.cpp -o obj/elimination.o

obj/matrix.o: src/matrix.cpp include/matrix.hpp include/fraction.hpp
	g++ -c src/matrix.cpp -o obj/matrix.o

obj/fraction.o: src/fraction.cpp include/fraction.hpp
	g++ -c src/fraction.cpp -o obj/fraction.o
