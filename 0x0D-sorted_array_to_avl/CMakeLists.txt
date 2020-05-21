project(arrayToAVL_lib C)

set(HEADER_FILES binary_trees.h)

set(SOURCE_FILES 0-sorted_array_to_avl.c binary_tree_print.c print_array.c)

add_library(arrayToAVL_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(Basic main.c ${SOURCE_FILES} binary_tree_print.c print_array.c)