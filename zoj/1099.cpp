#include <stdio.h>
#include <string.h>
int main()
{
    int i,length=0;/*当前行的长度*/
    char word[81];
    while(scanf("%s", word)!=EOF)
    {
        if(strcmp(word, "<br>")==0)
        {
            printf("\n");
            length=0;
        }
        else if(strcmp(word, "<hr>")==0)
        {
            if(length>0) printf("\n");
            for(i=0;i<80;i++) printf("-");
            printf("\n");
            length=0;
        }
        else if(length+strlen(word)+1 >80)
        {
            /*需要换行*/
            printf("\n%s", word);
            length=strlen(word);
        }
        else
        {
            /*无需要换行*/
            if(length>0)
            {
                printf(" ");
                length++;
            }
            printf("%s", word);
            length += strlen(word);
        }
    }
    return 0;
}