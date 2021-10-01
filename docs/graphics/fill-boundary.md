# Boundary Fill

```
// C Implementation for Boundary Filling Algorithm
#include <graphics.h>

// Function for 4 connected Pixels
void boundaryFill4(int x, int y, int fill_color,int boundary_color)
{
	if(getpixel(x, y) != boundary_color &&
	getpixel(x, y) != fill_color)
	{
		putpixel(x, y, fill_color);
		boundaryFill4(x + 1, y, fill_color, boundary_color);
		boundaryFill4(x, y + 1, fill_color, boundary_color);
		boundaryFill4(x - 1, y, fill_color, boundary_color);
		boundaryFill4(x, y - 1, fill_color, boundary_color);
	}
}

//driver code
int main()
{
	// gm is Graphics mode which is
	// a computer display mode that
	// generates image using pixels.
	// DETECT is a macro defined in
	// "graphics.h" header file
	int gd = DETECT, gm;

	// initgraph initializes the
	// graphics system by loading a
	// graphics driver from disk
	initgraph(&gd, &gm, "");

	int x = 250, y = 200, radius = 50;

	// circle function
	circle(x, y, radius);

	// Function calling
	boundaryFill4(x, y, 6, 15);

	delay(10000);

	getch();

	// closegraph function closes the
	// graphics mode and deallocates
	// all memory allocated by
	// graphics system .
	closegraph();

	return 0;
}
```

### 4-connected pixels Vs 8-connected pixels

Let us take a figure with the boundary color as GREEN and the fill color as RED. The 4-connected method fails to fill this figure completely. This figure will be efficiently filled using the 8-connected technique.

### Flood fill Vs Boundary fill

Though both Flood fill and Boundary fill algorithms color a given figure with a chosen color, they differ in one aspect. In Flood fill, all the connected pixels of a selected color get replaced by a fill color. On the other hand, in Boundary fill, the program stops when a given color boundary is found.