
// Constants
const table = document.querySelector('table')
const orange_reserve = document.querySelector('.orange_reserve')
const gray_reserve = document.querySelector('.gray_reserve')
const orange_points = document.querySelector('.orange_points')
const gray_points = document.querySelector('.gray_points')
const leftBoard = document.querySelector('.left_border')
const rightBoard = document.querySelector('.right_border')




// const a = document.querySelectorAll('.left_border *')
// console.log(a)
// Functions

function xyCoord(td) {
    return {
        x: td.parentNode.rowIndex,
        y: td.cellIndex,
    };
}

function delegate(parent, type, selector, handler) {
    parent.addEventListener(type, function(event) {
        const targetElement = event.target.closest(selector)
        if (this.contains(targetElement))
            handler.call(targetElement, event)
    })
}

// variables
const WIN_VALUE = 5
let numberOfRows = 6
let numberOfColumns = 6
let count_OrangeReserve = 8
let count_GrayReserve = 8
let count_OrangePoints = 0
let count_GrayPoints = 0
let gameState = 0// 0 - start
let player = Math.round(Math.random()) + 1 // 1 - OrangeCat, 2 - GrayCat
let beingDragged

// 0 - Empty, 1 - Orange, 2 - GrayCat
let boardGame = [
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
]
// const kitten = {
//     x: -1,
//     y: -1,
//     color: 'gray',
//     img: new Image(),
//     onBoard: false, // onTheBoard
// };

function createKitten(_player, isDraggable) {
    const kitten = document.createElement('img');
    kitten.className = 'kitten';
    kitten.draggable = isDraggable
    if (_player == 2) {
      kitten.src = 'assets/img/gray_cat.png';
      kitten.alt = 'gray kitten'
      kitten.dataset.color = 'gray'
    } else {
        kitten.src = 'assets/img/orange_cat.png';
        kitten.alt = 'orange kitten'
        kitten.dataset.color = 'orange'
    }
  
    return kitten;
}

function nextPlayer() {
    // pushKittens()
    if (player == 1)
        player = 2
    else
        player = 1
    changePlayerBackground() //*
}

function isGameLost(){
    return count_GrayReserve == 0 || count_GrayReserve == 0
}

function getLoser() { // Only if the game is lost
    if (count_GrayReserve == 0 || count_GrayPoints < WIN_VALUE)
        return 2
    else
        return 1
}

function getWinner() {
    if (count_GrayPoints == WIN_VALUE)
        return 2
    
    return 1
}

function isGameWon() { //*
    return count_GrayPoints == WIN_VALUE || count_OrangePoints == WIN_VALUE || isGameLost()
}

function gameScored() { //* 3 kittens in row

} 

function updateState() {
    if(gameScored() && gameWin()) {
        //*
    } else if (isGameLost()) {
        //*
    }
}

function updateLabels() {
    orange_points.innerText = count_OrangePoints
    orange_reserve.innerText = count_OrangeReserve

    gray_points.innerText = count_GrayPoints
    gray_reserve.innerText = count_GrayReserve
}

function changePlayerBackground() { //* - to implement
    
}

function isInsideBoardGame(x, y) {
    if (x >= 0 && x < numberOfRows && y >= 0 && y < numberOfColumns)
        return true
    return false
}

function pushKittens(coord) {
    for (let i = -1; i <=1; i++) {
        for (let j = -1; j <=1; j++) {
            if  (i == 0 && j == 0) 
                continue;
            let x = coord.x + i
            let y = coord.y + j
            if (isInsideBoardGame(x, y) && boardGame[x][y] != 0) {
                if (isInsideBoardGame(x + i, y + j) && boardGame[x + i][y + j] == 0) { // if the new position is inside the board then move the Kitten
                    boardGame[x + i][y + j] = boardGame[x][y]
                    boardGame[x][y] = 0
                } else if (!isInsideBoardGame(x + i, y + j)){ // else move the reservce
                    if (boardGame[x][y] == 1) {
                        count_OrangeReserve++
                    } else {
                        count_GrayReserve++;
                    }
                    boardGame[x][y] = 0
                }
            }
        }
    }
    
}

function fillBoardGame() {
    const tds = document.querySelectorAll('td')
    for (let i=0; i<tds.length; i++) {
        const row = Math.floor(i / numberOfColumns)
        const col = Math.floor(i % numberOfColumns)
        const val = boardGame[row][col]
        
        // console.log({row, val}, val)
        if (tds[i].firstElementChild){
            tds[i].removeChild(tds[i].firstElementChild)
        }
        if (val != 0) {
            tds[i].appendChild(createKitten(val, false))
        }
    }
}

function fillKittensReserve(_player, _reserveCounter) {
    let board;
    if (_player == 1) {
        board = leftBoard;
    } else {
        board = rightBoard;
    }

    while (board.childElementCount > _reserveCounter) {
        board.removeChild(board.firstElementChild)
    }

    while(board.childElementCount < _reserveCounter) {
        board.appendChild(createKitten(_player, true))
    }

}


function isDropOkay() {
    if (player == 1 && beingDragged.dataset.color == 'orange' ||
        player == 2 && beingDragged.dataset.color == 'gray'
    ) {
        return true
    }
    return false
}

function isPlaceVacant(coord) {
    return boardGame[coord.x][coord.y] == 0
}

function placeKitten(coord) {
    if (!isPlaceVacant(coord)) {
        return false
    } 
    if (player == 1) {
        fillKittensReserve(1, --count_OrangeReserve)
    } else {
        fillKittensReserve(2, --count_GrayReserve)
    }

    boardGame[coord.x][coord.y] = player
    pushKittens(coord)
    return true
}

function processGame() {
    updateState()
    updateLabels()
    fillBoardGame() 
    fillKittensReserve(1, count_OrangeReserve)
    fillKittensReserve(2, count_GrayReserve)
    nextPlayer()
}

// Utilities 
//* Starting configurations
fillBoardGame() 
fillKittensReserve(1, count_OrangeReserve)
fillKittensReserve(2, count_GrayReserve)
updateLabels()


// Methods
delegate(table, 'click', 'td', function(e) {
    const coordinates = xyCoord(this)

    if (placeKitten(coordinates)) {
        processGame()        
    } 
    // console.log(boardGame)
    console.log('Player', player)
    console.log(coordinates)
})


// Handling Drag and Drop
table.addEventListener('dragover', (e) => {
    e.preventDefault()
})

delegate(table, 'dragenter', 'td', function(e) {
    this.classList.add('highlight')
})
delegate(table, 'dragleave', 'td', function(e) {
    this.classList.remove('highlight')
})

delegate(table, 'drop', 'td', function(e) {
    
    const coordinates = xyCoord(this)

    if (beingDragged && placeKitten(coordinates)) {
        processGame()
    } 
    console.log('Player', player)
    console.log(coordinates)

    this.classList.remove('highlight')
})

leftBoard.addEventListener('dragstart', (e) => {
    if (player == 1) { // His time to play
        beingDragged = e.target
    } else
        beingDragged = null
})

rightBoard.addEventListener('dragstart', (e) => {
    if (player == 2) { // His time to play
        beingDragged = e.target
        console.log('Drag and Drop')
    } else
        beingDragged = null
})