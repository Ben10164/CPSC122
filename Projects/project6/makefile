affine: project6.cpp input.in
	g++ project6.cpp -o affine

test: affine
	./affine 0 key.out
	./affine 1 key.out input.in encrypt.out
	./affine 2 key.out encrypt.out decrypt.out

clean: 
	rm -rf ./*.out || :
	rm -rf ./affine || :