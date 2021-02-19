/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (!head) {
        return false;
    }
    ListNode *fast = head, *slow = head;
    while (n-- && fast) {
        fast = fast->next;
    }

    if (!fast) {
        return head->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *node = slow->next;
    if (node) {
        slow->next = node->next;
        free(node);
        node = NULL;
    }
    return head;
}
// @lc code=end

