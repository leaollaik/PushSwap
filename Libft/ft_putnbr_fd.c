/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:57:51 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 19:00:34 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	temp = '0' + (n % 10);
	write(fd, &temp, 1);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("ft_putnbr_fd.c", O_RDWR);
// 	ft_putnbr_fd(543, fd);
// }
