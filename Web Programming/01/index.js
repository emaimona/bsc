let arr = [2, 1, ,-4, 3, 0]
arr[100]  = 100
let newarr = []

// for (let i=0; i<arr.length; i++)
//     if (arr[i] % 2 == 0)
//         newarr.push(arr[i])

// console.log(newarr)

// for (const el of arr)
//     (el % 2 ===  0) ? newarr[newarr.length] = el : el; 

console.log(arr.filter(function(el){
    return el % 2 === 0;
}))

console.log(arr.filter( (el) => el % 2 === 0))
console.log( arr.map((n) => 2*n))
console.log( arr.map((n, i) => 2*n + i))

console.log( arr.reduce( (sum , n) => (sum + n ), 0))


// Maximum element
console.log('The maximum element is' + arr.reduce( (bigger, n) => (n > bigger ? n : bigger), -Infinity) )

// spread operator
console.log( Math.max(...arr))

let car = {
    year: 1007,
    model: 'Tesla Model Y', 
    works: true
}

console.log(car.year)
console.log(car['year'])


let cars = [
    {
        year: 1007,
        model: 'Tesla Model Y', 
        works: true
    },
    {
        year: 1007,
        model: 'Dolbe Model Y', 
        works: true
    },
    {
        year: 1007,
        model: 'Tesla Model Y', 
        works: false
    },
    
]

console.log('Car that work ' + (cars.filter( (el) => el.works === true)))



// Count less Function

function countLess(limit, array) {
    return array.filter( x =>  x < lim)
}

function countLessReduce(limit, array) {
    return array.reduce( (res, x) => x < limit ? res + 1 : res, 0 )
}

const countLessArrow = (limit, array) => array.filter( x => x < limit).length