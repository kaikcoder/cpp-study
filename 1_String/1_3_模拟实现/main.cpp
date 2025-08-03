#include "String.h"
#include <iostream>

int main() {
    using guokai::String;

    String s1("hello");
    String s2(" world");

    std::cout << "原始 s1: " << s1 << '\n';
    std::cout << "原始 s2: " << s2 << '\n';

    s1 += '!';
    std::cout << "s1 += '!': " << s1 << '\n';

    s1 += s2.c_str();
    std::cout << "s1 += s2: " << s1 << '\n';

    s1.insert(5, ',');
    std::cout << "插入 ',' 后: " << s1 << '\n';

    s1.erase(6, 6);
    std::cout << "删除 6 个字符后: " << s1 << '\n';

    std::cout << "迭代器遍历 s1: ";
    for (String::iterator it = s1.begin(); it != s1.end(); ++it)
        std::cout << *it;
    std::cout << '\n';

    std::cout << "'o' 的位置: "  << s1.find('o')  << '\n';
    std::cout << "\"lo\" 的位置: " << s1.find("lo") << '\n';

    s1.clear();
    std::cout << "清空后 s1 是否为空: " << (s1.empty() ? "是" : "否") << '\n';
}
