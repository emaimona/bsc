const form = document.querySelector("form");
const divContainer = document.querySelector(".container");

const inputs = document.querySelectorAll('input')

let M = Array.from(inputs).map( input => parseInt(input.dataset.consumption)).reduce( (acc, val) => acc + val, 0)
console.log('M = ',M);

function currentConsumption() { 
    return Array.from(inputs).map( input => +((input.value/input.max)*input.dataset.consumption).toFixed(2))
}
function adjustLabels() {
    Array.from(inputs).map( input => {
        const obj = document.querySelector(`label[for=${input.id}]`)
        obj.style.width = ((input.value/input.max)*input.dataset.consumption) +"px"
    })
}

console.log(currentConsumption())
adjustLabels()

form.addEventListener('input', ( ) =>{

   adjustLabels()
   console.log(currentConsumption())
})