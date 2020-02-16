
// alert("Voila");

document.write(Number.MAX_VALUE+"<br>");
document.write(Number.MIN_VALUE+"<br>");
document.write(Number.NaN+"<br>");
document.write(Number.POSITIVE_INFINITY+"<br>");
document.write(Number.NEGATIVE_INFINITY+"<br>");


document.write(Math.PI+"<br>");
document.write(Math.sin(35)+"<br>");

document.write("<br>"+"August" + 1977);
document.write("<br>");
document.write(7*"30");  // 210


document.write("<br>"+String(123));
document.write("<br>"+(1977).toString());
document.write("<br>"+Number("1977"));
document.write("<br>"+("1977 "-0));

String.concat(1)
parseInt();
parseFloat();

("Hello").length;
("Hello").charAt(3);
("Hello").indexOf('l');
("Hello").substring(1,3);
("Hello").toLowerCase;
("Hello").toUpperCase;

/*
typeof null : "object"
typeof Object :"function"
*/

var today = new Date();
document.write("<br>"+today);
document.write("<br>Locale String : "+today.toLocaleString());
document.write("<br>Date : "+today.getDate());
document.write("<br>Month(0-11) : "+today.getMonth());
document.write("<br>Day(0-6) : "+today.getDay());
document.write("<br>Full Year : "+today.getFullYear());
document.write("<br>Time : "+today.getTime());
document.write("<br>Hours : "+today.getHours());
document.write("<br>Minutes : "+today.getMinutes());
document.write("<br>Seconds : "+today.getSeconds());
document.write("<br>Milliseconds : "+today.getMilliseconds());


window.alert("The sum is : ", 13); // returns undefined, won't render HTML
var bool = window.confirm("Is the sum : 14"); // If (OK) return true else if (Cancel) return false
var name = window.prompt("Enter your name : ", "");
window.console.log("Logged!");

// switch case is type sensitive
var item = 1;
switch (item) {
	case 1 : console.log("1");
			 break;
	case 2 : console.log("2");
			 break;
 	default: console.log("Default !"); 
}

var i = 0;
while(i < 10) {
	//console.log(i);
	i++;
}

for (var i=0; i<10; i++) {
	//console.log(i);
}

var obj = new Object({name:"Athul C K", age:20, relationship_status:"single"});
console.log(obj["name"], obj.age);
delete obj.name;


var arr = new Array(1,2,3, "4", "%");

var aa = Array(10) // [ <10 empty slots> ]

var arr = "Hai Hello Am I".split(" ");
arr.join(" ");




// jQuery

$("document").ready(function() {

	$("p").css("color","blue");
	
});





