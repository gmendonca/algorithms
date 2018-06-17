BIGVALUE=999999
class Dijkstra:
    def __init__(self, n):
        self.graph = {}
        self.Q = {}
        self.dist = {}
        self.prev = {}
        self.visited = []

        for v in xrange(1,n+1):
            self.dist[v] = BIGVALUE
            self.Q[v] = self.dist[v]
            self.graph[v] = {}

    def add_pair(self, u, v, w):
        self.graph[u][v] = w
        self.graph[v][u] = w

    def shortest_path(self, source):
        self.dist[source] = 0
        self.Q[source] = self.dist[source]
        while len(self.Q) > 0:
            u = min(self.Q, key=self.Q.get)
            del self.Q[u]
            for v in self.graph[u]:
                alt = self.dist[u] + self.graph[u][v]
                if alt < self.dist[v]:
                    self.dist[v] = alt
                    self.prev[v] = u
                    self.Q[v] = self.dist[v]
