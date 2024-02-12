#include <iostream> 
using namespace std;

class matrix{

    public:
        
        int depth = 0; 
        int valueMatrix;
        int **numbers; 
        int ***matrixAccess; 
        string *stringMatrix;

        matrix(int quantity){

            valueMatrix = quantity;
            matrixAccess = new int**[4]; //change value in this pointer
            stringMatrix = new string[4];

            matrixAccess[depth] = calculusInitial();
            depth++; 

        }

        ~matrix(){
            try{
                for(int i = 0; i < valueMatrix; i++){
                    delete [] numbers[i];
                }
                delete [] numbers;
                delete[] stringMatrix;

            }catch(exception& error){
                string messageError = error.what();
                cerr << "Error: " << messageError << endl; 
            }
        }

        void showMatrixAll(int valueInput){
            try{
                cout << "\nMatrix - long access (" << (valueInput + 1) << "):\n\n" << stringMatrix[valueInput] << endl;
            }catch(exception& error){
                string messageError = error.what();
                cerr << "Error: " << messageError << endl;
            }
        }

        int **calculusInitial(){

            numbers = new int*[valueMatrix];
            int valueInput; 

            for(int i = 0; i < valueMatrix; i++){
                numbers[i] = new int[valueMatrix]; 
                for(int j = 0; j < valueMatrix; j++){
                    cin >> valueInput; 
                    numbers[i][j] = valueInput;
                    stringMatrix[depth] += std::to_string(valueInput) + " "; 
                }
                stringMatrix[depth] += "\n";
            } 
            
            return numbers;
        }

        int **calculustGeneric(){
            numbers = matrixAccess[depth-1];
            int **numbersAux = new int*[valueMatrix];
            int valueInput, valueBool = 0, ant, counterJ = 0, i = 0, j = 0; 

            while(i < valueMatrix ){

                numbersAux[i] = new int[valueMatrix];
                counterJ = 0;

                while(counterJ < valueMatrix){

                    if(j > 0)
                        ant = valueBool;

                    valueBool = numbers[i][j] && numbers[j][counterJ] == 1 ? 1 : 0;

                    if(j > 0)
                        valueBool |= ant;
                    
                    if(j == valueMatrix - 1){
                        numbersAux[i][counterJ] = valueBool;
                        stringMatrix[depth] += std::to_string(valueBool) + " ";
                        counterJ++;
                        j = 0;
                    }else{
                        j++;
                    }
                }
                
                stringMatrix[depth] += "\n";
                
                if(counterJ == valueMatrix){
                    i++;
                    counterJ = 0;
                }
                
            }
            
            return numbersAux; 
        }

        void calculusAccess(int num){ 

            while((num - 1) > 0){
                matrixAccess[depth] = calculustGeneric();
                depth++;
                num--; 
            }
        }   

};

int main(){
    
    int valueMatrix;
    cout << "Pass the value: ";
    cin >> valueMatrix;
    matrix *matrixTest = new matrix(valueMatrix);
    matrixTest->calculusAccess(3);
    matrixTest->showMatrixAll(0);
    matrixTest->showMatrixAll(1);
    matrixTest->showMatrixAll(2);
            
}