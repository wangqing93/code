
Function.prototype.method = function (name, func) {
    this.prototype[name] = func;
    return this;
};

Function.method('bind', function (that) {
    document.writeln(this);
    //    function () {
    //return this.value;
   //}
    document.writeln(arguments);
    //[object Arguments]
    var method = this,
        slice = Array.prototype.slice,
        args = slice.apply(arguments, [1]); //slice(start,end)  //start = 1
    document.writeln(args);
    //[object Object]
    return function () {
        document.writeln(that);
        return method.apply(that,
            args.concat(slice.apply(arguments, [0])));
    };
});
var x = function () {
    return this.value;
}.bind({value: 666});
alert(x());