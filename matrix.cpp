/**
 *  @file matrix.c
 *  @brief the description will be used in lists and at the start of the documentation page
 *  @author Blagovest Kostov
 *  @copy This software is distributed under proprietary license
 *                 #### all rights reserved
 *  Copying and distribution of this file, with or without modification, 
 *  are permitted in any medium provided you do not contact me about the file 
 *  or any problems you are having with the file.
 */

#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;


/**
 *  @brief Brief
 *  
 *  @param [in] e Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
inline void doAbort(const char*acError){
    cout << acError << endl;
    exit(1);
}

class Matrix{
  private:
    int iWidth, iHeight;
    int**myArray;
  public:
    /**
     *  @brief Brief
     *  
     *  @param [in] iWidth Parameter_Description
     *  @param [in] iHeight Parameter_Description
     *  @return Return_Description
     *  
     *  @details Details
     */
    Matrix(int iWidth, int iHeight): iWidth(iWidth), iHeight(iHeight) {
        myArray = new int*[iHeight];
        for(int i=0;  i < iHeight;  i++)
            myArray[i] = new int[iWidth];
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    ~Matrix(){
        delete[] myArray;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    void doFill(){
        for(int i=0;i<iHeight;i++)
            for(int j=0;j<iWidth;j++)
                myArray[i][j] = rand()%100;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    void doInit(){
        for(int i = 0;  i < iHeight;  i++)
            for(int j = 0;  j < iWidth;  j++)
                myArray[i][j] = 0;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    void printOut(){
        for(int i = 0;  i < iHeight;  i++){
            for(int j = 0;  j < iWidth;  j++)
                cout << setw(8) << myArray[i][j];
            cout << endl;
        }
        cout << endl;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    void getInput(){
        for(int i = 0;  i < iHeight;  i++)
            for(int j = 0;  j < iWidth;  j++){
                cout<<"Please enter a value for row "<< i <<" column "<< j <<":";
                cin >> myArray[i][j];
            }
    }
    /**
     *  @brief Brief
     *  
     *  @param [in] m Parameter_Description
     *  @param [in] n Parameter_Description
     *  @return Return_Description
     *  
     *  @details Details
     */
    inline int getElement(int m, int n){
        return myArray[m][n];
    }
    /**
     *  @brief Brief
     *  
     *  @param [in] m Parameter_Description
     *  @param [in] n Parameter_Description
     *  @param [in] value Parameter_Description
     *  @return Return_Description
     *  
     *  @details Details
     */
    inline void setElement(int m, int n, int myValue){
        myArray[m][n] = myValue;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    inline int getWidth(){
        return iWidth;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    inline int getHeight(){
        return iHeight;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    Matrix*doClone(){
        return new Matrix(*this);
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    Matrix*doTranspose(){
        Matrix*myTrans = new Matrix(iHeight,iWidth);
        for(int i=0; i<iHeight; i++)
            for(int j=0; j<iWidth; j++)
                myTrans->setElement(j,i,myArray[i][j]);
        return myTrans;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    void shiftDown(){
        myArray[iWidth]=myArray[0];
        for(int i=0; i < iWidth-1; i++)
            myArray[i]++;
    }
    /**
     *  @brief Brief
     *  
     *  @param [in] poMatrix Parameter_Description
     *  @return Return_Description
     *  
     *  @details Details
     */
    Matrix*doMultiply(Matrix*poMatrix){
        if(iHeight!=poMatrix->iWidth)
            doAbort("Illegal matrix dimensions");
        Matrix*resMatrix=new Matrix(iWidth,poMatrix->iHeight);
        for(int i=0;i<iWidth;i++)
            for(int j = 0;  j< resMatrix->iHeight;  j++)
                for(int k = 0;  k < iHeight;  k++)
                    resMatrix->myArray[i][j] += (myArray[i][k]*poMatrix->myArray[k][j]);
        return resMatrix;
    }
    /**
     *  @brief Brief
     *  
     *  @param [in] iRow Parameter_Description
     *  @param [in] iCol Parameter_Description
     *  @return Return_Description
     *  
     *  @details Details
     */
    Matrix*rmRowCol(int iRow, int iCol){
        Matrix*myTrans=new Matrix(iWidth-1, iWidth-1);
        myTrans->doInit();
        for(int i=0, k=0;  i < iWidth;  i++){
            if(i==iRow)
                continue;
            for(int j=0, l=0;  j < iWidth;  j++){
                if(j==iCol)
                    continue;
                myTrans->setElement(k,l,myArray[i][j]);
                l++;
            }
            k++;
        }
        return myTrans;
    }
    /**
     *  @brief Brief
     *  
     *  @return Return_Description
     *  
     *  @details Details
     */
    int computeDeterminant(){
        if(iWidth!=iHeight)
            doAbort("determinant of nonsquare matrix");
        if(iWidth==1)
            return myArray[0][0];
        if(iWidth==2)
            return myArray[0][0] * myArray[1][1]-
                   myArray[0][1] * myArray[1][0];
        if(iWidth==3)
            return myArray[0][0] * myArray[1][1] * myArray[2][2]+
                   myArray[0][1] * myArray[1][2] * myArray[2][0]+
                   myArray[0][2] * myArray[1][0] * myArray[2][1]-
                   myArray[0][0] * myArray[1][2] * myArray[2][1]-
                   myArray[0][1] * myArray[1][0] * myArray[2][2]-
                   myArray[0][2] * myArray[1][1] * myArray[2][0];
        else{
            int myResult=0;
            for(int i=0,mySign=1;i<iWidth;i++){
                myResult+=mySign*myArray[0][i]*rmRowCol(0,i)->computeDeterminant();
                mySign  *=-1;
            }
            return myResult;
        }
    }

};
/**
 *  @brief Brief
 *  
 *  @param [in] argc Parameter_Description
 *  @param [in] argv Parameter_Description
 *  @return Return_Description
 *  
 *  @details Details
 */
int main(int argc, char**argv){
    Matrix*myMatrix = new Matrix(4, 4);
    myMatrix->getInput();
    myMatrix->printOut();
    cout<<"The determinant is: " << myMatrix->computeDeterminant() << endl;
    return 0;
}
  
/**************************************************************************************************\
*                                                                                                  *
*      $Log$                                                                                       *
*                                                                                                  *
*                                                                                                  *
*                                                                                                  *
*                                                                                                  *
*                                                                                                  *
\**************************************************************************************************/

