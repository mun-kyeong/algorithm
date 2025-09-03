function solution(citations) {
    var answer = 0;
    
    let h = 0;
    while(true){
        let leastCount = 0;
        for(const cit of citations ){
            if(leastCount >= h) break;
            if(cit >= h) leastCount ++
        }
        if(leastCount < h) break;
        answer = leastCount;
        h++;
    }
    
    return answer;
}

