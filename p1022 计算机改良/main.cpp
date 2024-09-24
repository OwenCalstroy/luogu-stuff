#include <iostream>
#include <cstdio>
#include <string>


char a;
int eq = 1;
int ope = 1;
int x = -1;
int k = 0;
int b = 0;
char un;
bool korb = false; //true->k
std::string instr;

inline void app(int x) {
    if (korb == true) {
        k += eq*ope * (x);
    }
    else {
        b += eq*ope * (x);
    };
    korb = false;
    
}


int main() {
    std::cin >> instr;
    for (int i = 0; i != instr.size(); ++i) {
        a = instr[i];

        if (a == '=') { app(x); eq = -1; ope = 1; x = -1; };
        if (a == '+') { app(x); ope = 1; x = -1; };
        if (a == '-') {

            if (i) {
                if (instr[i - 1] == '=') {
                    ope = -1;
                    x = -1;
                    continue;
                };
                app(x);
            };
            ope = -1;
            x = -1;

        };

        if (a >= '0' && a <= '9' && x == -1) { x = a - '0'; }
        else if (a >= '0' && a <= '9' && x != -1) { x = x * 10 + (a - '0'); };

        if (a >= 'a' && a <= 'z') {
            if (x == -1) {
                x += 2;
            };
            korb = true;
            un = a;
        };
    }
    app(x);

    double ans = double(-b * 1.0 / k);
    if (ans == -0.0) ans = 0;//特判，将-0.0改为0
    printf("%c=%.3lf", un, ans);//保留三位小数输出
    return 0;
}