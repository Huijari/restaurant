restaurant: *.c *.h
	clang -O3 *.c -o restaurant -Wall

run: restaurant
	./restaurant

tags: tags
	ctags *.c
