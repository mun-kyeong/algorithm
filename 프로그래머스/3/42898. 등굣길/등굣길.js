function solution(m, n, puddles) {
    const MOD = 1000000007;

    const arr = Array.from({length: n}, ()=> Array(m).fill(0));
    
    for(const dist of puddles){
        const [x,y] = dist;    
        arr[y - 1][x - 1] = -1; 
    }
    
      arr[0][0] = 1;
    
    for(let i=0; i<n; i++){
        for(let j=0; j<m; j++){
            if (arr[i][j] === -1) { arr[i][j] = 0; continue; }
            if (i > 0) arr[i][j] += arr[i - 1][j];
            if (j > 0) arr[i][j] += arr[i][j - 1];
            arr[i][j] %= MOD;

        }
    }
    return arr[n-1][m-1];
}