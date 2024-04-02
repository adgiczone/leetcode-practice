/*
 * @lc app=leetcode id=142 lang=c
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !(head->next)) {
        return false;
    }
    struct ListNode *slow = head->next;
    struct ListNode *fast = head->next->next;
    while (fast && slow != fast ) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : NULL;
    }
    if (fast) {
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return (fast);
}

    // @lc code=end
