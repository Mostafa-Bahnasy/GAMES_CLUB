#pragma once
/////////////////////////costs////////////////////////////////
const short pingCost = 5;
const short pianoCost = 5;
const short puzzleCost = 5;
const short pacmanCost = 10;
const short ticCost = 4;
const short paintCost = 3;
const short sudokuCost = 2;
const short casinoCost = 5;
const short brickCost = 10;
const short snakeCost = 3;
int window = 0;
int wallInd = 0;

//-------------------------------------------------------------
using namespace std;
using namespace sf;
//-------------------------------------------------------------
/////////////////////////////////////////////////

RectangleShape backTrick;

/////////////////////////////////////////////////
// ////////////////////////global sounds
SoundBuffer song1,song2,song3,click_sound,pass_sound;
Sound back_sound,clicks;
int sound_level = 50;

SoundBuffer TypingBuff;
Sound Typing;
void initialize_sounds() {
	//////load buff
	song1.loadFromFile("assets\\audio\\trailer-sport-stylish-16073.ogg");

	song2.loadFromFile("assets\\audio\\backSong.ogg");

	song3.loadFromFile("assets\\audio\\songb.ogg");
	///////setdefault song
	back_sound.setBuffer(song1);
	back_sound.play();
	back_sound.setLoop(true);
	///////
	// clicks sounds
	click_sound.loadFromFile("assets\\audio\\enter_sound.ogg");
	pass_sound.loadFromFile("assets\\audio\\select_sound.ogg");
	clicks.setLoop(0);
	clicks.setVolume(50.f);
	////////////////

	TypingBuff.loadFromFile("assets\\audio\\computer-keyboard-1.ogg");
	Typing.setBuffer(TypingBuff);
}
void clicky() {
	clicks.setBuffer(click_sound);
	clicks.play();
}
void selecty() {
	clicks.setBuffer(pass_sound);
	clicks.play();
}
/////////////////////////////////////////
//----------------------window play again-------
//------------------------------------------------------------------windows
sf::RenderWindow win(sf::VideoMode(1920, 1080), "store", Style::Fullscreen);

//-----------------------------------

//--------------public functions-------------------------------
bool mouse_l() {
	return Mouse::isButtonPressed(Mouse::Left);
}
bool mouse_r() {
	return Mouse::isButtonPressed(Mouse::Right);
}

void win_si(RenderWindow& win,size_t x, size_t y) {
	win.setSize(Vector2u(x, y));
}
void hide(RenderWindow &wind) {
	wind.setVisible(0);
}
void appear(RenderWindow& wind) {
	wind.setVisible(1);
}
//inline void hide_all_window() {
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//	hide(win);
//}
bool mouse_intersects(RenderWindow & win, Sprite & temp) {
	auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
	auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	return (temp.getGlobalBounds().contains(translated_pos));
}

bool mouse_intersects(RenderWindow& win, Text& temp) {
	auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
	auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	return (temp.getGlobalBounds().contains(translated_pos));
}

bool mouse_intersects(RenderWindow& win, RectangleShape temp) {
	auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
	auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	return (temp.getGlobalBounds().contains(translated_pos));
}

bool mouse_intersects(RenderWindow& win, CircleShape temp) {
	auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
	auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	return (temp.getGlobalBounds().contains(translated_pos));
}


///---------------------------make unique ID
wstring GUIDToWString(GUID* guid)
{
	wchar_t guid_string[37];
	swprintf(
		guid_string, sizeof(guid_string) / sizeof(guid_string[0]),
		L"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		guid->Data1, guid->Data2, guid->Data3,
		guid->Data4[0], guid->Data4[1], guid->Data4[2],
		guid->Data4[3], guid->Data4[4], guid->Data4[5],
		guid->Data4[6], guid->Data4[7]);

	// remove when VC++7.1 is no longer supported
	guid_string[sizeof(guid_string) / sizeof(guid_string[0]) - 1] = L'\0';

	return wstring(guid_string);
}

