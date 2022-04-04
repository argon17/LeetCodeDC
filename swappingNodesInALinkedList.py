# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        prev1, cur1 = dummy, head
        _k = k - 1
        while _k:
            prev1 = cur1
            cur1 = cur1.next
            _k -= 1
        prev2, cur2 = dummy, head
        checker = cur1
        while checker.next:
            prev2 = cur2
            cur2 = cur2.next
            checker = checker.next

        if cur1 == cur2:
            return dummy.next
        
        prev1.next, prev2.next = cur2, cur1
        cur1.next, cur2.next = cur2.next, cur1.next
        return dummy.next
