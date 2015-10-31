objects = exg.o biTree.o
target = exg
CFLAGS = '-g'
exg : $(objects)
	gcc -o $(target) $(CFLAGS) $(objects)
$(objexts) : %.o:%.c
	gcc -c $(CFLAGS) $< -o $@
.PHONY : clean
clean :
	rm $(target) $(objects)
