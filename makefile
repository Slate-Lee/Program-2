stateApp: Driver.o stateData.o stateManager.o
	g++ Driver.o stateData.o stateManager.o -o stateApp

Driver.o: Driver.cpp
	g++ -c Driver.cpp

stateData.o: stateData.cpp
	g++ -c stateData.cpp

stateManager.o: stateManager.cpp
	g++ -c stateManager.cpp

clean:
	rm *.o stateApp
