const canvas = document.querySelector('canvas');
const ctx = canvas.getContext("2d");

// Application state
const plane = {
  x: 0,
  y: 20,
  width: 60,
  height: 30,
  vx: 0,
  img: new Image(),
};
const parcel = {
  x: 0,
  y: plane.y + plane.height,
  width: 30,
  height: 30,
  vx: 0,
  vy: 0,
  ay: 0,
  img: new Image(),
};
const house = {
  x: 400,
  y: canvas.height - 120,
  width: 100,
  height: 100,
  img: new Image(),
};
let gameState = 0; // 0-start, 1-moving, 2-dropping, 3-hit, 4-missed

// ================= Game loop =====================

// Time-based animation (from the lecture slide)
let lastFrameTime = performance.now();

function next(currentTime = performance.now()) {
  const dt = (currentTime - lastFrameTime) / 1000; // seconds
  lastFrameTime = currentTime;

  update(dt); // Update current state
  render(); // Rerender the frame

  requestAnimationFrame(next);
}

function update(dt) {
    if (gameState > 0) {
      plane.vx = 200
      plane.x += plane.vx * dt;
      if (gameState <= 2) 
        parcel.x = plane.x
    } 
    if (gameState == 2) {
      parcel.ay = 300
      parcel.vy += dt * parcel.ay
      parcel.y += parcel.vy * dt;
      if (isCollision(house, parcel)) {
        gameState = 3;
      }
    }

    if (parcel.y > canvas.height) {
      gameState = 4;
    }
}

function render() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.drawImage(plane.img, plane.x, plane.y, plane.width, plane.height)
  ctx.drawImage(house.img, house.x, house.y, house.width, house.height)
  ctx.drawImage(parcel.img, parcel.x, parcel.y, parcel.width, parcel.height)
  if (gameState == 3) {
    ctx.fillText("Delivered", 50, 0, 140);
  }
  if (gameState == 4) {
    ctx.fillText("Missed", 50, 90, 140);
  }
}

// Start the loop
plane.img.src = "plane.png";
house.img.src = "house.png";
parcel.img.src = "parcel.png";
next(); 


// =============== Utility functions =================

function isCollision(box1, box2) {
  return !(
    box2.y + box2.height < box1.y ||
    box1.x + box1.width < box2.x ||
    box1.y + box1.height < box2.y ||
    box2.x + box2.width < box1.x
  );
}

canvas.addEventListener('click', () => {
  if (gameState === 0) {
      gameState = 1
  } else if (gameState === 1) {
    gameState = 2
  }
  console.log('click')
})

