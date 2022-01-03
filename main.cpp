#include<iostream>
#include<simplecpp>
#include<string>
#include<ctype.h>

using namespace std;

void clickPos()
{
    float clickpos[2]={getClick()/65536,getClick()%65536};
    cout<<clickpos[0]<<"\t"<<clickpos[1]<<endl;
}



void prePlay();

void play()
{
    int car_body_start[2]={0,0},car_wheel1_start[2]={36,177},car_wheel2_start[2]={116,177};
    prePlay();
    Line l1(0,200,600,200);
    Line l2(0,196,600,196);
    Line l3(0,194,600,194);
    l3.setColor(COLOR(255,255,255));
    Line l4(0,190,600,190);
    Line l5(0,186,600,186);
    double sides[13][2]={16,148,16,169,30,169,55,171,90,172,118,172,142,177,133,157,114,154,96,140,50,140,33,157,16,148};
    Polygon b(car_body_start[0],car_body_start[1],sides,13);
    b.setFill();
    Circle w1(car_wheel1_start[0],car_wheel1_start[1],10);
    Circle w2(car_wheel2_start[0],car_wheel2_start[1],10);
    w1.setFill();
    w2.setFill();
   // while(1)clickPos();
    wait(10);
    int k=1;
    while( k!=0)
    {
    for(int m=0;m<=50;m++)
    {
    b.moveTo(car_body_start[0]+=m,0);
    w1.moveTo(car_wheel1_start[0]+=m,177);
    w2.moveTo(car_wheel2_start[0]+=m,177);
    }
    wait(2);
    k--;
    }
    while(1)clickPos();
}

void menu()
{
    Rectangle bg(300,300,600,600);
    bg.setColor(COLOR(48,48,48));
    bg.setFill();
    char ch;
    XEvent e1;
    {
        Text t(300, 50, "DRIVE!");
        t.setColor(COLOR(255, 0, 0));
        Text t1(300, 110, "M E N U");
        Text t2(300, 140, "1: Start Game");
        Text t3(300, 170, "2: Help");
        Text t4(300, 200, "3: Credits");
        Text t5(300, 230, "4: Exit");
        nextEvent(e1);
        ch = charFromEvent(e1);
    }
    switch (ch)
    {
        case 49:play();
                break;
        case 50:XEvent e2;
                {
                        Text t1(300, 220, "Controls: ");
                        Text t2(300, 260, "Goal: ");
                        Text t3(300, 300, "-");
                        Text t4(300, 340, "-");
                        Text t5(300, 380, "-");
                        Text t6(300, 420, "-");
                        Text t7(300, 460, "Press any key to go back!");
                        t7.setColor(COLOR(255, 0, 0));
                        nextEvent(e2);
                        int an = charFromEvent(e2);
                        if (an)
                        {
                            t1.~Text();
                            t2.~Text();
                            t3.~Text();
                            t4.~Text();
                            t5.~Text();
                            t6.~Text();
                            t7.~Text();
                            menu();
                        }
                    }
        case 51:XEvent e3;
                {
                        Text t1(300, 220, "CREDITS:");
                        Text t2(300, 260, "Project Members: ");
                        Text t3(300, 300, "Chinmay Joshi, Shubham Tendulkar, Vadiraj Inamdar, Vibhav Desai");
                        Text t4(300, 340, "Teacher Incharge: Prof. Amrita Naik");
                        Text t5(300, 380, "Press any key to go back!");
                        t5.setColor(COLOR(255, 0, 0));
                        nextEvent(e3);
                        int an = charFromEvent(e3);
                        if (an)
                        {
                            t1.~Text();
                            t2.~Text();
                            t3.~Text();
                            t4.~Text();
                            t5.~Text();
                            menu();
                        }
                    }
        case 52:closeCanvas();
                break;
        default:menu();
                break;
    }
}

void ageRestrict()
{
        XEvent e;
        {
            Text t1(300, 300, "You are not eligible to take this test!");
            Text t2(300, 350, "Press any key to go back!");
            t2.setColor(COLOR(255, 0, 0));
            nextEvent(e);
            int an = charFromEvent(e);
            if (an)
            {
                t1.~Text();
                t2.~Text();
            }
        }
}

void prePlay()
{
        int year=2000;
        Text t(300, 50, "W E L C O M E !");
        t.setColor(COLOR(255, 0, 0));
        Text t1(300, 110, "Few things before starting");
        Text t2(300, 140, "Enter your year of birth");
        Text t3(300, 170, "YYYY: ");
        Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()),170,year);
        Text t4(310+(textWidth("YYYY: ")/2),170," - ");
        Rectangle dec(310+(textWidth("YYYY: ")/2),170,textHeight(),textHeight());
        Text t5(305+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()),170," + ");
        Rectangle inc(305+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()),170,textHeight(),textHeight());
        Rectangle db(340+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()),170,textWidth("DONE"),textHeight());
        Text db_t(340+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()),170,"DONE");
        while(1)
        {
            XEvent e;
            {
                nextEvent(e);
                if(mouseButtonPressEvent(e))
                {
                    if(e.xbutton.x>328 && e.xbutton.x<341)
                    {
                        if(e.xbutton.y>161 && e.xbutton.y<175)
                        {
                            y.~Text();
                            year--;
                            Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()),170,year);
                            while(!getClick())
                            wait(0.5);
                        }
                    }
                    if(e.xbutton.x>394 && e.xbutton.x<408)
                    {
                        if(e.xbutton.y>161 && e.xbutton.y<175)
                        {
                            y.~Text();
                            year++;
                            Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()),170,year);
                            while(!getClick())
                            wait(0.5);
                        }
                    }
                    if(e.xbutton.x>418 && e.xbutton.x<454)
                    {
                        if(e.xbutton.y>161 && e.xbutton.y<175)
                        {
                            cout<<endl<<year<<endl;
                            break;
                        }
                    }
                }
            }
        }
        t2.~Text();
        t3.~Text();
        t4.~Text();
        t5.~Text();
        y.~Text();
        db_t.~Text();
        dec.~Rectangle();
        inc.~Rectangle();
        db.~Rectangle();
        if(2021-year<18)
        {
            ageRestrict();
            menu();
        }
        string name_user;
        XEvent name;
        {
        int i=0;
        Text a(300,200,"Type your name: ");
        while(1)
        {
            nextEvent(name);
            if(mouseButtonPressEvent(name))continue;
            if(charFromEvent(name)==13) break;
            if(isdigit(charFromEvent(name))) continue;
            cout<<endl<<(int)charFromEvent(name)<<endl;
            name_user+= charFromEvent(name);
        }
        Text n(300,250,name_user);
        XEvent z;
        {
            Text t5(300, 380, "Press any key to proceed!");
            t5.setColor(COLOR(0, 255, 0));
            nextEvent(z);
            int an = charFromEvent(z);
            if (an)
            {
                a.~Text();
                n.~Text();
            }
        }
    }
    cout<<endl<<name_user<<endl;
    t1.~Text();
}

int main()
{
    initCanvas("DRIVE",600,600);
    menu();
    closeCanvas();
    getch();
}
