#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int nhapmatranA(int n, float A[100][100])
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("nhap A[%d][%d] = ", i, j);
            cin>> A[i][j];
        }
    }
}
int nhapmatranB(int n, float B[100])
{
    int i;
        for(i=1; i<=n; i++)
        {
            printf("nhap B[%d] = ", i);
            cin>> B[i];
        }
    
}
int xuatmatranA(int n, float A[100][100])
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
        	cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int xuatmatranB(int n, float B[100])
{
    int i;
    for(i=1; i<=n; i++)
    {
        cout<<B[i]<<"\t";
    }
        cout<<"\n";
}

int xuatmatranL(int n, float L[100][100])
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
        	cout<<L[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int xuatmatranX(int n, float X[100])
{
    int i;
    for(i=1; i<=n; i++)
    {
        cout<<X[i]<<"\t";
    }
        cout<<"\n";
}
int xuatmatranY(int n, float Y[100])
{
    int i;
    for(i=1; i<=n; i++)
    {
        cout<<Y[i]<<"\t";
    }
        cout<<"\n";
}
/* kiem tra mang doi xung*/
int doixung(int n, float A[100][100])
{
    int i, j;
    for(i=1; i<=n; i++)
    {          
        for(j=1; j<=n; j++)
        {
            if(A[i][j] !=A[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
// bien doi ma tran khong doi xung ve doi xung
void biendoiMaTran(int n,float A[100][100],float B[100],float M[100][100],float D[100])
{
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) 
		{
			float sum=0;
			if(i==j)
			{
				for(int k=1;k<=n;k++) 
				{
					sum+=A[k][i]*A[k][i];
				}
				M[i][i]=sum;
				
			}
			else
			{
				for(int k=1;k<=n;k++) 
				{
					sum+=A[k][i]*A[k][j];
					M[i][j]=sum;
					M[j][i]=sum;
				}
			}
		}
		
		
	}

	for(int i=1;i<=n;i++)
    {
		float sum1=0;
		for(int j=1;j<=n;j++) 
		{
		sum1+=A[j][i]*B[j];
		
		}
		D[i]=sum1;
	}
// tra ve ma tran da xu ly doi xung
	for(int i=1;i<=n;i++)
	{
		B[i]=D[i];
		for(int j=1;j<=n;j++)
			A[i][j]=M[i][j];
	}
}


int cholesky(int n, float L[100][100], float A[100][100],
float B[100],float X[100],float Y[100])
{
// tim ma tran tam giac
	L[1][1]=sqrt(A[1][1]);
	for(int j=2;j<=n;j++) 
	{
		L[j][1]=A[j][1]/L[1][1];
	}	
	for(int j=2;j<=n-1;j++) 
	{
		for(int k=1;k<=j-1;k++) 
		{ 
			float sum=0;
			sum += L[j][k]*L[j][k];
			L[j][j]=sqrt(A[j][j]-sum);
		}
		for (int i=j+1;i<=n;i++)
		{
			for(int k=1;k<=j-1;k++)
			{
				float sum1=0;
				sum1 +=L[i][k]*L[j][k];
				L[i][j]=(A[i][j]-sum1)/L[j][j];
			}
		}
		
	}
	float sum2=0;
	for(int k=1;k<=n-1;k++)
	{ 
		sum2 +=L[n][k]*L[n][k];
	}
		
	L[n][n]=sqrt(A[n][n]-sum2);
		
	for(int i=1;i<=n;i++) 
	{
		if(L[i][i]==0)
		{ 
			cout<<"\nMa tran suy bien";
			exit(0);
		}
	}		

// tim Y
	Y[1]=B[1]/L[1][1];
	for (int i=2;i<=n;i++)
	{   
		float sum3=0;
		for(int j=1;j<=i-1;j++) 
		{
			
			sum3 +=L[i][j]*Y[j];
			Y[i]=(B[i]-sum3)/L[i][i];
		}
	
	}
// tim X
	X[n]=Y[n]/L[n][n];
	for(int i=n-1;i>=1;i--)
	{
		float sum4 =0;
		for(int j=n;j>=i+1;j--)
		{
			sum4 +=L[j][i]*X[j];
			X[i]=(Y[i]-sum4)/L[i][i];
		}
	}

}
  int main()
{
    int n,a; float A[100][100] ,L[100][100],X[100],B[100],Y[100],M[100][100],D[100];
    cout<<"nhap ma tran cap:\n";
    cin>>n;
    nhapmatranA(n, A);
    nhapmatranB(n,B);   
    if(doixung(n, A)==0)
    {
        printf("ma tran A vua nhap khong doi xung\n");
        biendoiMaTran(n,A,B,M,D);
        cout<<"Ma tran A sau bien doi:\n";
        xuatmatranA(n,A);
        cout<<"Ma tran B sau bien doi:\n";
        xuatmatranB(n,B) ;
        
       
        
    }
    else
    {
        printf("ma tran A vua nhap doi xung\n");
    }
  
    cout<<"Ma tran L:\n";
    cholesky(n,L,A,B,X,Y);
    xuatmatranL(n,L);
    cout<<"Ket qua Y:\n";
    xuatmatranY(n,Y);
    cout<<"Ket qua X:\n";
    xuatmatranX(n,X);
    return 0;
}
