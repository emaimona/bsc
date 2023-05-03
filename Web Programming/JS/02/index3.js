const target = Math.ceil( Math.random() * 100 );

const button = document.querySelector('button')
const span = document.querySelector('span')
const input = document.querySelector('input')

function checkResult() {
    let value = parseInt(input.value)

    if (!isNaN(value)) {
        if (value < target) {
            span.innerText = 'Target is HIGHER'
        } else if (value > target) {
            span.innerText = 'Target is LOWER'
        } else  
            span.innerText = 'CORRECT'
    } else
        span.innerText = 'Type a number, bruh.'
}


button.addEventListener('click', checkResult)