<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 4 - Inside Out</title>
    <link rel=stylesheet href="src/index.css">
</head>
<body>
    <h1>Task 4 - Inside Out</h1>
    
    <?php if(isset($_SESSION['user'])): ?>
        <h2>Riley emotion control panel</h2>
        <form action='logout.php'>
            <input type="submit" value="LOGOUT">
        </form>
        <div>
            <img src="<?= $_SESSION['user']['image'] ?? ''?>">
        </div>
    <?php else: ?>
        <h2>Log in</h2>
        <form action='login.php' method='post'>
            <input name="username" placeholder="Username">
            <input name="password" type="password" placeholder="Password">
            <input type="submit" value="LOGIN">
        </form>
    <?php endif; ?>
   
</body>
</html>