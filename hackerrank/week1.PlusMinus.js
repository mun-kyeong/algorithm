"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on("end", function () {
  inputString = inputString.split("\n");

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

/**
 *
 * 문제풀이 : reduce를 통해 양수,음수,0의 개수를 판단
 * > (각 숫자 개수 / 길이) 를 게산해서 출력 (기본문제였음)
 */

function plusMinus(arr) {
  const length = arr.length;
  const result = arr.reduce(
    (acc, curr) => {
      curr > 0 ? acc[0]++ : curr < 0 ? acc[1]++ : acc[2]++;
      return acc;
    },
    [0, 0, 0]
  );

  Array.from({ length: 3 }, (_, i) => {
    console.log((result[i] / length).toFixed(6));
  });
}

function main() {
  const n = parseInt(readLine().trim(), 10);

  const arr = readLine()
    .replace(/\s+$/g, "")
    .split(" ")
    .map((arrTemp) => parseInt(arrTemp, 10));

  plusMinus(arr);
}
