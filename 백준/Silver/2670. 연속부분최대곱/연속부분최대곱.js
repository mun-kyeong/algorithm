const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const array = input.slice(1).map((line) => Number(line));

let maxNumber = 0;
let acc = 1;

for (const num of array) {
  if (1 > acc * num) {
    acc = 1;
    if (maxNumber < num) maxNumber = num;
    continue;
  }
  acc = acc * num;
  if (maxNumber < acc) maxNumber = acc;
}

console.log(maxNumber.toFixed(3));
