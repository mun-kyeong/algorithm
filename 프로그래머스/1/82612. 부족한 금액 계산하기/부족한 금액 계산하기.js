function solution(price, money, count) {
    var answer = -1;
    let acc = 0
    for(let i=1; i<=count; i++){
        acc += price * i
    }
    
    if(acc < money) return 0
    return acc-money ;
}