#include <stdio.h>
#define sys_kernel_2D_memcpy 451
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int main() {
    float M1[3][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0}};
    float M2[3][3] = {{10.0,11.0,12.0},{13.0,14.0,15.0},{16.0,17.0,18.0}};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M2[i][j]);
        }
        printf("\n");
    }

    int sissy = syscall(sys_kernel_2D_memcpy, M2, M1);
    if(sissy < 0){
        printf("Error");
        return 1;

    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M2[i][j]);
        }
        printf("\n");
    }

    return 0;

}