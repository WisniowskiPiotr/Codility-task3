#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Exception{
  private: 
    int Id;
    string Comment;

  public:
    Exception(int id,string comment){
      Id=id;
      Comment=comment;
    };

    int GetId(){
      return Id;
    };
    
    string GetComment(){
      return Comment;
    };
};

vector<vector<bool>> GenerateMatrix(char *argv[]){
  string arg=argv[1]; // convert to string
  if(arg[0]!='[')
    throw new Exception(3,"Input data should start with '[' char.");
  int argsize=arg.size();
  vector<vector<bool>> result;
  for (int i=0; i<argsize; i++){
    switch(arg[i]){
      case '[':{ // allocate new vector
        result.emplace_back();
        break;
      };
      case ']':{// skipp
        break;
      };
      case ',':{// skipp
        break;
      };
      case '1':{// case true
        result.back().emplace_back(true);
        break;
      };
      case '0':{// case false
        result.back().emplace_back(false);
        break;
      };
      default:{
        throw new Exception(1,"Unexpected chars in input string.");
        break;
      };
    };
  };
 return result;
};

class TrueBox{
  private: 
    int X;
    int Y;
    int L;

  public:
    TrueBox(int x,int y, vector<vector<bool>> &matrix){
      X=x;
      Y=y;
      L=0;
      vector<bool> flag1=this->Check(true, matrix);
      vector<bool> flag2=this->Check(false, matrix);
      while(flag1[0] && flag1[1] && flag2[0] && flag2[1]){
        L++;
        flag1=this->Check(true, matrix);
        flag2=this->Check(false, matrix);
      };
    };

    int GetL(){
      return L;
    };

    int GetX(){
      return X;
    };

    int GetY(){
      return Y;
    };

    vector<bool> Check( bool direction, vector<vector<bool>> &matrix, bool next=0){// sprawdzić czy się nie przekroczy rozmiarów maciezy a
      vector<bool> result(2,true);
      if(X+L+next>=matrix.size() || Y+L+next>=matrix[X+L].size()){
        result[1]=false;
        return result;
      };
        
      for(int i=next; i<=L+next; i++){
        if(((direction && matrix[X+L][Y+i]==false) || (!direction && matrix[X+i][Y+L]==false))){
          result[0]=false;
          return result;
        };
      };
      return result;
    };

    bool Move(bool x, bool y, vector<vector<bool>> &matrix){
      vector<bool> flag1=this->Check(true, matrix, x);
      vector<bool> flag2=this->Check(false, matrix, y);
      if(flag1[1]==false || flag2[1]==false)
        return false;
      if((!flag1[0] && flag2[0])){
        L--;
      };
      X+=x;
      Y+=y;   
      return true;     
    };

};

int main(int argc,char *argv[]){
  try{
    if(argc<2)
      throw new Exception(2,"Please provide input matrix.");
    vector<vector<bool>> input=GenerateMatrix(argv);
    TrueBox box(0,0,input);
    while(box.Move(true,true,input));

    cout<<"Obliczone L: "<<box.GetL()<<" ostatnia pozycja: "<<box.GetX()<<", "<< box.GetY()<<endl;

  }
  catch(Exception exception){
    cout<<"Error id: "<<exception.GetId()<<endl;
    cout<<exception.GetComment()<<endl;
    return exception.GetId();
  };
return 0;
};