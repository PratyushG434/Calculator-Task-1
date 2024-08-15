#include<iostream>
using namespace std;
long int factorial(int n)
{
    long int fact=1;
    for(int j=1;j<=n;j++)
    {
        fact*=j;
    }
    return fact;
}
double sine(double angle)
{
    double sinvalue = 0;
    double x = 1;
    long int i;
    for(i=1;i<=30;i++)
    {   
        x*=angle;
        if(i%2==1)
        {
            if(i%4==3)
            sinvalue-=x/factorial(i);
            else if(i%4==1)
            sinvalue+=x/factorial(i);
        }
    }
    return sinvalue;
}
double cosine(double angle)
{
    double cosvalue = 1;
    double x = 1;
    long int i;
    for(i=1;i<=30;i++)
    {   
        x*=angle;
        if(i%2==0)
        {
            if(i%4==2)
            cosvalue-=x/factorial(i);
            else if(i%4==0)
            cosvalue+=x/factorial(i);
        }
    }
    return cosvalue;
}
int main()
{
    int choice,choice1,choice2;
    double n1=0.0,n2=0.0;
    do
    {
    
    cout<<"Press 1 for addition."<<endl;
    cout<<"Press 2 for subtraction."<<endl;
    cout<<"Press 3 for muliplication."<<endl;
    cout<<"Press 4 for division."<<endl;
    cout<<"Press 5 for trigonmetric calculations."<<endl;
    cout<<"Press 6 for natural log."<<endl;
    cout<<"Press 7 for square root."<<endl;
    cout<<"Press 8 for finding roots of a quadratic equation."<<endl;
    cout<<"Press 9 to exit."<<endl;
    cin>>choice;
    switch(choice)
    {
       
        
        case 1:     cout<<"Enter two numbers."<<endl;
                    cin>>n1>>n2;
                    cout<<"The sum is "<<(n1+n2)<<endl;
                    break;
        case 2:     cout<<"Enter n1 and n2 for n1-n2"<<endl;
                    cin>>n1>>n2;        
                    cout<<"The difference is "<<(n1-n2)<<endl;
                    break;
        case 3:     cout<<"Enter two numbers."<<endl;
                    cin>>n1>>n2;
                    cout<<"The product is "<<(n1*n2)<<endl;
                    break;
        case 4:     cout<<"Enter n1 and n2 for n1/n2"<<endl;
                    cin>>n1>>n2;
                    if(n2==0)
                        cout<<"Division by zero is not allowed."<<endl;
                    else  
                        cout<<"The quotient is "<<(n1/n2)<<endl;
                    break;
        case 5:    
        {
                    double angle;
                    cout<<"Select the function to perform."<<endl;
                    cout<<"1. Sine"<<endl;
                    cout<<"2. Cosine"<<endl;
                    cout<<"3. Tangent"<<endl;
                    cout<<"4. Cotangent"<<endl;
                    cout<<"5. Cosecant"<<endl;
                    cout<<"6. Secant"<<endl;
                    cin>>choice1;
                    while(choice1>6||choice1<1)
                    {
                        cout<<"INVALID CHOICE.Choose Again.";
                        cin>>choice1;
                    }
                    do{
                    cout<<"For entering in degrees press 1."<<endl<<"For entering in radions press 2."<<endl;
                    cin>>choice2;
                    }while(choice2>2||choice2<1);
                    cout<<"Enter the angle."<<endl;
                    cin>>angle;
                    if(choice2==1)
                    {
                        angle=angle*3.14/180;
                    }
                    while(angle<0)
                    {
                        angle+=6.314;
                    }
                    while(angle>6.314)
                    {
                        angle-=6.314;
                    }
                    switch (choice1)
                    {
                        case 1:     cout<<sine(angle)<<endl;
                                    break;
                        case 2:     cout<<cosine(angle)<<endl;
                                    break;
                        case 3:     if((int)cosine(angle)*1000==0)
                                        cout<<"Sorry.The angle is out of domain of the choosen function."<<endl;
                                    else
                                        cout<<sine(angle)/cosine(angle)<<endl;
                                    break;
                        case 4:     if((int)sine(angle)*1000==0)  // as we cannot get a perfect zero.
                                        cout<<"Sorry.The angle is out of domain of the choosen function."<<endl;
                                    else
                                        cout<<cosine(angle)/sine(angle)<<endl;
                                    break;
                        case 5:     if((int)sine(angle)*1000==0)
                                        cout<<"Sorry.The angle is out of domain of the choosen function."<<endl;
                                    else
                                        cout<<1/sine(angle)<<endl;
                                    break;
                        case 6:     if((int)cosine(angle)*1000==0)
                                        cout<<"Sorry.The angle is out of domain of the choosen function."<<endl;
                                    else
                                        cout<<1/cosine(angle)<<endl;
                                    break;
                        default:    cout<<"INVALID CHOICE."<<endl;
                    }
                    break;
        }
        case 6:     
        {           cout<<"Enter a number"<<endl;
                    cin>>n1;
                    double expo=1,y=0.0000,x;
                    if(n1>1)                           
                    {   
                        while(true)
                        {
                            x=y;
                            for(int i=1;i<=10;i++,x*=y)
                            {
                                expo+= x/factorial(i);   
                            }
                            if(expo>=n1)
                                break;
                            y+=0.0001;
                            expo=1;
                        }
                    }
                    else if(n1>0)
                    {
                        while(true)
                        {
                            x=y;
                            for(int i=1;i<=10;i++,x*=y)
                            {
                                expo+= x/factorial(i);   
                            }
                            if(expo<=n1)
                                break;
                        y-=0.0001;
                        expo=1;
                        }
                    }
                    else if(n1<=0)
                    {
                        cout<<"Negative numbers or Zero is not allowed."<<endl;
                        break;
                    }
                    cout<<"The result is "<<y<<endl;
                    break;
        }
        case 7:     
        {           double i;           
                    cout<<"Enter a positive number."<<endl;
                    cin>>n1;
                    if(n1<0)
                    {
                        cout<<"Cannot find the root of a negative number."<<endl;
                        break;
                    }
                    for(i=0.000000;i*i<n1;i+=0.000001)
                    {
                        ;
                    }
                    cout<<i;
                    break;
        }
        case 8:
        {           
                    double a,b,c;
                    cout<<"Enter the value of a,b and c."<<endl;
                    cin>>a>>b>>c;
                    double d=b*b-4*a*c;
                    if(a==0)
                        cout<<"a cannot be zero for a quadratic equation."<<endl;
                    else if(d>=0)
                    {
                        double i;
                        for(i=0.000000;i*i<d;i+=0.000001)
                        {
                            ;
                        }
                        n1=(-b+i)/2/a;
                        n2=(-b-i)/2/a;
                        cout<<"The roots are "<<n1<<" and "<<n2;
                    }
                    else 
                    {
                        cout<<"The roots are imaginary.";
                    }
                    break;
        }
        case 9:     cout<<"Thanku for using our services.";
                    break;
        default:    cout<<"INVALID CHOICE"<<endl;
        
    }
    }while(choice!=9);
    return 0;

}
