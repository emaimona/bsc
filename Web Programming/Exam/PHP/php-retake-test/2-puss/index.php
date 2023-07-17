<?php
    $name = $_GET['name'] ?? ''; 
    $wish = $_GET['wish'] ?? '';
    $lives = $_GET['lives'] ?? '';
    $victory = $_GET['victory'] ?? false;
    $victory = filter_var($victory, FILTER_VALIDATE_BOOLEAN);

    $errors = [];
    $isGET = false;
    if ($_GET) {
        $isGET = true;
        if ($name === '') {
            $errors['name'] = "Name is required!";
        } else if (!in_array($name, ['puss', 'kitty', 'perrito', 'goldie'])) {
            $errors['name'] = "Unknown character!";
        }

        if (trim($wish) === '') {
            $errors['wish'] = "Making a wish is required!";
        }

        if ($lives === '') {
            $errors['lives'] = "Remaining lives are required!";
        } else if (filter_var($lives, FILTER_VALIDATE_INT) === false) {
            $errors['lives'] = "Remaining lives must be a whole number!";
        } else if (intval($lives) < 1)
            $errors['lives'] = "The wisher must have at least 1 life left!";

    
        if (!$victory)
            $errors['victory'] = "You may not wish now; enemies are nearby!";

    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 2 - Puss in Boots</title>
    <link rel=stylesheet href="src/index.css">
</head>
<body>
    <h1>Task 2 - Puss in Boots</h1>
    <h2>Wish</h2>
    <form action="index.php" method="GET" novalidate>
        <div>
            <label for="name">Name of wisher</label><br>
            <select name="name">
                <option value="puss">Puss in Boots</option>
                <option value="kitty">Kitty Softpaws</option>
                <option value="perrito">Perrito</option>
                <option value="goldie">Goldie</option>
            </select>
        </div>

        <div>
            <label for="wish">Wish</label><br>
            <input name="wish">
        </div>

        <div>
            <label for="lives">How many lives left?</label><br>
            <input name="lives">
        </div>

        <div>
            <label for="victory">Enemies defeated?</label><br>
            <input name="victory" type="checkbox"> Yes, both the Big Bad Wolf and Jack Horner have been defeated.
        </div>

        <div>
            <input type="submit" value="Make a wish">
        </div>
    </form>

    <?php if($errors): ?>
        <div>
            <h2>Error while wishing</h2>
            <ul>
                <?php foreach($errors as $e): ?>
                    <li><?= $e ?></li>
                <?php endforeach; ?>
                
            </ul>
        </div>
    <?php endif; ?>
    
    <?php if(!$errors && $isGET): ?>
        <div>
            <h2>Successful wishing</h2>
            <img src="src/end.jpg">
        </div>
    <?php endif; ?>

    <h2>Links for testing</h2>
    <ul>
        <li><a href="index.php?name=&wish=&lives=">❌name;❌wish;❌lives;❌victory</a></li>
        <li><a href="index.php?name=jack&wish=All the magic in the World&lives=1">❌name;✅wish;✅lives;❌victory</a></li>
        <li><a href="index.php?name=wolf&wish=Last life of Puss in Boots&lives=none&victory=on">❌name;✅wish;❌lives;✅victory</a></li>
        <li><a href="index.php?name=puss&wish=Give me back my lives&lives=0&victory=on">❌name;❌wish;✅lives;❌victory</a></li>
        <li><a href="index.php?name=puss&wish=Give me back my lives&lives=1&victory=on">✅name;✅wish;✅lives;✅victory</a></li>
    </ul>
</body>
</html>