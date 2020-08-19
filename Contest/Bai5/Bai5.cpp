#include<iostream>

using namespace std;

int n;
int a[100];
int k;

void init();
void xuatch();
bool kiemtra();
void sinh();


int main()
{
    int test;
    cin>>test;
	while(test > 0) {
    cin>>n;
	cin>>k;
	init();
	while(kiemtra()==false)
	{
		xuatch();
		sinh();
	}
	xuatch();
	cout << endl;
    test--;
	}
}
void init()
{
	for(int i=1;i<k+1;i++)
	{
		a[i]=i;
	}
}
void xuatch()
{
	for(int i=1;i<k+1;i++)
	{
		cout<<a[i];
	}
	cout<<" ";
}
bool kiemtra()
{
	int tt=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i] != n-k+i)
		return false;
	}
	return true;
}
void sinh()
{
	int i=k;
	while( i>0 && a[i]==n-k+i) i--;
	if(i>0)
	{
		a[i]++;
		for(int j=i+1;j<k+1;j++)
		a[j]=a[j-1]+1;
	}
}


