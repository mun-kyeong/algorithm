const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const n = Number(input[0]);
const m = Number(input[1]);
const array = input.slice(2, m + 2).map((arr) => arr.split(" "));

const [start, end] = input
  .slice(m + 2)
  .toString()
  .split(" ")
  .map(Number);

// const tree = Array.from(Array(n + 1), () => new Map());
// // const INF = 100000 * 1000;

// for (let i = 2; i < m + 2; i++) {
//   let [from, to, cost] = input[i].split(" ").map(Number);
//   if (!tree[from].has(to) || tree[from].get(to) > cost) {
//     tree[from].set(to, cost); // 최소 비용으로 간선 저장
//   }
// }

const tree = array.reduce((acc, curr) => {
  const [s, e, c] = curr;
  if (!acc[s]) acc[s] = new Map();
  if (!acc[s].has(e) || acc[s].get(e) > Number(c)) {
    acc[s].set(e, Number(c));
  }
  return acc;
}, {});

const queue = [[start, 0]];
const dist = Array(n + 1).fill(Infinity);
dist[start] = 0;

while (queue.length) {
  queue.sort((a, b) => a[1] - b[1]);
  const [startNode, cost] = queue.shift();

  if (dist[startNode] < cost) continue;

  if (Number(startNode) === end) {
    console.log(dist[startNode]);
    break;
  }

  // 여기서 런타임 에러남!!  tree[startNode] << 이거 순회하려고 할 때 원래 없는 값이면 런타임 에러를 출력 ..
  //
  for (const city of tree[startNode] || new Map()) {
    const [nextNode, cost] = city;

    const newConst = Number(dist[startNode]) + Number(cost);
    if (newConst < dist[nextNode]) {
      dist[nextNode] = newConst;
      queue.push([nextNode, newConst]);
    }
  }
}

// console.log(dist[end]);
