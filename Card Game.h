#pragma once

pairSp cardWall, cardInner;
object heroCoin, devilCoin;
vector< object >cards(7); // 7 
vector<short>fPlayer, Splayer;
Text_C playB;
Text_C fPlayerP, sPlayerP;

void initial_cards() {
	// walls
	cardWall.loadSp("assets\\card assets\\wallpaperflare.com_wallpaper-min.jpg");
	cardInner.loadSp("assets\\card assets\\875040-min.jpg");
	////////
	// coins
	heroCoin.make_sp("assets\\card assets\\Asset 12-min.png");
	devilCoin.make_sp("assets\\card assets\\Asset 10-min.png");
	/////////
	// cards
	/*for (int i = 0; i < 7; i++) {
		cards[i].make_sp("card assets\\ (" + to_string(i+1) + ").png");
	}*/
	/////////

	playB.make_text("Game Of Squids.ttf","PLAY");
	playB.shape_text(60, Color::Blue);
	playB.text_pos(350, 680);
}





void to_run_card() {
	
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
			}
		}
		//////////////////////////////////







		win.clear();
		cardWall.drawTo(win);
		if (mouse_intersects(win, playB.text)) {
			playB.text_color(Color::Cyan);
			win.draw(playB.text);
		}
		else {
			playB.text_color(Color::Blue);

			win.draw(playB.text);

		}
		win.display();

	}







}