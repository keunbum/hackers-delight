#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) (void) 0
#endif

#define M ((int) 5e5 + 9)
#define OFFSET ((int) 1e7)

int Hash(int x) {
  return (x + OFFSET) % M;
}

typedef struct Node Node;
struct Node {
  int x;
  Node *next;
};

Node *NewNode(int x) {
  Node *nd = (Node *) malloc(sizeof(Node));
  nd->x = x;
  nd->next = NULL;
  return nd;
}

typedef struct List List;
struct List {
  Node *head;
  Node *last;
};

List a[M];

void Add(List *list, int x) {
  if (!list->head) {
    list->head = NewNode(x);
    list->last = list->head;
  }
  Node *new_node = NewNode(x);
  list->last->next = new_node;
  list->last = new_node;
}

Node *Find(List *list, int x) {
  Node *nd = list->head;
  while (nd) {
    if (nd->x == x) {
      return nd;
    }
    nd = nd->next;
  }
  return NULL;
}

int main() {
  int n, m;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    Add(a + Hash(x), x);
  }
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%d ", Find(a + Hash(x), x) != NULL);
  }
  return 0;
}
