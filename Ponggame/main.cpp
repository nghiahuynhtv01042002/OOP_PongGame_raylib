#include <iostream>
#include <raylib.h>
class Ball{
private: 
    float xPosition ,yPosition;
    float radius;
    int xSpeed, ySpeed; 
public:
    Ball(float xPos ,float yPos,float radius,int xSpeed, int ySpeed):
        xPosition(xPos), yPosition(yPos) ,radius(radius) ,xSpeed(xSpeed) ,ySpeed(ySpeed){}
   
    
    Ball(float xPos ,float yPos,float radius):
        xPosition(xPos), yPosition(yPos) ,radius(radius) ,xSpeed(0) ,ySpeed(0){}

    void setPosition(float xPos ,float yPos){
        this->xPosition = xPos;
        this->yPosition = yPos;
    }
    void setRadius(float radius){
        this->radius = radius;
    }
    void setSpeed(int xSpeed, int ySpeed){
        this->xSpeed = xSpeed;
        this->ySpeed = ySpeed;
    }
    float getX_Pos(){
        return xPosition;
    }
    float getY_Pos(){
        return yPosition;
    }
    int getX_Speed(){
        return xSpeed;
    }
    int getY_Speed(){
        return ySpeed;
    }
    void Draw(){
        DrawCircle(xPosition, yPosition, radius, WHITE);
    }
    void UpdatePostion(){
        this->xPosition += this->xSpeed;
        this->yPosition += this->ySpeed;
        if((int)(this->yPosition + this->radius) >= GetScreenHeight() || this->yPosition -  this->radius <=0){
            this->ySpeed *=-1;
        }
        if((int)(this->xPosition + this->radius) >= GetScreenWidth() || this->xPosition - this->radius <=0){
            this->xSpeed *=-1;
        }
    }
};
class Paddle{
private: 
    float xPosition,  yPosition;
    int  height, width ;
    int speed;
public: 
    Paddle():xPosition(0),yPosition(0), height(0),width(0),speed(0){}
    Paddle(float xPos, float yPos , int height, int width):
        xPosition(xPos),yPosition(yPos), height(height),width(width),speed(0){}
    Paddle(float xPos, float yPos , int height, int width, int speed):
        xPosition(xPos),yPosition(yPos), height(height),width(width),speed(speed){}
    void setSpeed(int speed){
        this->speed = speed;
    }   
    void setPosition(float xPos ,float yPos){
        this->xPosition = xPos;
        this->yPosition = yPos;
    }
    void seth_HW(int height, int width){
        this->height = height;
        this->width = width;
    }
    void Draw(){
        DrawRectangle(xPosition ,yPosition,width,height,WHITE);
    }
    int getHeigth(){
        return height;
    }
    void UpdatePostion(){
        if(IsKeyDown(KEY_UP)){
            yPosition -=speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            yPosition +=speed;
        }
         if(yPosition <=0){
            yPosition =0;
        }
        if(yPosition+ height >= GetScreenHeight()){
            yPosition = GetScreenHeight() - height;
        }
    }
};

int main () {
    const int screen_width = 1280;
    const int screen_height = 800;
    const char* titile = "Pong Game made by TXN";
    InitWindow(screen_width, screen_height, titile);
    SetTargetFPS(60);

    Ball ball(screen_width/2, screen_height/2, 20.00);
    ball.setSpeed(7 ,7);

    Paddle player1(0,0,0,0);
    player1.seth_HW(120,25);
    player1.setPosition(10,screen_height/2-player1.getHeigth()/2);
    player1.setSpeed(6);

    while(!WindowShouldClose()){
        BeginDrawing();
        ball.UpdatePostion();
        player1.UpdatePostion();

        // Drawing  stuff
        ClearBackground(BLACK);
        ball.Draw();
        player1.Draw();
        // DrawRectangle(10,screen_height/2-60,25,120,WHITE);
        // DrawRectangle(screen_width -35 ,screen_height/2-60,25,120,WHITE);
        DrawLine(screen_width/2, 0 ,screen_width/2, screen_height ,WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}