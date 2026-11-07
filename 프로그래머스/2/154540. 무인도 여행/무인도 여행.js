function solution(maps) {
    let arr = Array(maps.length)
    
    for(let i=0; i<maps.length; i++){
        const mapArr = maps[i].split("")
        arr[i] = mapArr
    }
    const ans = []
    
    let tempX = [1,0,-1,0]
    let tempY = [0,-1,0,1]
    
    for(let i=0; i<maps.length; i++){
        for(let j=0; j<maps[0].length; j++){
            
            if(arr[i][j] == "X") continue
                
            let queue = [[i,j]]
            let count = Number(arr[i][j])
            arr[i][j] = "X"
            while(queue.length){
                const [x,y] = queue.shift()
                for(let k=0; k<4; k++){
                    const newX = x + tempX[k]
                    const newY= y + tempY[k]
                    if(newX<0 || newY <0 || newX >= maps.length 
                       || newY>=maps[0].length) 
                        continue
                    if(arr[newX][newY] !== "X"){
                        queue.push([newX, newY])
                        count += Number(arr[newX][newY])
                        arr[newX][newY] = "X"
                     }
                }
            }
            ans.push(count)
        }
    }
    
    ans.sort((a,b)=> a-b)
    
    if(ans.length == 0) return [-1]
    return ans;
}