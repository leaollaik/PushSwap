#include "push_swap.h"

static void	putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

static void	putnbr_fd_long(long n, int fd)
{
	char	buf[32];
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0 && i < 31)
	{
		buf[i++] = (char)('0' + (nb % 10));
		nb /= 10;
	}
	while (i-- > 0)
		write(fd, &buf[i], 1);
}

static void	putfloat_pct_2(float v, int fd)
{
	long	scaled;

	if (v < 0)
		v = 0;
	if (v > 1)
		v = 1;
	scaled = (long)(v * 10000.0f + 0.5f); /* (fraction*100) *100 */
	putnbr_fd_long((scaled / 100), fd);
	write(fd, ".", 1);
	if ((scaled % 100) < 10)
		write(fd, "0", 1);
	putnbr_fd_long(scaled % 100, fd);
}

static void	print_strategy_line(int strategy_id)
{
	if (strategy_id == 1)
		putstr_fd("[bench] strategy: simple (O(n^2))\n", 2);
	else if (strategy_id == 2)
		putstr_fd("[bench] strategy: medium (O(n*sqrt(n)))\n", 2);
	else if (strategy_id == 3)
		putstr_fd("[bench] strategy: complex (O(n log n))\n", 2);
	else
		putstr_fd("[bench] strategy: adaptive (regime-based)\n", 2);
}

void	bench_print(t_args *args, float disorder, int strategy_id)
{
	putstr_fd("[bench] disorder: ", 2);
	putfloat_pct_2(disorder, 2);
	putstr_fd("%\n", 2);

	print_strategy_line(strategy_id);

	putstr_fd("[bench] total ops: ", 2);
	putnbr_fd_long(args->num_oper, 2);
	putstr_fd("\n", 2);

	putstr_fd("[bench] counts: ", 2);
	putstr_fd("sa=", 2); putnbr_fd_long(args->oper->sa, 2);
	putstr_fd(" sb=", 2); putnbr_fd_long(args->oper->sb, 2);
	putstr_fd(" ss=", 2); putnbr_fd_long(args->oper->ss, 2);
	putstr_fd(" pa=", 2); putnbr_fd_long(args->oper->pa, 2);
	putstr_fd(" pb=", 2); putnbr_fd_long(args->oper->pb, 2);
	putstr_fd(" ra=", 2); putnbr_fd_long(args->oper->ra, 2);
	putstr_fd(" rb=", 2); putnbr_fd_long(args->oper->rb, 2);
	putstr_fd(" rr=", 2); putnbr_fd_long(args->oper->rr, 2);
	putstr_fd(" rra=", 2); putnbr_fd_long(args->oper->rra, 2);
	putstr_fd(" rrb=", 2); putnbr_fd_long(args->oper->rrb, 2);
	putstr_fd(" rrr=", 2); putnbr_fd_long(args->oper->rrr, 2);
	putstr_fd("\n", 2);
}
