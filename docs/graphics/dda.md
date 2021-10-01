# Digital differential analyzer

```
dx = X1 - X0;
dy = Y1 - Y0;

steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

Xinc = dx / (float) steps;
Yinc = dy / (float) steps;

X = X0;
Y = Y0;
for (int i = 0; i <= steps; i++)
{
    putpixel (round(X),round(Y),WHITE);
    X += Xinc;
    Y += Yinc;
}
```