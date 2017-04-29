restaurant: *.c
	clang -O3 *.c -o restaurant

run: restaurant
	./restaurant
