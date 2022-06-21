/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 //r.update

  /*
   * File:   main.cpp
   * Author: MSCS
   *
   * Created on 12 March 2020, 8:38 AM
   *
   */
   //updated



#include "board.h"
#include "agent.h"
#include <iostream>
#include <fstream>

  //using std::cout;
  //using std::cin;


using namespace std;

int main(int argc, char** argv) {
	int i = 0;
	int input = 0;
	char symbol = '@';
	vector<string> statesV;//vectot to stor all states
	vector<string> movesV;//vector to store all moves
	string sChoice = "s";
	double speed = 0.4;//to store user prefered speed of play
	string newLine = "y";//to ask user whether board states shuld be printed on new line or cleared
	bool bi = false;//
	while (i != 3)
	{

		cout << "Welcome to the abalone board game." << endl;
		cout << "Please select one of the options below: " << endl;
		cout << "Press -> 1 ,to play against a bot." << endl;
		cout << "Press -> 2 ,to watch a bot play against another bot." << endl;
		cout << "Press -> 3 ,if you do not wish to play at all." << endl;
		cout << "Enter input: "; //<< endl;
		cin >> input;
		
		if (input != 3)
		{
			cout << "Clear screen after a move? [y/n]!";// << endl;
			cin >> newLine;
			if (newLine == "y" || newLine == "yes")
			{
				bi = false;
			}
			else if (newLine == "n" || newLine == "no")
			{
				bi = true;
			}
			while (input != 1 && input != 2)
			{
				cout << "Invalid input, please Enter input again. " << endl;
				cout << "Enter input: ";
				cin >> input;

			}
			if (input == 1)
			{
				cout << "You are up against a bot, are you ready?" << endl;
				cout << "Choose your character - [@/O] ? :";// << endl;
				cin >> symbol;
				userVbot(symbol, statesV, movesV, bi);
				input = 0;
			}
			else if (input == 2)
			{

				cout << "Press [s] for fast, [f] for slow and [sf] for super-fast speed of play:";
				cin >> sChoice;
				if (sChoice == "s") {
					speed = 0.8;

				}
				else if (sChoice == "f")
				{
					speed = 0.3;

				}
				else if (sChoice == "sf")
				{
					speed = 0.0;

				}
				botVbot(statesV, movesV, speed, bi);
				input = 0;
			}
			char rep = 'n';
			cout << "Would you like to watch a replay of your game?[y/n]";cin >> rep;
			if (rep == 'y' || rep == 'Y' ) {
				int a = 0, b = movesV.size();
				cout << "Enter A to watch the entire game or B to replay only a portion: ";
				cin >> rep;
				if (rep == 'B' || rep == 'b') {
					cout << "At which index would you like to stop: ";cin >> a;
					cout << "At which index would you like to start: ";cin >> b;
				}
				for (int i = a;i < b;i++) {
					cout << movesV[i] << endl;
					cout << statesV[i] << endl;
					SLP(0.2);
					system(CL);
				}
			}
		}
		else
		{

			cout << "Goodbye !!!" << endl;
			break;
		}


	}



}
