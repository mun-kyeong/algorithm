function solution(n, computers) {
    let networkCount = 0;
    const visited = new Array(n).fill(false)
    
    function bfs(start){
        const queue = [start];
        visited[start] = true;
       while(queue.length){
            const node = queue.shift(); // shift 하면 배열의 앞 요소 반환 + 없애기
            for(let i=0; i<n; i++){
                const newNode = computers[node][i];
                if(visited[i] || newNode === 0) continue;
                visited[i] = true;
                queue.push(i);
            }
        }
        networkCount ++;

    }
    
           
    for(let i=0; i<n; i++){
        if(visited[i] === false) bfs(i);
    }

    
    return networkCount;
}