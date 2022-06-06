/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MSCS
 *
 * Created on 12 March 2020, 8:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include "board.h"
#include "agent.h"


using namespace std;

int humanVbot(const char& char1){
    if(char1 != '@' && char1 != 'O'){
        throw string("Parameter must be O or @ only!");
    }
    char bot;
    if(char1 == '@'){
        bot = 'O';
    }
    else{
        bot = '@';
    }
    system(CL);
    SLP(1);
    time_t now = time(NULL);
    srand(now);
    cout << "Seed: " << now << endl;
    board abalone;
    string state(abalone);
    cout << "Initial State:" << endl << state; 
    agent *w = new humanAgent(char1);
    agent *b = new distAgent(bot);
    movement *pom = nullptr; // previous opponent's move
    movement *mym = nullptr; // player's chosen move
    char c = char1;
    int i = 1;
    string winner = "No player";
    while (abalone.inPlay())
    {
        try
        {
            if (c == 'O')
            {
                movement mm = w->move(pom, abalone);
                mym = new movement(mm);
                if (pom)
                    delete pom;
                pom = new movement(mm);
            }
            else
            {
                movement mm = b->move(pom, abalone);
                mym = new movement(mm);
                if (pom)
                    delete pom;
                pom = new movement(mm);
            }
        }
        catch (const string &s)
        {
            cout << s;
            return 1;
        }
        bool valid = abalone.executeMove(c, mym->l, mym->n, mym->fd, mym->md);
        system(CL);
        if (valid)
        {
            cout << "Move " << i << ": " << c << "," << mym->l << "," << mym->n << "," << mym->fd << "," << mym->md <<" (Bot)" << endl;
            string state(abalone);
            cout << "Next State:" << endl << state;
        }
        else
        {
            cout << "Invalid move!!" << endl;
            string state(abalone);
            cout << "Next State:" << endl << state;
        }
        
        delete mym;
        abalone.refreshOffboardCounts(winner);
        if (c == 'O')
            c = '@';
        else
            c = 'O';
        i++;
    }
    if (pom)
        delete pom;
    delete w;
    delete b;
    system(CL);
    string final_state(abalone);
    cout << "Final State: " << endl << final_state ;
    cout << "The total number of moves made is: " << i-1 << endl;
    cout << winner << " wins this round of the game!" << endl;
    return 0;
}
int botVbot(){
    system(CL);
    SLP(1);
    time_t now = time(NULL);
    srand(now);
    cout << "Seed: " << now << endl;
    board abalone;
    string state(abalone);
    cout << "Initial State:" << endl << state; 
    SLP(10);
    system(CL);
    SLP(1);
    agent *w = new randAgent('O');
    agent *b = new distAgent('@');
    movement *pom = nullptr; // previous opponent's move
    movement *mym = nullptr; // player's chosen move
    char c = 'O';
    int i = 1;
    string winner = "No player";
    while (abalone.inPlay())
    {
        try
        {
            if (c == 'O')
            {
                movement mm = w->move(pom, abalone);
                mym = new movement(mm);
                if (pom)
                    delete pom;
                pom = new movement(mm);
            }
            else
            {
                movement mm = b->move(pom, abalone);
                mym = new movement(mm);
                if (pom)
                    delete pom;
                pom = new movement(mm);
            }
        }
        catch (const string &s)
        {
            cout << s;
            return 1;
        }
        bool valid = abalone.executeMove(c, mym->l, mym->n, mym->fd, mym->md);
        string player;
        if(i%2 == 0){
            player = "Bot 2";
        }
        else{
            player = "Bot 1";
        }
        cout << "Move " << i++ << ": " << c << "," << mym->l << "," << mym->n << "," << mym->fd << "," << mym->md <<"("<<player<<")"<< endl;
        if (valid)
        {
            string state(abalone);
            cout << "Next State:" << endl << state;
            SLP(0.4);
            system(CL);
            SLP(0.4);
        }
        else
        {
            cout << "Invalid move!!" << endl;
            SLP(0.1);
            system(CL);
            SLP(0.1);
        }
        if (c == 'O')
            c = '@';
        else
            c = 'O';
        delete mym;
        abalone.refreshOffboardCounts(winner);
        //SLP(1);
        //system(CL);
    }
    if (pom)
        delete pom;
    delete w;
    delete b;
    //cout << "Seed: " << now << endl;
    //cout << "Initial State: " << endl << initialState;
    string final_state(abalone);
    cout << "Final State: " << endl << final_state ;
    cout << "The total number of moves made is: " << i-1 << endl;
    cout << winner << " wins this round of the game!" << endl;
    return 0;
}

int main(int argc, char** argv) {
    int hbgame = humanVbot('O');
    
   // int bbgame = botVbot();
    
}