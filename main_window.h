#pragma once

//------------------------------------------------------------------------ c++ header files
#include<SFML/Graphics.hpp>
#include<chrono>
#include<iostream>
#include<vector>
#include<map>
#include<any>
#include<cmath>
#include<sstream>
#include<queue>
#include<algorithm>
#include<deque>
#include<set>
#include<iomanip>
#include<utility>
#include<stack>
#include<time.h>
#include<Windows.h>
#include<stdio.h>
#include<numeric>
#include <SFML/Audio.hpp>
//#include<bits/stdc++.h>
#include<cstring>
#include<string>
#include <random>
//----------------------------------------------------------------------------
//------------------------------------------------------------------------ project files
#include"classes.h"
#include"TextBox.h"
#include"animation.h"

#include"login_registeri.h"
Animation backAnime[3];

#include"Piano.h"
#include"TIC_TAC_TOE.h"
#include"pingpong.h"
#include"Pac_Man.h"
#include"sudoko_solver.h"
#include"CMD.h"
#include"Casino_guessing number.h"
#include"puzzle.h"
#include"games tutorial.h"
#include"Snake.h"
#include"Brick breaker.h"
#include"magica.h"
#include"Card Game.h"
using namespace std;

using namespace sf;

//----------------------------------------------------------
object add;
object addfield;
object show_id;
object icon[11]; // for now 
object currentMoney;
RectangleShape gameShader;
string nameOfgames[11];
Text_C gameName;
//-----------------------------------------
//accounti client;
void playSong(SoundBuffer& buff) {

	back_sound.setBuffer(buff);
	back_sound.play();
	back_sound.setLoop(true);
}
void main_initializations() {
	// background 
	/////////////////////

	// add money button
	add.make_text("alfont_com_arial-1.ttf", "ADD");
	add.shape_text(60, Color::Blue);
	add.t_origin();
	add.text_pos(1770.f, 800.f);
	//////////////////////

	// ID hider and shower
	show_id.make_text("MorningRainbow.ttf", "########");
	show_id.shape_text(32, Color::Black);
	show_id.t_origin();
	show_id.text_pos(1770.f, 100.f);
	///////////////////////

	//-----------------ICONS----------------//
	// yugi card   (0)
	icon[0].make_sp("assets\\icons\\yugi_icon.png");
	icon[0].origin(1);
	// tic  card   (1)
	icon[1].make_sp("assets\\icons\\tic_icon.png");
	icon[1].origin(1);
	// chatti card   (2)
	icon[2].make_sp("assets\\icons\\paint_icon.png");
	icon[2].origin(1);
	//  piano card   (3)
	icon[3].make_sp("assets\\icons\\piano_icon.png");
	icon[3].origin(1);
	// pacman card   (4)
	icon[4].make_sp("assets\\icons\\hang_icon.png");
	icon[4].origin(1);
	// ping card   (5)
	icon[5].make_sp("assets\\icons\\ping_icon.png");
	icon[5].origin(1);
	// sudoku card   (6)
	icon[6].make_sp("assets\\icons\\sudoku icon.png");
	icon[6].origin(1);
	//-------------
	// Casino card  (7)
	icon[7].make_sp("assets\\icons\\casino icon.png");
	icon[7].origin(1);
	//-------------
	// puzzle card  (8)
	icon[8].make_sp("assets\\icons\\puzzle icon.png");
	icon[8].origin(1);
	//-------------
	// puzzle card  (9)
	icon[9].make_sp("assets\\icons\\snake icon.png");
	icon[9].origin(1);
	//-------------
	// brick card  (10)
	icon[10].make_sp("assets\\icons\\brick breaker icon.png");
	icon[10].origin(1);
	//-------------

	// icons postion
	float shift = 200.f;
	int i = 0;
	for ( i ; i < 5; i++) {
		icon[i].sp_pos(shift + i * 300.f, 200.f);
	}
	for (int j=0; i < 10; i++,j++) {
		icon[i].sp_pos(300.f * j + shift, 550.f);
	}
	for (int j = 0; i < 11; i++, j++) {
		icon[i].sp_pos(300.f * j + shift, 900.f);
	}
	//-----------------------------------------------add field
	addfield.shape_entity(1, Color::White, 250.f, 70.f);
	addfield.recta.setPosition(Vector2f(1770.f, 600.f));
	addfield.make_text("alfont_com_arial-1.ttf","|");
	addfield.shape_text(40, Color::Black);
	//addfield.t_origin();
	addfield.text_pos(addfield.recta.getPosition().x-110.f, addfield.recta.getPosition().y);
	addfield.text.setOutlineColor(Color::Black);
	//---------------------------------------------------------
	//--------current money-----------
	currentMoney.make_text("alfont_com_arial-1.ttf", "#########");
	currentMoney.shape_text(32, Color::Black);
	//currentMoney.t_origin();
	currentMoney.text_pos(1770.f, 900.f);
	//-------------------------------
	gameShader.setFillColor(Color(50, 150, 100,50));
	gameShader.setSize(Vector2f(300, 1080));
	gameShader.setPosition(Vector2f(1920 - 300, 0));
	//////////////////////////////////////////////
	////games name
	nameOfgames[0] = "YO GI OH!";
	nameOfgames[1] = "TIC TAC TOE!";
	nameOfgames[2] = "CHATTI!";
	nameOfgames[3] = "PIANO!";
	nameOfgames[4] = "PACMAN!";
	nameOfgames[5] = "PINGPONG!";
	nameOfgames[6] = "SUDOKU SOLVER!";
	nameOfgames[7] = "CASINO!";
	nameOfgames[8] = "PUZZLE!";
	nameOfgames[9] = "SNAKE!";
	nameOfgames[10] = "BRICK!";
	//text
	gameName.make_text("Game Of Squids.ttf", "");
	gameName.shape_text(22, Color(32, 238,209));
	///////////////////////////////////////////////
	facLogo.loadSp("assets\\facuality back.png");
	/*
					 +2
		   -3->cmd
			0->card yugi
			1->tic
			2->paint
			3->piano
			4->pacman
			5->pingpong
			6->sudoku solver
			7->casino
			8->puzzle
			9->snake
			10->brick
			*/
}
bool moeny_alert(int i) {
	if (i == 1) {
		if (arr_acc[ind].money <= ticCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}
		arr_acc[ind].money -= ticCost;
		return 0;
	}
	else if (i == 2) {

		if (arr_acc[ind].money <= paintCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= paintCost;
		return 0;
	}
	else if (i == 3) {

		if (arr_acc[ind].money <= pianoCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= pianoCost;
		return 0;
	}
	else if (i == 4) {

		if (arr_acc[ind].money <= pacmanCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= pacmanCost;
		return 0;
	}
	else if (i == 5) {

		if (arr_acc[ind].money <= pingCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= pingCost;
		return 0;
	}
	else if (i == 6) {

		if (arr_acc[ind].money <= sudokuCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= sudokuCost;
		return 0;
	}
	else if (i == 7) {

		if (arr_acc[ind].money <= casinoCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}
		return 0;
	}
	else if (i == 8) {

		if (arr_acc[ind].money <= puzzleCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}
		
		arr_acc[ind].money -= puzzleCost;
		return 0;
	}
	else if (i == 9) {

		if (arr_acc[ind].money <= snakeCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= snakeCost;
		return 0;
	}
	else if (i == 10) {

		if (arr_acc[ind].money <= brickCost) {
			//alertTxt.alert(gwin, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
			return 1;
		}

		arr_acc[ind].money -= brickCost;
		return 0;
	}
	// do for all games
	/*
					 +2
		   -3->cmd
			0->card yugi
			1->tic
			2->paint
			3->piano
			4->pacman
			5->pingpong
			6->sudoku solver
			7->casino
			8->puzzle
			9->snake
			10->brick
			*/
			return 0;
}
void makeBackgrounds() {
	///back one  hatsune
	backAnime[0].setHight(263);
	backAnime[0].setWidth(263);
	backAnime[0].setIndX(0);
	backAnime[0].setIndY(0);
	backAnime[0].texture.loadFromFile("assets\\backImages\\output-onlinegiftools.png");
	backAnime[0].texture.setSmooth(1);
	backAnime[0].sp.setTexture(backAnime[0].texture);
	backAnime[0].setLimitX(53);
	backAnime[0].setLimitY(0);
	backAnime[0].sp.setScale(Vector2f(4, 4));
	backAnime[0].sp.setPosition(Vector2f(960, 540));
	backAnime[0].todraw = 1;
	//////////////////////////

	///back two  nico
	backAnime[1].setHight(281);
	backAnime[1].setWidth(500);
	backAnime[1].setIndX(0);
	backAnime[1].setIndY(0);
	backAnime[1].texture.loadFromFile("assets\\backImages\\download (3).png");
	backAnime[1].texture.setSmooth(1);
	backAnime[1].sp.setTexture(backAnime[1].texture);
	backAnime[1].setLimitX(3);
	backAnime[1].setLimitY(5);
	backAnime[1].sp.setScale(Vector2f(3.84, 3.84));
	backAnime[1].sp.setPosition(Vector2f(960, 540));
	backAnime[1].todraw = 1;
	//////////////////////////

	///back three  sowrd art action
	backAnime[2].setHight(389);
	backAnime[2].setWidth(692);
	backAnime[2].setIndX(0);
	backAnime[2].setIndY(0);
	backAnime[2].texture.loadFromFile("assets\\backImages\\spritesheet.png");
	backAnime[2].texture.setSmooth(1);
	backAnime[2].sp.setTexture(backAnime[2].texture);
	backAnime[2].setLimitX(0);
	backAnime[2].setLimitY(2);
	backAnime[2].sp.setScale(Vector2f(3.5, 3.5));
	backAnime[2].sp.setPosition(Vector2f(960, 540));
	backAnime[2].todraw = 1;
	//////////////////////////

	//////////////////////////
	backAnime[2].delay = 6000;
	backAnime[1].delay = 100;
	backAnime[0].delay = 100;
}

//-----------------------------------------------------------
bool to_run_games() {
	srand(time(0));// time,  // rand();

	sf::Event closeEv;
	
	initial_accounts();
	
	main_initializations();
	initialize_options();
	iniAlert();
	make_words();
	
	tic_initialize_sprites();
	initialize_board();
	ping_initial();
	initialize_piano_sprites();
	initialize_text_piano();
	intialize_piano_sounds();
	pac_intial();
	initialLoginWindow();
	makeBackgrounds();
	initialize_again_menu();
	inititialChat();
	setBrick();
	initial_ping_score();
	setPuzzle();
	setSnake();
	initial_cards();
	//
	//appear(win);
	///////// background
	
	Clock clock,d;
	clock.restart();
	Time time;
	
	
	/////////
	bool addmoney = 0;
	// game tutorial
	tutorial gameTutorial("Game Of Squids.ttf","");
	gameTutorial.shape_text(40, Color::Red);
	//---------------
	
	Clock gameClock;
	TIME ttime;
	bool isGameClock = 0;
	//window = 2;
	while (win.isOpen()) {

		// -------------------------------close window
		while (win.pollEvent(closeEv)) {

			if (closeEv.type == sf::Event::Closed) {
				win.close();
			}

			///-------------options-------------
			if (closeEv.type == Event::KeyReleased) {
				if (closeEv.key.code == sf::Keyboard::Escape)
				{

					if (to_run_options()) {
						win.clear();
						//hide(win);
						//appear(win);
					}
					else {

						win.clear();
						//hide_all_window();
						if (window != 1)
							window = 1;
						else
							window = 0;
					}
				}
			}
			//------------------------------------
			
			///--------------toAdd_ backspace-----

			if (closeEv.type == Event::KeyReleased) {
				if (closeEv.key.code == sf::Keyboard::BackSpace&&!arr_acc[ind].added)
				{
					if (arr_acc[ind].toAdd.size())arr_acc[ind].toAdd.resize(arr_acc[ind].toAdd.size() - 1);
				}
			}
			//------------------------------------
		}
		win.clear(Color::White);

		if (window != 4) {

			if (clock.getElapsedTime().asMilliseconds() > backAnime[wallInd].delay) {
				backAnime[wallInd].animate();
				clock.restart();
			}
			win.draw(backAnime[wallInd].sp);
		}
		//---------------------------------------------
		if (!window) {// login window
			to_run_logini();
			if (window == 1) {
				playSong(song3);
			}
			else if (window == -1) {
				playSong(song2);
			}
			Sleep(100);
		}
		else if (window == -1) {// cmd
			to_run_cmd(arr_acc[ind]);
			window = 0;
		}

		else if (window==1) { // main window
		
			
			if (addmoney&&!arr_acc[ind].added) {
				// do add money
				if (arr_acc[ind].toAdd.size() <= 9) {
				


					if (Keyboard::isKeyPressed(Keyboard::Num0) && arr_acc[ind].toAdd.size()) {
						arr_acc[ind].toAdd += '0';
					}

					if (Keyboard::isKeyPressed(Keyboard::Num1)) {
						arr_acc[ind].toAdd += '1';
					}

					if (Keyboard::isKeyPressed(Keyboard::Num2)) {
						arr_acc[ind].toAdd += '2';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num3)) {
						arr_acc[ind].toAdd += '3';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num4)) {
						arr_acc[ind].toAdd += '4';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num5)) {
						arr_acc[ind].toAdd += '5';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num6)) {
						arr_acc[ind].toAdd += '6';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num7)) {
						arr_acc[ind].toAdd += '7';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num8)) {
						arr_acc[ind].toAdd += '8';
					}
					if (Keyboard::isKeyPressed(Keyboard::Num9)) {
						arr_acc[ind].toAdd += '9';
					}
					Sleep(100);
				}
				addfield.text_str(arr_acc[ind].toAdd+"|");
			}
			
			////////////drawings////////////
			
			win.draw(gameShader);

			for (int i = 0; i < 11; i++) {
				if (mouse_intersects(win, icon[i].sp)) {
					icon[i].sp.setScale(Vector2f(1.25f, 1.25f));
					gameName.text_str(nameOfgames[i]);
					gameName.text_pos(icon[i].sp.getPosition().x-100, icon[i].sp.getPosition().y -160 );
					
				}
				win.draw(icon[i].sp);
				win.draw(gameName.text);
				if (mouse_l()&&mouse_intersects(win,icon[i].sp)) {
					icon[i].sp.setScale(Vector2f(1.f, 1.f));
					// check if user have money to play that game
					if (moeny_alert(i)) {
						// show alert
						alertTxt.alert(win, "NOT ENOUGH MONEY", Color::Red, 960.f, 540.f);
						continue;
					}

					//--------------------------------------------
					window = i+2;
					Sleep(200);

					if (window > 1) {
						gameTutorial.setInd(window - 2);
						gameTutorial.printTutorial(win, 40);
					}
					continue;
				}
				icon[i].sp.setScale(Vector2f(1.f, 1.f));
				gameName.text_str("");
			}
			//
			if (mouse_intersects(win, add.text)) {
				add.text_color(Color::Red);
			}
			else {
				add.text_color(Color::Blue);
			}
			win.draw(add.text);
			//
			//
			if (mouse_intersects(win, show_id.text)) {
				show_id.text_str(arr_acc[ind].id);
			}
			else {
				show_id.text_str("########");
			}
			//
			//
			if (mouse_intersects(win, currentMoney.text)) {
				currentMoney.text_str(to_string(arr_acc[ind].money));
			}
			else {
				currentMoney.text_str("(MyMoney)");
			}
			win.draw(addfield.recta);

			win.draw(addfield.text);

			win.draw(show_id.text);

			win.draw(currentMoney.text);
			//
			win.display();
			// mouse clicks
			if (mouse_l()) {
				if (mouse_intersects(win, addfield.recta))
					addmoney = 1;
				else if (mouse_intersects(win, addfield.recta) && arr_acc[ind].added) 
					addfield.text_str(arr_acc[ind].toAdd);
				else if (mouse_intersects(win, add.text))arr_acc[ind].added = 1, addfield.text_str("");

				else addmoney = 0;
				Sleep(50);
			}
			if (window > 1) {
				gameClock.restart();
				isGameClock = 1;
			}
			
		}
		else if (window == 2) { // magica.io
		to_run_card();

	    }
		else if (window == 3) { // tic tac toe
		
		to_run_tic();
        }
		else if (window == 4) { // chat 
		to_run_chatRoom();

		}
		else if (window == 5) {// piano
		to_run_piano();
        }
		else if (window == 6) {// pacman
		to_run_pac();
		}
		else if (window == 7) {// ping pong
		to_run_pingpong( d);
        }
		else if (window == 8) { // sudoku
		to_run_sudoku_solver();
        }
		else if (window == 9) {// casino
		to_run_casino();
        }
		else if (window == 10) {// puzzle
		to_run_puzzle();
        }
		else if (window == 11) { // snake
		to_run_snake();
        }
		else if (window == 12) { // brick
		to_run_breaker();
        }

		/*
		             +2
		   -3->cmd
		    0->card yugi
			1->tic
			2->paint
			3->piano
			4->pacman
			5->pingpong
			6->sudoku solver
			7->casino
			8->puzzle
			*/

			if (isGameClock) {

				//----------------count time-----------------
				ttime.current_time(gameClock);
				entity_time.text_str(ttime.current.time_str);
				entity_time.text.setFillColor(Color::Cyan);

				//--------------check time--------------------

				if (ttime.current.duration >= 180) {
					if (play_again(win)) {
						gameClock.restart();
						ttime.current.duration = 0;
						ttime.minutes = 0;
						ttime.seconds = 0;
					}
					else {
						window = 1;
						isGameClock = 0;
 						Sleep(300);
					}
				}
				//-------------------------------------------

			}
	}
	return 0;
}