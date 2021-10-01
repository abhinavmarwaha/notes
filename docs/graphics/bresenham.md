# Bresenham

```
#include<stdio.h>  
#include<graphics.h>  
void drawline(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {  
            putpixel(x,y,7);  
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {  
            putpixel(x,y,7);  
            p=p+2*dy;}  
            x=x+1;  
        }  
}  
int main()  
{  
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;  
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");  
    printf("Enter co-ordinates of first point: ");  
    scanf("%d%d", &x0, &y0);  
    printf("Enter co-ordinates of second point: ");  
    scanf("%d%d", &x1, &y1);  
    drawline(x0, y0, x1, y1);  
    return 0;  
}  
```


DDA Algorithm	Bresenham's Line Algorithm
1. DDA Algorithm use floating point, i.e., Real Arithmetic.	1. Bresenham's Line Algorithm use fixed point, i.e., Integer Arithmetic
2. DDA Algorithms uses multiplication & division its operation	2.Bresenham's Line Algorithm uses only subtraction and addition its operation
3. DDA Algorithm is slowly than Bresenham's Line Algorithm in line drawing because it uses real arithmetic (Floating Point operation)	3. Bresenham's Algorithm is faster than DDA Algorithm in line because it involves only addition & subtraction in its calculation and uses only integer arithmetic.
4. DDA Algorithm is not accurate and efficient as Bresenham's Line Algorithm.	4. Bresenham's Line Algorithm is more accurate and efficient at DDA Algorithm.
5.DDA Algorithm can draw circle and curves but are not accurate as Bresenham's Line Algorithm	5. Bresenham's Line Algorithm can draw circle and curves with more accurate than DDA Algorithm.