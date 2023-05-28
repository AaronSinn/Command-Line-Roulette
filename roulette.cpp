#include <iostream> 
#include <algorithm>
#include <cctype>
#include <string>

void printRules();

int main(){
    
    int numbers[38];    //array that will act as the spin wheel
    int number = -1;    //number that the ball would land on.  Set to 00 by deafult.
    int greenNums[2] = {-1, 0};     //-1 is 00
    int redNums[18];    //odd numbers
    int blackNums[18];  //even numbers

    //amount that the user bets on each option
    int betOnNumber = 0;     //Straight up bet on one or more numbers.  Payout: 35 to 1
    int betOnOddOrEven = 0;  //00 and 0 not included.  Payout: 1 to 1
    int betOnColour = 0;     //Red or Black.  Payout: 1 to 1
    int betOnDozen = 0;      //1-12, 13-24, 25-36.  Payout: 2 to 1
    int betOnColumn = 0;     //multiple of 3 start with 1,2,3 for the columns. Payout: 2 to 1
    int betOnHighOrLow = 0;  //1-18, 19-36.  Payout: 1 to 1

    char userInput = 'n';    //determine what the user wants to bet on

    String oddOrEven = "odd";

    int blackCount = 0;
    int redCount = 0;

    for(int i = -1; i < 37; i++){
        numbers[i+1] = i; //populates numbers with 0-37

        //adds all even numbers to black.
        if((i > 0) && (i%2 == 0)){
            blackNums[blackCount] = i;
            blackCount++;
        }

        //adds all odd numbers to red.
        if((i > 0) && (i%2 != 0)){
            redNums[redCount] = i;
            redCount++;
        }
        
    }

    int money = 1000;
    printRules();

    while((money > 0) && (money < 10'000)){     //game loop
        using namespace std;
        cout << "You have $" << money << "!\n\n";
        
        cout << "Would you like to bet on Odd or Even? [Y/N]\n";
        cin >> betOnOddOrEven;

        if(tolower(userInput) == 'y'){
            
        }


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