<?php
    session_start(); //* Should always be at the beginning of any page that uses sessions
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';

    $error = false;
    if ($_POST) {
        include_once 'storage.php';
        $stor = new Storage(new JsonIO('users.json'));
    
        $user = $stor->findOne(['username' => $username]);
        if (!$user) {
            $error = true;
        } else {
            if (password_verify($password, $user['password'])) {
                // Login successful
                $_SESSION['user_id'] = $user['id'];
                header('location: index.php');
                exit();
            } else {
                $error = true;
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
    <title>Login</title>
</head>
<body>
    <h1>Login</h1>
    <?php if($error): ?>
        <span style="color: red;">Invalid username or password</span> <br> <br>
    <?php endif; ?>

    <form action="login.php" method="POST">
        Username: <input type="text" class="text" name="username"> <br>
        Password: <input type="password" name="password" > <br>
        <button>Login</button>
    </form>

    
</body>
</html>