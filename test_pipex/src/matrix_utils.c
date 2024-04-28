/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:23:14 by madias-m          #+#    #+#             */
/*   Updated: 2024/04/28 15:23:16 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_matrixlen(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size])
		size++;
	return (size);
}

void	ft_free_matrix(char ***matrix)
{
	int	y;

	y = 0;
	while ((*matrix)[y])
		free((*matrix)[y++]);
	free(*matrix);
}
