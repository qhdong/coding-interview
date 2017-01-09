OBJECTS = string_literal.out replace_blank.out construct_binarytree.out \
		  excel.out number_of_one.out

include ../GNU_makefile_template

LOCFLAGS = -I../utils

construct_binarytree.out: construct_binarytree.o ../utils/binarytree.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) construct_binarytree.o ../utils/binarytree.o -o construct_binarytree.out
