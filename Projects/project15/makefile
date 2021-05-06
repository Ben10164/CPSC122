List: list.o listTst.o
	g++ -o list listTst.o list.o

listTst.o: listTst.cpp
	g++ -c listTst.cpp 

list.o: list.cpp
	g++ -c list.cpp 

clean :
	rm -rf *.o || :
	rm -rf ./list || :
	
test: List 
	./list 