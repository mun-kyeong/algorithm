function solution(strings, n) {
    var answer = [];
    
    function sortArr(a,b){
        if(a[n] == b[n]) return a.localeCompare(b)
        return a[n].localeCompare(b[n])
    }
    strings.sort(sortArr)
    return strings;
}