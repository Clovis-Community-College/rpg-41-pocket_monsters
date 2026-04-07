a.out: main.o class_slop.o
	g++ main.o class_slop.o
main.o: main.cc class_slop.h
	g++ -c main.cc
clean: 
	rm -f *.o a.out core
