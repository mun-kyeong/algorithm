

function solution(n, times) {
    var answer = 0;
    
    const MAX_NUMBER = Math.max(...times)*n
    
    function findAns(start, end){
        const mid = Math.floor((start + end)/2) // 500000
        
        let sum = 0
        times.forEach((time)=> {
            sum += Math.floor(mid/time)
        })
        
        if (start === end) return start;
        
        if(sum < n){
            return findAns(mid+1, end)
        }else {
            return findAns(start, mid)
        }
    }
    const ans = findAns(0,MAX_NUMBER)
    return ans;
}