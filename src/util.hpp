#include <gtkmm-4.0/gtkmm.h>
#include <math.h>

namespace bcalc
{
    int digits(int n)
    {
        int i = 0;

        do
        {
            n /= 10;
            i++;
        }
        while (n);

        return i;
    }
}
