#include <iostream> 

void printRules();

int main(){
    
    int money = 1000;
    printRules();

    while((money > 0) && (money < 10'000)){
        using namespace std;
        cout << "You have $" << money << "!\n";
        
        

    }
}

void printRules(){
    using namespace std;

    cout << "           Welcome to Roulette!           \n";
    cout << "The roulette wheel has 38 slots (1-36) and \n";
    cout << "two green slots (0 and 00).  The odd numbers\n";
    cout << "are red slots and the even numbers are black.\n";
    cout << "You will have the option to bet on indiviual\n";
    cout << "numbers, colours, even and odd numbers, ranges,\n";
    cout << "and more. The payout level will be displayed \n";
    cout << "when you place your bet.  You will start with\n";
    cout << "$1000.  If you lose all your money, the game ends\n";
    cout << "and you lose.  If you reach $10,000, you win!\n";
}