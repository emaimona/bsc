const canvas = document.querySelector('canvas')
const ctx = canvas.getContext("2d")

// ctx.fillStyle = "orange"
// ctx.fillRect(50, 50, 80, 100)


// ctx.beginPath()
// ctx.moveTo(50, 50)
// ctx.lineTo(130, 50)
// ctx.lineTo(90, 0)
// // ctx.lineTo(50, 50)
// ctx.closePath()
// ctx.stroke()
// ctx.fillStyle = "red"
// ctx.fill()

let rect = {
    x : 0,
    y : 10,
    w : 50,
    h : 70,
}

// function update() {
//     rect.x += 0.1 * dt
// }

// function render() {
//     ctx.clearRect(0, 0, canvas.width, canvas.height)
//     ctx.fillRect(rect.x, rect.y, rect.w, rect.h)
// }

// let last = performance.now()

// function gameLoop() {
//     let now = performance.now()
//     dt = now - last
//     last = now
//     render()
//     update()
//     requestAnimationFrame(gameLoop)
// }

// gameLoop()


// ctx.beginPath();
// ctx.arc(X, Y, R, 0, 2 * Math.PI, false);
// ctx.lineWidth = 3;
// ctx.strokeStyle = '#FF0000';
// ctx.stroke();

circles = []
let v = 0.1

function render() {
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    for (const circ of circles) {
        ctx.beginPath()
        ctx.arc(circ.x, circ.y, 50, 0, 2 * Math.PI, false);
        ctx.fill()
    }
}

function update() {
    for (const circ of circles) {
        circ.s += 0.1
        circ.y += v * dt * circ.s
        // console.log(circles[0].y)

        if (circ.y > 600) {
            circ.s *= -1;
        }
    }


}
let last = performance.now()
function loop() {
    dt = performance.now() - last
    last = performance.now()
    render()
    update()
    requestAnimationFrame(loop)
}

loop()

canvas.addEventListener('click', (e) => {
    circles.push({x: e.clientX, y: e.clientY, s:1})
})