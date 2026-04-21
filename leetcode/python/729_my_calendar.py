from sortedcontainers import SortedDict

def next_key(data, key):
    keys = list(data)
    idx = keys.index(key)
    nxt_key = keys[idx + 1]
    return nxt_key


class MyCalendar:

    def __init__(self):
        self.books = SortedDict({})
    
    def check_book(self, startTime, endTime):
        counter = 0
        for x in self.books.keys():
            if x <= startTime:
                counter += self.books[x]
            elif x < endTime and x >= startTime:
                return False
            elif counter > 0:
                return False
        return True


    def book(self, startTime: int, endTime: int) -> bool:
        #print(f"check book {startTime} {endTime}" )
        prev = 0
        if self.check_book(startTime, endTime):
            if startTime in self.books:
                prev = self.books[startTime]
                self.books[startTime] = 1
            else:
                self.books[startTime] = 1
            if endTime in self.books:
                self.books[endTime] -= 1    
            else:
                self.books[endTime] = -1
            # update based on prev
            if prev < 0:
                self.books[endTime] -=abs(prev)
            #print(self.books)
            return True
        #print(self.books)
        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)