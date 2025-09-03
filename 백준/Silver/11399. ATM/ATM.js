const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const numbers = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);

let accNum = 0;
const accNumbers = numbers.reduce((acc, num) => {
  accNum += num;
  return acc + accNum;
}, 0);

// console.log(
//   accNumbers.reduce((acc, num) => {
//     return acc + num;
//   }, 0)
// );

console.log(accNumbers);
