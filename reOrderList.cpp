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
	void reorderList(ListNode* head) {
		ListNode* s = head, *f = head;
		while (f && f->next) {
			s = s->next;
			f = f->next->next;
		}
		ListNode* newHead = reverseLL(s->next);
		s->next = NULL;
		// printLL(head);
		// printLL(newHead);
		while (newHead) {
			s = head; f = newHead;
			head = head->next;
			newHead = newHead->next;
			s->next = f;
			f->next = head;
		}
	}
private:
	ListNode* reverseLL(ListNode* head) {
		ListNode* r = NULL, *q = NULL, *p = head;
		while (p) {
			r = q;
			q = p;
			p = p->next;

			q -> next = r;
		}
		return q;
	}
	void printLL(ListNode* head) {
		while (head) {
			cout << head->val << " -> ";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
};