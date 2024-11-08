//Steve Yang z5374603
int common_elements(int length, int source1[length], int source2[length], int destination[length])
{
    int num = 0;
    int i = 0;
    int j = 0;
    
    while (i < length)
    {
        j = 0;
        while (j < length)
        {
            if (source1[i] == source2[j])
            {
                destination[num] = source1[i];
                num++;
                break;
            }
            j++;
        }
        i++;
    }
    return num;
}