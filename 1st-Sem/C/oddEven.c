#include<stdio.h>
int main()
{
  int ix=2,iy=1,ox=10,oy=1,ex=20,ey=1,x,xc=0,oc=0,ec=0;
  printf("\033[%d;%dH%s",ox,oy,"Odd numbers are : ");
  oy=oy+20;
  printf("\033[%d;%dH%s",ex,ey,"Even numbers are : ");
  ey=ey+20;
  printf("\033[%d;%dH%s",ix,iy,"Input numbers");
  iy=iy+15;
  
  
  while(1)
  {
  printf("\033[%d;%dH%s",ix,iy," ");
   iy+=5;  
    scanf("%d",&x);
    if(x==-1)
        break;
    xc++;
    if(xc==15){xc=0,ix++;iy=1;}
    if(x%2==0)
    {
      ec++;
      if(ec%15==0){ex++;ey=1;}
      printf("\033[%d;%dH%d",ex,ey,x);
      ey=ey+5;
    }
    else
     {
       oc++;
       if(oc%15==0){ox++;oy=1; }
      printf("\033[%d;%dH%d",ox,oy,x);
      oy=oy+5;
    } 
  }
  printf("\033[%d;%dH%s%d",ox,oy,"Frequency of odd number is ",oc);
    printf("\033[%d;%dH%s%d",ex,ey,"Frequency of even number is ",ec);
    printf("\033[%d;%dH%s",30,1,"");
}