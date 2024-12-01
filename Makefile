DIR_NAME = dist

.PHONY: checkdir

checkdir:
	@if [ ! -d "$(DIR_NAME)" ]; then \
		mkdir -p $(DIR_NAME); \
		echo "Direktori '$(DIR_NAME)' telah dibuat."; \

run : 
	g++ -std=c++17 -o dist/main *.cpp src/*.cpp -I include
	./dist/main

clean :
	rm dist/main