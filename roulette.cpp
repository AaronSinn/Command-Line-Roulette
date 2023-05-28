#include <iostream> 
#include <algorithm>
#include <cctype>
#include <unordered_map> 
#include <random>   
#include <vector>  


void printRules();
void printArray(int array[], int size);

int main(){
    std::unordered_map<int, int> numberBetsMap;
    std::vector<int> numbers = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 ,19 ,20, 21, 22, 23, 24, 25, 26, 27 ,28 ,29 ,30 ,31, 32, 33, 34, 35, 36};
    int number = -1;                //number that the ball would land on.  Set to 00 by deafult.
    int greenNums[2] = {-1, 0};     //-1 is 00
    int redNums[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    int blackNums[] = {2, 4, 6, 8, 10, 11, 13, 15, 17 ,20 ,22, 24, 26, 28, 29, 31, 33, 35};
    int columnOne[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};              
    int columnTwo[] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};              
    int columnThree[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};

    int sizeOfColumns = sizeof(columnOne)/sizeof(columnOne[0]);

    char userInput = 'n';           //determine what the user wants to bet on
    bool valid_input = false;       

    int numberPicked = 0;              //If the user wants to bet on a number, this will determine which one.
    char keepBettingOnNumbers = 'n';   //Determines if the user wants to bet on more numbers.

    int money = 1000;
    printRules();

    while((money > 0) && (money < 10'000)){     //game loop
        using namespace std;

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
        int winnings = 0;               //amount the user won or lost from each spin

        // Shuffle the array.  Acts as spinning the wheel
        std::random_device random_dev;
        std::mt19937       generator(random_dev());
        std::shuffle(numbers.begin(), numbers.end(), generator);

        number = numbers[0];
        //cout << "\nnumber is " << number << ". (for testing)\n\n";

        cout << "You have $" << money << "!\n\n";               //game starts here
        cout << "Would you like to bet on a number? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' && tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on a number? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){
            
            do{
                
                valid_input = false;
                do{
                    cout << "Which number do you want to bet on? Enter -1 for double zeros.\n";
                    cin >> numberPicked;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);

                while((numberPicked < -1) || (numberPicked > 36)){      //ensures the user enters a valid number
                        cout << "Invalid number! Which numebr do you want to bet on? Enter -1 for double zeros.\n";
                        cin >> numberPicked;
                }

                valid_input = false;
                do{
                    cout << "How much do you want to bet on " << numberPicked << "?\n";
                    cin >> betOnNumber;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);

                while(betOnNumber > money){
                    cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                    cout << "How much do you want to bet on " << numberPicked << "?\n";
                    cin >> betOnNumber;
                }

                money -= betOnNumber;

                numberBetsMap[numberPicked] = betOnNumber;  //adds the number the user bet on and the amount to the hash map

                cout << "Do you want to pick another number to bet on? [Y/N]\n";
                cin >> keepBettingOnNumbers;
            } while (tolower(keepBettingOnNumbers) == 'y');
        }

        cout << "Would you like to bet on Odd or Even? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' && tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on Odd or Even? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){

            valid_input = false;
            do{
                cout << "How much do you want to bet on odd?\n";
                cin >> betOnOdd;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnOdd > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on odd?\n";
                cin >> betOnOdd;
            }
            money -= betOnOdd;
            
            valid_input = false;
            do{
                cout << "How much do you want to bet on even?\n";
                cin >> betOnEven;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnEven > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on even?\n";
                cin >> betOnEven;
            }
            money -= betOnEven;
        }
        

        cout << "Would you like to bet on Red or Black? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' && tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on Red or Black? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){

            valid_input = false;
            do{
                cout << "How much do you want to bet on Red?\n";
                cin >> betOnRed;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnRed > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much do you want to bet on Red?\n";
                    cin >> betOnRed;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnRed;

            valid_input = false;
            do{
                cout << "How much do you want to bet on Black?\n";
                cin >> betOnBlack;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnBlack > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on Black?\n";
                cin >> betOnBlack;

                valid_input = false;
                do{
                    cout << "How much do you want to bet on Black?\n";
                    cin >> betOnBlack;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnBlack;
        }

        cout << "Would you like to bet on a Dozen? [Y/N]\n";
        cin >> userInput;

        if(tolower(userInput) == 'y'){

            valid_input = false;
            do{
                cout << "How much would you like to bet on 1-12?\n";
                cin >> betOnFirstDozen;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnFirstDozen > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much would you like to bet on 1-12?\n";
                    cin >> betOnFirstDozen;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnFirstDozen;

            valid_input = false;
            do{
                cout << "How much would you like to bet on 13-24?\n";
                cin >> betOnSecondDozen;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnSecondDozen > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much would you like to bet on 13-24?\n";
                    cin >> betOnSecondDozen;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnSecondDozen;

            valid_input = false;
            do{
                cout << "How much would you like to bet on 25-36?\n";
                cin >> betOnThirdDozen;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnThirdDozen > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much would you like to bet on 25-36?\n";
                    cin >> betOnThirdDozen;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnThirdDozen;
        }

        cout << "Would you like to bet on a Column?  [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' && tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on a Column?  [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){

            valid_input = false;
            do{
                cout << "How much do you want to bet on column one ("; printArray(columnOne, sizeOfColumns); cout << ")?\n";
                cin >> betOnFirstColumn;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnFirstColumn > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much do you want to bet on column one ("; printArray(columnOne, sizeOfColumns); cout << ")?\n";
                    cin >> betOnFirstColumn;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnFirstColumn;

            valid_input = false;
            do{
                cout << "How much do you want to bet on column Two ("; printArray(columnTwo, sizeOfColumns); cout << ")?\n";
                cin >> betOnSecondColumn;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnSecondColumn > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";

                valid_input = false;
                do{
                    cout << "How much do you want to bet on column Two ("; printArray(columnTwo, sizeOfColumns); cout << ")?\n";
                    cin >> betOnSecondColumn;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnSecondColumn;

            valid_input = false;
            do{
                cout << "How much do you want to bet on column Three ("; printArray(columnThree, sizeOfColumns); cout << ")?\n";
                cin >> betOnThirdColumn;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnThirdColumn > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on column Three ("; printArray(columnThree, sizeOfColumns); cout << ")?\n";
                cin >> betOnThirdColumn;

                valid_input = false;
                do{
                    cout << "How much do you want to bet on column Three ("; printArray(columnThree, sizeOfColumns); cout << ")?\n";
                    cin >> betOnThirdColumn;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnThirdColumn;
        }

        cout << "Would you like to bet on high or low? [Y/N]\n";
        cin >> userInput;

        while(tolower(userInput) != 'y' && tolower(userInput) != 'n'){
            cout << "You made a typo! Would you like to bet on high or low? [Y/N]\n";
            cin >> userInput;
        }

        if(tolower(userInput) == 'y'){

            valid_input = false;
            do{
                cout << "How much do you want to bet on low (1-18)?\n";
                cin >> betOnLow;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnLow > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on low (1-18)?\n";
                cin >> betOnLow;

                valid_input = false;
                do{
                    cout << "How much do you want to bet on low (1-18)?\n";
                    cin >> betOnLow;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);
            }
            money -= betOnLow;

            valid_input = false;
            do{
                cout << "How much do you want to bet on high (19-36)?\n";
                cin >> betOnHigh;

                if (!(valid_input = cin.good())) {
                    cout << "That input is invalid!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }while(!valid_input);

            while(betOnHigh > money){
                cout<<"You dont have enough money for that bet. You have $" << money << ".\n";
                cout << "How much do you want to bet on high (19-36)?\n";
                cin >> betOnHigh;
                
                 valid_input = false;
                do{
                    cout << "How much do you want to bet on high (19-36)?\n";
                    cin >> betOnHigh;

                    if (!(valid_input = cin.good())) {
                        cout << "That input is invalid!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while(!valid_input);

            }
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

    if(money > 10'000){
        std::cout <<"Congrats!! You win with $" << money << "! :)";
    }
    else{
        std::cout <<"You lose :( Maybe try slots or something :)";
    }

    return 0;
}

void printRules(){
    using namespace std;

    cout << "                                          Welcome to Roulette!                    \n";
    cout << "The roulette wheel has 38 slots (1-36) and ";
    cout << "two green slots (0 and 00).  The odd numbers\n";
    cout << "are red slots and the even numbers are black.";
    cout << "You will have the option to bet on indiviual\n";
    cout << "numbers, colours, even and odd numbers, ranges,";
    cout << "and more. The payout level will be displayed \n";
    cout << "when you place your bet.  You will start with";
    cout << "$1000.  If you lose all your money, the game ends\n";
    cout << "and you lose.  If you reach $10,000, you win!\n";
}

void printArray(int array[], int size){
    using namespace std;

    for(int i = 0; i < size; i++){

        if(i == size-1){        //Won't print a comma for the last element
            cout << array[i];
            break;
        }
        cout << array[i] << ", ";
    }
}
