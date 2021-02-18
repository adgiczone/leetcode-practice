/*
 * @lc app=leetcode id=707 lang=c
 *
 * [707] Design Linked List
 */

// @lc code=start

#define DEBUG 0

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

#if DEBUG
void print_link_list(MyLinkedList *obj)
{
    MyLinkedList *root = obj;
    int i = 0;
    printf("%s:\n", __func__);

    while (root) {
        printf("link[%d] = %d %p\n", i++, root->val, root);
        root = root->next;
    }
}
#endif

MyLinkedList *create_node(int value)
{
    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    if (!node) {
        return NULL;
    }
    node->val = value;
    node->next = NULL;
    return node;
}

MyLinkedList *get_node(int index, MyLinkedList *root)
{
    MyLinkedList *iter = root;
    int i = 0;
    while ((i++) < index && root) {
        iter = iter->next;
    }
    return iter;
}
/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *link_list = malloc(sizeof(MyLinkedList));
    link_list->val = -1;
    link_list->next = NULL;
#if DEBUG
    printf("%s\n", __func__);
    print_link_list(link_list);
#endif
    return link_list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
#if DEBUG
    printf("%s %d\n", __func__, index);
    print_link_list(obj);
#endif
    if (!obj) {
        return -1;
    }
    MyLinkedList *node = get_node(index, obj->next);
    return node ? node->val : -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    if (!obj) {
        return;
    }

    MyLinkedList *node = create_node(val);
    node->next = obj->next;
    obj->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
#if DEBUG
    printf("%s:%d\n", __func__, val);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }
    MyLinkedList *iter = obj;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = create_node(val);
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
#if DEBUG
    printf("%s [%d]:%d\n", __func__, index, val);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }
    MyLinkedList *iter = get_node(index, obj);

    if (iter) {
        MyLinkedList *node = create_node(val);
        node->next = iter->next;
        iter->next = node;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
#if DEBUG
    printf("%s %d\n", __func__,index);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }
    MyLinkedList *iter = get_node(index, obj);

    if (iter) {
        MyLinkedList *node = iter->next;
        iter->next = node ? node->next : NULL;
        free(node);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
#if DEBUG
    printf("%s %p\n", __func__, obj);
#endif
    if (!obj) {
        return;
    }
    while(obj) {
        MyLinkedList *node = obj;
        obj = obj->next;
        free(node);
        node = NULL;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
// @lc code=end

