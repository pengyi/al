objects = exg.o biTree.o
CFLAGS = '-g'
exg : $(objects)
	gcc -o exg $(CFLAGS) $(objects)
$(objexts) : %.o:%.c
	gcc -c $(CFLAGS) $< -o $@
.PHONY : clean
clean :
	rm exg $(objects)
