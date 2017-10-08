// 创建一个名为 Quo 的构造器函数。它构造一个带有 status 属性的对象。
var Quo = function (string) {
    this.status = string;
};
// 给 Quo 的所有实例提供一个名为 get_status 的公共方法。
Quo.prototype.get_status = function () {
    return this.status;
};
// 构造一个 Quo 实例。
var myQuo = new Quo("confused");
document.writeln(myQuo.get_status()); // confused

var myQuo;
myQuo = Quo("confused");
document.writeln(myQuo.get_status()); // no output