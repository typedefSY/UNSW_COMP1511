//Steve Yang z5374603
int remove_duplicates(int length, int source[length], int destination[length])
{
    int i = 0;
    int j = 0;
    int equal = 0;
    int num = 0;
    while (i < length)
    {
        j = i - 1;
        equal = 0;
        while (j >= 0)
        {
            if (source[i] == source[j])
            {
                equal = 1;
                break;
            }
            j--;
        }
        if (equal == 0)
        {
            destination[num] = source[i];
            num++;
        }
        i++;
    }
    return num;
}
