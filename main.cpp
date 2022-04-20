//home/ibrahim/Personal_for_Ibrahim/Learning/C++/C++_Codes/Assignment3/photographer
// Name: Ibrahim Tarek Ibrahim Mohamed
// ID: 20211002
// Assignment 3

// including all required files
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "bmplib.h"
#include "bmplib.cpp"

// initializing all functions before the main
void display_menu();
double avg();
void load();
void save();
void mirror ();
void detect_edges();
void flip_horizontal();
void flip_vertical();
void Black_White_Filter();
const int COUNT = 256 *256;
unsigned char image[SIZE][SIZE];
// using function std::input & std::output
using namespace std;
//..........................................
//initializing main function
int main (){
    //loading the image
    load();
    // always showing the menu display
    while (true) display_menu();
    cout<<"\n";
}
//..........................................
void display_menu(){
    char option;
    int option1;
    //showing all possible options
    cout<<"choose a filter to apply or 0 to exit : \n";
    cout<<"1- Black & White Filter\n";
    cout<<"4- Flip Image\n";
    cout<<"7- Detect Image Edges\n";
    cout<<"a- Mirror 1/2 Image\n";
    cout<<"s- Save the image to a file\n";
    cout<<"0- Exit\n";
    // input options
    cin >> option;

    //applying black and white filter
    if (option == '1') Black_White_Filter();
    else if (option == '4'){
        cout<<"for horizontal flip press (1) for vertical flip press (2)"<<endl;
        cin>>option1;
        if(option1 == 1)flip_horizontal();
        else if (option1 == 2) flip_vertical();
    }
    // apply edges remarking filter
    else if (option == '7'){
         Black_White_Filter();
         detect_edges();
     }
    // applying mirror filter
    else if (option == 'a') mirror();
    // ending program
    else if (option == '0') exit(0);
}
//..........................................
//initializing loading function
void load(){
    char imageFileName[100];
    // input image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    // load image file name
    readGSBMP(imageFileName, image);
 }
//..........................................
// initialize saving image function
 void save(){
    char imageFileName[100];
    // input new image saved name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    // saving the image with the new filter and name
    writeGSBMP(imageFileName, image);
}
//..........................................
// initializing average calculating function
double avg(){
    int sum = 0;
    for ( int row =0 ; row <SIZE; row++)
        for (int col =0 ; col <SIZE; col++)
            sum += image[row][col];
    double result = sum / COUNT ;
    return result ;
}
//..........................................
void Black_White_Filter(){
    // nested for loop to calculate the average by the column and row
    for ( int row =0 ; row <SIZE; row++){
        for (int col =0 ; col <SIZE; col++){
            // checking if the oclumn ended or not
           if (image[row][col] > avg()) image[row][col] =255;
           else if (image[row][col] < avg()) image[row][col] =0;
        }
    }
    // saving the filter fy calling the function
    save();
}
//..........................................
// initializing horizontal flipping function
void flip_horizontal(){
    unsigned char temp;
    // nested loop to pass by every bit in the image by column and row
    for( int row = 0; row < SIZE/2 ; row++){
        for(int col =0 ; col < SIZE ; col++){
            // shifting the bits horizontally
            temp = image[255-row][col];
            image[255-row][col] = image[row][col] ;
            image[row][col] = temp;
        }
    }
    // saving the filter fy calling the function
    save();
}
//..........................................
// initializing vertical flipping function
void flip_vertical(){
    unsigned char temp;
    // nested loop to pass by every bit by column and row
    for( int row = 0; row < SIZE ; row++){
        for(int col =0 ; col < SIZE/2 ; col++){
            // shifting the bits vertically
            temp = image[row][255 - col];
            image[row][255 - col] = image[row][col] ;
            image[row][col] = temp;
        }
    }
    // saving the filter fy calling the function
    save();
}
//..........................................
// initializing Mirroring function
void mirror(){
    int choice;
    // showing Mirroring choices
    cout<<"Left Mirroring -1-\n";
    cout<<"Right Mirroring -2-\n";
    cout<<"Upper Mirroring -3-\n";
    cout<<"Lower Mirroring -4-\n";
    // Input choice
    cin >> choice;
    // applying Left Mirroring
    if (choice == 1){
        // nested loop do pass by every bit by column and row
        for( int row = 0; row < SIZE ; row++){
            for(int col =0 ; col < SIZE/2 ; col++){
                image[row][255-col] = image[row][col];
            }
        }
    }
    // applying Right Mirroring
    else if (choice == 2){
        // nested loop do pass by every bit by column and row
        for( int row = 0; row < SIZE ; row++){
            for(int col =0 ; col < SIZE/2 ; col++){
                image[row][col] = image[row][255-col];
            }
        }
    }
    // applying Upper Mirroroing
    else if (choice == 3){
        // nested loop do pass by every bit by column and row
        for( int row = 0; row < SIZE/2 ; row++){
            for(int col =0 ; col < SIZE ; col++){
                image[255-row][col] = image[row][col];
            }
        }
    }
    // applying Lower Mirroring
    else if (choice == 4){
        // nested loop do pass by every bit by column and row
        for( int row = 0; row < SIZE/2 ; row++){
            for(int col =0 ; col < SIZE ; col++){
                image[row][col] = image[255-row][col];
            }
        }
    }
    // saving the filter fy calling the function
    save();
}
//..........................................
// initializing dectecting edges function
void detect_edges(){
    // nested loop do pass by every bit by column and row
    for( int row = 0; row < SIZE ; row++){
        for(int col =0 ; col < SIZE ; col+=1){
            // checking if bits has ended
            if(image[row][col] == image[row][col+1]) image[row][col]= 255;
            else {image[row][col] = 0;}
        }
    }
}
//..........................................
