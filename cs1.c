#include<stdio.h>
#include<graphics.h>
int wmaxx,wminx,wmaxy,wminy,rc,rc1,dx,dy,xi,yi,x=50,y=0,xd=250,yd=150;
int main()
{
 printf("\nEnter the window minimum and maximum for x axis : ");
 scanf("%d%d",&wminx,&wmaxx);
 printf("\nEnter the window minimum and maximum for y axis : ");
 scanf("%d%d",&wminy,&wmaxy);

 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);


 //line(x,y,xd,yd);
 //x=150;y=100;
 //x1=350;y1=250;

//region code assignment
if(x<100 && y<50)
{
	rc=1001;
}
else if(x>=100 && x<=300 && y<50)
{
	rc=1000;
}
else if(x>300 && y<50)
{
	rc=1010;
}
else if(x<100 && y>=50 && y<=250)
{
	rc=0001;
}
else if(x>=100 && x<=300 && y>=50 && y<=250)
{
	rc=0000;
}
else if(x>300 && y>=50 && y<=250)
{
	rc=0010;
}
else if(x<100 && y>250)
{
	rc=0101;
}
else if(x>=100 && x<=300 && y>250)
{
	rc=0100;
}
else if(x>300 && y>250)
{
	rc=0110;
}
 //printf("rc %d",rc);
if(rc!=0000)
{
	rc1=rc;
}

dx=xd-x;
dy=yd-y;

if(rc1&1000)
{
	xi = x+((dx*(wminy - y))/dy);
	yi = wminy;
	
}
else if(rc1&0100)
{
	
	xi = x+((dx*(wmaxy - y))/dy);
	yi = wmaxy;

			
}
else if(rc1&0010)
{
	yi = y+((dy*(wminx - x))/dx);
	xi = wminx;	
}
else 
{
		

	yi = y+((dy*(wmaxx - x))/dx);
	xi = wmaxx;	
}

rectangle(wminx,wminy,wmaxx,wmaxy);
line(x,y,xd,yd);
rectangle(wminx+250,wminy,wmaxx+250,wmaxy);
line(xi+250,yi,xd+250,yd);


 getch();
 closegraph();
//return 0;
}
