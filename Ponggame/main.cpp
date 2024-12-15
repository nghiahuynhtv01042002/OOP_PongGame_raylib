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
int main () {
    const int screen_width = 1280;
    const int screen_height = 800;
    const char* titile = "Pong Game made by TXN";
    InitWindow(screen_width, screen_height, titile);
    SetTargetFPS(60);
    Ball ball(screen_width/2, screen_height/2, 20.00);
    ball.setSpeed(7 ,7);
    while(!WindowShouldClose()){
        BeginDrawing();
        ball.UpdatePostion();
        // Drawing  stuff
        ClearBackground(BLACK);
        ball.Draw();
        DrawRectangle(10,screen_height/2-60,25,120,WHITE);
        DrawRectangle(screen_width -35 ,screen_height/2-60,25,120,WHITE);
        DrawLine(screen_width/2, 0 ,screen_width/2, screen_height ,WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}