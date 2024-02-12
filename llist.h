// llist.h

#ifndef LLIST_H
#define LLIST_H

struct node {
    int value;
    struct node *next;
};

void llist_insert_head(struct node **head, struct node *n);
struct node *llist_delete_head(struct node **head);

void llist_insert_tail(struct node **head, struct node *n);

void llist_print(struct node *head);
void llist_free(struct node **head);

struct node *node_alloc(int value);
void node_free(struct node *n);

void llist_insert_head(struct node **head, struct node *n) {
    n->next = *head;
    *head = n;
}

struct node *node_alloc(int value) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node != NULL) {
        node->value = value; // assign a value to the node
        node->next = NULL; 
    }
    return node;
}

struct node *llist_delete_head(struct node **head) {
    struct node *temp = *head; // reassign head to temp variable and make the head point to the next node.
    if (*head != NULL) {
        *head = (*head)->next;
    }
    return temp;
}

void llist_insert_tail(struct node **head, struct node *n) {
    // go through each node until reaching null `next` and then point to the new new passed in
    if (*head == NULL) {
        *head = n;
    } else 
    {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
    }
    n->next = NULL;
}

void llist_print(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("\n");
}

void llist_free(struct node **head) {
    // go through each node and reassign head to point to next node and then free the previous node
    struct node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void node_free(struct node *n) {
    // pass in a node and free from memory
    free(n);
}

#endif