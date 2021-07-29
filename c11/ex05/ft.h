#ifndef FT_H
# define FT_H

# include <unistd.h>

# define MOD0 "Stop : modulo by zero"
# define DIV0 "Stop : division by zero"

typedef enum e_op
{
	op_sum,
	op_min,
	op_div,
	op_mul,
	op_mod,
}			t_op;

int		min(int a, int b);
int		div(int a, int b);
int		mul(int a, int b);
int		mod(int a, int b);
int		sum(int a, int b);

void	ft_doop(char **av, int (**op)(int, int));

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
