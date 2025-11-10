function solution(numbers) {
  const digits = typeof numbers === 'string' ? numbers.split('') : numbers;
  const answer = new Set();

  function findFun(length, arr, result, currNumbers) {
    if (arr.length === length) {
      result.add(Number(arr.join("")));
      return;
    }
    for (let i = 0; i < currNumbers.length; i++) {
      arr.push(currNumbers[i]);
      const next = currNumbers.filter((_, idx) => idx !== i);
      findFun(length, arr, result, next);
      arr.pop();
    }
  }

  for (let i = 1; i <= digits.length; i++) {
    const res = new Set();
    findFun(i, [], res, digits);
    for (const num of res) {
      if (isPrime(num)) answer.add(num);
    }
  }

  return answer.size;
}

function isPrime(num) {
  if (num < 2) return false;
  if (num === 2 || num === 3) return true;
  if (num % 2 === 0 || num % 3 === 0) return false;

  for (let j = 5; j * j <= num; j += 6) {
    if (num % j === 0 || num % (j + 2) === 0) return false;
  }
  return true;
}

// console.log(solution("17")); // 3 → [7, 17, 71]
