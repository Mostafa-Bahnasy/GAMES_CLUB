

int modified_w = 192;
int original_w = 64;
int n = 0;
int grid[5][5];

Texture t;

Sprite panel[17];
// random postions
void randomize(int grid[5][5]) {

	// we will iterate any number of times, and randomize ezch time.
	// consider we iterate 10 times for now

	int loop = 13;

	while (loop--) {
		//------------------------------------------------------------------

		 // get random postions
		size_t x1 = randomi(1, 4), x2 = randomi(1, 4), y1 = randomi(1, 4), y2 = randomi(1, 4);
		// x represnts row num, and y col num.

		// first swap grid array
		swap(grid[x1][y1], grid[x2][y2]);
		// ----------------------

	}



}

// check if current board is winning board
bool is_winner(int grid[5][5]) {
	// we will check if numbers are sorted
	int ind = 1;

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			if (ind != grid[i][j]) {
				return 0;
			}
			ind++;
		}
	}
	return 1;
}

void setPuzzle() {

	//GPU Protection

	//setting textures to handle panels individually 
	t.loadFromFile("assets\\otherGames\\15.png");
	t.setSmooth(1); // to delete pixels
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			n++;
			panel[n].setTexture(t);
			panel[n].setTextureRect(IntRect(i * original_w, j * original_w, original_w, original_w));
			panel[n].setScale(Vector2f(3.f, 3.f));

			grid[i + 1][j + 1] = n;

		}
	}
	//random sprites
	randomize(grid);

}

void to_run_puzzle()
{
	
	
		//Game logic


		//a panel has only 4 possible swaps


		//it's either ahead in x or  in y 


		//it's either after in x or  in y


		//swapping positions for the win

			if (mouse_l())
			{
				Vector2i pos = Mouse::getPosition(win);
				int x = pos.x / modified_w + 1;
				int y = pos.y / modified_w + 1;

				int dx = 0;
				int dy = 0;

				if (grid[x + 1][y] == 16) { dx = 1; dy = 0; };
				if (grid[x][y + 1] == 16) { dx = 0; dy = 1; };
				if (grid[x][y - 1] == 16) { dx = 0; dy = -1; };
				if (grid[x - 1][y] == 16) { dx = -1; dy = 0; };

				int n = grid[x][y];
				grid[x][y] = 16;
				grid[x + dx][y + dy] = n;

				//animation
				panel[16].move(-dx * modified_w, -dy * modified_w);
				float speed = 3;

				for (int i = 0; i < modified_w; i += speed)
				{
					panel[n].move(speed * dx, speed * dy);
					win.draw(panel[16]);
					win.draw(panel[n]);
					
				}
			}


		//drawin them panels boi


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{


				int n = grid[i + 1][j + 1];
				panel[n].setPosition(i * modified_w, j * modified_w);
				win.draw(panel[n]);


			}
		}
		win.display();

		
		// check winner
		if (is_winner(grid)) {
			win.clear();
			alertTxt.alert(win, "WINNER WINNER", Color::Red, 960, 540);
			arr_acc[ind].money += 10;
			window = 1;
		}
	}
