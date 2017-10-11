var foo = function() {
    return {
        status:true
    }
};

var foo1 = function() {
    return
    {
        status:true
    }
};

document.writeln(foo().status); // true
document.writeln(foo1().status); //nothing