#pragma once

object ping1, computer, p_ball, border1, border2;
object ping_score,pingwall;
//---------------------------------------------------------------------------------------------
long long cnt = 0, score_player = 0, score_computer = 0;

void ping_initial() {
	// ball
	p_ball.shape_entity(0, Color::White, 25.f, 25.f);
	// player one serve
	ping1.shape_entity(1, Color::Blue, 50.f, 200.f);
	// player two serve
	computer.shape_entity(1, Color::Green, 50.f, 200.f);
	// borders
	border1.shape_entity(1, Color::Red, 1920.f, 5.f);
	border2.shape_entity(1, Color::Red, 1920.f, 5.f);
	//
	border1.recta.setPosition(Vector2f(960.f, 0.f)); 
	border2.recta.setPosition(Vector2f(960.f, 1080.f));
	// 
	p_ball.circle.setPosition(Vector2f(960.f, 540.f));
	//
	ping1.recta.setPosition(Vector2f(80.f, 540.f));
	computer.recta.setPosition(Vector2f(1840.f, 540.f));
}
//------------

float ballx = 5.f, bally = 0.f, shift = 0.1f;
//
Vector2f ping1m, ping2m;
//////////////
void initial_ping_score() {
	ping_score.make_text("MorningRainbow.ttf", "0 - 0");
	ping_score.text_pos(960.f, 100.f);
	ping_score.shape_text(72,Color::Yellow,0,0);
	ping1m.x = 0, ping1m.y = 0; ping2m.x = 0, ping2m.y = 0;

}

void to_run_pingpong() {
	
		if (cnt%5==0) {
			ballx = ballx+0.5f ; shift -= 0.02f;
		}
		//------------------------------------------------
		// -------------for left player-------------------
		if (Keyboard::isKeyPressed(Keyboard::W)) { // UP
			ping1.recta.move(Vector2f(0.f, -10)); ping1m.y = -5;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) { // DOWN
			ping1.recta.move(Vector2f(0.f, 10)); ping1m.y = 5;
		}
		//-------------------------------------------------
		//--------------for second player------------------
		if (bally > 0) {
			computer.recta.move(Vector2f(0, bally-shift));
		}
		else if(bally<0) {
			computer.recta.move(Vector2f(0, bally + shift));

		}
		//--------------------------------------------------
		// -------detec collision
		if (ping1.recta.getGlobalBounds().intersects(p_ball.circle.getGlobalBounds())) {
			ballx = ballx * -1;
			if (ping1m.y > 0) {
				bally = abs(ballx);
			}
			else if (ping1m.y < 0) {
				bally = -1 * abs(ballx);
			}
		//	bally = ping1m.y;
		}
		else if (computer.recta.getGlobalBounds().intersects(p_ball.circle.getGlobalBounds())) {
			ballx = ballx * -1;
			if (cnt % 3 == 0)
				bally = bally * -1;
			else
				bally = bally;
			cnt++;
		}
		else if (border1.recta.getGlobalBounds().intersects(p_ball.circle.getGlobalBounds())|| border2.recta.getGlobalBounds().intersects(p_ball.circle.getGlobalBounds())) {
			ballx = ballx ;
			bally = bally*-1;
		}
		//
		// border and ping collision
		if (ping1.recta.getGlobalBounds().intersects(border1.recta.getGlobalBounds())) {
			ping1.recta.move(Vector2f(0, 5));
		}
		if (ping1.recta.getGlobalBounds().intersects(border2.recta.getGlobalBounds())) {
			ping1.recta.move(Vector2f(0, -5));
		}
		if (computer.recta.getGlobalBounds().intersects(border1.recta.getGlobalBounds())) {
			computer.recta.move(Vector2f(0, 3));
		}
		if (computer.recta.getGlobalBounds().intersects(border2.recta.getGlobalBounds())) {
			computer.recta.move(Vector2f(0, -3));
		}
		//--------------------------
		
		// ball motion
		p_ball.circle.move(Vector2f(ballx, bally));
		//
		//-----------------check point
		if (p_ball.circle.getPosition().x < 0) {// then computer scores
			score_computer++;
			p_ball.circle.setPosition(Vector2f(960.f, 540.f));
			ballx = -3; bally = 0;
				computer.recta.setPosition(Vector2f(1840.f, 540.f));
				shift = 0.07;
				cnt = 0;
		}
		else if (p_ball.circle.getPosition().x > 1920) {// then player scores
			score_player++;
			p_ball.circle.setPosition(Vector2f(960.f, 540.f));
			ballx = 3; bally = 0;
			computer.recta.setPosition(Vector2f(1840.f, 540.f));
			shift = 0.07;
			cnt = 0;
		}
		ping_score.text_str(to_string(score_player) + " - " + to_string(score_computer));

		//----------------------------
		// drawings
		win.clear();
		//
		if(pingwall.todraw)
		win.draw(pingwall.sp);
		win.draw(ping_score.text);
		win.draw(ping1.recta);
		win.draw(computer.recta);
		win.draw(border1.recta);
		win.draw(border2.recta);
		win.draw(p_ball.circle);
		//
		win.display();
		//
		// reset
		ping1m.x = 0, ping1m.y = 0, ping2m.x = 0, ping2m.y = 0;
		if (cnt % 4 == 0)cnt++;

		if (score_computer > 7) {
			score_computer = 0;
			score_player = 0;
			if (play_again(win)) {
				window = window;
			}
			else {
				Sleep(200);
				window = 1;
			};
		}
		else if (score_player > 7) {
			score_computer = 0;
			score_player = 0;
			if (play_again(win)) {
				window = window;
			}
			else {
				Sleep(200);
				window = 1;
			}
		}
		///////////////////////////////////////////
		
}
