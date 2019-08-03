#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<ctime>
#include<graphics.h>
using namespace std;
#define N 9
#define UNASSIGNED 0

class sudoku{
    public:
       
       sudoku()
       { 
       }
     bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
     bool isSafe(int grid[N][N], int row, int col, int num);
     bool SolveSudoku(int grid[N][N]);
     void printGrid(int grid[N][N]);
     int sudokugenerator(int grid[N][N]);
     bool UsedInRow(int grid[N][N], int row, int num);
     bool UsedInCol(int grid[N][N], int col, int num);
     bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
     void emptyprintgrid();
}; 

static int r=1;
 

 
 /////////////////////////////////////////////////////////////////////////////////////////////////////
bool sudoku ::  SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
 /////////////////////////////////////////////////////////////////////////////////////////////
 
 
/* Searches the grid to find an entry that is still unassigned. */
bool sudoku :: FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 ////////////////////////////////////////////////////////////////////////////////////////////
 
 
/* Returns whether any assigned entry n the specified row matches 
   the given number. */
bool sudoku :: UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 ///////////////////////////////////////////////////////////////////////////////////////////
 
 
/* Returns whether any assigned entry in the specified column matches 
   the given number. */
bool sudoku ::  UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 ///////////////////////////////////////////////////////////////////////////////////////////
 
 
 
/* Returns whether any assigned entry within the specified 3x3 box matches 
   the given number. */
bool sudoku :: UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////

 
/* Returns whether it will be legal to assign num to the given row,col location. 
 */
bool sudoku :: isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}

//*************************************************************************************

void sudoku :: emptyprintgrid()
{
  cleardevice();
  setcolor(WHITE);
  setlinestyle(SOLID_LINE,0,3);
  rectangle(40,40,400,400);
  setlinestyle(SOLID_LINE,0,1);
  setcolor(GREEN);
  line(80,40,80,400);
  setcolor(WHITE);
  line(80,40,80,400);                           //displaying grid
  line(120,40,120,400);
  setcolor(GREEN);
  line(160,40,160,400);  
  setcolor(WHITE);
  line(200,40,200,400);
  line(240,40,240,400);
  setcolor(GREEN);
  line(280,40,280,400); 
  setcolor(WHITE); 
  line(320,40,320,400);
  line(360,40,360,400);
  line(40,80,400,80);
  line(40,120,400,120);
  setcolor(GREEN);
  line(40,160,400,160); 
  setcolor(WHITE);
  line(40,200,400,200);
  line(40,240,400,240);
  setcolor(GREEN);
  line(40,280,400,280); 
  setcolor(WHITE); 
  line(40,320,400,320);
  line(40,360,400,360);
  
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  rectangle(40,420,80,460);      outtextxy(53,425,"1");
  rectangle(80,420,120,460);     outtextxy(93,425,"2");
  rectangle(120,420,160,460);    outtextxy(133,425,"3");
  rectangle(160,420,200,460);    outtextxy(173,425,"4");
  rectangle(200,420,240,460);    outtextxy(213,425,"5");
  rectangle(240,420,280,460);    outtextxy(253,425,"6");
  rectangle(280,420,320,460);    outtextxy(293,425,"7");
  rectangle(320,420,360,460);    outtextxy(333,425,"8");
  rectangle(360,420,400,460);    outtextxy(373,425,"9"); settextstyle(3,HORIZ_DIR,1);
  rectangle(420,80,500,120);     outtextxy(430,85,"RESET");
  rectangle(420,140,500,180);    outtextxy(427,145,"SUBMIT");
  rectangle(420,200,500,240);    outtextxy(425,205,"DELETE");
  rectangle(420,260,500,300);    outtextxy(445,265,"EXIT");
}
     

//****************************************************************************

