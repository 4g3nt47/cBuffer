bin/cBuffer.o: src/cBuffer.c src/cBuffer.h
	gcc -Os -s -c src/cBuffer.c -o bin/cBuffer.o

clean:
	rm bin/*
