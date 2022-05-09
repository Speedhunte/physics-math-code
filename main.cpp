#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

 template<typename T>
class Matrix {

private:
    int N;// ������
    int M;// �������

public:
    T *data;
    Matrix(int N, int M){ //����������� ������� ������� ���������� �������
    this->N=N;
    this->M=M;
    this->data=new T [N][M]={{0}};

    }


    Matrix() { //����������� ��������� �� �����
    ifstream input("����� ���� � �����");

    if (!input){
        cout<<"���� �� ������"<<endl;
    }
    input>>N;
    input>>M;
    this->data=new T  [N][M];
    for (int i =0;i<N;i++)
        for (int j=0;j<M;j++)
            input>> this->data[i][j];

    }


    Matrix operator *(const Matrix& other) /*���������� ��������� ������ */
    {
        Matrix temp;
        temp.data=new T  [other.N][other.M];
        if (this->M!=other.N)
            cout<<"������ ��������";
        else{
            for (int i=0;i<other.N){
                for (int j=0;i<other.M) {

                    temp.data[i][j]=0;
                    for (int k=0;k<other.N)
                        temp.data[i][j]+=(this->data[i][k]*other.data[k][j])

                }
            }
            return temp;
        }

    }
    Matrix operator +(const Matrix &other) /*���������� �������� ������*/
    {   if (this->N=other.N && this->M=other.M)
        {
           Matrix temp;
           temp.data=new T  [other.N][other.M]={{0}};
           for (int i=0; i<this->N;i++) {
                for (int j=0; i<this->M;j++)
                    temp.data[i][j]+=(this->data[i][j]+other.data[i][j]);
           }
           return temp;
        }
        else {
            cout<<"������� ������"<<endl;
        }


    }


    Matrix operator -(const Matrix &other) /*���������� ��������� ������*/
    {   if (this->N=other.N && this->M=other.M)
        {
           Matrix temp;
           temp.data=new T [other.N][other.M]={{0}};
           for (int i=0; i<this->N;i++) {
                for (int j=0; i<this->M;j++)
                    temp.data[i][j]+=(this->data[i][j]-other.data[i][j]);
           }
           return temp;
        }
        else {
            cout<<"������� ������"<<endl;
        }
    }


    bool operator ==(const Matrix & other){ /* �������� �� ��������� ������, ��� 0 � 1 */

        if (this->N=other.N && this->M=other.M) {
            for (int i=0; i<this->N;i++) {
                    for (int j=0; i<this->M;j++){
                        if (this->data[i][j]!=other.data[i][j] )
                            return false;
                    }
            }

        }
    }


    Matrix & operator = (const Matrix &other)
    {
        this->N=other.N;
        this->M=other.M;
        if (this->data!=nullptr){
            delete[] this->data;
        }
        this->data=new T  [N][M];
        for (int i=0; i<this->N;i++) {
                    for (int j=0; i<this->M;j++)
                        this->data[i][j]=other.data[i][j];
         }
         return *this;
    }


};
int main()
{
setlocale(LC_ALL,"");

}
