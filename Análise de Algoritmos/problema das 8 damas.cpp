// Solução do Problema das 8 Damas
// Adaptado de www.geeksforgeeks.org
// Disciplina de Análise de Algoritmos
// Jaime Cohen - UEPG

#include <iostream>
#include <cstdlib>

using namespace std;

int N;

// Imprime a solução
void printSolution(int**  board)
{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
	cout << board[i][j] << " ";
      cout << endl;
    }
}

// Verifica se é possível colocar uma nova dama
// em board[row][col] assumindo que já foram colocadas
// damas nas colunas de 0 até col-1
// Só precisa verificar as colunas da esquerda.
bool isSafe(int** board, int row, int col)
{
  int i, j;

  /* Verifica se há dama na mesma linha */
  for (i = 0; i < col; i++)
    if (board[row][i])
      return false;

  /* Verifica a diagonal para cima */
  for (i=row, j=col; i>=0 && j>=0; i--, j--)
    if (board[i][j])
      return false;

  /* Verifica a diagonal para baixo */
  for (i=row, j=col; j>=0 && i<N; i++, j--)
    if (board[i][j])
      return false;

  return true;
}

/* Função recursiva que executa o backtracking */
bool solveRec(int** board, int col)
{
  // testa se encontrou a solução
  if (col >= N)
    return true;

  /* para cada linha */
  for (int i = 0; i < N; i++)
    if ( isSafe(board, i, col) )
      {
	board[i][col] = 1;
	if ( solveRec(board, col + 1) )
	  return true;
        // não é possível colocar a dama em board[i][col]
	// então restaura a configuração
	board[i][col] = 0;
      }
  // não é possível estender a solução
  return false;
}

bool solveNQ()
{
  int **board;
  board = new int *[N];
  for(int i = 0; i <N; i++)
    board[i] = new int[N];

  if ( solveRec(board, 0) == false )
    {
      cout << "Solution does not exist" << endl;
      return false;
    }

  printSolution(board);
  return true;
}

// driver program to test above function
int main(int argc, char *argv[])
{
  if (argc == 2)
    N = atoi(argv[1]);
  else
    N = 8;
  solveNQ();

  return 0;
}
