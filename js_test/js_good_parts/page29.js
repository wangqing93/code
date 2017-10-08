
var myObject = {
    value:1,
    incre:function() {
        this.value += 1;
    }
}
document.writeln(myObject.value);//1
myObject.incre();
document.writeln(myObject.value); //2

var value = 100;
function add(x, y) {
    return x+y;
}
document.writeln(this.value);

myObject.double = function () {
    var that = this; //解决方法
    var helper = function () {
        that.value = add(that.value, that.value);
    };
    helper(); //以函数的形式调用 helper。
};
myObject.double();
document.writeln(myObject.value);//4

myObject.double1 = function () {
    var helper = function () {
        document.writeln(this.value); //100
        this.value = add(this.value, this.value);
    };
    helper(); //以函数的形式调用 helper。
};
// 以方法的形式调用 double。
myObject.double1();
document.writeln(myObject.value);//4
document.writeln(this.value);//200





