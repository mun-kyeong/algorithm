let m, n;

function solution(maps) {
    m = maps[0].length, n =maps.length ;
    let queue = [];
    let visited = Array.from({length : n}, ()=> 
        Array.from({length : m}, ()=> false)
    )
    
    queue.push([0,0,1]) // [x,y,count]
    visited[0][0] = true; // [x,y]
    
    let answer = -1;
    while(queue.length){
        // console.log(queue)
        const [x,y,count] = queue.shift(); // [x,y,count]
        if(x ===m-1 && y ===n-1) answer = count;
        // x+1, y
        if(x+1 < m && !visited[y][x+1] && maps[y][x+1] === 1){
            visited[y][x+1] = true;
            queue.push([x+1, y, count+1])
        }
           
        // x-1, y
        if(x-1 >= 0 && !visited[y][x-1] && maps[y][x-1] === 1){
            visited[y][x-1] = true;
            queue.push([x-1, y, count+1])
        }
           
        // x, y +1
        
        if(y+1 <n && !visited[y+1][x] && maps[y+1][x] === 1 ){
            visited[y+1][x] = true;
            queue.push([x, y+1, count+1])
        }
        
       // x, y -1
        if(y-1 >= 0 && !visited[y-1][x] && maps[y-1][x] === 1){
            visited[y-1][x] = true;
            queue.push([x, y-1, count+1])
        }
    }
    
    return answer;
}
