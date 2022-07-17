import heapq
from queue import PriorityQueue


pq = PriorityQueue()

heap = []

num = [17, 5, 10, 19, 21, 8]

for data in num:
    heapq.heappush(heap, data)
    pq.put(data)

print("Priority Queue: ", end=" ")

for _ in range(6):
    print(pq.get(), end=" ")

print("")

print("Priority Queue (Heap): ", end=" ")
for _ in range(6):
    print(heapq.heappop(heap), end= " ")