NAME		=	fractol
MLX			=	libmlx.a
LIBFT		=	libft.a


SRCS_DIR	=	srcs
HDRS_DIR	=	include
MLX_DIR_MAC	=	minilibx_opengl
MLX_DIR_LIN	=	minilibx_linux
LIBFT_DIR	=	libft


HDRS		=	$(addprefix $(HDRS_DIR)/, complex.h fractol.h utils.h)
MLX_MAC_HDRS=	$(addprefix $(MLX_DIR_MAC)/, mlx_int.h mlx_new_window.h mlx_opengl.h mlx_png.h mlx.h)
MLX_LIN_HDRS=	$(addprefix $(MLX_DIR_LIN)/, mlx.h)
LIBFT_HDRS	=	$(addprefix $(LIBFT_DIR)/, libft.h)


SRCS		= 	$(addprefix $(SRCS_DIR)/, draw.c complex.c events.c fractol.c utils.c)
OBJS		=	$(SRCS:.c=.o)


MLX_MAC_FL	=	-I $(MLX_DIR_MAC)/ -framework OpenGL -framework AppKit
MLX_LIN_FL	=	-I $(MLX_DIR_LIN)/ -lXext -lX11 -lm -lz
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HDRS) $(MLX_MAC_HDRS) $(LIBFT_HDRS)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS)
				cd $(LIBFT_DIR) && $(MAKE)
				cd $(MLX_DIR_MAC) && $(MAKE)
				$(GCC) $(MLX_MAC_FL) $(MLX_DIR_MAC)/$(MLX) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

linux:			$(OBJS)
				cd $(LIBFT_DIR) && $(MAKE)
				cd $(MLX_DIR_LIN) && $(MAKE)
				$(GCC) $(OBJS) -L$(MLX_DIR_LIN) -lmlx_Linux -L/usr/lib -I$(MLX_DIR_LIN) -lXext -lX11 -lm -lz $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:				
				rm -f $(OBJS)
				cd $(MLX_DIR_MAC) && $(MAKE) clean
				cd $(LIBFT_DIR) && $(MAKE) clean

fclean:			clean
				rm -f $(NAME)
				cd $(MLX_DIR_MAC) && $(MAKE) clean
				cd $(LIBFT_DIR) && $(MAKE) fclean

clean_linux:	
				rm -f $(OBJS)
				cd $(MLX_DIR_LIN) && $(MAKE) clean
				cd $(LIBFT_DIR) && $(MAKE) clean

fclean_linux:	clean
				rm -f $(NAME)
				cd $(MLX_DIR_LIN) && $(MAKE) clean
				cd $(LIBFT_DIR) && $(MAKE) fclean

re:				fclean $(NAME)

.PHONY:			all clean fclean re
