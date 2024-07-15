a, p = input().split()
arr = []

def BFS(bfs): 
    if arr.count(bfs) != 0:
        return arr.index(bfs)
    arr.append(bfs)
    num = 0
    for i in bfs:
        num += int(i) ** int(p)
    return BFS(str(num))

print(BFS(a))    