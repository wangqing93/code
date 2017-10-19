var Foo = {};
var a1 = Object.create(Foo);

Object.defineProperty(Foo, "constructor", {
    enumerable: false,
    value: function Gotcha(){}
});

document.writeln(a1);  //object
document.writeln(Foo.constructor);  //function Gotcha() {}
document.writeln("test");