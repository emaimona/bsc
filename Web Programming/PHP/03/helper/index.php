<?php
    include_once('storage.php');
    $stor = new Storage(new JsonIO('data.json'));
    $data = $stor -> findAll();
?>

<h1>List of names</h1>

<i>in php the '.' dot sign means concatenation so we nee to use the -> sign</i> <br>
<i>Once arrays are easier we will use it like that instead of '$d -> name' </i> <br>
<i> In an url after '?' are a GET attributes</i>
<ul>
    <?php foreach($data as $id => $d): ?>
       <li> <a href="show.php?id=<?= $id ?>"> <?= $d['name'] ?>  </a> </li> </br> 
    <?php endforeach; ?>
</ul>

<a href=''>