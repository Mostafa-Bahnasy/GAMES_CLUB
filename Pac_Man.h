#pragma once
//------------------------------------------------------------------------ c++ header files
//#include<SFML/Graphics.hpp>
//#include"classes.h"
//#include<iostream>
//#include<vector>
//#include<map>
//#include<any>
//#include<cmath>
//#include<sstream>
//#include<queue>
//#include<algorithm>
//#include<deque>
//#include<set>
//#include<iomanip>
//#include<utility>
//#include<stack>
//#include<time.h>
//#include<Windows.h>
//#include<stdio.h>
//#include<numeric>
//#include <SFML/Audio.hpp>
////#include<bits/stdc++.h>
//#include<cstring>
//#include<string>
//#include <random>
//----------------------------------------------------------------------------
using namespace std;
using namespace sf;
//----------------------------------------------------------

RectangleShape pacman, gost;
int lvl = 0; /// shows me inside the code the current lvl
int die_cnt = -3; /// count number of dies, that pacman did
float movex=0.4f, movey=0.4f; // it is better to implement it inside struct, as you will make many gosts
// now coins
// next struct contains circle and boolean, which will help me to determine
// if coin is visible or not
struct coin {
	CircleShape cir;
	bool isvisible = 1;
};
//
coin coins[10][10]; // this container carries coins that pacman eats.
//------------------------------
// score part
Text score_text; 
Font font;
string score_string;
int score_count = 0;
//--------------------------------------------------------------------------

void pac_intial() {
	// pacman (we make it rectangle here)
	pacman.setSize(Vector2f(50.f, 50.f));
	pacman.setPosition(Vector2f(600.f,900.f));
	pacman.setFillColor(Color::Yellow);
	// gost
	gost.setSize(Vector2f(50.f, 50.f));
	gost.setFillColor(Color::Blue);
	gost.setPosition(Vector2f(400.f, 400.f));
	// coins
	// we need to make a temp of one coin, and then we will copy it to our array 20*20

	// our temp
	CircleShape temp; // we make it here as a circle
	temp.setRadius(10.f); // this determine the radius length of our circle.
	temp.setFillColor(Color::Red); // set color red
	
	// now we need to set postion to our temp, but we will better do it inside the array
	// which will help us, as we use the counter of the loop to set our postion.

	for (int i = 0; i < 10; i++) {
		// it is two d array, so we make another loop inside.
		for (int j = 0; j < 10; j++) {
			// now, i represents rows, and j represents columns.
			coins[i][j].cir = temp; // we assign element of array to our temp before setting postion
			// we will make the gap horizontally between coins equal 50.f
			// and vertically equal 20.f, make it as you want
			// to setpostion, we need to multiply our circle size by indexes
			// as it will spread coins one by one
			// our radius is 10, so size is 20 width and hight

			coins[i][j].cir.setPosition(Vector2f(140.f+(20.f + 140 )* j, 100.f+(20.f + 60 )* i));
			//-------------------------------
		}
	}
	//----------------------------------------------------------------------
	// now lets move to score

	score_string = to_string(score_count); // we here set integer counter to string
	font.loadFromFile("MorningRainbow.ttf");
	// text setting
	score_text.setFont(font); // we then assign font to our text
	score_text.setString(score_string); // we her set string to text, to print it to screen
	score_text.setCharacterSize(72); // we then assign size, as in microsoft word
	score_text.setFillColor(Color::Red); // color
	score_text.setPosition(Vector2f(960.f, 60.f)); // asign it according to your window
	//----------------------------------------------------------------------------
	pacman.setOrigin(Vector2f(pacman.getLocalBounds().width / 2, pacman.getLocalBounds().height / 2));
	gost.setOrigin(Vector2f(gost.getLocalBounds().width / 2, gost.getLocalBounds().height / 2));
}