string make_unique_id() {
	GUID guid;
	CoCreateGuid(&guid);
	wstring temp = GUIDToWString(&guid);
	std::string str;
	std::transform(temp.begin(), temp.end(), std::back_inserter(str), [](wchar_t c) {
		return (char)c;
		});
	string copy = str.substr(0, 8);
	return copy;
}
/////////////////////////////////////////////

size_t randomi(size_t left,size_t right ) {
	size_t temp = rand() % (right+1);
	while (temp < left||temp>right) {
		if(temp<left)
		temp += left;
		if (temp > right) {
			temp = rand() % temp;
		}
	}
	return temp;
}
//-------------------------------------------------------------
// -----------------------------Time Class---------------------

struct time_t_d {// to return time text and time duration
	string time_str;
	size_t duration=0;
};


class TIME :public time_t_d {
public:
	Time time;
	size_t minutes=0;
	size_t seconds=0;
	time_t_d current;
	//-----------------
	void current_time(Clock& clock) {
		time = clock.getElapsedTime();
		seconds = time.asSeconds();
		string str;
		if (seconds < 10)
			 str = "Time: " + to_string(minutes) + ":" + "0" + to_string(seconds);
		else
			 str = "Time: " + to_string(minutes) + ":" + to_string(seconds);  //else set it normaly cast variables to strings


		if (seconds >= 60) {
			minutes++;
			clock.restart();
		}
		current.time_str = str;
		current.duration = 60*minutes+seconds;
		
	}




};




// ------------------------------------------------------------
//--------------------------------Text Class-------------------

class Text_C {
public:
	sf::Text text;
	sf::Font font;
	int points=0;
	//------------------------------fonts&labels&text-----
	// ----reset text-----
	void text_str(string str) {
		this->text.setString(str);
	}
	//------load text-----
	void make_text(string addresse, string title) {// word
		this->font.loadFromFile(addresse);
		this->text.setFont(this->font);
		this->text.setString(title);
	}
	//-----shape text------
	void shape_text(size_t ch_size, Color cl, bool underlined = 0, bool bold = 0) {
		this->text.setCharacterSize(ch_size);
		this->text.setFillColor(cl);
		if (underlined)this->text.setStyle(sf::Text::Underlined);
		if (bold)this->text.setStyle(sf::Text::Bold);

		this->text.setOrigin(Vector2f(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2));
	}
	//--set origin()
	void t_origin() { // [ 1 ]
		this->text.setOrigin(Vector2f(this->text.getLocalBounds().width/2, this->text.getLocalBounds().height/2));
	}
	// change color text
	void text_color(Color cl) {
		this->text.setFillColor(cl);
	}
	//change pos
	void text_pos(float x,float y) {
		this->text.setPosition(Vector2f(x,y));
	}
	//------outline text color on mouse----
	void outline_mouse(RenderWindow &win, Color orcl, Color ncl) {
		auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
		auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		if (this->text.getGlobalBounds().contains(translated_pos)) {
			this->text.setOutlineColor(ncl);
		}
		else {
			this->text.setOutlineColor(orcl);
		}
	}
	//-------Text color on mouse pass-------
	bool color_mouse(RenderWindow &win, Color orcl, Color ncl) {
		auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
		auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		if (this->text.getGlobalBounds().contains(translated_pos)) {
			this->text.setFillColor(ncl);
			if (mouse_l())return 1;
		}
		else {
			this->text.setFillColor(orcl);
		}
		return 0;
	}
	//------print alert---------
	void alert(RenderWindow& win, string alertStr,Color cl,float posX,float posY) {
		this->text.setString(alertStr);
		this->text.setFillColor(cl);
		this->text.setOrigin(Vector2f(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2));

		this->text_pos(posX,posY);
		int loop = 30;
		while (loop--) {
			win.clear();
			win.draw(this->text);
			win.display();
			if (loop % 4==0) {
				this->text.setScale(Vector2f(1.f, 1.f));
			}
			else if(loop%4==1){

				this->text.setScale(Vector2f(1.2f, 1.2f));
			}
			else if (loop % 4 == 2) {
				this->text.setScale(Vector2f(1.5f, 1.5f));

			}
			else {
				this->text.setScale(Vector2f(1.65f, 1.65f));

			}
			Sleep(150);
		}

		this->text.setScale(Vector2f(1.f, 1.f));
	}
	///////////////////////////////////////////////
	void alert(RenderWindow& win, string alertStr, Color cl, float posX, float posY, Sprite& sp,float size) {
		this->text.setString(alertStr);
		this->text.setFillColor(cl);
		this->text.setCharacterSize(size);
		this->text.setOrigin(Vector2f(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2));
		this->text_pos(posX, posY);
		string tempStr = "";
		////////////////////////////////
		back_sound.stop();
		Typing.play();
		Typing.setLoop(true);
		////////////////////////////////
		for (auto i : alertStr) {
			tempStr += i;
			this->text.setString(tempStr);
			win.clear();
			win.draw(sp);
			win.draw(text);
			win.display();
			Sleep(90);
			
		}
		Typing.stop();
		Sleep(3000);
		back_sound.play();
	}
};


