function solution(word){
    let newWord=[]
    
    for(let i=0; i<word.length; i++){
        const lastWord = newWord[newWord.length-1]
        if(word[i] === lastWord) newWord.pop();
        else newWord.push(word[i])
    }
    
    return newWord.length === 0 ? 1:0 ;
    
}