

#include <stdio.h>

#define MAXN 100000

int main()
{
  int N;
  int x, i, i1, i2, i3, circ, circ3;
  int num_triangulos = 0;
  int pontos[MAXN+3];

  scanf("%d ", &N);
  pontos[0] = 0;
  for (i=0; i<N-1; ++i) {
    scanf("%d ", &x);
    pontos[i+1] = pontos[i] + x;
  }
  scanf("%d ", &x);
  circ = pontos[N-1] + x;
  if (circ%3 || N<3)  {
    printf("0\n");
    return 0;
  }

  circ3 = circ/3;
  i2=1; i3=2;
  for (i1=0; pontos[i1] < circ3; ++i1) {
    while (i2 < N && pontos[i2] < pontos[i1] + circ3)
      ++i2;
    while (i3 < N && pontos[i3] < pontos[i1] + 2*circ3)
      ++i3;
    if (pontos[i2] == pontos[i1] + circ3 && pontos[i3] == pontos[i1] + 2*circ3)
      num_triangulos++;
  }
  printf("%d\n", num_triangulos);

  return 0;
}
