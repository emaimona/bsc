const task1 = document.querySelector('#task1');
const task2 = document.querySelector('#task2');
const task3 = document.querySelector('#task3');
const task4 = document.querySelector('#task4');

const game = [
  "XXOO",
  "O OX",
  "OOO ",
];

function count(str, ch) {
  let count = 0;
  for (const c of str) 
    count += c === ch ? 1 : 0;
  return count
}

task1.innerHTML = game.every( e => e.length == game[0].length)
task2.innerHTML = Array.from(game[0]).every(e => e === 'O' || e === 'X')
xs = game.map(e => count(e, 'X')).reduce((acc, e) => acc + e, 0)
ys = game.map(e => count(e, 'O')).reduce((acc, e) => acc + e, 0)
task3.innerHTML = `X / O = ${xs} / ${ys}`

task4.innerHTML = game.map( e => e.includes('XXX') || e.includes('OOO')).findIndex(e => e === true)