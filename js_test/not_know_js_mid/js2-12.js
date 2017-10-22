var a = [];
a["14"] = 42;
a.splice(0,2);  //size change
document.writeln(a.length);  //13
delete a[4]
document.writeln(a.length);  //13
document.writeln(a[4])  //undefined
