/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (!head) {
        return NULL;
    }
    struct ListNode *ret = head;
    struct ListNode *prev = NULL;
    struct ListNode *node = NULL;
    while (head) {
        if (head->val == val) {
            node = head;
            if (prev) {
                prev->next = head->next;
            }
            else {
                ret = head->next;
            }
            head = head->next;
            free(node);
            continue;
        }
        prev = head;
        head = head->next;
    }
    return ret;
}
// @lc code=end

