#include <stdio.h>
#include <assert.h>

#define DEBUG 1

#define choice_push(a,b,c,d,e) choice[0]=a;choice[1]=b;choice[2]=c;choice[3]=d;choice[4]=e
#define N 50
#define PC 5

int sum(int choice[])
{
	return choice[0]+choice[1]+choice[2]+choice[3]+choice[4];
}
int print_choice(int choice[])
{
	printf("%d,%d,%d,%d,%d\n", choice[0],choice[1],choice[2],choice[3],choice[4]);
}
int MIN(int choice[])
{
	int m = N;
	for (int i = 0; i < PC; ++i)
	{
		if (m > choice[i])
		{
			m = choice[i];
		}
	}
	return m;
}
int MAX(int choice[])
{
	int m = 0;
	for (int i = 0; i < PC; ++i)
	{
		// printf("%d\n", choice[i]);
		if (m < choice[i])
		{
			m = choice[i];
		}
	}
	return m;
}
int init_table(int table[PC][N][N])
{
	for (int p = 0; p < PC; ++p)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				table[p][i][j] = 0;
			}
		}
	}
}
int main() {
	int table[PC][N][N];
	init_table(table);
	int total, n, a, b, c, d, e;
	int left, left_b, left_c, left_d, left_e;
	int mmax, mmin;
	int choice[PC];
	total = 0;
	for (a = 1; a < N; ++a)
	{
		left_b = N - a;
		// print 'A take',a,', left',left
		for (b = 1; b <= left_b; ++b)
		{
			left_c = N - a - b;
			for (c = 1; c <= left_c; ++c)
			{
				left_d = N - a - b - c;
				for (d = 1; d <= left_d; ++d)
				{
					left_e = N - a - b - c - d;
					for (e = 1; e <= left_e; ++e)
					{
						choice_push(a,b,c,d,e);
						// print_choice(choice);
						assert(sum(choice) <= 100);
						// if a > 88 || b > 88:
							// print choice
						mmax = MAX(choice);
						mmin = MIN(choice);
						// printf("max %d, min %d\n", mmax, mmin);
						if (a == mmax || a == mmin)
						{
							// pass
						}
						else
						{
							table[0][0][a] += 1;
						}
						if (b == mmax || b == mmin)
						{
							/* code */
						}
						else
						{
							table[1][left_b][b] += 1;
						}
						if (c == mmax || c == mmin)
						{
							/* code */
						}
						else
						{
							table[2][left_c][c] += 1;
						}
						if (d == mmax || d == mmin)
						{
							/* code */
						}
						else
						{
							table[3][left_d][d] += 1;
						}
						if (e == mmax || e == mmin)
						{
							/* code */
						}
						else
						{
							table[4][left_e][e] += 1;
						}
						total += 1;
					}
				}
			}
		}
	}
	printf("%d\n", total);
	for (int person = 0; person < PC; ++person)
	{
		printf("for %c\n", 'A'+person);
		for (int left = 0; left < N; ++left)
		{
			printf("left %d\n", left);
			for (int choice = 1; choice < N; ++choice)
			{
				int live = table[person][left][choice];
				if (live > 0)
				{
					printf("for %c, left %d, when %d\t%d\t%.2f%%\n", 'A'+person, left, choice, live, 1.0*live/total*100);
				}
			}
		}
	}
	int max_choice = 0;
	int max = 0;
	for (int choice = 0; choice < N; ++choice)
	{
		int live = table[0][0][choice];
		if (live > max)
		{
			max_choice = choice;
			max = live;
		}
	}
	printf("A will chose %d\n", max_choice);
	int last_choice = max_choice;
	max = 0;
	for (int choice = 0; choice < N; ++choice)
	{
		int live = table[1][N - last_choice][choice];
		if (live > max)
		{
			max_choice = choice;
			max = live;
		}
	}
	printf("B will chose %d\n", max_choice);
	last_choice = max_choice;
	max = 0;
	// for (int choice = 0; choice < N; ++choice)
	// {
	// 	int live = table[2][N - last_choice][choice];
	// 	if (live > max)
	// 	{
	// 		max_choice = choice;
	// 		max = live;
	// 	}
	// }
	// printf("C will chose %d\n", max_choice);
}
