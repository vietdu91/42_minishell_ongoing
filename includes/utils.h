/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:44:03 by emtran            #+#    #+#             */
/*   Updated: 2022/02/10 22:19:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 1

/* 		UTILS_DIGITS 	*/

long int	ft_atoi(const char *str);
int			ft_nbrlen(int n);

/*		UTILS_LINKED	*/

int			add_node_after_current(char *content, t_pars_node *n, \
			t_pars_list *l);

/*		UTILS_MEMORY	*/

void		*ft_memcpy(void *dest, const void *src, size_t count);
char		*ft_strcalloc(size_t size);
void		*ft_calloc(size_t num, size_t size);

/* 		UTILS_SPLIT 	*/

size_t		ft_wordcount(char const *s, char c);
size_t		ft_wordlen(char const *s, char c);
char		**ft_freetamere(char **array);
char		**ft_split(char const *s, char c);

/*		UTIS_SPLIT_CHARSET.C		*/

int			size_word(char *s, char *c, t_args *args);
int			count_words(char *s, char *c);
int			ready_for_split(int nb_words, char *c, char *s, char **flag);
char		**create_split(char **split, int nb_words);
char		**ft_split_charset(char **splitted, char *s, char *c, t_args *args);

/*		UTILS_STRINGS 	*/

int			ft_strlen(char *str);
int			ft_strcmp(char *str1, char *str2);
void		ft_strcpy(char *dest, char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strnstr(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *str);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
char		*join_char(char *str, char c);
size_t		ft_strlcpy_w_quotes(char *dest, char *src, size_t size);

/* 		UTILS_WRITE 	*/

void		ft_putnbr(int nb, int fd);
void		ft_putstr(char *str, int fd);
void		ft_putchar(char c, int fd);

/*		UTILS_META.C	*/
int			does_meta_exist(t_pars_node *node);
int			is_full_meta(char *str);
char		*new_content_first(t_pars_node *node, int *i);
void		splitter_content_meta(t_pars_node *node, t_pars_list *l);

#endif