const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

// ctx.fillStyle = 'orange'
// ctx.fillRect(50, 50, 80, 100)

// ctx.beginPath()
// ctx.moveTo(50, 50)
// ctx.lineTo(130, 50)
// ctx.lineTo(90, 0)
// ctx.closePath()
// ctx.stroke()

// ctx.fillStyle = 'red'
// ctx.fill()



// animations

let rect = {
    x: 0,
    y: 10, 
    w: 50,
    h: 70
}


function update(dt) {
    rect.x += 0.1 * dt
}

function render(){
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    ctx.fillRect(rect.x, rect.y, rect.w, rect.h)
}

let last = performance.now()
function gameLoop() {
    // For slow computer it will run slower, that is why we need to use this 

    // See: time independent animation loop
    let now = performance.now()
    let dt = now - last
    last = now


    update(dt)
    render()
    requestAnimationFrame(gameLoop)
}

// gameLoop()




// Drawing a Circle

let circles =  []

function updateCirc(dt) {
    for (const circle of circles) {
        circle.v += 0.01 * dt
        circle.y += 0.01 * circle.v * dt 


        if (circle.y > canvas.height - 20) {
            circle.v *= -1
         }
    }

}

function renderCirc(){
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    for (const circle of circles) {
        ctx.beginPath()
        ctx.arc(circle.x, circle.y, 20, 0, 2*Math.PI)
        ctx.fill()
    }


}


function gameLoopCirc() {
    let now = performance.now()
    let dt = now - last
    last = now

    updateCirc(dt)
    renderCirc()
    requestAnimationFrame(gameLoopCirc)
}

gameLoopCirc()
canvas.addEventListener('click', (e) => {
   circles.push({x: e.clientX, y:e.clientY, v:1})
})

// Taks:
/*
    1. make the circles accelerate
    2. make the circles bouce back on the bottom edge
*/