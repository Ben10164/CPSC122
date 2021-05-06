transposition: project7.cpp input.in
	g++ project7.cpp -o transposition

test: transposition
	./transposition 0 key.out
	./transposition 1 key.out input.in encrypt.out
	./transposition 2 key.out encrypt.out decrypt.out

clean: 
	rm -rf ./*.out || :
	rm -rf ./transposition || :