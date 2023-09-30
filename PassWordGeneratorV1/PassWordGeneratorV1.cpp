#include<iostream>

#include<cstdlib>

#include<ctime>

using namespace std;
static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphnum) - 1;
char GenRand() {
    return alphnum[rand() % strLen];
}
int main() {
    int pass_len, digit_len = 0, sympl_len = 0;
    srand(time(0));

    cout << "Enter the length of the password required:";
    cin >> pass_len;
    cout << pass_len << endl;
    cout << "Your Password is: ";

    GENERATE_VALID:
     sympl_len = 0, digit_len = 0;
        char char_of_arr;
        string str;
        for (int z = 0; z < pass_len; z++) {
            char_of_arr = GenRand();
            str += char_of_arr;

            if (isdigit(char_of_arr)) {
                digit_len++;
            }
            if (char_of_arr == '!' || char_of_arr == '@' || char_of_arr == '$' ||
                char_of_arr == '%' || char_of_arr == '^' || char_of_arr == '&' ||
                char_of_arr == '*' || char_of_arr == '#') {
                sympl_len++;
            }
        }
        // cout << sympl_len << " : " << digit_len << " : " <<  str << endl;
    if (pass_len > 2 && (sympl_len  != 2 || digit_len  != 3)) {
        goto GENERATE_VALID;
    }

    cout << str;
    cout << endl << endl << "                 THANK YOU";
    return 0;
}