//Конструктор, операторы "+" и "+="

#include <iostream>

using namespace std;

 struct CompIntegers{
int num, length;
int* primes;

CompIntegers(int a=2):num(a),length(0){
    primes=new int[100];
    primes[0]=1;
    while(a!=1){
    for(int i=2; i<=a; i++){
        if(a%i==0){
            a/=i;
            length++;
            primes[length]=i;
            i--;
        }
    }
    }
}
~CompIntegers()
	{
		delete[] primes;
	}

CompIntegers& operator *= (int n)
	{
	while(n != 1){
for (int i = 2; i <= n; i++){
if (n%i==0){
n/=i;
    length++;
        primes[length]=i;
        i=2;
}
}
}
		return *this;
	}
};


	CompIntegers& operator * (CompIntegers& A, int B)
	{
	    CompIntegers Temp;
	    for(int j=1; j<A.length; j++){
            Temp.primes[Temp.length]=A.primes[A.length];
	    }
	while(B != 1){
for (int i = 2; i <= B; i++){
if (B%i==0){
B/=i;
    Temp.length++;
        Temp.primes[Temp.length]=i;
        i--;
}
}
}
		return A;
	}

ostream& operator<< (ostream &out, const CompIntegers &primes)
{ for(int i=1; i<=primes.length; i++){
	out << primes.primes[i] <<" ";
}
	return out;
}

int main()
{
    int q;
cin >> q;
struct CompIntegers b(q);
b*=10;
cout << "1)operator*= " << b << endl;
struct CompIntegers c(q);
c = b*8;
cout << "2)operator* " << c << endl;
    return 0;
}
