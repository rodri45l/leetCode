# https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
import random


class RandomizedSet:
    def __init__(self):
        self.values = []  # List to store elements
        self.index_map = {}  # Dictionary to store value-to-index mapping

    def insert(self, val: int) -> bool:
        if val in self.index_map:
            return False
        # Add the value to the list and update the dictionary
        self.index_map[val] = len(self.values)
        self.values.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.index_map:
            return False
        # Get the index of the value to be removed
        idx_to_remove = self.index_map[val]
        last_val = self.values[-1]  # Get the last value in the list

        # Swap the value to remove with the last element
        self.values[idx_to_remove] = last_val
        self.index_map[last_val] = idx_to_remove

        # Remove the last element from the list and delete from the dictionary
        self.values.pop()
        del self.index_map[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.values)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
