OBJECTS = string_literal.out replace_blank.out construct_binarytree.out \
		  excel.out number_of_one.out sort_ages.out \
		  min_number_in_rotated_array.out stack_based_queue.out \
		  queue_based_stack.out fibonacci.out array_size.out

include ../GNU_makefile_template

LOCFLAGS = -I../utils

stack_based_queue.o: stack_based_queue.h
queue_based_stack.o: queue_based_stack.o

construct_binarytree.out: construct_binarytree.o ../utils/binarytree.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) construct_binarytree.o ../utils/binarytree.o -o construct_binarytree.out
