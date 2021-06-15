#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_ll.h"
 
Start init(info elem) {
    Start start = malloc(sizeof(Node));
    CHECK_MALLOC(start);
    start->data = elem;
    start->next = NULL;
    return start;
}

void add_Node_at_begin(Start *node, info elem) {
    Node *temp = *node;
    Node *new_node = malloc(sizeof(Node));
    CHECK_MALLOC(new_node);
    new_node->data = elem;
    new_node->next = temp;
    *node = new_node;
}

void add_Node_at_end(Start *node, info elem) {
    Node *new_node = malloc(sizeof(Node));
    CHECK_MALLOC(new_node);
    new_node->data = elem;
    new_node->next = NULL;
    Node *ptr = *node;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void print_list(Start node) {
    Node *ptr = node;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}

bool search_elem(Start node, info elem) {
    Node *ptr = node;
    int flag = false;
    while (ptr != NULL) {
        if (ptr->data == elem) {
            flag = true;
            break;
        } 
    ptr = ptr->next;
    }
    return flag;
}

void del_Node_at_begin(Start *node) {
    if (*node == NULL) {
        return;
    }
    Node* temp = *node;
    *node = (*node)->next;
    free(temp);
}

void del_Node_at_end(Start *node) {
    if (*node == NULL) {
        return;
    }
    Node *ptr = *node;
    Node *ptr_prev = NULL;
    while (ptr->next != NULL) {
        ptr_prev = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    ptr_prev->next = NULL;
}

int list_len(Start node) {
    if (node == NULL) {
        return 0;
    }
    int length = 1;
    Node *ptr = node;
    while (ptr->next != NULL) {
        length += 1;
        ptr = ptr->next;
    }
    return length;
}

void del_Node_after_pos(Start *node, int pos) {
    if (*node == NULL) {
        return;
    }
    if (pos >= list_len(*node)) {
        return;
    }
    Node *ptr = *node;
    int count = 0;
    while (count != pos) {
        ptr = ptr->next;
        count++;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}
