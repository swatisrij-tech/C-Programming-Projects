#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void showMenu();
void handleArithmetic();
void handleAdvancedMath();
void handleMatrixOperations();

int main() {
    int calculationType;
    while (1) {
        showMenu();
        if (scanf("%d", &calculationType) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (calculationType == 0) {
            printf("Exiting Calculator. Goodbye!\n");
            break;
        }

        switch (calculationType) {
            case 1:
                handleArithmetic();
                break;
            case 2:
                handleAdvancedMath();
                break;
            case 3:
                handleMatrixOperations();
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
        printf("\n----------------\n");
    }

    return 0;
}

void showMenu() {
    printf("\n<--->> All In One Calculator<< --->\n");
    printf("1. Simple Arithmetic (Addition, Subtraction, etc.)\n");
    printf("2. Advanced Math (Factorial, Fibonacci)\n");
    printf("3. Matrix Solver\n");
    printf("0. Exit Application\n");
    printf("Enter what you want to do: ");
}

void handleArithmetic() {
    double a,b,result,res;
        int choice;
        printf("\nEnter Numbers\n");
        scanf("%lf %lf",&a,&b);
        printf("Enter 1 for Addtion\n");
        printf("Enter 2 for Subraction\n");
        printf("Enter 3 for Multiplication\n");
        printf("Enter 4 for Division\n");
        printf("Enter 5 for Power Of Number a power b\n");
        printf("Enter 6 for Logorithmn\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            result=a+b;
            printf("Addition Is= %lf",result);
            break;
            case 2:
            result=a-b;
            printf("Subraction Is= %lf",result);
            break;
            case 3:
            result=a*b;
            printf("Multiplication Is= %lf",result);
            break;
            case 4:
            if(b==0){
                result=0;
                printf("Division Is= %lf",result);
            }
            else if(b!=0){
                result=a/b;
                printf("Division Is= %lf",result);
            }
            break;
            case 5:
            result=pow(a,b);
            printf("Power Is= %lf",result);
            break;
            case 6:
            result=log(a);
            res=log10(a);
            printf("log of with base e is= %lf",result);
            printf("Log with base 10 is= %lf",res);
            break;
            default:
            printf("Invalid Numbers");
            break;
        }
}
void handleAdvancedMath() {
    int input;
    printf("Enter 1 for Factorial\n");
    printf("Enter 2 for Fibonacci\n");
    scanf("%d",&input);
    int n;
    int f=1;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    scanf("%d",&n);
    switch(input){
        case 1:
        printf("Factorial of %d\n",n);
        for(int i=n;i>=1;i--){
            f=f*i;
            }
        printf("%d",f);
        break;
        case 2:
        printf("Fibonacci Series: %d, %d, ", t1, t2);
        for (int i = 3; i <= n; ++i) {
            printf("%d, ", nextTerm);
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        } 
    }
}
void handleMatrixOperations() {
    int row1,col1;
    printf("First Matrix\n");
    printf("Enter Number of Values For Row 1\n");
    scanf("%d",&row1);
    printf("Enter Number of Values For Column1\n");
    scanf("%d",&col1);
    int matr1[row1][col1];
    printf("Enter Values For Rows and Columns\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            scanf("%d",&matr1[i][j]);
        }
    }
    int row2,col2;
    printf("\nSecond Matrix");
    printf("\nEnter Number of Values For Row 2\n");
    scanf("%d",&row2);
    printf("\nEnter Number of Values For Column2\n");
    scanf("%d",&col2);
    int matr2[row2][col2];
    printf("\nEnter Values For Row and Columns\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            scanf("%d",&matr2[i][j]);
        }
    }
    printf("Your First Matrix\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d  ",matr1[i][j]);
        }
        printf("\n");
    }
    printf("Your Second Matrix\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("%d ",matr2[i][j]);
        }
        printf("\n");
    }
    int choose;
    printf("Enter 1 for Matrix Addition\n");
    printf("Enter 2 for Matrix Subraction\n");
    printf("Enter 3 for Matrix Multiplication\n");
    printf("Enter 4 for Matrix Determinant\n");
    printf("Enter 5 for Matrix Transpose\n");
    printf("Choose");
    scanf("%d",&choose);
    switch(choose){
        case 1:
        if(row1==row2&&col1==col2){
            for(int i=0;i<row1;i++){
                for(int j=0;j<col1;j++){
                    printf("%d ",matr1[i][j]+matr2[i][j]);
                }
                    printf("\n");
            }  
        }
        else{
            printf("Matrix Addition Is Not Possible In Unequal Rows and Column!!");
        }
        break;
        case 2:
        if(row1==row2&&col1==col2){
            for(int i=0;i<row1;i++){
                for(int j=0;j<col1;j++){
                    printf("%d ",matr1[i][j]-matr2[i][j]);
                }
                    printf("\n");
            }  
        }
        else{
            printf("Matrix Subraction Is Not Possible In Unequal Rows and Column!!");
        }
        break;
        case 3:
        if (col1 == row2) { 
            int mul[100][100] = {0}; 
            for (int i = 0; i < row1; i++) {
                for (int j = 0; j < col2; j++) {
                    for (int k = 0; k < col1; k++) {
                        mul[i][j] += matr1[i][k] * matr2[k][j];
                    }
                    printf("%d ", mul[i][j]);
                }
                printf("\n");
            }
        } 
        else {
            printf("Matrix Multiplication Is Not Possible! Columns of Matrix 1 must equal Rows of Matrix 2.\n");
        }
        break;
        case 4:
        if (row1 == col1) {
            int det = 0;
            
            if (row1 == 1) {
                det = matr1[0][0];
                printf("Determinant of Matrix 1: %d\n", det);
            } 
            else if (row1 == 2) {
                det = (matr1[0][0] * matr1[1][1]) - (matr1[0][1] * matr1[1][0]);
                printf("Determinant of Matrix 1: %d\n", det);
            } 
            else if (row1 == 3) {
                det = matr1[0][0] * (matr1[1][1] * matr1[2][2] - matr1[1][2] * matr1[2][1])
                    - matr1[0][1] * (matr1[1][0] * matr1[2][2] - matr1[1][2] * matr1[2][0])
                    + matr1[0][2] * (matr1[1][0] * matr1[2][1] - matr1[1][1] * matr1[2][0]);
                printf("Determinant of Matrix 1: %d\n", det);
            } 
            else {
                printf("Determinant calculation only supported up to 3x3 in this version.\n");
            }
        } else {
            printf("Determinant Is Not Possible! The matrix must be square (Rows == Columns).\n");
        }
        break;
        case 5:
        printf("Transpose of Matrix 1:\n");
        for (int j = 0; j < col1; j++) {
            for (int i = 0; i < row1; i++) {
                printf("%d ", matr1[i][j]);
            }
            printf("\n");
        }
        break;
        default:
        printf("Invalid**");



    }   
}  

    
    
    