// call hello() : undefined undefined A 5 undefined A
var s = "\u0041";
function add(x, y)
{
    x = 1;
    document.writeln(this.x);
    document.writeln(this.s);
    document.writeln(x+y);
    return x+y;
}
function hello() {
    var x = 3;
    var y = 4;
    document.writeln(this.x);
    var sum = add(x,y);
    document.writeln(this.x);
    document.writeln(this.s);
}