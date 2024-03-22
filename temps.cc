/*
 *   @file: temps.cc
 * @author: Alexander Vano
 *   @date: 3/22/2024
 *  @brief: Athens daily low temps
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

/** lowestTemp - access the lowest temperature from the array
*  @return - return the lowest temperature
*/  
int lowestTemp(int temps[]);

/** highestTemp - access the highest temperature from the array
*  @return - return the highest temperature
*/  
int highestTemp(int temps[]);

/** averageTemp - calculate the average temperature from the array
*  @return - return the average temperature
*/  
double averageTemp(int temps[]);



int main(int argc, char const *argv[]) {

    //Declares file objects
    ifstream inFile;
    ofstream outFile;

    //Declares required variables
    string line;
    int index = 0;
    int dailyLow[30];

    //Open file and check for errors
    inFile.open("athens_low_temps.txt");
    if(!inFile.is_open()) {
        cerr << "An error has occured whilst trying to open the temperature file" << endl;
    }

    //Add temperatures to array
    while(getline(inFile, line)) {
        dailyLow[index] = stoi(line);
        index++;
    }

    //Print out temperature information
    cout << "Lowest Daily Temperature: " << lowestTemp(dailyLow) << endl;
    cout << "Highest Daily Temperature: " << highestTemp(dailyLow) << endl;
    cout << "Average Daily Temperature: " << averageTemp(dailyLow) << endl;

    inFile.close();

}

//Get the lowest temperature from the daily temps
int lowestTemp(int temps[]) {
    int lowest = temps[0];
    for(int i = 0; i < 29; i++) {
        if(temps[i] < lowest)
        lowest = temps[i];
    }

    return lowest;
}

//Get the highest temperature from the daily temps
int highestTemp(int temps[]) {
    int highest = temps[0];
    for(int i = 0; i < 29; i++) {
        if(temps[i] > highest)
        highest = temps[i];
    }

    return highest;
}

//Get the average temperature from the daily temps
double averageTemp(int temps[]) {
    double average = 0;
    for(int i = 0; i < 29; i++) {
        average += temps[i];
    }
    average = (average / 30);

    return average;
}