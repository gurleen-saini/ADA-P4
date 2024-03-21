// #include<iostream>
// #include<cstdlib>
// #include<ctime>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// int endtime(float **mat,int rows,int cols,int start,int end)
// {
//     int jobs;
//     int selected=0;
//     if(mat[0][0]<end)
//     {
//         jobs=1;
//     }
//     else if(mat[0][0]>end)
//     {
//         return 0;
//     }

//     for(int j=1;j<5;j++)
//     {
//         if(mat[1][selected]>end)
//         {
//             return jobs;
//         }
//         else if(mat[1][selected]<=mat[0][j])
//         {
//             // cout<<selected+1<<endl;
//             selected=j;
//             jobs++;
//         }
//     }
//     // cout<<selected+1<<endl;
//     return jobs;
// }

// int main()
// {
//     float start=9;
//     float end=17;

//     // cout<<"Selected Jobs "<<endl;
//     // float mat[2][5]={{10,10.5,11,12,13},{11,12,12,13,14}};
//     // cout<<"Total Jobs = "<<endtime(mat,2,5,start,end)<<endl;



//     float A;
//     for(int j=1000;j<=100000;j=j+1000)
//     {
//         float** a = new float*[2];

//         for(int k=0;k<j;k++)
//         {
//             a[0][k]=rand();
//             a[1][k]=rand();
//         }
                
                
//         sort(a[0],a[0]+j);
//         sort(a[1],a[1]+j);
//         clock_t t1=clock();
//         for(int l=0;l<10;l++)
//         {
//             endtime(a,2,j,start,end);
//         }
//         clock_t t2=clock();
//         A=(float)(t2-t1)/10;
//         cout<<A<<",";
//     }
// }

// // float mat[2][5]={{10,10.5,11,12,12.5},{11,12,12.5,13,14}};



#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int endtime(float **mat, int rows, int cols, float start, float end) {
    int jobs = 0;
    for (int j = 0; j < cols; j++) {
        if (mat[0][j] >= start && mat[1][j] <= end) {
            jobs++;
        }
    }
    return jobs;
}

int main() {
    float start = 9.0;
    float end = 17.0;

    float A;
    for (int j = 1000; j <= 100000; j += 1000) {
        float** a = new float*[2];
        for (int i = 0; i < 2; i++) {
            a[i] = new float[j];
            for (int k = 0; k < j; k++) {
                // Generate random floating-point numbers between start and end
                a[i][k] = start + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(end-start)));
            }
        }

        clock_t t1 = clock();
        for (int l = 0; l < 10; l++) {
            endtime(a, 2, j, start, end);
        }
        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A << ",";
        
        // Free dynamically allocated memory
        for (int i = 0; i < 2; i++) {
            delete[] a[i];
        }
        delete[] a;
    }
}
