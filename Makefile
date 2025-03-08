all:	compile link

compile:
	g++ -c src/*.cpp src/Entities/*.cpp src/States/*.cpp -I"C:\SFML_MinGW64\SFML\include" -DSFML_STATIC

link:
	g++ *.o -o main -L"C:\SFML_MinGW64\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

clean:
	rm -f main *.o