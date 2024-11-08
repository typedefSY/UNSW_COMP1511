// 
// Author: Steve Yang (z5374603)
// Date: INSERT-DATE-HERE
//
// Description:
// INSERT-DESCRIPTION-HERE

#include "fractions.h"

// These are function stubs!
// They are functions which compile but do not have the correct behaviour.

double convert(struct fraction frac) 
{
    double ans = 0;
    ans = (double)frac.top / (double)frac.bottom;

    return ans;
}

struct fraction add(struct fraction first, struct fraction second) 
{
    // TODO: complete the function
    struct fraction result;
    result.top = 0;
    result.bottom = 1;
    result.bottom = first.bottom * second.bottom;
    result.top = first.top * second.bottom + second.top * first.bottom;
    int top = result.top;
    int bottom = result.bottom;
    int temp_1 = 0;
    if (result.top > result.bottom)
    {
        if (top % bottom != 0)
        {
            temp_1 = top % bottom;
                while(temp_1 != 0)
            {
                top = bottom;
                bottom = temp_1; 
                temp_1 = top % bottom;
            }
            result.top = result.top / bottom;
            result.bottom = result.bottom / bottom;
        }
        else
        {
            result.top /= result.bottom;
            result.bottom = 1;
        }
    }
    else
    {
        if (bottom % top != 0)
        {
            temp_1 = bottom % top;
                while(temp_1 != 0)
            {
                bottom = top;
                top = temp_1; 
                temp_1 = bottom % top;
            }
            result.top = result.top / top;
            result.bottom = result.bottom / top;
        }
        else
        {
            result.bottom /= result.top;
            result.top = 1;
        }
    }
    

    return result;
}