PROJ=algorithms
GCC=g++

OBJS=bubble_sort.o\
     common_types.o\
     heap_sort.o\
     insert_sort.o\
     main.o\
     maximum_subarray.o\
     merge_sort.o\
     selection_sort.o\
     shell_sort.o\
     strassen_matrix_multiply.o\

INCLUDES=\

LIBS=\

all:CFLAGS=-Wall -O2
all:$(PROJ)

debug:CFLAGS=-DDEBUG -g
debug:$(PROJ)

$(PROJ):$(OBJS)
	$(GCC) -o $(PROJ) $(OBJS) $(LIBS)

%.o:%.cpp
	$(GCC) -o $@ -c $< $(INCLUDES) $(CFLAGS)
    
clean:
	@echo "\033[31mclean project target file and objects\033[0m"
	rm -fr $(PROJ)
	rm -fr $(OBJS)
