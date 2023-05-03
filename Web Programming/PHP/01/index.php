Hello world
<?php
    $array = [1, 2, 3, 4, 5, 6];

    //* does not work
    // print($array);
    // echo($array);

    //* solution
    print_r($array);


    // loop
    for ($i=0; $i<count($array); $i++) {
        print($array[$i]);
    }

    // another solution
    foreach($array as $val) {
        echo ' ' . $val;
    }

    // if i need also the key
    foreach($array as $key => $val) {
        print($key . ' => ' . $val);
    }

    echo '<h1> Associative Array</h1>';
    //* this is just an array set customlly
    $object = [
        'year' => 1239,
        'month' => 12,
        'day' => 1
    ];

    foreach($object as $key => $val) {
        echo '<b>' . $key . '</b> ' . $val . '</br>';
    }


    echo '<h1>Filter</h1>';
    print_r($array);
    echo '<br>';

    $filtered = array_filter($array, function ($val) {
        return $val % 2 == 0;
    });

    print_r($filtered); echo '   =>  <i>this is why we should not index the array and use the foreach instead</i>';

    echo '</br></br> <b>functions do not see anything outside the scope even if it is a global, hence use \'use ($variable)\'</b><br>';
    $c = 0;
    $filtered = array_filter($array, function ($val) use ($c) {
        return $val % 2 == $c;
    });


    $colors = ['r', 'g', 'b', 'b', 'g', 'r', 'r'];

    $rs = count(array_filter($colors, function ($col) { return $col == 'r';}));

    //* arrow functions
    $bs = count(array_filter($colors, fn($col) => $col === 'g'));

    echo '<h4> Rs: ' . $rs . ', Bs: ' . $bs .'</h4>';

    //* We use " " for string substitution
    echo "<b> Rs: $rs, Gs: $bs </b>  =>  <i> using string substitution </i> <br>";


    $matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];

    $data = [
        ['name' => 'John Doe', 'neptun' => 'ABC001', 'grade' => 2  ],
        ['name' => 'Petar Petrovic', 'neptun' => 'ZZZ111', 'grade' => 5  ],
        ['name' => 'Yamada Hanako', 'neptun' => 'XXXASD', 'grade' => 3  ],
    ]
?>


<br>
<h2>This syntax is only used to output value</h2>
<h4> Red and Blue</h4>
Red count: <?= $rs ?> <br>
Blue count: <?= $bs ?> <br>

<div style='background-color: blue; width: <?= 100 * $rs ?>px;'></div>

<h1> lists </h1>

<ul>
    <?php foreach($colors as $col): ?>
        <li><?= $col ?></li>
    <?php endforeach; ?>
</ul>

<h1>Tables</h1>

<table>
    <?php foreach($matrix as $row): ?>
        <tr>
            <?php foreach($row as $val): ?>
                <td><?= $val ?></td>
            <?php endforeach; ?>
        </tr>
    <?php endforeach; ?>
</table>


<h1>Table from an array of associative arrays</h1>

<table>
    <?php foreach($data as $row): ?>
        <tr>
            <td><?= $row['name'] ?> </td>
            <td><?= $row['neptun'] ?> </td>
            <td><?= $row['grade'] ?> </td>
        </tr>
    <?php endforeach; ?>
</table>