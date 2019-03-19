/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 23:43:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/18 23:43:41 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    *convertit(t_tetra *tetramino, char **tetra)
{
  int x;
  int y;
  char found;
  int anc_x;
  int anc_y;

  y = 0;
  found = 0;

   while(y < 4)
   {
     x = 0;
     while(tetra[x][y] == '.')
      x++;
     if (tetra[x][y] == '#' && found == '0'){
      anc_x = x;
      anc_y = y;
      found == 1;}
     if (tetra[x][y] == '#' && found == '1'){
       tetramino->block1 = {x,y}; //convert x,y according to anchors x & y
       found == '2';}
     if (tetra[x][y] == '#' && found == '2'){
       tetramino->block2 = {x,y}; //store x,y to int arr element of struct
       found == '3';}
     if (tetra[x][y] == '#' && found == '3'){
       tetramino->block3 = {x,y}; //create indication of last block found
       found == '4';}
     if (found == '4')
        break ;
     y++;
   }
   tetramino->letter_id = 'A'; //set incrementation on each entrance

  return (tetramino);
}

t_tetra				*ft_newtetra(char **tetra)
{
  t_tetra *tetramino;

  if (!(tetramino = (t_tetra *)malloc(sizeof(*tetramino))))
		return (NULL);
  if (!tetra)
  {
    tetramino->block1 = NULL;
    tetramino->block2 = NULL;
    tetramino->block3 = NULL;
    tetramino->letter_id = 0;
  }
  else
  {
    if (!(tetramino->block1 = (int *)malloc(sizeof(int *) * 3)))
      return (NULL);
    if (!(tetramino->block2 = (int *)malloc(sizeof(int *) * 3)))
      return (NULL);
    if (!(tetramino->block3 = (int *)malloc(sizeof(int *) * 3)))
      return (NULL);
    if (!(tetramino->letter_id = (char)malloc(sizeof(char) * 2)))
      return (NULL);
    convertit(tetramino, tetra);
  }
  tetramino->next = NULL;
  return (tetramino);
}
