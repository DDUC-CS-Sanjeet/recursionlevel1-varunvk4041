#include<iostream>
using namespace std;
int fiboi(int num)
{
	int term1=0,term2=1,temp=0,k=1;
	if(num>0)
	{
		if(num==1)
		cout<<term1;
		else if(num==2)
		cout<<term1<<" "<<term2;
		else
		{
			cout<<term1<<" "<<term2;
			while(k<=num-2)
			{
				temp=term1+term2;
				term1=term2;
				term2=temp;
				k++;
				cout<<" "<<temp;
			}
		}
	}
	else
	{
		cout<<"\nERROR ! Number of terms can't be less than or equal to 0\n";	
	}
}
int powi( int num1, int num2)
{
	int power=1;
	for(int i=1;i<=num2;i++)
	power*=num1;
	return power;
}
int facti(int num)
{
	int fact=1;
	for(;num>0;num--)
	fact*=num;
	return fact;
}
int gcdi( int num1, int num2)
{
	int temp=0;
	while(num2!=0)
	{
		temp=num1;
		num1=num2;
		num2=temp%num1;
	}
	return num1;
}
int factr(int num)
{
	if(num==0)
	return 1;
	else
	{
		return num*factr(num-1);
	}
}
int gcdr( int num1, int num2)
{
		if(num2==0)
		return num1;
		
		else if( num1<0 || num2<0 )
		{
			throw "\nInvalid arguements!";
		}
		else
		{
			return gcdr(num2,num1%num2);
		}
}
int powr( int temp, int num1, int num2)
{
	if(num2==1)
	return temp;
	else
	{
		return powr(temp*num1,num1,num2-1);
	}
}
int fibor( int term, int temp, int num )
{
	if( num == 0 || num < 0)
	{
		return 0;
	}
	else
	{
		cout<<" "<<term;
		return fibor( term + temp, term, num-1);
	}
}
int main()
{
	int choice,num1,num2,num3,num4,num5,num6;
	char ans;
	do
	{
		cout<<"\n_________________________________MENU_____________________________________\n";
		cout<<"\n\n1.Euclid's algorithm for gcd of two numbers num1 and num2";
		cout<<"\n\n2.Factorial of a number num3";
		cout<<"\n\n3.A number num4 raised to power another number num5";
		cout<<"\n\n4.First num6 terms of Fibonacci sequence.";
		cout<<"\n\nEnter your choice (1-4)";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter two numbers (num1 and num2) ";
					cin>>num1>>num2;
					cout<<"\n1. via Iteration";
					cout<<"\n2. via Recursion";
					cout<<"\nEnter your choice(1-2)";
					cin>>choice;
					switch(choice)
					{
						case 1: cout<<"\nGCD of "<<num1<<" and "<<num2<<" = "<<gcdi(num1,num2);
								break;
						case 2: try
								{
								cout<<"\nGCD of "<<num1<<" and "<<num2<<" = "<<gcdr(num1,num2);
								}
								catch(string str)
								{
									cout<<str;
								}
								break;
						default: cout<<"\nINVALID choice";
					}
					break;
			case 2: cout<<"\nEnter number (num3)";
					cin>>num3;
					cout<<"\n1. via Iteration";
					cout<<"\n2. via Recursion";
					cout<<"\nEnter your choice(1-2)";
					cin>>choice;
					switch(choice)
					{
						case 1: cout<<"\nFactorial of "<<num3<<" = "<<facti(num3);
								break;
						case 2: cout<<"\nFactorial of "<<num3<<" = "<<factr(num3);
								break;
						default: cout<<"\nINVALID choice";
					}
					break;
			case 3: cout<<"\nEnter two numbers (num4 and num5)";
					cin>>num4>>num5;
                    cout<<"\n1. via Iteration";
					cout<<"\n2. via Recursion";
					cout<<"\nEnter your choice(1-2)";
					cin>>choice;
					switch(choice)
                    {
                        case 1: cout<<endl<<num4<<" to the power "<<num5<<" = "<<powi(num4,num5);
                                break;
                        case 2: cout<<endl<<num4<<" to the power "<<num5<<" = "<<powr(num4,num4,num5);
					            break;
                    }
					break;
			case 4: cout<<"\nEnter number (num6)";
					cin>>num6;
                    cout<<"\n1. via Iteration";
					cout<<"\n2. via Recursion";
					cout<<"\nEnter your choice(1-2)";
					cin>>choice;
					switch(choice)
                    {
                        case 1: cout<<endl;
								fiboi(num6);
                                break;
                        case 2: cout<<endl;
								fibor(0,1,num6);
                                break;
                        default: cout<<"\nINVALID choice";
                    }
					break;
			default: cout<<"\nINVALID choice!";
		}
			cout<<"\nDo you wish to continue?(y/n): ";
			cin>>ans;
			if(ans=='n')
			cout<<"\n____________________PROGRAM ENDED___________________";	
	}while(ans == 'y');
	return 0;
}