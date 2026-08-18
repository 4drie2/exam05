#include "bsq.h"

typedef struct s_map{
	int	h, w;
	char	e, o, f;
	char	**g;
}	t_map;

int	min3(int a, int b, int c){
	if (b < a)
		a = b;
	return (c < a ? c : a);
}

void	clean(t_map *m){
	for (int y = 0; m->g && y < m->h && m->g[y]; ++y)
		free(m->g[y]);
	free(m->g);
}

int	load(FILE *fp, t_map *m){
	char	*l = NULL;
	size_t	cap = 0;
	char	nl;
	int	n;

	if (fscanf(fp, "%d %c %c %c%c", &m->h, &m->e, &m->o, &m->f, &nl) != 5
		|| nl != '\n' || m->h < 1
		|| m->e == m->o || m->e == m->f || m->o == m->f)
		return (0);
	m->g = calloc(m->h, sizeof(char *));
	if (!m->g)
		return (0);
	for (int y = 0; y < m->h; ++y){
		n = getline(&l, &cap, fp);
		if (n < 2 || l[n - 1] != '\n')
			return (free(l), 0);
		m->g[y] = l;
		l = NULL;
		cap = 0;
		--n;
		if (y == 0)
			m->w = n;
		if (n != m->w)
			return (0);
		for (int x = 0; x < n; ++x)
			if (m->g[y][x] != m->e && m->g[y][x] != m->o)
				return (0);
		m->g[y][n] = 0;
	}
	return (1);
}

void	solve(t_map *m){
	int	*d = calloc(m->h * m->w, sizeof(int));
	int	best = 0, by = 0, bx = 0;

	if (!d)
		return ;
	for (int y = 0; y < m->h; ++y)
		for (int x = 0; x < m->w; ++x){
			int	v = 0;
			if (m->g[y][x] != m->o)
				v = (y && x) ? min3(d[(y - 1) * m->w + x],
					d[y * m->w + x - 1], d[(y - 1) * m->w + x - 1]) + 1 : 1;
			d[y * m->w + x] = v;
			if (v > best){
				best = v;
				by = y;
				bx = x;
			}
		}
	free(d);
	for (int y = by - best + 1; y <= by; ++y)
		for (int x = bx - best + 1; x <= bx; ++x)
			m->g[y][x] = m->f;
}

int	main(int argc, char **argv){
	t_map	m = {0, 0, 0, 0, 0, NULL};
	FILE	*fp = stdin;

	if (argc > 1){
		fp = fopen(argv[1], "r");
		if (!fp)
			return (fprintf(stdout, "Error: cannot open file\n"), 1);
	}
	if (load(fp, &m)){
		solve(&m);
		for (int y = 0; y < m.h; ++y)
			fprintf(stdout, "%s\n", m.g[y]);
	}
	else
		fprintf(stdout, "Error: invalid map\n");
	clean(&m);
	if (fp != stdin)
		fclose(fp);
	return (0);
}
