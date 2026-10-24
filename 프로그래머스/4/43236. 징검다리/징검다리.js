
function solution(distance, rocks, n) {
    var answer = 0;
    const rockLength = rocks.length
    rocks.push(distance)
    rocks = rocks.sort((a,b)=> a-b)
    
    function findCount(start, end){
        if(start>end) return
        
        const mid = Math.floor((start+end)/2)
        
        let remains = [0]
        let remainIdx = 0
        let removeCount = 0
        
        rocks.forEach((rock)=> {
            if(rock - remains[remainIdx] < mid){
                removeCount++
            }else{
                remains.push(rock)
                remainIdx++
            }
        })
        
        if(removeCount <= n){
            answer = mid;
            return findCount(mid+1, end)
        }else {
            return findCount(start, mid-1)
        }
        
    }
    let rockDist = findCount(0,distance)

    return answer;
}