void sudoku:: printGrid(int grid[N][N])
{
  int cx,cy;
  cleardevice();
  setcolor(WHITE);
  setlinestyle(SOLID_LINE,0,3);
  rectangle(40,40,400,400);
  setlinestyle(SOLID_LINE,0,1);
  setcolor(GREEN);
  line(80,40,80,400);
  setcolor(WHITE);
  line(80,40,80,400);                           //displaying grid
  line(120,40,120,400);
  setcolor(GREEN);
  line(160,40,160,400);  
  setcolor(WHITE);
  line(200,40,200,400);
  line(240,40,240,400);
  setcolor(GREEN);
  line(280,40,280,400); 
  setcolor(WHITE); 
  line(320,40,320,400);
  line(360,40,360,400);
  line(40,80,400,80);
  line(40,120,400,120);
  setcolor(GREEN);
  line(40,160,400,160); 
  setcolor(WHITE);
  line(40,200,400,200);
  line(40,240,400,240);
  setcolor(GREEN);
  line(40,280,400,280); 
  setcolor(WHITE); 
  line(40,320,400,320);
  line(40,360,400,360);
  
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  rectangle(40,420,80,460);      outtextxy(53,425,"1");
  rectangle(80,420,120,460);     outtextxy(93,425,"2");
  rectangle(120,420,160,460);    outtextxy(133,425,"3");
  rectangle(160,420,200,460);    outtextxy(173,425,"4");
  rectangle(200,420,240,460);    outtextxy(213,425,"5");
  rectangle(240,420,280,460);    outtextxy(253,425,"6");
  rectangle(280,420,320,460);    outtextxy(293,425,"7");
  rectangle(320,420,360,460);    outtextxy(333,425,"8");
  rectangle(360,420,400,460);    outtextxy(373,425,"9"); settextstyle(3,HORIZ_DIR,1);
  rectangle(420,80,500,120);     outtextxy(430,85,"RESET");
  rectangle(420,140,500,180);    outtextxy(427,145,"SUBMIT");
  rectangle(420,200,500,240);    outtextxy(425,205,"DELETE");
  
  
 settextstyle(1,HORIZ_DIR,1); 
  for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            switch(grid[i][j])
            {
                case 1:outtextxy(55+40*i,55+40*j,"1");break;
                case 2:outtextxy(55+40*i,55+40*j,"2");break;
                case 3:outtextxy(55+40*i,55+40*j,"3");break;
                case 4:outtextxy(55+40*i,55+40*j,"4");break;
                case 5:outtextxy(55+40*i,55+40*j,"5");break;
                case 6:outtextxy(55+40*i,55+40*j,"6");break;
                case 7:outtextxy(55+40*i,55+40*j,"7");break;
                case 8:outtextxy(55+40*i,55+40*j,"8");break;
                case 9:outtextxy(55+40*i,55+40*j,"9");break;
            }
        setcolor(RED);
        }
    }
    setcolor(WHITE);
  rectangle(420,260,500,300); outtextxy(425,265,"EXIT");
   
}
//****************************************************************************************************
//used to open file and read the unsolved sudoku in the grid
int sudoku::sudokugenerator(int grid[N][N])
{
    int i,j,cx3,cy3,h=0;   
    char ch[81];
    
    //add rand
    cleardevice();
    setcolor(WHITE);
     settextstyle(BOLD_FONT,HORIZ_DIR,2);
     rectangle(160,130,340,170);       //displays the rectangle for difficulty level
     outtextxy(210,140,"1.EASY");

    rectangle(160,200,340,240);
    outtextxy(200,210,"2.MEDIUM");

    rectangle(160,270,340,310);
    outtextxy(210,280,"3.HARD");
    ifstream f;
    while(!ismouseclick(WM_LBUTTONDOWN))
           {delay(10);}
     getmouseclick(WM_LBUTTONDOWN,cx3,cy3);
          if(cx3>=160 && cx3<=340 && cy3>=130 && cy3<=170)
    {
          
        switch(r)                          //opening file
        {
                                         
            case 1:
               { f.open("sudoku2.txt");
                break;}
             case 2:
               { f.open("sudoku3.txt");
                break;}
             case 3:
                { f.open("sudoku4.txt");
                break;}
             case 4:
                { f.open("sudoku5.txt");
                break;}
             case 5:
                { f.open("sudoku6.txt");
                break;}
             case 6:
               { f.open("sudoku7.txt");
                break;}
             case 7:
               { f.open("sudoku8.txt");
                break;}
             case 8:
               { f.open("sudoku9.txt");
                break;}
             case 9:
                { f.open("sudoku2.txt");
                break;}
        }r++;
    }
    else if(cx3>=160 && cx3<=340 && cy3>=200 && cy3<=240)
    {
         switch(r)
         {
            
             case 1:
                 f.open("sudoku10.txt");
                break;
             case 2:
                 f.open("sudoku11.txt");
                break;
             case 3:
                 f.open("sudoku12.txt");
                break;
             case 4:
                f.open("sudoku13.txt");
                break;
             case 5:
                 f.open("sudoku14.txt");
                break;
             case 6:
                 f.open("sudoku15.txt");
                break;
             case 7:
                f.open("sudoku16.txt");
                break;
             case 8:
                 f.open("sudoku17.txt");
                break;
             case 9:
                f.open("sudoku18.txt");
                break;
            }r++;

    }

     else if(cx3>=160 && cx3<=340 && cy3>=270 && cy3<=310)
    {
         switch(r)
        {
                
             case 1:
                f.open("sudoku19.txt");
                break;
             case 2:
                 f.open("sudoku20.txt");
                break;
             case 3:
                 f.open("sudoku21.txt");
                break;
             case 4:
                f.open("sudoku22.txt");
                break;
             case 5:
                 f.open("sudoku23.txt");
                break;
             case 6:
                 f.open("sudoku24.txt");
                break;
             case 7:
                 f.open("sudoku25.txt");
                break;
             case 8:
                 f.open("sudoku26.txt");
                break;
             case 9:
                 f.open("sudoku27.txt");
                break;
            }r++;
    }
    

f>>ch;



   for(int i=0;i<9;i++)
   {
     for(int j=0;j<9;j++)
     {
      grid[i][j]=(int)ch[h]-48;
      h++;
      }
   }
     
   return 0;
}
//*********************************************************************************************

