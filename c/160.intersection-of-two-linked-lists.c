/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define _method_1 0
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode *list_a = headA;
    struct ListNode *list_b = headB;
#if _method_1
    int len_a = 0, len_b = 0;

    while (list_a || list_b) {
        (list_a == NULL) ? list_a = NULL : (list_a = list_a->next, len_a++);
        (list_b == NULL) ? list_b = NULL : (list_b = list_b->next, len_b++);
    }
    int diff = (len_a > len_b) ? len_a - len_b : len_b - len_a;
    bool long_a = (len_a > len_b) ? true : false;
    list_a = headA;
    list_b = headB;
    if (long_a) {
        while (diff--) {
            list_a = list_a->next;
        }
    } else {
        while (diff--) {
            list_b = list_b->next;
        }
    }
    while (list_a != list_b) {
        list_a = list_a->next;
        list_b = list_b->next;
    }
#else
    while (list_a != list_b) {
        list_a = list_a ? list_a->next : headB;
        list_b = list_b ? list_b->next : headA;
    }
#endif
    return list_a;
}
// @lc code=end