// object: is to modify sprites and sound and other live objects.


//--------------------------------------
class object:public Text_C , public TIME{
public:
	bool todraw = 0;
	sf::Sprite sp;
	sf::Texture tx_sp;
	Texture shadowtx;
	std::string name;

	//float x = 0, y = 0;
	sf::SoundBuffer buff;
	sf::Sound music;
	sf::Sprite shadow_sp;
	RectangleShape recta;
	CircleShape circle;
	bool ispressed = 0;
	float movex = 0.f, movey = 0.f;
    //--------------------sprite-------------------------------------------------------------
		//----alaign it to origin
	void origin() {// sprite
		this->sp.setOrigin(Vector2f(this->sp.getLocalBounds().width / 2.f, this->sp.getLocalBounds().height / 2.f));
		this->shadow_sp.setOrigin(Vector2f(this->shadow_sp.getGlobalBounds().width / 2.f, this->shadow_sp.getGlobalBounds().height / 2.f));

	}
	
	// scale  sprite
	void scale_sp(float x,float y,bool bl=0) {
		if(!bl)
		this->sp.setScale(Vector2f(x, y));
		else
			this->sp.setScale(Vector2f(x, y));
		this->shadow_sp.setScale(Vector2f(x, y));
	}
	//sprite origin only
	void origin(bool bl) {
		if(bl)this->sp.setOrigin(Vector2f(this->sp.getGlobalBounds().width / 2.f, this->sp.getGlobalBounds().height / 2.f));
		else this->shadow_sp.setOrigin(Vector2f(this->shadow_sp.getGlobalBounds().width / 2.f, this->shadow_sp.getGlobalBounds().height / 2.f));
	}
	//--------
	//------make sprite
	void make_sp(std::string str) {
		this->tx_sp.loadFromFile(str);
		this->tx_sp.setSmooth(1);
		this->sp.setTexture(tx_sp);
	}
	//----make shadow sprite
	void make_shadow(string add) {
		 shadowtx.loadFromFile(add);
		this->shadow_sp.setTexture(shadowtx);
	}
	//----shadow_pos---------
	void shadow_pos() {
		this->shadow_sp.setPosition(this->sp.getPosition());
	}
	//-----entire sprite rect texture--
	void make_sp(int pos_x, int pos_y, int size_x, int size_y) {
		this->sp.setTextureRect(IntRect(Vector2i(pos_x, pos_y), Vector2i(size_x,size_y)));

	}
	//-----entire shadow rect texture--
	void make_shadow(int pos_x, int pos_y, int size_x, int size_y) {
		this->shadow_sp.setTextureRect(IntRect(Vector2i(pos_x, pos_y), Vector2i(size_x, size_y)));

	}

