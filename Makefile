CFLAGS= -Wall -Wextra -Werror -O3 -g
NAME= fractol
BNAME= fractol_bonus
MSRCS= main.c events.c julia.c mandelbrot.c fract_utils.c \
		utils.c utils2.c
BSRCS= main.c events.c julia.c mandelbrot.c fract_utils.c \
		burning_ship.c utils.c utils2.c map_utils.c
MOBJS= $(addprefix mandatory/, $(MSRCS:.c=.o))
BOBJS= $(addprefix bonus/, $(BSRCS:.c=.o))

all: minilbx $(NAME)

bonus: minilbx $(BNAME)

$(NAME): $(MOBJS)
	$(CC) $(CFLAGS) $(MOBJS) minilibx-linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) minilibx-linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -lm -lz -o $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

minilbx:
	make -C minilibx-linux/

clean:
	$(RM) $(MOBJS) $(MOBJS:.o=.d)
	$(RM) $(BOBJS) $(BOBJS:.o=.d)

fclean: clean
	make clean -C minilibx-linux/
	$(RM) $(NAME)
	$(RM) $(BNAME)

re: fclean all

.PHONY: minilbx clean

-include $(MOBJS:.o=.d)
-include $(BOBJS:.o=.d)
