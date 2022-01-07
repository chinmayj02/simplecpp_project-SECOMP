#include<iostream>
#include<simplecpp>
#include<string>
#include<ctype.h>
#include<ctime>
#include<fstream>
#include<stdlib.h>

using namespace std;

void prePlay();
int s=1;
int correctanswer=0;
string name_user;
int year=2000;// year of birth
char* dt;


class que
{
    char q[10000],op1[1000],op2[1000],op3[1000],op4[1000];
    int A,B,C,D;
    public:
        char* question(){return(q);}
        char* o1(){return(op1);}
        char* o2(){return(op2);}
        char* o3(){return(op3);}
        char* o4(){return(op4);}
        int correctanswer()
        {
            if(A==1)return(1);
            else if(B==1)return(2);
            else if(C==1)return(3);
            else return(4);
        }
};

// to get coordinates of mouse click
void clickPos()
{
    float clickpos[2]={getClick()/65536, getClick()%65536};
    cout<<clickpos[0]<<"\t"<<clickpos[1]<<endl;
}

int getans(int x,int y)
{
    if(((x>=58)&&(x<=161)) && ((y>=394)&&(y<=446 ))) return(10);
    else if(((x>=58)&&(x<=162))&&((y>=494)&&(y<=544))) return(20);
    else if(((x>=417)&&(x<=522))&&((y>=394)&&(y<=444))) return(30);
    else if(((x>=418)&&(x<=522))&&((y>=495)&&(y<=544))) return(40);
    else return(0);
}

