// Event Handling 

const output = document.querySelector('span')
const button = document.querySelector('button')


function increaseByOne() {
    // let value = parseInt(output.innerText)
    let value = +output.innerText
    value = value + 1
    output.innerText = value
}

button.addEventListener('click', increaseByOne)