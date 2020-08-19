#include<iostream>

using namespace std;

int n;
int a[100];

void init();
bool kiemtra();
void xuatch();
void sinh();

int main()
{
    int test;
    cin>>test;
    while(test > 0) {
	cin>>n;
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
	for(int i=1;i<=n;i++)
		a[i]=i;
}

bool kiemtra()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1]) return false;
	}
	return true;
}


void xuatch()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<" ";
}

void sinh()
{
	int i=n, temp;
	while(i>0 && a[i-1]>a[i]) i--;
	if(i>0)
	{
		int k=n;
		while(a[i-1]>a[k]) k--;
		temp=a[i-1];
		a[i-1]=a[k];
		a[k]=temp;
		int r=i, s=n;
		while(r<s)
		{
			temp=a[r];
			a[r]=a[s];
			a[s]=temp;
			r++;
			s--;
		}
	}
}