int main()
{
          int x=170;
          sudoku s;
          initwindow (520, 520, "Windows BGI"); 
          settextstyle(4,HORIZ_DIR,5);
          outtextxy(50,100,"SUDOKU 247");
          
           settextstyle(8,HORIZ_DIR,2);
           outtextxy(150,250,"Loading,Please Wait");
           for(int i=0;i<100;++i)
           {
             delay(30);
             line(x,280,x,300);
             x++;
            } 
                                     //displaying the window
          int sample[N][N],grid[N][N],sample1[N][N];
          int i,j,cx,cy,cx1,cy1,cx2,cy2,cx5,cy5,cx7,cy7,marks2=0,marks=0;
          bool flag;
          char str[5]; 
          for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
              sample[i][j]=grid[i][j]=0;
          setcolor(WHITE);
          settextstyle(BOLD_FONT,HORIZ_DIR,2);
          
          
      do{
          cleardevice();
          rectangle(140,160,380,200);
          outtextxy(155,170,"1.SUDOKU GENERATOR");
          
          rectangle(140,240,380,280);
          outtextxy(170,250,"2.SUDOKU SOLVER");
         
          while(!ismouseclick(WM_LBUTTONDOWN))
           {delay(10);}
           getmouseclick(WM_LBUTTONDOWN,cx,cy);
           
 if(cx>=140  && cx<=380 && cy>=160 &&cy<=200)
            {
              s.sudokugenerator(grid);
              s.printGrid(grid);
        
   while(1)
  {
    
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
     delay(10);
    }
     getmouseclick(WM_LBUTTONDOWN,cx7,cy7);
     
     for(int i=40;i<400;i+=40)        
          for(int j=40,y=0;j<400;j+=40,y++)
             {
              if(cx7>=i&&cx7<=i+40&&cy7>=j&&cy7<=j+40)
                 {
                           setcolor(RED);
                           rectangle(i,j,i+40,j+40);
                  
                           while(!ismouseclick(WM_LBUTTONDOWN))
                             {
                               delay(100);
                              }
                            getmouseclick(WM_LBUTTONDOWN,cx1,cy1);
                            int h=1;
                        for(int k=40;k<400;k++)
                         { setcolor(WHITE);
             
                             if(cx1>=k&&cx1<=k+40&&cy1>=420&&cy1<=460)//to print the number
                          {
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                                 
                              itoa(h,str,10);
                              outtextxy(i+10,j+10,str);
                              sample[i/40-1][j/40-1]=h; 
                              rectangle(i,j,i+40,j+40);
                               setcolor(GREEN);
                  
                                 line(160,40,160,400);
                           line(280,40,280,400);
                             line(40,160,400,160);  
                           line(40,280,400,280); 
                           break;
                          }
                          if(k%40==0) h++;
                     else if(cx1>=420&&cx1<=500&&cy1>=200&&cy1<=240)//to delete an element
                     {
                       outtextxy(i+10,j+10,"  ");
                       rectangle(i,j,i+40,j+40);
                   setcolor(GREEN);
                   sample[j/40-1][i/40-1]=0;
                   
                   line(160,40,160,400);
                   line(280,40,280,400);
                   line(40,160,400,160);  
                   line(40,280,400,280);
             }
              else                       //no action
              {
               rectangle(i,j,i+40,j+40);
               setcolor(GREEN);
                  
                   line(160,40,160,400);
                   line(280,40,280,400);
                   line(40,160,400,160);  
                   line(40,280,400,280); 
               }
        }
           
        
        }}
    if(cx7>=420&&cy7>=80&&cx7<=500&&cy7<=120)//to reset
   {
     s.printGrid(grid);
   }
   if(cx7>=420&&cx7<=500&&cy7>=260&&cy7<=300)//to exit
     break;
   if(cx7>420&&cx7<500&&cy7>140&&cy7<180)//after submit
   {
                       for(int i=0;i<9;i++)
                          for(int j=0;j<9;j++)
                            sample1[i][j]=grid[i][j];            
                            bool flag=s.SolveSudoku(grid);
                           
                             if(flag==true)
                              {              
                              for(int i=0;i<9;i++)
                                   {    for(int j=0;j<9;j++)
                                          {if(sample1[i][j]==0)
                                            {
                                             
                                              itoa(grid[i][j],str,10);
                                              outtextxy((i+1)*40+10,(j+1)*40+10,str);
                                              }
                                            }
                                            }}
                            while(!ismouseclick(WM_LBUTTONDOWN))
                            {
                              delay(100);
                              }
                              
                            getmouseclick(WM_LBUTTONDOWN,cx5,cy5);
                            cleardevice();
                            marks=0;
                            for(int i=0;i<9;i++)
                            {
                                for(int j=0;j<9;j++)
                                {if(sample[i][j]!=0)
                                    if(sample[i][j]==grid[i][j])
                                    {marks++;

                                    }
                                    else
                                      marks2++;
                                }
                            }
         
          cleardevice();
          rectangle(140,160,300,200);
          outtextxy(175,170,"SCORE");
          itoa(marks,str,10);
          outtextxy(200,240,str);
          if(marks2+marks==81)
          {rectangle(140,160,380,200);
          outtextxy(155,170,"CONGRATS!! YOU HAVE SOLVED IT CORRECTLY");}
          while(!ismouseclick(WM_LBUTTONDOWN))
          {
            delay(10);
          }
  break;
  }}
 }
    if(cx>140&&cx<=380&&cy>=240&&cy<=280)//sudoku solver
      {s.emptyprintgrid();
       while(1)
  {
    
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
     delay(10);
    }
     getmouseclick(WM_LBUTTONDOWN,cx,cy);
     
     for(int i=40;i<400;i+=40)        
          for(int j=40,y=0;j<400;j+=40,y++)
             {
              if(cx>=i&&cx<=i+40&&cy>=j&&cy<=j+40)
                 {
                    setcolor(RED);
                    rectangle(i,j,i+40,j+40);
                  
          while(!ismouseclick(WM_LBUTTONDOWN))
                      {
                       delay(100);
                       }
                     getmouseclick(WM_LBUTTONDOWN,cx1,cy1);
            int h=1;
            for(int k=40;k<400;k++)
            { setcolor(WHITE);
             
              if(cx1>=k&&cx1<=k+40&&cy1>=420&&cy1<=460)//to print the number
               {
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3); 
                   itoa(h,str,10);
                   outtextxy(i+10,j+10,str); 
                   sample[i/40-1][j/40-1]=h; 
                   rectangle(i,j,i+40,j+40);
                   setcolor(GREEN);
                  
                   line(160,40,160,400);
                   line(280,40,280,400);
                   line(40,160,400,160);  
                   line(40,280,400,280); 
                  break;
                  }
                  if(k%40==0) h++;
             else if(cx1>=420&&cx1<=500&&cy1>=200&&cy1<=240)//to delete an element
             {
               outtextxy(i+10,j+10,"  ");
               rectangle(i,j,i+40,j+40);
                   setcolor(GREEN);
                   sample[j/40-1][i/40-1]=0;
                   
                   line(160,40,160,400);
                   line(280,40,280,400);
                   line(40,160,400,160);  
                   line(40,280,400,280);
             }
              else                       //no action
              {
               rectangle(i,j,i+40,j+40);
               setcolor(GREEN);
                  
                   line(160,40,160,400);
                   line(280,40,280,400);
                   line(40,160,400,160);  
                   line(40,280,400,280); 
               }
        }
           
        
        }}
    if(cx>=420&&cy>=80&&cx<=500&&cy<=120)//to reset
   {
     s.emptyprintgrid();
   }
   if(cx>=420&&cx<=500&&cy>=260&&cy<=300)//to exit
     break;
   if(cx>420&&cx<500&&cy>140&&cy<180)//after submit
   {
      for(int i=0;i<9;i++)
         for(int j=0;j<9;j++)
                sample1[i][j]=sample[i][j];         
                          bool flag=  s.SolveSudoku(sample);
                               for(int i=0;i<9;i++)
                                   {    for(int j=0;j<9;j++)
                                          {if(sample1[i][j]==0)
                                            {
                                              itoa(sample[i][j],str,10);
                                              outtextxy((i+1)*40+10,(j+1)*40+10,str);
                                              }
                                            }
                                            }
       
           
    
    
}
}

}
       cleardevice();
       setcolor(WHITE);
       settextstyle(BOLD_FONT,HORIZ_DIR,2);
       rectangle(100,160,400,200);
       outtextxy(105,170,"DO YOU WANT TO CONTINUE?");
       rectangle(150,240,230,280);
       outtextxy(190,250,"Y");
       rectangle(240,240,320,280);
       outtextxy(280,250,"N");
     
   while(1){  
       while(!ismouseclick(WM_LBUTTONDOWN))
       {
         delay(10);
       }
       getmouseclick(WM_LBUTTONDOWN,cx2,cy2);
       
       if(cx2>=240&&cx2<=320&&cy2>=240&&cy2<=280)
       {
         cleardevice();
         settextstyle(8,HORIZ_DIR,7);
         outtextxy(80,150,"THANK YOU!");
         while(!ismouseclick(WM_LBUTTONDOWN))
         {
           delay(10);
         }
         return(0);
         }
       else if(cx2>=170&&cx2<=250&&cy2>=240&&cy2<=280)
         break;
      }
       
      }while(cx2>=170&&cx2<=250&&cy2>=240&&cy2<=280);
      
}
                
