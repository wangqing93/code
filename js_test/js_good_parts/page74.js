function Window_Load(){
        //分组捕获
    var str='aaa2312 dzcv3423  aaa 4434';
    var re=/[a-z]+(\d+)/ig;
    document.writeln("string: " + str);
    document.writeln("<br />");

    var i=1;
    document.writeln("分组捕获(/[a-z]+(\d+)/ig)");
    while(re.exec(str)){
        document.writeln("第" + i + "次匹配：" + RegExp.lastMatch + "   分组1：" + RegExp.$1);
        i++;
    }

    var result = re.exec(str);
    for (i = 0; i < result.length; i++)
        document.writeln(i + ": " + result[i])
    document.writeln("<br />");

        //分组不捕获
    var str='aaa2312 dzcv3423  aaa 4434';
    var re=/[a-z]+(?:\d+)/ig;

    var i=1;
    document.writeln("分组不捕获(/[a-z]+(?:\d+)/ig)");
    while(re.exec(str)){
        document.writeln("第" + i + "次匹配：" + RegExp.lastMatch + "   分组1：" + RegExp.$1);
        i++;
    }
    var result = re.exec(str);
    for (i = 0; i < result.length; i++)
        document.writeln(i + ": " + result[i])
    document.writeln("<br />");
}

function test_exp() {
    var testStr = "windows 95";
    document.writeln("string: " + testStr);
    /* 1 - 不带子表达式匹配 */
    var testReg = /^windows .*$/
    var result = testStr.match(testReg);
    document.writeln("/^windows .*$/ = "+result) // /^windows .*$/=windows 95

    /* 2 - 带子表达式匹配 */
    var testReg = /^windows (.*)$/
    var result = testStr.match(testReg);
    document.writeln("/^windows (.*)$/ = "+result) // /^windows (.*)$/=windows 95,95

    /* 3 - 带子表达式，不记录其匹配结果 */
    var testReg = /^windows (?:.*)$/
    var result = testStr.match(testReg);
    document.writeln("/^windows (?:.*)$/ = "+result) // /^windows (?:.*)$/=windows 95

    /* 4 - 前瞻匹配，匹配位置，正匹配 */
    var testReg = /^windows (?=95)95$/
    var result = testStr.match(testReg);
    document.writeln("/^windows (?=95)9$/ = "+result) // /^windows (?=.*)$/=windows 95

    var testReg = /^windows (?=95)$/
    var result = testStr.match(testReg);
    document.writeln("/^windows (?=95)$/ = "+result) // /^windows (?=.*)$/=windows 95

    /* 5 - 前瞻匹配，匹配位置，负匹配 */
    var testStr = "windows me"
    document.writeln("string: " + testStr);
    var testReg = /^windows (?!95)me$/
    var result = testStr.match(testReg);
    document.writeln("/^windows (?!95)me$/ = "+result) // /^windows (?!d*)$/=windows me
}

Window_Load();
test_exp();