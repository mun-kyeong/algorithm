function solution(record) {
    var answer = [];
    const users = {}
    for(const msg of record){
        const [key, userID, name] = msg.split(" ");
        if(key === "Change" || key === "Enter" ) users[userID] = name;
        if(key === "Enter") answer.push(["Enter", userID])
        else if(key === "Leave") answer.push(["Leave", userID])
    }
    
    const message = [];
    for(const [key, id] of answer){
        if(key === "Enter") message.push(users[id] + "님이 들어왔습니다.");
        else if(key === "Leave") message.push(users[id] + "님이 나갔습니다.");
    }
    return message;
}