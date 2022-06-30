#pragma once
////////////////////////////////////
pairSp cardWall, cardInner;// 7 cards
pairSp playButton, bonusB, endB;
Texture cards;
object heroCoin, devilCoin; 
Text_C playB, turnText;
pairSp cardB,Info;
Text_C endTemp;
struct cardPlayer {
	bool coinNum = 0; // zero devil && one hero
	vector<object>handS;
	vector<short>handI;
	int points = 4000;
	Text_C pointsT;
	vector<bool>sel;
};
cardPlayer player1, player2;
////////////////////////////

void initial_cards() {
	// walls
	cardWall.loadSp("assets\\card assets\\wallpaperflare.com_wallpaper-min.jpg");
	cardInner.loadSp("assets\\card assets\\Asset 10.png");
	////////
	// coins
	heroCoin.make_sp("assets\\card assets\\Asset 12-min.png");
	devilCoin.make_sp("assets\\card assets\\Asset 10-min.png");
	heroCoin.origin(true);
	devilCoin.origin(true);
	/////////
	// cards
	cards.loadFromFile ("assets\\card assets\\cards.png");
	cards.setSmooth(1);
	/////////

	playB.make_text("Game Of Squids.ttf","PLAY");
	playB.shape_text(60, Color::Blue);
	playB.text_pos(350, 680);
	/////////
	
	////////////////
	/////turn text
	turnText.make_text("Game Of Squids.ttf", "");
	turnText.shape_text(60, Color::Red);
	turnText.text.setOrigin(Vector2f(turnText.text.getLocalBounds().width / 2, turnText.text.getLocalBounds().height / 2));
	////////////////////////////////////////
	///////game play buttons////////
	// play
	playButton.loadSp("assets\\card assets\\play button.png");
	playButton.posSp(1550.f, 200.f);
	playButton.scl(0.6f, 0.6f);
	// bonus

	bonusB.loadSp("assets\\card assets\\bonus button.png");
	bonusB.posSp(1550.f, 500.f);
	bonusB.scl(0.6f, 0.6f);
	// end

	endB.loadSp("assets\\card assets\\end turn.png");
	endB.posSp(1550.f, 800.f);
	endB.scl(0.6f, 0.6f);
    ////////////////////////////////////
	// initial points
	player1.pointsT.make_text("OPTIAlert-Medium.otf", to_string(player1.points));
	player1.pointsT.shape_text(72, Color::Green);
	player1.pointsT.text_pos(100.f, 900.f);
	//
	player2.pointsT.make_text("OPTIAlert-Medium.otf", to_string(player2.points));
	player2.pointsT.shape_text(72, Color::Red);
	player2.pointsT.text_pos(100.f, 200.f);
	////////////////

	endTemp.make_text("Game Of Squids.ttf", "#END^TURN#");
	endTemp.shape_text(32, Color::Red);
	endTemp.text_pos(800, 500);
	////////////////

	cardB.loadSp("assets\\card assets\\stamp.png");
	Info.loadSp("assets\\card assets\\info.png");
	Info.posSp(-40.f, -40.f);

}

////////////////////////////////////
// hight =242, width =173
void selectCard(Sprite& sp, int ind) {
	sp.setTexture(cards);
	sp.setTextureRect(IntRect(ind *173,0, 173, 242));

	sp.setOrigin(Vector2f(sp.getGlobalBounds().width / 2, sp.getGlobalBounds().height / 2));
}

////////////////////////////////////
void drawVec(vector< object >& v) {
	for (int i = 0; i < v.size(); i++) {
		win.draw(v[i].sp);
	}
}


