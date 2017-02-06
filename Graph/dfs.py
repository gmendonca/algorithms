class Dfs:
    def __init__(self, N):
        self.graph = {}
        self.visited = []
        self.component = {}
        self.queue = []

    def add_pair(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph[u]:
            self.graph[u].append(v)

    def visit(self, root):
        self.queue.append(root)
        if root not in self.component:
            self.component[root] = []
        self.visited.append(root)
        while len(self.queue) > 0:
            u = self.queue.pop()
            for v in self.graph[u]:
                if v not in self.visited:
                    self.component[root].append(v)
                    self.visited.append(v)
                    self.queue.append(v)

    def dfs(self):
        self.visited = []
        for u in self.graph:
            self.visit(u)
