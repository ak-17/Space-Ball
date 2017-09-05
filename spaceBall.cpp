#include<graphics.h>
#include<bits/stdc++.h>
#define XMAX 639
#define YMAX 450
using namespace std;
int b_x;
int b_y;
int b_x2;
int b_y2;
void ball(int x,int y)
{
    setfillstyle(1,WHITE);
    fillellipse(x,y,10,10);
}

int xdirection (int x,int y,int flag)
{
    if(x>=XMAX || x<=0)
    {
        flag = -1 * flag;
    }
    return flag;
}
int ydirection(int x,int y,int flag)
{
    if(y>=YMAX || y<=30)
    {
        flag = -1 * flag;
    }
    return flag;
}

bool bartouch(int x,int y)
{
    if((b_x-50 <= x)&& (b_x+50 >=x) && (b_y <=y)&&(b_y+10>=y))
    {
        return true;
    }
    else
        return false;
}

bool bartouch2(int x,int y)
{
    if((b_x2-50 <= x)&& (b_x2+50 >=x) && (b_y2 <=y)&&(b_y2+10>=y))
    {
        return true;
    }
    else
        return false;
}
void drawbar(int x,int y)
{
    setfillstyle(1,WHITE);
    bar(x-50,y,x+50,y+10);
    fillellipse(x-50,y+5,5,5);
    fillellipse(x+50,y+5,5,5);
}
void drawbar2(int x,int y)
{
    setfillstyle(1,WHITE);
    bar(x-50,y,x+50,y+10);
    fillellipse(x-50,y+5,5,5);
    fillellipse(x+50,y+5,5,5);
}
void intro()
{
    settextjustify(1,1);
    //settextstyle(1,0,4);
    setcolor(WHITE);
    int flag = 1;
    int x=250,y=3;

    while(true)
    {
        outtextxy(300,240,"SPACE BALL");
        outtextxy(300,300,"Press any key");
        bar(x,250,x+50,250+y);
        x = x + flag*10;
        if(x>=400)
        {
            flag=-1;
        }
        if(x<=200)
        {
            flag=1;
        }
        if(kbhit())
            break;
        delay(100);
        cleardevice();
    }
    cleardevice();
}
int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    bool gameOver = false;
    int x=100,y=100;
    b_x=320,b_y=450;
    b_x2=320,b_y2=20;
    int flagx=1,flagy=1;
    float level = 0.1;
    int order;
    int arr[4] = {100,150,200,250};
    //cout<<getmaxx()<<" "<<getmaxy();
    intro();
    int prev_x=100,prev_y=100;
    int turn=1;
    while(!gameOver)
    {
        ball(x,y);
        setcolor(LIGHTGRAY);
        fillellipse(prev_x,prev_y,8,8);
        drawbar(b_x,b_y);
        drawbar2(b_x2,b_y2);
        if(turn==1)
        {
            delay(1000);
            turn++;
        }
        if(!bartouch(x,y) && (y>=450))
        {
            gameOver = true;
        }
        if(y<=30 && !bartouch2(x,y))
        {
            gameOver=true;
            //cout<<x<<" "<<y<<endl;
            //cout<<b_x2<<" "<<b_y2;
        }
        if(bartouch(x,y)||bartouch2(x,y))
        {
            level=level+0.1;
        }
        flagx = xdirection(x,y,flagx);
        flagy = ydirection(x,y,flagy);
        prev_x = x;
        prev_y = y;
        x = (x + (flagx * 10));
        y = y + (flagy * 10);
        if(kbhit())
        {
            char c = getch();
            if(c=='a' || c=='A')
            {
                b_x = b_x - 20;
                b_x2 = b_x2 -20;
            }
            else if (c=='d' || c=='D')
            {
                b_x = b_x + 20;
                b_x2 = b_x2 + 20;
            }
        }
        order = level;
        delay(arr[order]);
        cout<<level<<" "<<order<<" "<<arr[order]<<endl;
        cleardevice();
    }
    outtextxy(300,240,"GAME OVER");
    getch();
    return 0;
}
