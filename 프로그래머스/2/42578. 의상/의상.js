function solution(clothes) {
    
    const obj = clothes.reduce((acc, curr)=> {
        const [cloth, type] = curr;
        if(!acc[type]) acc[type] =1
        else acc[type]++
        return acc;
    },{})
    
    const keyValues = Object.keys(obj)
    
    const answer = keyValues.reduce((acc, curr)=> {
        return acc * (obj[curr]+1);
    },1) -1
    
    
    return answer;
}