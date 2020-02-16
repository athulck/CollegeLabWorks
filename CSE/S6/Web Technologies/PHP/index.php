<!DOCTYPE html>
<html>
<head>
	<title>PHP</title>
</head>
<body>


<?php 

// phpinfo();

$var = 1;
echo isset($var);
unset($var);
echo isset($var);

echo "<br>";
$double = 3.14;
echo $double;

echo "<br>";
$double = 10e-14;
echo $double;
echo "<br>";

$name = "Athul";
echo "Hello $name \n Hai";
echo 'Hello $name \n';

echo "<br>";
echo TRUE;
echo FALSE;

echo "<br>".floor(13.6);
echo "<br>".ceil(13.6);
echo "<br>".round(13.5);
echo "<br>".srand(23);
echo "<br>".rand(320,323);
echo "<br>".abs(-13);
echo "<br>".min(12,13,14,15,16);
echo "<br>".max(12,13,14,15,16);


echo "<br>"."strlen of Hello is ".strlen("Hello");
echo "<br>"."strcmp of 'Hello' and 'Hello' is ".strcmp("Hello", "Hello");  // 0 means true
echo "<br>"."strpos of o in Hello is ".strpos("Hello", "o");
echo "<br>"."substr of 4,3 in HelloWorld is ".substr("HelloWorld", 4,3);
echo "<br>"."strtolower of HelloWorld is ".strtolower("HelloWorld");

echo "<br>";

$list['a'] = 5;
$list[] = 10;
echo $list['a'];

?>


</body>
</html>