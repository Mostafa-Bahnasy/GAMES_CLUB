#pragma once


/////////////////////////////this is just console simulator for sudoko solver

//-----------------------------------------------------------------------------------------------
using namespace std;
///////////////////////////////////////////////global declarations
int repeat[9] = { 101,102,103,104,105,106,107,108,109 };
int board_s[9][9] = {}; // initially empty board_s
bool to_break = 0;
//////////////////////////////////////////////
struct point {
	int x = 0, y = 0;
};
int siz = 1;
vector<point>arri;
//--------------------------------------------functions declarations
void pline(int n);
bool is_right_num(int val);
void print_board(bool end);
void get_board();
bool is_empty_board();
bool is_empty_board(int b[9][9]);
void clear_repeated();
bool is_exist(int value);
bool check_col(int b[9][9]);
bool check_row(int b[9][9]);
bool check_rectangles(int b[9][9]);
void copy_board(int ori[9][9], int cop[9][9]);
bool is_right_board(int b[9][9]);
void solver(int boardi[9][9]);

bool  solving(int b[9][9], int ind);
bool solve_again();
void show_title();
bool program();
//---------------------------------------------------------------------
///////////////////////////////////////////////

void  to_run_sudoku_solver() {


	while (program());
	system("cls");
	show_title(); Sleep(200);
	cout << "\t \t\t\tTHANK YOU FOR USING OUR PROGRM\n";
	Sleep(1000);
	system("cls");
	window = 1;
}
//////////////////////////////////////////////////////
//------------------------------functions definations

// print lline function
void pline(int n) {
	cout << "\n";
	while (n--)cout << "_";
	cout << '\n';
}
//----------------------
//void Push(point t) {
//	arr[siz - 1] = t;
//	siz++;
//	arr = new point[siz];
//}
//----------------------

// check enter right num
bool is_right_num(int val) {
	if (val < 0 || val>9)return 0;
	return 1;
}
//-----------------------

// show our board_s
void print_board(bool end) {
	if (end) { // then we print the final board_s the ans.
		pline(50);
		for (int i = 0; i < 9; i++) {
			cout << "\t\t| ";
			for (int j = 0; j < 9; j++) {
				if (!(j % 3)) {
					cout << "| " << board_s[i][j] << " ";
				}
				else {
					cout << board_s[i][j] << " ";
				}
			}
			cout << " |";
			pline(50);
		}
		pline(50);
	}
	else {// then we print entered board_s
		for (int i = 0; i < 9; i++) {
			cout << "\t\t";
			for (int j = 0; j < 9; j++) {
				if (board_s[i][j] == -1)cout << "0 ";
				else if (board_s[i][j])cout << board_s[i][j] << " ";
				else return;
			}
			cout << "\n";
		}
	}
}
//----------------------
/*
0 5 8 0 0 0 0 4 0
0 1 0 0 0 5 0 6 3
0 0 0 6 7 0 0 0 0
0 6 0 4 9 0 0 0 0
0 7 0 0 2 0 9 0 8
9 0 0 5 8 0 0 0 0
1 8 0 7 0 2 0 0 0
3 0 0 8 0 0 5 2 0
0 9 0 0 0 0 7 0 1
----------------------------
3 0 0 8 0 1 0 0 2
2 0 1 0 3 0 6 0 4
0 0 0 2 0 4 0 0 0
8 0 9 0 0 0 1 0 6
0 6 0 0 0 0 0 5 0
7 0 2 0 0 0 4 0 9
0 0 0 5 0 9 0 0 0
9 0 4 0 8 0 7 0 5
6 0 0 1 0 7 0 0 3
----------------------------
0 0 3 4 5 6 7 8 9
7 8 9 1 2 3 4 5 6
4 5 6 7 8 9 1 2 3
3 1 2 8 4 5 9 6 7
6 9 7 3 1 2 8 4 5
8 4 5 6 9 7 3 1 2
2 3 1 5 7 4 6 9 8
9 6 8 2 3 1 5 7 4
5 7 4 9 6 8 2 3 1
*/
// get user board_s
void get_board() {
	pline(100);
	cout << "\t\t\t\t\tEnter Your Board bellow\n";
	cout << "\t\t\t\t\tTo Enter empty cell, enter 0\n\n";
	//-----------------------get board_s
	for (int i = 0; i < 9; i++) {
		cout << "\t\t\t";
		for (int j = 0; j < 9; j++) {
			int val;
			cin >> val;
			while (!is_right_num(val)) {
				pline(30);
				system("cls");
				Sleep(500);
				pline(70);
				cout << "Please, Enter valid Num (*_*)\n\n";
				pline(70);
				Sleep(500);
				print_board(false);

				cin >> val;
			}
			if (!val) {
				arri.push_back({ i,j });
				board_s[i][j] = -1;
			}
			else
				board_s[i][j] = val;
		}
		cout << "\n";
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board_s[i][j] == -1)board_s[i][j] = 0;
		}
	}
}
//-------------------------

// check empty cell in board_s
bool is_empty_board(int b[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (b[i][j] == 0)return 1;
		}
	}
	return 0;
}
// override
bool is_empty_board() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board_s[i][j] == 0)return 1;
		}
	}
	return 0;
}
//-----------------------------