	//------set name for object
	void set_name(std::string s) {
		this->name = s;
	}
	//------setpos-------
	void sp_pos(float x_pos,float y_pos) {
		this->sp.setPosition(Vector2f(x_pos, y_pos));
	}
	//----flip sprite
	void flip() {
		this->sp.scale(-1, 1);
	}
	//----make sound 
	void make_sound(std::string s) {
		this->buff.loadFromFile(s);
		this->music.setBuffer(buff);
	}
	//------draw tiny func
	void dr(RenderWindow &wi) {
		wi.draw(this->sp);
	}
	//-----appear&disappear
	void show(bool bl) {
		this->todraw = bl;
	}
	//----------------------------------------------
	

	// ---------------------------------------------
	//------------------------musics----------------
	//----music play----
	void play(bool bl) {
		// bl = 1 for loop play
		// bl = 0 for instance play
		if (bl) {
			this->music.play();
			this->music.setLoop(1);
		}
		else {
			this->music.play();
			this->music.setLoop(1);
		}
	}
	//----stop&pause music-----
	void stop(bool bl) {
		// bl = 1 for stop
		// bl = 0 for pause
		if (bl) {
			this->music.stop();
		}
		else {
			this->music.pause();
		}
	}
	//-------set volume--
	void vol_level(float fl) {
		this->music.setVolume(fl);
	}
	//------------------------------------------------
	
