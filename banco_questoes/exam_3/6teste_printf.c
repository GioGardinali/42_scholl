/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6teste_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:09:17 by gigardin          #+#    #+#             */
/*   Updated: 2024/08/19 20:24:13 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//função construída no dia 19/08 as 20:23, demorei 15 minutos
void put_string(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void put_digit(long long int number, int base, int *len)
{
	char *hex = "0123456789abcdef";
	
	if (number < 0)
	{
		number = number * -1;
		*len += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number/base), base, len);
	*len += write(1, &hex[number % base], 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list pointer;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			if (*format == 's')
				put_string(va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return ((va_end(pointer)), len);
}