void test(char q[],char op1[],char op2[],char op3[],char op4[],int v)
{
    int z=0,p;
    Rectangle RB(290,290,500,100);
    Rectangle ROP_1(110,420,175,50);
    Rectangle ROP_2(110,520,175,50);
    Rectangle ROP_3(470,420,175,50);
    Rectangle ROP_4(470,520,175,50);
    Circle C(290,460,40);
    Text q_in(290,460-textHeight(),"Q No:");
    string q_no="0";
    if(s==1) q_no.replace(0,1,"1");
    else if(s==2)q_no.replace(0,1,"2");
    else if(s==3)q_no.replace(0,1,"3");
    else if(s==4)q_no.replace(0,1,"4");
    else if(s==5)q_no.replace(0,1,"5");
    Text qno(290,460,q_no+"/5");
    Text A(260,290,q);
    Text OP1(110,420,op1);
    Text OP2(110,520,op2);
    Text OP3(470,420,op3);
    Text OP4(470,520,op4);
    stat:
    int a=getClick();
    int x=a/65536;
    int y=a%65536;
    z=getans(x,y);
    p=v;
    if(s==1)
    {
        if((z==10)&&(p==1))
        {
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
            correctanswer++;
        }
        else if((z==20)&&(p==1))
        {
            ROP_2.setColor(COLOR(255,99,71));
            ROP_2.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else if((z==30)&&(p==1))
        {
            ROP_3.setColor(COLOR(255,99,71));
            ROP_3.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else if((z==40)&&(p==1))
        {
            ROP_4.setColor(COLOR(255,99,71));
            ROP_4.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else goto stat;
    }
    else if(s==2)
    {
        if((z==20)&&(p==2))
        {
            ROP_2.setColor(COLOR(255,99,71));
            ROP_2.setFill();
            ROP_3.setColor(COLOR(0,255,0));
            ROP_3.setFill();
            wait(0.9);
        }
        else if((z==10)&&(p==2))
        {
            ROP_1.setColor(COLOR(255,99,71));
            ROP_1.setFill();
            ROP_3.setColor(COLOR(0,255,0));
            ROP_3.setFill();
            wait(0.9);
        }
        else if((z==30)&&(p==2))
        {
            ROP_3.setColor(COLOR(0,255,0));
            ROP_3.setFill();
            correctanswer++;
            wait(0.9);
        }
        else if((z==40)&&(p==2))
        {
            ROP_4.setColor(COLOR(255,99,71));
            ROP_4.setFill();
            ROP_3.setColor(COLOR(0,255,0));
            ROP_3.setFill();
            wait(0.9);
        }
        else goto stat;
    }
    else if(s==3)
    {
        if((z==30)&&(p==3))
        {
            ROP_3.setColor(COLOR(255,99,71));
            ROP_3.setFill();
            ROP_2.setColor(COLOR(0,255,0));
            ROP_2.setFill();
            wait(0.9);
        }
        else if((z==10)&&(p==3))
        {
            ROP_1.setColor(COLOR(255,99,71));
            ROP_1.setFill();
            ROP_2.setColor(COLOR(0,255,0));
            ROP_2.setFill();
            wait(0.9);
        }
        else if((z==20)&&(p==3))
        {
            ROP_2.setColor(COLOR(0,255,0));
            ROP_2.setFill();
            correctanswer++;
            wait(0.9);
        }
        else if((z==40)&&(p==3))
        {
            ROP_4.setColor(COLOR(255,99,71));
            ROP_4.setFill();
            ROP_2.setColor(COLOR(0,255,0));
            ROP_2.setFill();
            wait(0.9);
        }
        else goto stat;
    }
    else if(s==4)
    {
        if((z==10)&&(p==4))
        {
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            correctanswer++;
            wait(0.9);
        }
        else if((z==20)&&(p==4))
        {
            ROP_2.setColor(COLOR(255,99,71));
            ROP_2.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else if((z==30)&&(p==4))
        {
            ROP_3.setColor(COLOR(255,99,71));
            ROP_3.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else if((z==40)&&(p==4))
        {
            ROP_4.setColor(COLOR(255,99,71));
            ROP_4.setFill();
            ROP_1.setColor(COLOR(0,255,0));
            ROP_1.setFill();
            wait(0.9);
        }
        else goto stat;
    }
    else if(s==5)
    {
        if((z==40)&&(p==5))
        {
            ROP_4.setColor(COLOR(0,255,0));
            ROP_4.setFill();
            correctanswer++;
            wait(0.9);
        }
        else if((z==30)&&(p==5))
        {
            ROP_3.setColor(COLOR(255,99,71));
            ROP_3.setFill();
            ROP_4.setColor(COLOR(0,255,0));
            ROP_4.setFill();
            wait(0.9);
        }
        else if((z==20)&&(p==5))
        {
            ROP_2.setColor(COLOR(255,99,71));
            ROP_2.setFill();
            ROP_4.setColor(COLOR(0,255,0));
            ROP_4.setFill();
            wait(0.9);
        }
        else if((z==10)&&(p==5))
        {
            ROP_1.setColor(COLOR(255,99,71));
            ROP_1.setFill();
            ROP_4.setColor(COLOR(0,255,0));
            ROP_4.setFill();
            wait(0.9);
        }
        else goto stat;
    }
    s++;
    if(s>=6)
    {
        RB.~Rectangle();
        ROP_1.~Rectangle();
        ROP_2.~Rectangle();
        ROP_3.~Rectangle();
        ROP_4.~Rectangle();
        C.~Circle();
        A.~Text();
        OP1.~Text();
        OP2.~Text();
        OP3.~Text();
        OP4.~Text();
        return;
    }
}

void play()
{
    string status="0000";
    int car_body_start[2]={0, 0},car_wheel1_start[2]={36, 177},car_wheel2_start[2]={116, 177};
    prePlay();
    // lines below car -road
    Line l1(0, 200, 600, 200);
    Line l2(0, 196, 600, 196);
    Line l3(0, 194, 600, 194);
    l3.setColor(COLOR(255, 255, 255));
    Line l4(0, 190, 600, 190);
    Line l5(0, 186, 600, 186);
    double sides[13][2]={16,148,16,169,30,169,55,171,90,172,118,172,142,177,133,157,114,154,96,140,50,140,33,157,16,148};
    // car body
    Polygon b(car_body_start[0], car_body_start[1], sides,13);
    b.setFill();
    //car wheels
    Circle w1(car_wheel1_start[0], car_wheel1_start[1], 10);
    Circle w2(car_wheel2_start[0], car_wheel2_start[1], 10);
    w1.setFill();
    w2.setFill();
    // construction of stars
    double star_sides[5][2];
    for(int i=0; i<5; i++)
    {
        star_sides[i][0] = 5*cos(4*PI/5*i);
        star_sides[i][1] = 5*sin(4*PI/5*i);
    }
    Polygon star1(168, 168, star_sides, 5);
    Polygon star2(268, 168, star_sides, 5);
    Polygon star3(368, 168, star_sides, 5);
    Polygon star4(468, 168, star_sides, 5);
    Polygon star5(568, 168, star_sides, 5);
    star1.setColor(COLOR(255, 234, 0));
    star2.setColor(COLOR(255, 234, 0));
    star3.setColor(COLOR(255, 234, 0));
    star4.setColor(COLOR(255, 234, 0));
    star5.setColor(COLOR(255, 234, 0));
    star1.setFill();
    star2.setFill();
    star3.setFill();
    star4.setFill();
    star5.setFill();
    que t[10];
    int i;
    char s[1000],o1[1000],o2[1000],o3[1000],o4[1000];
    fstream f;//binary file object
    f.open("quiz_data.dat",ios::binary|ios::in);
    for(i=1;i<=5;i++)//loop to execute the test
    {
        f.read((char*)&t[i],sizeof(t[i]));
        strcpy(s,t[i].question());
        strcpy(o1,t[i].o1());
        strcpy(o2,t[i].o2());
        strcpy(o3,t[i].o3());
        strcpy(o4,t[i].o4());
        test(s,o1,o2,o3,o4,i);
    }
    if(correctanswer>=3)
    {
        status.replace(0,4,"Pass");
        b.~Polygon();
        star1.~Polygon();
        star2.~Polygon();
        star3.~Polygon();
        star4.~Polygon();
        star5.~Polygon();
        w1.~Circle();
        w2.~Circle();
        l1.~Line();
        l2.~Line();
        l3.~Line();
        l4.~Line();
        l5.~Line();
        Rectangle Pas(300,300,300,100);
        Text Pass(300,300,"CONGRATS!!!YOU PASSED THE TEST");
        Pass.setFill(COLOR(0,255,0));
        XEvent endgame;
        {
            while(1)
            {
                nextEvent(endgame);
                int an = charFromEvent(endgame);
                if (an) break;
            }

        }
    }
    else
    {
        status.replace(0,4,"Fail");
        b.~Polygon();
        star1.~Polygon();
        star2.~Polygon();
        star3.~Polygon();
        star4.~Polygon();
        star5.~Polygon();
        w1.~Circle();
        w2.~Circle();
        l1.~Line();
        l2.~Line();
        l3.~Line();
        l4.~Line();
        l5.~Line();
        Rectangle Pas(300,300,300,100);
        Text Pass(300,300,"Oh!!!Better Luck Next Time...");
        Pass.setFill(COLOR(0,255,0));
        XEvent endgame;
        {
            while(1)
            {
                nextEvent(endgame);
                int an = charFromEvent(endgame);
                if (an) break;
            }

        }

    }
    // stars rotation
   /* while(1)
    {
        star1.right(5);
        star2.right(5);
        star3.right(5);
        star4.right(5);
        star5.right(5);
        wait(0.1);
    }
    // car movement
    for(int m=0;m<=50;m++)
    {
        b.moveTo(car_body_start[0]+=m, 0);
        w1.moveTo(car_wheel1_start[0]+=m, 177);
        w2.moveTo(car_wheel2_start[0]+=m, 177);
    }
    wait(2);
*/
    //while(1)clickPos();

    fstream f1;
    f1.open("user_data.txt", ios::out|ios::app);// for record keeping
    if(!f1) {cout<<"error"; return ;}
    // format-  name|year_of_birth|score|pass or fail|timestamp
    f1 << name_user<<'|'<<year<<'|'<<correctanswer<<'|'<<status<<'|'<<dt;
    f1.close();
}

void menu()
{
    // background
    Rectangle bg(300, 300, 600, 600);
    bg.setColor(COLOR(48, 48, 48));
    bg.setFill();
    char ch;
    XEvent e1;
    {
        Text t(300, 50, "D R ! V E ezy");
        t.setColor(COLOR(255, 0, 0));
        Text t1(300, 110, "M E N U");
        Text t2(300, 140, "1: Start Test");
        Text t3(300, 170, "2: Help");
        Text t4(300, 200, "3: Credits");
        Text t5(300, 230, "4: Exit");
        nextEvent(e1);
        ch = charFromEvent(e1);
    }
    switch (ch)
    {
        // input=1
        case 49:cout<<endl<<"%Start Test%"<<endl;
                play();
                break;
        // input=2
        case 50:cout<<endl<<"%Help%"<<endl;
                cout<<endl<<"Use mouse to hover over the options."<<endl;
                cout<<endl<<"Left mouse click to select your answer."<<endl;
                cout<<endl<<"\tGoal: "<<endl;
                cout<<endl<<"This is a very basic traffic test."<<endl;
                cout<<endl<<"Total of 5 multiple choice questions will be asked."<<endl;
                cout<<endl<<"Score will be calculated based on\nthe number of correct answers and the speed of answering"<<endl;
                XEvent e2;
                {
                        Text t1(300, 150, "Controls: ");
                        Text c1(300, 190, "Use mouse to hover over the options.");
                        Text c2(300, 230, "Left mouse click to select your answer.");
                        Text t2(300, 270, "Goal: ");
                        Text t3(300, 310, "This is a very basic traffic test.");
                        Text t4(300, 350, "Total of 5 multiple choice questions will be asked.");
                        Text t5(300, 390, "Score will be calculated based on");
                        Text t6(300, 410, "the number of correct answers and the speed of answering");
                        Text t7(300, 470, "Press any key to go back!");
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
                            c1.~Text();
                            c2.~Text();
                            system("CLS");
                            menu();
                        }
                    }
        // input=3
        case 51:cout<<endl<<"%Credits%"<<endl;
                cout<<endl<<"\tTeam Dynamites "<<endl;
                cout<<endl<<"Vibhav Desai (2014063)"<<endl;
                cout<<endl<<"Vadiraj Inamdar (2014059)"<<endl;
                cout<<endl<<"Shubham Tendulkar (2014051)"<<endl;
                cout<<endl<<"Chinmay Joshi (2014006)"<<endl;
                 cout<<endl<<"\nFaculty Incharge: Prof. Amrita Naik"<<endl;;
                XEvent e3;
                {
                        Text t1(300, 150, "CREDITS:");
                        Text t2(300, 190, "Team Dynamites ");
                        Text m1(300, 230, "Vibhav Desai (2014063)");
                        Text m2(300, 250, "Vadiraj Inamdar (2014059)");
                        Text m3(300, 270, "Shubham Tendulkar (2014051)");
                        Text m4(300, 290, "Chinmay Joshi (2014006)");
                        Text t3(300, 330, "Faculty Incharge: Prof. Amrita Naik");
                        Text t4(300, 380, "Press any key to go back!");
                        t4.setColor(COLOR(255, 0, 0));
                        nextEvent(e3);
                        int an = charFromEvent(e3);
                        if (an)
                        {
                            t1.~Text();
                            t2.~Text();
                            t3.~Text();
                            t4.~Text();
                            m2.~Text();
                            m1.~Text();
                            m3.~Text();
                            m4.~Text();
                            system("CLS");
                            menu();
                        }
                    }
        // input=4
        case 52:cout<<endl<<"%Exit%"<<endl;
                closeCanvas();
                break;
        default:menu();
                break;
    }
}

void ageRestrict()
{
        int error=0;
        XEvent ar;
        {
            Text t1(300, 300, "You are not eligible to take this test!");
            cout<<endl<<"You are not eligible to take this test!"<<endl;
            Text t2(300, 350, "Press any key to go back!");
            t2.setColor(COLOR(255, 0, 0));
            while(1)
            {
                nextEvent(ar);
                int an = charFromEvent(ar);
                if(an==49) continue;
                else
                {
                    t1.~Text();
                    t2.~Text();
                    return;
                }
            }
        }
}

void prePlay()
{
        // local time
        time_t now = time(0);
        // saving time in string-format- (day month date hours:minutes:seconds year)
        dt = ctime(&now);
        cout<<endl<<dt<<endl;
        Text t(300, 50, "W E L C O M E !");
        Text tm(500,20,dt);
        t.setColor(COLOR(255, 0, 0));
        Text t1(300, 110, "Few things before starting");
        Text t2(300, 140, "Enter your year of birth");
        Text t3(300, 170, "YYYY: ");
        Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()), 170, year);
        Text t4(310+(textWidth("YYYY: ")/2), 170, " - ");
        Rectangle dec(310+(textWidth("YYYY: ")/2), 170, textHeight(), textHeight());
        Text t5(305+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()), 170, " + ");
        Rectangle inc(305+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()), 170, textHeight(), textHeight());
        Rectangle db(340+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()), 170, textWidth("DONE"), textHeight());
        Text db_t(340+(textWidth("YYYY: ")/2)+(textHeight()/2)+textWidth("9999")+(2*textHeight()), 170, "DONE");
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
                            Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()), 170, year);
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
                            Text y(310+(textWidth("YYYY: ")/2)+(2*textHeight()), 170, year);
                            while(!getClick())
                            wait(0.5);
                        }
                    }
                    if(e.xbutton.x>418 && e.xbutton.x<454)
                    {
                        if(e.xbutton.y>161 && e.xbutton.y<175)
                        {
                            cout<<endl<<"Year of birth: "<<year<<"\tAge: "<<2022-year<<endl<<endl;
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
        if(2021-year<18) // check if age is 18 or above
        {
            ageRestrict();
            menu();
        }
        XEvent name;
        {
            int i=0;
            Text a(300, 200, "Type your name: ");
            cout<<"Name: ";
            while(1)
            {
                nextEvent(name);
                if(mouseButtonPressEvent(name))continue;
                if(charFromEvent(name)==13) break;
                if(isdigit(charFromEvent(name))) continue;
                if(charFromEvent(name)==8) continue;
                cout<<charFromEvent(name);
                name_user+= charFromEvent(name);
            }
            t1.~Text();
            t.~Text();
            a.~Text();
            Text n(300,250,"Welcome, "+name_user);
            XEvent z;
            {
                Text t5(300, 380, "Press any key to proceed!");
                t5.setColor(COLOR(0, 255, 0));
                nextEvent(z);
                int an = charFromEvent(z);
                if (an)
                {
                    n.~Text();
                    cout<<endl<<endl<<"**Test initiated successfully**"<<endl;
                }
            }
        }
        cout<<endl<<"Welcome, "<<name_user<<" !"<<endl;
}

int main()
{
    initCanvas("MAIN", 600, 600);
    menu();
    closeCanvas();
    getch();
}
