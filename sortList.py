# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        def merge(h1, h2):
            dummy = cur = ListNode()
            while h1 and h2:
                if h1.val < h2.val:
                    cur.next, h1 = h1, h1.next
                else:
                    cur.next, h2 = h2, h2.next
                cur = cur.next
            cur.next = h1 or h2
            return dummy.next
        pre, slow, fast = None, head, head
        while fast and fast.next:
            pre, slow, fast = slow, slow.next, fast.next.next
        pre.next = None
        left = self.sortList(head)
        right = self.sortList(slow)
        return merge(left, right)