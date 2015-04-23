#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

void create(struct DLL* pointer_to_list) {
    pointer_to_list->first = NULL;
    pointer_to_list->last = NULL;
}

int is_empty(struct DLL* pointer_to_list) {
    return pointer_to_list->first == NULL && pointer_to_list->last == NULL ;
}

int equals(int c, int elem) {
    return c == elem;
}
/**
 *
 */
void find(struct DLL* pointer_to_list, int (*predicate)(int, int),
        T_DLL* node_to_find, int elem) {
    T_DLL node = pointer_to_list->first;
    while (node != NULL && !predicate(node->elem, elem)) {
        node = node->next;
    }
    *node_to_find = node;
}

int contains(struct DLL* pointer_to_list, int elem) {
    T_DLL node;
    find(pointer_to_list, equals, &node, elem);
    return node != NULL ;
}

void insert_beginning(struct DLL* pointer_to_list, int elem) {
    //TODO check errors
    T_DLL pointer_to_new_node = (T_DLL) malloc(sizeof(struct T_Node));
    pointer_to_new_node->elem = elem;
    pointer_to_new_node->prev = NULL;
    pointer_to_new_node->next = pointer_to_list->first;
    if (is_empty(pointer_to_list)) {
        pointer_to_list->last = pointer_to_new_node;
    } else {
        pointer_to_list->first->prev = pointer_to_new_node;
    }
    pointer_to_list->first = pointer_to_new_node;
}

void insert_end(struct DLL* pointer_to_list, int elem) {
    //TODO check errors
    T_DLL pointer_to_new_node = (T_DLL) malloc(sizeof(struct T_Node));
    pointer_to_new_node->elem = elem;
    pointer_to_new_node->next = NULL;
    pointer_to_new_node->prev = pointer_to_list->last;
    if (is_empty(pointer_to_list)) {
        pointer_to_list->first = pointer_to_new_node;
    } else {
        pointer_to_list->last->next = pointer_to_new_node;
    }
    pointer_to_list->last = pointer_to_new_node;
}


void delete_end(struct DLL* pointer_to_list) {
    T_DLL last;
    if (!is_empty(pointer_to_list)) {
        last = pointer_to_list->last;
        if (last->prev == NULL ) {
            pointer_to_list->first = NULL;
            pointer_to_list->last = NULL;
        } else {
            pointer_to_list->last = pointer_to_list->last->prev;
            pointer_to_list->last->next = NULL;
        }
        free(last);
    } else {
        //check errors //TODO
    }
}

void delete_beginning(struct DLL* pointer_to_list) {
    T_DLL first;
    if (!is_empty(pointer_to_list)) {
        first = pointer_to_list->first;
        if (first->next == NULL ) {
            pointer_to_list->first = NULL;
            pointer_to_list->last = NULL;
        } else {
            pointer_to_list->first = pointer_to_list->first->next;
            pointer_to_list->first->prev = NULL;
        }
        free(first);
    } else {
        //check errors //TODO
    }
}
void destroy(struct DLL* pointer_to_list) {
    T_DLL first = pointer_to_list->first;
    while (first != NULL ) {
        pointer_to_list->first = pointer_to_list->first->next;
        free(first);
        first = pointer_to_list->first;
    }
    pointer_to_list->last = NULL;
}
void delete_node_from_DLL(struct DLL* pointer_to_list, int index) {
    int i = 0;
    T_DLL previous, next;
    T_DLL pointer_to_node = pointer_to_list->first;
    while (pointer_to_node != NULL && i < index) {
        pointer_to_node = pointer_to_node->next;
        i++;
    }

    if (pointer_to_node != NULL ) {
        if (pointer_to_node->next == NULL && pointer_to_node->prev == NULL ) {
            destroy(pointer_to_list);
        } else if (pointer_to_node->prev == NULL ) {
            delete_beginning(pointer_to_list);
        } else if (pointer_to_node->next == NULL ) {
            delete_end(pointer_to_list);
        } else {
            previous = pointer_to_node->prev;
            next = pointer_to_node->next;
            previous->next = next;
            next->prev = previous;
            free(pointer_to_node);
        }
    }
}

void bubble_sort_list(struct DLL* pointer_to_list) {
    T_DLL end_list = pointer_to_list->last;
    T_DLL aux_prev, aux_now = pointer_to_list->first;
    if (aux_now != NULL ) {
        aux_prev = aux_now;
        aux_now = aux_now->next;
        while (end_list != NULL ) {
            while (aux_now != NULL ) {
                if (aux_prev->elem > aux_now->elem) {
                    aux_prev->elem -= aux_now->elem;
                    aux_now->elem += aux_prev->elem;
                    aux_prev->elem = aux_now->elem - aux_prev->elem;
                }
                aux_prev = aux_now;
                aux_now = aux_now->next;
            }
            end_list = end_list->prev;
            aux_prev = pointer_to_list->first;
            aux_now = aux_prev->next;
        }
    }

}
