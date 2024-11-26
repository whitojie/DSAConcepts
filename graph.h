/*
 GRAPHS

 A graph is a non-linear data structure made of nodes (vertex)
 and edges. A node contains data and an edge is a connecting between
 nodes. Two nodes are adjacent when a connection is established between
 them. An example of a graph would be like social media following. If one
 user follows another, then they are connected or adjacent and undirected.

 Directed graphs have directions where one node could connect to another
 but not the other way around. For example, destinations, there could be
 one-way streets or two-way streets.
 Time complexity to locate edge = O(1) (find two indices)

 Adjacency List: Array list of linked lists, and each element is a separate
 linked-list, and each header contains address of the node. If there is adjacency
 between one node and another, you would add it to the linked list
 Time complexity to locate an edge = 0(V) where V is # of vertices

 */