#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>

void main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int x1,x2,y1,y2;
	float m;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "..\\bgi");

	/* read result of initialization */
	errorcode = graphresult();
	/* an error occurred */
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}

	cout<<"\nEnter x1: ";
	cin>>x1;
	cout<<"\nEnter x2: ";
	cin>>x2;
	cout<<"\nEnter y1: ";
	cin>>y1;
	cout<<"\nEnter y2: ";
	cin>>y2;

	int dx=x2-x1;
	int dy=y2-y1;
	int d= dy+(2*dx);    		  //d0=a-2b where a=dy,b=-dx,c=Bdx
	int N=-(2*dy);          	 //E=2*b
	int NE=2*(dy-dx);  	        //NE=2(a+b)

	m=(dy)/(float)(dx);

	putpixel(x1,y1,RED);        //plotting of the starting pixel

	if((m)>-1)
	{
	while(x1<x2)
	{
		if(d<=0)
		{
			d+=NE;
			x1++;
			y1++;

		}
		else
		{
			d+=N;
			y1++;
		}
		putpixel(x1,y1,RED);
	}
	}
	/* clean up */
	getch();
	closegraph();
}
