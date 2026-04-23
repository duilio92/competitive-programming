
class Solution:
    def k_is_ok(self, k, piles, h):
        hours = 0
        for pile in piles:
            hours += ceil(pile/ k)
        return hours <= h

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left =1 
        right = max(piles)

        while left < right:
            mid = (left + right) // 2
            if self.k_is_ok(mid, piles, h):
                right = mid
            else:
                left= mid +1
        return left