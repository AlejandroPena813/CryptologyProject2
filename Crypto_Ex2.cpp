// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <vector> //vector class
#include <sstream>
using namespace std;

int main () {    //keywords p pad, u unpad, b<n> block length n
  char str[256];
  string inputPad;
  int inputLength;

  std::cout << "Enter the name of an existing text file: ";
  std::cin.get (str,256);    // get c-string

  std::fstream is(str, fstream::in | fstream::out);     // open file

  cout<< "Enter p for pad or u for unpadding: ";
  cin.ignore(); //fixes getline glitch
  getline(cin,inputPad);
  //cout<< "inputPad: "<< inputPad<< endl; //not needed just testing  //only testing padding so far then use this

  cout<< "Enter the block length value n: "; //make the default n = 8
  cin>>inputLength;
  //cout<< "blockLength: "<< inputLength<<endl;

  vector<int> padVec (inputLength,inputLength);
  //cout<< "padVec elements: "<<endl;
  /*for(int i=0; i<padVec.size(); i++)
    cout<< padVec[i]<< endl; */

  std::ostringstream oss;
  string s;
  char c;

if( (inputPad.find("p") != string::npos) ){

  while (is.get(c)){        // loop getting single characters
    //cout << hex <<(int)c << " ";
    oss<< hex <<(int)c;
    oss<< " ";
    s = oss.str(); //s now contains the hex values of the txt file!!!!!!!

  }
  //cout<< "before padding"<<s << " ";
  std::ofstream outfile (str);//hopefully erase contents
  //int someInt= 88888888;
  outfile<< s;//absorb the hex converted string
  //outfile<< someInt;//replace with vec values

  for(int i=0; i<padVec.size(); i++) //absorbing padded bytes
    outfile<< padVec[i]<< " ";
  //cout<< endl; //put a message saying contents of text have changed and these are the following contents

 cout<< "Confirm in your file! After converting file to hex ascii and padding: " << s << " ";
 for(int i=0; i<padVec.size(); i++) //absorbing padded bytes
   cout<< padVec[i]<< " ";

 cout<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////This is unpadding part
//std::ofstream outfile (str);//there is a previous version of same name, use if else statements to avoid prob
//string pad;
//std::ostringstream oss2;//get the char version
if( (inputPad.find("u") != string::npos) ){

//vector<int> unpadVec; // 0's get turned to a WRITE THIS IN BUGS
string line;
vector<string> unpadVec;

while ( getline (is,line, ' ') )
{   //convert 2 digit strings to int
    int lineInt = atoi(line.c_str());
    oss<<lineInt;//oss has the decimal version, need to go to char

    std::string myString = oss.str();
    oss.str("");//clearing oss

    //int value = atoi(myString.c_str()); //value = 45
    //unpadVec.push_back(value);
    unpadVec.push_back(myString);
}

//for(int i=0; i<unpadVec.size(); i++)//does size change dynamically??
  //cout<< unpadVec[i]<< " ";

  //cout<<"end of vec eleme" <<endl;  //this was for converting ascii hex to char, but unsuccesful. only able to store elements into vec tho

  for(int i=0; i<=inputLength; i++)//pop_back padd char
    unpadVec.pop_back();

    cout<< "Confirm in your file! Elements of ascii hex file after unpadding: " <<endl;

    for(int i=0; i<unpadVec.size(); i++) //print unpadded vec
      cout<< unpadVec[i]<< " ";

  std::ofstream outfile (str);//hopefully erase contents
  for(int i=0; i<unpadVec.size(); ++i){ //absorbing unpadded elements
    //if(unpadVec[i]==0)
    //  outfile<< 'a' <<" ";
    //else
      outfile<< unpadVec[i]<< " "; //the last element is 0, bug?
  }
}
  ///////////////////////////////////////////////////////end of 2_1, need to do u and p options, plus 2_1 and 2_2 options

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////// 2_2 start


/*  char strOther[256]; //specify name of keyfile
  int inputLengthP2;
  vector<int> keyVec;
  vector<string> fileVec;//store file elements to shift around
  vector<string> encryVec(10); //will have en order

std::cout << "Enter the name of the key text file: "<<endl; //need for e or decrypt
cin.ignore();//once again fixes silly get issue
cin.get (strOther,256);    // get c-string
cout<< "name of this file to be exec: "<< strOther <<endl; */

/*cout<< "Enter the block length value n: "; //make the default n = 8
cin>>inputLengthP2; */ //not just yet, this will help with char strings of multiples of n

/*std::fstream fs(strOther, fstream::in | fstream::out);  //for actual key file


string line; //SAME NAME AS BEFOREEEEEEEEE< SCOPE PROBS
string lineFile;//retrieves file lines

while ( getline (fs,line, ' ') )
{   //convert 2 digit strings to int
    keyVec.push_back( atoi(line.c_str()) );

}

cout<<" KEY VEC ELEMENTS: " <<endl;
for(int i=0; i<keyVec.size(); i++)//does size change dynamically??
  cout<< keyVec[i];

  cout<<endl;

  while ( getline (is,lineFile, ' ') )//retrieve file elements
  {   //convert 2 digit strings to int
      fileVec.push_back( lineFile );//look at other example if broken

  }

  cout<<" FILE FILE VEC ELEMENTS: " <<endl;
  for(int i=0; i<fileVec.size(); i++)//does size change dynamically??
    cout<< fileVec[i];

  for(int i = 0; i<=6; i++){//reorder fileVec

    int position = keyVec[i];
    encryVec.insert(encryVec.begin()+position-1, fileVec[i]);


  }


  cout<<" FILE FILE AFTER REORDER VEC ELEMENTS: " <<endl;
  for(int i=0; i<10; i++)//does size change dynamically??
    cout<< encryVec[i];

 std::ofstream outfile (str);//hopefully erase contents
  for(int i=0; i<unpadVec.size(); ++i){ //absorbing unpadded elements
    if(unpadVec[i]==0)
      outfile<< 'a' <<" ";
    else
      outfile<< unpadVec[i]<< " ";
  }*/ //needed to reinsery fileVec elements


  //fs.close();//close key file
  is.close();                // close file

  return 0; //for unpadding first read the string seperated by spaces, put into string with value of dec and static_char
            //then remove the final n bytes
}
