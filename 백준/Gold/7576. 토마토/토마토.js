const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [M, N] = input[0].split(" ").map((num) => Number(num));

// O(N) 만큼 반복하면서 1인 지점을 찾기 O(N^2) or O(MxN)

const queue = [];
let map = input
  .slice(1)
  .map((line) => line.split(" ").map((num) => Number(num)));

let index = 0;
let maxCount = 0;
let head = 0;

for (const row of map) {
  row.forEach((num, idx) => {
    num === 1 && queue.push([idx, index, 0]);
  });
  index++;
}

while (queue[head]) {
  const [m, n, count] = queue[head++];
  validateTomato(m, n + 1, count);
  validateTomato(m, n - 1, count);
  validateTomato(m + 1, n, count);
  validateTomato(m - 1, n, count);
  maxCount = Math.max(maxCount, count);
  // console.log(map);
}

function validateTomato(m, n, count) {
  if (m < M && n < N && m >= 0 && n >= 0 && map[n][m] === 0) {
    map[n][m] = 1;
    queue.push([m, n, count + 1]);
  }
}

for (const arr of map) {
  if (arr.indexOf(0) !== -1) {
    console.log("-1");
    return;
  }
}

console.log(maxCount);

// --- 재귀 bfs ---

// 초기 값이 1인 지점을 찾아서 start 일수를 0으로 잡고 bfs 재귀 할때마다 일수 +1씩 더하기.
// bfs 스택이 다 비었을 때 배열 중 0이 있는지 먼저 확인 => -1 출력
// 아니라면 맨 마지막 day를 출력 (걸리는 시간)
// 시간복잡도는 최악일 경우 O(N × M)
