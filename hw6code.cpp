#include<iostream>
#include<fstream>
#include<string> //huh???
#include<vector>
#include<array>
#include <cstdlib> // implemented to use atoi
#include<typeinfo>
#include<math.h>

using namespace std;

int quad_prob(int num, int user_input)
{
    int position = num + (user_input)^2; //use user input as the number to square for quad probing?
    return position;
}

/*int * extraction (vector<string>file){
string HA;
int hAdd [file.size()]; // array that holds the hash addresses aka hash table?
/*cout << "file size:" << file.size() << endl; // for debugging
cout << "hAdd's size: " << sizeof(hAdd) << endl; */
/*for (int s=0; s<file.size(); s++){
        HA = file[s]; //insert social security number into string
        //cout << "*" << HA << endl;//cout << HA[0] << "+" << HA[1] << endl;
        char *a=new char[4]; //create a character array that takes in pieces of numbers from the string variable and
        a[0]=HA[2];
        a[1]=HA[4];
        a[2]=HA[6];
        a[3]=HA[7];
        int j=atoi(a); // convert array into integers and input it in integer variable
        //printing weird numbers
        cout << j << endl;

        hAdd[s] = j; } //adds the converted and extracted variable into array
/*cout << "size: " << sizeof(hAdd) << endl;
for (int g=0; g<sizeof(hAdd); g++){
    cout << "hAdd" << hAdd[g] << endl;
}
return hAdd;
}*/

void write_file (int arr[]){
    ofstream newfile; //created a new file to put/write stuff in
    newfile.open("hashed_socials.txt"); //opens the new file
    for (int x=0; x<sizeof(arr); x++){
        newfile << arr[x] << ',';
        if (x == (sizeof(arr)-1)){ //prevents comma at the last hash address
            newfile << arr[x];
        }
    }
}

int main(){
string line, temp ="";
vector<string> ssn;
ifstream in;
int userI;//used for quadratic probing

cout << "Please enter a number between 1 and 450 million:" << endl;
cin >> userI;

in.open("everybodys_socials.txt");
if (in.is_open()){
while(getline(in,line)){ //goes through the file and gets the data into line
    line += ',';
    //cout << line << endl; //debuggging
        for (int i=0; i<line.length(); i++){
            //cout << typeid(line[i]).name() << " - " << endl; checking debugg, so line[i] is type char
            //the if statement is not working -runtime error // - cleared up by using push back on vector
            if (line[i] == ','){ // when it hits the comma, the temp with the whole social security number is added into the vector
                ssn.push_back(temp);//empties temp once finish adding number into vector for another number
                //cout << "Temp: " << temp << endl; debugging
                temp = "";}
        else {temp += line[i]; // if not a comma, add every char number into temp
        }
    }
    }
    //cout << "line length: " << line.length() << endl;//for debugging
}
else { cout << "file not found, please try again" << endl;}

in.close();

string HA;
int hAdd [ssn.size()]; // array that holds the hash addresses aka hash table?
/*cout << "file size:" << file.size() << endl; // for debugging
cout << "hAdd's size: " << sizeof(hAdd) << endl; */
for (int s=0; s<ssn.size(); s++){
        HA = ssn[s]; //insert social security number into string
        //cout << "*" << HA << endl;//cout << HA[0] << "+" << HA[1] << endl;
        char *a=new char[4]; //create a character array that takes in pieces of numbers from the string variable and
        a[0]=HA[2];
        a[1]=HA[4];
        a[2]=HA[6];
        a[3]=HA[7];
        int j=atoi(a); // convert array into integers and input it in integer variable
        //printing weird numbers
        cout << j << endl;

        hAdd[s] = j; }
//extraction(ssn);
//int arr [ssn.size()]; //arr = extraction(ssn);
int hash_table[ssn.size()];
int socialSN = 0;
for (int p=0; p<ssn.size(); p++){
    socialSN = atoi(ssn[p].c_str());
    int k = hAdd[p];
    hash_table[k] = socialSN;
    //quad_prob(socialSN, userI);
}

write_file(hash_table);
}
