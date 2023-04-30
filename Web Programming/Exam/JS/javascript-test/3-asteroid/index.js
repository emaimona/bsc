const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

const width = canvas.width;
const height = canvas.height;

// My values
let gameState = 0; // 0-start, 1-won, 2-lost
ctx.font = "90px Arial";
ctx.fillStyle = 'aqua'
 
const asteroid = {
    x: 0,
    y: 20,
    width: 50,
    height: 40,
    img: new Image(),
    vx: 60
};
const rocket = {
    x: width / 2,
    y: height - 50,
    width: 20,
    height: 50,
    img: new Image(),
    vy: 0
};
asteroid.img.src = 'asteroid.png';
rocket.img.src = 'rocket.png';

// =============== Utility functions =================

function isCollision(box1, box2) {
    return !(
        box2.y + box2.height < box1.y ||
        box1.x + box1.width < box2.x ||
        box1.y + box1.height < box2.y ||
        box2.x + box2.width < box1.x
    );
}

function calculateScore() {
    return Math.round(
        100 *
            Math.abs(
                asteroid.x + asteroid.width / 2 - rocket.x - rocket.width / 2
            )
    );
}

// ============= From the lecture =================

let lastFrameTime = performance.now();

function next(currentTime = performance.now()) {
    const dt = (currentTime - lastFrameTime) / 1000; // seconds
    lastFrameTime = currentTime;

    update(dt); // Update current state
    render(); // Rerender the frame

    requestAnimationFrame(next);
}

function update(dt) {
    if (gameState === 0) {
        asteroid.x += asteroid.vx * dt;
        rocket.y += rocket.vy * dt;
        if (isCollision(rocket, asteroid)) {
            console.log("Boom")
            gameState = 1
        }
    }

    if (rocket.y + rocket.height < 0) {
        gameState = 2
    }

}

function render() {
    ctx.clearRect(0, 0, width, height); // Clear the canvas first
    ctx.drawImage(asteroid.img, asteroid.x, asteroid.y, asteroid.width, asteroid.height)
    ctx.drawImage(rocket.img, rocket.x, rocket.y, rocket.width, rocket.height)

    if (gameState == 1) {
        ctx.fillText(`Won: ${calculateScore()} pts`, 50, 300, 300);
    } else if (gameState == 2) {
        ctx.fillText(`Lost`, 50, 300, 300);
    }

}

next(); // Start the loop

window.addEventListener('keypress', () => {
    rocket.vy = -200

})
