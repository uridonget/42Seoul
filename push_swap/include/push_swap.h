/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:05:37 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/14 12:11:49 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	size_t			idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t			size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

typedef struct s_vars
{
	size_t	chunk;
	t_stack	*a;
	t_stack	*b;
}	t_vars;

// ft_free.c : free 함수
void		free_stack(t_stack *stack);
void		free_all(t_vars *vars);

// init_stack.c : 스택을 할당함
int			init_stack(t_vars *vars);

// ft_node.c : 노드와 관련된 함수들
t_node		*ft_new_node(long long num);
t_node		*ft_get_node(t_stack *stack);
void		ft_add_node_back(t_stack *stack, t_node *new);
void		ft_add_node_front(t_stack *stack, t_node *new);

// ft_atoi.c : 문자열을 정수로 바꾸기
int			ft_isspace(int c);
long long	ft_atoi(const char *str);

// insert_num.c : argv를 정수로 바꿔서 노드에 넣는 함수
int			insert_num(char const *str, t_stack *stack);

// set_idx.c : 노드에 저장된 값을 비교하여 인덱스를 할당
int			set_idx(t_stack *stack);

// ft_push.c
int			pa(t_vars *vars);
int			pb(t_vars *vars);

// ft_swap.c
int			sa(t_stack *a);
int			sb(t_stack *b);
int			ss(t_vars *vars);

// ft_rotate.c
int			ra(t_stack *a);
int			rb(t_stack *b);
int			rr(t_vars *vars);

// ft_rev.c
int			rra(t_stack	*a);
int			rrb(t_stack *b);
int			rrr(t_vars *vars);

// ft_commnad.c : 명령어 실행. flag가 1이면 cmd 출력
int			ft_command(t_vars *vars, char *cmd, int flag);

// is_sorted.c : 스택이 정렬되었는지 확인
int			is_sorted(t_stack *a);

// a_to_b.c : A에서 B로 노드들을 이동
void		a_to_b(t_vars *vars);

// b_to_a.c : B에서 A로 노드들을 이동
void		b_to_a(t_vars *vars, size_t target);

// push_swap.c : 값들을 A에 정렬시키기
void		push_swap(t_vars *vars);

// ft_sort.c : 적은 개수의 노드들을 하드코딩으로 정렬 sort_a는 3개 이하, sort_6은 6개 이하
void		sort_a(t_vars *vars);
void		sort_b(t_vars *vars);
void		sort_6(t_vars *vars);

// print_err.c : Error\n 를 프린트하며 리턴값이 0
int			print_err(void);

#endif
