const tr = document.querySelector("table tr");
const cells = document.querySelector("#cells");
const limit = document.querySelector("#limit");
const generateButton = document.querySelector("#generate");
const increaseButton = document.querySelector("#increase");

function randomBetween(min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min);
}

// Work here...
generateButton.addEventListener('click', () => {
    let tds = ''
    for (let i = 0; i < +cells.value; i++) {
        tds += '<td>0</td>'
    }
    tr.innerHTML = tds
})


increaseButton.addEventListener('click', () => {
    const tds = document.querySelectorAll('td')
    let largest_value = 1
    for(const td of tds) {
        const val = randomBetween(1, +limit.value) + +td.innerText
        td.innerText = val
        largest_value = Math.max(largest_value, val)
    }
    console.log(largest_value)
    for(const td of tds) {
        const lightness = (+td.innerText * 100) / largest_value
        td.style.backgroundColor = `hsl(10, 70%, ${lightness}%)`
    }
})
