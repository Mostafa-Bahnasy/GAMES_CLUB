#pragma once




//
Sprite chatBack;
Texture chatBackT;
object recieveSp, sendSp, adminSp;
Animation chatPlayer;
object chatWindow[3];
Textbox typing(32,Color(219, 70,236),false);
Font chatFont;
Text_C namer, chater;
Vector<pairSp>skips;
//

void inititialChat() {
	// background
	chatBackT.loadFromFile("assets\\chat\\Asset 11-min.png");
	chatBackT.setSmooth(1);
	chatBack.setTexture(chatBackT);
	/////////////

	// player chat
	chatPlayer.setWidth(32);
	chatPlayer.setHight(48);
	chatPlayer.setLimitX(4);
	chatPlayer.setLimitY(4);
	chatPlayer.setMoveX(0.5f);
	chatPlayer.setMoveY(0.5f);
	
	chatPlayer.texture.loadFromFile("assets\\chat\\playerChat.png");
	chatPlayer.texture.setSmooth(1);
	chatPlayer.sp.setTexture(chatPlayer.texture);
	chatPlayer.sp.setPosition(Vector2f(1000,1000));
	chatPlayer.sp.setScale(2.5, 2.5);
	
	////////////////

	//  chat window
	for (int i = 6; i < 9; i++) {
		chatWindow[i - 6].make_sp("assets\\chat\\Asset " + to_string(i) + ".png");
	}
	///////////////
	chatFont.loadFromFile("WeretigerRegular-vWjZ.ttf");
	typing.setFont(chatFont);
	typing.setLimit(1,14);
	///////////////
	
	// chat boxes
	recieveSp.make_sp("assets\\chat\\Asset 11.png");
	recieveSp.make_text("alfont_com_arial-1.ttf", "[MESSEGES BOX]");
	recieveSp.shape_text(32, Color::Cyan);
	recieveSp.sp_pos(900.f, 0);
	recieveSp.text_pos(1100.f, 15.f);
	//
	sendSp.make_sp("assets\\chat\\3310.png");
	sendSp.make_text("alfont_com_arial-1.ttf", "[SENDER BOX]");
	sendSp.shape_text(32, Color::Cyan);
	sendSp.scale_sp(0.6f, 0.6f);
	sendSp.text_pos(200.f, 50.f);
	//
	adminSp.make_sp("assets\\chat\\Asset 12.png");
	adminSp.make_text("alfont_com_arial-1.ttf", "[ADMIN BOX]");
	adminSp.shape_text(32, Color::Cyan);
	adminSp.sp.setOrigin(Vector2f(adminSp.sp.getLocalBounds().width, adminSp.sp.getLocalBounds().height));
	adminSp.sp_pos(1920.f, 1080.f);
	adminSp.text.setPosition(Vector2f(adminSp.sp.getPosition().x - 200, adminSp.sp.getPosition().y - 200));
//////////////////////////////////
	namer.make_text("WeretigerRegular-vWjZ.ttf", "");
	namer.shape_text(32, Color::Black);
	namer.text_pos(360, 820);

	//
	chater.make_text("WeretigerRegular-vWjZ.ttf", "");
	chater.shape_text(32, Color(219, 70, 236));

	chater.text_pos(490, 820);
	////////////////////////

}
//////////////////


