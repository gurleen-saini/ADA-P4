#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
float knabsackprice(int** mat,int rows,int cols,int maxweight)
{
    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(mat[0][k]<mat[0][j])
            {
                j=k;
            }
        }
        int t=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=t;
        int tn=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=tn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=4;i>=0;i--)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i>=0)
    {
        x[i] =  float (maxweight)/(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=mat[0][i]*x[i];
    }

    return sum;
}

float knabsackweight(int** mat,int rows,int cols,int maxweight)
{
    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(mat[1][k]<mat[1][j])
            {
                j=k;
            }
        }
        int t=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=t;
        int tn=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=tn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=0;i<5;i++)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i<5)
    {
        x[i] =  maxweight/float(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=float (mat[0][i])*float(x[i]);
    }

    return sum;
}

float knabsackweightprice(int** mat,int rows,int cols,int maxweight)
{
    float h[5];
    for(int p=0;p<5;p++)
    {
        h[p]=float (mat[0][p])/mat[1][p];
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<h[i]<<" ";
    // }
    // cout<<endl;

    int j;
    for(int i=0;i<5;i++)
    {
        j=i;
        for(int k=i+1;k<5;k++)
        {
            if(h[k]<h[j])
            {
                j=k;
            }
        }
        int t=h[i];
        h[i]=h[j];
        h[j]=t;
        int tn=mat[1][i];
        mat[1][i]=mat[1][j];
        mat[1][j]=tn;
        int tnn=mat[0][i];
        mat[0][i]=mat[0][j];
        mat[0][j]=tnn;
    }

    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    float x[5]={0};
    int i;
    for(i=4;i>=0;i--)
    {
        if(mat[1][i]<=maxweight && maxweight>0)
        {
            maxweight-=mat[1][i];
            x[i]=1;
        }
        else
        {
            break;
        }
    }

    if(i>=0)
    {
        x[i] =  float (maxweight)/(mat[1][i]);
    }

    // for(int i=0;i<5;i++)
    // {
    //     cout<<x[i]<<" ";
    // }

    float sum=0.0;

    for(i=0;i<5;i++)
    {
        sum+=mat[0][i]*x[i];
    }

    return sum;

}

int main()
{
    // int i=0;
    // int maxweight=10;

    // while(i<3)
    // {
    //     int mat[2][5]={{5,8,10,6,7},{2,3,4,3,2}};
    //     if(i==0)
    //     {
    //         float pp = knabsackprice(mat,2,5,10);
    //         cout<<endl<<"Profit = "<<pp<<endl;
    //     }
    //     if(i==1)
    //     {
    //         float wp = knabsackweight(mat,2,5,10);
    //         cout<<endl<<"Weight = "<<wp<<endl;
    //     }
    //     if(i==2)
    //     {
    //         float wpp = knabsackweightprice(mat,2,5,10);
    //         cout<<endl<<"Profit by weight = "<<wpp<<endl;
    //     }
    //     i++;
    // }

    
    float A;
    for(int j=1000;j<=100000;j=j+1000)
    {
        int** a = new int*[2];
        int** mat = new int*[2];

        for(int i = 0; i < 2; i++) {
            a[i] = new int[j];
            mat[i] = new int[j];
        }

        for(int k=0;k<j;k++)
        {
            a[0][k]=rand();
            a[1][k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            
            int i=0;
            int maxweight=10;

            while(i<3)
            {
                for(int i = 0; i < 2; i++) {
                    for(int m = 0; m < j; m++) {
                        mat[i][m] = a[i][m];
                    }
                }

                if(i==0)
                {
                    float pp = knabsackprice(mat,2,j,maxweight);
                    // cout<<endl<<"Profit = "<<pp<<endl;
                }
                if(i==1)
                {
                    float wp = knabsackweight(mat,2,j,maxweight);
                    // cout<<endl<<"Weight = "<<wp<<endl;
                }
                if(i==2)
                {
                    float wpp = knabsackweightprice(mat,2,j,maxweight);
                    // cout<<endl<<"Profit by weight = "<<wpp<<endl;
                }
                i++;
            }

        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";

        for(int i = 0; i < 2; i++) {
            delete[] a[i];
            delete[] mat[i];
        }
        delete[] a;
        delete[] mat;
    }
}
