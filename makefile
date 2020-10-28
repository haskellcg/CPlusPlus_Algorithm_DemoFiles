PROJ=algorithms
GCC=g++

OBJS=basic_queue.o\
     basic_stack.o\
     bubble_sort.o\
     bucket_sort.o\
     common_types.o\
     counting_sort.o\
     double_link_list.o\
     heap_sort.o\
     insert_sort.o\
     main.o\
     maximum_subarray.o\
     merge_sort.o\
     nowcoder_com_first_part.o\
     order_statistic_funtions.o\
     quick_sort.o\
     radix_sort.o\
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
