var a = {member: true};
var b = Object.create(a); // 来自第 3 章
var t = a.hasOwnProperty('member'); // t 是 true
var u = b.hasOwnProperty('member'); // u 是 false
document.writeln(b.hasOwnProperty('hasOwnProperty')); // false
document.writeln(a.hasOwnProperty('hasOwnProperty')); // false