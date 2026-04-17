from typing import List
from collections import deque
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visit_count = 1
        visited = [False] * len(rooms)
        visited[0] = True
        keys  = deque()
        for x in rooms[0]:
            keys.append(x)
        while keys:
            room = keys.popleft()
            if not visited[room]:
                visited[room] = True
                for x in rooms[room]:
                    keys.append(x)
                visit_count += 1
            if visit_count == len(rooms):
                return True
        return False