//-----------------------------------------------------------
void to_run_pac() {
	///////////////////////////////////////////////
	
		//---------------move
		// pacman

		if (Keyboard::isKeyPressed(Keyboard::Up)|| Keyboard::isKeyPressed(Keyboard::W)) {
			pacman.move(Vector2f(0.f, -6.f));
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			pacman.move(Vector2f(0.f, 6.f));
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			pacman.move(Vector2f(-6.f,0.f ));
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
			pacman.move(Vector2f(6.f, 0.f));
		}

		// pac man collision
		// we here check if pacman exceeds window cordinates
		// if then, we make it move in opposite direction.
		if (pacman.getPosition().x >= 1800.f) {
			pacman.move(Vector2f(-6.f, 0.f));
		}
		if (pacman.getPosition().x <= 10.f) {
			pacman.move(Vector2f(6.f, 0.f));
		}
		if (pacman.getPosition().y <= 10.f) {
			pacman.move(Vector2f(0.f, 6.f));
		}
		if (pacman.getPosition().y >= 980.f) {
			pacman.move(Vector2f(0.f, -6.f));
		}
		// here we check if gost intersects pacman.
		if (pacman.getGlobalBounds().intersects(gost.getGlobalBounds())) {
			pacman.setPosition(Vector2f(0.f, 0.f));
			die_cnt++;
		}
		// collision with coins
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (pacman.getGlobalBounds().intersects(coins[i][j].cir.getGlobalBounds())) {
					coins[i][j].isvisible = 0;
					coins[i][j].cir.setPosition(Vector2f(-1000.f, -1000.f));
					score_count++;
				}
			}
		}
		// gost
		// we here check if gost exceeds window cordinates
		// if then, we make it move in opposite direction.
		if (gost.getPosition().x >= 1900.f) {
			gost.move(Vector2f(-3.f, 0.f));
		}
		if (gost.getPosition().x <= 100.f) {
			gost.move(Vector2f(3.f, 0.f));
		}
		if (gost.getPosition().y <= 100.f) {
			gost.move(Vector2f(0.f, 3.f));
		}
		if (gost.getPosition().y >= 1000.f) {
			gost.move(Vector2f(0.f, -3.f));
		}
		//---------
		// ----------------gost movement
		// there we have 2 levels
		// lvl 1, gost move up and down only
		if (lvl == 0) {
			if (gost.getPosition().y > 900) {
				movey = -3.f;
			}
			else if (gost.getPosition().y < 100) {
				movey = 3.f;
			}
			gost.move(Vector2f(0.f, movey));
		}
		else if (lvl == 1) {// then we make gost follow pacman
			if (pacman.getPosition().x > gost.getPosition().x) {
				movex = 3.f;
			}
			if (pacman.getPosition().x < gost.getPosition().x) {
				movex = -3.f;
			}
			if (pacman.getPosition().y > gost.getPosition().y) {
				movey = 3.f;
			}
			 if (pacman.getPosition().y < gost.getPosition().y) {
				movey= -3.f;
			}
			gost.move(Vector2f(movex, movey));
		}
		//--------------------------------------
		if (score_count > 20) { lvl = 1; }
		//----------------drawings
		pacman.rotate(20.f);
		gost.rotate(20.f);
        win.clear(Color::White);
		// draw coins
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (coins[i][j].isvisible) // if coin is still visible draw it
					win.draw(coins[i][j].cir);
			}
		}
		win.draw(pacman);
		win.draw(gost);
		// before drawing score we need to update permanently our score
		score_string = to_string(score_count);
		score_text.setString(score_string);
		win.draw(score_text); // then draw score
		win.display();

		/// check win///
		if (score_count == 100) {
			alertTxt.alert(win, "WINNER WINNER", Color::Red, 960, 540);
			arr_acc[ind].money += 20;
			window = 1;
		}

		////////////////
		/// check lose///
		if(!die_cnt){
			if (play_again(win)) {
				
				// take money 

				arr_acc[ind].money -= pacmanCost;
				if (arr_acc[ind].money <= 0) {
					arr_acc[ind].money += pacmanCost;
					window = 1;
				}
				die_cnt = -3;
				score_count = 0;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						coins[i][j].isvisible = 1;
						coins[i][j].cir.setPosition(Vector2f(140.f + (20.f + 140) * j, 100.f + (20.f + 60) * i));

					}
				}
			}
			else {
				window = 1;
				Sleep(300);
				
			}
		}
		
}