CC=gcc
CFLAGS=
DEPS = mysh_routines.h
OBJ = mysh.o mysh_routines.o

make : mysh mycp mycat #myls

mysh : $(OBJ)
	gcc -o mysh $^ $(CFLAGS) 

mycp: mycp.o
	gcc -o mycp mycp.o

#myls: myls.o
#	gcc -o myls myls.o

mycat: mycat.o
	gcc -o mycat mycat.o

mycp.o: mycp.c
	cc -c mycp.c

#myls.o: myls.c
#	cc -c myls.c

mycat.o: mycat.c
	cc -c mycat.c

mysh.o : mysh.c $(DEPS)
	cc -c mysh.c

mysh_routines.o : mysh_routines.c $(DEPS)
	cc -c mysh_routines.c

.PHONY: clean

clean:
	rm -f *.o mysh mycp myls mycat
