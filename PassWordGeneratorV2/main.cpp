#include<iostream>
#include<cstdlib>
#include<ctime>
#include <vector>
using namespace std;

// static const char alphnum[] =  ;

class RandomChar{
private:
      string lower_char = "abcdefghijklmnopqrstuvwxyz";
      string upper_char = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      string sympols =  "!@#$%^&*" ;
      string numbers = "0123456789";
public:
    RandomChar(){   }

    // return random lower character of lower_char
    char genRandLower(){
        return lower_char[rand() % (lower_char.size() - 1)];
    }
    // return random upper character of upper_char
    char genRandUpper(){
        return upper_char[rand() % (upper_char.size()- 1)];
    }

    // return random sympol
    char genRandSympol(){
        return sympols[rand() % (sympols.size() - 1)];
    }

    // return random number 0 - 9
    char genRandNum(){
        return numbers[rand() % (numbers.size()- 1)];
    }
    // return amount of random lower characters
    vector<char> amountOfLowerChar(int amount){
        vector<char> lower_result;
        for(int i = 0; i < amount; i++){
            lower_result.push_back(genRandLower());
        }
        return lower_result;
    }

    // return amount of random upper characters
    vector<char> amountOfUpperChar(int amount){
        vector<char> upper_result;
        for(int i = 0; i < amount; i++){
            upper_result.push_back(genRandUpper());
        }
        return upper_result;
    }

    // return amount of random sympols
    vector<char> amountOfSympls(int amount){
        vector<char> sympol_result;
        for(int i = 0; i < amount; i++){
            sympol_result.push_back(genRandSympol());
        }
        return sympol_result;
    }

    // return amount of random numbers
    vector<char> amountOfNumbers(int amount){
        vector<char> number_result;
        for(int i = 0; i < amount; i++){
            number_result.push_back(genRandNum());
        }
        return number_result;
    }




};

class GeneratedPassword{
    RandomChar password_elements;
    int lower_len, upper_len, digit_len = 0, sympl_len = 0;
    vector<char> lowers, uppers, sympols, digits;
    string final_result;
public:
    GeneratedPassword(){
        cout << "Enter how many lower characters, if no enter 0 : ";
        cin >> lower_len;
        cout << "Enter how many upper character, if no enter 0 : ";
        cin >> upper_len;
        cout << "Enter how many sympols, if no enter 0 : ";
        cin >> sympl_len;
        cout << "Enter how many digits, if no enter 0 : ";
        cin >> digit_len;

        lowers = password_elements.amountOfLowerChar(lower_len);
        uppers = password_elements.amountOfUpperChar(upper_len);
        sympols = password_elements.amountOfSympls(sympl_len);
        digits = password_elements.amountOfNumbers(digit_len);
    }
    void print(vector<char> target){
        for(auto x : target)
            cout << x;
        cout << endl;
    }
    // void check(){
    //     print(lowers);
    //     print(uppers);
    //     print(sympols);
    //     print(digits);
    // }
    char getRandomElement(vector<char> &target){
        if(target.size() == 1){
            char element = target[0];
            target.pop_back();
            return element;
        }
        int idx = rand() % (target.size() - 1);
        char element = target[idx];
        swap(target[idx], target.back());
        target.pop_back();
        return element;
    }
    string buildThePassword(){
        while(!lowers.empty() || !uppers.empty() || !sympols.empty() || !digits.empty()){
            int random_vector = rand() % 5;

            // work on lowers
            if(random_vector == 1){
                if(!lowers.empty()){
                    // choose random element
                    final_result += getRandomElement(lowers);
                }
            }
            // work on uppers
            else if(random_vector == 2){
                if(!uppers.empty()){
                    // choose random element and remove it
                    final_result += getRandomElement(uppers);
                }
            }
            // work on sympls
            else if(random_vector == 3){
                if(!sympols.empty()){
                    // choose random element and remove it
                    final_result += getRandomElement(sympols);
                }
            }
            // work on digits
            else if(random_vector == 4){
                if(!digits.empty()){
                    // choose random element and remove it
                    final_result += getRandomElement(digits);
                }
            }
        }
        return final_result;
    }
    string getLastResult(){

       return buildThePassword();
    }
    

};


int main() {
   bool again;
    srand(time(0));

    
AGAIN:
    GeneratedPassword last_result;
    // last_result.check();

    cout << "\n\nYou Password is: " <<  last_result.getLastResult() << endl;
    cout << "\nNeed another password? \nEnter 1 for yes, 0 for no : ";
    cin >> again;
    
    if(again)
        goto AGAIN;

    system("pause");
    return 0;
}