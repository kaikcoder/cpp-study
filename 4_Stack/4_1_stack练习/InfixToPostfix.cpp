/*
中缀表达式转后缀表达式过程：
    1.操作数输出不动
    2.操作符入栈通过比较确定计算顺序
    整体过程:
        -栈为空，操作符入栈
        -栈不为空，操作符比栈顶操作符优先级高，则入栈
        -栈不为空，操作符比栈顶操作符优先级等于或低出栈顶的运算符
*/