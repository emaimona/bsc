<?php
	function validTime($time) {
		return preg_match("/^(?:[0-7]):[0-5][0-9]$/", $time);
	}

	$places = [
		'Írottkő',
		'Sárvár',
		'Sümeg',
		'Keszthely',
		'Tapolca',
		'Badacsonytördemic',
		'Nagyvázsony',
		'Városlőd',
		'Zirc',
		'Bodajk',
		'Szárliget',
		'Dorog',
		'Piliscsaba',
		'Hűvösvölgy',
		'Rozália téglagyár',
		'Dobogókő',
		'Visegrád',
		'Nagymaros',
		'Nógrád',
		'Becske',
		'Mátraverebély',
		'Mátraháza',
		'Sirok',
		'Szarvaskő',
		'Putnok',
		'Aggtelek',
		'Bódvaszilas',
		'Boldogkőváralja',
		'Sátoraljaújhely',
		'Hollóháza'
	];

	$errors = [];
	$trackname = $_GET['trackname'] ?? '';
	$from = $_GET['from'] ?? '';
	$to = $_GET['to'] ?? '';
	$distance = $_GET['distance'] ?? '';
	$time = $_GET['time'] ?? '';

	if ($_GET) {
		if ($trackname === '') {
			$errors['trackname'] = "Track name is required!";
		}
		//  else if (count(explode(' ', $trackname)) < 2) {
		// 	$errors['trackname'] = "Track name must be 2 words at least. </br>";
		// }

		if ($from === '') {
			$errors['from'] = "From is required";
		} else if (!in_array($from, $places)) {
			$errors['from'] = "From must be valid";
		}

		if ($to === '') {
			$errors['to'] = "To is required";
		} else if (!in_array($to, $places)) {
			$errors['to'] = "To must be valid";
		}
		if ($from === $to) {
			$errors['to'] = "From and To must be different";
		}

		if ($distance === '') {
			$errors['distance'] = "Distance is required!";
		} else if (filter_var($distance, FILTER_VALIDATE_FLOAT) === false) {
			$errors['distance'] = "Distance is not a number!";
		}

		if ($time === '') {
			$errors['time'] = "Time is required";
		} else if (!validTime($time)) {
			$errors['time'] = "Time format is invalid";
		}

		$errors = array_map(fn($e) => "<span style='color:red'> $e</span>", $errors);
	}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <title>Task 2</title>
</head>
<body>
    <h1>Task 2: Trip registration</h1>
    <form action="index.php" method="get" novalidate>
        <label for="i1">Track name:</label> <input type="text" name="trackname" id="i1" value='<?= $trackname ?? '' ?>'> <?= $errors['trackname'] ?? '' ?> <br>
        <label for="i2">From:</label> <input type="text" name="from" id="i2" value='<?= $from ?? '' ?>'> <?= $errors['from'] ?? '' ?> <br>
		<label for="i3">To:</label> <input type="text" name="to" id="i3" value='<?= $to ?? '' ?>'> <?= $errors['to'] ?? '' ?><br>
        <label for="i4">Distance:</label> <input type="text" name="distance" id="i4" value='<?= $distance ?? '' ?>'> <?= $errors['distance'] ?? '' ?> <br>
		<label for="i5">Time:</label> <input type="text" name="time" id="i5" value='<?= $time ?? '' ?>'> <?= $errors['time'] ?? '' ?> <br>
		<button type="submit">Register</button>
    </form>


    <div id="success" style="<?= $errors ? "display : none": ''?>;">
        <h2>Trip data saved!</h2>
	</div>


    <h2>Hyperlinks for testing</h2>
    <a href="index.php?trackname=&from=&to=&distance=&time=">trackname=&from=&to=&distance=&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=&to=&distance=&time=">trackname=10.sz.+túra&from=&to=&distance=&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Budapest&to=&distance=&time=">trackname=10.sz.+túra&from=Budapest&to=&distance=&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=&distance=&time=">trackname=10.sz.+túra&from=Sárvár&to=&distance=&time=</a><br>
	<a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Sárvár&distance=&time=">trackname=10.sz.+túra&from=Sárvár&to=Sárvár&distance=&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=&time=">trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=ezer&time=">trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=ezer&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=">trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=10">trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=10</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=10%3A60">trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=10%3A60</a><br>
    <a href="index.php?trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=4%3A10"><span style="color: green">Correct input: </span>trackname=10.sz.+túra&from=Sárvár&to=Dobogókő&distance=1000&time=4%3A10</a><br>

    </body>
</html>