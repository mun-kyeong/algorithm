function moveNode(number,node){
    const[x,y] = node
    switch(number){
        case 0:
            return [x,y+1]
        case 1:
            return [x+1,y+1]
        case 2:
            return [x+1,y]
        case 3:
            return [x+1, y-1]
        case 4:
            return [x,y-1]
        case 5:
            return [x-1, y-1]
        case 6:
            return [x-1,y]
        case 7:
            return [x-1, y+1]
    }
}

function opositeNode(arrow){
    const num = arrow-4
    if(num <0) return 4 + arrow
    return num
}

function solution(arrows) {
    var answer = 0;
    let node = [0,0]
    let movedNode = []
    const visitedNode = {}
                    
    arrows.forEach((arrow,idx) => {
        const opArrow = opositeNode(arrow)

        for(let i=0; i<2; i++){
            movedNode = moveNode(arrow,node)
            const currNode = String(node)
            const nextNode = String(movedNode)
            
            if(!visitedNode[currNode]){
                visitedNode[currNode] = new Set() 
            }
           if (visitedNode[nextNode] &&!visitedNode[currNode].has(arrow))   
            {
                answer ++
            }   
            visitedNode[currNode].add(arrow)

            if(!visitedNode[nextNode]){
                visitedNode[nextNode] = new Set()
            }
            visitedNode[nextNode].add(opArrow)
            node = movedNode
        }       
        
    })
    
    // const currNode = String(node)
    // const arrow = arrows[arrows.length-1]
    // if(!visitedNode[currNode].has(arrow) 
    //     && visitedNode[currNode].size>=2){
    //     answer ++
    // }
    
    return answer;
}