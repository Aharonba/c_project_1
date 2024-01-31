CC=gcc
FLAGS= -Wall -g


all: loops libclassloops.a recursives libclassrec.a recursived libclassrec.so loopd libclassloops.so mains maindloop maindrec

loops: libclassloops.a

libclassloops.a: advancedClassificationLoop.o basicClassification.o	
	ar rcs libclassloops.a advancedClassificationLoop.o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c  advancedClassificationLoop.c -o advancedClassificationLoop.o

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c  basicClassification.c -o basicClassification.o

recursives: libclassrec.a

libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

recursived: libclassrec.so

libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) $(FLAGS) -shared -fPIC -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

loopd: libclassloops.so

libclassloops.so: advancedClassificationLoop.o basicClassification.o	
	$(CC) $(FLAGS) -shared -fPIC -o libclassloops.so advancedClassificationLoop.o basicClassification.o

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -static -o mains main.o libclassrec.a

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c  main.c -o main.o

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

clean:
	rm -f *.o *.a *.so mains maindloop maindrec




