function solution(s) {
    const ans = []
    for (const arr of s.split(" ")){
            ans.push(makeFirstUpper(arr))
            }
    
    return ans.join(" ");
}

function makeFirstUpper(word){
    let result = ''
        if(word[0] >= 'a' && word[0]  <= 'z'){    
result = word[0].toUpperCase();
        }
    else result=word[0]
    
    for (let i=1; i<word.length; i++) {
        result += word[i].toLowerCase();  
    }
    return result;
}