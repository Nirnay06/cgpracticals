#include<iostream.h>
#include<graphics.h>
#include<conio.h>


int abs(int n){
return ((n>0) ? n : n*(-1));

}

void dda(int x0,int y0,int x1,int y1){
int dx,dy;
dx=x1-x0;
dy=y1-y0;

int steps=abs(dx) > abs(dy) ? abs(dx) : abs(dy);
float x=x0;
float y=y0;

float xinc=dx/(float)steps;
float yinc=dy/(float)steps;

for(int i=0;i<=steps;i++){
putpixel(x,y,RED);
x+=xinc;
y+=yinc;

}


}

void main(){
int gd = DETECT , gm;
initgraph(&gd,&gm, "c:\\turboc3\\bgi");

int x0=2,y0=2,x1=14,y1=16;
dda(x0,y0,x1,y1);
getch();

}



