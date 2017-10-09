#!/usr/bin/php
<?php
print("Spencer\n");

#defining a variable
$number = 15;

#defining a string
$string = "Spencer Alfred Schafer";
print("$number\n$string.\n");

#adding a result to a variable
$addition = 21 + 21;
print($addition."\n");

#defining an array
$array = array(1, 2, 3, 4, 5);
print($array[1]."\n");

#defining a hash table
$hash = array("x" => "1", "y" => "2", "z" => "3");
echo $hash["x"]."\n";
print($hash["y"]."\n");

#printing recursively
print_r($hash);
print_r($array);

#creating a function
function add($a, $b)
{
	return($a + $b);
}

print(add("5", "10")."\n");

#if-else
if ($hash["x"] == "1")
	print("OK\n");
else
	print("ERROR\n");
?>
