# Ellipse with MidPoint

```
void midptellipse(int rx, int ry, int xc, int yc)
{

	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry)
		- (rx * rx * ry)
		+ (0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	while (dx < dy) {

		printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		if (d1 < 0) {
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
		+ ((rx * rx) * ((y - 1) * (y - 1)))
		- (rx * rx * ry * ry);

	while (y >= 0) {

		printf("(%f, %f)\n", x + xc, y + yc);
		printf("(%f, %f)\n", -x + xc, y + yc);
		printf("(%f, %f)\n", x + xc, -y + yc);
		printf("(%f, %f)\n", -x + xc, -y + yc);

		if (d2 > 0) {
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else {
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
}
```