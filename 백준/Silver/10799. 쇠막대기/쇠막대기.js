const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

let stack = [];
let count = 0;

for (let i = 0; i < input.length; i++) {
  if (input[i] === "(") {
    stack.push("(");
  } else {
    stack.pop();
    if (input[i - 1] === "(") {
      count += stack.length;
    } else {
      count += 1;
    }
  }
}

console.log(count);
