var myVariable = 'global';
var myOtherVariable = 'global';

function myFunction() {
	var myVariable = 'local';
	return myVariable;
}

function myOtherFunction() {
	myOtherVariable = 'local';
	return myOtherVariable;
}

console.log(myVariable);		//{1}
console.log(myFunction());		//{2}
console.log(myOtherVariable);	//{3}
console.log(myOtherFunction());	//{4}
console.log(myOtherVariable);	//{5}