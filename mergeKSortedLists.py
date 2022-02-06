# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        q = PriorityQueue()
        for idx, node in enumerate(lists):
            if node:
                q.put((node.val, idx, node))
        while q.qsize():
            val, idx, node = q.get()
            cur.next = node
            if node.next:
                q.put((node.next.val, idx, node.next))
            cur = cur.next
        return dummy.next