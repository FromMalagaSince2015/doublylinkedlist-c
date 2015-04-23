#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

typedef struct T_Node* T_DLL;
struct T_Node {
    int elem;
    T_DLL prev;
    T_DLL next;
};

struct DLL {
    T_DLL first;
    T_DLL last;
};

void create(struct DLL* pointer_to_list);
int is_empty(struct DLL* pointer_to_list);
int contains(struct DLL* pointer_to_list, int elem);
void insert_beginning(struct DLL* pointer_to_list, int elem);
void insert_end(struct DLL* pointer_to_list, int elem);
void delete_beginning(struct DLL* pointer_to_list);
void delete_end(struct DLL* pointer_to_list);
void destroy(struct DLL* pointer_to_list);
void delete_node_from_DLL(struct DLL* pointer_to_list, int index);
void bubble_sort_list(struct DLL* pointer_to_list);

#endif /* DOUBLYLINKEDLIST_H_ */
