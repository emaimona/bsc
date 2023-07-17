<?php
    session_start(); //* Start a new session or resumes the existing one
    //* The values of a session are specific to each user, that is, there will not be available in other browser session
    
    /* ** WHE ARE 
     * 1 - Session based authentication (the server store the data)
     * 2 - Token based authentication (client has all the data, eg: JWT) => JWT is just for authorization, not for authentication
     */
    if (!isset($_SESSION['count']))
        $_SESSION['count'] = 0;
    else
        $_SESSION['count']++;


    if (!isset($_SESSION['user_id'])) {
        header('location: login.php');
        exit();
    } else {
        include_once 'storage.php';
        $stor = new Storage(new JsonIO('users.json'));
        $user = $stor->findById($_SESSION['user_id']);
    }

?>

<h1>Count: <?= $_SESSION['count'] ?> </h1>

<h2> Hello, <?= $user['username']?>!</h2>

<a href="logout.php">Log out</a> <br>


Search by name: <input type="text" id="search"> <br>
<table>
    
</table>
    
<br>
<script src="ajax.js"></script>
