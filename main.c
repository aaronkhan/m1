#include <stdio.h>
#include <math.h>

#include "timer.h"

double pi_leibniz (int n);
double pi_bbp (int n);
int adjust_rep_count (int count, double time, double tmin, double tmax);

int main (void)
{
    double tol = 1.e-6;
    double abserr, pi;
    int i = 1;
    int ibbp, ileibniz;
    double tmin = 1., tmax = 2., time, time1;

    do
    {
        pi = pi_bbp (i);
        abserr = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;
    }
    while (abserr > tol);
    ibbp = i / 2;
    printf ("\n");

    i = 1;
    do
    {
        pi = pi_leibniz (i);
        abserr = fabs (pi - M_PI);
        printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;
    }
    while (abserr > tol);
    ileibniz = i / 2;
    printf ("\n");

    int count;

    count = 1000;
    do
    {
        timer_start ();

        for (i = 0; i < count; i++)
        {
            pi_leibniz (ileibniz);
        }

        time = timer_stop ();
        time1 = time / count;
        printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);
        /*
         * adjust count such that cpu time is between
         * tmin and tmax
         */
        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf (" Leibniz: time per call = %10.2f usec\n", time1 * 1.e6);
    
    do
    {
        timer_start ();

        for (i = 0; i < count; i++)
        {
            pi_bbp (ibbp);
        }

        time = timer_stop ();
        time1 = time / count;
        printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);
        /*
         * adjust count such that cpu time is between
         * tmin and tmax
         */
        count = adjust_rep_count (count, time, tmin, tmax);
    }

    while ((time > tmax) || (time < tmin));
    printf (" Bbp: time per call = %10.2f usec\n", time1 * 1.e6);

    return 0;
}
