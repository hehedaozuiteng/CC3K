// cc3k.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <fstream>
#include "game.h"
#include <ncurses.h>

using namespace std;

int main(int argc, char** argv)
{
	string file_name;
	cin.exceptions(ios::eofbit | ios::failbit);
	string cmd;
	bool running = true;
	bool curse = false;
	Game mainGame;
	//find the file; 
	file_name = "map.txt";
	if (argc == 1) {
		
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				curse = true;
			}
			else { 
				file_name = argv[i]; 
			}
		}
	}
#ifdef TEST
	cout << "READ file from " << file_name << endl;
#endif


	//reading map
	ifstream file{ file_name };
	if (file.fail()) {
		cout << file_name << " cannot read" << endl;
		running = false;
	}
	else {
		// todo add reset the game		//	
			


	}





	//runing part;
	if (curse) {
		initscr();			/* Start curses mode 		  */
		noecho();/* Print Hello World		  */
		refresh();			/* Print it on to the real screen */
					/* Wait for user input */
		
		
		char mesg[] = "Enter Your race: ";		/* message to be appeared on the screen */
		char str[80];
		int row, col;
		getmaxyx(stdscr, row, col);		/* get the number of rows and columns */
		printw("%s", mesg);
		getstr(str);
		mainGame = Game(file_name, str);
		mainGame.curse = true;
		clear();
		char *array;
		string sb;
		sb = mainGame.display();
		array = &sb[0];
		printw("%s", array);
		
		int keyboard;
		while (keyboard = getch())
		{
			
			char key_c = (char)keyboard;
			if (key_c == 'q') { break; }
			else if (key_c == 'r') {
				 clear();
				mvprintw(row / 2, (col - 18) / 2, "%s", mesg);
				getstr(str);
				mainGame = Game(file_name, cmd);
				mainGame.curse = true;
				clear();
				sb = mainGame.display();
				array = &sb[0];
				printw("%s", array);
			}
			else if (key_c == 'w'|| key_c == 's'|| key_c == 'a'|| key_c == 'd')
			{
				char me[] = "Enter Your race: guess!!!";
				printw("%s", me);
				printw("%c",  key_c);
				string dir = "";
				if (key_c == 'w') dir = "no";
				else if (key_c == 's') dir = "so";
				else if (key_c == 'a') dir = "we";
				else if (key_c == 'd') dir = "ea";

				
				if (!mainGame.Move(dir)) {
					clear();
					sb = mainGame.display();
					array = &sb[0];
					printw("%s", array);
				}
				else {
					clear();
					printw("Your goal is %i\n Press r to restart!!!", mainGame.goal);
					
				}
			}

		}

		endwin();
	}
	else {
		try {
			if (running) {
				cout << "select your race: ";
				cin >> cmd; // pick the race 

				mainGame = Game(file_name, cmd);
			}
			while (running) {
				bool end = false;
				cin >> cmd;
				if ((cmd == "no") || (cmd == "so") || (cmd == "ea") || (cmd == "we") ||
					(cmd == "ne") || (cmd == "nw") || (cmd == "se") || (cmd == "sw")) {
#ifdef TEST
					cout << "move " << cmd << endl;
#endif
					//tode 

					end = mainGame.Move(cmd);


				}
				else if (cmd == "a") {
					cin >> cmd;
					if ((cmd == "no") || (cmd == "so") || (cmd == "ea") || (cmd == "we") ||
						(cmd == "ne") || (cmd == "nw") || (cmd == "se") || (cmd == "sw")) {
#ifdef TEST
						cout << "attack " << cmd << endl;
#endif
						//tode 

						end = mainGame.Attack(cmd);


					}
#ifdef TEST1
					else { cout << "cannot find direction of attack " << cmd << endl; }
#endif

			}
				else if (cmd == "u") {
					cin >> cmd;
					if ((cmd == "no") || (cmd == "so") || (cmd == "ea") || (cmd == "we") ||
						(cmd == "ne") || (cmd == "nw") || (cmd == "se") || (cmd == "sw")) {
#ifdef TEST 
						cout << "using " << cmd << endl;
#endif
						//tode 

						end = mainGame.Using(cmd);


					}
#ifdef TEST
					else { cout << "cannot find direction of using " << cmd << endl; }
#endif

				}
				else if (cmd == "q") { // quite the game
#ifdef TEST 
					cout << "quite the game" << endl;
#endif
					running = false;
				}
				else if (cmd == "r") { // reset the gane

#ifdef TEST
					cout << "restart the game" << endl;
#endif

					try {
						cout << "select your race: ";
						cin >> cmd; // pick the race 
						mainGame = Game(file_name, cmd);
					}
					catch (ios::failure &) {
						running = false;
					}

				}
				if (end) {
					cout << "wanna restart game: (Y/N)";
					cout << endl;
					cin >> cmd;
					if ((cmd == "Y") || (cmd == "yes") || (cmd == "y") || (cmd == "Yes")) {
						try {
							cout << "select your race: ";
							cin >> cmd; // pick the race 
							mainGame.restart(file_name, cmd);
						}
						catch (ios::failure &) {
							running = false;
						}

					}
					else {
						running = false;
					}
				}

		}
	}
		catch (ios::failure &) {
		}
}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
/*

*/







