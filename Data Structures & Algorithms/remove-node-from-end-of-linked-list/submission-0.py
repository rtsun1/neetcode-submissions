# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def reverse(node):
    prev = None
    while node:
        go_to = node.next
        node.next = prev
        prev = node
        node = go_to
    return prev
    
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = reverse(head)

        # remove
        prev = None
        node = head
        idx = 0
        while idx != n - 1:
            prev = node
            node = node.next
            idx += 1
        if prev is None: # node to remove is head
            head = head.next
        else:
            prev.next = node.next

        head = reverse(head)

        return head