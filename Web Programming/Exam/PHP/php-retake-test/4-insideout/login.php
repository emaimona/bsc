<?php

// A jelszavak ugyanazok, mint a felhasználónevek, csak kisbetűkkel
// Passwords are the same as the username, but without capital letters.
// username: Joy   passowrd: joy

$users = [
    [ 'username' => 'Anger',    'image' => 'src/anger.png',     'password' => '$2y$10$lmWGeP7PIrtaLDcGxh/Vde73Om6xNAYRIid1Kk6cDmSBm88AOiCrK'],
    [ 'username' => 'Disgust',  'image' => 'src/disgust.png',   'password' => '$2y$10$kTVA1YfBVCmacocsmJjHpOgUz6W/jhjTKQXHsfcHLNM4JtkVvKjEC'],
    [ 'username' => 'Fear',     'image' => 'src/fear.png',      'password' => '$2y$10$f24OXlLARqSpO9PPMjbnZuxN5eIJRq/tNa958knrufsfFQDIvhKO2'],
    [ 'username' => 'Joy',      'image' => 'src/joy.png',       'password' => '$2y$10$.jq5VNxJG5LA3DCwbjnrYeI5g2ic.vt8c65qwvpI315gISFBDZyYe'],
    [ 'username' => 'Sadness',  'image' => 'src/sadness.png',   'password' => '$2y$10$3WqLSd0dWIK82DHPjg0WqOMwzXvoH4wZXkHOF5XmUD8rt8xK1kWc.']
];
    
    session_start();
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';

    if ($_POST && !isset($_SESSION['user'])) {       
        $user = array_filter($users, fn($u) => $u['username'] == $username);
        $user = count($user) ? $user[array_key_first($user)] : NULL;
        if (password_verify($password, $user['password'])) {
            $_SESSION['user'] = [ 
                "user" => $user['username'],
                "image" =>  $user['image']
            ];
        } 
    }

    header('location: index.php');
    exit();
?>