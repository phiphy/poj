#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

typedef map<string, int> formula;
typedef map<string, int>::iterator formulait;
typedef map<string, int>::const_iterator formulaconstit;

int read_digit(const string &s, int &i, char end)
{
    int d = s[i] - '0';
    for (++i; s[i]!=end && isdigit(s[i]); ++i)
        d = 10 * d + s[i] - '0';
    return d;
}
string read_element(const string &s, int &i, char end)
{
    int j = i;
    for (++i; s[i]!=end && islower(s[i]); ++i)
        ;
    return s.substr(j, i - j);
}

formula f(const string s, int &i, char end='\0')
{
    formula m, mm;
    int x, factor(1);
    string element;
    while (true) {
        if (s[i] == '+' || s[i] == end) {
            for (formulait it = mm.begin(); it != mm.end(); ++it)
                m[it->first] += it->second;
            ++i;
            if (s[i] == end) {
                break;
            }
            mm.clear();
            factor = 1;
            ++i;
        } else if (isdigit(s[i])) {
            factor = read_digit(s, i, end);
        } else if (isupper(s[i])) {
            element = read_element(s, i, end);
            if (isdigit(s[i]))
                x = read_digit(s, i, end) * factor;
            else
                x = factor;
            mm[element] += x;
        } else if (s[i] == '(') {
            formula mmm;
            mmm = f(s, ++i, ')');
            if (isdigit(s[i]))
                x = read_digit(s, i, end) * factor;
            else
                x = factor;
            for (formulait it = mmm.begin(); it != mmm.end(); ++it)
                mm[it->first] += it->second * x;
        }
    }
    return m;
}

bool g(const formula &m1, const formula &m2)
{
    if (m1.size() != m2.size())
        return false;
    formulaconstit it1, it2;
    for (it1 = m1.begin(); it1 != m1.end(); ++it1) {
        it2 = m2.find(it1->first);
        if (it2 == m2.end() || it2->second != it1->second)
            return false;
    }
    return true;
}

int main()
{
    int n, i(0);
    string ls, rs;
    formula lm, rm;
    cin>>ls;
    lm = f(ls, i);
    cin>>n;
    while (n--) {
        cin>>rs;
        i = 0;
        rm = f(rs, i);
        cout<<ls<<(g(lm, rm) ? "==" : "!=")<<rs<<endl;
    }
    return 0;
}
