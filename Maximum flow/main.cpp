function: FordFulkerson(Graph G,Node S,Node T):
    Initialise flow in all edges to 0
    while (there exists an augmenting path(P) between S and T in residual network graph):
        Augment flow between S to T along the path P
        Update residual network graph
    return



function: DinicMaxFlow(Graph G,Node S,Node T):
    Initialize flow in all edges to 0, F = 0
    Construct level graph
    while (there exists an augmenting path in level graph):
        find blocking flow f in level graph
        F = F + f
        Update level graph
    return F
