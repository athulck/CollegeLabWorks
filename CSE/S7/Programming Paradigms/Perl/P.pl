


print "\nHello World\n";



$foo = "albatross";

if ($foo =~ s/[aeiou]/-/) {
	print "\nTrue";
	print "\n".$1;
}
else {
	print "\nFalse";
}



print "\n".$foo."\n";