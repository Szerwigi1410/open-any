#include <string>
#include <iostream>
using namespace std;
// important values
// paths
string confPath = string(getenv("HOME")) + "/.config/open-any/config.txt";
//programs
string code;
string text;
string audio;
string video;
string mdown;
string pics;
string gimp;
string krita;
string defaultOp;

// error printing
void prnError(string s) {
        cerr << "\033[31m" << "\033[1m" << s;
}
