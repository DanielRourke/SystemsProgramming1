#include "iorb.h"
#include "time.h"


int isInteger(char * str);

int main(int argc, char *argv[])
{
    int size;
    //validate user input
    if (argc > 2 )
    {
        printf("Usage: ./main or ./main integer \n");
        return -1;
    }
    else if(argc == 2 && isInteger(argv[1]) == 0)
    {
        printf("Usage: ./main or ./main integer\n");
        return -1;
    }
    else if (argc == 2)
    {
        size  = atoi(argv[1]);
        if(size < 0)
        {
            printf("Integer must be Posative\n");
            printf("Usage: ./main or ./main integer\n");
            return 1;
        }
        else if(size > 10000)
        {
            printf("Integer must be less than 10000\n");
            printf("Usage: ./main or ./main integer\n");
            return 1;
        }
    }
    else
        size = 20;
    
    srand(time(0));
    POINTER Head;
    Head = (POINTER) 0;
    build_list(&Head, size);
    print_list(Head);
    sort_list_bubble(&Head , calc_pri_accending );
    test_list(Head , calc_pri_accending );
    print_list(Head);

    return 1;
}


isInteger(char * str)
{
    int ret = 1;
    while(*str != '\0')
    {
        if (!isdigit(*str))
        {
            ret = 0;
           
        }
        *str++;
    }
    
    return ret;
}