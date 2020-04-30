#define ALL(x) (x).begin(), (x).end()
#define _s(x) sort(ALL(x))
#define _so(x, f) sort(ALL(x), f)
#define _ms(x, b) memset(x, b, sizeof(x))
#define _mc(x, b) memcpy(x, b, sizeof(x))
#define _c(n, v) cout << n << "[" << v << "]" << endl
#define _f(i, a, b) for (i = a; i <= b; ++i)
typedef long long ll;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

fstream OUT;

struct dict
{
    string name;
    string type;
};

dict reserved[14] = {
    {"begin", "beginsym"},
    {"call", "callsym"},
    {"const", "constsym"},
    {"do", "dosym"},
    {"end", "endsym"},
    {"if", "ifsym"},
    {"odd", "oddsym"},
    {"procedure", "proceduresym"},
    {"read", "readsym"},
    {"then", "thensym"},
    {"var", "varsym"},
    {"while", "whilesym"},
    {"write", "writesym"},
    {"else", "elsesym"}};

dict kigou[16]{
    {"+", "plus"},
    {"-", "minus"},
    {"*", "times"},
    {"/", "slash"},
    {"=", "eql"},
    {"#", "neq"},
    {"<", "lss"},
    {"<=", "leq"},
    {">", "gtr"},
    {">=", "geq"},
    {":=", "becomes"},
    {"(", "lparen"},
    {")", "rparen"},
    {",", "comma"},
    {";", "semicolon"},
    {".", "period"}};

int Skbt(char &v)
{
    //字母
    if (v >= 'a' && v <= 'z')
    {
        return 1;
    }
    //数字
    else if (v >= '0' && v <= '9')
    {
        return 2;
    }
    //空格
    else if (v == ' ')
        return -1;
    //符号
    else
        return 3;
}
string def(string v)
{
    int i = 0;
    //number
    if (Skbt(v[0]) == 2)
    {
        _f(i, 0, v.size() - 1)
        {
            if (Skbt(v[i]) != 2)
                return "";
        }
        return "number";
    }
    //保留字
    i = 0;
    _f(i, 0, 13)
    {
        if (v == reserved[i].name)
            return reserved[i].type;
    }
    //符号
    i = 0;
    _f(i, 0, 15)
    {
        if (v == kigou[i].name)
            return kigou[i].type;
    }

    return "ident";
}

int output(string v)
{
    _c("        opt", v);
    _c("        def", def(v));

    if (v == "" || def(v) == "")
        return -1;
    else
    {
        OUT << '(' << def(v) << ',' << v << ')' << '\n';
    }
    return -9;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fstream IN;
    IN.open("input.txt");
    OUT.open("output.txt");
    string s, word, temp;
    while (getline(IN, s))
    {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        word = "";
        _c("line", s);
        int i = 0, flag = 0;
        while (s[i] != 0)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
            _c("    s[i]", s[i]);
            _c("    i:", i);
            _c("        word", word);
            //输入状态
            switch (Skbt(s[i])) //识别
            {
            case 1: //字母
                word += s[i];
                break;
            case 2: //数字
                word += s[i];
                break;
            case -1: //空格
                flag = 1;
                break;
            case 3: //符号
                if (word == "" || word == "<" || word == ">" || word == ":")
                {
                    word += s[i];
                    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '=' || s[i] == ';' || s[i] == '#' || s[i] == ',' || s[i] == '(' || s[i] == ')')
                        flag = 1;
                }
                else if (Skbt(s[i - 1]) != 3)
                {
                    flag = 1;
                    --i;
                }
                break;
            default:
                break;
            }
            if (s[i] == 0 || s[i + 1] == 0)
                flag = 1;
            if (flag == 1) //新词
            {
                output(word);
                word = "";
                flag = 0;
            }
            ++i;
        }
    }
    IN.close();
    OUT.close();
    return 0;
}