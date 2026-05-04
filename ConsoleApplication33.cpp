// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;
#include <cmath>
#include <time.h>
/*
int main()
{
	double s = 0.0;
	for (int n = 1; n <= 25; n++)
	{
		double one = pow(-1.0,n) * ((n*n + 1.0)/n);
		s+= one;
	}
	printf("%lf\n", s);
	system("pause");
	return 0;
}
*/
/*
int main()
{
  double maxx = 0.0;
  int n = 0;
  for (int i = 1; i <= 25; i++)
  {
    double u = 5.0 * cos(sqrt(2.0*i));
    if (u > maxx){
      maxx = u;
      n = i;
    }
  }
  printf("%.7lf\n", maxx);
  printf("%i\n", n);
  system("pause");
  return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Ru");

    double s, a, x, z;
    int i;

    printf("Введите x=");
    scanf_s("%lf", &x);

    clock_t start, end;

    s = 0;
    i = 0;

    start = clock();

    printf("i\ta\t\t\t\ts\n");

    a = pow(x, 2 * i) / 1.0;

    while (abs(a) > 1e-20)
    {
        s += a;

        printf("%d\t%.20f\t%.20f\n", i, a, s);

        i++;

        
        f = 1;
        for (int j = 2; j <= 2 * i; j++)
        {
            f *= j;
        }

        a = pow(x, 2 * i) / f;
    }

    end = clock();

    z = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Sum = %.4f\nTime = %.5f s", s, z);

    system("pause");
}
*/
/*
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Ru");

    double s, a, x, z;
    int i;

    printf("Введите x=");
    scanf_s("%lf", &x);

    clock_t start, end;

    s = 0;
    i = 0;
    a = 1; // a0 = x^0 / 0! = 1

    start = clock();

    printf("i\ta\t\t\t\ts\n");

    while (fabs(a) > 1e-20)
    {
        s += a;

        printf("%d\t%.20f\t%.20f\n", i, a, s);

        i++;

        // рекуррентная формула
        a = a * (x * x) / ((2 * i) * (2 * i - 1));
    }

    end = clock();

    z = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Sum = %.4f\nTime = %.5f s", s, z);

    system("pause");
}
*/


/*

int main()
{
    double A_prev = 1; // A0
    double A_curr = 1; // A1
    double A_next;

    int n = 1;

    do
    {
        n++;

        A_next = pow(M_E, -(n - 1)) * A_curr + pow(M_E, (n - 1)) * A_prev;

        A_prev = A_curr;
        A_curr = A_next;
        cout << "A_n = " << A_curr << endl;

    } while (A_curr <= 10000);

    cout << "Минимальный n = " << n << endl;
    system("pause");
    return 0;
}
*/

