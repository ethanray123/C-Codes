#include<stdio.h>
#include<conio.h>

int main()
{
    float income, sss, phc, nti, it;
    printf("Input your Income, SSS Contribution and Philhealth Contribution: ");
    scanf("%f%f%f",&income,&sss,&phc);
    nti=income-(sss+phc);
    if(nti<=10000){
        it=income*0.5;
    }else if(nti<=30000){
        it=500+((nti-10000)*0.10);  
    }else if(nti<=70000){
        it=2500+((nti-30000)*0.15);  
    }else if(nti<=140000){
        it=8500+((nti-70000)*0.20);  
    }else if(nti<=250000){
        it=22500+((nti-140000)*0.25);  
    }else if(nti<=500000){
        it=50000+((nti-250000)*0.30);  
    }else{
        it=125000+((nti-500000)*0.32);  
    }
    printf("Income Tax is : %f", it);
    getch();
    return 0;
}
