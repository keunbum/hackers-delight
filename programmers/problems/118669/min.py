def solution(n, paths, gates, summits):
    answer = [0, 10000001]
    is_gate = [False] * (n + 1)
    for gate in gates:
        is_gate[gate] = True
    summits.sort()
    is_summit = [False] * (n + 1)
    for summit in summits:
        is_summit[summit] = True
    graph = [[] for _ in range(n+1)]
    for i, j, w in paths:
        graph[i].append([j, w])
        graph[j].append([i, w])
    
    def get_smallest_node():
        min_value = 10000002
        index = 0  
        for i in range(1, n + 1):
            if intensity[i] < min_value and i not in visited:
                min_value = intensity[i]
                index = i
        return index

    def dijkstra(start):
        nonlocal answer
        visited_summits = 0
        s = []
        for j in graph[start]:
            intensity[j[0]] = j[1]
        for i in range(n - 1):
            if visited_summits == len(summits):
                break
            now = get_smallest_node()
            if now == 0:
                continue
            visited.add(now)
            if is_summit[now]:
                visited_summits += 1
                continue
            for j in graph[now]:
                if is_gate[j[0]]:
                    continue
                cost = max(intensity[now], j[1])
                intensity[j[0]] = min(intensity[j[0]], cost)

        for target in summits:
            if intensity[target] < answer[1]:
                answer = [target, intensity[target]]
            elif intensity[target] == answer[1]:
                answer[0] = min(target, answer[0])

    for start in gates:
        intensity = [10000001] * (n + 1)
        intensity[start] = 0
        visited = set(gates)
        dijkstra(start)

    return answer
