#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cstdlib> //implemented to use the atoi
#include <vector>

using namespace std;

int main(){

    vector <string> *ssn = new vector <string>; //created a new vector using pointer to allocate space, used to store the info from the file
    //vector<string> ssn;
    //read SSN's from the file into strings
    ifstream in;
    in.open("everybodys_social.txt");
    int i = 0;
    while(!EOF){
        getline(in, ssn[i],',');
        i++;
    }
    in.close();//close the file once it finishes putting all the info into vector

    int *nums = new int[&ssn.size()]; //created array to store the hash addresses, used a pointer to allocate space
    //int nums [ssn.size()]
    //this for loop is to go through the vector and extract the digits I want for the hash addresses
    for (int j =0; j<ssn.size(); j++){
        ssn[j] = ssn[j][2] + ssn[j][4] + ssn[j][6] + ssn[j][7]; //extracts the string for every 3rd, 5th, 7th, and 8th part (since c++ starts from 0)
        nums[j] = atoi(ssn[j]); //store and convert the extracted strings into ints
    }

} //note use cstrings to fix problem
