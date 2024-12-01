DIR_NAME = dist

run : 
	@if [ ! -d "$(DIR_NAME)" ]; then \
			mkdir -p $(DIR_NAME); \
	fi
	g++ -std=c++17 -o dist/main *.cpp src/*.cpp -I include
	./$(DIR_NAME)/main

clean :
	rm $(DIR_NAME)/main