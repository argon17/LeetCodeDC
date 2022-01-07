/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *head;
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    int getRandom() {
        int ans;
        ListNode* cur = head;
        for(int len = 1; cur; cur = cur -> next, ++len)
            // P(choosing current node) = P(choosing 0 out of [0, 1, ...(len - 1)]) = 1/len
            if(rand() % len == 0) 
                ans = cur -> val;
        return ans;
        // P(ith node is the answer) = P(ith node is choosen) * P((i+1)th node is not choosen) * ... * P((len - 1)th node not choosen)
        //                           = 1 / i * (1 - 1/(i+1)) * (1 - 1/(i+2)) * ... * (1 - 1/len)
        //                           = 1/i * i/(i+1) * (i+1)/(i+2) * ... * (len - 1)/len
        //                           = 1 / len
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */