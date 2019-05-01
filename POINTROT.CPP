#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
#define PI 3.14
void main()
{  clrscr();
   int O[2],theta,i,j;
   float R[2][2],N[2],val=PI/180,a,b;
   char dir[20];
   printf("Enter the coordinates x and y for the point:");
   cin>>O[0]>>O[1];
   printf("Enter the angle for rotation:");
   cin>>theta;
   a=sin(theta*val);
   b=cos(theta*val);
   printf("Enter the direction of rotation:");
   cin>>dir;
   printf("Original coordinates:");
   printf("[%d  %d]\n",O[0],O[1]);
   //Rotation matrix formed is | cos(theta)   -sin(theta) |
   //                          | sin(theta)    cos(theta) |
   if(dir=="anticlockwise")
   {
      R[0][0]=R[1][1]=b;
      R[0][1]=-a;
      R[1][0]=a;
   }
   else
   {
      R[0][0]=R[1][1]=b;
      R[0][1]=a;
      R[1][0]=-a;
   }
   printf("\nRotation Matrix formed is: \n");
   for(i=0;i<2;i++)
   { printf("\n");
     for(j=0;j<2;j++)
     {  printf("[%f]",R[i][j]);
     }
   }
   for(i=0;i<2;i++)
   {  N[i]=0;      }
   for(i=0;i<2;i++)
   {  for(j=0;j<2;j++)
      {
	 N[i]+=R[i][j]*O[j];
      }
   }
   printf("\nNew coordinates:");
   printf("[%f  %f]\n",N[0],N[1]);
   getch();
}