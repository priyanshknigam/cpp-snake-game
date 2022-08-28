// Created By: Priyansh Kumar Nigam
// Snake Game
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameover = false;
int width = 20, height = 20;
int scorect = 0, maxsc {};
int x {}, y{};
int tailx[100] = {}, taily[100] = {};
int ntail {};
static int foodx {}, foody {}, score {};
enum gdirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
gdirection dir;
int scores[100] = {};


void setup() {
    
    gameover = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    foodx = (rand()%(width-2))+1;
    foody = (rand()%(height-2))+1;
}

void display() {
    system("cls");
    for (int j {}; j<height; j++) {
        for (int i {}; i<width; i++) {
        if (i == 0 || j == 0 || i == width-1 || j == height-1)
        {
            cout<<"#";
        }
        else if (i == x&& j == y)
        {
            cout<<"O";
        }
        else if (i == foodx && j == foody)
        {
            cout<<"F";
        }
        else 
        {
            bool temp = false;
            for (int k {}; k<ntail; k++)
            {
                if (tailx[k] == i && taily[k] == j)
                {
                    cout<<"o";
                    temp = true;
                }
            
            }
            if (!temp)
                cout<<" ";
        }
        }
        cout<<endl;
    }
    cout<<endl;
    if (score>maxsc)
        cout<<"Score: "<<score<<"\t"<<"High Score: "<<score<<endl;
    else
        cout<<"Score: "<<score<<"\t"<<"High Score: "<<maxsc<<endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                dir = STOP;
                break;
        }
    }
}

void logic()
{
    
    
    int prevx {tailx[0]}, prevy {taily[0]}, prev2x {}, prev2y {};
    tailx[0] = x;
    taily[0] = y;
    
    for (int i = 1; i<ntail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    
    switch (dir)
    {
        case LEFT:
                x--;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            case RIGHT:
                x++;
                break;
            case STOP:
                break;
    }
    if (x == width-1 || x <= 0 || y == height-1 || y <= 0)
    {
        gameover = true;
    }
    for (int i =0; i<ntail; i++)
    {
        if (tailx[i] == x && taily[i] == y)
            gameover = true;
    }
    if (x == foodx && y == foody)
    {
        score += 10;
        foodx = (rand()%(width-2))+1;
        foody = (rand()%(height-2))+1;
        ntail++;
    }
    
    
    
//     cout<<"\nFoodx vakue is: "<<foodx <<endl;
//     cout<<"\nFoody vakue is: "<<foody <<endl;
}

int main() {
    char dif,c;
    bool replay = true;
//    setup();
//    display();
//    input();
//    logic();
    cout<<"Welcome to Snake Game"<<endl;
    cout<<"Choose Difficulty: Hard (h), Medium(m), Easy (e): ";
    cin>>dif;
    while (replay)
    {
        x =0;
        y = 0;
        tailx[100] = {0}; 
        taily[100] = {0};
        ntail = 0;
        foodx =0;
        foody =0; 
        score =0;;
        enum gdirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        gdirection dir;
        setup();
        while (!gameover) {
            display();
            input();
            logic();
            if (dif == 'e')
                Sleep(100);
            else if (dif == 'm')
                Sleep(50);
        }
        replay = false;
        if (scorect == 0)
        {
            maxsc = score;
            scorect++;
            cout<<"Your score was "<<score<<" current high score is "<<maxsc<<endl;
        }
        else if (maxsc < score)
        {
            maxsc = score;
            cout<<"Cognratulations! you've made new high score of  "<<maxsc<<endl;            
        }
        else 
        {
            cout<<"Game Over! Better luck next time"<<endl;
            cout<<"Your score was "<<score<<" current high score is "<<maxsc<<endl;
        }
        cout<<"Press c to continue playing, any other button to exit: ";
        
        cin>>c;
        if (c=='c')
        {
            replay = true;
            gameover = false;
        }
    }
    
    return 0;
}