/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:14:16 by angnguye          #+#    #+#             */
/*   Updated: 2022/12/16 23:31:51 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)

{
	int		count;
	va_list	arg_ptr;
	int		i;

	count = 0;
	i = 0;
	if (!input)
		return (0);
	va_start(arg_ptr, input);
	while (input[i])
	{
		if (input[i] != '%')
		{
			count += ft_putchar(input[i]);
			i++;
		}
		else if (input[i] == '%')
		{
			count += check_type(input[i + 1], arg_ptr);
			i = i + 2;
		}
	}
	va_end(arg_ptr);
	return (count);
}

int	check_type(const char converter, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (converter == 'c')
		count = ft_putchar(va_arg(arg_ptr, int));
	else if (converter == 's')
		count = ft_putstr(va_arg(arg_ptr, char *));
	else if (converter == 'd' || converter == 'i')
		count = ft_putnbr(va_arg(arg_ptr, int));
	else if (converter == '%')
		count = ft_putchar('%');
	else if (converter == 'u')
		count = ft_print_unsigned(va_arg(arg_ptr, unsigned int));
	else if (converter == 'p')
		count = ft_pointer(va_arg(arg_ptr, unsigned long long));
	else if (converter == 'X')
		count = ft_to_hex(va_arg(arg_ptr, unsigned long), 'X');
	else if (converter == 'x')
		count = ft_to_hex(va_arg(arg_ptr, unsigned long), 'x');
	return (count);
}
