function solution(num) {
    var answer = 0;
    let count = 0
    while(count < 500 && num!==1){
        if(num%2 === 0) num = num/2
        else{
            num = num * 3 + 1
        }
        count++
    }
    return count===500 ? -1 : count
}