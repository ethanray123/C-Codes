#include<stdio.h>
#include<conio.h>

char validatePass(int pass);
void changePass(int *password, int pass);

int main(){
    int password = 1234, pass;
    char check;
    printf("Your Default Password is : %d",password);
    printf("\n\nEnter a four Digit Password: ");
    scanf("%d",&pass);
    check = validatePass(pass);
    if(check == 'A'){
         changePass(&password, pass); 
         printf("Your password was successfully changed"); 
         printf("\n Your New Password is : %d", password);    
    }else{
         printf("Invalid Password!"); 
    }

    getch();
    return 0;
}

char validatePass(int pass){
    char validation;
    if(pass < 10000 && pass > 999){
         validation = 'A';     
    }else{
         validation = 'D'; 
    }
    return validation;           
}

void changePass(int *password, int pass){
        *password=pass;
}