	//---------------------------Animations----------------------------
	// ------------rotate inside screen----------
	void rotate_in(RenderWindow &win ,vector<object>v) {
		for (float i = 0.05f; i < 0.5f; i += 0.05f) {
			win.clear();
			for (auto in : v) {
				win.draw(in.sp);
			}
			win.draw(this->sp);
			win.display();
			Sleep(50);
			this->sp.rotate(45);
			this->sp.scale(Vector2f(1.f - i, 1.f - i));
		}

	}
	// ------------scale inside screen----------
	void scale_in(RenderWindow &win, vector<object>v) {
		for (float i = 0.05f; i < 0.5f; i += 0.05f) {
			win.clear();
			for (auto in : v) {
				win.draw(in.sp);
			}
			win.draw(this->sp);
			win.display();
			Sleep(50);
			
			this->sp.scale(Vector2f(1.f - i, 1.f - i));
		}

	}
	// ------------scale outside screen----------
	void scale_out(RenderWindow &win, vector<object>v) {
		for (float i = 0.05f; i < 0.5f; i += 0.05f) {
			win.clear();
			for (auto in : v) {
				win.draw(in.sp);
			}
			win.draw(this->sp);
			win.display();
			Sleep(50);
			this->sp.scale(Vector2f(1.f + i, 1.f + i));
		}

	}
	// ------------rotate outside screen----------
	void rotate_out(RenderWindow &win, vector<object>v) {
		for (float i = 0.05f; i < 0.5f; i += 0.05f) {
			win.clear();
			for (auto in : v) {
				win.draw(in.sp);
			}
			win.draw(this->sp);
			win.display();
			Sleep(50);
			this->sp.rotate(45);
			this->sp.scale(Vector2f(1.f + i, 1.f + i));
		}

	}
	//-----------------flip many times-----------
	void flip(RenderWindow &win, int times,vector<object>v) {// override
		while (times--) {
			win.clear();
			for (auto in : v) {
				win.draw(in.sp);
			}
			win.draw(this->sp);
			win.display();
			Sleep(50);
			this->flip();
		}
	}
	//----------------go with mouse-----------------
	bool mouse_intersects(RenderWindow &win,Sprite& temp) {
		auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
		auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		return (temp.getGlobalBounds().contains(translated_pos));
	}
	//---------------change color--------------------
	void change_color_sp(Color cl) {
		this->sp.setColor(cl);
	}
	//--------------change color shadow--------------
	void change_color_sh(Color cl) {
		this->shadow_sp.setColor(cl);
	}
	//-----change color on mouse pass--
	void color_sprite_pass(RenderWindow &win, Color orcl, Color ncl) {
		auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
		auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		if (this->sp.getGlobalBounds().contains(translated_pos)) {
			this->sp.setColor(ncl);
		}
		else {
			this->sp.setColor(orcl);
		}
	}
	//-----change color on mouse pass--
	bool color_sprite_pass(RenderWindow& win) {
		auto mouse_pos = sf::Mouse::getPosition(win); // Mouse position relative to the window
		auto translated_pos = win.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		if (this->sp.getGlobalBounds().contains(translated_pos)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	//-----color and disappear----------------------
	void color_animation(Color cl,RenderWindow &win) {

	}
	//--------------------------rectangle shaping
	void shape_entity(bool isrect,Color cl,float size_x,float size_y) {
		if (isrect) {
			this->recta.setFillColor(cl);
			this->recta.setSize(Vector2f(size_x, size_y));

			this->recta.setOrigin(this->recta.getLocalBounds().width / 2, this->recta.getLocalBounds().height / 2);
		}
		else {
			this->circle.setFillColor(cl);
			this->circle.setRadius(size_x);
			this->circle.setOrigin(this->circle.getLocalBounds().width / 2, this->circle.getLocalBounds().height / 2);
		}
	}
};
object entity_time;
object wallpaper;
// intialize time
void intial_time() {
	//--------------------------------------------------------------Time texture
	entity_time.make_text("alfont_com_arial-1.ttf", "00:00");
	entity_time.shape_text(36, Color(228, 191, 212, 1), 0, 0);
	entity_time.text_pos(1750.f, 150.f);
}
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
class pairSp {
private:
	Sprite sp;
	Texture tx;

public:
	void loadSp(string add) {
		this->tx.loadFromFile(add);
		this->sp.setTexture(this->tx);
	}
	//////
	void posSp(float x, float y) {
		this->sp.setPosition(x, y);
	}
	/////
	void play(RenderWindow& wi) {
		wi.clear(Color::White);
		wi.draw(this->sp);
		wi.display();
		Sleep(1000);
	}

	void drawTo(RenderWindow& w) {
		w.draw(this->sp);
	}

	Texture& getTexture() {
		return this->tx;
	}

	void scl(float x, float y) {
		this->sp.setScale(x, y);
	}
	Sprite& Sp() {
		return this->sp;
	}
};



//--------------------------------------------------------------



//---------------objects------------------------
object main_menu, again;
void initialize_again_menu() {
	again.make_sp("assets\\option\\again.png");
	again.make_shadow("assets\\option\\shadow_again.png");

	//again.origin();
	again.sp_pos(430.f, 540.f);
	again.shadow_pos();
	//
	main_menu.make_sp("assets\\option\\gohome.png");
	main_menu.make_shadow("assets\\option\\shadow_gohome.png");
	//main_menu.origin();
	main_menu.sp_pos(670.f, 540.f);
	main_menu.shadow_pos();
}
//-----------------------------------------------
bool play_again(RenderWindow &win) {

	sf::Event closeEv;
	//appear(win);
	while (win.isOpen()) {
		// -------------------------------close window
		while (win.pollEvent(closeEv)) {

			if (closeEv.type == sf::Event::Closed) {
				return 0;
			}
		}
	
		//--------------------------------------------if left click
		if (mouse_l()) {
			clicky();
			if (again.mouse_intersects(win,again.shadow_sp)) {
				//hide(win);
				return 1;
			}
			if (main_menu.mouse_intersects(win,main_menu.shadow_sp)) {
				//hide(win);
			//	hide(win);
				
				// appear main window
				return 0;
			}
		}
		//-----------------------------------------------------------
		//-------------drawings--------------------------------------
		win.clear();
		//--------------------------------------------if mouse pass
		if (again.color_sprite_pass(win)) {
			win.draw(again.shadow_sp); selecty();
		}
		else {
			win.draw(again.sp);
		}
		if (main_menu.color_sprite_pass(win)) {
			win.draw(main_menu.shadow_sp); selecty();
		}
		else {
			win.draw(main_menu.sp);
		}
		//--------------------------------------------------------

		win.display();
		//-----------------------------------------------------------

	}
	//hide(win);
	//hide(win);
	return 0;
}


//------------------------------------------------------------------options window
//-------glopal objects
object option_back,shader;
// for volume
object vol_up, vol_down, vol_screen;
// for background
object credit_wall;
object walls[3];
// options choices
object edit_wall, edit_vol, credit, ret, exiti;
object songi, songj, songk;
//---------------------

void initialize_options() {
	// wallpapers
	walls[0].make_sp("assets\\backImages\\download.jpg");
	walls[1].make_sp("assets\\backImages\\download (4).png");
	walls[2].make_sp("assets\\backImages\\download (1).jpg");

	
	//////////////////////////////////////////////////////////////////postion
	for (int i = 0; i < 3; i++) {
		walls[i].sp_pos(300.f + (500.f) * i, 500.f);
	}
	
	//////////////////////////////////////////////////////////////////
	/// window background
	option_back.make_sp("assets\\option\\2801920.jpg");
	/////////////////////////////////////
	//////---volume---///////
	//-------------up sound button
	vol_up.make_sp("assets\\option\\sound_up.png");
	vol_up.make_shadow("assets\\option\\sound_up_sh.png");
	vol_up.origin();
	vol_up.sp_pos(700.f, 600.f);
	vol_up.shadow_pos();
	//-------------down sound button
	vol_down.make_sp("assets\\option\\sound_down.png");
	vol_down.make_shadow("assets\\option\\sound_d_sh.png");
	vol_down.origin();
	vol_down.sp_pos(1280.f, 600.f);
	vol_down.shadow_pos();
	//-------------vol_screen
	//---box
	vol_screen.recta.setSize(Vector2f(200.f, 100.f));
	vol_screen.recta.setOrigin(Vector2f(vol_screen.recta.getLocalBounds().width / 2, vol_screen.recta.getLocalBounds().height / 2));
	vol_screen.recta.setPosition(Vector2f(960.f, 300.f));
	vol_screen.recta.setFillColor(Color::White);
	//---text
	vol_screen.make_text("Game Of Squids.ttf", to_string(sound_level)+"%");
	vol_screen.shape_text(44, Color::Red);
	vol_screen.t_origin();
	vol_screen.text.setPosition(vol_screen.recta.getPosition());
	//---------------------------------
	// options
	///////// volume
	edit_vol.make_text("Game Of Squids.ttf", "SOUNDS");
	edit_vol.shape_text(50, Color::Magenta);
	edit_vol.t_origin();
	edit_vol.text_pos(960.f,300.f);

	//////// walls
	edit_wall.make_text("Game Of Squids.ttf", "WALLPAPERS");
	edit_wall.shape_text(50, Color::Magenta);
	edit_wall.t_origin();
	edit_wall.text_pos(960.f, 450.f);

	//////// credit
	credit.make_text("Game Of Squids.ttf", "CREDIT");
	credit.shape_text(50, Color::Magenta);
	credit.t_origin();
	credit.text_pos(960.f, 600.f);

	//////// return but
	ret.make_sp("assets\\option\\return but.png");
	ret.make_shadow("assets\\option\\return but sh.png");
	ret.origin();
	ret.sp_pos(1800.f, 100.f);
	ret.shadow_pos();
	ret.scale_sp(0.7f, 0.7f, true);

	///////  exit 
	exiti.make_text("Game Of Squids.ttf", "EXIT");
	exiti.shape_text(50, Color::Magenta);
	exiti.t_origin();
	exiti.text_pos(960.f, 750.f);
	/////////////////////////////////////////////////////
	/////// shader
	shader.make_sp("assets\\option\\menu_shader.png");
	shader.origin(1);
	shader.sp_pos(960.f, 540.f);

	/////// credit wall
	credit_wall.make_sp("assets\\option\\credit_wall.png");
	//////////////////////////////////////////////////////
	
	/////songs_sprites
	// song2
	songi.make_text("Game Of Squids.ttf", "SONG_2");
	songi.shape_text(32, Color::White);
	songi.t_origin();
	songi.text_pos(960.f, 150.f);
	// song1
	songj.make_text("Game Of Squids.ttf", "SONG_1");
	songj.shape_text(32, Color::White);
	songj.t_origin();
	songj.text_pos(660.f, 150.f);
	// song3
	songk.make_text("Game Of Squids.ttf", "SONG_3");
	songk.shape_text(32, Color::White);
	songk.t_origin();
	songk.text_pos(1260.f, 150.f);
	/////////////////////////////////////
}




bool to_run_options() {
	sf::Event closeEv;
	//hide_all_window();
	//initialize_options();
	//appear(win);
	bool first = 1;
	int order = -1;

	while (win.isOpen()) {

		// -------------------------------close window
		while (win.pollEvent(closeEv)) {

			if (closeEv.type == sf::Event::Closed) {
				win.close();
			}
		}
		////////////////////////////////////////////////

		if (first) {
			bool choosed = 0; // check if user entered some option

			/////////////////////////////mouse events/////////////////////
			//----------------------check intersects
				if (mouse_intersects(win, exiti.text)) {
					exiti.text_color(Color::Cyan); 
					order = 3;
					selecty();
				}
				if (mouse_intersects(win, credit.text)) {
					credit.text_color(Color::Cyan);order = 2;
					selecty();
				}
				if (mouse_intersects(win, edit_vol.text)) {
					edit_vol.text_color(Color::Cyan); order = 0;
					selecty();
				}
				if (mouse_intersects(win, edit_wall.text)) {
					edit_wall.text_color(Color::Cyan);  order = 1;
					selecty();
				}
				if (mouse_intersects(win, ret.sp)) {
					ret.todraw=1;
					order = 4;

					selecty();
					// draw shadow
				}
			//-------------------check click
				if (mouse_l()&&order>=0) {
					choosed = 1;
					clicky();
				}
				//////////////////////////////////////////////////////////////

				

		////drawings////
		win.clear();
		win.draw(option_back.sp);
		win.draw(shader.sp);
		win.draw(exiti.text);
		win.draw(edit_vol.text);
		win.draw(edit_wall.text);
		win.draw(credit.text);
		//
		if(!ret.todraw)
		    win.draw(ret.sp);
		else
			win.draw(ret.shadow_sp);
		//
		win.display();
		///////////////
		if (choosed) {
			first = 0; Sleep(100); continue;
		}
		////// re initialize/////
		ret.todraw = 0;
		exiti.text_color(Color::Magenta);
		edit_vol.text_color(Color::Magenta);
		edit_wall.text_color(Color::Magenta);
		credit.text_color(Color::Magenta);
		order = -1;
		/////////////////////////

		}
		else {
			if (order == 0) { ////sounds
				/////////////////////////
				bool intersect = 0;
				if (mouse_intersects(win, ret.sp))ret.todraw = 1;
				if (ret.todraw && mouse_l()) {
					intersect = 1;
					clicky();
				}
				//-----------------------------
				////////check if choosed any song
				if (mouse_l()) {

					if (mouse_intersects(win, songi.text)) {
						songi.text_color(Color::Red);
						back_sound.stop();
						back_sound.setBuffer(song1);
						back_sound.play();
						back_sound.setLoop(1);
					}
					else if (mouse_intersects(win, songj.text)) {
						songj.text_color(Color::Red);
						back_sound.stop();
						back_sound.setBuffer(song2);
						back_sound.play();
						back_sound.setLoop(1);
					}
					else if (mouse_intersects(win, songk.text)) {
						songk.text_color(Color::Red);
						back_sound.stop();
						back_sound.setBuffer(song3);
						back_sound.play();
						back_sound.setLoop(1);
					}
				}
				////////check normal intersection
				if (mouse_intersects(win, songi.text)) {
					songi.text_color(Color::Red);

				}
				else if (mouse_intersects(win, songj.text)) {
					songj.text_color(Color::Red);

				}
				else if (mouse_intersects(win, songk.text)) {
					songk.text_color(Color::Red);

				}
				///////////////////////////////////////

				//------------------------------
				
				//-----if increse sound
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					sound_level++; vol_up.todraw = 1; selecty();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down)) { /// if decrease sound
					sound_level--; vol_down.todraw = 1;
					selecty();
				}
				//-----------------------------------
				//check overfloaw
				if (sound_level >= 100)sound_level = 100;
				else if (sound_level <= 0)sound_level = 0;

				///----------update sound percentage
				vol_screen.text_str(to_string(sound_level) + "%");

				//////////////////drawings
				win.clear();
				///
				if (!vol_up.todraw)
					win.draw(vol_up.sp);
				else
					win.draw(vol_up.shadow_sp);
				///
				if (!vol_down.todraw)
					win.draw(vol_down.sp);
				else
					win.draw(vol_down.shadow_sp);
				///
				win.draw(vol_screen.recta);
				win.draw(vol_screen.text);
				win.draw(songi.text);
				win.draw(songj.text);
				win.draw(songk.text);
				if (!ret.todraw)
					win.draw(ret.sp);
				else
					win.draw(ret.shadow_sp);
				win.display();
				//////////////////
				
				////////setvolume
				back_sound.setVolume(sound_level);
				///////re initialize
				vol_up.todraw = 0;
				vol_down.todraw = 0;
				songi.text_color(Color::White);
				songj.text_color(Color::White);
				songk.text_color(Color::White);
				//
				Sleep(100);
				if (intersect) { first = 1, order = -1, Sleep(200); continue; }
				
			}
			else if (order == 1) { /////wallpapers
			bool intersect = 0;
			if (mouse_intersects(win, ret.sp))ret.todraw = 1;
			if (ret.todraw && mouse_l()) {
				intersect = 1;
				clicky();
			}
			/////////////////check if wall choice
			for (int i = 0; i < 3;i++) {
				if (mouse_intersects(win, walls[i].sp)) {
					walls[i].todraw = 1; selecty();
					if (mouse_l()) {
						wallInd = i;
					}
				}
			}
			
			////////////////////////drawings
			win.clear();
			for (int i = 0; i < 3;i++) {
				if(!walls[i].todraw)
				win.draw(walls[i].sp);
				else {
					walls[i].sp.setScale(Vector2f(1.25f, 1.25f));
					win.draw(walls[i].sp);
					walls[i].sp.setScale(Vector2f(1.f, 1.f));
					walls[i].todraw = 0;
				}
			}
			//
			if (ret.todraw)
				win.draw(ret.shadow_sp);
			else
				win.draw(ret.sp);
			//
			 win.display();
			////////////////////////
			 ret.todraw = 0;
			 if (intersect) { first = 1; order = -1; Sleep(300); continue; }

			}
			else if (order == 2) { //// credits
				bool intersect = 0;
				if (mouse_intersects(win, ret.sp))ret.todraw=1;
				if (ret.todraw && mouse_l()) {
					intersect = 1;
					clicky();
				}
				////////////drawings
				win.clear();
				win.draw(credit_wall.sp);
				//
				if (ret.todraw)
					win.draw(ret.shadow_sp);
				else
					win.draw(ret.sp);
				//
				win.display();
				/////////////
				ret.todraw = 0;
				if (intersect) { first = 1; order = -1; Sleep(300); continue; }

			}
			else if (order == 3) {////// exit
				return 0;
				
			}
			else if (order == 4) {////// return
				return 1;
			}
		}

	}
	
	//return 0;
}

//-----------------------------alert
Text_C alertTxt;

void iniAlert() {

	//----------alert text-----------
	alertTxt.make_text("OPTIAlert-Medium.otf", "");
	alertTxt.shape_text(40, Color::Red);
	alertTxt.t_origin();
}