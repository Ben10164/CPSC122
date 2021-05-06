caeser: project5.cpp input.in
	g++ project5.cpp -o caeser

test: caeser
	./caeser 0 key.out
	./caeser 1 key.out input.in encrypt.out
	./caeser 2 key.out encrypt.out decrypt.out

clean:
	rm -rf ./*.out || :
	rm -rf ./caeser || :