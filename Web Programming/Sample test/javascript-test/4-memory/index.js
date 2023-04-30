const inputCircleNumber = document.querySelector("#circle-number");
const buttonStart = document.querySelector("#start");
const divContainer = document.querySelector("#container");
const divOutput = document.querySelector("#output");

// Application state

let canGuess = false;
let solution = [];
let series = [];

// ========= Utility functions =========

function random(a, b) {
  return Math.floor(Math.random() * (b - a + 1)) + a;
}

function toggleHighlight(node) {
  node.classList.toggle("highlight")
  node.addEventListener("animationend", function (e) {
      node.classList.remove("highlight");
  }, {once: true});
}

// =====================================

function flash(i = 0) {
  if (i == solutionLength) {
    divOutput.innerHTML = "Now is your turn.."
    canGuess = true;
    return;
  }
  const circles = document.getElementsByClassName('circle')
  if (i < solutionLength) {
    toggleHighlight(circles[series[i]-1])
    setTimeout(() => flash(i + 1), 1000)
  }
}

function addCircles() {
  while (+divContainer.childElementCount > +inputCircleNumber.value){
    divContainer.removeChild(divContainer.lastChild)
    count--
  }

  while (divContainer.childElementCount < +inputCircleNumber.value){
    const a = document.createElement("a");
    a.className = "circle"
    a.innerText = ++count
    divContainer.appendChild(a)
}
}

let solutionLength = 7;
let count = 0
addCircles()

inputCircleNumber.addEventListener('input', () => {
    addCircles()
})


buttonStart.addEventListener('click', () => {
  series = []
  for(let i=0; i<solutionLength; i++) {
    let val = Math.ceil( Math.random()* inputCircleNumber.value )
    series.push(val)
  }
  console.log(series)
  // toggleHighlight(divContainer.firstElementChild)
    canGuess = false
    divOutput.innerHTML = "Flashing circles.."
    flash()
})


divContainer.addEventListener('click', (e) => {
    if (canGuess && e.target.matches('a')) {
        solution.push(+e.target.innerText)
        if (solution.length == solutionLength) {
          result = JSON.stringify(solution) === JSON.stringify(series)
          console.log(result)
          solution = []

          divOutput.innerHTML = result ? "Nice Job!" : "Failed!"
          canGuess = false
        }
    }
})
 