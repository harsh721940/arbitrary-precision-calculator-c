OBJ=$(patsubst %.c, %.o, $(wildcard *.c))
result.exe : $(OBJ)
	gcc -o $@ $^
clear :
	rm *.exe
