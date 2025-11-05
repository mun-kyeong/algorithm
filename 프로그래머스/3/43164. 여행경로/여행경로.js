function solution(tickets) {
    var answer = [];

    const tree = makeTree(tickets)
    
    function dfs(start, visited){
        if(visited.length === tickets.length + 1){
            answer.push( [...visited]);
            return;
        }
        
        const cities = tree.get(start) || [];

        for(let i=0; i<cities.length; i++){
            const currCity =  cities[i];
            cities.splice(i,1)
            // visited.push(currCity)
            dfs(currCity, [...visited, currCity])
            cities.splice(i,0,currCity )
        }

    }
    
    dfs("ICN", ["ICN"])
    
    
    answer.sort((a,b)=> a.join("") - b.join(""));
    return answer[0];

}
 
function makeTree(tickets){
    const subTree = tickets.reduce((acc,curr)=> {
        const [start,end] = curr
        if(!acc.get(start)) acc.set(start, [end]);
        else acc.get(start).push(end);
        return acc;
    }, new Map())
    
    
    for(key of subTree.keys()){
        const values = subTree.get(key).sort()
        subTree.set(key, values)
    }
    
    return subTree
}