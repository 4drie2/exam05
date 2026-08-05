#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count(char *b, int w, int h, int x, int y){
	int	n = 0;

	for (int dy = -1; dy <= 1; ++dy)
		for (int dx = -1; dx <= 1; ++dx){
			int	ny = y + dy, nx = x + dx;
			if ((dx || dy) && nx >= 0 && nx < w && ny >= 0 && ny < h)
				n += b[ny * w + nx];
		}
	return (n);
}

void	draw(char *b, int w, int h){
	int	x = 0, y = 0, pen = 0;
	char	c;

	while (read(0, &c, 1) == 1){
		if (c == 'x')
			pen = !pen;
		else if (c == 'w' && y > 0)
			--y;
		else if (c == 's' && y < h - 1)
			++y;
		else if (c == 'a' && x > 0)
			--x;
		else if (c == 'd' && x < w - 1)
			++x;
		if (pen)
			b[y * w + x] = 1;
	}
}

void	show(char *b, int w, int h){
	for (int y = 0; y < h; ++y){
		for (int x = 0; x < w; ++x)
			putchar(b[y * w + x] ? 'O' : ' ');
		putchar('\n');
	}
}

int	main(int ac, char **av){
	if (ac != 4)
		return (1);

	int	w = atoi(av[1]), h = atoi(av[2]), it = atoi(av[3]);
	if (w <= 0 || h <= 0)
		return (1);

	char	*b = calloc(w * h, 1), *n = calloc(w * h, 1), *t;
	if (!b || !n)
		return (1);

	draw(b, w, h);
	while (it-- > 0){
		for (int y = 0; y < h; ++y)
			for (int x = 0; x < w; ++x){
				int	c = count(b, w, h, x, y);
				n[y * w + x] = (c == 3 || (b[y * w + x] && c == 2));
			}
		t = b; b = n; n = t;
	}
	show(b, w, h);
	free(b);
	free(n);
	return (0);
}
