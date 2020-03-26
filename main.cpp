#include <iostream>

#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

using namespace std;

void count(int **p[]){
    int *count[MAX_NUM_INTVAR];
    int i=0, con=0, o[MAX_NUM_PTR][2]= {0};
    int valorMin, repMin;


    //Primero ver todas los pointers de las 3º capa
    while(p[i] != nullptr) {
        //se asigna una copia de la dirreccion
        count[con]= *p[i];
        //loop para checkear que esa dirrección es unica o se repite
        for (int j = 0; j < con+1; ++j) {
            if(*p[i] == count[j]){++con; o[j][0]= **p[i]; ++o[j][1]; break;}
        }
        ++i;
    }

    for (int m = 0; m <  con; ++m) {
        valorMin= o[m][0];
        //Hallar el valorMIN
        for (int l = m; l < con; ++l) {
            if (o[l][0] <= valorMin) {
                valorMin = o[l][0];
                repMin = o[l][1];
                o[l][0] = o[m][0];
                o[l][1] = o[m][1];
                o[m][0] = valorMin;
                o[m][1] = repMin;
            }
        }
    }
    for (int k = 0; k < con ; ++k) {
        if (o[k][0] == 0){
            continue;
        }else{
            cout << "\n" << o[k][0] << " " << o[k][1];
        }
    }
    cout << "\n";

    for (int m = 0; m <  con; ++m) {
        repMin= o[m][1];
        //Hallar el valorMIN
        for (int l = m; l < con; ++l) {
            if (o[l][1] < repMin) {
                repMin = o[l][1];
                valorMin = o[l][0];
                o[l][1] = o[m][1];
                o[l][0] = o[m][0];
                o[m][1] = repMin;
                o[m][0] = valorMin;
            }
        }
    }

    //Despues de hacer el sort de o[j][0] y o[j][1]
    for (int k = 0; k < con ; ++k) {
        if (o[k][0] == 0){
            continue;
        }else{
        cout << "\n" << o[k][0] << " " << o[k][1];
        }
    }
}

int main(){
    int **ptrArray[MAX_SIZE_PTRARRAY] = {};
    int  *intPtr[MAX_NUM_PTR];
    int   intVar[MAX_NUM_INTVAR];

    int sizeArray,sizePtr, sizeVar;
    int digit;
    std::cin >> sizeArray;
    std::cin >> sizePtr;
    std::cin >> sizeVar;

    ptrArray[sizeArray]= nullptr;
    for (int i = 0; i < sizeArray ; ++i) {
        cin >> digit;
        ptrArray[i] = &intPtr[digit];
    }
    for (int j = 0; j < sizePtr ; ++j) {
        cin >> digit;
        intPtr[j] = &intVar[digit];
    }
    for (int k = 0; k < sizeVar; ++k) {
        cin >> digit;
        intVar[k] = digit;
    }

    count(ptrArray);

    return 0;
}