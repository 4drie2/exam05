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