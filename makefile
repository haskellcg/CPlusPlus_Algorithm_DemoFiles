PROJ=algorithms
GCC=g++

OBJS=bubble_sort.o\
     common_types.o\
     insert_sort.o\
     main.o\
     merge_sort.o\
     selection_sort.o\
     shell_sort.o\

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
