const gamesResults = loadGameResult()

// windows
const startGame = document.querySelector('.gameBegin')
const endGame = document.querySelector('.gameEnd')

// Constants
const table = document.querySelector('.tableBoard table')
const lastGamesTable = document.querySelector('.lastGamesTable')
const lastGamesTBody = document.querySelector('.lastGamesTable tbody')

const orange_reserve = document.querySelector('.orange_reserve')
const gray_reserve = document.querySelector('.gray_reserve')
const orange_points = document.querySelector('.orange_points')
const gray_points = document.querySelector('.gray_points')
const leftBoard = document.querySelector('.left_border')
const rightBoard = document.querySelector('.right_border')

const center = document.querySelector('.center')
const left = document.querySelector('.left')
const right = document.querySelector('.right')

const form = document.querySelector('form')
const btnContinueLastGame = document.querySelector('#continue')
const btnStartGame = document.querySelector('#star')
const btnRestartGame = document.querySelector('#restart')
const btnReload = document.querySelector('#reload')
const btnNewGame = document.querySelector('#new_game')
const btnStartNewGame = document.querySelector('#start_new_game')
const btnSaveGame = document.querySelector('#start_new_game')

//config
const player1 = document.querySelector('#player1')
const player2 = document.querySelector('#player2')
const row_size = document.querySelector('#row_size')
const col_size = document.querySelector('#col_size')
const win_value = document.querySelector('#win_value')
const nbr_kittens = document.querySelector('#nbr_kittens')

//
const winner = document.querySelector('#winner')



// Functions


function delegate(parent, type, selector, handler) {
    parent.addEventListener(type, function(event) {
        const targetElement = event.target.closest(selector)
        if (this.contains(targetElement))
            handler.call(targetElement, event)
    })
}


function updateLabels() {
    orange_points.innerText = count_OrangePoints
    orange_reserve.innerText = count_OrangeReserve

    gray_points.innerText = count_GrayPoints
    gray_reserve.innerText = count_GrayReserve
}


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

function fillBoardGame() {
    const tds = document.querySelectorAll('.tableBoard td')
    for (let i=0; i<tds.length; i++) {
        const row = Math.floor(i / numberOfColumns)
        const col = Math.floor(i % numberOfColumns)
        const val = boardGame[row][col]
        
        if (tds[i].firstElementChild){
            tds[i].removeChild(tds[i].firstElementChild)
        }
        if (val != 0) {
            tds[i].appendChild(createKitten(val, false))
        }
    }
}


