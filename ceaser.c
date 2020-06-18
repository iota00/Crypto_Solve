#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
void encypt(){
    // using malloc is pretty good , but for now let's just make a test
    char s[1000];
    int key;

    printf("Enter ROT number :\n");
    scanf("%d",&key);


    // in case the input is over than 25 : 
    if(key >= 26) 
        key %= 26;
    printf("Enter the original text : \n");
    scanf("\n%[^\n]",s);
    printf("\n--------------------------------------------------------------\n");
    // change and print the Encrypted Text :
    printf("\n Encypted Text :\n   ");
    for (int i = 0; i < strlen(s); i++)
    {
        // check for non alpha char :
        if(isalpha(s[i])){
            if((s[i] + key) > 'z'){
                int new;
                new = s[i] + key - 'z' -1;
                printf("%c" , 'a' + new);
            }
            else if ((s[i] + key) > 'Z' && s[i] <= 'Z') 
            // the second condition is because if the text is in lower case then the first condition well be always true .
            {
                int new;
                new = s[i] + key - 'Z' -1;
                printf("%c" , 'A' + new);
            }
            else
                printf("%c",s[i] + key);
            }
        else
            printf("%c",s[i]);
    }
    printf("\n");
    sleep(1);
}


void decrypt(){
    char s[1000];
    int key;

    printf("Entre ROT number  or '0' if don't know it : \n");
    scanf("%d",&key);
    
    if(key >= 26)
        key %= 26;
    printf("\n Entre the Cipher text : \n");
    scanf("\n%[^\n]",s);
    printf("\n--------------------------------------------------------------\n");
    printf("The decrypted text is :\n   ");
    if (key)
    { 
       for (int i = 0; i < strlen(s); i++)
       {
        if(isalpha(s[i])){
            // the second condition is because if the text is in upper case then the first condition well be always true .
            if((s[i] - key) < 'a' && s[i] >= 'a'){
                int new;
                new = 'a' -( s[i] - key)  -1 ;
                printf("%c" , 'z' - new);
            }
            else if ((s[i] - key) < 'A' ) 
            {
                int new;
                new = 'A' - (s[i] - key) - 1 ;
                printf("%c" , 'Z' - new);
            }
            else
                printf("%c",s[i] - key);
        }
        else
            printf("%c",s[i]);   
       }
       
       
    }
    else{
        for (int j = 0; j < 26; j++)
        {
            printf("\n ROT %d :      ",j);
            for (int i = 0; i < strlen(s); i++)
            {
                if(isalpha(s[i])){
                    if((s[i] - j) < 'a' && s[i] >= 'a'){
                        int new;
                        new = 'a' -( s[i] - j)  -1 ;
                        printf("%c" , 'z' - new);
                    }
                    else if ((s[i] - j) < 'A' ) 
                    {
                        int new;
                        new = 'A' - (s[i] - j) - 1 ;
                        printf("%c" , 'Z' - new);
                    }
                    else
                        printf("%c",s[i] - j);
                    }
                    else
                        printf("%c",s[i]); 
            }
        }
    }
 printf("\n");   
 sleep(1);
}
int main(int argc, char const *argv[])
{
    int choice ;
    do{
            printf("------------------------- Welcome : ------------------------- \n");
            printf("Entre your choice : \n");
            printf("  > 1.Encrypt\n");
            printf("  > 2.Decrypt\n");
            printf("  > 3.Exit\n");
            // Get user choice :
            scanf("%d",&choice);

            // Call functions :
            switch (choice)
            {
                case 1:
                    encypt();
                    break;
                case 2:
                    decrypt();
                    break;
            }
    }while(isalpha(choice) == 0 && choice != 3);
    printf("\n Thanks for using this program ... \n");
    sleep(1);
    return 0;
}
