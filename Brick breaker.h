int remainBricks = 20;
//--------------------------------------//
bool lose = false;
Texture t12,  t32, t42;
Font fonti;
float dx = 10, dy = 9;
Sprite sball,  spaddle;
Sprite block[20];

int cntr = 0;

bool isCollide(Sprite& s1, Sprite& s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

void setBrick() {
	

	fonti.loadFromFile("OrganicalPersonalUseBoldItalic-2O6xe.ttf");
	t12.loadFromFile("assets\\brick\\ball.png");
	t32.loadFromFile("assets\\brick\\paddle.png");
	t42.loadFromFile("assets\\brick\\block03.png");
	//smooth
	t12.setSmooth(1);
	t32.setSmooth(1);
	t42.setSmooth(1);
	//-----------------------------------------//GAME'S SPRITES AND THEIR POSITION
	sball.setTexture(t12),spaddle.setTexture(t32);
	spaddle.setPosition(300 * 2, 420 * 2);
	sball.setPosition(300 * 2, 300 * 2);


	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 4; j++)
		{
			block[cntr].setTexture(t42);
			block[cntr].setPosition(200+i * 43 * 2, 50+j * 20 * 2);
			block[cntr].setScale(Vector2f(2.f, 2.f));
			cntr++;
		}

	//---------------scales--------------------
	sball.setScale(Vector2f(2.f, 2.f));
	spaddle.setScale(Vector2f(2.f, 2.f));

}

void to_run_breaker()
{
	//---------------------------------//WINDOW SIZE AND TIME SETTINGS
	Sleep(30);

		//---------------------------------------------
	bool isColl = 0;

        //----------------------------------------BALL MOVEMENT
		Vector2f b = sball.getPosition();
		if (b.x < 0 || b.x>600 ) dx = -dx;
		if (b.y < 0 || b.y>450 * 2) dy = -dy;
		//----------------------------------------//PADLE MOVMENT
		if (Keyboard::isKeyPressed(Keyboard::Right)) spaddle.move(12, 0);
		if (Keyboard::isKeyPressed(Keyboard::Left)) spaddle.move(-12, 0);

		Vector2f paddle = spaddle.getPosition();
		if (paddle.x > 432 * 2)
		{
			spaddle.setPosition(431 * 2, 420 * 2);
		}
		if (paddle.x < 0)
		{
			spaddle.setPosition(0, 420 * 2);
		}
		//-------------------------------------//BALL WITH (BLOCKS AND PADDLE)
		sball.move(dx, 0);
		for (int i = 0; i < cntr; i++)
			if (isCollide(sball, block[i])) { block[i].setPosition(-200, 0); dx = -dx; remainBricks--;  isColl = 1; }

		sball.move(0, dy);
		for (int i = 0; i < cntr; i++)
			if (isCollide(sball, block[i])) { block[i].setPosition(-200, 0); dy = -dy; remainBricks--;  isColl = 1; }

		if (isCollide(sball, spaddle)) dy = -(5), isColl = 1;
		//-----------------------------------------//WINDOW DRAW
		win.draw(sball);
		win.draw(spaddle);
		for (int i = 0; i < cntr; i++)
			win.draw(block[i]);
		//---------------------------------------//LOSE WINDOW
		if (lose)
		{
			cntr = 0;
			for (int i = 0; i <= 3; i++)
				for (int j = 0; j <= 4; j++)
				{
					block[cntr].setPosition(200 + i * 43 * 2, 50 + j * 20 * 2);
					cntr++;
				}
			if (play_again(win)) {
				// take money 

				arr_acc[ind].money -= brickCost;
				if (arr_acc[ind].money <= 0) {
					arr_acc[ind].money += brickCost;
					Sleep(200);
					window = 1;
				}
				////////////then reinitialize
				lose = 0;
				
				spaddle.setPosition(300 * 2, 420 * 2);
				sball.setPosition(300 * 2, 300 * 2);

			}
			else {

				Sleep(200);
				window = 1;
			}
		}

		//----------------------------------//WINDOW DISPLAY
		win.display();

		///---------------------checkers
		
		if (b.y == 430 * 2)
		{
			lose = true;
		}
		// check win
		if (!remainBricks) {
			win.clear();
			alertTxt.alert(win, "WINNER WINNER", Color::Red, 520, 450);
			arr_acc[ind].money += 30;
			
			window = 1;
			cntr = 0;
			for (int i = 0; i <= 3; i++)
				for (int j = 0; j <= 4; j++)
				{
					block[cntr].setPosition(200 + i * 43 * 2, 50 + j * 20 * 2);
					cntr++;
				}
		}
		//
		if (isColl)clicky();
	}
	