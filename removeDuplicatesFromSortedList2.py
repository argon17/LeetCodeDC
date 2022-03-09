# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        cur = head
        while cur and cur.val == head.val:
            cur = cur.next
        nex = self.deleteDuplicates(cur)
        if cur != head.next:
            return nex
        head.next = nex
        return head
