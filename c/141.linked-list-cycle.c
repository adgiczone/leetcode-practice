/*
 * @lc app=leetcode id=141 lang=c
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head || !(head->next)) {
        return false;
    }
    struct ListNode *fast = head->next->next;
    while (fast && head != fast ) {
        head = head->next;
        fast = fast->next ? fast->next->next : NULL;
    }
    return (fast);
}
// @lc code=end

