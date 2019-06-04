#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

#define MAX_DIM 2
#define N 1000000
#define rand1() (rand() / (double)RAND_MAX)

using namespace std;

typedef struct kd_node_t {
	double x[MAX_DIM];
	struct kd_node_t *left, *right;
}node;

inline double
dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--) {
		t = a->x[dim] - b->x[dim];
		d += t * t;
	}
	return d;
}
inline void swap(struct kd_node_t *x, struct kd_node_t *y) {
	double tmp[MAX_DIM];
	memcpy(tmp, x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp, sizeof(tmp));
}


/* see quickselect method */
struct kd_node_t* find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1)
		return start;

	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;
	while (1) {
		pivot = md->x[idx];

		swap(md, end - 1);
		for (store = p = start; p < end; p++) {
			if (p->x[idx] < pivot) {
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);

		/* median has duplicate values */
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else        start = store;
	}
}

struct kd_node_t* make_tree(struct kd_node_t *t, int len, int i, int dim){
	struct kd_node_t *n;
	if (!len) return 0;
	if ((n = find_median(t, t + len, i))) {
		i = (i + 1) % dim;
		n->left = make_tree(t, n - t, i, dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}

/* global variable, so sue me */
long long visited;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist){
	double d, dx, dx2;
	if (!root) return;
	d = dist(root, nd, dim);
	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;
	visited++;
	if (!*best || d < *best_dist) {
		*best_dist = d;
		*best = root;
	}

	/* if chance of exact match is high */
	if (!*best_dist) return;
	if (++i >= dim) i = 0;
	nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
	if (dx2 >= *best_dist) return;
	nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);

}

int bruteForce(node *data, node query) {
	int n = N, d = MAX_DIM;
	double best_dist = DBL_MAX; int best_idx;
	for (int i = 0; i < n; i++) {
		double dist = 0;
		visited++;
		for (int j = 0; j < d; j++) {
			dist += (data[i].x[j] - query.x[j])*(data[i].x[j] - query.x[j]);
		}
		if (dist < best_dist) {
			best_dist = dist;
			best_idx = i;
		}
	}
	return best_idx;
}


int main(void){
	
	printf("Â÷¿ø(DIM) : %d\n", MAX_DIM);
	srand(unsigned(time(0)));
	clock_t start_, end_;
	double time_;
	struct kd_node_t *root, *found, *data;	
	struct kd_node_t query;//±âÁØÁ¡
	double best_dist;
	for (int d = 0; d < MAX_DIM; d++) query.x[d] = rand1();//±âÁØÁ¡ ·£´ý µ¥ÀÌÅÍ ÀÔ·Â
	data = (struct kd_node_t*) calloc(N, sizeof(struct kd_node_t));//1,000,000°³ µ¥ÀÌÅÍ »ý¼º
	
	for (int i = 0; i < N; i++) {
		for (int d = 0; d < MAX_DIM; d++) {
			data[i].x[d] = rand1();
		}
	}
	//ºê·çÆ®Æ÷½º ÀÛµ¿ Å×½ºÆ®
	/*int idx = bruteForce(data, query);
	cout << "query : ";
	for (int i = 0; i < MAX_DIM; i++) {
		cout << data[idx].x[i] << ' ';
	}
	cout << '\n'<< "found data : ";
	for (int i = 0; i < MAX_DIM; i++) {
		cout << data[idx].x[i] << ' ';
	}*/
	//Æ®¸®»ý¼º
	root = make_tree(data, N, 0, MAX_DIM);
	int test_runs = 1000; // Äõ¸® °¹¼ö
	
	printf("\nKD Æ®¸®\n");
	visited = 0;
	start_ = clock();
	for (int i = 0; i < test_runs; i++) {
		found = 0;
		for (int d = 0; d < MAX_DIM; d++) query.x[d] = rand1();//±âÁØÁ¡ ·£´ý µ¥ÀÌÅÍ ÀÔ·Â
		nearest(root, &query, 0, MAX_DIM, &found, &best_dist);
	}
	end_ = clock();
	time_ = double(end_ - start_) / CLOCKS_PER_SEC;
	printf("1000°³ Äõ¸® ÃÑ Å½»ö ½Ã°£ : %f\n", time_);
	printf("Äõ¸®´ç Æò±Õ Å½»ö ½Ã°£ : %f\n", time_ / 1000);
	printf("Äõ¸®´ç Æò±Õ Å½»ö È½¼ö : %d\n", visited / 1000);

	printf("\nºê·çÆ®Æ÷½º\n");
	visited = 0;
	start_ = clock();
	for (int i = 0; i < test_runs; i++) {
		for (int d = 0; d < MAX_DIM; d++) query.x[d] = rand1();//±âÁØÁ¡ ·£´ý µ¥ÀÌÅÍ ÀÔ·Â
		bruteForce(data, query);
	}
	end_ = clock();
	time_ = double(end_ - start_) / CLOCKS_PER_SEC;
	printf("1000°³ Äõ¸® ÃÑ Å½»ö ½Ã°£ : %f\n", time_);
	printf("Äõ¸®´ç Æò±Õ Å½»ö ½Ã°£ : %f\n", time_ / 1000);
	printf("Äõ¸®´ç Æò±Õ Å½»ö È½¼ö : %d\n", visited / 1000);
	
	//free(data);

	return 0;
}