#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

void show_in_console(struct DLL* pointer_to_list) {
    T_DLL first = pointer_to_list->first;
    while (first != NULL ) {
        printf("%d -> ", first->elem);
        first = first->next;
    }
    printf("NULL\n");
}

int main(void) {
    int i, is_in;
    struct DLL list;
    printf("creation:\n");
    create(&list);
    show_in_console(&list);
    printf("Insertions:\n");
    for (i = 0; i < 6; i++) {
        insert_beginning(&list, i);
        insert_end(&list, i);
        show_in_console(&list);
    }

    printf("Destruction:\n");
    destroy(&list);
    show_in_console(&list);

    for (i = 0; i < 5; i++) {
        insert_beginning(&list, i);
    }

    printf("Deletion at the end:\n");
    show_in_console(&list);
    delete_end(&list);
    show_in_console(&list);

    //DELETE NODE

    printf("Deletion at a given position:\n");
    printf("At %d\n", 3);
    delete_node_from_DLL(&list, 3);
    show_in_console(&list);
    printf("At %d\n", 1);
    delete_node_from_DLL(&list, 1);
    show_in_console(&list);
    printf("At %d\n", 0);
    delete_node_from_DLL(&list, 0);
    show_in_console(&list);
    printf("At %d\n", 0);
    delete_node_from_DLL(&list, 0);
    show_in_console(&list);

    //SEARCH
    printf("Searching:\n");
    for (i = 0; i < 5; i++) {
        insert_beginning(&list, i);
    }
    show_in_console(&list);
    is_in = contains(&list, 3);
    if (is_in) {
        printf("%d is in list", 3);
    } else {
        printf("3 is not in list");
    }
    printf("\n");
    is_in = contains(&list, i);
    if (is_in) {
        printf("%d is in list", i);
    } else {
        printf("%d is not in list", i);
    }
    printf("\n");

    //Bubble SORT
    printf("Bubble sorting:\n");
    bubble_sort_list(&list);
    show_in_console(&list);

    ////////

    return EXIT_SUCCESS;
}
