const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [M, N] = input[0].split(" ").map(Number);

const queue = [];
let map = input.slice(1).map((line) => line.split(" ").map(Number));

let maxCount = 0;
let head = 0;

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (map[i][j] === 1) {
      queue.push(j, i, 0);
    }
  }
}

while (head < queue.length) {
  const m = queue[head++];
  const n = queue[head++];
  const count = queue[head++];
  maxCount = Math.max(maxCount, count);

  validateTomato(m, n + 1, count);
  validateTomato(m, n - 1, count);
  validateTomato(m + 1, n, count);
  validateTomato(m - 1, n, count);
}

function validateTomato(m, n, count) {
  if (m < M && n < N && m >= 0 && n >= 0 && map[n][m] === 0) {
    map[n][m] = 1;
    queue.push(m, n, count + 1);
  }
}

for (let i = 0; i < N; i++) {
  if (map[i].includes(0)) {
    console.log(-1);
    process.exit(0);
  }
}

console.log(maxCount);
