#include <iostream>
using namespace std;
int main() {
	int L,R;
	cin>>L>> R;
	int result=0;
	for(int i=L;i<=R;i++)
	{
		result=result^i;	
	}
	if(result%2==0)
	cout<<"even";
	else
	cout<<"odd";
	return 0;
}