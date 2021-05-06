testpad: testpad.cpp testpadFunctions.cpp 
	g++ -o testpad testpad.cpp

clean: testpad
	rm testpad