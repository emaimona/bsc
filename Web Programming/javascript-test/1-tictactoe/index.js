const task1 = document.querySelector('#task1');
const task2 = document.querySelector('#task2');
const task3 = document.querySelector('#task3');
const task4 = document.querySelector('#task4');

const game = [
  "XXOO",
  "O OX",
  "OOO ",
];


task1.innerHTML = game.every( row => row.length == game[0].length );
task2.innerHTML = game[0].split('').every( char => char == 'O' || char == 'X');


// function countCh(ch) {

//     let count = 0;
//     for(letter of game) {
//         for (let i=0; i<letter.length; i++)
//           if (ch == letter[i])
//            count++
//     }

//     return count;
// }

// task3.innerHTML = `X / O = ${countCh('X')} / ${countCh('O')}`
const zeros = game.join('').split('').filter(char => char === 'O').length
const xes = game.join('').split('').filter(char => char === 'X').length

task3.innerHTML = `X / O = ${xes} / ${zeros}`

task4.innerText = game.findIndex(row => row.includes('XXX') || row.includes('OOO'))