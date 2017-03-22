#include <stdlib.h>
#include <stdio.h>

int __strlen(char * str, int * spacji);

int main(void){
    int spacji = 0;
    char tab[] = {"  RAn    dom t    e           x                           t.               "};
    printf_s("%s\n%d\n", tab, __strlen(tab, &spacji));
    printf_s("%d slowa\n\n", spacji);
    return 0;
}

int __strlen(char * str, int * spacja){
    int znaki, doubles = 0;
    for(znaki = 0; *(str + znaki) != '\0'; znaki++){
        if(32 == (int)*(str + znaki)){
            if(32 != (int)*(str + znaki + 1) && znaki > 0 && *(str + znaki + 1) != '\0')
                (*spacja)++;
            else
                doubles++;  //zdublowane spacje
        }
    }
    return znaki - *spacja - doubles;
}
