#include <stdio.h>
#include <math.h>

int mdc(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b); //% é o resto da divisão de a/b
    }
}

int main(){
    printf("MDC: %d\n", mdc(24,40));
    return 0;
}