// this function clear repeated array
void clear_repeated() {
	for (int i = 0; i < 9; i++) {
		repeat[i] = i + 100;
	}
}
//------------------------------

// check if number occur twice
bool is_exist(int value) {
	// this func checks if the value occures inside repeated array

	for (int i = 0; i < 9; i++) {

		if (repeat[i] == value && repeat[i]) { return 1; }

		// as now we check if number is zero, and consider it as not winning board_s.
	}
	return 0;
}
//---------------------------------

//////////////////////////////////////////////comming function check winner board_s 
//---------------------------------------------------------------
bool check_col(int b[9][9]) {

	bool is = 1; // we assume first it has no repeated numbers

	for (int i = 0; i < 9; i++) {
		clear_repeated(); // initializing array (repeated.)

		for (int j = 0; j < 9; j++) {
			int temp = b[j][i];
			if (is_exist(temp)) {
				is = 0;
				break;
			}
			else {
				repeat[j] = temp;
			}
		}
		if (!is)break;

	}
	return is;
	// if all columns are not the same then it will return 1;
}

//-------------------------------------------------------------------
bool check_row(int b[9][9]) {

	bool is = 1; // we assume first it has no repeated numbers

	for (int i = 0; i < 9; i++) {

		clear_repeated(); // initializing array (repeated.)

		for (int j = 0; j < 9; j++) {
			int temp = b[i][j];
			if (is_exist(temp)) {
				is = 0;
				break;
			}
			else {
				repeat[j] = temp;
			}
		}
		if (!is)break;

	}
	return is;
	// if all rows are not the same then it will return 1;
}

//-------------------------------------------------------------------
bool check_rectangles(int b[9][9]) {

	// to solve this problem, we need to imagine each small recangle as an individual array
	// so we notice that each small array, starts with column or row that is divisible by 3

	for (int start_row = 0; start_row < 9; start_row += 3) {
		// this loop shifts start index of array vertically

		for (int start_col = 0; start_col < 9; start_col += 3) {
			// this loop shifts start index of array horizontally
			//----------
			// now we need to loop over each small array

			for (int i = start_row; i < start_row + 3; i++) {
				clear_repeated();
				for (int j = start_col; j < start_col + 3; j++) {
					int temp = b[i][j];

					if (is_exist(temp)) {
						return 0;
					}
					else {
						repeat[j] = temp;
					}

				}
			}

		}
	}
	return 1;

}
////////////////////////////////////////////////////////////////////////////////////

// copy boards
void copy_board(int ori[9][9], int cop[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			ori[i][j] = cop[i][j];
		}
	}
}
//--------------------------------------

// uses checks funcs to check current board_s
bool is_right_board(int b[9][9]) {
	if (!check_col(b) || !check_rectangles(b) || !check_row(b)) { return 0; }
	else { return 1; }

}
//--------------------------------------

// try to find right permutation of nums
void solver(int boardi[9][9]) {
	//======Base Case======
	if (!is_empty_board(boardi)) {// if board_s is full
		// check if right board_s or not
		if (is_right_board(boardi)) {
			// then copy boardi to our answer board_s 
			copy_board(board_s, boardi);
			// set breaker to 1
			to_break = 1;
		}
		else {
			// then return as not right board_s
			return;
		}
	}
	//---------------------else we do board_s
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!boardi[i][j]) {//0
				for (int k = 1; k < 10; k++) {
					//take
					boardi[i][j] = k;
					solver(boardi);
					boardi[i][j] = 0;
				}
			}

		}

	}
	return;

}
//--------------------------------------

// if user want solve again
bool solve_again() {
	char ch;
	pline(50);
	cout << "TO SOLVE ANOTHER BOARD ENTER Y,  OR ANY KEY TO BREAK(^ _ ^)\n\n";
	cin >> ch;
	ch = tolower(ch);
	if (ch == 'y')return 1;
	return 0;
}
//---------------------------------------
void show_title() {
	cout << "\t\t\t-------------------||(-_-)|SUDOKU SOLVER|(-_-)||-------------------\n\n\n";
}
//---------------------------------------------------

// run the program
bool program() {
	to_break = 0;
	system("cls");
	show_title();
	get_board();
	int temp[9][9];
	copy_board(temp, board_s);
	// there we have two algorithms
	bool sol = solving(temp, 0);
	if (!sol) {
		pline(100);
		cout << "\t\t\t\tTHERE IS NO SOLUTION FOR THIS BOARD\n";
	}
	else
		print_board(1);
	Sleep(5000);
	return solve_again();
}
////////////////////////////////////////////////////////////////////////////////////////

//algorithm 2 using graph

bool  solving(int b[9][9], int ind) {
	//--------------------------------
	if (!is_empty_board(b)) {
		if (is_right_board(b)) {
			copy_board(board_s, b);
			return 1;
		}
		return 0;
	}
	//---------------------------------
	if (!is_right_board(b))return 0;
	if (ind >= arri.size())return 0;
	//---------------------------------
	for (int i = 1; i < 10; i++) {
		b[arri[ind].x][arri[ind].y] = i;
		if (solving(b, ind + 1)) { return 1; }
		else {
			b[arri[ind].x][arri[ind].y] = 0;
		}
	}
}
 