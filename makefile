PROJ=algorithms
GCC=g++

OBJS=bubble_sort.o\
     common_types.o\
     insert_sort.o\
     main.o\

INCLUDES=\

LIBS=\

CFLAGS=-Wall -O2


$(PROJ):$(OBJS)
	$(GCC) -o $(PROJ) $(OBJS) $(LIBS)

%.o:%.cpp
	$(GCC) -o $@ -c $< $(INCLUDES) $(CFLAGS)
    
clean:
	@echo "clean project target file and objects"
	rm -fr $(PROJ)
	rm -fr $(OBJS)
