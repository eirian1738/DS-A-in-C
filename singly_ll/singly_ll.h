// Learning purpose implementation of singly linked list

// macro for printing boolean values
#define PRINT_BOOL(x) fputs(x ? "true\n" : "false\n",stdout)

// macro for checking malloc return value
#define CHECK_MALLOC(ptr) if (ptr == NULL) {exit(EXIT_FAILURE);}

// type definition for data inside nodes
typedef int info;

// list definition
struct Singly_ll {
    info data;
    struct Singly_ll *next;
};

typedef struct Singly_ll Node;

// type def for the starting point
typedef Node *Start;

/* Create the first node
 * @param type info - element to be added in the first node
 * @return Node* - a pointer to the first node

*/
Start init(info elem);

// Add node before the first node - O(1)
void add_Node_at_begin(Start *node, info elem);

// Add node after the last node - O(n)
void add_Node_at_end(Start *node, info elem);

// Traverse the list and print the content of each node - O(n)
void print_list(Start node);

// Traverse the list and search if the element passed as parameter is present the in list
bool search_elem(Start node, info elem);

// Delete the first node in the list - O(1)
void del_Node_at_begin(Start *node);

// Delete the last node in the list - O(n)
void del_Node_at_end(Start *node);

// Return the length of the list - O(n)
int list_len(Start node);

// Delete the node after the given position - O(n) in the worst case
void del_Node_after_pos(Start *node, int pos); 
