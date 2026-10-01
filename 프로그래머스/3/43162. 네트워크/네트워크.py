def solution(n, computers):
    answer = 1
    arr = []
    arr.append(0)
    
    visited = set()
    visited.add(0)
    
    while(True):
        if(len(arr) == 0): 
            if(len(visited) == n):
                break
            for i in range(0,n):
                if(i not in visited):
                    arr.append(i)
                    visited.add(i)
                    answer +=1
                    break
        else :
            net = arr.pop()
            for i in range(0,n):
                if(computers[net][i] == 1 or computers[i][net]):
                    if(i not in visited):
                        arr.append(i)
                        visited.add(i)
    return answer

