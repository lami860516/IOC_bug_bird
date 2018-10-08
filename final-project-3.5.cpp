#include <iostream>
#include <curses.h>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
int have[25][80];         //0���S�F��  1����� 2���Ͳ��� 3�����O��' 
using namespace std;
class bug
{
      public:
      void set();               //���ͥX�Ͳ��� 
      void set(int a,int b);    //���ͥX�Ͳ���     �i�H���wxy�y�СAa��x  b��y 
      void set(int a,int b,int c);
      void printbug();             //�L�X�� 
      void movebug();      
      bool copy();             //�P�_�ݤ��ݭn�ƻs 
      bool findxy( int &nx , int &ny );//��X8�Ӥ�즳�S���Ŧ쪺�@�� 
      int x,y,times; 
      int array[8];//8�Ӥ�V
      bool color;//�ƻs�ɬ�true������� ��L�ɭԬ�false ������ 
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
     int order=0;//��X���X�Ӥ�V�i�H  ���O��Jarray 
          
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
      void set(int a,int b);              //���ͳ��� 
      void set(int a,int b,int c);        //���ͳ���A�i�H�]�wx y�y�� �P�ɶ� 
      void printbird();                       //�L�X 
      void movebird();
      bool findxy( int &nx , int &ny );  //��X8�Ӥ�즳�S���Ŧ쪺�@��  
      bool die() ;                        //�P�_�O�_�n��    �^��true�N��n�� 
      int x,y,times;
      int array[8];//8�Ӥ�V 
};
bool bird::findxy( int &nx , int &ny )
{ 
     int order=0;//��X���X�Ӥ�V�i�H  ���O��Jarray 
          
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
     
     int num=rand()%order;//��@�Ӥ�V 
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
        printf("���䴩�C��");
        
     }
     start_color(); 
     
     init_pair(1,COLOR_MAGENTA ,COLOR_BLACK);//���νƻs 
     init_pair(2,COLOR_RED,COLOR_BLACK);//���Υ��� 
     init_pair(3,COLOR_WHITE,COLOR_BLACK);//���d������ 
     init_pair(4,COLOR_YELLOW,COLOR_BLACK);//�ܾj������ 
     init_pair(5,COLOR_CYAN,COLOR_BLACK);//�x�{���`������ 
     init_pair(6,COLOR_GREEN,COLOR_BLUE);
     init_pair(7,COLOR_GREEN,COLOR_BLACK);
     init_pair(8,COLOR_WHITE,COLOR_RED);
	 
	 attron(COLOR_PAIR(6));
	 border('T','T','T','T','#','#','#','#');
     refresh();
     
	 
	 char qaq[5],qwq[5];
	 attron(COLOR_PAIR(3));
	 move(9,29);printw("���O���� �r���O����" );refresh(); 
	 move(10,26);printw("���γ������F�NGame Over�F��" );refresh(); 
	 move(11,29);printw("�A�n�h�����ΡG" );refresh();
	 getstr(qaq);
	 move(12,29);printw("�A�n�h�ֳ���G" );refresh();
	 getstr(qwq); 
	 clear();
	 refresh();
	 attron(COLOR_PAIR(8));
	 move(10,34);
     printw("Game  Start");
     refresh();   
     move(12,34);
     printw("�C �� �} �l");
	 refresh();Sleep(1500);clear();refresh();
	 
	 
     int bugs=atoi(qaq) ;    //�Ҧ����Ϊ��`�� 
     int birds=atoi(qwq) ;      //�Ҧ����઺�`�� 
     int nx , ny , h ,n,bx , by,clk=1 ,z;      //nx ny�o��n�ƻs���y�� n���Ϊ� b������  
     attron(COLOR_PAIR(6));
	 border('T','T','T','T','#','#','#','#');
     refresh();
     
     attron(COLOR_PAIR(2));
     for(int i=0;i<bugs;i++)              //���ͤ@�}�l�]�w�����λP���� 
        q[i].set();   
     attron(COLOR_PAIR(3));
     for(int g=0;g<birds;g++)
        w[g].set();		
     
	attron(COLOR_PAIR(7));
     move(24,22);addstr("                                  ");
     move(24,22);addstr("time�G");refresh();printw("%d",clk);refresh();
	 move(24,35);addstr("bug�G");refresh();printw("%d",bugs);refresh();
	 move(24,48);addstr("bird�G");refresh();printw("%d",birds);refresh();
	 
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
    		printw("��������j���F��");refresh();
    		move(12,10);refresh();
    		printw("�n�A�H����X�����i�h�H");refresh();
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
    		printw("���Φ������F");refresh();
    		move(12,15);refresh();
    		printw("�n���L �T�T�T");refresh();
    		getch();
    		clear();refresh();
    		attron(COLOR_PAIR(8)|A_BOLD);
    		move(10,34);
    		printw("Game   Over");
    		refresh();   
    		move(12,34);
    		printw("�C �� �� ��");
    		refresh();
    		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                               ";
    		system("pause");
    		exit(0);
    		
		}
         clk++;
         h = bugs ;
         for(int i=0;i<h;i++)
         {   
            
			 if( q[i].copy() )	//�p�G�n�ƻs 
             {   
             	
                 if( q[i].findxy( nx , ny ) )//�p�G�䪺���V 
                 {   
                     
					 q[bugs].set( nx , ny );
                     q[bugs].printbug();//�b(nx,ny)���ͤ@������ 
                     bugs++;
                 }
                 
             }
             else
             {   
			 	attron(COLOR_PAIR(2));
			 	q[i].movebug();  }//���� 
                 
				 
				 
				 q[i].printbug();
         }  					//���ΰʧ@��o�� 
                                                      
         n = birds;
         for(int i=0 ; i<n ; i++)
         {
             if( w[i].die() )//�p�G�n�����F 
             {    birds-- ;
                  have[w[i].y][w[i].x] = 0 ;
                  w[i].set( w[birds].x , w[birds].y , w[birds].times ) ;
                  n-- ;
                  i-- ;
             }
             else
             {   
			 	w[i].movebird();
                 if( have[w[i].y][w[i].x]==2 )//�p�G���Ӧ�m�O���� 
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
    	move(24,22);addstr("time�G");refresh();printw("%d",clk);refresh();
		move(24,35);addstr("bug�G");refresh();printw("%d",bugs);refresh();
		move(24,48);addstr("bird�G");refresh();printw("%d",birds);refresh();
     }
     endwin(); 
}
