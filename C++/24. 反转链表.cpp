/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        // 1->3->5->7->9
        // 1<-3  5  7->9
        // 用tmp记录后一个节点，防止链表断开
        // 用prev记录前一个节点，以改变指针next的指向
        // cur指向当前节点
        ListNode *tmp = NULL, *prev = NULL, *cur = head;
        while (cur) {
            tmp = cur->next;   // 记录后一个结点
            cur->next = prev;  // 改变指向
            prev = cur;        // prev后移
            cur = tmp;         // cur后移
        }
        return prev;  // cur为空时跳出循环，前一个结点prev即为新的链表头
    }
};