const containerDiv = document.querySelector("#container");
const counterSpan = document.querySelector("#span-counter");
const widthInput = document.querySelector("#input-width");
const heightInput = document.querySelector("#input-height");
const generateForm = document.querySelector("#form-generate");

function random(a, b) {
    return Math.floor(Math.random() * (b - a + 1)) + a;
}

function xyCoord(td) {
    return {
        x: td.cellIndex,
        y: td.parentNode.rowIndex,
    };
}

function distanceHue(x1, y1, x2, y2) {
    const distance = Math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2);
    const maxDistance = Math.sqrt((10 - 1) ** 2 + (14 - 1) ** 2);
    console.log(distance / maxDistance);
    const hue = (120 * distance) / maxDistance;
    return hue;
}

// Work here...
let randomX = random(0, 9)
let randomY = random(0, 13)
let heat_distance = 0
let clicks = 0

const table = document.querySelector('table')

function delegate(parent, type, selector, handler) {
    parent.addEventListener(type, function(event) {
        const targetElement = event.target.closest(selector)
        if (this.contains(targetElement))
            handler.call(targetElement, event)
    })
}
delegate(table, 'click', 'td', function(e) {
    const coordinates = xyCoord(this)
    heat_distance = distanceHue(randomX, randomY, coordinates.x, coordinates.y)
    this.style.backgroundColor = `hsla(${heat_distance},100%, 50%, 0.7)`
    if (randomX == coordinates.x && randomY == coordinates.y) {
        this.classList.add("treasure")
    }

    if (!this.dataset.clicked) {
        this.dataset.clicked = true
        counterSpan.innerHTML = ++clicks
    }
})