/////////////////
void to_run_chatRoom() {
	Clock clock;
	Event ev;
	typing.setSelected(1);
	bool inBox = 0;
	int recieveInd = 0;
	bool skipper = 1;
	while (win.isOpen()) {

		while (win.pollEvent(ev)) {
			if (ev.type == Event::KeyReleased) {
				if (ev.key.code == Keyboard::Escape&&inBox) {
					inBox = 0;
					skipper = 0;
					Sleep(100);
				}
				else if (ev.key.code == Keyboard::Escape) {
					win.clear();
					window = 1;
					Sleep(100);
					return;
				}
				
			}
			if (ev.type == Event::TextEntered) {
				typing.typedOn(ev);

			}

		}

		////////////////////////////////////////////
		if (arr_acc[ind].nickName=="") { // first phase
			alert.text_str("WELCOME IN CHATROOM\nPLEASE TYPE YOUR NICKNAME:");
			typing.setPosition(Vector2f(alert.text.getPosition().x+190, alert.text.getPosition().y+14));
			
			win.clear();
			win.draw(alert.text);
			typing.drawTo(win);
			win.display();
			// check if user entered nickname
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				if (typing.getText().size()>2) {
					arr_acc[ind].nickName = typing.getText();
					typing.clear_text();

					chatPlayer.animate(2);
					

				}
			}
			

		}
		/////////////////////////////////////////////

		/////////////////////////////////////////////
		// secondphase game world
		else {
			if (arr_acc[ind].chatBoxInd < 0) { // then choose chat window
				


				//////drawings
				win.clear(Color::White);
				for (int i = 2; i > -1; i--) {
					chatWindow[i].sp_pos(200.f, 250 * i);
					chatWindow[i].scale_sp(0.5f, 0.3f);
					// collision
					if (mouse_intersects(win, chatWindow[i].sp)) {
						chatWindow[i].scale_sp(0.6f,0.6f);
						if (mouse_l()) {
							arr_acc[ind].chatBoxInd = i;
						}
					}
					////////////
					win.draw(chatWindow[i].sp);
				}
				win.display();
				if (arr_acc[ind].chatBoxInd > -1) {
					alert.text_str("["+arr_acc[ind].nickName+"]");
					alert.shape_text(32, Color::Black);
					alert.text_pos(380, 830);
					
					Sleep(200);
				}
			}
			else {
				if (!inBox) {
					if (Keyboard::isKeyPressed(Keyboard::W)) {
						if (chatPlayer.getIndY() == 3) {
							if (clock.getElapsedTime().asSeconds() > 0.1) {
								clock.restart();
								chatPlayer.animate(chatPlayer.getIndX() + 1);
							}
						}
						else
							chatPlayer.setIndY(3);

						if (chatPlayer.sp.getPosition().y > 30)
							chatPlayer.sp.move(0, -5);
					}
					else if (Keyboard::isKeyPressed(Keyboard::S)) {
						if (chatPlayer.getIndY() == 0) {
							if (clock.getElapsedTime().asSeconds() > 0.1) {
								clock.restart();
								chatPlayer.animate(chatPlayer.getIndX() + 1);
							}
						}
						else
							chatPlayer.setIndY(0);
						if (chatPlayer.sp.getPosition().y < 1960)
							chatPlayer.sp.move(0, 5);
					}
					else if (Keyboard::isKeyPressed(Keyboard::A)) {
						if (chatPlayer.getIndY() == 1) {
							if (clock.getElapsedTime().asSeconds() > 0.1) {
								clock.restart();
								chatPlayer.animate(chatPlayer.getIndX() + 1);
							}
						}
						else
							chatPlayer.setIndY(1);
						if (chatPlayer.sp.getPosition().x > 40)
							chatPlayer.sp.move(-5, 0);
					}
					else if (Keyboard::isKeyPressed(Keyboard::D)) {
						if (chatPlayer.getIndY() == 2) {
							if (clock.getElapsedTime().asSeconds() > 0.1) {
								clock.restart();
								chatPlayer.animate(chatPlayer.getIndX() + 1);
							}
						}
						else
							chatPlayer.setIndY(2);
						if (chatPlayer.sp.getPosition().x < 1960)
							chatPlayer.sp.move(5, 0);
					}
					//////////////////////////////////
					///colision
					if (chatPlayer.sp.getGlobalBounds().intersects(adminSp.sp.getGlobalBounds())) {
						adminSp.todraw = 1;
						adminSp.scale_sp(1.2, 1.2);
					}
					else {
						adminSp.todraw = 0;
						adminSp.scale_sp(1, 1);

					}
					//
					if (chatPlayer.sp.getGlobalBounds().intersects(sendSp.sp.getGlobalBounds())) {
						sendSp.todraw = 1;
						sendSp.scale_sp(0.8f, 0.8f);
					}
					else {
						sendSp.todraw = 0;
						sendSp.scale_sp(0.6f, 0.6f);

					}
					//
					if (chatPlayer.sp.getGlobalBounds().intersects(recieveSp.sp.getGlobalBounds())) {
						recieveSp.todraw = 1;
						recieveSp.scale_sp(1.2, 1.2);
					}
					else {
						recieveSp.todraw = 0;
						recieveSp.scale_sp(1, 1);

					}

					/////////////////



					////drawings////
					win.clear();
					win.draw(chatBack);
					//
					win.draw(sendSp.sp);
					if (sendSp.todraw)win.draw(sendSp.text);
					//
					win.draw(adminSp.sp);
					if (adminSp.todraw)win.draw(adminSp.text);
					//
					win.draw(recieveSp.sp);
					if (recieveSp.todraw)win.draw(recieveSp.text);
					//
					win.draw(chatPlayer.sp);
					win.display();

					////////////////////
				}

				///check if entered any box
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					// check box
					if (recieveSp.todraw) {
						inBox = 1;

						Sleep(200);
						typing.clear_text();
						typing.setColor(Color::White);
					}
					else if (sendSp.todraw) {
						inBox = 1;

						Sleep(200);
						typing.clear_text();
						typing.setColor(Color::White);
					}
					else if (adminSp.todraw) {
						inBox = 1;

						Sleep(200);
						typing.clear_text();
						typing.setColor(Color::White);
					}
				}
				/////////////
				// inside boxes
				if (inBox) {
					typing.setSelected(1);
					chatWindow[arr_acc[ind].chatBoxInd].scale_sp(1, 1);
					chatWindow[arr_acc[ind].chatBoxInd].sp_pos(0,200);
					typing.setLimit(1, 40);

					///////////////////
					if (adminSp.todraw) {
						typing.setPosition({480, 820});
						win.clear(Color::White);
						win.draw(chatWindow[arr_acc[ind].chatBoxInd].sp);
						win.draw(alert.text);
						typing.drawTo(win);
						win.display();
						if (Keyboard::isKeyPressed(Keyboard::Enter)) {// take last string
							if (typing.getText() != "")
							adminChat.push_back({  alert.text.getString(),typing.getText(),arr_acc[ind].chatBoxInd});
							
						}
					}
					else if (sendSp.todraw) {
						typing.setPosition({ 480, 820 });
						win.clear(Color::White);
						win.draw(chatWindow[arr_acc[ind].chatBoxInd].sp);
						win.draw(alert.text);
						typing.drawTo(win);
						win.display();
						if (Keyboard::isKeyPressed(Keyboard::Enter)) {// take last string
							if(typing.getText()!="")
							glopalChat.push_back({ alert.text.getString(),typing.getText() ,arr_acc[ind].chatBoxInd });

						}
					}
					else if (recieveSp.todraw) {




						/////drawings
						win.clear(Color::White);
						
						win.draw(chatWindow[glopalChat[recieveInd].chatBoxInd].sp);
						chater.text_str(glopalChat[recieveInd].mess);
						namer.text_str(glopalChat[recieveInd].nm);
						win.draw(namer.text);
						win.draw(chater.text);
						win.display();
						//////////////

						// scrolling
						if (Keyboard::isKeyPressed(Keyboard::Left)) {
							recieveInd = max(recieveInd - 1, 0); 
						}
						else if (Keyboard::isKeyPressed(Keyboard::Right)) {
							recieveInd = min((unsigned int)1 + recieveInd, glopalChat.size()-1); 
						}
					

					}
				}
			}
		}




	}



}

