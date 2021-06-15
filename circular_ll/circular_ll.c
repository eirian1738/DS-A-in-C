#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHECK_MALLOC(ptr) if (ptr == NULL) {exit(EXIT_FAILURE);}

#define PRINT_BOOL(x) fputs(x ? "true\n" : "false\n",stdout)

typedef int info;

struct Circular_ll {
    info data;
    struct Circular_ll *next;
};

typedef struct Circular_ll Node;

typedef Node* Start;

Start init(info elem) {
    Start start = malloc(sizeof(Node));
    CHECK_MALLOC(start); 
    start -> data = elem;
    start -> next = start;
    return start;
}

void insert_at_begin(Start* start, info elem) {
    Node* new = malloc(sizeof(Node));
    CHECK_MALLOC(new);
    new -> data = elem;
    new -> next = NULL;
    Node* temp = *start;
    while (temp -> next != *start) {
        temp = temp -> next;
    }

    new->next = *start;
    *start = new;
    temp->next = *start;
}

void print_list(Start start) {
    Node* ptr = start;
    while (ptr->next != start) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Element: %d\n", ptr->data);
}

void insert_at_end(Start* start, info elem) {
    Node *new = malloc(sizeof(Node));
    CHECK_MALLOC(new);
    new -> data = elem;
    new -> next = NULL;
    Node *temp = *start;
    while (temp -> next != *start) {
        temp = temp -> next;
    }
    new -> next = temp -> next;
    temp -> next = new;
}

bool search(Start start, info elem) {
    bool flag = false;
    Node *ptr = start;
    while (ptr -> next != start) {
        if (ptr -> data == elem ) {
            flag = true;
            break;
        }
        else {
            ptr = ptr-> next;
        }
    }
    return flag;
}

void delete_at_begin(Start *start) {
    // temp1 points at the first node
    Node *temp1 = *start;
    // temp2 will move to the last node
    Node *temp2 = *start;
    while (temp2 -> next != *start) {
        temp2 = temp2-> next;
    }

    // make the last node and the start point at the second node now
    temp2 -> next = temp1 -> next;
    *start = temp1 -> next;
    // destroy first node
    temp1 -> next = NULL;
    free(temp1);
}

void delete_at_end(Start *start) {
    Node *temp1 = *start;
    Node *temp2 = NULL;

    while (temp1 -> next != *start) {
        temp2 = temp1;
        temp1 = temp1 -> next;
    }

    temp2 -> next = *start;
    temp1 -> next = NULL;
    free(temp1);
}


int main(int argc, char* argv[]) {
    
    Start my_circular = init(10);
    insert_at_begin(&my_circular, 11);
    insert_at_begin(&my_circular, 176);
    insert_at_begin(&my_circular, 189);
    insert_at_begin(&my_circular, 1777);
    insert_at_begin(&my_circular, 1635);
    insert_at_end(&my_circular, 256);
    insert_at_end(&my_circular, 27);
    insert_at_end(&my_circular, 2876);
    insert_at_end(&my_circular, 22864);

    print_list(my_circular);
    
    bool is_in_list = search(my_circular, 27);
    bool is_not_in_list = search(my_circular, 34);
    bool is_in_2 = search(my_circular, 1777);

    PRINT_BOOL(is_in_list);
    PRINT_BOOL(is_not_in_list);
    PRINT_BOOL(is_in_2);
    delete_at_begin(&my_circular);
    delete_at_begin(&my_circular);
    delete_at_begin(&my_circular);
    printf("After 3 deletes at begin\n");
    print_list(my_circular);
    delete_at_end(&my_circular);
    printf("After 3 deletes at end\n");
    print_list(my_circular);
    insert_at_begin(&my_circular, 765);
    insert_at_end(&my_circular, 5354);
    printf("After 1 add in begin and 1 in end\n");
    print_list(my_circular);

return EXIT_SUCCESS;
}
