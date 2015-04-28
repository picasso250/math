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
int init_table(int table[PC][N+1][N])
{
	for (int p = 0; p < PC; ++p)
	{
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				table[p][i][j] = 0;
			}
		}
	}
}
int main() {
	int table[PC][N+1][N];
	init_table(table);
	int total, n, a, b, c, d, e;
	int left, left_b, left_c, left_d, left_e;
	int mmax, mmin;
	int choice[PC]; // {a,b,c,d,e}
	total = 0;
	int left_table[PC];
	left_table[0] = N;
	for (choice[0] = 1; choice[0] < N; ++choice[0])
	{
		left_table[1] = N - choice[0];
		// print 'A take',choice[0],', left',left
		for (choice[1] = 1; choice[1] <= left_table[1]; ++choice[1])
		{
			left_table[2] = N - choice[0] - choice[1];
			for (choice[2] = 1; choice[2] <= left_table[2]; ++choice[2])
			{
				left_table[3] = N - choice[0] - choice[1] - choice[2];
				for (choice[3] = 1; choice[3] <= left_table[3]; ++choice[3])
				{
					left_table[4] = N - choice[0] - choice[1] - choice[2] - choice[3];
					for (choice[4] = 1; choice[4] <= left_table[4]; ++choice[4])
					{
						// print_choice(choice);
						assert(sum(choice) <= N);
						mmax = MAX(choice);
						mmin = MIN(choice);
						if (choice[0] == mmax || choice[0] == mmin)
						{
							// pass
						}
						else
						{
							table[0][N][choice[0]] += 1;
						}
						if (choice[1] == mmax || choice[1] == mmin)
						{
							/* code */
						}
						else
						{
							table[1][left_table[1]][choice[1]] += 1;
						}
						if (choice[2] == mmax || choice[2] == mmin)
						{
							/* code */
						}
						else
						{
							table[2][left_table[2]][choice[2]] += 1;
						}
						if (choice[3] == mmax || choice[3] == mmin)
						{
							/* code */
						}
						else
						{
							table[3][left_table[3]][choice[3]] += 1;
						}
						if (choice[4] == mmax || choice[4] == mmin)
						{
							/* code */
						}
						else
						{
							table[4][left_table[4]][choice[4]] += 1;
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
		for (int left = 0; left <= N; ++left)
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
	left = N;
	for (int person = 0; person < PC; ++person)
	{
		left -= max_choice;
		printf("%d left for %c\n", left, 'A'+person);
		max = 0;
		for (int choice = 0; choice < N; ++choice)
		{
			int live = table[person][left][choice];
			// printf("live %d when %d\n", live, choice);
			if (live > max)
			{
				max_choice = choice;
				max = live;
			}
		}
		printf("%c will chose %d\n", person+'A', max_choice);
	}
}
