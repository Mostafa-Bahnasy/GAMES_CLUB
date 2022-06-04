#pragma once
using namespace std;
using namespace sf;
//-----------------------objects to use-----------------------------global
 object  Abt, Sbt, Dbt, Fbt, Gbt, Hbt, Jbt, Kbt, Lbt, Nbt, Mbt;// white blanks
 object Wbt,Ebt,Tbt,Ybt,Ubt,Obt,Pbt;
 //-------------------stop sounds func------------------------------
 void stop_sounds() {
	 Abt.music.stop();
	 Sbt.music.stop();
	 Dbt.music.stop();
	 Fbt.music.stop();
	 Gbt.music.stop();
	 Hbt.music.stop();
	 Jbt.music.stop();
	 Kbt.music.stop();
	 Nbt.music.stop();
	 Mbt.music.stop();
	 Wbt.music.stop();
	 Ebt.music.stop();
	 Tbt.music.stop();
	 Ybt.music.stop();
	 Ubt.music.stop();
	 Obt.music.stop();
	 Pbt.music.stop();
 }
 //----------------------RESET TO DRAW------------------------------
 void reset_drawings_piano() {
	 Abt.todraw = 0;
	 Sbt.todraw = 0;
	 Dbt.todraw = 0;
	 Fbt.todraw = 0;
	 Gbt.todraw = 0;
	 Hbt.todraw = 0;
	 Jbt.todraw = 0;
	 Kbt.todraw = 0;
	 Lbt.todraw = 0;
	 Nbt.todraw = 0;
	 Mbt.todraw = 0;
	 Wbt.todraw = 0;
	 Ebt.todraw = 0;
	 Tbt.todraw = 0;
	 Pbt.todraw = 0;
	 Ybt.todraw = 0;
	 Ubt.todraw = 0;
	 Obt.todraw = 0;
 }