function addBackgroundToThePlacesTwoBePushed(list) {
    const tds = document.querySelectorAll('.tableBoard td')
    for (let i=0; i<tds.length; i++) {
        const row = Math.floor(i / numberOfColumns)
        const col = Math.floor(i % numberOfColumns)
        for (coord of list) {
            if (row == coord.x && col == coord.y) {
                tds[i].classList.add('toBePushed')
                setTimeout(() => {
                    tds[i].classList.remove('toBePushed')
                  }, 1500);
            }
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

function generateTable() { // Based on the newly create values
    table.innerHTML = '' // Clean table
    for (let i = 0; i < numberOfRows; i++) {
            let tr ='<tr>'
            for (let j =0; j < numberOfColumns; j++) {
                tr+='<td></td>'
            }
            tr+= '</tr>'
            table.innerHTML += tr
    }
}

function processInformation() {
    WIN_VALUE = +win_value.value
    numberOfRows = +row_size.value
    numberOfColumns = +col_size.value
    count_OrangeReserve = +nbr_kittens.value
    count_GrayReserve = +nbr_kittens.value
    count_OrangePoints = 0
    count_GrayPoints = 0
    gameState = 1
    player = Math.round(Math.random()) + 1

    boardGame = []
    boardGame = Array(numberOfRows).fill().map(() => Array(numberOfColumns).fill(0));

    generateTable()
}

function saveGameResultData() {
    gamesResults.push({
        player1 : player1.value,
        player2 : player2.value,
        player1_points : count_OrangePoints,
        player2_points : count_GrayPoints,
        points_required_to_win : WIN_VALUE,
        data_time : new Date().toISOString(),
    })
    saveGameResult(gamesResults)
}

function updateState() {
    if((gameScored() && isGameWon()) || isGameLost()) {
        showGameOver()
    }
}


function processGame(restart) {
    if (restart) {
        processInformation() // restart
    }

    updateState()
    updateLabels()
    fillBoardGame() 
    fillKittensReserve(1, count_OrangeReserve)
    fillKittensReserve(2, count_GrayReserve)
    nextPlayer()
}

function restartGame() {
    gameState = 1
    processGame(true)
    hideGameOver()
    showGame()
}

function newGame() {
    gameState = 1
    hideGameOver()
    ShowStartMenu()

}
// Utilities 



// Methods
delegate(table, 'click', 'td', function(e) {
    const coordinates = xyCoord(this)
    if (placeKitten(coordinates)) {
        processGame()        
    } 
})

delegate(table, 'mouseover', 'td', function(e) {
    addBackgroundToThePlacesTwoBePushed(getListOfKittenToPushed(xyCoord(this)))
})




// Handling Drag and Drop
table.addEventListener('dragover', (e) => {
    e.preventDefault()
})

delegate(table, 'dragenter', 'td', function(e) {
    if (beingDragged)
        addBackgroundToThePlacesTwoBePushed(getListOfKittenToPushed(xyCoord(this)))
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
    } else
        beingDragged = null
})


// Starting form

form.addEventListener('submit', (e)=> {
    e.preventDefault() 
    processGame(true)
    hideStartMenu()
    showGame()
}) 


btnContinueLastGame.addEventListener('click', () => {
    latestGameData = loadAllGameData()
    WIN_VALUE = latestGameData.WIN_VALUE
    numberOfRows = latestGameData.numberOfRows
    numberOfColumns = latestGameData.numberOfColumns
    count_OrangeReserve = latestGameData.count_OrangeReserve
    count_GrayReserve = latestGameData.count_GrayReserve
    count_OrangePoints = latestGameData.count_OrangePoints
    count_GrayPoints = latestGameData.count_GrayPoints
    gameState = latestGameData.gameState
    player= latestGameData.player
    boardGame = latestGameData.boardGame

    generateTable()
    processGame()
    hideStartMenu()
    showGame()
})

btnSaveGame.addEventListener('click', () => {
    saveAllGameData({
        WIN_VALUE,
        numberOfRows,
        numberOfColumns,
        count_OrangeReserve,
        count_GrayReserve,
        count_OrangePoints,
        count_GrayPoints,
        gameState,
        player : player == 1 ? 2 : 1,
        boardGame,
    })
})


btnReload.addEventListener('click', restartGame)

btnRestartGame.addEventListener('click', restartGame) 

btnNewGame.addEventListener('click', newGame)

btnStartNewGame.addEventListener('click', () => {
    hideGame()
    newGame()

})

function hideGame() {
    right.style.display = 'none'
    left.style.display = 'none'
    center.style.display = 'none'
}

function showGame() {
    playStartSong()
    gameState = 1
    left.style.display = 'flex'
    right.style.display = 'flex'
    center.style.display = 'flex'
}

function hideStartMenu() {
    startGame.style.display = 'none'
}

function ShowStartMenu() {
    const latestGameData = loadAllGameData()
    if (!latestGameData) {
        btnContinueLastGame.disabled = true
    } else {
        btnContinueLastGame.disabled = false
    }

    while (lastGamesTBody.firstElementChild)
        lastGamesTBody.removeChild(lastGamesTBody.firstElementChild)
    // Insert the last data
    for (info of gamesResults.slice(-3)) {
        lastGamesTBody.innerHTML = `<tr> 
                            <td>${info.player1}</td> 
                            <td>${info.player2}</td> 
                            <td>${new Date(info.data_time).toLocaleDateString()}</td>
                             <td>${info.player1_points} - ${info.player2_points}</td> 
                             </tr>` + lastGamesTBody.innerHTML 
    }
    
    startGame.style.display = 'flex'
}



function showGameOver() {
    saveGameResultData()

    playGameWonSong()

    gameState = 2
    hideGame()
    winner.innerHTML = count_GrayPoints == WIN_VALUE ? player1.value : player2.value
    endGame.style.display = 'flex'
}

function hideGameOver() {
    endGame.style.display = 'none'
}




//* Starting configurations

hideGame()
hideGameOver()
ShowStartMenu()

