function solution(rectangle, characterX, characterY, itemX, itemY) {
    var answer = 0;
    let space = Array.from({length : 102}, () => Array.from({length:102}).fill(0))
    // console.log(space)
    const start = [characterX, characterY]
    const end = [itemX, itemY]
    
    for (let i=0; i<rectangle.length; i++){
        const [x1,y1, x2,y2] = rectangle[i]
        
        for (let x=x1*2; x<=x2*2; x++){
            for(let y=y1*2; y<= y2*2; y++){
                space[y][x] = 1
            }
        }
    }
    
     
    for (let i=0; i<rectangle.length; i++){
        const [x1,y1, x2,y2] = rectangle[i]
        
        for (let x=x1*2 +1; x<x2*2; x++){
            for(let y=y1*2+1; y<y2*2; y++){
                space[y][x] = 0
            }
        }
    }
    let idx = 0
    let queue = [[characterX*2, characterY*2,0]]
    
    const dx = [1,-1,0,0]
    const dy = [0,0,-1,1]
    
    let visited = Array.from({length : 102}, ()=> Array.from({length: 102}).fill(false))
    
    while(idx < queue.length){
        const [x,y,count] = queue[idx++]
        if(x=== itemX*2 && y=== itemY*2){
            return count/2
        }
        
        for(let i=0; i<4; i++){
            const tempX = x + dx[i]
            const tempY = y + dy[i]
            
            if (tempX < 0 || tempX >= 102 || tempY < 0 || tempY >= 102) continue
            if(visited[tempY][tempX]) continue
            
            if(space[tempY][tempX] === 1){
                visited[tempY][tempX] = true
                queue.push([tempX, tempY, count+1])
            }
        }
    }
    
    return 0;
    
    return answer;
}