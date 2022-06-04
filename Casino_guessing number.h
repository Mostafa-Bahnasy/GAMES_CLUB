
void rules();
void casino_title();
void transfer_money(accounti& user, int money);

void to_run_casino()
{
    accounti user;
    user = arr_acc[ind];
    string name;
    int amnt=0;
    int bidamnt=0;
    int guess=0;
    int dice=0;
    char choice;

    srand(time(0)); // لتحديد رقم عشوائي كل مرة
    system("cls"); // to clear console
    casino_title();
    cout << "\nEnter Player Name: ";

    cin >> name;

    //by hisham walid
    do
    {
        amnt = user.money;
        casino_title();
        system("cls");
        rules();
        do
        {
            cout << "\nWelcome " << name << " Are You Ready To Play? " << "\n\n"; Sleep(200);
            cout << "Enter Bid Amount: ";
            string bidamntStr;
            cin >> bidamntStr;
            bool valid = 1;
            for (auto strInd : bidamntStr) {
                if (!isdigit(strInd))valid = 0;
            }
            if (!valid) {
                cout << "\nEnter valid value\n";
                bidamnt = -10;
            }
            else
            bidamnt = stoi(bidamntStr);
            if (bidamnt > amnt)
                cout << "You Can not Bid More Than Current Amount\n"
                << "\nRe-enter Amount: ";
        } while (bidamnt > amnt || bidamnt<=0);

        do
        {
            cout << "Guess The Number Between 1 To 10 :";
            string guessStr;
            cin >> guessStr;
            bool valid = 1;
            for (auto strInd : guessStr) {
                if (!isdigit(strInd))valid = 0;

            }
            if (!valid)
                guess = -1;
            else
            guess = stoi(guessStr);
            if (guess <= 0 || guess > 10||!valid)
                cout << "\nNumber Sholud Be Between 1 To 10\n"
                << "\nGuess Numer Again: ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\nHurray You Won " << bidamnt * 10 << " coin";
            amnt = amnt + bidamnt * 10;
        }
        else
        {
            cout << "Sorry You Lose " << bidamnt << " coin\n";
            amnt = amnt - bidamnt;
        }

        cout << "\nThe Winning Number Was: " << dice << "\n";
        cout << "\n" << name << ", Your Remaining Amount Is " << amnt << " coin\n";
        user.money = amnt;// update user money
        
        if (amnt == 0)
        {
            cout << "\nSorry You Don't Have Money To Play \n";
            break;
        }
        cout << "\nYou Want To Play Again Press (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    transfer_money(user, user.money); // money transfer

    cout << "\n===============================================================================================\n";
    cout << "\t Thanks For Playing Game Again Your Current Amount Is " << amnt << " coin";
    cout << "\n===============================================================================================\n";
    Sleep(2000);

    system("cls");

    window = 1;
}
//by hisham walid
void rules()
{
    system("cls");
    cout << "\n===============================================================================================\n";
    cout << "\t\t\t\t   Game Rules";
    cout << "\n===============================================================================================";
    cout << "\n1. Choose Number Between 1 To 10";
    cout << "\n2. Winning Amount Will Be 10 Times Of Bid Amount";
    cout << "\n3. Loose Amount Will Be Biding Amount";
    cout << "\n4. You Can Leave A Game Any Time";
    cout << "\n===============================================================================================\n";
}
void casino_title() {
    cout << "\n===============================================================================================";
    cout << "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
    cout << "\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
    cout << "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
    cout << "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
    cout << "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
    cout << "\n===============================================================================================\n";

}
void transfer_money(accounti &user,int money) {
    int sizei = arr_acc.size();

    for (int i = 0; i < sizei; i++) {
        if (user.id == arr_acc[i].id) {
            arr_acc[i].money = money; return;
        }
    }
}