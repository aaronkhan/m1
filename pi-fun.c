
double pi_leibniz (int n);
double pi_bbp (int n);

double pi_leibniz (int n)  //Leibniz Series calculation of pi
{
    int i;
    double pi2 = 0.;
    double s = 1.;

    for (i = 0; i < n; i++)
    {
        pi2 += s / (2 * i + 1.);
        s = -s;
    }
    return 4 * pi2;
}

double pi_bbp (int n)  //BBP Series calculation of pi:
{
    int k, k8;
    double pi = 0.;
    double sc = 1.;

    for (k = 0; k < n; k++)
    {
        k8 = 8*k;
        pi += sc*(4./(k8 + 1) - 2./(k8 + 4) - 1./(k8 + 5) - 1./(k8 + 6));
        sc /= 16.;
    }
    return pi;
}
