#include <iostream> 
#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <random>

void printRules();
void printArray(int array[]);

int main(){
    std::unordered_map<int, int> numberBetsMap;
    int numbers[38];                //array that will act as the spin wheel
    int number = -1;                //number that the ball would land on.  Set to 00 by deafult.
    int greenNums[2] = {-1, 0};     //-1 is 00
    int redNums[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    int blackNums[] = {2, 4, 6, 8, 10, 11, 13, 15, 17 ,20 ,22, 24, 26, 28, 29, 31, 33, 35};
    int columnOne[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};              
    int columnTwo[] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};              
    int columnThree[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};

    //amount that the user bets on each option
    int betOnNumber = 0;            //Straight up bet on one or more numbers.  Payout: 35 to 1
    int betOnEven = 0;              //00 and 0 not included.  Payout: 1 to 1
    int betOnOdd = 0;               //00 and 0 not included.  Payout: 1 to 1
    int betOnBlack = 0;             //Bet on Black.  Payout: 1 to 1
    int betOnRed = 0;               //Bet on Black.  Payout: 1 to 1
    int betOnFirstDozen = 0;        //1-12.   Payout: 2 to 
    int betOnSecondDozen = 0;       //13-24.  Payout: 2 to 1
    int betOnThirdDozen = 0;        //25-36.  Payout: 2 to 1
    int betOnFirstColumn = 0;       //Column starting with 1. Payout: 2 to 1
    int betOnSecondColumn = 0;      //Column starting with 2. Payout: 2 to 1
    int betOnThirdColumn = 0;       //Column starting with 3. Payout: 2 to 1
    int betOnLow = 0;               //1-18.  Payout: 1 to 1
    int betOnHigh = 0;              //19-36. Payout: 1 to 1

    char userInput = 'n';    //determine what the user wants to bet on

    int numberPicked = 0;              //If the user wants to bet on a number, this will determine which one.
    char keepBettingOnNumbers = 'n';   //Determines if the user wants to bet on more numbers.

    int money = 1000;
    printRules();

    while((money > 0) && (money < 10'000)){     //game loop
        using namespace std;
        int winnings = 0;                  //amount the user won or lost from each spin

        // Shuffle the array.  Acts as spinning the wheel
        int size = sizeof(numbers) / sizeof(numbers[0]);
        random_device rd;
        mt19937 rng(rd());
        shuffle(numbers, numbers + size, rng);

        number = numbers[0];    //number the ball lands on


        cout << "You have $" << money << "!\n\n";               //game starts here
        cout << "Would you like to bet on a number? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' || tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on a number? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){
            
            do{
                cout << "Which numebr do you want to bet on? Enter -1 for double zeros.\n";
                cin >> numberPicked;

                while((numberPicked < -1) || (numberPicked > 36)){      //ensures the user enters a valid number
                    cout << "Invalid number! Which numebr do you want to bet on? Enter -1 for double zeros.\n";
                    cin >> numberPicked;
                }

                cout << "How much do you want to bet on " << numberPicked << "?\n";
                cin >> betOnNumber;
                money -= betOnNumber;

                numberBetsMap[numberPicked] = betOnNumber;  //adds the number the user bet on and the amount to the hash map

                cout << "Do you want to pick another number to bet on? [Y/N]\n";
                cin >> keepBettingOnNumbers;
            } while (tolower(keepBettingOnNumbers) == 'y');
        }

        cout << "Would you like to bet on Odd or Even? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' || tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on Odd or Even? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){

            cout << "How much do you want to bet on odd?\n";
            cin >> betOnOdd;
            money -= betOnOdd;

            cout << "How much do you want to bet on even?\n";
            cin >> betOnEven;
            money -= betOnEven;
        }
        

        cout << "Would you like to bet on Red or Black? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' || tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on Red or Black? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){
            cout << "How much do you want to bet on Red?\n";
            cin >> betOnRed;

            cout << "How much do you want to bet on Black?\n";
            cin >> betOnBlack;
        }

        cout << "Would you like to bet on a Dozen? [Y/N]\n";
        cin >> userInput;

        if(tolower(userInput) == 'y'){
            cout << "How much would you like to bet on 1-12?";
            cin >> betOnFirstDozen;
            money -= betOnFirstDozen;

            cout << "How much would you like to bet on 13-24?";
            cin >> betOnSecondDozen;
            money -= betOnSecondDozen;

            cout << "How much would you like to bet on 25-36?";
            cin >> betOnThirdDozen;
            money -= betOnThirdDozen;
        }

        cout << "Would you like to bet on a Column?  [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' || tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on a Column?  [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){
            cout << "How much do you want to bet on column one ("; printArray(columnOne); cout << ")?\n";
            cin >> betOnFirstColumn;
            money -= betOnFirstColumn;

            cout << "How much do you want to bet on column Two ("; printArray(columnTwo); cout << ")?\n";
            cin >> betOnSecondColumn;
            money -= betOnSecondColumn;

            cout << "How much do you want to bet on column Three ("; printArray(columnThree); cout << ")?\n";
            cin >> betOnThirdColumn;
            money -= betOnThirdColumn;
        }

        cout << "Would you like to bet on high or low? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' || tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on high or low? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){
            cout << "How much do you want to bet on low (1-18)?\n";
            cin >> betOnLow;
            money -= betOnLow;

            cout << "How much do you want to bet on high (19-36)?\n";
            cin >> betOnHigh;
            money -= betOnHigh;
        }

        //bets are over.  Winnings are now calculated.

        for (const auto& map : numberBetsMap) {
            if(map.first == number){
                winnings += map.second*35;
            }
        }

        for(int i = 0; i<sizeof(redNums)/sizeof(redNums[0]); i++){  //if the number is red
            if(redNums[i] == number){
                winnings += betOnRed*2;
            }
        }

        for(int i = 0; i<sizeof(blackNums)/sizeof(blackNums[0]); i++){  //if the number is black
            if(blackNums[i] == number){
                winnings += betOnBlack*2;
            }
        }

        if(number >= 1 && number%2 == 0){ //if the number is even
            winnings += betOnEven*3;
        }

        if(number >= 1 && number%2 != 0){ //if the number is odd
            winnings += betOnOdd*3;
        }

        for(int i = 0; i<sizeof(columnOne)/sizeof(columnOne[0]); i++){  //if the number is in col 1
            if(columnOne[i] == number){
                winnings += betOnFirstColumn*3;
            }
        }

        for(int i = 0; i<sizeof(columnTwo)/sizeof(columnTwo[0]); i++){  //if the number is in col 2
            if(columnTwo[i] == number){
                winnings += betOnSecondColumn*3;
            }
        }

        for(int i = 0; i<sizeof(columnThree)/sizeof(columnThree[0]); i++){  //if the number is col 3
            if(columnThree[i] == number){
                winnings += betOnThirdColumn*3;
            }
        }

        if(number >= 1 && number <= 12){ // number is 1-12
            winnings += betOnFirstColumn*3;
        }

        if(number >= 13 && number <= 24){ // number is 13-24
            winnings += betOnSecondColumn*3;
        }

        if(number >= 25 && number <= 36){ // number is 25-36
            winnings += betOnThirdColumn*3;
        }

        if(number >= 1 && number <= 18){ // number is 1-18
            winnings += betOnLow*2;
        }

        if(number >= 19 && number <= 36){ // number is 18-26
            winnings += betOnHigh*2;
        }

        money += winnings;
        
        if(winnings >= 0){
            cout <<"You won $" << winnings << "!\n";
        }

        if(winnings < 0){
            cout <<"You lost $" << winnings << ".\n";
        }

    } //end of game loop
    return 0;
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

void printArray(int array[]){
    using namespace std;

    int size = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i < size; i++){

        if(i == size-1){        //Won't print a comma for the last element
            cout << array[i];
            break;
        }
        cout << array[i] << ", ";
    }
}