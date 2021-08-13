class Solution:
    # Heap
    # Time : O(NlogN) / Space : O(N)
    # add ugly number into a min heap, and then pop the smallest item and regenerate the next
    # ugly number
    def nthUglyNumber1(self, n: int) -> int:
        if n is None:
            return
        
        # initiation
        factors = [2, 3, 5]
        # use a set to avoid duplicates
        seen = {1}
        # first ugly number
        heap_num = [1]

        # generate the following n-1 ugly numbers
        for i in range(n - 1):
            # Pop and return the smallest item from the heap, maintaining the heap invariant.
            current = heapq.heappop(heap_num)

            for factor in factors:
                candidate = current * factor
                if candidate not in seen:
                    seen.add(candidate)
                    # Push the value item onto the heap, maintaining the heap invariant.
                    heapq.heappush(heap_num, candidate)
        
        return heapq.heappop(heap_num)

    # DP + 3 pointers
    # define f[i] as the ith ugly number, and 3 pointers p2/p3/p5 as the candidate to multiply 
    # factors 2/3/5 to generate the next ugly number
    # f[i] = min{f[p2] * 2, f[p3] * 3, f[p5] * 5}
    # f[1], p2, p3, p5 = 1, 1, 1, 1
    # target f[n]
    def nthUglyNumber(self, n: int) -> int:
        if n is None:
            return

        f = [0] * (n + 1)
        f[1] = 1
        p2, p3, p5 = 1, 1, 1

        for i in range(2, n + 1):
            num2, num3, num5 = f[p2] * 2, f[p3] * 3, f[p5] * 5
            f[i] = min(num2, num3, num5)

            # increase the pointer if the candidate is used, so that duplicates is avoided
            if f[i] == num2:
                p2 += 1
            if f[i] == num3:
                p3 += 1
            if f[i] == num5:
                p5 += 1
        
        return f[n]
