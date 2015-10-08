#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main()
{

    pid_t pid; // data type for represent process id
    pid= fork();
    cout << "Pid pos chamada do fork: "<< pid<<endl;
    if(pid<0){  // sinalize fork errors
        perror("fork");
        exit(1);
    }
    if(pid==0){
        cout << "   ===Inicio processo filho==="<<endl;
        cout << "   Pid filho dentro do filho: "<< pid<<endl;
        cout << "   Getpid filho: "<< getpid()<<endl;
        int num;
        cout << "   Digite numero da sequencia de fibonacci:" << endl;
        cin>> num;
        while(num<=-1){
            cout << "Digite numero >=0 da sequencia de fibonacci:" << endl;
            cin>> num;
        }

        cout<< "   Sequencia de fibonaci: "; // para exibir sequencia descomentar aqui <<<<=====
        BigInteger fibo=1, aux1=1, aux2=0;
        cout<< fibo; // para exibir sequencia descomentar aqui <<<<=====
        for(BigInteger x=2; x<=num; x++){
            fibo=aux1+aux2;
            cout<< ", "<<fibo; // para exibir sequencia descomentar aqui <<<<=====
            aux2=aux1;
            aux1=fibo;
        }
       cout<<endl;
       cout<<"   Fibonaccci("<<num<<"): "<<fibo<<endl;
       cout << "   ===  Fim processo filho  ==="<<endl;
       return 0;
    }

   if (pid>0){
        cout << "======Inicio processo Pai======"<<endl;
        cout << "Pid filho dentro do pai: "<< pid<<endl;
        cout << "Getpid pai: "<< getpid()<<endl;
        cout << "Pai espera filho"<<endl;
        wait(NULL);
        cout << "Filho acabou, pai continua"<<endl;
        cout << "====== Fim processo pai  ======"<<endl;
    }

    return 0;

}
