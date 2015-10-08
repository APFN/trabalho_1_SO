#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;
// Set the matrix dimensions
// Remembering that: A_row == B_col
#define A_col 3
#define A_row 3
#define B_col 3
#define B_row 3


int matrix_A [A_row][A_col];//input
int matrix_B [B_row][B_col];//input
int matrix_C [A_row][B_col];//output


struct Shared_data{ // data struct for coordinates
    int i; // roll
    int j; //col
};

void *get_matrix_C(void  *coor){  //receives coordinates for C calculus

    struct Shared_data *posi= (struct Shared_data*)coor;
    int result=0;
    for(int i=0;i<A_col;i++){
        result +=matrix_A[posi->i][i]*matrix_B[i][posi->j];  // multiples A_rows with B_col
    }
    matrix_C[posi->i][posi->j]= result; // the result go to these coordinates of C
    pthread_exit(0); //thread return
}

int main()
{
    //receives and alocate matrix A
    cout << "Diginete matriz A" << endl;
    for(int i=0;i<A_row;i++){
        for(int j=0;j<A_col;j++){
            cin>>matrix_A[i][j];
        }
    }
    cout << "{"<<endl;
    for(int i=0;i<A_row;i++){
        cout << " {";
        for(int j=0;j<A_col;j++){
            cout <<matrix_A[i][j];
            cout << ",";
        }
        cout << "}"<<endl;
    }
    cout << "}"<<endl;
    char ok;
    cout << "ok? (y or n)"<<endl;
    cin>>ok;
    if(ok=='n'){
        while(ok=='n'){
            cout << "Diginete matriz " << endl;
            for(int i=0;i<A_row;i++){
                for(int j=0;j<A_col;j++){
                    cin>>matrix_A[i][j];
                }
            }
            cout << "{"<<endl;
            for(int i=0;i<A_row;i++){
                cout << " {";
                for(int j=0;j<A_col;j++){
                    cout <<matrix_A[i][j];
                    cout << ",";
                }
                cout << "}"<<endl;
            }
            cout << "}"<<endl;
            cout << "ok? (y or n)"<<endl;
            cin>>ok;
        }
    }
    //receives and alocate matrix B
    cout << "Diginete matriz B" << endl;
    for(int i=0;i<B_row;i++){
        for(int j=0;j<B_col;j++){
            cin>>matrix_B[i][j];
        }
    }
    cout << "{"<<endl;
    for(int i=0;i<B_row;i++){
        cout << " {";
        for(int j=0;j<B_col;j++){
            cout <<matrix_B[i][j];
            cout << ",";
        }
        cout << "}"<<endl;
    }
    cout << "}"<<endl;
    cout << "ok? (y or n)"<<endl;
    cin>>ok;
    if(ok=='n'){
        while(ok=='n'){
            cout << "Diginete matriz " << endl;
            for(int i=0;i<B_row;i++){
                for(int j=0;j<B_col;j++){
                    cin>>matrix_B[i][j];
                }
            }
            cout << "{"<<endl;
            for(int i=0;i<B_row;i++){
                cout << " {";
                for(int j=0;j<B_col;j++){
                    cout <<matrix_B[i][j];
                    cout << ",";
                }
                cout << "}"<<endl;
            }
            cout << "}"<<endl;
            cout << "ok? (y or n)"<<endl;
            cin>>ok;
        }
    }
    //with A and B received , its created A_row*B_col threads
    for(int x = 0; x < A_row; x++) {
          for(int y = 0; y < B_col; y++) {
             struct Shared_data *posi = (struct Shared_data *) malloc(sizeof(struct Shared_data)); // alocate memory for positions
             posi->i = x;
             posi->j = y;
             pthread_t tid;       // create a thread id
             pthread_attr_t attr;   // thread attributes
             // create the thread passing the fuction that  this
             pthread_attr_init(&attr); // get deafult attributes
             pthread_create(&tid,&attr,get_matrix_C,posi); //creates the thread by passing a function and the argument of this function
             pthread_join(tid, NULL); // wait thread finish
          }
       }
    // Imprime matriz C dpeois da multiplicaçao
    cout << "AxB = :  "<<endl;
    cout << "{"<<endl;
    for(int i=0;i<B_row;i++){
        cout << " {";
        for(int j=0;j<B_col;j++){
            cout <<matrix_C[i][j];
            cout << ",";
        }
        cout << "}"<<endl;
    }
    cout << "}"<<endl;

    return 0;
}

