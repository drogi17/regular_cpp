all:makeFolder clear
	g++ -o build/main main.cpp
	ln -s build/main main

	
makeFolder:
	if [ -d "build" ]; then echo "=> build"; else mkdir "build"; fi

clear: 
	rm -rf build/*
	rm -rf ./main
