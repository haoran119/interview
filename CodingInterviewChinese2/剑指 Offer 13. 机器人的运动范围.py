from queue import Queue

class Solution:
    # BFS
    def movingCount1(self, m: int, n: int, k: int) -> int:
        def sum_of_digit(number):
            result = 0

            while number:
                result += number % 10
                number //= 10

            return result

        # FIFO queue
        q = Queue()
        q.put((0, 0))
        s = set()

        while not q.empty():
            # remove and return an item from the queue
            x, y = q.get()

            if ((x, y) not in s) and 0 <= x < m and 0 <= y < n and (sum_of_digit(x) + sum_of_digit(y) <= k):
                # add current grid to the result set
                s.add((x, y))
                # append next down grid and next right grid to the queue
                for next_x, next_y in [(x + 1, y), (x, y + 1)]:
                    # note that the element is a tuple of (x, y) rather than x, y
                    q.put((next_x, next_y))

        # size of result set
        return len(s)


    # iteration
    # Same as the above BFS solution, we only consider visit the next down grid and next right grid
    # so we could get the status formular : visitable[i][j] = visitable[i−1][j] or visitable[i][j−1],
    # where visitable[0][0] = True.
    # Finally we could iterate all grids from [0, 0] to [m, n] to calculate all visitable grids
    def movingCount(self, m: int, n: int, k: int) -> int:
        def sum_of_digit(number):
            result = 0

            while number:
                result += number % 10
                number //= 10

            return result

        # note that the result set element is a list of tuple (x, y)
        visitable = set([(0, 0)])

        for x in range(m):
            for y in range(n):
                if ((x - 1, y) in visitable or (x, y - 1) in visitable) and sum_of_digit(x) + sum_of_digit(y) <= k:
                    visitable.add((x, y))

        return len(visitable)


if __name__ == '__main__':
    mySolution = Solution()

    m = 2
    n = 3
    k = 1

    print(mySolution.movingCount(m, n, k))
