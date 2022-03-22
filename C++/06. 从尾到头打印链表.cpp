/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法一：辅助栈
class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        ListNode* p = head;
        while (p) {
            stk.push(p->val);
            p = p->next;
        }
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

// 方法二：递归
class Solution {
   public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (head) {
            reversePrint(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};