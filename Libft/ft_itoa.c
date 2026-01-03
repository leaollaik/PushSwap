/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:47:13 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 19:02:13 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	check(long *num, int *len)
{
	if (*num < 0)
	{
		*num = -(*num);
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = num_len(n);
	check(&num, &len);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if ((num == 0 && len > 0 && n < 0))
		{
			str[0] = '-';
			break ;
		}
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// }
