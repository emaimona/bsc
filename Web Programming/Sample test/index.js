let youtubers = [
    {
        name: 'T-Series',
        videos: 17535,
        subscribers: 226000000,
        total_views: 203188101349
    },
    {
        name: 'Cocomelon - Nursery Rhymes',
        videos: 802,
        subscribers: 144000000,
        total_views: 140043959116
    },
    {
        name: 'SET India',
        videos: 95472,
        subscribers: 143000000,
        total_views: 130361573813
    },
    {
        name: 'PewDiePie',
        videos: 4507,
        subscribers: 112000000,
        total_views: 28537486596
    },
    {
        name: 'Kids Diana Show',
        videos: 1023,
        subscribers: 101000000,
        total_views: 82303088360
    },
    {
        name: 'MrBeast',
        videos: 729,
        subscribers: 105000000,
        total_views: 17480355779
    },
    {
        name: 'Like Nastya',
        videos: 717,
        subscribers: 101000000,
        total_views: 84126451538
    },
    {
        name: 'Vlad and Niki',
        videos: 488,
        subscribers: 87300000,
        total_views: 68558650784
    },
    {
        name: 'WWE',
        videos: 64170,
        subscribers: 91200000,
        total_views: 71692745898
    },
    {
        name: 'Zee Music Company',
        videos: 7008,
        subscribers: 88500000,
        total_views: 50506122721
    },
]

function delegate(parent, type, selector, handler) {
    parent.addEventListener(type, function (event) {
        const targetElement = event.target.closest(selector)
        if (this.contains(targetElement)) handler.call(targetElement, event)
    })
}

// WORK HERE!

const t1 = document.getElementById('t1')
const t2 = document.getElementById('t2')
const t3 = document.getElementById('t3')
const t4 = document.getElementById('t4')
const btn = document.querySelector('button')
const table = document.querySelector('table')
const input = document.querySelector('input')
let value

// 1
t1.innerText = youtubers.length

// 2
t2.innerHTML = youtubers.reduce( (bigger, n) => (n.videos > bigger ? n.videos : bigger), -Infinity)

// 3
t3.innerHTML = youtubers.every( n => n.videos > 500) ? "Yes": "No"

// 4
t4.innerHTML = youtubers.filter( n => n.subscribers > 100000000).map(n => n.name).join(', ')

// 5
btn.addEventListener("click", () => {console.log("The button has been clicked"); generateMatrix(parseInt(input.value))})

// 6
function generateMatrix(value) {
    let content = ''
    for (let i = 0; i < value; i++ ) {
        let tr = '<tr>'
        for (let j = 0; j < value; j++ ) {
            if (j != i)
                tr += `<td>0</td>`
            else
                tr += `<td class='diagonal'>0</td>`
        }
        content += tr + '</tr>'
    }
    table.innerHTML = content
}

table.addEventListener('click', (e) => {
    const tag = e.target
    const tr = tag.closest('tr')
    if (tag.tagName === 'TD') {
        tag.innerHTML = +tag.innerText + 1
        if (tag.innerText >= 6)
            tag.style.color = 'red'

        tr.style.backgroundColor = 'yellow'
    }
})