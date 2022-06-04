#pragma once
//------------------------------------------------------------------------ c++ header files

using namespace std;
using namespace sf;
//----------------------------------------------------------
object controller,mouse_c,t_title;
object board[3][3];
object blank, xt, ot;
Text_C EGl, EGr;
char c_board[3][3] = {};// make minmax
bool isplayerx = 1;
vector<object>x_tic, o_tic;
static int deep = 9;
//--------------------
void draw(RenderWindow& win, vector<object>v) {
	for (int i = 0; i < v.size(); i++) {
			win.draw(v[i].sp);
	}
}
void draw(RenderWindow& win, object arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j].todraw)
				win.draw(arr[i][j].sp);
			else
				win.draw(arr[i][j].shadow_sp);
		}
	}
}
//----------------------------------------------------------sprites
void tic_initialize_sprites() {
	
	//---wallstart sprites
	// controller
	controller.make_sp("assets\\tic\\controler.png");
	controller.make_shadow("assets\\tic\\controler shadow.png");
	controller.origin();
	controller.sp_pos(300.f, 400.f);
	controller.shadow_pos();
	controller.todraw = 0;
	controller.scale_sp(0.4f, 0.4f, 1);
	// mouse
	mouse_c.make_sp("assets\\tic\\mouse.png");
	mouse_c.make_shadow("assets\\tic\\mouse shadow.png");
	mouse_c.origin();
	mouse_c.sp_pos(1600.f,400.f);
	mouse_c.shadow_pos();
	mouse_c.todraw = 1;
	mouse_c.scale_sp(0.4f, 0.4f, 1);
	//------------------
	//screen title
	t_title.make_text("MorningRainbow.ttf", "TIC_TAC_TOE");
	t_title.shape_text(100, Color(108, 255, 233, 200), 0, 0);
	t_title.text_pos(950.f, 30.f);
	//-------end game text
	EGl.make_text("MorningRainbow.ttf", "GAME ");
	EGl.shape_text(150, Color(28, 33, 142));
	EGr.make_text("MorningRainbow.ttf", "OVER ");
	EGr.shape_text(150, Color(15, 154, 207));
}
void initialize_board() {
	// blank
	blank.make_sp("assets\\tic\\tic_pos_sp.png");
	blank.make_shadow("assets\\tic\\tic_pos_shadow.png");
	blank.origin();
	blank.todraw = 1;
	// xt
	xt.make_sp("assets\\tic\\X.png");
	xt.origin(1);
	// ot
	ot.make_sp("assets\\tic\\circle_o.png");
	ot.origin(1);
	// then push in arrays
	float shift_x = 20.f,shift_y=240.f;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = blank;
			board[i][j].sp_pos(float(shift_y+(shift_x+250.f)*i), float(shift_y+(shift_x+250.f)*j));
			board[i][j].shadow_pos();
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c_board[i][j] = '_';
		}
	}
}
//----------------------------minimax algo-------------------
short is_win(char boardi[3][3],bool player1) {// check if in this move any player wins ot not.
	// positive for first player, negative for second player
	if (player1) {
		char ch = 'x';
		bool iswin = 1;
		for (int i = 0,j=0; i < 3; i++,j++) {
			if (boardi[i][j] != ch) { iswin = 0; break; }
		}
		if (iswin) {
			return 1;
		}
		iswin = 1;
		for (int i = 0, j = 2; i < 3; i++, j--) {
			if (boardi[i][j]!= ch) { iswin = 0; break; }
		}
		if (iswin)return 1;
		iswin = 1;
		for (int i = 0; i < 3; i++) {
			bool is = 1;
			for (int j = 0; j < 3; j++) {
				if (boardi[i][j] != ch)is = 0;
			}
			if (is)return 1;
		}
		for (int i = 0; i < 3; i++) {
			bool is = 1;
			for (int j = 0; j < 3; j++) {
				if (boardi[j][i] != ch)is = 0;
			}
			if (is)return 1;
		}
		return 0;
	}
	else {
		char ch = 'o';
		bool iswin = 1;
		for (int i = 0, j = 0; i < 3; i++, j++) {
			if (boardi[i][j] != ch) { iswin = 0; break; }
		}
		if (iswin) {
			return -1;
		}
		iswin = 1;
		for (int i = 0, j = 2; i < 3; i++, j--) {
			if (boardi[i][j] != ch) { iswin = 0; break; }
		}
		if (iswin)return -1;
		iswin = 1;
		for (int i = 0; i < 3; i++) {
			bool is = 1;
			for (int j = 0; j < 3; j++) {
				if (boardi[i][j] != ch)is = 0;
			}
			if (is)return -1;
		}
		for (int i = 0; i < 3; i++) {
			bool is = 1;
			for (int j = 0; j < 3; j++) {
				if (boardi[j][i] != ch)is = 0;
			}
			if (is)return -1;
		}
		return 0;
	}
}
//----------------------checks if board has empty cell or not
bool check_empty(char boardi[3][3]) {
	bool isempty = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boardi[i][j] == '_')isempty = 1;
		}
	}
	return isempty;
}
//----------------------
struct cordinates {
	int x=-1, y=-1;

};
cordinates minimizer;
//------------------------------return best value of choices
short o_minimax(int depth, char boardi[3][3], bool player1) {// do the algo
	short score = 0, bestscore = 0;

	if (is_win(boardi, !player1)) {
		// if it is human turn now, and he then loses as AI won previous turn.
		if (player1)return -1;
		else return 1; // opposite to above condition.
	}
	if (!depth)return 0; // as now we hadnt met any winning move.
	//

	if (player1) {// now its maximizer (human.)
		bestscore = -10;
		// do check all cells
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (boardi[i][j] == '_') {
					boardi[i][j] = 'o';
					score = o_minimax(depth-1, boardi, false);
					boardi[i][j] = '_';
					if (score > bestscore) {
						bestscore = score;
					}
				}
			}
		}
		// then return best score
		return bestscore;
	}
	else {// now its minimizer (AI.)
		bestscore = 10;
		// do check all cells
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (boardi[i][j] == '_') {
					boardi[i][j] = 'o';
					score = o_minimax(depth-1, boardi, true);
					boardi[i][j] = '_';
					if (score < bestscore) {
						bestscore = score;
					}
				}
			}
		}
		// then return best score
		return bestscore;

	}
}

