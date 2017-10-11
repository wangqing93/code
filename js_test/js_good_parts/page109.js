
var another_stooge = {
    "test":  "jjj"
};
var name = "test";
//another_stooge.hasOwnProperty = null; // 地雷
if (another_stooge.hasOwnProperty(name)) { // 触雷
    document.writeln(name + ': ' + another_stooge[name]);
}
document.writeln(another_stooge["constructor"]);
document.writeln(typeof(false));
var t= 0;
var tt = undefined;
document.writeln(Boolean(tt));
document.writeln(false == '0');
document.writeln(false == undefined);
document.writeln(false == null)
document.writeln(String(false));
