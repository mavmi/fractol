#ifndef COMPLEX_H
# define COMPLEX_H

# include <stdlib.h>
# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
	double	value;
}			t_complex;

t_complex	*complex_sum(t_complex *left, t_complex *right);
t_complex	*complex_multi(t_complex *left, t_complex *right);
t_complex	*complex_power_2(t_complex	*number);
t_complex	*init_complex(double re, double im);

#endif