#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

/* 
    This is a simple singly linked list implementation that takes arguments from the command line 
    and parses each command in the order they were entered.
    https://github.com/isaacbrickner/CS374_linked_list
    https://www.digitalocean.com/community/tutorials/arrow-operator-c-plus-plus
    https://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm
*/

int main(int argc, char *argv[]){

    struct node *head = NULL;

    // parse command line for matching linked list commands
    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "ih") == 0) { // insert head
            if (i + 1 < argc) {
                int node_value = atoi(argv[++i]);
                struct node *new_node = node_alloc(node_value);
                if(new_node != NULL) {
                    llist_insert_head(&head, new_node);
            }
            }
        } else if (strcmp(argv[i], "it") == 0) { // insert tail
            if (i + 1 < argc) {
                int node_value = atoi(argv[++i]);
                struct node *new_node = node_alloc(node_value);
                if (new_node != NULL) {
                    llist_insert_tail(&head, new_node);
                }
                }
        } else if (strcmp(argv[i], "dh") == 0) {
            llist_delete_head(&head);
        } else if (strcmp(argv[i], "f") == 0) {
            llist_free(&head);
        } else if (strcmp(argv[i], "p") == 0) { 
            llist_print(head);
        }
    }

    return 0;
}


