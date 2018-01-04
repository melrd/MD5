#include "convertir.h"
#include <iostream>
#include<vector>
//#include<math>

using namespace std;

vector<bool> bitFromInt(int number){
    vector<bool> result;
    vector<bool> temp;
    int q, r;
    while(q != 0){
        q = number / 2;
        r = number % 2;
        result.push_back(r);
        number = q;

    }
    for (int i = 0; i < result.size(); i++){
        temp.push_back(result[result.size()-i-1]);
    }
    return temp;
}
int intFromBit(char *block, long blocksize){
    int result=0;

    for(int i=0;i<blocksize;i++)
        result = (2*result+block[i]);

    return result;
}

int hexaFromBit(char* block, int blocksize){

    int result = intFromBit(block, blocksize);
    std::cout << "Voici ce nombre en hexadecimal: "<< std::hex << result << std::endl;

    return result;
}
/*bitFromHexa(char *block){


    bitFromInt();
}*/

char *complement(char*block, int blocksize){

    char *result = new char[blocksize];
    for(int i = 0; i < blocksize; i++){
        if(block[i] == 0)
            result[i] = 1;
        else
            result[i] = 0;
    }

    return result;
}

void initialisation(){

    string message ("Wikipedia, l'encyclopedie libre et gratuite");

    vector <int> asciiMessage;
    vector <bool> binMessage;
    vector <bool> temp2;

///PASSER DE ASCII EN BINAIRE
    for(int i = 0; i < message.size(); i++){
        asciiMessage.push_back((int)message[i]);
        vector <bool> temp;
        temp = bitFromInt(i);
        for(int j = 0; j < temp.size(); j++){
             binMessage.push_back(temp[j]); ///+ verifier que chaque bit soit dans une case !!!
        }

    }
displayVector(binMessage);
    int length = binMessage.size();

///AJOUT DU 1 ET DES 0
    binMessage.push_back(1);
    while((binMessage.size()%512)!=(448%512)){
        binMessage.push_back(0);
    }

    ///Verifier que la taille du mot
    if (length <0)
        cout<<"hello";
        ///alors seulement les 64 bits de poids faible de b sont utilisés. (Ces bits sont ajoutés comme deux Mots de 32 bits et mot de poids faible ajouté en premier conformément à conventions précédentes.)

    /// on met length en binaire et on ajoute des 0 pour que ca soit sur 64bits
    /// oublie petit boutiste (little endian)
    else{
        temp2 = bitFromInt(length);
        int length2 = temp2.size();

        while(temp2.size()!=64){
            temp2.push_back(0);
            binMessage.push_back(0);

            }
        for(int j = 0; j < length2; j++){
             binMessage.push_back(temp2[j]);

        }
    }

    displayVector(binMessage);
}

void displayVector(vector<bool> a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i];

    cout << endl;
}


/*void hashage(vector<bool> p){

    int taille = p.size()/512;
    unsigned int f, a, b, c, d, g;
///decoupage par bloc de 512
for(int j = 0; j < taille; j++){

    int w[16];

    ///decoupage en 16 mots de 32 bits
    for(int i = 0; i < 16; i++){
        for(int u = 0; u < 512; u++){

        }



            a = h[0];
            b = h[1];
            c = h[2];
            d = h[3];

            for (int i = 0; i < 64; i++){
                if (0 <= i && i <= 15){
                    f = fFunction(b, c, d);
                    g = i;
                }
                else if (16 <= i && i <= 31){
                    f = bFunction(b, c, d);
                    g = (5 * i + 1)%16;
                }
                else if (32 <= i && i <= 47){
                    f = hFunction(b, c, d);
                    g = (3 * i + 5)%16;
                }
                else {
                    f = iFunction(b, c, d);
                    g = (7 * i)%16;
                }

                int temp = d;
                d = c;
                c = b;
               // b = ((a + f + k[i] + w[g])    r[i]) + b;/// leftrotate
                a = temp;
            }
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
}
}

int fFunction(int b, int c, int d){
    return ((b&c)|(~b&d));
}
int gFonction(int b, int c, int d){
    return((b&d)|(~d&c));
}
int hFunction(int b, int c, int d){
    return (b^c^d);
}
int iFunction(int b, int c, int d){
    return (c^(~d|b));
}

int concatenate(){}
int leftrotate(){}*/

