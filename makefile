.PHONY:clean
main : adress.c
	gcc -o $@ $^
clean:
	rm main
