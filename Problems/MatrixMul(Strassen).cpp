#include<iostream>
using namespace std;

void addmatrix(int **a,int **b,int **c,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];
    }
}

void submatrix(int **a,int **b,int **c,int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j]-b[i][j];
    }
}

void strassen(int** a,int** b,int** c,int n){
    if(n==1){
        c[0][0]=a[0][0]*b[0][0];
        return;
    }

    int size=n/2;
    int **A11,**A12,**A21,**A22;
    int **B11,**B12,**B21,**B22;
    int **C11,**C12,**C21,**C22;
    int **temp1,**temp2;
    int **M1,**M2,**M3,**M4,**M5,**M6,**M7;

    A11=(int**)malloc(size*sizeof(int*));
    A12=(int**)malloc(size*sizeof(int*));
    A21=(int**)malloc(size*sizeof(int*));
    A22=(int**)malloc(size*sizeof(int*));

    B11=(int**)malloc(size*sizeof(int*));
    B12=(int**)malloc(size*sizeof(int*));
    B21=(int**)malloc(size*sizeof(int*));
    B22=(int**)malloc(size*sizeof(int*));

    C11=(int**)malloc(size*sizeof(int*));
    C12=(int**)malloc(size*sizeof(int*));
    C21=(int**)malloc(size*sizeof(int*));
    C22=(int**)malloc(size*sizeof(int*));

    temp1=(int**)malloc(size*sizeof(int*));
    temp2=(int**)malloc(size*sizeof(int*));

    M1=(int**)malloc(size*sizeof(int*));
    M2=(int**)malloc(size*sizeof(int*));
    M3=(int**)malloc(size*sizeof(int*));
    M4=(int**)malloc(size*sizeof(int*));
    M5=(int**)malloc(size*sizeof(int*));
    M6=(int**)malloc(size*sizeof(int*));
    M7=(int**)malloc(size*sizeof(int*));

    for(int i=0;i<size;i++){
        A11[i]=(int*)malloc(size*sizeof(int));
        A12[i]=(int*)malloc(size*sizeof(int));
        A21[i]=(int*)malloc(size*sizeof(int));
        A22[i]=(int*)malloc(size*sizeof(int));

        B11[i]=(int*)malloc(size*sizeof(int));
        B12[i]=(int*)malloc(size*sizeof(int));
        B21[i]=(int*)malloc(size*sizeof(int));
        B22[i]=(int*)malloc(size*sizeof(int));

        C11[i]=(int*)malloc(size*sizeof(int));
        C12[i]=(int*)malloc(size*sizeof(int));
        C21[i]=(int*)malloc(size*sizeof(int));
        C22[i]=(int*)malloc(size*sizeof(int));

        temp1[i]=(int*)malloc(size*sizeof(int));
        temp2[i]=(int*)malloc(size*sizeof(int));

        M1[i]=(int*)malloc(size*sizeof(int));
        M2[i]=(int*)malloc(size*sizeof(int));
        M3[i]=(int*)malloc(size*sizeof(int));
        M4[i]=(int*)malloc(size*sizeof(int));
        M5[i]=(int*)malloc(size*sizeof(int));
        M6[i]=(int*)malloc(size*sizeof(int));
        M7[i]=(int*)malloc(size*sizeof(int));

    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){

            A11[i][j]=a[i][j];
            A12[i][j]=a[i][j+size];
            A21[i][j]=a[i+size][j];
            A22[i][j]=a[i+size][j+size];

            B11[i][j]=b[i][j];
            B12[i][j]=b[i][j+size];
            B21[i][j]=b[i+size][j];
            B22[i][j]=b[i+size][j+size];

        }
    }

    addmatrix(A11,A22,temp1,size);
    addmatrix(B11,B22,temp2,size);
    strassen(temp1,temp2,M1,size);

    addmatrix(A21,A22,temp1,size);
    strassen(temp1,B11,M2,size);

    submatrix(B12,B22,temp1,size);
    strassen(A11,temp1,M3,size);

    submatrix(B21,B11,temp1,size);
    strassen(A22,temp1,M4,size);

    addmatrix(A11,A12,temp1,size);
    strassen(temp1,B22,M5,size);

    submatrix(A21,A11,temp1,size);
    addmatrix(B11,B12,temp2,size);
    strassen(temp1,temp2,M6,size);

    submatrix(A12,A22,temp1,size);
    addmatrix(B21,B22,temp2,size);
    strassen(temp1,temp2,M7,size);

    addmatrix(M1,M4,temp1,size);
    submatrix(M7,M5,temp2,size);
    addmatrix(temp1,temp2,C11,size);

    addmatrix(M3,M5,C12,size);

    addmatrix(M2,M4,C21,size);

    submatrix(M1,M2,temp1,size);
    addmatrix(M3,M6,temp2,size);
    addmatrix(temp1,temp2,C22,size);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            c[i][j]=C11[i][j];
            c[i][j+size]=C12[i][j];
            c[i+size][j]=C21[i][j];
            c[i+size][j+size]=C22[i][j];
        }
    }

    // free all allocated matrices
    for(int i=0;i<size;i++){
    free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
    free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
    free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);

    free(temp1[i]);
    free(temp2[i]);

    free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
    free(M5[i]); free(M6[i]); free(M7[i]);
    }

    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(C11); free(C12); free(C21); free(C22);

    free(temp1);
    free(temp2);

    free(M1); free(M2); free(M3); free(M4);
    free(M5); free(M6); free(M7);

}

int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    if(n<=0 || (n&(n-1))!=0){
        cout<<"only for 2 pow n size of matrix";
        return 0;            
    }

    int **a,**b,**c;
    a=(int**)malloc(n*sizeof(int*));
    b=(int**)malloc(n*sizeof(int*));
    c=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        a[i]=(int*)malloc(n*sizeof(int));
        b[i]=(int*)malloc(n*sizeof(int));
        c[i]=(int*)malloc(n*sizeof(int));
    }

    cout<<"Enter elements of matrix A one by one:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }

    cout<<"Enter elements of matrix B one by one:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    }

    strassen(a,b,c,n);
    cout<<"RESULTANT MATRIX:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }

}