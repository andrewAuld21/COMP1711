#include <stdio.h>
#include <stdlib.h>

 typedef struct list {
    int data;
    struct list* next_element;
} list;


int main()
{
    // making an instance of the 'list' struct called 'first_node'
    list first_node;

    // assigns a value of 5 to the 'data' integer in 'first_node'
    first_node.data = 5;

    // assigns a memory size of the same size as 'struct list' to the 'next_element' element of 'first_node'
    // using malloc (memory allocation)
    first_node.next_element = (list*) malloc(sizeof(struct list));

    // prints out the 'data' element of the 'list' instance 'first_node'
    printf("first_node data = %d \n", first_node.data);
   
    // prints out the 'next_element' element of the 'list' instance 'first_node'
    printf("first_node next_element address = %p \n", first_node.next_element);

    //printf("first_node data = %d \n", first_node.next_element.data);

}