

// Functions

function xyCoord(td) {
    return {
        x: td.cellIndex,
        y: td.parentNode.rowIndex,
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
let count_OrangeReserve = 8
let count_GrayReserve = 8
let count_OrangePoints = 0
let count_GrayPoints = 0
let gameState = 0// 0 - start
let player = nextPlayer(Math.round(Math.random()) + 1) // 1 - OrangeCat, 2 - GrayCat

// 0 - Empty, 1 - Orange, 2 - GrayCat
let boardGame = [
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0],
]
const kitten = {
    x: -1,
    y: -1,
    color: 'gray',
    img: new Image(),
    onBoard: false, // onTheBoard
};




function updateState() {
    
}

function changePlayerBackground() {

}

function pushCats() {
    
}

function nextPlayer() {
    pushCats()
    if (player == 1)
        player = 2
    else
        player = 1
    changePlayerBackground() //* - to implement
}

console.log('Player', player)

function isPlaceVacant(coord) {
    return boardGame[coord.x][coord.y] === 0
}

function placeKitten(coord) {
    if (!isPlaceVacant(coord)) {
        return false
    } 

    boardGame[coord.x][coord.y] = player
}

// kitten.img.src = 'asteroid.png';
// rocket.img.src = 'rocket.png';


