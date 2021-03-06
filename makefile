#*************************
#   compiler flags
#*************************
GCC                 =   g++

CFLAGS              =   -Wall -Werror -Wextra


#*************************
#   project files
#*************************
PROJ                =   algorithms

OBJS                =   avl_tree.o\
                        basic_queue.o\
                        basic_stack.o\
                        binary_search_tree.o\
                        bubble_sort.o\
                        bucket_sort.o\
                        common_types.o\
                        computational_geometry_utils.o\
                        counting_sort.o\
                        double_link_list.o\
                        egg_dropping_puzzle.o\
                        fusion_tree.o\
                        hash_set.o\
                        heap_sort.o\
                        insert_sort.o\
                        josephus_problem.o\
                        longest_common_subsequence_problem.o\
                        main.o\
                        matrix_chain_multiplication_problem.o\
                        matrix_circle_print.o\
                        maximum_subarray.o\
                        merge_sort.o\
                        nowcoder_com_first_part.o\
                        optimal_binary_search_tree_problem.o\
                        order_statistic_funtions.o\
                        permutation_generator.o\
                        quick_sort.o\
                        radix_heap.o\
                        radix_sort.o\
                        radix_tree.o\
                        red_black_tree.o\
                        rod_cutting_problem.o\
                        selection_sort.o\
                        shell_sort.o\
                        strassen_matrix_multiply.o\
                        string_hash_funtions.o\
                        tower_of_hanoi_problem.o\

INCLUDES            =   \

LIBS                =   \


#*************************
#   debug setting
#*************************
DEBUGDIR            =   debug

DEBUGPROJ           =   $(DEBUGDIR)/$(PROJ)

DEBUGOBJS           =   $(addprefix $(DEBUGDIR)/, $(OBJS))

DEBUGFLAGS          =   -g -O0 -DDEBUG


#*************************
#   release setting
#*************************
RELEASEDIR          =   release

RELEASEPROJ         =   $(RELEASEDIR)/$(PROJ)

RELEASEOBJS         =   $(addprefix $(RELEASEDIR)/, $(OBJS))

RELEASEFLAGS        =   -O3 -DNDEBUG


#*************************
#   phony
#*************************
.PHONY              :   all clean debug prep release remake


#*************************
#   default rules
#*************************
all                 :   prep release


#*************************
#   debug rules
#*************************
debug               :   $(DEBUGPROJ)

$(DEBUGPROJ)        :   $(DEBUGOBJS)
	$(GCC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $^

$(DEBUGDIR)/%.o     :   %.cpp
	$(GCC) -c $(CFLAGS) $(DEBUGFLAGS) -o $@ $^


#*************************
#   release rules
#*************************
release             :   $(RELEASEPROJ)

$(RELEASEPROJ)      :   $(RELEASEOBJS)
	$(GCC) $(CFLAGS) $(RELEASEFLAGS) -o $@ $^

$(RELEASEDIR)/%.o   :   %.cpp
	$(GCC) -c $(CFLAGS) $(RELEASEFLAGS) -o $@ $^


#*************************
#   prep rules
#*************************
prep                :
	@mkdir -p $(DEBUGDIR) $(RELEASEDIR)


#*************************
#   clean rules
#*************************
clean               :
	@echo "\033[36mClean project target file and objects:\033[0m"
	rm -f $(DEBUGPROJ)
	rm -f $(DEBUGOBJS)
	rm -f $(RELEASEPROJ)
	rm -f $(RELEASEOBJS)


#*************************
#   remake rules
#*************************
remake              :   clean all
