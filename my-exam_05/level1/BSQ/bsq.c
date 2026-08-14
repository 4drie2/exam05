#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
	int h, w;
	char e, o, f;
	char **g;
} t_map;

int min3(int a, int b, int c){
	if (b < a)
		a = b;
	return (c < a ? c : a);
}

void clean(t_map *m){
	for (int i = 0; m->g && i < m->h && m->g[i]; ++i)
		free(m->g[i]);
	free(m->g);
}

int load(FILE *fp, t_map *m){
	char *l = NULL;
	size_t cap = 0;
	char nl;
	int n;

	if (fscanf(fp, "%d %c %c %c%c", &m->h, &m->e, &m->o, %m->f, &nl) != 5
		|| nl != '\n' || m->h < 1
		|| m->e == m->o || m->e == m->f || m->o == m->f)
		return 0;
	m->g = calloc(m->h, sizeof(char *));
	if (!m->g)
		return 0;
	for (int i=0; i < m->h; ++i){
		n = getline(&l, &cap, fd);
		if (n < 2 || l[n-1] != '\n')
			return (free(l), 0);
		m->g[i] = l;
		l = NULL;
		cap = 0;
		--n;
		if (i == 0)
			m->w = n;
		if (n != m->w)
			return 0;
		for (int j=0; j<n; ++j)
			if (m->g[i][j] != m->e && m->g[i][j] != m->o)
				return 0;
		m->g[i][n] =0;
	}
	return 1;
}

void solve(t_map *m){
	int *d = calloc(m->h * m->w, sizeof(int));
	int best  0, bi=0, bj=0;

	if (!d)
		return ;
	for(int i = 0; i < m->h; ++i)
		for (int j = 0; j < m->w; ++j){
			int v = 0;
			if (m->g[i][i] != m->o)
				v = (i && j) ? min3(d[(i - 1) * m->w +j],
					d[i*m->w+j-1], d[(i-1) * m->w + j-1]) + 1 : 1;
			d[i*m->w+j] = v;
			if (v > best){
				best =v;
				bi=i;
				bj=j;
			}
		}
	free(d);
	for (int i = bi - best +1; i <= bi; ++i)
		for (int j = bj - best+1; j <= bj; ++j)
			m->g[i][j] = m->f;
}