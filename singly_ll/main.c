#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singly_ll.h"

int main(int argc, char* argv[]) {

    Start head = init(10);
    add_Node_at_begin(&head, 2);
    add_Node_at_begin(&head, 3);
    add_Node_at_begin(&head, 4);
    add_Node_at_end(&head, 14);
    add_Node_at_end(&head, 16);

    puts("BEFORE DELETE");
    print_list(head);
    int is_in_list = search_elem(head, 4);
    PRINT_BOOL(is_in_list);
    puts("AFTER DELETE AT BEGIN");
    del_Node_at_begin(&head);
    print_list(head);
    printf("LUNGHEZZA LISTA: %d\n", list_len(head));
    puts("AFTER DELETE AT END");
    del_Node_at_end(&head);
    print_list(head);
    printf("LUNGHEZZA LISTA: %d\n", list_len(head));
    puts("AFTER DELETE AT END");
    del_Node_at_end(&head);
    print_list(head);
    printf("LUNGHEZZA LISTA: %d\n", list_len(head));
    puts("AFTER ADD 76 AT END");
    add_Node_at_end(&head,76);
    print_list(head);
    printf("LUNGHEZZA LISTA: %d\n", list_len(head));
    add_Node_at_end(&head,119);
    add_Node_at_end(&head,276);
    printf("LUNGHEZZA LISTA: %d\n", list_len(head));
    print_list(head);
    del_Node_after_pos(&head,2);
    puts("AFTER DELET AFTER POS 3");
    print_list(head);

return EXIT_SUCCESS;
}
