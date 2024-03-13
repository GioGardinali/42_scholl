/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:37:31 by gigardin          #+#    #+#             */
/*   Updated: 2023/11/20 22:55:08 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_char	*get_letter(char letter)
{
	t_char	*set_char;

	set_char = (t_char *)malloc(sizeof(t_char));
	set_char->single_char = letter;
	set_char->next = NULL;
	return (set_char);
}

void	link_letter(t_char **head, t_char *new_letter)
{
	t_char	*aux;

	if (!new_letter)
		return ;
	if (!*head)
	{
		*head = new_letter;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = new_letter;
}

char	*free_str(t_char *string)
{
	t_char	*temp;

	temp = string;
	while (temp)
	{
		temp = temp->next;
		free(string);
		string = temp;
	}
	temp = NULL;
	return (NULL);
}
