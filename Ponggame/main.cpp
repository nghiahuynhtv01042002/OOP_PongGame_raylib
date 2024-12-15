#include <iostream>
#include <raylib.h>


int player_Score = 0;
int CPU_Score = 0;
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
    float getRadius(){
        return this->radius;
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
    void setX_Speed(int newXSpeed){
        this->xSpeed = newXSpeed;
    }
    void setY_Speed(int newYSpeed){
        this->ySpeed = newYSpeed;
    }
    void Draw(){
        DrawCircle(xPosition, yPosition, radius, WHITE);
    }
    void Reset_ball(){
        xPosition = GetScreenWidth()/2;
        yPosition = GetScreenHeight()/2;
        int speed_choice[2] = {-1,1};
        xSpeed *= speed_choice[GetRandomValue(0,1)];
        ySpeed *= speed_choice[GetRandomValue(0,1)];
    }
    void UpdatePostion(){
        this->xPosition += this->xSpeed;
        this->yPosition += this->ySpeed;
        if((int)(this->yPosition + this->radius) >= GetScreenHeight() || this->yPosition -  this->radius <=0){
            this->ySpeed *=-1;
        }
        if((int)(this->xPosition + this->radius) >= GetScreenWidth()){
            player_Score++;

            Reset_ball();
        }
        if(this->xPosition - this->radius <=0){
            CPU_Score++;
            Reset_ball();
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
    void updateYPosition(int newpos){
        this->yPosition +=newpos;
    }
    void setSpeed(int speed){
        this->speed = speed;
    }   
    void setPosition(float xPos ,float yPos){
        this->xPosition = xPos;
        this->yPosition = yPos;
    }
    void setYPos(float new_yPosition){
        this->yPosition = new_yPosition;
    }
    void set_HW(int height, int width){
        this->height = height;
        this->width = width;
    }
    float getX_Pos(){
        return xPosition;
    }
    float getY_Pos(){
        return yPosition;
    }
    int getSpeed(){
        return speed;
    }
    void Draw(){
        DrawRectangle(xPosition ,yPosition,width,height,WHITE);
    }
    int getHeigth(){
        return height;
    }
    int getWidth(){
        return width;
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
class CPUPaddle:public Paddle{
public: 
    CPUPaddle(float xPos, float yPos, int height, int width, int speed)
        : Paddle(xPos, yPos, height, width, speed){}
    void UpdatePostion(float y_Position_Ball ){
        if(getY_Pos()+getHeigth() /2 > y_Position_Ball){
           this->updateYPosition(-getSpeed());
        }
        if(getY_Pos()+getHeigth() /2 <= y_Position_Ball){
           this->updateYPosition(getSpeed());
        }
        if(getY_Pos() <=0){
            setYPos(0);
        }
        if(getY_Pos()+ getHeigth() >= GetScreenHeight()){
            setYPos(GetScreenHeight() - getHeigth());
        }
    }
};


int main () {
    const int screen_width = 1280;
    const int screen_height = 800;
    const char* titile = "Pong Game made by TXN";
    InitWindow(screen_width, screen_height, titile);
    SetTargetFPS(60);
    /*INITIAL OBJECT*/
    Ball ball(screen_width/2, screen_height/2, 20.00);
    ball.setSpeed(7 ,7);

    Paddle player1(0,0,0,0);
    player1.set_HW(120,25);
    player1.setPosition(10,screen_height/2-player1.getHeigth()/2);
    player1.setSpeed(6);

    CPUPaddle CPUplayer(0,0,0,0,0);
    CPUplayer.set_HW(120,25);
    CPUplayer.setPosition(screen_width -CPUplayer.getWidth() -10,screen_height/2-player1.getHeigth()/2);
    CPUplayer.setSpeed(6);
    
    /*GAME LOOP*/
    while(!WindowShouldClose()){
        // int endgame =0;
        
        BeginDrawing();
      
        // if(CPU_Score>=3){
        //     DrawText("YOU LOST", screen_width/4 -40,100, 100, WHITE);
        //     endgame =1;
        // }
        // if(player_Score>=3){
        //     DrawText("YOU WIN", screen_width/4-40,100, 100, WHITE);
        //     endgame =1;
        // }
        /*MAIN EVENTS*/
        if(CheckCollisionCircleRec( Vector2{ball.getX_Pos(), ball.getY_Pos()}, ball.getRadius() ,Rectangle{ player1.getX_Pos(), player1.getY_Pos(),(float) player1.getWidth(), (float)player1.getHeigth()})){
            ball.setX_Speed(-1*ball.getX_Speed());
        }
        if(CheckCollisionCircleRec( Vector2{ball.getX_Pos(), ball.getY_Pos()}, ball.getRadius() ,Rectangle{ CPUplayer.getX_Pos(), CPUplayer.getY_Pos(),(float) CPUplayer.getWidth(), (float)CPUplayer.getHeigth()})){
            ball.setX_Speed(-1*ball.getX_Speed());

        }
        /*UPDATE STATUS OBJECT*/
        ball.UpdatePostion();
        player1.UpdatePostion();
        CPUplayer.UpdatePostion(ball.getY_Pos());
        /*DRAWING OBJECT*/
        ClearBackground(BLACK);
        ball.Draw();
        player1.Draw();
        CPUplayer.Draw();
        DrawLine(screen_width/2, 0 ,screen_width/2, screen_height ,WHITE);
        DrawText(TextFormat("%i",player_Score), screen_width/4-20,20, 80, WHITE);
        DrawText(TextFormat("%i",CPU_Score), 3*screen_width/4-20,20, 80, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}