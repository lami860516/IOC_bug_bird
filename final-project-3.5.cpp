#include <iostream>
#include <curses.h>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
int have[25][80];         //0為沒東西  1為牆壁 2為生產者 3為消費者' 
using namespace std;
class bug
{
      public:
      void set();               //產生出生產者 
      void set(int a,int b);    //產生出生產者     可以指定xy座標，a為x  b為y 
      void set(int a,int b,int c);
      void printbug();             //印出蟲 
      void movebug();      
      bool copy();             //判斷需不需要複製 
      bool findxy( int &nx , int &ny );//選出8個方位有沒有空位的一個 
      int x,y,times; 
      int array[8];//8個方向
      bool color;//複製時為true為桃紅色 其他時候為false 為紅色 
};
void bug::set(int a,int b,int c)
{
     x=a;
     y=b;
     times=c;
}
void bug::set(int a,int b)
{
     x=a;
     y=b;
     have[y][x]=2;
     times=0;
}
bool bug::findxy( int &nx , int &ny )
{ 
     int order=0;//找出有幾個方向可以  分別放入array 
          
     if(have[y-1][x-1]==0)
     {
         array[order]=0;
         order++;
                                    }
     if(have[y-1][x]==0)
     {     
        array[order]=1;
        order++;
                                    }
     if(have[y-1][x+1]==0)
     {
        array[order]=2;
        order++;
                                     }
     if(have[y][x+1]==0)
     {
        array[order]=3;
        order++;                    
                                     }
     if(have[y+1][x+1]==0)
     {
         array[order]=4;
          order++;
                                     }  
     if(have[y+1][x]==0)
     {
         array[order]=5;
         order++;
                                     }
                                     
     if(have[y+1][x-1]==0)
     {
         array[order]=6;
         order++;
                                     }                                     
     if(have[y][x-1]==0)
     {
         array[order]=7;
         order++;
                                     }                
     if( order == 0 )
     {   return false ;   }
     
     
        int num=rand()%order;
        switch(array[num])
     {                     
       case 0:
          nx=x-1;
          ny=y-1;
          break;
       case 1 :                
          ny=y-1;
          nx=x;
          break;
       case 2 :
          ny=y-1;
          nx=x+1;
          break;
       case 3 :
          nx=x+1;
          ny=y;
          break;  
       case 4 :
          nx=x+1;
          ny=y+1;
          break;  
       case 5 :     
          nx=x;
          ny=y+1;    
          break;      
       case 6:
          nx=x-1;
          ny=y+1;      
          break;  
       case 7:    
          nx=x-1;
          ny=y;
          break; 
       
       }
       return true ;
}                  
void bug::set()
{
	  if(color==true)
	  	attron(COLOR_PAIR(1));
	  else
	  	attron(COLOR_PAIR(0));
	  
	  do
      {   x=rand()%78+1;
          y=rand()%23+1;
      }while( have[y][x]!=0 );
      have[y][x]=2;
      mvprintw(y,x,",");
      times=0;
}
bool bug::copy()
{
     if(times==2)
     {
       times=0;
       color=true;
       return true;
     }
     else
     {
     	color=false;
		 return false;
	 }
       
}  
void bug::printbug()
{
     
     if(color==true)
	  	attron(COLOR_PAIR(1));
	  else
	  	attron(COLOR_PAIR(0));
	  
	 move(y,x);
     addch(',');
}
void bug::movebug()
{    
     int order=0;
     times++;
    
     if(have[y-1][x-1]==0)
     {
         array[order]=0;
         order++;
                                    }
     if(have[y-1][x]==0)
     {     
        array[order]=1;
        order++;
                                    }
     if(have[y-1][x+1]==0)
     {
        array[order]=2;
        order++;
                                     }
     if(have[y][x+1]==0)
     {
        array[order]=3;
        order++;                    
                                     }
     if(have[y+1][x+1]==0)
     {
         array[order]=4;
          order++;
                                     }  
     if(have[y+1][x]==0)
     {
         array[order]=5;
         order++;
                                     }
                                     
     if(have[y+1][x-1]==0)
     {
         array[order]=6;
         order++;
                                     }                                     
     if(have[y][x-1]==0)
     {
         array[order]=7;
         order++;
                                   }                
     if( order == 0 )
     {   return ;                    }
     
        int num=rand()%order;
         have[y][x]=0; 
        switch(array[num])
     {                     
       case 0:
          x=x-1;       
          y=y-1;
          break;
       case 1 :                
          y=y-1;
          break;
       case 2 :
          y=y-1;
          x=x+1;
          break;
       case 3 :
          x=x+1;
          break;  
       case 4 :
          x=x+1;
          y=y+1;
          break;  
       case 5 :     
          y=y+1;    
          break;      
       case 6:
          x=x-1;
          y=y+1;
          break;  
       case 7:    
          x=x-1;
          break; 
       case 8:
          break;
       
       }
        have[y][x]=2;
}
class bird
{
      public:
      void set(); 
      void set(int a,int b);              //產生鳥兒 
      void set(int a,int b,int c);        //產生鳥兒，可以設定x y座標 與時間 
      void printbird();                       //印出 
      void movebird();
      bool findxy( int &nx , int &ny );  //選出8個方位有沒有空位的一個  
      bool die() ;                        //判斷是否要死    回傳true代表要死 
      int x,y,times;
      int array[8];//8個方向 
};
bool bird::findxy( int &nx , int &ny )
{ 
     int order=0;//找出有幾個方向可以  分別放入array 
          
     if(have[y-1][x-1]==0)
     {
         array[order]=0;
         order++;
                                    }
     if(have[y-1][x]==0)
     {     
        array[order]=1;
        order++;
                                    }
     if(have[y-1][x+1]==0)
     {
        array[order]=2;
        order++;
                                     }
     if(have[y][x+1]==0)
     {
        array[order]=3;
        order++;                    
                                     }
     if(have[y+1][x+1]==0)
     {
         array[order]=4;
          order++;
                                     }  
     if(have[y+1][x]==0)
     {
         array[order]=5;
         order++;
                                     }
                                     
     if(have[y+1][x-1]==0)
     {
         array[order]=6;
         order++;
                                     }                                     
     if(have[y][x-1]==0)
     {
         array[order]=7;
         order++;
                                     }                
     if( order == 0 )
     {   
         return false ;   }
     
     int num=rand()%order;//選一個方向 
     switch(array[num])
     {                     
       case 0:
          nx=x-1;
          ny=y-1;
          break;
       case 1 :                
          ny=y-1;
          nx=x;
          break;
       case 2 :
          ny=y-1;
          nx=x+1;
          break;
       case 3 :
          nx=x+1;
          ny=y;
          break;  
       case 4 :
          nx=x+1;
          ny=y+1;
          break;  
       case 5 :     
          nx=x;
          ny=y+1;    
          break;      
       case 6:
          nx=x-1;
          ny=y+1;      
          break;  
       case 7:    
          nx=x-1;
          ny=y;
          break; 

       }
       return true ;
}                  
void bird::set()
{
     do
      {   x=rand()%78+1;
          y=rand()%23+1;
      }while( have[y][x]!=0 );
     have[y][x]=3;
     attron(COLOR_PAIR(times+3));
     mvprintw(y,x,"O");
     times=0;
}
void bird::set(int a,int b) 
{
     x=a;
     y=b;
     have[y][x]=3;
     times=0;
}   
void bird::set(int a,int b,int c) 
{
     x=a;
     y=b;
     times=c;
}
void bird::printbird()
{
     move(y,x);
     attron(COLOR_PAIR(times+3));
     addch('O');
}
void bird::movebird()
{
     int order=0;
     times++;
     
     if(have[y-1][x-1]==0||have[y-1][x-1]==2)
     {
         array[order]=0;
         order++;
                                    }
     if(have[y-1][x]==0||have[y-1][x]==2)
     {     
        array[order]=1;
        order++;
                                    }
     if(have[y-1][x+1]==0||have[y-1][x+1]==2)
     {
        array[order]=2;
        order++;
                                     }
     if(have[y][x+1]==0||have[y][x+1]==2)
     {
        array[order]=3;
        order++;                    
                                     }
     if(have[y+1][x+1]==0||have[y+1][x+1]==2)
     {
         array[order]=4;
          order++;
                                     }  
     if(have[y+1][x]==0||have[y+1][x]==2)
     {
         array[order]=5;
         order++;
                                     }
                                     
     if(have[y+1][x-1]==0||have[y+1][x-1]==2)
     {
         array[order]=6;
         order++;
                                     }                                     
     if(have[y][x-1]==0||have[y][x-1]==2)
     {
         array[order]=7;
         order++;
                                     }                
     if( order == 0 )
     {   return ;                    }
     
        int num=rand()%order;
         have[y][x]=0; 
     switch(array[num])
     {                     
       case 0:
          x=x-1;       
          y=y-1;
          break;
       case 1 :                
          y=y-1;
          break;
       case 2 :
          y=y-1;
          x=x+1;
          break;
       case 3 :
          x=x+1;
          break;  
       case 4 :
          x=x+1;
          y=y+1;
          break;  
       case 5 :     
          y=y+1;    
          break;
       case 6:
          x=x-1;
          y=y+1;
          break;
       case 7:
          x=x-1;
          break;                  
      }            
}
bool bird::die()
{
    if(times==2)
    {   
        have[y][x]=0 ;
        return true;
    }
    else
    return false;   
}                                                                            
int main()
{   
     bug q[1794];
     bird w[1794];
     
     for(int i=1;i<=23;i++)
     {   for(int j=1;j<=78;j++)     
             have[i][j]=0;
     }
     for(int i=0;i<80;i++ )
     {   have[0][i]=1;       
         have[24][i]=1;  
     }
     for(int i=0;i<25;i++)
     {   have[i][0]=1; 
         have[i][79]=1;
     }
	 
     setlocale(LC_ALL,"");
     initscr(); 
     srand(time(0));
     
	 if (!has_colors()||start_color()==ERR){
        endwin();
        printf("不支援顏色");
        
     }
     start_color(); 
     
     init_pair(1,COLOR_MAGENTA ,COLOR_BLACK);//蟲蟲複製 
     init_pair(2,COLOR_RED,COLOR_BLACK);//蟲蟲平時 
     init_pair(3,COLOR_WHITE,COLOR_BLACK);//健康的鳥兒 
     init_pair(4,COLOR_YELLOW,COLOR_BLACK);//很餓的鳥兒 
     init_pair(5,COLOR_CYAN,COLOR_BLACK);//瀕臨死亡的鳥兒 
     init_pair(6,COLOR_GREEN,COLOR_BLUE);
     init_pair(7,COLOR_GREEN,COLOR_BLACK);
     init_pair(8,COLOR_WHITE,COLOR_RED);
	 
	 attron(COLOR_PAIR(6));
	 border('T','T','T','T','#','#','#','#');
     refresh();
     
	 
	 char qaq[5],qwq[5];
	 attron(COLOR_PAIR(3));
	 move(9,29);printw("圈圈是鳥兒 逗號是蟲蟲" );refresh(); 
	 move(10,26);printw("蟲蟲都死掉了就Game Over了喔" );refresh(); 
	 move(11,29);printw("你要多少蟲蟲：" );refresh();
	 getstr(qaq);
	 move(12,29);printw("你要多少鳥兒：" );refresh();
	 getstr(qwq); 
	 clear();
	 refresh();
	 attron(COLOR_PAIR(8));
	 move(10,34);
     printw("Game  Start");
     refresh();   
     move(12,34);
     printw("遊 戲 開 始");
	 refresh();Sleep(1500);clear();refresh();
	 
	 
     int bugs=atoi(qaq) ;    //所有蟲蟲的總數 
     int birds=atoi(qwq) ;      //所有鳥兒的總數 
     int nx , ny , h ,n,bx , by,clk=1 ,z;      //nx ny得到要複製的座標 n為蟲的 b為鳥的  
     attron(COLOR_PAIR(6));
	 border('T','T','T','T','#','#','#','#');
     refresh();
     
     attron(COLOR_PAIR(2));
     for(int i=0;i<bugs;i++)              //產生一開始設定的蟲蟲與鳥兒 
        q[i].set();   
     attron(COLOR_PAIR(3));
     for(int g=0;g<birds;g++)
        w[g].set();		
     
	attron(COLOR_PAIR(7));
     move(24,22);addstr("                                  ");
     move(24,22);addstr("time：");refresh();printw("%d",clk);refresh();
	 move(24,35);addstr("bug：");refresh();printw("%d",bugs);refresh();
	 move(24,48);addstr("bird：");refresh();printw("%d",birds);refresh();
	 
	 while(1)
     {   
		 refresh();
         Sleep(1000);
         clear();
         n = birds;h = bugs ;
		 if(n==0)
    	{
    		char *a,*b;
			clear();
			refresh();
			attron(COLOR_PAIR(2));
    		move(11,10);refresh();
    		printw("鳥兒全部餓死了喔");refresh();
    		move(12,10);refresh();
    		printw("要再隨機放幾隻鳥進去？");refresh();
    		move(13,10);refresh();
    		getstr(a);
    		for(z=0;z<atoi(a);z++)
    			w[z].set();
			birds=n=atoi(a);
			clear();
		}
		if(h==0)
		{
			clear();
			refresh();
			attron(COLOR_PAIR(2));
    		move(10,15);refresh();
    		printw("蟲蟲死光光了");refresh();
    		move(12,15);refresh();
    		printw("好難過 掰掰掰");refresh();
    		getch();
    		clear();refresh();
    		attron(COLOR_PAIR(8)|A_BOLD);
    		move(10,34);
    		printw("Game   Over");
    		refresh();   
    		move(12,34);
    		printw("遊 戲 結 束");
    		refresh();
    		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                               ";
    		system("pause");
    		exit(0);
    		
		}
         clk++;
         h = bugs ;
         for(int i=0;i<h;i++)
         {   
            
			 if( q[i].copy() )	//如果要複製 
             {   
             	
                 if( q[i].findxy( nx , ny ) )//如果找的到方向 
                 {   
                     
					 q[bugs].set( nx , ny );
                     q[bugs].printbug();//在(nx,ny)產生一隻蟲蟲 
                     bugs++;
                 }
                 
             }
             else
             {   
			 	attron(COLOR_PAIR(2));
			 	q[i].movebug();  }//移動 
                 
				 
				 
				 q[i].printbug();
         }  					//蟲蟲動作到這裡 
                                                      
         n = birds;
         for(int i=0 ; i<n ; i++)
         {
             if( w[i].die() )//如果要死掉了 
             {    birds-- ;
                  have[w[i].y][w[i].x] = 0 ;
                  w[i].set( w[birds].x , w[birds].y , w[birds].times ) ;
                  n-- ;
                  i-- ;
             }
             else
             {   
			 	w[i].movebird();
                 if( have[w[i].y][w[i].x]==2 )//如果那個位置是蟲蟲 
                 {
                         for(int j=0;j<bugs;j++)
                         {
                              if( q[j].x==w[i].x && q[j].y==w[i].y )
                              {
                                     bugs--;
                                     q[j].set( q[bugs].x , q[bugs].y , q[bugs].times ) ;
                                     w[i].findxy(bx,by);
                                     w[i].times=0;
                                     w[birds].set(bx,by);
                                     birds++;
                                     break ;
                               }
                         }
                 }
                 
				 w[i].printbird();
                 have[w[i].y][w[i].x]=3;
             }
         }
     	 attron(COLOR_PAIR(6));
    	 if(clk%5==0) 
			border('T','T','T','T','#','#','#','#');
		 if(clk%5==1) 
			border('E','E','E','E','#','#','#','#');
		 if(clk%5==2) 
			border('A','A','A','A','#','#','#','#');
         if(clk%5==3) 
			border('M','M','M','M','#','#','#','#');
		 if(clk%5==4) 
			border('1','1','1','1','#','#','#','#');
    	refresh();
    	attron(COLOR_PAIR(7));
    	move(24,22);addstr("                                   ");
    	move(24,22);addstr("time：");refresh();printw("%d",clk);refresh();
		move(24,35);addstr("bug：");refresh();printw("%d",bugs);refresh();
		move(24,48);addstr("bird：");refresh();printw("%d",birds);refresh();
     }
     endwin(); 
}
