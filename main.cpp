#include <iostream>

using namespace std;

int matriceAdiacenta[1000][1000];
int noduriPrime[1000];		// vector de frecventa
int grade[100];

bool prim (int n)
{
  if (n < 2 || n == 4 || n == 6)
    return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int grad (int linie, int n)
{
  int gradNod = 0;
  for (int i = 0; i <= n; i++)
    gradNod += matriceAdiacenta[linie][i];

  return gradNod;
}

int min_array (int array[], int n)
{
  int temp = array[1];
  for (int i = 1; i <= n; i++)
    if (temp > array[i])
      temp = array[i];
  return temp;
}

int main ()
{
  // citire
  int n, m;
  cin >> n >> m;


  while (m)
    {
      int x, y;
      cin >> x >> y;

      // generare matrice de adiacenta
      matriceAdiacenta[x][y] = 1;
      matriceAdiacenta[y][x] = 1;

      // modificare vector de fregventa
      noduriPrime[x] += 1;
      noduriPrime[y] += 1;

      m--;
    }


  // printare matrice
  cout << "\tMATRICE DE ADIACENTA\n";
  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
	cout << matriceAdiacenta[i][j] << " ";
      cout << "\n";
    }

  // printare noduri cu grad prim
  cout << "\n\tNODURI CU GRADE PRIM\n";
  for (int j = 1; j <= n; j++)
    if (prim (noduriPrime[j]))
      cout << j << " ";

  // printare noduri izolaet
  cout << "\n\n\tNODURI IZOLATE\n";
  int izolate = 0;
  for (int j = 1; j <= n; j++)
    if (!noduriPrime[j])
      {
	cout << j << " ";
	izolate++;
      }
  cout << "\nNUMARUL TOTAL DE NODURI IZOLATE ESTE: " << izolate;

  // printare noduri incidente cu nodul T
  cout << "\n\n NODURILE ADICENTE CU UN NOD DAT";
  cout << "\nNodul pe care il doriti: ";
  int t;
  cin >> t;
  for (int j = 1; j <= n; j++)
    if (matriceAdiacenta[t][j])
      cout << j << " ";

  //printare noduri cu gradul minim
  cout << "\n\n\t NODURILE CU CEL MAI MIC GRAD\n";
  for (int i = 1; i <= n; i++)
    grade[i] = grad (i, n);	// generare multime de grade
  int _min = min_array (grade, n);
  for (int i = 1; i <= n; i++)
    if (grade[i] == _min)
      cout << i << " ";

  return 0;
}
