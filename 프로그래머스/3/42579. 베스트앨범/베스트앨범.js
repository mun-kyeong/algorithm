function solution(genres, plays) {
    var answer = [];
    let topGenres = {};
    let topPlays = {};
    for(let i=0; i<genres.length; i++){
        const genre = genres[i];
        const play = plays[i];
        if(!topGenres[genre]) {
            topGenres[genre] = play;
            topPlays[genre] = [[i,play]]
        }
        else {
            topGenres[genre] += play;
            topPlays[genre].push([i,play])
        }
    }
    
    let arr = []
    const rankGenres = Object.entries(topGenres).sort((a,b)=>  b[1] - a[1])
    // console.log(Object.values(rankGenres))
    rankGenres.forEach((rank)=> {
        const rankGenre = rank[0]
        // console.log(rankGenre)
        // console.log(topPlays[rankGenre])
        const genrePlays = topPlays[rankGenre].sort((a,b)=> {
            if(a[1] === b[1]) return a[1] - b[1]
            else return b[1] - a[1]
        })
        // console.log(genrePlays)
        for(let i=0; i<genrePlays.length && i<2; i++){
            arr.push(genrePlays[i][0])
        }
        
    })

    return arr
}