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
    vector<int> reversePrint(ListNode* head) {
        // 正序遍历链表，res 存储节点数值
        vector<int> res;
        for (ListNode* p = head; p != NULL; p = p->next) {
            res.push_back(p->val);
        }
        // 反转 res
        reverse(res.begin(), res.end());
        return res;
    }
};