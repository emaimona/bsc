const form = document.querySelector("form");
const divContainer = document.querySelector(".container");

const inputs = document.querySelectorAll("input");

const consumptions = Array.from(inputs).map( e => {
    return parseInt(e.dataset.consumption);
}) 

const sum = consumptions.reduce( (sum, value) => sum + value, 0)
// const max = Math.max(...consumptions);
// consumptions.forEach( e =>{ console.log(e)})

// consumptions.forEach( e =>{ console.log( (sum / max) * e)})
// console.log(max)
console.log(sum);






// 2b
let arr = []
for (const input of inputs) {
    arr.push(input.value / input.max * input.dataset.consumption)
}
console.log(arr)


// 2b. -v2
console.log(Array.from(inputs).map( input => input.value * input.dataset.consumption))

// 2c.
arr = []
for(const input of inputs) {
    ci = input.value  / input.mamx * input.dataset.consumption
    arr.push(ci)

    //2c.
    const label = document.querySelector(`label[for=${input.id}]`)
    label.style.width = (ci * M / 100) + '%'
}

console.log(arr)

// 2d.
function update() {
    let arr = []
    for(const input of inputs) {
        ci = input.value  / input.mamx * input.dataset.consumption
        arr.push(ci)
    
        //2c.
        const label = document.querySelector(`label[for=${input.id}]`)
        label.style.width = (ci / M * 100) + '%'
    }
}
update()
form.addEventListener('input', update)
