/*
 * @lc app=leetcode id=707 lang=c
 *
 * [707] Design Linked List
 */

// @lc code=start

//#ifndef _DEBUG
//#define DEBUG 0
//#endif

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

#if defined DEBUG
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
/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *link_list = malloc(sizeof(MyLinkedList));
    link_list->val = -1;
    link_list->next = NULL;
#if defined DEBUG
    printf("%s\n", __func__);
    print_link_list(link_list);
#endif
    return link_list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
#if defined DEBUG
    printf("%s %d\n", __func__, index);
    print_link_list(obj);
#endif
    if (!obj) {
        return -1;
    }
    MyLinkedList *iter = obj;
    for (int i = 0; i < index + 1; i++) {
        if (iter && iter->next) {
            iter = iter->next;
        }
        else {
            return -1;
        }
    }
    return iter->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
#if defined DEBUG
    printf("%s: %d\n", __func__, val);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }

    MyLinkedList *node = malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = obj->next;
    obj->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
#if defined DEBUG
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
    iter->next = malloc(sizeof(MyLinkedList));
    iter->next->val = val;
    iter->next->next = NULL;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
#if defined DEBUG
    printf("%s [%d]:%d\n", __func__, index, val);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }
    MyLinkedList *iter = obj;

    for (int i = 1; i < index + 1; ++i) {
        if (!iter || (!iter->next && i == index)) {
            break;
        }
        iter = iter->next;
    }
    if (iter) {
        MyLinkedList *node = malloc(sizeof(MyLinkedList));
        node->val = val;
        node->next = iter->next;
        iter->next = node;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
#if defined DEBUG
    printf("%s %d\n", __func__,index);
    print_link_list(obj);
#endif
    if (!obj) {
        return;
    }
    MyLinkedList *iter = obj;

    for (int i = 0; i < index; ++i) {
        if (!iter) {
            return;
        }
        iter = iter->next;
    }
    if (iter) {
        MyLinkedList *node = iter->next;
        iter->next = node ? node->next : NULL;
        free(node);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
#if defined DEBUG
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

