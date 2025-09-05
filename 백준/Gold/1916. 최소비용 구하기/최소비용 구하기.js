const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [n, m] = [input[0], input[1]].map(Number);
const graph = Array.from(Array(n + 1), () => new Map());
const INF = 100000 * 1000;

for (let i = 2; i < m + 2; i++) {
  let [from, to, cost] = input[i].split(" ").map(Number);
  if (!graph[from].has(to) || graph[from].get(to) > cost) {
    graph[from].set(to, cost); // 최소 비용으로 간선 저장
  }
}

const [start, end] = input[m + 2].split(" ").map(Number);

function dijkstra(start) {
  const distance = Array(n + 1).fill(INF);
  distance[start] = 0;

  const queue = [];
  queue.push([0, start]); // cost, node 저장

  while (queue.length) {
    queue.sort((a, b) => a[0] - b[0]); //비용을 오름차순으로 정렬
    const [currCost, currNode] = queue.shift(); //최단비용 꺼냄

    if (distance[currNode] < currCost) continue; //이미 처리된 경로는 패스

    graph[currNode].forEach((nextCost, nextNode) => {
      const totalCost = currCost + nextCost;

      if (totalCost < distance[nextNode]) {
        //최단비용 갱신
        distance[nextNode] = totalCost;
        queue.push([totalCost, nextNode]);
      }
    });
  }
  return distance;
}

const result = dijkstra(start);
console.log(result[end]);
