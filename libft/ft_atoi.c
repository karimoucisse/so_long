/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:11:25 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/05 17:24:11 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	get_res(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

// transform char to int
long	ft_atoi(const char *str)
{
	long	i;
	long	res;
	int		plus_sign;
	int		minus_sign;

	i = 0;
	res = 0;
	plus_sign = 0;
	minus_sign = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			plus_sign++;
		if (str[i] == '-')
			minus_sign++;
		if ((plus_sign + minus_sign) > 1)
			return (0);
		i++;
	}
	res = get_res(str + i);
	if (minus_sign > 0)
		return (-res);
	return (res);
}
