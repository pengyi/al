objects = exg.o biTree.o list.o
target = exg
CFLAGS = -g 
exg : $(objects)
	gcc -o  $(target) $(objects)
exg.o:exg.c
	gcc -c -g exg.c -o exg.o
list.o:../list/list.c ../list/list.h
	gcc -c -g ../list/list.c -o list.o
biTree.o:biTree.c biTree.h
	gcc -c -g  biTree.c -o biTree.o
.PHONY : clean
clean :
	-rm $(target) $(objects)
#end
