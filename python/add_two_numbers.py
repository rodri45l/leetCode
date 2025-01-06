from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return f"ListNode({self.val})"


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        next_add = 0
        last = True
        results = []
        last_flag = False
        if l1.next is None and l2.next is None:
            last_flag = True
        while l1.next or l2.next or last:
            result_node = ListNode()
            val1 = l1.val
            val2 = l2.val
            result = val1 + val2 + next_add
            if result > 9:
                result = result - 10
                next_add = 1
            else:
                next_add = 0
            result_node.val = result
            results.append(result_node)
            l1.val = 0 if not l1.next else l1.val
            l1 = l1.next if l1.next else l1
            l2.val = 0 if not l2.next else l2.val
            l2 = l2.next if l2.next else l2
            if last_flag:
                last = False
            if l1.next is None and l2.next is None:
                last_flag = True

        next_item = None
        if next_add != 0:
            result_node = ListNode()
            result_node.val = 1
            result_node.next = None
            results.append(result_node)
        print(results)
        for item in results[::-1]:
            if next_item:
                item.next = next_item
                next_item = item
            else:
                next_item = item
        return next_item


if __name__ == "__main__":
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    solution = Solution()
    result = solution.addTwoNumbers(l1, l2)
    while result:
        print(result.val)
        result = result.next
