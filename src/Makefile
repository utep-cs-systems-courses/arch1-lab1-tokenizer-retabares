tokenizer_exec: tokenizer.o history.o ui.o
	gcc -o tokenizer_exec tokenizer.o history.o ui.o

tokenizer.o: tokenizer.h tokenizer.c

history.o: tokenizer.c history.h history.c

ui.o: history.o ui.c

clean:
	rm -f *.o tokenizer_exec
