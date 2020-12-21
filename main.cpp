#include <iostream>
#include <fstream>>
#include<stdlib.h>

#include "games.h"

using namespace std;

struct User {
    char userName[50];
    string password;
    string passwordConfirm;
};

struct UserStats {
    int gamesPlayed;
    int gamesWon;
    int gamesLoss;
};

void loginOrRegister();

bool loginScreen(){
    string username, password;
    cout<<"LOGIN"<<endl;
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;
    cout<<endl;
    cout<<"--------------------------"<<endl;


    User userFromFile;

    fstream f;
    f.open("users.dat", ios::in | ios::binary);
    if(f.is_open()){
        f.read(reinterpret_cast<char*>(&userFromFile), sizeof(User));
        f.close();
    };
    if (userFromFile.userName == username && userFromFile.password == password) {
        cout<<"LOGGED IN AS: "<<username<<endl;
        return true;
    }else{
        cout<<"INCORRECT CREDENTIALS"<<endl;
        return false;
   }

}


void registerScreen(){
    User user;
    cout<<"REGISTRATION"<<endl;
    cout<<"Enter your username: ";
    cin>>user.userName;
    cout<<endl;
    do {
        cout<<"Enter your password: ";
        cin>>user.password;
        cout<<"Enter your password again: ";
        cin>>user.passwordConfirm;

        if (user.passwordConfirm != user.password){
            cout<<endl;
            cout<<"Passwords do not match"<<endl;
        }

    }while(user.passwordConfirm != user.password);

    cout<<"--------------------------"<<endl;

    fstream f;
    f.open("users.dat", ios::out | ios::binary);

    if(f.is_open()) {
       f.write(reinterpret_cast<char*>(&user), sizeof(User));
       f.close();
   };
}

void loginOrRegister(){
    int loginOption;
    bool logedin;
    do {
        cin >> loginOption;
        if (loginOption < 1 || loginOption > 2){
            cout<<"Invalid Input, Enter Again: "<<endl;
        }
    }while(loginOption < 1 || loginOption > 2);

    switch(loginOption) {
    case 1:
        logedin = loginScreen();
        while(logedin == false){
            logedin = loginScreen();
        }
        break;
    default:
        registerScreen();
        logedin = loginScreen();
        while(logedin == false){
            logedin = loginScreen();
        }
        break;
    }
}

int main()
{
    // LOGIN AND REGISTRATION
    registrationMenu();
    loginOrRegister();

    cout << endl;

    // GAME MENU
    int menuOption;
    bool run = true;

    while(run) {
        system("CLS");
        gameMenu();
        do {
            cin >> menuOption;
            if (menuOption < 1 || menuOption > 5){
                cout << "Invalid input, Enter again: "<<endl;
            };
        }while(menuOption < 1 || menuOption > 5);

        switch(menuOption){
        case 1:
            system("CLS");
            tictactoe();
            break;
        case 2:
            system("CLS");
            guessTheCountry();
            break;
        case 3:
            system("CLS");
            snakeAndLadder();
            break;
        case 4:
            system("CLS");
            cout<<"User stats"<<endl;
            cin.get();
            break;
        default:
            run = false;
            break;
        }
    }


    return 0;
}
