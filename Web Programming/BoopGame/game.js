
let timers = []

// variables
let WIN_VALUE = +win_value.value
let numberOfRows = 6//+row_size.value
let numberOfColumns = 6//+col_size.value
let count_OrangeReserve = 8//+nbr_kittens
let count_GrayReserve = 8//+nbr_kittens
let count_OrangePoints = 0
let count_GrayPoints = 0
let gameState = 0// 0 - Collecting info, 1 - start, 2 - End
let player = Math.round(Math.random()) + 1 // 1 - OrangeCat, 2 - GrayCat
let beingDragged

// 0 - Empty, 1 - Orange, 2 - GrayCat
let boardGame = [
    [0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [1, 2, 1, 0, 0, 0],
    [0, 1, 2, 0, 0, 0],
    [0, 0, 1, 2, 0, 0],
]



// Functions
function xyCoord(td) {
    return {
        x: td.parentNode.rowIndex,
        y: td.cellIndex,
    };
}




function nextPlayer() {
    // pushKittens()
    if (timers.length) {
        clearTimeout(timers[timers.length-1])
        timers.pop()
    }



    if (player == 1) {
        player = 2
        rightBoard.classList.add('focusPlayer')
        setTimeout(() => rightBoard.classList.remove('focusPlayer'), 350)
    } else {
        player = 1
        leftBoard.classList.add('focusPlayer')
        setTimeout(() => leftBoard.classList.remove('focusPlayer'), 350)
    }

 
    timers.push(setTimeout(()=> {
            if (gameState == 1) {
                if (player == 2)
                count_OrangePoints = WIN_VALUE
                else
                count_GrayPoints = WIN_VALUE
                showGameOver()
                console.log('Time out')
            }
            timers.pop()
                
        }, 120000)) // 2 seconds
}

function isGameLost(){
    if (count_GrayReserve == 0)
        count_OrangePoints = WIN_VALUE
    else if (count_OrangeReserve == 0)
        count_GrayPoints = WIN_VALUE

    return count_GrayReserve == 0 || count_OrangeReserve == 0
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

function isGameWon() { 
    return isGameLost() || count_GrayPoints == WIN_VALUE || count_OrangePoints == WIN_VALUE
}


function addPointsAndReserve(_player) { // Add 3 kittens in the reserve
    if (_player == 1) {
        count_OrangePoints++
        count_OrangeReserve += 3
    } else {
        count_GrayPoints++
        count_GrayReserve += 3
    }
}


function helperDiagonal(i, j) {
    if (boardGame[i][j] !=0 && boardGame[i][j] == boardGame[i+1][j-1] && boardGame[i][j] == boardGame[i+2][j-2]) {
        addPointsAndReserve(boardGame[i][j])
        boardGame[i][j] = 0
        boardGame[i+1][j-1] = 0
        boardGame[i+2][j-2] = 0
        return true
    }
    return false
}



function helperAntiDiagonal(i, j) {
    if (boardGame[i][j] !=0 && boardGame[i][j] == boardGame[i+1][j+1] && boardGame[i][j] == boardGame[i+2][j+2]) {
        addPointsAndReserve(boardGame[i][j])
        boardGame[i][j] = 0
        boardGame[i+1][j+1] = 0
        boardGame[i+2][j+2] = 0
        return true
    }
    return false
}

function diagonalGameScoredCheck() {
    let flag = false
    for (let z=0; z<numberOfColumns; z++) {
        let i = 0;
        let j = z;
        while (i+2<numberOfRows && j > 1) {
            flag = flag || helperDiagonal(i, j)
            i++; j--
        }
   }
   for (let z=1; z<numberOfRows; z++) {
       let i = z;
       let j = numberOfColumns-1;
       while(i+2<numberOfRows && j > 1) {
            flag = flag || helperDiagonal(i, j)
            i++; j--
        }
   }

   return flag
}


function antiDiagonalGameScoredCheck() {
    let flag = false
    for (let z=0; z<numberOfColumns; z++) {
        let i = 0;
        let j = z;
        while (i+2<numberOfRows && j+2<numberOfColumns) {
            flag = flag || helperAntiDiagonal(i, j)
            i++; j++
        }
   }
   for (let z=1; z<numberOfRows; z++) {
       let i = z;
       let j = 0;
       while(i+2<numberOfRows && j+2<numberOfColumns) {
            flag = flag || helperAntiDiagonal(i, j)
            i++; j++
        }
   }
   return flag
}


function verticalGameScoredCheck() {
    let flag = false
    for (let i=0; i<numberOfRows-2; i++) {
        for (let j=0; j<numberOfColumns; j++) {
            if (boardGame[i][j] !=0 && boardGame[i][j] == boardGame[i+1][j] && boardGame[i][j] == boardGame[i+2][j]) {
                addPointsAndReserve(boardGame[i][j])
                boardGame[i][j] = 0
                boardGame[i+1][j] = 0
                boardGame[i+2][j] = 0
                flag = true
            }
        }
    }
    return flag
}

function horizontalGameScoredCheck() {
    let flag = false
    for (let i=0; i<numberOfRows; i++) {
        for (let j=0; j<numberOfColumns-2; j++) {
            if (boardGame[i][j] !=0 && boardGame[i][j] == boardGame[i][j+1] && boardGame[i][j] == boardGame[i][j+2]) {
                addPointsAndReserve(boardGame[i][j])
                boardGame[i][j] = 0
                boardGame[i][j+1] = 0
                boardGame[i][j+2] = 0
                flag = true
            }
        }
    }
    return flag
}


function gameScored() { // 3 kittens in row
    if ( diagonalGameScoredCheck() ||
        antiDiagonalGameScoredCheck() ||
        horizontalGameScoredCheck() ||
        verticalGameScoredCheck()) {
        
        playGameScoreSong()

        return true
    }

    return false
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

function getListOfKittenToPushed(coord) {
    let list = []
    for (let i = -1; i <=1; i++) {
        for (let j = -1; j <=1; j++) {
            if  (i == 0 && j == 0) 
                continue;
            let x = coord.x + i
            let y = coord.y + j
            if (isInsideBoardGame(x, y) && boardGame[x][y] != 0) {
                if (isInsideBoardGame(x + i, y + j) && boardGame[x + i][y + j] == 0) { // if the new position is inside the board then move the Kitten
                    list.push({x, y})
                } else if (!isInsideBoardGame(x + i, y + j)){ // else move the reservce
                    list.push({x, y})
                }
            }
        }
    }
    
    return list
}


function isPlaceVacant(coord) {
    return boardGame[coord.x][coord.y] == 0
}

function placeKitten(coord) {
    if (!isPlaceVacant(coord) || gameState != 1) {
        return false
    } 
    if (player == 1) {
        playOrangeKittenMoveSong()
        fillKittensReserve(1, --count_OrangeReserve)
    } else {
        playGrayKittenMoveSong()
        fillKittensReserve(2, --count_GrayReserve)
    }

    boardGame[coord.x][coord.y] = player
    pushKittens(coord)
    return true
}


// Saving 
function saveGameResult(gameData) {
    localStorage.setItem('gameResult', JSON.stringify(gameData));
  }
  
function loadGameResult() {
const gameDataJson = localStorage.getItem('gameResult');
if (gameDataJson) {
    return JSON.parse(gameDataJson);
}
return [];
}


// Game history
function saveAllGameData(gameData) {
    localStorage.setItem('allGameData', JSON.stringify(gameData));
  }
  
  function loadAllGameData() {
    const gameDataString = localStorage.getItem('allGameData');
    if (gameDataString) {
      return JSON.parse(gameDataString);
    }
    // if no data is found in localStorage, return a default object
    return null;
  }
  



//* Music Player

function playStartSong() {
    let a = new Audio("assets/audio/start.wav")
    a.play()
}

function playOrangeKittenMoveSong() {
    let a = new Audio("assets/audio/orange.wav")
    a.play()
}


function playGrayKittenMoveSong() {
    let a = new Audio("assets/audio/gray.wav")
    a.play()
}

function playGameScoreSong() {
    let a = new Audio("assets/audio/score.wav")
    a.play()
}

function playGameWonSong() {
    let a = new Audio("assets/audio/win.wav")
    a.play()
}

// function playIntroSong() {
//     intro = new Audio("assets/audio/intro.wav")
//     intro.play()
//     intro.stop
// }