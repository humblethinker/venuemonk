#include <iostream>
using namespace std;

int main() {
	int sum = 1000;
    int a;
    for (a = 1; a <= sum/3; a++)
    {
        int b;
        for (b = a + 1; b <= sum/2; b++) 
        /* Since a and b are interchangeable and a=/=b (that will imply 2*a^2=c^2, which is not possible
        integers), we assume b>a, also since a<b<c, a will have maximum value under sum/3 similarly
        b will have value under sum/2*/
        {
            int c=sum-a-b;
            if (a*a+b*b==c*c)
            {
            cout<<"The required answer is : "<<a*b*c;
            break;
            }
        }
    }
    return 0;
}