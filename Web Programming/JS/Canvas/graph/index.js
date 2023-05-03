const canvas = document.querySelector('canvas')
const ctx = canvas.getContext('2d')

const bp = document.querySelector('.bp')
const sp = document.querySelector('.sp')
const bm = document.querySelector('.bm')
const sm = document.querySelector('.sm')

let b = false
let s = false
const change = 10
let BigMac = {
    x : 0,
    y : 250,
    up : false,
    val : 250
}

let Spotify = {
    x : 0,
    y : 200,
    up : false,
    val : 300
}

ctx.beginPath();

bp.addEventListener('click', () => {
    ctx.beginPath();
    ctx.strokeStyle = 'red'
    ctx.moveTo(BigMac.x, BigMac.y);
    BigMac.x += change
    BigMac.y -= change
    ctx.lineTo(BigMac.x, BigMac.y);
    ctx.stroke();

    BigMac.val += change
    if (!BigMac.up && BigMac.x !== change) {
        ctx.fillStyle = 'red'
        ctx.fillText(BigMac.val, BigMac.x, BigMac.y)
        ctx.stroke()        
    }
    BigMac.up = true
})

bm.addEventListener('click', () => {
    ctx.beginPath();
    ctx.strokeStyle = 'red'
    ctx.moveTo(BigMac.x, BigMac.y);
    BigMac.x += change
    BigMac.y += change
    ctx.lineTo(BigMac.x, BigMac.y);
    ctx.stroke();

    BigMac.val -= change

    if (BigMac.up && BigMac.x !== change) {
        ctx.fillStyle = 'red'
        ctx.fillText(BigMac.val, BigMac.x, BigMac.y)
        ctx.stroke()        
    }
    BigMac.up = false
})

sp.addEventListener('click', () => {
    ctx.beginPath();
    ctx.strokeStyle = 'green'
    ctx.moveTo(Spotify.x, Spotify.y);
    Spotify.x += change
    Spotify.y -= change
    ctx.lineTo(Spotify.x, Spotify.y);
    ctx.stroke();

    Spotify.val += change
    if (!Spotify.up && Spotify.x !== change) {
        ctx.fillStyle = 'green'
        ctx.fillText(Spotify.val, Spotify.x, Spotify.y)
        ctx.stroke()        
    }
    Spotify.up = true
})
sm.addEventListener('click', () => {
    ctx.beginPath();
    ctx.strokeStyle = 'green'
    ctx.moveTo(Spotify.x, Spotify.y);
    Spotify.x += change
    Spotify.y += change
    ctx.lineTo(Spotify.x, Spotify.y);
    ctx.stroke();

    Spotify.val -= change
    if (Spotify.up && Spotify.x !== change) {
        ctx.fillStyle = 'green'
        ctx.fillText(Spotify.val, Spotify.x, Spotify.y)
        ctx.stroke()        
    }

    Spotify.up = false
})