////////////////////////////////////
void to_run_card() {
	int gameInd = 0;
	int phases = 0;
	int coinScore = 0;
	short turns = 0;
	bool test = 0;
	size_t damage = 0;
	short winner = 0;
	bool availB = 0;
	//////////////////////////////////
	Event e;
	while (win.isOpen()) {
		while (win.pollEvent(e)) {
			if (e.type == Event::KeyReleased) {
				if (e.key.code == Keyboard::Escape) {
					if (!to_run_options()) {
						window = 1;
						Sleep(200);
						return;
					}
				}
				else if (e.key.code == Keyboard::I) {
					test = !test;
				}
			}

		}
		//////////////////////////////////
		if (!test) {
			win.clear(Color::White);

			if (gameInd) {

				//drawings
				cardInner.drawTo(win);

				//////////////////////
				// check phases
				if (phases == 0) {// choose coin phase
					heroCoin.sp_pos(680.f, 540.f);
					devilCoin.sp_pos(1230.f, 540.f);
					win.draw(heroCoin.sp);
					win.draw(devilCoin.sp);

					if (mouse_l()) {
						if (mouse_intersects(win, devilCoin.sp)) {
							phases = 1;
							player1.coinNum = 0, player2.coinNum = 1;
						}
						else if (mouse_intersects(win, heroCoin.sp)) {
							player1.coinNum = 1, player2.coinNum = 0;
							phases = 1;
						}

					}
				}
				else if (phases == 1) { // show coins result
					bool coinRes;
					win.clear();
					cardInner.drawTo(win);
					// first coins guess
					heroCoin.sp_pos(500.f, 540.f);
					devilCoin.sp_pos(500.f, 540.f);
					coinRes = rand() % 2;
					if (coinRes) { coinScore++; win.draw(heroCoin.sp); }
					else { coinScore--; win.draw(devilCoin.sp); }
					win.display();
					Sleep(1000);


					//////////////////////
					// second coin

					win.clear();
					cardInner.drawTo(win);
					heroCoin.sp_pos(900.f, 540.f);
					devilCoin.sp_pos(900.f, 540.f);
					coinRes = rand() % 2;
					if (coinRes) { coinScore++; win.draw(heroCoin.sp); }
					else { coinScore--; win.draw(devilCoin.sp); }
					win.display();
					Sleep(1000);

					//////////////////////
					// third coin

					win.clear();
					cardInner.drawTo(win);
					heroCoin.sp_pos(1300.f, 540.f);
					devilCoin.sp_pos(1300.f, 540.f);
					coinRes = rand() % 2;
					if (coinRes) { coinScore++; win.draw(heroCoin.sp); }
					else { coinScore--; win.draw(devilCoin.sp); }
					win.display();
					Sleep(1000);
					phases = 2;
					////////////////////////

					// show player turn
					if (player1.coinNum) {//H
						if (coinScore == 1) {
							turns = 1;
						}
						else if (coinScore == 3) { turns = 2; }
						else if (coinScore == -3) turns = 4;
						else if(coinScore==-1)turns = 3;
					}
					else {//D
						if (coinScore == -1)turns = 1;
						else if (coinScore == -3)turns = 2;
						else if (coinScore == 1)turns = 3;
						else if (coinScore == 3)turns = 4;
					}
					phases = 2;
				}
				else if (phases == 2) { // show turn
					// show who has turn
					turnText.text_pos(700.f, -10.f);
					if (turns == 1) { // fplayer turn
						turnText.text_str("FIRST PLAYER");
					}
					else if (turns == 2) { // fplayer turn bonus

						turnText.text_str("FIRST PLAYER BONUS");
					}
					else if (turns == 3) { // splayer turn 

						turnText.text_str("SECOND PLAYER");
					}
					else if (turns == 4) { // splayer turn bonus

						turnText.text_str("SECOND PLAYER BONUS");
					}
					while (turnText.text.getPosition().y < 1100.f) {
						cardInner.drawTo(win);

						turnText.text.move(0, 2.5f);
						win.draw(turnText.text);
						win.display();

					}
					//////////////////////
					phases = 3;

					if (turns == 2 || turns == 4)availB = 1;
					else availB = 0;
				}

				else if (phases == 3) { // draw a card
				// get card index
					if (turns < 3) {// then first player draw
						// get current card to draw
						int ind = player1.handS.size();

						////////////////////////////
						float finalPlace = 460.f + ind * 200; // final postion 
						// random a card
						int cardInd = rand() % 7;
						object tempSp;
						selectCard(tempSp.sp, cardInd);
						player1.handS.push_back(tempSp);
						player1.handI.push_back(cardInd);
						player1.sel.push_back(0);
						/////////////////
						//// draw new card ////
						player1.handS.back().sp_pos(2000.f, 540.f);
						// move from right to left
						while (player1.handS.back().sp.getPosition().x > finalPlace) {
							player1.handS.back().sp.move(-3.f, 0);
							cardInner.drawTo(win);
							drawVec(player1.handS);
							drawVec(player2.handS);

							win.display();
						}
						///////////////////////////
						while (player1.handS.back().sp.getPosition().y < 920.f) {
							player1.handS.back().sp.move(0, 1.5f);
							cardInner.drawTo(win);
							drawVec(player2.handS);
							drawVec(player1.handS);

							win.display();

						}
						Sleep(2000);
					}
					else { // then second player draw
						// get current card to draw
						int ind = player2.handS.size();

						////////////////////////////
						float finalPlace = 460.f + ind * 200; // final postion 
						// random a card
						int cardInd = rand() % 7;
						object tempSp;
						selectCard(tempSp.sp, cardInd);
						player2.handS.push_back(tempSp);

						player2.handI.push_back(cardInd);
						player2.sel.push_back(0);
						/////////////////
						//// draw new card ////
						player2.handS.back().sp_pos(2000.f, 540.f);
						// move from right to left
						while (player2.handS.back().sp.getPosition().x > finalPlace) {
							player2.handS.back().sp.move(-3.f, 0);
							cardInner.drawTo(win);
							drawVec(player2.handS);
							drawVec(player1.handS);

							win.display();
						}
						///////////////////////////
						while (player2.handS.back().sp.getPosition().y > 250.f) {
							player2.handS.back().sp.move(0, -1.5f);
							cardInner.drawTo(win);
							drawVec(player2.handS);
							drawVec(player1.handS);

							win.display();
						}

						Sleep(2000);
					}

					phases = 4;

				}
				else if (phases == 4) { // game play, show available effects and other
				int choosedButton = 0;
					// buttons intersects
					if (mouse_intersects(win, bonusB.Sp())) {
						bonusB.scl(0.7f, 0.7f);
						if (availB) {
							if (mouse_l()) {
								choosedButton = 2;
							}
						}
					}
					else {
						bonusB.scl(0.6f, 0.6f);
					}
					//
					if (mouse_intersects(win, endB.Sp())) {
						endB.scl(0.7f, 0.7f);
						if (mouse_l()) {
							choosedButton = 3;
						}
					}
					else {
						endB.scl(0.6f, 0.6f);
					}
					//
					if (mouse_intersects(win, playButton.Sp())) {
						playButton.scl(0.7f, 0.7f);
						if (mouse_l()) {
							choosedButton = 1;
						}
					}
					else {
						playButton.scl(0.6f, 0.6f);
					}
					///////////////////////
					cardInner.drawTo(win);
					// drawings
					
					playButton.drawTo(win);
					endB.drawTo(win);
					bonusB.drawTo(win);
					// first player hand
					for (int i = 0; i < player1.handS.size(); i++) {
						if (mouse_intersects(win, player1.handS[i].sp)) {
							player1.handS[i].scale_sp(1.1f, 1.1f);
						}
						else {
							player1.handS[i].scale_sp(1.f, 1.f);
						}
						win.draw(player1.handS[i].sp);
					}
					// second player hand
					for (int i = 0; i < player2.handS.size(); i++) {
						if (mouse_intersects(win, player2.handS[i].sp)) {
							player2.handS[i].scale_sp(1.1f, 1.1f);
						}
						else {
							player2.handS[i].scale_sp(1.f, 1.f);
						}
						win.draw(player2.handS[i].sp);
					}
					win.draw(player1.pointsT.text);
					win.draw(player2.pointsT.text);
					//
					if (choosedButton == 3) {// endTurn
						phases = 7;
					}
					else if (choosedButton == 2) { // bonus
						phases = 6;
					}
					else if (choosedButton == 1) { // play
						phases = 5;
					}

				}
				else if (phases == 5) { // play
				//
				bool toEnd = 0;
				if (mouse_intersects(win, endB.Sp())) {
					endB.scl(0.7f, 0.7f);
					if (mouse_l())toEnd = 1;
				}
				else {
					endB.scl(0.6f, 0.6f);
				}
				//
				
				///////////////////////
				cardInner.drawTo(win);
				// drawings

				playButton.drawTo(win);
				endB.drawTo(win);
				bonusB.drawTo(win);
				// first player hand
				for (int i = 0; i < player1.sel.size(); i++) {
					if (!player1.sel[i]) {
						if (mouse_intersects(win, player1.handS[i].sp)) {
							player1.handS[i].scale_sp(1.1f, 1.1f);
							if (mouse_l() && turns < 3) {
								player1.sel[i] = 1;
							}
							else {
								player1.sel[i] = 0;

							}
						}
						else {
							player1.handS[i].scale_sp(1.f, 1.f);
						}
					}
					win.draw(player1.handS[i].sp);
				}
				// second player hand
				for (int i = 0; i < player2.sel.size(); i++) {
					if (!player2.sel[i]) {
						if (mouse_intersects(win, player2.handS[i].sp)) {
							player2.handS[i].scale_sp(1.1f, 1.1f);
							if (mouse_l() && turns > 2) {
								player2.sel[i] = 1;
							}
							else {
								player2.sel[i] = 0;

							}
						}
						else {
							player2.handS[i].scale_sp(1.f, 1.f);
						}
					}
					win.draw(player2.handS[i].sp);
				}
				win.draw(player1.pointsT.text);
				win.draw(player2.pointsT.text);
				////////////////////////////

				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					// go check pattern
					phases = 8;
				}



				if (toEnd)phases = 7;

                }

				///////////////////////////////////
				else if (phases == 6) { // bonus
				bool isSelected = 0;
				int choosedButton = 0;
				
				//
				if (mouse_intersects(win, endB.Sp())) {
					endB.scl(0.7f, 0.7f);
					if (mouse_l()) {
						choosedButton = 3;
					}
				}
				else {
					endB.scl(0.6f, 0.6f);
				}
				//
				if (mouse_intersects(win, playButton.Sp())) {
					playButton.scl(0.7f, 0.7f);
					if (mouse_l()) {
						choosedButton = 1;
					}
				}
				else {
					playButton.scl(0.6f, 0.6f);
				}

				///////////////////////
				cardInner.drawTo(win);
				// drawings
				playButton.drawTo(win);
				endB.drawTo(win);
				bonusB.drawTo(win);
				// first player hand
				for (int i = 0; i < player1.handS.size(); i++) {
					if (!player1.sel[i]) {
						if (mouse_intersects(win, player1.handS[i].sp)) {
							player1.handS[i].scale_sp(1.1f, 1.1f);
							if (turns > 2) {
								if (mouse_l()) {
									player1.sel[i] = 1;
									isSelected = 1;
								}
							}
						}
						else {
							player1.handS[i].scale_sp(1.f, 1.f);
						}
					}
					win.draw(player1.handS[i].sp);
				}
				// second player hand
				for (int i = 0; i < player2.handS.size(); i++) {
					if (!player2.sel[i]) {
						if (mouse_intersects(win, player2.handS[i].sp)) {
							player2.handS[i].scale_sp(1.1f, 1.1f);
							if (turns < 3) {
								if (mouse_l()) {
									player1.sel[i] = 1;
								}
							}
						}
						else {
							player2.handS[i].scale_sp(1.f, 1.f);
						}
					}
					win.draw(player2.handS[i].sp);
				}
				win.draw(player1.pointsT.text);
				win.draw(player2.pointsT.text);
				//
				///////////////////////////////

				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					if (isSelected) {
						if (turns < 3) {
							// then destroy from second player hand
							int it = 0;
							for (it; it < player2.sel.size(); it++) {
								if (player2.sel[it]) {
									player2.sel[it] = 0;
									break;
								}
							}
							for (int i=it; i < player2.sel.size()-1; i++) {

								Vector2f temp = player2.handS[i].sp.getPosition();
								player2.handS[i].sp.setPosition(player2.handS[i + 1].sp.getPosition());
								player2.handS[i].sp.setPosition(temp);

								swap(player2.handI[i], player2.handI[i + 1]);
								swap(player2.handS[i], player2.handS[i + 1]);


							}
							player2.handI.pop_back();
							player2.handS.pop_back();
							player2.sel.pop_back();
							/////////////////////////////////////////
							// then go to phase play
							phases = 4;
							availB = 0;
						}
						else{

							// then destroy from first player hand
							int it = 0;
							for (it; it < player1.sel.size(); it++) {
								if (player1.sel[it]) {
									player1.sel[it] = 0;
									break;
								}
							}
							for (int i = it; i < player1.sel.size() - 1; i++) {
								Vector2f temp = player1.handS[i].sp.getPosition();
								player1.handS[i].sp.setPosition(player1.handS[i+1].sp.getPosition());
								player1.handS[i].sp.setPosition(temp);
								swap(player1.handI[i], player1.handI[i + 1]);
								swap(player1.handS[i], player1.handS[i + 1]);


							}
							player1.handI.pop_back();
							player1.handS.pop_back();
							player1.sel.pop_back();
							/////////////////////////////////////////
							// then go to phase play
							phases = 4;
							availB = 0;
						}

					}
					else {
						if (turns < 3) {
							if (player1.handI.size() < 6) {
								// draw new card
								// get current card to draw
								int ind = player1.handS.size();

								////////////////////////////
								float finalPlace = 460.f + ind * 200; // final postion 
								// random a card
								int cardInd = rand() % 7;
								object tempSp;
								selectCard(tempSp.sp, cardInd);
								player1.handS.push_back(tempSp);
								player1.handI.push_back(cardInd);
								player1.sel.push_back(0);
								/////////////////
								//// draw new card ////
								player1.handS.back().sp_pos(2000.f, 540.f);
								// move from right to left
								while (player1.handS.back().sp.getPosition().x > finalPlace) {
									player1.handS.back().sp.move(-3.f, 0);
									cardInner.drawTo(win);
									drawVec(player1.handS);
									drawVec(player2.handS);

									win.display();
								}
								///////////////////////////
								while (player1.handS.back().sp.getPosition().y < 920.f) {
									player1.handS.back().sp.move(0, 1.5f);
									cardInner.drawTo(win);
									drawVec(player2.handS);
									drawVec(player1.handS);

									win.display();

								}
								Sleep(2000);
							}
							else {
								// end turn
								phases = 4;
								availB = 0;
							}
						}
						else {
							if (player2.handI.size() < 6) {
								// draw new card
														// get current card to draw
								int ind = player2.handS.size();

								////////////////////////////
								float finalPlace = 460.f + ind * 200; // final postion 
								// random a card
								int cardInd = rand() % 7;
								object tempSp;
								selectCard(tempSp.sp, cardInd);
								player2.handS.push_back(tempSp);

								player2.handI.push_back(cardInd);
								player2.sel.push_back(0);
								/////////////////
								//// draw new card ////
								player2.handS.back().sp_pos(2000.f, 540.f);
								// move from right to left
								while (player2.handS.back().sp.getPosition().x > finalPlace) {
									player2.handS.back().sp.move(-3.f, 0);
									cardInner.drawTo(win);
									drawVec(player2.handS);
									drawVec(player1.handS);

									win.display();
								}
								///////////////////////////
								while (player2.handS.back().sp.getPosition().y > 250.f) {
									player2.handS.back().sp.move(0, -1.5f);
									cardInner.drawTo(win);
									drawVec(player2.handS);
									drawVec(player1.handS);

									win.display();
								}

								Sleep(2000);
							}
							else {
								// end turn
								phases = 4;
								availB = 0;
							}
						}
					}
				}
				//////////////////////////////
				if (choosedButton == 3) {// endTurn
					phases = 7;

				}
				
				else if (choosedButton == 1) { // play
					phases = 5; availB = 0;
				}


				}
				else if (phases == 7) {
				// end turn animation
				phases = 0;
				size_t scaller = 32;
				while (scaller < 100) {
					
					cardInner.drawTo(win);
					scaller += 2;
					endTemp.text.setCharacterSize(scaller);
					win.draw(endTemp.text);
					win.display();
					Sleep(30);
				}
                }
				else if (phases == 8) {
				// play animation
				float theta = 0.f;
				while (theta < 350.f) {
					theta += 2.f;
					cardB.posSp(850 + 200 * cos(theta), 520 + 200 * sin(theta));

					win.clear();
					cardInner.drawTo(win);
					cardB.drawTo(win);

					win.display();
					Sleep(20);
				}
				
				cardB.posSp(-2000, -2000);
				phases = 9;// go check pattern

                }
				else if (phases == 9) {
				// (repeat-1)*n
				short effect = 0;
				if (turns < 3) {
					//////get selected cards/////
					vector<int>selItem;
					for (int i = 0; i < player1.sel.size(); i++) {
						if (player1.sel[i])selItem.push_back(player1.handI[i]);
					}
					//////////////////////
					
					///////efect 1////////
					bool repeated = 1;
					for (int i = 1; i < selItem.size(); i++) {
						if (selItem[i] != selItem[i - 1]) { repeated = 0; break; }
					}
					//
					if (repeated) {
						damage = (selItem.size() - 1) * 300;
						effect = 1;
					}
					//////////////////////
					///////efect 2////////

					if (selItem.size() == 3) {
						bool shield[3] = {};
						bool isShield = 1;

						for (int i = 0; i < selItem.size(); i++) {
							shield[selItem[i]] = 1;
						}
						for (int i = 0; i < 3; i++) {
							isShield = shield[i];
						}
						//
						if (isShield) {
							effect = 2;
						}
					}
						//////////////////////
						///////efect 3////////
						// spear
						if (selItem.size()==3) {
							bool spear[3] = {};
							for (int i = 0; i < 3; i++) {
								spear[max(selItem[i] - 4, 0)] = 1;
							}
							bool isSpear = 1;
							for (int i = 0; i < 3; i++) {
								isSpear = spear[i];
							}
							// 
							if (isSpear) {
								effect = 3;
							}
						}

						//////////////////////
						///////efect 4////////
						// army 
						if (selItem.size() == 6) {
							bool isArmy = 1;
							bool army[7] = {};
							for (int i = 0; i < 6; i++) {
								army[selItem[i]] = 1;
							}
							for (int i = 0; i < 3; i++) {
								isArmy = army[i];
							}
							for (int i = 4; i < 7; i++) {
								isArmy = army[i];
							}
							if (isArmy) {
								effect = 4;
							}
						}
						//////////////////////
						///////efect 5////////
						// yang
						if (selItem.size() == 4) {
							bool yang[7] = {};
							for (int i = 0; i < 4; i++) {
								
								yang[selItem[i]] = 1;
							}
							if (yang[0] && yang[1] && yang[6] && yang[5]) {
								effect = 5;
							}

						}



					
				}
				else {
					//////get selected cards/////
					vector<int>selItem;
					for (int i = 0; i < player2.sel.size(); i++) {
						if (player2.sel[i])selItem.push_back(player2.handI[i]);
					}
					//////////////////////

					///////efect 1////////
					bool repeated = 1;
					for (int i = 1; i < selItem.size(); i++) {
						if (selItem[i] != selItem[i - 1]) { repeated = 0; break; }
					}
					//
					if (repeated) {
						damage = (selItem.size() - 1) * 300;
						effect = 1;
					}
					//////////////////////
					///////efect 2////////

					if (selItem.size() == 3) {
						bool shield[3] = {};
						bool isShield = 1;

						for (int i = 0; i < selItem.size(); i++) {
							shield[selItem[i]] = 1;
						}
						for (int i = 0; i < 3; i++) {
							isShield = shield[i];
						}
						//
						if (isShield) {
							effect = 2;
						}
					}
					//////////////////////
					///////efect 3////////
					// spear
					if (selItem.size() == 3) {
						bool spear[3] = {};
						for (int i = 0; i < 3; i++) {
							spear[max(selItem[i] - 4, 0)] = 1;
						}
						bool isSpear = 1;
						for (int i = 0; i < 3; i++) {
							isSpear = spear[i];
						}
						// 
						if (isSpear) {
							effect = 3;
						}
					}

					//////////////////////
					///////efect 4////////
					// army 
					if (selItem.size() == 6) {
						bool isArmy = 1;
						bool army[7] = {};
						for (int i = 0; i < 6; i++) {
							army[selItem[i]] = 1;
						}
						for (int i = 0; i < 3; i++) {
							isArmy = army[i];
						}
						for (int i = 4; i < 7; i++) {
							isArmy = army[i];
						}
						if (isArmy) {
							effect = 4;
						}
					}
					//////////////////////
					///////efect 5////////
					// yang
					if (selItem.size() == 4) {
						bool yang[7] = {};
						for (int i = 0; i < 4; i++) {

							yang[selItem[i]] = 1;
						}
						if (yang[0] && yang[1] && yang[6] && yang[5]) {
							effect = 5;
						}

					}




				}
				/////////////////////
				if (turns < 3) {
					if (effect == 1) { // repeat
						player2.points -= damage;
						player2.points = max(player2.points, 0);
					}
					else if (effect==2) {// shield
						player1.points += 1000;
					}
					else if (effect == 3) {// spear

						player2.points -= 1000;
						player2.points = max(player2.points, 0);
					}
					else if (effect == 4) { // army
						player2.points = 0;
					}
					else if (effect == 5) { // Yang
						player1.points += 500;
						player2.handI.clear();
						player2.handS.clear();
						player2.sel.clear();
					}
				}
				else {
					if (effect == 1) { // repeat
						player1.points -= damage;
						player1.points = max(player1.points, 0);
					}
					else if (effect == 2) {// shield
						player2.points += 1000;
					}
					else if (effect == 3) {// spear

						player1.points -= 1000;
						player1.points = max(player1.points, 0);
					}
					else if (effect == 4) { // army
						player1.points = 0;
					}
					else if (effect == 5) { // Yang
						player2.points += 500;
						player1.handI.clear();
						player1.handS.clear();
						player1.sel.clear();
					}
				}
				////////////////////////
				// clear player hand
				if (turns < 3) {
					vector<int>toDelete;
					for (int i = 0; i < player1.sel.size(); i++) {
						if (player1.sel[i])
							toDelete.push_back(i);
					}
					for (int i = toDelete.size() - 1; i > -1; i--) {
						player1.handI.erase(player1.handI.begin() + toDelete[i]);
						player1.handS.erase(player1.handS.begin() + toDelete[i]);
						player1.sel.erase(player1.sel.begin() + toDelete[i]);
					}
					for (int i = 0; i < player1.handS.size(); i++) {
						player1.handS[i].sp_pos(460.f + 200 * i, 920.f);
					}
					toDelete.clear();
				}
				else {

					vector<int>toDelete;
					for (int i = 0; i < player2.sel.size(); i++) {
						if (player2.sel[i])
							toDelete.push_back(i);
					}
					for (int i = toDelete.size() - 1; i > -1; i--) {
						player2.handI.erase(player2.handI.begin() + toDelete[i]);
						player2.handS.erase(player2.handS.begin() + toDelete[i]);
						player2.sel.erase(player2.sel.begin() + toDelete[i]);
					}

					for (int i = 0; i < player2.handS.size(); i++) {
						player2.handS[i].sp_pos(460.f + 200 * i, 250.f);
					}
					toDelete.clear();
				}
				//////////////////////
				phases = 7;//end turn

                }
			}
			else {



				cardWall.drawTo(win);
				if (playB.color_mouse(win, Color::Blue, Color::Magenta))gameInd = 1;

				win.draw(playB.text);



			}

			win.display();


		}
		else {
		/*testo.setPosition(800, 500);
		float theta = 0.f;
		while (theta<360.f) {
			theta += 2.f;
			testo.setPosition(800+100*cos(theta),500+100* sin(theta));
			win.clear();


			win.draw(testo);

			win.display();
			Sleep(20);
		}*/
		win.clear();
		Info.drawTo(win);
		win.display();

	    }
		if (winner==1) {
			turnText.alert(win, "Player#1 Winner", Color::Blue, 700, 480);
			player2.sel.clear();
			player2.handI.clear();
			player2.handS.clear();
			player1.handI.clear();
			player1.handS.clear();
			player1.sel.clear();

			player1.pointsT.text_str("4000");
			player2.pointsT.text_str("4000");
			Sleep(100);
			return ;
		}
		else if(winner==2) {

			turnText.alert(win, "Player#2 Winner", Color::Blue, 700, 480);
			player2.sel.clear();
			player2.handI.clear();
			player2.handS.clear();
			player1.handI.clear();
			player1.handS.clear();
			player1.sel.clear();

			player2.pointsT.text_str("4000");
			player1.pointsT.text_str("4000");
			Sleep(100);
			return;
		}
		///////////check winner/////////
		if (player1.points == 0) {
			winner=1;
		}
		if(player2.points == 0) {
			winner = 2;
		}
		///////////////////////////////
		////////////check hand////////
		if (player1.handI.size() >= 6) {
			player1.handI.clear();
			player1.handS.clear();
			player1.sel.clear();
		}
		if (player2.handI.size() >= 6) {
			player2.sel.clear();
			player2.handI.clear();
			player2.handS.clear();
		}
		//////////////////////////////
		player1.pointsT.text_str(to_string(player1.points));

		player2.pointsT.text_str(to_string(player2.points));
	}
	





}