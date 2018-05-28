#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <stdio.h>
#include <string>


using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

float money = 2000.0f;
float uinput, bet;
int s1, s2, s3, rolls, temp;
string spacing;

int title() {
	cout << "   dP''Yb  88b 88 888888     88''Yb 88 888888     88''Yb    db    88b 88 8888b.  88 888888 " << endl;
	cout << "   dP   Yb 88Yb88 88__       88__dP 88   88       88__dP   dPYb   88Yb88  8I  Yb 88   88   " << endl;
	cout << "   Yb   dP 88 Y88 88''       88''Yb 88   88       88''Yb  dP__Yb  88 Y88  8I  dY 88   88   " << endl;
	cout << "    YbodP  88  Y8 888888     88oodP 88   88       88oodP dP''''Yb 88  Y8 8888Y'  88   88    " << endl << endl;
                                                                

	return 0;
}

int mainmenu(int a) {
	cout << "Player's Chips: " << money << endl << endl;
	cout << "1) Play Slots" << endl;
	cout << "2) Quit Slot Machine" << endl;
	cout << "3) Credits" << endl;
	cin >> a;
	return a;
}

int slots(int a) {
	system("cls");
	spacing = "                 ";
	if (money >= 1) {
		do {
			system("Color 0A");
			cout << "Enter Amount you want to bet: $";
			cin >> uinput;
			system("Color 07");
			if ((uinput > 0) && (money >= uinput)){
				bet = uinput;
				break;
			}
			else {
				cout << "Invalid amount make sure to only bet what you can, current balance is: $" << money << endl;
			}
		} while (1 == 1);
		rolls = rand() % 10 + 20;
		for (int i = 0; i < rolls; i++) { //Rolling
			Beep((rand() % 1000 + 1500), 50);
			s1 = rand() % 7 + 2;
			s2 = rand() % 7 + 2;
			s3 = rand() % 7 + 2;
			system("cls");
			cout << spacing <<"________________________" << endl;
			cout << "                 |-=$ ONE-BIT BANDIT $=-| ()" << endl;
			cout << "                 |______________________| ||" << endl;
			cout << "                 |                      | ||" << endl;
			cout << "                 |    [" << s1 << "]  [" << s2 << "]  [" << s3 << "]     |==)" << endl;
			cout << "                 |                      |" << endl;
			cout << "                 |_______|_____|________|" << endl;
		}
		system("cls");
		s1 = rand() % 7 + 2;
		s2 = rand() % 7 + 2;
		s3 = rand() % 7 + 2;
		cout << "                 ________________________" << endl;
		cout << "                 |-=$ ONE-BIT BANDIT $=-| ()" << endl;
		cout << "                 |______________________| ||" << endl;
		cout << "                 |                      | ||" << endl;
		cout << "                 |    [" << s1 << "]  [" << s2 << "]  [" << s3 << "]     |==)" << endl;
		cout << "                 |                      |" << endl;
		cout << "                 |_______|_____|________|" << endl;
		
		//Check if won

		if ((s1 == 7) && (s2 == 7) && (s3 == 7)) {
			for (int i = 0; i < 5; i++) {
				Beep(3000, 150);
				system("Color 0A");
				Beep(4000, 150);
			}
			bet = bet * 10;
			cout << "You Won: $" << bet << "!" << endl;
			money += bet;
		}
		else if ((s1 == s2) && (s2 == s3)) {
			for (int i = 0; i < 3; i++) {
				Beep(3000, 150);
				system("Color 0A");
				Beep(4000, 150);
			}
			bet = bet * 5;
			cout << "You Won: $" << bet << "!" << endl;
			money += bet;
		}
		else if ((s1 == s2) || (s2 == s3) || (s1 == s3)) {
			for (int i = 0; i < 1; i++) {
				Beep(3000, 50);
				system("Color 0A");
				Beep(4000, 50);
			}
			bet = bet * 3;
			cout << "You Won: $"<< bet <<"!" << endl;
			money += bet;
		}
		else {
			for (int i = 0; i < 1; i++) {
				Beep(500, 150);
				system("Color 0C");
				Beep(300, 150);
			}
			
			cout << "You Lose!" << endl;
			money -= bet;
		}
		cout << "Player's Chips: " << money << endl << endl;
		cout << endl << "Press Enter To Continue..." << endl;
		system("Color 07");
		
	}
	else {
		system("Color 7C");
		cout << "Your Broke, Go Home!" << endl;
		cout << "Player's Chips: " << money << endl << endl;
		cout << endl << "Press Enter To Continue..." << endl;
	}
	cin >> a;
	a = 0;
	system("Color 07");
	return a;
}

int main() {

	HWND console = GetConsoleWindow();
	RECT w;
	GetWindowRect(console, &w);
	

	do {
		//plant a seed
		//srand(time(NULL));
		MoveWindow(console, w.left, w.top, 800, 300, TRUE); //Resize console window
		srand((unsigned int)time(NULL));
		system("cls");
		system("Color 0E");
		title();
		temp = mainmenu(temp);
		if (temp == 1) {
			MoveWindow(console, w.left, w.top, 500, 300, TRUE);
			temp = slots(temp);
		}
		else if (temp == 2) {
			break;
		}
		else if (temp == 3) {
			system("Color 7C");

			system("cls");
			title();
			Beep((rand() % 500 + 2500), 150);
			spacing = "                 ";
			cout << "-= Credits =-";
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "Casino Machine - Henry Oliver" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "ASCII Art - Henry Oliver" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "this code isn't as effecient as it could be - Henry Oliver" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "Making my lunch - Henry Oliver" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "Special Thanks to Henry Oliver for something" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			system("cls");
			title();
			cout << "Thanks for playing - Henry Oliver" << endl;
			Beep((rand() % 500 + 2500), 150);
			sleep_for(seconds(3));
			Beep((rand() % 500 + 2500), 150);
			system("Color 07");
		}
		else {
			cout << "Invalid Input, try again";
			sleep_for(seconds(3));
		}
		cout << endl;
	} while (1 == 1);

	return 0;
}