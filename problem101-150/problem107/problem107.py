import heapq

# min-heap
class PriorityQueue:
    def __init__(self):
        self._queue = []
        self._index = 0

    def push(self, item, priority):
        heapq.heappush(self._queue, (priority, self._index, item)) # -priority if max-heap
        self._index += 1

    def pop(self):
        return heapq.heappop(self._queue)[-1]

    def empty(self):
        return self._queue == []


#q = PriorityQueue()
#q.push("AAA", 2)
#q.push("BBB", 3)
#q.push("CCC", 1)
#print q.pop()
#print q.pop()
#print q.empty()
#print q.pop()
#print q.empty()

inf = 1000000000

def PrimeAlgorithm(G):
    N = len(G)
    root = 0

    Q = PriorityQueue()

    dist = [inf] * N
    dist[root] = 0
    Q.push(root, 0)

    visited = [False] * N

    min_cost = 0

    while not Q.empty():
        u = Q.pop()
        if visited[u]:
            continue
        visited[u] = True
        min_cost += dist[u]
        for v in range(N):
            if G[u][v] != -1 and visited[v] == False and G[u][v] < dist[v]:
                dist[v] = G[u][v]
                Q.push(v, G[u][v])

    return min_cost


def inputGraph(filename):
    f = open(filename, 'r')
    G = []
    for line in f:
        lst = [-1 if x == '-' else int(x) for x in line.strip('\n').split(',')]
        G.append(lst)
    f.close()
    return G


def sumGraph(G):
    total = 0
    for lst in G:
        for x in lst:
            if x != -1:
                total += x
    return total / 2

#G = inputGraph("sample.txt")
G = inputGraph("network.txt")
min_cost = PrimeAlgorithm(G)
total = sumGraph(G)
print min_cost
print total - min_cost