//------------------------- return best move
cordinates best_move(char b[3][3]) {
	cordinates temp;
	short score = 0, bestscore = 10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (b[i][j] == '_') {
				b[i][j] = 'o';
				score = o_minimax(deep, b, true);
				b[i][j] = '_';
				if (score < bestscore) {
					temp.x = i, temp.y = j;
					bestscore = score;
				}
			}
		}
	}
	return temp;
}
//-----------------------------------------------------------
int row = 0, col = 0;
bool iscontroller = 1;

//-----------------------------------------------------------
bool to_run_tic() {/*
	tic_initialize_sprites();
	initialize_board();*/
	//initializaions
	
	
	
		bool skipper = 0;

		if ( backAnime[wallInd].todraw ) {

			
			// check arrows pressed
			if (Keyboard::isKeyPressed(Keyboard::Right)|| Keyboard::isKeyPressed(Keyboard::Left)) {
				selecty();
				iscontroller = !iscontroller;
			}
			bool isclick = 0;
			// check mouse click
			if (mouse_l()) {
				clicky();
				if (controller.mouse_intersects(win, controller.sp)) {
					isclick = 1;
					iscontroller = 1;
				}
				else if (mouse_c.mouse_intersects(win, mouse_c.sp)) {
					isclick = 1;
					iscontroller = 0;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter)&&!isclick) {
				isclick = 1;
			}
			//---drawings
			win.draw(t_title.text);
			if (iscontroller) {
				win.draw(controller.shadow_sp);
				win.draw(mouse_c.sp);
			}
			else {
				win.draw(mouse_c.shadow_sp);
				win.draw(controller.sp);
			}
			win.display();
			Sleep(100);
			if (isclick) {
				backAnime[wallInd].todraw = 0;
				t_title.text_color(Color(103, 9, 63));
				t_title.text_pos(500.f, 30.f);
			}
	    }
		else {
			

			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
				backAnime[wallInd].todraw = 1;
			}
			
			// check in drawings part if user entered controller or mouse 
			bool ischoosed = 0;
			if (iscontroller) {
				// check if any arrow pressed
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					row++;
					row = row % 3;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					row--;
					if (row < 0) {
						row = 2;
					}
				}
				else if (Keyboard::isKeyPressed(Keyboard::Up)) {
					col--;
					if (col < 0) { col = 2; }
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down)) {
					col++;
					col = col % 3;
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					ischoosed = 1; clicky();
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (mouse_intersects(win, board[i][j].sp)) {
							row = i, col = j;
							if (mouse_l()) {
								ischoosed = 1; clicky();
							}
						}
						
					}
				}
			}
			//----------
			bool isXwin = 0;
			// check if user choosed that cell or not.
			if (ischoosed && c_board[row][col]=='_') {// and if cell is available or not.
				
				// then we need to mark it with x or o.
				c_board[row][col] = 'x';
				board[row][col].todraw = 0;
				x_tic.push_back(xt);
				x_tic.back().sp.setPosition(board[row][col].sp.getPosition());
				if (is_win(c_board, true) ) { skipper = 1; isXwin = 1; }
				if (!skipper) {
					// now check next move for computer
					minimizer = best_move(c_board);
					// then make move
					c_board[minimizer.x][minimizer.y] = 'o';
					// check winner
					if (is_win(c_board, false)) {
						skipper = 1;
					}
					else{
						c_board[minimizer.x][minimizer.y] = '_';
						bool bes = 0;
						for (int i = 0; i < 3; i++) {
							for (int j = 0; j < 3; j++) {
								if (c_board[i][j] == '_'&&!bes) {
									c_board[i][j] = 'x';
									if (is_win(c_board, 1)) {
										minimizer.x = i, minimizer.y = j; bes = 1;
									}
									c_board[i][j] = '_';
								}
							}
					    }
					}
					c_board[minimizer.x][minimizer.y] = 'o';

					board[minimizer.x][minimizer.y].todraw = 0;
					o_tic.push_back(ot);
					o_tic.back().sp.setPosition(board[minimizer.x][minimizer.y].sp.getPosition());
					//
				}
			}
			else {
				board[row][col].todraw = 0;
			}

			there_is_winner: // this statment when only x player wins

			// drawings

			win.draw(t_title.text);
			
			draw(win, board);
			draw(win, x_tic);
			draw(win, o_tic);
			win.draw(entity_time.text);// TIME

			win.display();
			
			board[row][col].todraw = 1;
			board[minimizer.x][minimizer.y].todraw= 1;
			Sleep(100);

			if (x_tic.size() >= 5||skipper) {
				EGl.text.setOrigin(EGl.text.getGlobalBounds().width, 0); // left up
				EGr.text.setOrigin(0, 0); // right down
				EGr.text.setPosition(Vector2f(960.f, 1080.f));
				EGl.text_pos(960.f, 0);
				for (float it = 0.f; it < 600.f; it += 30.f) {
					win.clear(Color::White);
					//

					win.draw(backAnime[wallInd].sp);
					win.draw(t_title.text);

					draw(win, board);
					draw(win, x_tic);
					draw(win, o_tic);
					//
					win.draw(EGl.text);
					win.draw(EGr.text);
					EGl.text.setPosition(Vector2f(960.f, it));
					EGr.text.setPosition(Vector2f(960.f, 1080.f - it));
				    //
					win.display();
					//
					Sleep(50);
					if (isXwin) {
						arr_acc[ind].money += ticCost;
					}
					else {

						arr_acc[ind].money -= ticCost;// last game cost

						int remaining = arr_acc[ind].money - ticCost;
						if (remaining <= 0) {
							cout << "you dont have enough money!\n";
							system("cls");
							return 1;
						}
						
					}
				}
				Sleep(1000);
				// clear board
				x_tic.clear();
				o_tic.clear();
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						c_board[i][j] = '_';
						board[i][j].todraw = 1;
					}
				}
			}
			
		}
		
	

}



