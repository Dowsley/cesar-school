class Node:
    def __init__(self, data):
        self.vertex = data
        self.next = None

class UndirectedGraph:
    def __init__(self, size):
        # Initialize vertices list with provided size
        self.graph = [None] * self.size

    def add_edge(self, src, dest):
        # Adding the node to the source node
        node = Node(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        # Adding the source node to the destination as
        # it is the undirected graph
        node = Node(src)
        node.next = self.graph[dest]
        self.graph[dest] = node

    # Function to print the graph
    def print_graph(self):
        for i in range(self.V):
            print("Adjacency list of vertex {}\n head".format(i), end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next
            print(" \n")
