#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long n = get_long("Number: ");
    int length = 0;
    long num = n;

    while(num>0)
    {
        length++;
        num /= 10;
    }

    int a = (n%10);
    int b = (n/10)%10;
    int c = (n/100)%10;
    int d = (n/1000)%10;
    int e = (n/10000)%10;
    int f = (n/100000)%10;
    int g = (n/1000000)%10;
    int h = (n/10000000)%10;
    int i = (n/100000000)%10;
    int j = (n/1000000000)%10;
    int k = (n/10000000000)%10;
    int l = (n/100000000000)%10;
    int m = (n/1000000000000)%10;
    
    int aa = (2*b);
    int ab = (2*d);
    int ac = (2*f);
    int ad = (2*h);
    int ae = (2*j);
    int af = (2*l);
    int pa = 0;
    int pb = 0;
    int pc = 0;
    int pd = 0;
    int pe = 0;
    int pf = 0;
    int pg = 0;
    int ph = 0;

    //visa or mastercard LENGTH 16
    if (length == 16)
    {
        int v = (n/10000000000000)%10;
        int o = (n/100000000000000)%10;
        int p = (n/1000000000000000)%10;
        int ag = (2*v);
        int ah = (2*p);
        if(aa>9)
        {
            pa = (aa/10)%10 + (aa%10);
        }
        else
        {
            pa = aa%10;
        }
        if(ab>9)
        {
            pb = (ab/10)%10 + (ab%10);
        }
        else
        {
            pb = ab%10;
        }
        if(ac>9)
        {
            pc = (ac/10)%10 + (ac%10);
        }
        else
        {
            pc = ac%10;
        }
        if(ad>9)
        {
            pd = (ad/10)%10 + (ad%10);
        }
        else
        {
            pd = ad%10;
        }
        if(ae>9)
        {
            pe = (ae/10)%10 + (ae%10);
        }
        else
        {
            pe = ae%10;
        }
        if(af>9)
        {
            pf = (af/10)%10 + (af%10);
        }
        else
        {
            pf = af%10;
        }
        if(ag>9)
        {
            pg = (ag/10)%10 + (ag%10);
        }
        else
        {
            pg = ag%10;
        }
        if(ah>9)
        {
            ph = (ah/10)%10 + (ah%10);
        }
        else
        {
            ph = ah%10;
        }
        int sum16 = pa + pb + pc + pd + pe + pf + pg + ph;
        int x16 = (a + c + e + g + i + k + m + o);
        int y16 = sum16 + x16;
        int z16 = y16%10;
//CHECKING FRONT DIGITS
        if ((p == 5) & (o == 1 || o == 2 || o == 3 || o == 4 || o == 5) & (z16 == 0))
         {
             printf("MASTERCARD\n");
         }
         else if ((p == 4) & (z16 == 0))
         {
             printf("VISA\n");
         }
         else
        {
            printf("INVALID\n");
        }
    }
    //IF FIFTEEN
    else if (length == 15)
    {
        int v = (n/10000000000000)%10;
        int o = (n/100000000000000)%10;
        int ag = (2*v);
        if(aa>9)
        {
            pa = (aa/10)%10 + (aa%10);
        }
        else
        {
            pa = aa%10;
        }
        if(ab>9)
        {
            pb = (ab/10)%10 + (ab%10);
        }
        else
        {
            pb = ab%10;
        }
        if(ac>9)
        {
            pc = (ac/10)%10 + (ac%10);
        }
        else
        {
            pc = ac%10;
        }
        if(ad>9)
        {
            pd = (ad/10)%10 + (ad%10);
        }
        else
        {
            pd = ad%10;
        }
        if(ae>9)
        {
            pe = (ae/10)%10 + (ae%10);
        }
        else
        {
            pe = ae%10;
        }
        if(af>9)
        {
            pf = (af/10)%10 + (af%10);
        }
        else
        {
            pf = af%10;
        }
        if(ag>9)
        {
            pg = (ag/10)%10 + (ag%10);
        }
        else
        {
            pg = ag%10;
        }
        int sum15 = pa + pb + pc + pd + pe + pf + pg;
        int x15 = (a + c + e + g + i + k + m + o);
        int y15 = sum15 + x15;
        int z15 = y15%10;
        if ((o == 3) & (v == 4 || v == 7) & (z15 == 0))
         {
             printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //IF THIRTEEN
    else if (length == 13)
{
    int x = (a + c + e + g + i + k + m);
    if(aa>9)
    {
        pa = (aa/10)%10 + (aa%10);
    }
    else
    {
        pa = aa%10;
    }
    if(ab>9)
    {
        pb = (ab/10)%10 + (ab%10);
    }
    else
    {
        pb = ab%10;
    }
    if(ac>9)
    {
        pc = (ac/10)%10 + (ac%10);
    }
    else
    {
        pc = ac%10;
    }
    if(ad>9)
    {
        pd = (ad/10)%10 + (ad%10);
    }
    else
    {
        pd = ad%10;
    }
    if(ae>9)
    {
        pe = (ae/10)%10 + (ae%10);
    }
    else
    {
        pe = ae%10;
    }
    if(af>9)
    {
        pf = (af/10)%10 + (af%10);
    }
    else
    {
        pf = af%10;
    }
    int sum13 = pa + pb + pc + pd + pe + pf;
    int x13 = (a + c + e + g + i + k + m);
    int y13 = sum13 + x13;
    int z13 = y13%10;
    if ((m == 4) & (z13 == 0))
    {
         printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
//if INVALID
    else
    {
        printf("INVALID\n");
    }
    }
