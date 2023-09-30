#include <bits\stdc++.h>
#include <string>
using namespace std;



int main(){

char alphnum[]="0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; 
const string str = "12345456356345636534636435436534563456";
cout << sizeof(str) << endl;
cout << "\nsz " << str.size() << " " << str.length() << " " << endl;
cout << alphnum << endl;
int sz = sizeof(alphnum);
for(int i = 0; i < 10; i++){
    cout << alphnum[rand() & (sizeof(alphnum) - 1)];
}

return 0;
}
