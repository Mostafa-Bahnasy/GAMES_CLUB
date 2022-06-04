#pragma once
//----------------------
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
string words[12];
void make_words() {
	words[0] = { "" };
	words[1] = { "TIC_TAC_TOE:\n->two players game.\n->each player takes either X or O sign.\n->they take turns till someone reach bingo.\n->you will get 5 coins each time you win.\n->you will lose 4 coins each time you havnt won.\n->our system will challenge you,and not a real person.\n->you pay 3 coins to use game for 3 mins." };
	words[2] = { "CHATTI:\n->local chat app.\n->you can send and recieve messeges using glopal chat.\n->and you can send to admins if you want fron admins box.\n->you first choose you nicknameand chatti window." };
	words[3] = { "PIANO:\n-> not a game.\n->you use tiles, by clicking or typing, to make sounds.\n->you pay 3 coins to use app for 3 mins." };
	words[4] = { "PACMAN:\n->single player game.\n->there is a field, coins,and a gost.\n->your task is to collect all the coins.\n-> if gost caught you, you will lose one life.\n-> if you lose all your three lives, you will lose.\n->you pay 10 coins to play,and gain 20 coins if you win." };
	words[5] = { "PINGPONG:\n->two player game.\n->each player has a racket.\n->there is a ball,and two players try to hit it.\n-> if your hit overrides your opponent, you recive point.\n->you pay 5 coins to play,and get 20 coins if you have won.\n->you will challenge out system,and not a real person." };
	words[6] = { "SUDOKU_SOLVER:\n-> not a game.\n->you pay 2 coins to solve one board.\n->you will be kicked out once you dont have enough money." };
	words[7] = { "CASINO:\n->single player game.\n->you guess a number which the wheel will stop on.\n->you win 10 times your bet if you guess right.\n->you lose only your bet if you guess wrong.\n->there is no requiered costs to start this game." };
	words[8] = { "PUZZLE:\n->single player game.\n->click a number and it moves.\n->then tread accordingly to arrange those numbers from 1 to 15." };
	words[9] = { "SNAKE:\n->single player game.\n->use arrows to move snake and collect apples.\n->you win 5 coins after for each 500 point.\n->you pay 3 coins to play." };
	words[10] = { "BRICK BREAKER:\n->single player game.\n->use arrows to move paddle and hit the ball.\n->once you breack all bricks, you win.\n->it costs 10 coins to play.\n->you gain 30 coins if you win." };
}
//-----------------------
class tutorial
{

private:
	int index = 0;
	Text outText;
	Font font;
public:
	// constructors & destructors
	tutorial(string addresse, string title);
	~tutorial();
	//---------------------------

	// getter & setter
	// index
	int getInd() {
		return this->index;
	}
	//
	void setInd(int index) {
		this->index = index;
	}
	
	//
	//----------------

	//----functions----
	////print rules////
	void printTutorial(RenderWindow& win, size_t delay) {
		string tempStr = "";
		////////////////////////////////
		back_sound.stop();
		Typing.play();
		Typing.setLoop(true);
		////////////////////////////////
		for (auto i : words[this->index]) {
			tempStr += i;
			this->outText.setString(tempStr);
			this->outText.setPosition(Vector2f(150.f, 150.f));
			win.clear();
			win.draw(outText);
			win.display();
			Sleep(delay);
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				Typing.stop();

				Sleep(100);
				back_sound.play();

				return;

			}
		}
		Typing.stop();
		Sleep(3000);
		back_sound.play();
	}
	
	//-----shape text------
	void shape_text(size_t ch_size, Color cl, bool underlined = 0, bool bold = 0) {
		this->outText.setCharacterSize(ch_size);
		this->outText.setFillColor(cl);
		if (underlined)this->outText.setStyle(sf::Text::Underlined);
		if (bold)this->outText.setStyle(sf::Text::Bold);

	}
	///////////////////////
};

tutorial::tutorial(string addresse, string title)
{
	this->font.loadFromFile(addresse);
	this->outText.setFont(this->font);
	this->outText.setString(title);
}

tutorial::~tutorial()
{
}