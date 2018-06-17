class StrongConnected:
    def __init__(self, N):
        self.graph = {}
        self.visited = []
        self.L = []
        self.assigned = []
        self.component = {}

        for u in xrange(0, N):
            self.graph[u] = []

    def add_pair(self, u, v):
        self.graph[u].append(v)

    def visit(self, u):
        if u not in self.visited:
            self.visited.append(u)
            for v in self.graph[u]:
                self.visit(v)
            self.L.append(u)

    def dfs(self):
        self.visited = []
        self.L = []
        for u in self.graph:
            self.visit(u)

    def assign(self, u, root):
        if u not in self.assigned:
            if root not in self.component:
                self.component[root] = []
            self.component[root].append(u)
            self.assigned.append(u)
            for v in self.graph[u]:
                self.assign(v, root)

    def strong_connect(self):
        self.assigned = []
        self.L.sort()
        for u in self.L:
            if u not in self.assigned:
                self.assign(u, u)
