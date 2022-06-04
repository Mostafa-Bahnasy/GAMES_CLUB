#pragma once

int N = 30, M = 20;

int expand = 16*2;// width of recatngle
int w = expand * N; // width of screen
int h = expand * M; // hight of screen
int points = 0; // score
int fruitCnt = 0; // n%5=0 -> eat 5 fruits.
int dir;// left(1), right(2), up(3), down(0)
int  num = 4;// lenght of snake
bool gameOver = 0;
Texture t11, t21, t31;

Sprite sprite1; // white 
Sprite sprite2; // red
Sprite sprite3; // green
float timer = 0, delay = 0.1;
Clock snClock;
Text_C snakeScore;

struct Snake
{
    int x=0, y=0;

};
Snake snBoard[100]; // carry snake rectangles.

struct Fruit
{
    int x=0, y=0;
};

Fruit fruit;

void Tick()
{
    // head -> ind[0] -> snBoard
    for (int i = num; i > 0; --i)
    {

        snBoard[i].x = snBoard[i - 1].x; 
        snBoard[i].y = snBoard[i - 1].y;
       // snBoard[i].bl = 1;
    }
    //
    if (dir == 0) snBoard[0].y += 1; // down
    if (dir == 1) snBoard[0].x -= 1; // left
    if (dir == 2) snBoard[0].x += 1; // right
    if (dir == 3) snBoard[0].y -= 1; // up
    //
    //---------------------

    if ((snBoard[0].x == fruit.x) && (snBoard[0].y == fruit.y))
    {
        num++; // snake body
        //
        fruit.x = rand() % N;
        fruit.y = rand() % M;
        //
        fruitCnt++;
        if (fruitCnt % 5 == 0) {
            points += 100;
        }
        else {
            points += 32;
        }
    }

    if (snBoard[0].x > N) snBoard[0].x = 0;  
    if (snBoard[0].x < 0) snBoard[0].x = N;

    if (snBoard[0].y > M) snBoard[0].y = 0;  
    if (snBoard[0].y < 0) snBoard[0].y = M;

    // check collision of head and any recangle of body
    for (int i = 1; i < num; i++) {
        if (snBoard[0].x == snBoard[i].x && snBoard[0].y == snBoard[i].y) {
            gameOver = 1; return;
        }
    }
}

void setSnake() {

    t11.loadFromFile("assets\\snake\\white.png");
    t21.loadFromFile("assets\\snake\\red.png");
    t31.loadFromFile("assets\\snake\\green.png");
   sprite1.setTexture(t11); // white 
   sprite2.setTexture(t21); // red
    sprite3.setTexture(t31); // green
    //
    sprite1.setScale(Vector2f(2.f, 2.f)); // 1*1 -> 2*1-> 2 * 2;
    sprite2.setScale(Vector2f(2.f, 2.f));
    sprite3.setScale(Vector2f(2.f, 2.f));
    //
    //

    fruit.x = 10;
    fruit.y = 10;
    // bahnasy
    //-----points score
    snakeScore.make_text("alfont_com_arial-1.ttf", "0");
    snakeScore.shape_text(46, Color::Blue);
    snakeScore.text_pos(50.f, 50.f);
    //

}

void to_run_snake()
{

    
        gameOver = 0;
        float time = snClock.getElapsedTime().asSeconds();
        snClock.restart();
        timer += time;
      
        //////////////////////////////////////////////////
        //
        if (Keyboard::isKeyPressed(Keyboard::Left)&& dir!=2) dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right)&& dir!=1) dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up)&&dir!=0) dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down)&&dir!=3) dir = 0;
        //
        if (timer > delay) { timer = 0; Tick(); }

        ////////////////////////////////////////////////////////////////////
        //////  draw  ///////

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                sprite1.setPosition(i * expand, j * expand);  // white
                win.draw(sprite1);
            }

        for (int i = 0; i < num; i++)
        {
            sprite2.setPosition(snBoard[i].x * expand, snBoard[i].y * expand); //red 
            win.draw(sprite2);
        }
        //
        sprite3.setPosition(fruit.x * expand, fruit.y * expand);  // fruit
        win.draw(sprite3);
        ////////////////////////////////////////////////////////////////////
        //
        // bahnasy
        //
        win.draw(snakeScore.text);
        //
        win.display();
        //
       
        // check points
        snakeScore.text_str(to_string(points));
        //-------------
        
        // bahnasy
        ///////////////
        if (gameOver) {
            arr_acc[ind].money += ((points / 500) * 5LL);
            if (play_again(win)) {
                // take money 

                arr_acc[ind].money -= snakeCost;
                if (arr_acc[ind].money <= 0) {
                    arr_acc[ind].money += snakeCost;
                    window = 1;
                }
                num = 4;
                points = 0;
                fruitCnt = 0;
                Sleep(300);
            }
            else {
                Sleep(300);// 300 ms
                window = 1;
            }
        }
        //////////////

    }




