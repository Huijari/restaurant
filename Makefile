restaurant: *.c *.h
	clang -O3 *.c -o restaurant

run: restaurant
	./restaurant
