    # https://www.spoj.com/problems/TDBFS/
    from sys import stdin, stdout
    import queue
     
    def bfs(start_vertex):
        visited = [False for _ in range(n+1)]
        result = []
        cola = queue.Queue(0)
        cola.put(start_vertex)
        while not cola.empty():
            elem = cola.get()
            visited[elem] = True
            result.append(elem)
            for j in graph[elem]:
                if not visited[j]:
                    cola.put(j)
                    visited[j] = True
        return result
     
    def dfs(start_vertex):
        visited = [False for _ in range(n+1)]
        result = []
        dfs_internal(start_vertex, visited, result)
        return result
     
    def dfs_internal(start_vertex, visited, result):
        result.append(start_vertex)
        visited[start_vertex] = True
        for i in graph[start_vertex]:
            if not visited[i]:
                dfs_internal(i,visited,result)
     
    def print_list(order):
        stdout.write(str(order[0]))
        for i in range(1, len(order)):
            stdout.write(" " + str(order[i]))
        stdout.write('\n')
     
    t = int(stdin.readline())
    for i in range(0, t):
        n = int(stdin.readline())
        graph = [[] for _ in range(n+1)]
        for k in range(0, n):
            ady_l = [int(n) for n in stdin.readline().split()]
            l = ady_l[0]
            count = ady_l[1]
            for j in range(0, count):
                destiny = ady_l[2+j]
                graph[l].append(destiny)
        stdout.write("graph {}\n".format(i+1))
        # read querys
        query_line = [int(n) for n in stdin.readline().split()]
        while(query_line[0]!=0 or query_line[1]!=0):
            start_vertex = query_line[0]
            is_dfs = query_line[1] == 0
            if is_dfs:
                order = dfs(start_vertex)
            else:
                order = bfs(start_vertex)
            print_list(order)
            query_line = [int(n) for n in stdin.readline().split()]
     