import heapq

heap = []


heapq.heappush(heap, 3)
heapq.heappush(heap, 10)
heapq.heappush(heap, 5)
heapq.heappush(heap, 21)


for _ in range(4):
    print(heapq.heappop(heap))

