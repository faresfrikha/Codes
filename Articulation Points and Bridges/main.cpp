function find_articulation_points(adj[][], V)
    count = 0
    for i = 0 to V
        visited[i] = false
    initial_val = 0
    for i = 0 to V
        if visited[i] == false
            DFS(adj, V, visited, i)
            initial_val = initial_val+1

    for i=0 to V
        for j = 0 to V
            visited[j] = false
            copy[j] = adj[i][j]
            adj[i][j]=adj[j][i]=0

        nval = 0
        for j= 0 to V
            if visited[j] == false AND j != i
                nval = nval + 1
                DFS(adj, n, visited, j)
        if nval > initial_val
            count = count + 1
        for j= 0 to V
            adj[i][j] = adj[j][i] = copy[j]
    return count




    time = 0
function DFS(adj[][], disc[], low[], visited[], parent[], AP[], vertex, V)
        visited[vertex] = true
        disc[vertex] = low[vertex] = time+1
        child = 0
        for i = 0 to V
                if adj[vertex][i] == true
                        if visited[i] == false
                                child = child + 1
                                parent[i] = vertex
                                DFS(adj, disc, low, visited, parent, AP, i, n, time+1)
                                low[vertex] = minimum(low[vertex], low[i])
                                if parent[vertex] == nil and child > 1
                                        AP[vertex] = true
                                if parent[vertex] != nil and low[i] >= disc[vertex]
                                        AP[vertex] = true
                        else if parent[vertex] != i
                                low[vertex] = minimum(low[vertex], disc[i])



function find_bridges(adj[][], V, Edge[], E, isBridge[])
    for i = 0 to E
        adj[Edge[i].u][Edge[i].v]=adj[Edge[i].v][Edge[i].u]=0
        for j = 0 to V
            visited[j] = false
        Queue.Insert(Edge[i].u])
        visited[Edge[i].u] = true
        check = false
        while Queue.isEmpty() == false
            x = Queue.top()
            if x == Edge[i].v
                check = true
                BREAK
            Queue.Delete()
            for j = 0 to V
                if adj[x][j] == true AND visited[j] == false
                    Queue.insert(j)
                    visited[j] = true
        adj[Edge[i].u][Edge[i].v]=adj[Edge[i].v][Edge[i].u]=1
        if check == false
            isBridge[i] = true



time = 0
function DFS(adj[][], disc[], low[], visited[], parent[], vertex, n)
        visited[vertex] = true
        disc[vertex] = low[vertex] = time+1
        child = 0
        for i = 0 to n
                if adj[vertex][i] == true
                        if visited[i] == false
                                child = child + 1
                                parent[i] = vertex
                                DFS(adj, disc, low, visited, parent, i, n, time+1)
                                low[vertex] = minimum(low[vertex], low[i])
                                if low[i] > disc[vertex]
                                        print vertex, i
                        else if parent[vertex] != i
                                low[vertex] = minimum(low[vertex], disc[i])
