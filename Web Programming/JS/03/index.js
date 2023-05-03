const li = document.querySelectorAll('li')

// for (const l of li) {
//     l.addEventListener('click', function () {
//         l.style.color = 'red'
//     })
// }


const ul = document.querySelector("ul")

ul.addEventListener('click', function(e) {
    if (e.target.matches('li'))
    e.target.style.color = 'red';
})

let time = null
document.addEventListener('click', function(e) {
    if (time === null) {
        time = e.timeStamp
    } else {
        // console.log(Math.floor((e.timeStamp - time) / 1000))
        time = e.timeStamp
    }
})

const table = document.createElement('table');
document.body.appendChild(table);

let lines = ""
for (let i=0; i<10; i++) {
    let tr = "<tr>"
    for (let j=0; j<10; j++) {
        tr += `<td> ${0} </td>`
    }
    lines +=  tr + "</tr>"
}
table.innerHTML = lines;
table.addEventListener('click', function(e) {
    if (e.target.matches('td')) {
        e.target.innerText = parseInt(e.target.innerText)+ 1
    }
})




/*Will not work */
// table.addEventListener('mouseover', function(e) {
//     if (e.target.matches('tr')) {
//         e.target.style.backgroundColor = "yellow";
//     }
// } 
// )


function delegate(parent, type, selector, handler) {
    parent.addEventListener(type, function(event) {
        const targetElement = event.target.closest(selector)
        if (this.contains(targetElement))
            handler.call(targetElement, event)
    })
}

delegate(table, 'mouseout', 'tr', function(e) {
    this.style.backgroundColor = ''
})
delegate(table, 'mouseover', 'tr', function(e) {
    this.style.backgroundColor = 'yellow'
})
