Function.prototype.method = function (name, func) {
    this.prototype[name] = func;
    return this;
};

String.method('deentityify', function () {
// 字符实体表。它映射字符实体的名字到对应的字符。
    var entity = {
        quot: '"',
        lt: '<',
        gt: '>'
    };
// 返回 deentityify 方法。
    return function () {
// 这才是 deentityify 方法。它调用字符串的 replace 方法，
// 查找‘&’开头和‘;’结束的子字符串。如果这些字符可以在字符实体表中找到，
// 那么就将该字符实体替换为映射表中的值。它用到了一个正则表达式（参见第 7 章）。
        return this.replace(/&([^&;]+);/g,
            function (a, b) { //b regular expression result
                var r = entity[b];
                document.writeln(a);
                document.writeln(b);
                document.writeln(r);
                return typeof r === 'string' ? r : a;
            }
        );
    };
}());
document.writeln('&lt;&quot;&gt;'.deentityify( )); // <">
//<
//lt
//<
//"
//quot
//"
//>
//gt
//>
//<">