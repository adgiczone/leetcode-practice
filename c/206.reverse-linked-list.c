/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if (!head) {
        return NULL;
    }
    struct ListNode *prev = NULL;
    struct ListNode *node = NULL;

    while (head) {
        node = head->next;
        head->next = prev;
        prev = head;
        head = node;
    }
    return prev;
}
// @lc code=end

