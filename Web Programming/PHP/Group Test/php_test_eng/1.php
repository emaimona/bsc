<?php
    $cell_classes = [
        ['eligendi', 'deserunt', 'eligendi', 'deserunt', 'pariatur', 'pariatur', 'pariatur'],
        ['eligendi', 'deserunt', 'eligendi', 'deserunt', 'deserunt', 'deserunt', 'pariatur'],
        ['eligendi', 'eligendi', 'eligendi', 'deserunt', 'pariatur', 'pariatur', 'pariatur'],
        ['deserunt', 'deserunt', 'eligendi', 'deserunt', 'pariatur', 'deserunt', 'deserunt'],
        ['deserunt', 'deserunt', 'eligendi', 'deserunt', 'pariatur', 'pariatur', 'pariatur'],
    ];

    $rowSize = count($cell_classes);
    $colSize = count($cell_classes[0]);

    $deseruntCount = 0;
    forEach ($cell_classes as $rows) {
        forEach ($rows as $cell) {
            if ($cell === 'deserunt') {
                $deseruntCount++;
            }
        }
    }
        

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <title>PHP GROUP TEST</title>
</head>
<body>
    <h1>PHP GROUP TEST</h1>

    <h2>Task 1: Output generation from array</h2>

    Array dimensions: <b> <?= $rowSize ?> x <?= $colSize ?> </b>
    <br>
    Total number of <i>deserunt</i> values: <b><?= $deseruntCount ?></b>

    <table>
        <?php 
            forEach ($cell_classes as $x => $rows) {
                echo '<tr>';
                forEach ($rows as $y => $cell) {
                    echo '<td class="' . $cell . '">' . ($x+1) . ($y+1) . '</td>';
                }
                echo '</tr>';
            }
        ?>
    </table>
</body>
</html>