//----------------------initializing func---------------------------
 
 void initialize_piano_sprites() {
	 // wallpaper
	 //------white blanks postion and size------
	 Abt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Sbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Dbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Fbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Gbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Hbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Jbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Kbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Lbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Nbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 Mbt.make_sp("assets\\otherGames\\piano_Sp.png");
	 //position
	 Abt.sp_pos(50.f,50.f);
	 Sbt.sp_pos(200.f, 50.f);
	 Dbt.sp_pos(350.f, 50.f);
	 Fbt.sp_pos(500.f, 50.f);
	 Gbt.sp_pos(650.f, 50.f);
	 Hbt.sp_pos(800.f, 50.f);
	 Jbt.sp_pos(950.f, 50.f);
	 Kbt.sp_pos(1100.f, 50.f);
	 Lbt.sp_pos(1250.f, 50.f);
	 Nbt.sp_pos(1400.f, 50.f);
	 Mbt.sp_pos(1550.f, 50.f);

	 //------white blanks shadows pos&size----
	 Abt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Sbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Dbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Fbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Gbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Hbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Jbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Kbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Lbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Nbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 Mbt.make_shadow("assets\\otherGames\\piano_shadow.png");
	 //position
	 Abt.shadow_pos();
	 Sbt.shadow_pos();
	 Dbt.shadow_pos();
	 Fbt.shadow_pos();
	 Gbt.shadow_pos();
	 Hbt.shadow_pos();
	 Jbt.shadow_pos();
	 Kbt.shadow_pos();
	 Lbt.shadow_pos();
	 Nbt.shadow_pos();
	 Mbt.shadow_pos();
	 
	 //-------------------------------------------
	 //------Black blanks postion and size--------
	 Wbt.make_sp("assets\\otherGames\\black_sp.png");
	 Ebt.make_sp("assets\\otherGames\\black_sp.png");
	 Tbt.make_sp("assets\\otherGames\\black_sp.png");
	 Ybt.make_sp("assets\\otherGames\\black_sp.png");
	 Ubt.make_sp("assets\\otherGames\\black_sp.png");
	 Obt.make_sp("assets\\otherGames\\black_sp.png");
	 Pbt.make_sp("assets\\otherGames\\black_sp.png");
	 //position
	 Wbt.sp_pos(125.f, 50.f);
	 Ebt.sp_pos(275.f, 50.f);
	 Tbt.sp_pos(575.f, 50.f);
	 Ybt.sp_pos(725.f, 50.f);
	 Ubt.sp_pos(875.f, 50.f);
	 Obt.sp_pos(1175.f, 50.f);
	 Pbt.sp_pos(1325.f, 50.f);
	 
	 //--------------------------------------------
	 //------Black blanks shadows postion and size--------
	 Wbt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Ebt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Tbt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Ybt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Ubt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Obt.make_shadow("assets\\otherGames\\black_shadow.png");
	 Pbt.make_shadow("assets\\otherGames\\black_shadow.png");
	 //POSITION
	 Wbt.shadow_pos();
	 Ebt.shadow_pos();
	 Tbt.shadow_pos();
	 Ybt.shadow_pos();
	 Ubt.shadow_pos();
	 Obt.shadow_pos();
	 Pbt.shadow_pos();
	 //---------------------------------------------

 }
 void intialize_piano_sounds() {
	 Abt.make_sound("assets\\audio\\A.ogg");
	 Sbt.make_sound("assets\\audio\\S.ogg");
	 Dbt.make_sound("assets\\audio\\D.ogg");
	 Fbt.make_sound("assets\\audio\\F.ogg");
	 Gbt.make_sound("assets\\audio\\G.ogg");
	 Hbt.make_sound("assets\\audio\\H.ogg");
	 Jbt.make_sound("assets\\audio\\J.ogg");
	 Kbt.make_sound("assets\\audio\\K.ogg");
	 Lbt.make_sound("assets\\audio\\L.ogg");
	 Nbt.make_sound("assets\\audio\\N.ogg");
	 Mbt.make_sound("assets\\audio\\M.ogg");
	 Wbt.make_sound("assets\\audio\\W.ogg");
	 Ebt.make_sound("assets\\audio\\E.ogg");
	 Tbt.make_sound("assets\\audio\\T.ogg");
	 Ybt.make_sound("assets\\audio\\Y.ogg");
	 Ubt.make_sound("assets\\audio\\U.ogg");
	 Obt.make_sound("assets\\audio\\O.ogg");
	 Pbt.make_sound("assets\\audio\\P.ogg");
	 
 }
 //-----------------------------------------------------------------
 void initialize_text_piano() {
	 //----Abt
	 Abt.make_text("MorningRainbow.ttf", "A");
	 Abt.shape_text(72, Color(7, 128, 13, 150) , 0, 0);
	 Abt.text_pos(100.f, 450.f);
	 //----Sbt
	 Sbt.make_text("MorningRainbow.ttf", "S");
	 Sbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Sbt.text_pos(250.f, 450.f);
	 //----Dbt
	 Dbt.make_text("MorningRainbow.ttf", "D");
	 Dbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Dbt.text_pos(400.f, 450.f);
	 //----Fbt
	 Fbt.make_text("MorningRainbow.ttf", "F");
	 Fbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Fbt.text_pos(550.f, 450.f);
	 //----Gbt
	 Gbt.make_text("MorningRainbow.ttf", "G");
	 Gbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Gbt.text_pos(700.f, 450.f);
	 //----Hbt
	 Hbt.make_text("MorningRainbow.ttf", "H");
	 Hbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Hbt.text_pos(850.f, 450.f);
	 //----Jbt
	 Jbt.make_text("MorningRainbow.ttf", "J");
	 Jbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Jbt.text_pos(1000.f, 450.f);
	 //----Kbt
	 Kbt.make_text("MorningRainbow.ttf", "K");
	 Kbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Kbt.text_pos(1150.f, 450.f);
	 //----Lbt
	 Lbt.make_text("MorningRainbow.ttf", "L");
	 Lbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Lbt.text_pos(1300.f, 450.f);
	 //----Nbt
	 Nbt.make_text("MorningRainbow.ttf", "N");
	 Nbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Nbt.text_pos(1450.f, 450.f);
	 //----Mbt
	 Mbt.make_text("MorningRainbow.ttf", "M");
	 Mbt.shape_text(72, Color(7, 128, 13, 150), 0, 0);
	 Mbt.text_pos(1600.f, 450.f);
	//--------------------------------------------------------------
	//--------------black blanks text-------------------------------
	//----Wbt
	 Wbt.make_text("MorningRainbow.ttf", "W");
	 Wbt.shape_text(72, Color::Black, 0, 0);
	 Wbt.text_pos(175.f, 250.f);
	 //----Ebt
	 Ebt.make_text("MorningRainbow.ttf", "E");
	 Ebt.shape_text(72, Color::Black, 0, 0);
	 Ebt.text_pos(325.f, 250.f);
	 //----Tbt
	 Tbt.make_text("MorningRainbow.ttf", "T");
	 Tbt.shape_text(72, Color::Black, 0, 0);
	 Tbt.text_pos(625.f, 250.f);
	 //----Ybt
	 Ybt.make_text("MorningRainbow.ttf", "Y");
	 Ybt.shape_text(72, Color::Black, 0, 0);
	 Ybt.text_pos(775.f, 250.f);
	 //----Ubt
	 Ubt.make_text("MorningRainbow.ttf", "U");
	 Ubt.shape_text(72, Color::Black, 0, 0);
	 Ubt.text_pos(925.f, 250.f);
	 //----Obt
	 Obt.make_text("MorningRainbow.ttf", "O");
	 Obt.shape_text(72, Color::Black, 0, 0);
	 Obt.text_pos(1225.f, 250.f);
	 //----Pbt
	 Pbt.make_text("MorningRainbow.ttf", "P");
	 Pbt.shape_text(72, Color::Black, 0, 0);
	 Pbt.text_pos(1375.f, 250.f);
	 intial_time();
 }
