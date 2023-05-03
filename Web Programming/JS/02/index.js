const h1 = document.querySelector('h1')
h1.innerHTML = "Something else <i>Me</i>"

const h2s = document.querySelectorAll('h2')
// for (let h1 of h2s)
//     h1.style.color = 'green'


// Array.from(h2s).map( e => e.style.color = "orange")

h2s.forEach( h1 => h1.style.color = "orange")



let matrix =  [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [10, 11, 12]
]

// Create table

const table = document.querySelector('table')
// let content = ""
// for (let i=0; i<matrix.length; i++) {
//     content += "<tr>"
//     for (let j=0; j<matrix[i].length; j++)
//         content += "<td>" + matrix[i][j] + "</td>"
//     content += "</tr>"
// }

// table.innerHTML = content


// for (let i=0; i < matrix.length; i++) {
//     let tr = document.createElement('tr')
//     for (let j=0; j<matrix[i].length; j++) {
//         let td = document.createElement('td')
//         td.innerHTML = matrix[i][j]
//         tr.appendChild(td)
//     }
//     table.appendChild(tr)
// }



// matrix.map( row =>  {
//     const tr = document.createElement('tr')
//     row.map( el => {
//         const td = document.createElement('td')
//         td.innerText = el
//         tr.appendChild(td)
//     })
//     table.appendChild(tr)
// })


matrix.forEach(row => {table.innerHTML += `<tr> ${row.map(cel => `<td>${cel}</td>`).join(' ')}</tr>`})

// table.innerHTML = matrix.map(row => '<tr>')