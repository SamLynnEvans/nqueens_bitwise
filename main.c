#include <stdio.h>
#include <stdlib.h>

int	g_count = 0;

void	check_number(char *str);

void	get_number(char *str)
{
	printf("enter a number between 4 and 16 (inclusive): ");
	scanf("%s", str);
	check_number(str);
}

void	check_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || i == 2 || atoi(str) < 4 || atoi(str) > 16)
		{
			printf("incorrect input, let's try again...\n");
			get_number(str);
			break ;
		}
		i++;
	}	
}

void	recursive_solver(int row, int maj_con, int min_con, int col_con, int n)
{
	int queen_position;
	int	conflicts = min_con | maj_con | col_con;
	int	i;

	i = 0;
	min_con &= 65535;
	while (i < n)
	{
		queen_position = 1 << (15 - i);
		if (!(queen_position & conflicts))
		{
			if (row == n - 1)
				g_count++;
			else
				recursive_solver(row + 1, (maj_con | queen_position) >> 1, (min_con | queen_position) << 1, col_con | queen_position, n);
		}
		i++;
	}
}

void	solve_queens(int n)
{
	int	minor_dconflict;
	int	major_dconflict;
	int	column_conflict;

	column_conflict = 0;
	major_dconflict = 0;
	minor_dconflict = 0;
	recursive_solver(0, column_conflict, major_dconflict, minor_dconflict, n);
	printf("solutions = %d\n", g_count);
}

int main(void)
{
	char	str[80];
	int		n;

	get_number(str);
	n = atoi(str);
	printf("you entered %d\n", n);
	solve_queens(n);
}
