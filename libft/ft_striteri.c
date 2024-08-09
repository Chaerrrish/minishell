/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:45:58 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/19 14:50:07 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ff(unsigned int a, char* b)
{
	write(1, &b[a], 1);
}

int main(void)
{
	void (*f)(unsigned int, char*);
	f = ff;
	char s[10] = "abcdefghi";

	ft_striteri(s, f);
	return (0);
}*/
