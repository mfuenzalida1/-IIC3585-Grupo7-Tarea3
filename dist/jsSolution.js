const t0 = performance.now();
const jsDiv = document.getElementById("js-solution-div")
const n = 7;

const generateSet = (numbers) => {
  const set = []
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      set.push(numbers[i] + numbers[j]);
      set.push(numbers[i] * numbers[j]);
    }
  }
  return set;
}

const checkRepeated = (numbers) => {
  numbers.sort((a,b) => a-b);
  for (let i = 1; i < numbers.length; i++) {
    if (numbers[i-1] === numbers[i]) return false;
  }
  return true;
}

const getNextNumbers = (numbers) => {
  for (let i = 1; i < n; i++) {
    if (numbers[i-1] + 1 < numbers[i]) {
      numbers[i-1] = numbers[i-1] + 1;
      jsDiv.innerHTML = `loading: max number: ${numbers[i-1] + 1}`
      for (let j = 1; j < i; j++) {
        numbers[j-1] = j;
      }
      return numbers;
    }
  }
  numbers[numbers.length - 1] = numbers[numbers.length - 1] + 1;
  for (let i = 1; i < numbers.length; i++) {
    numbers[i-1] = i;
  }
  return numbers; 
}

let numbers = [];
for (let i = 1; i <= n; i++) {
  numbers.push(i)
}

while (true) {
  if (checkRepeated(generateSet(numbers))) {
    break;
  } else {
    numbers = getNextNumbers(numbers);
  }
}

const t1 = performance.now();

jsDiv.innerHTML = `<h4>JS solution:</h4><p>${numbers}</p> <p>${generateSet(numbers).sort((a,b) => a-b)}</p><p>tiempo de ejecucion: ${(t1-t0)/1000} segundos</p>`;

console.log(numbers)
console.log(generateSet(numbers).sort((a,b) => a-b))