//------------------------------------------------------------------
 
 void to_run_piano() {

	 //----------------play sounds-----------------
	 //--mouse
	 if (mouse_l()) {
		 if (Abt.mouse_intersects(win, Abt.sp)) {
			 Abt.music.play();
			 Abt.todraw = 1;
		 }
		 if (Sbt.mouse_intersects(win, Sbt.sp)) {
			 Sbt.music.play();
			 Sbt.todraw = 1;
		 }
		 if (Dbt.mouse_intersects(win, Dbt.sp)) {
			 Dbt.music.play();
			 Dbt.todraw = 1;
		 }
		 if (Fbt.mouse_intersects(win, Fbt.sp)) {
			 Fbt.music.play();
			 Fbt.todraw = 1;
		 }
		 if (Gbt.mouse_intersects(win, Gbt.sp)) {
			 Gbt.music.play();
			 Gbt.todraw = 1;
		 }
		 if (Hbt.mouse_intersects(win, Hbt.sp)) {
			 Hbt.music.play();
			 Hbt.todraw = 1;
		 }
		 if (Jbt.mouse_intersects(win, Jbt.sp)) {
			 Jbt.music.play();
			 Jbt.todraw = 1;
		 }
		 if (Kbt.mouse_intersects(win, Kbt.sp)) {
			 Kbt.music.play();
			 Kbt.todraw = 1;
		 }
		 if (Lbt.mouse_intersects(win, Lbt.sp)) {
			 Lbt.music.play();
			 Lbt.todraw = 1;
		 }
		 if (Nbt.mouse_intersects(win, Nbt.sp)) {
			 Nbt.music.play();
			 Nbt.todraw = 1;
		 }
		 if (Mbt.mouse_intersects(win, Mbt.sp)) {
			 Mbt.music.play();
			 Mbt.todraw = 1;
		 }
		 if (Wbt.mouse_intersects(win, Wbt.sp)) {
			 Wbt.music.play();
			 Wbt.todraw = 1;
		 }
		 if (Ebt.mouse_intersects(win, Ebt.sp)) {
			 Ebt.music.play();
			 Ebt.todraw = 1;
		 }
		 if (Tbt.mouse_intersects(win, Tbt.sp)) {
			 Tbt.music.play();
			 Tbt.todraw = 1;
		 }
		 if (Ybt.mouse_intersects(win, Ybt.sp)) {
			 Ybt.music.play();
			 Ybt.todraw = 1;
		 }
		 if (Ubt.mouse_intersects(win, Ubt.sp)) {
			 Ubt.music.play();
			 Ubt.todraw = 1;
		 }
		 if (Obt.mouse_intersects(win, Obt.sp)) {
			 Obt.music.play();
			 Obt.todraw = 1;
		 }
		 if (Pbt.mouse_intersects(win, Pbt.sp)) {
			 Pbt.music.play();
			 Pbt.todraw = 1;
		 }
	 }
	 //--button
	 // if_keyy_pressed

	 if (Keyboard::isKeyPressed(Keyboard::A) && !Abt.todraw) {
		 Abt.music.play();
		 Abt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::S) && !Sbt.todraw) {
		 Sbt.music.play();
		 Sbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::D) && !Dbt.todraw) {
		 Dbt.music.play();
		 Dbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::F) && !Fbt.todraw) {
		 Fbt.music.play();
		 Fbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::G) && !Gbt.todraw) {
		 Gbt.music.play();
		 Gbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::H) && !Hbt.todraw) {
		 Hbt.music.play();
		 Hbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::J) && !Jbt.todraw) {
		 Jbt.music.play();
		 Jbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::K) && !Kbt.todraw) {
		 Kbt.music.play();
		 Kbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::L) && !Lbt.todraw) {
		 Lbt.music.play();
		 Lbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::N) && !Nbt.todraw) {
		 Nbt.music.play();
		 Nbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::M) && !Mbt.todraw) {
		 Mbt.music.play();
		 Mbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::W) && !Wbt.todraw) {
		 Wbt.music.play();
		 Wbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::E) && !Ebt.todraw) {
		 Ebt.music.play();
		 Ebt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::T) && !Tbt.todraw) {
		 Tbt.music.play();
		 Tbt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::Y) && !Ybt.todraw) {
		 Ybt.music.play();
		 Ybt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::U) && !Ubt.todraw) {
		 Ubt.music.play();
		 Ubt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::O) && !Obt.todraw) {
		 Obt.music.play();
		 Obt.todraw = 1;
	 }
	 if (Keyboard::isKeyPressed(Keyboard::P) && !Pbt.todraw) {
		 Pbt.music.play();
		 Pbt.todraw = 1;
	 }



	 //----------------drawings--------------------
	 //todraw =0 for sp, =1 for shadow.
	 //---Abt
	 win.draw(entity_time.text);
	 if (Abt.todraw)win.draw(Abt.shadow_sp);
	 else win.draw(Abt.sp);
	 //---Sbt
	 if (Sbt.todraw)win.draw(Sbt.shadow_sp);
	 else win.draw(Sbt.sp);
	 //---Dbt
	 if (Dbt.todraw)win.draw(Dbt.shadow_sp);
	 else win.draw(Dbt.sp);
	 //---Fbt
	 if (Fbt.todraw)win.draw(Fbt.shadow_sp);
	 else win.draw(Fbt.sp);
	 //---Gbt
	 if (Gbt.todraw)win.draw(Gbt.shadow_sp);
	 else win.draw(Gbt.sp);
	 //---Hbt
	 if (Hbt.todraw)win.draw(Hbt.shadow_sp);
	 else win.draw(Hbt.sp);
	 //---Jbt
	 if (Jbt.todraw)win.draw(Jbt.shadow_sp);
	 else win.draw(Jbt.sp);
	 //---Kbt
	 if (Kbt.todraw)win.draw(Kbt.shadow_sp);
	 else win.draw(Kbt.sp);
	 //---Lbt
	 if (Lbt.todraw)win.draw(Lbt.shadow_sp);
	 else win.draw(Lbt.sp);
	 //---Nbt
	 if (Nbt.todraw)win.draw(Nbt.shadow_sp);
	 else win.draw(Nbt.sp);
	 //---Mbt
	 if (Mbt.todraw)win.draw(Mbt.shadow_sp);
	 else win.draw(Mbt.sp);
	 //---Wbt
	 if (Wbt.todraw)win.draw(Wbt.shadow_sp);
	 else win.draw(Wbt.sp);
	 //---Ebt
	 if (Ebt.todraw)win.draw(Ebt.shadow_sp);
	 else win.draw(Ebt.sp);
	 //---Tbt
	 if (Tbt.todraw)win.draw(Tbt.shadow_sp);
	 else win.draw(Tbt.sp);
	 //---Ybt
	 if (Ybt.todraw)win.draw(Ybt.shadow_sp);
	 else win.draw(Ybt.sp);
	 //---Ubt
	 if (Ubt.todraw)win.draw(Ubt.shadow_sp);
	 else win.draw(Ubt.sp);
	 //---Obt
	 if (Obt.todraw)win.draw(Obt.shadow_sp);
	 else win.draw(Obt.sp);
	 //---Pbt
	 if (Pbt.todraw)win.draw(Pbt.shadow_sp);
	 else win.draw(Pbt.sp);
	 //--------------------------------------------
	 //-----show piano letter---
	 win.draw(Abt.text);
	 win.draw(Sbt.text);
	 win.draw(Dbt.text);
	 win.draw(Fbt.text);
	 win.draw(Gbt.text);
	 win.draw(Hbt.text);
	 win.draw(Jbt.text);
	 win.draw(Kbt.text);
	 win.draw(Lbt.text);
	 win.draw(Nbt.text);
	 win.draw(Mbt.text);
	 win.draw(Wbt.text);
	 win.draw(Ebt.text);
	 win.draw(Tbt.text);
	 win.draw(Ybt.text);
	 win.draw(Ubt.text);
	 win.draw(Obt.text);
	 win.draw(Pbt.text);
	 win.display();

	 // reinitialize
	 Abt.todraw = 0;
	 Sbt.todraw = 0;
	 Dbt.todraw = 0;
	 Fbt.todraw = 0;
	 Gbt.todraw = 0;
	 Hbt.todraw = 0;
	 Jbt.todraw = 0;
	 Kbt.todraw = 0;
	 Lbt.todraw = 0;
	 Nbt.todraw = 0;
	 Mbt.todraw = 0;
	 Wbt.todraw = 0;
	 Ebt.todraw = 0;
	 Tbt.todraw = 0;
	 Ybt.todraw = 0;
	 Ubt.todraw = 0;
	 Obt.todraw = 0;
	 Pbt.todraw = 0;

 }


