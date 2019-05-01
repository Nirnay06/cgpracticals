#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>

void plot4(int x, int y, int cx, int cy)
{
	putpixel(x+cx,y+cy,RED);
	putpixel(x+cx,-y+cy,RED);
	putpixel(-x+cx,y+cy,RED);
	putpixel(-x+cx,-y+cy,RED);
}

void main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	double x,y,a,b,cx,cy,DR1,DR2;

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

	cout<<"\nEnter centre(x): ";
	cin>>cx;
	cout<<"\nEnter centre(y): ";
	cin>>cy;
	cout<<"\nEnter length of major axis: ";
	cin>>a;
	cout<<"\nEnter length of minor axis: ";
	cin>>b;

	x=0;
	y=b;

	plot4(x,y,cx,cy);

	DR1=pow(b,2)-(pow(a,2)*b)+(pow(a,2)*0.25);

	while((pow(a,2)*(y-0.5))>(pow(b,2)*(x+1)))
	{
		if(DR1<0)
		{
			DR1+=(pow(b,2)*((2*x)+3));
		}
		else
		{
			DR1+=(pow(b,2)*((2*x)+3)+ pow(a,2)*((-2*y)+3));
			y--;
		}
		x++;
		plot4(x,y,cx,cy);
	}

	//code for region 2 of the ellipse

	DR2= pow(b,2)*pow((x+0.5),2)+pow(a,2)*pow((y-1),2)-pow(a,2)*pow(b,2);

	while(y>0)
	{
		if(DR2<0)
		{
			DR2+= pow(b,2)*((2*x)+3) + pow(a,2)*((-2*y)+3);
			x++;
		}
		else
		{
			DR2+= pow(a,2)*((-2*y)+3);
		}
		y--;
		plot4(x,y,cx,cy);
	}

	/* clean up */
	getch();
	closegraph();
}