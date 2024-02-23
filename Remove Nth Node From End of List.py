class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        temp = dummy
        temp1 = dummy
        for i in range(n):
            temp1 = temp1.next
            if not temp1:
                return head.next
        while temp1.next:
            temp = temp.next
            temp1 = temp1.next
        temp.next = temp.next.next
        return dummy.next
