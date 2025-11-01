function solution(s) {
    var answer = '';    
    return s.split("").sort((a,b)=> a<b ? 1 : -1).join("");
}