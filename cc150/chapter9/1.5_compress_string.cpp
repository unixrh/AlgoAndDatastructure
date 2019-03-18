/* 题目：利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
 * 解法：使用string直接拼接的。。。关键点在于string中拼入一个字符串时，最好的办法是push_back?
 */

#include <iostream>
#include <string>

using namespace std;

string compressStr(string str) {
    string res = "";
    for(int i = 0; i < str.size(); i++) {
        int count = 1;
        for(int j = i+1; j < str.size(); j++) {
            if(str[i] == str[j]) {
                count++;
            } else {
                break;
            }
        }
        res.push_back(str[i]);
        res += to_string(count);
        i += (count - 1);
    }
    if(res.size() >= str.size())
        return str;
    else
        return res;
}

int main(int argc, char* argv[]) {
    string str;
    cin >> str;
    cout << compressStr(str) << endl;
    return 0;
}
