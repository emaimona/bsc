<?php

$universes = [
    [
        'id' => 1610,
        'spiderman' => 'Miles Morales',
        'img' => 'src/miles.jpg',
        'movies' => [
            'Into the spiderverse',
            'Across the spiderverse'
        ]
    ],
    [
        'id' => 65,
        'spiderman' => 'Gwen Stacy',
        'img' => 'src/gwen.jpg',
        'movies' => [
            'Into the spiderverse',
            'Across the spiderverse'
        ]
    ],
    [
        'id' => 928,
        'spiderman' => 'Miguel O\'Hara',
        'img' => 'src/miguel.jpg',
        'movies' => [
            'Across the spiderverse'
        ]
    ],
    [
        'id' => 131222,
        'spiderman' => 'Peter "Lego" Parker',
        'img' => 'src/lego.png',
        'movies' => [
            'The LEGO Movie',
            'Across the spiderverse'
        ]
    ],
    [
        'id' => 50101,
        'spiderman' => 'Pavitr Prabhakar',
        'img' => 'src/pavitr.png',
        'movies' => [
            'Across the spiderverse'
        ]
    ],
    [
        'id' => 199999,
        'spiderman' => 'Peter "Tomholland" Parker',
        'img' => 'src/tomholland.jpg',
        'movies' => [
            'Spiderman: Homecoming',
            'Spiderman: Far from home',
            'Spiderman: No way home',
            'Avengers: Infinity War',
            'Avengers: Endgame',
            'Captain America: Civil War',
            'Venom'
        ]
    ]
];

    usort($universes, function($e1, $e2) { return $e1['id'] - $e2['id'];});
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 1 - Spiderverse</title>
    <link rel="stylesheet" href="src/index.css">
</head>
<body>
    <h1>Task 1 - Spiderverse</h1>


    <?php foreach($universes as $u): ?>
        <div>
        <h2>Earth-<?= $u['id'] ?></h2>
        <div>
            Appeared in <?= count($u['movies'])?> movie(s):
            <ul>
                <?php foreach($u['movies'] as $m): ?>
                    <li><?= $m ?></li>
                <?php endforeach; ?>
            </ul>
        </div>
        <img src="<?= $u['img'] ?>" title="<?= $u['spiderman'] ?>">
    </div>
    <?php endforeach; ?>
    
</body>
</html>