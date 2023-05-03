const task1 = document.querySelector('#task1');
const task2 = document.querySelector('#task2');
const task3 = document.querySelector('#task3');
const task4 = document.querySelector('#task4');

console.log(cities);
console.log(connections);

// Work here...
function getInfo(name) {
    for (const city of cities) {
        if (city.city === name)
            return city;
    }
}

const Constantinople = getInfo('Constantinople')
task1.innerHTML = `${Constantinople.today}, ${Constantinople.country}`

task2.innerHTML  = (cities.filter(cities => cities.x >= 30 && cities.x <= 60 && cities.y >= 40 && cities.y <= 60)).map( place => place.today).join(' , ')

task3.innerHTML = connections.filter(cities => cities.toCity == 'Budapest').length > 0

const greenConnections = connections.filter(cities => cities.color == 'green')
const sum = greenConnections.reduce((acc, val) => acc + val.elements.length, 0)
task4.innerHTML = sum / greenConnections.length

confetti.start(1200)

