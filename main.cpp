//
//  main.cpp
//  Project 1B First Draft
//
//  Created by Siddhant Singhal on 23/10/18.
//  Copyright © 2018 Siddhant Singhal. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>


void calculator();
int main();


void calculator(){
    
    double input_interval[2]{};
    double immediate_interval[2]{};
    double memory_stored [2]{};
    
    bool i_flag = false;
    bool mem_stored = false ;
    bool mc = false;
    
    std::string input;

    do {
        
        std::cout << "input :> ";
        std::cin >> input;
        
        if (input == "enter"){
            
            std::cin >> input_interval[0];
            std::cin >> input_interval[1];
            {
            
            if ( input_interval[0] > input_interval[1] ){
                std::cout << "Error: invalid interval as " << input_interval[0] << " > " << input_interval[1] ;
                std::cout << std::endl;
            } else {
                
                i_flag = true;
                immediate_interval[0] = input_interval[0];
                immediate_interval[1] = input_interval[1];
            }
            }
        } else if (input == "negate" ){
            if(i_flag == true){
            double temp;
            temp = immediate_interval[0];
            immediate_interval[0] = -immediate_interval[1];
            immediate_interval[1] = -temp;
            }

        } else if (input == "invert"){
            if (i_flag == true){
            
                if (input_interval[0] <= 0 && input_interval[1] >= 0){
                    
                    std::cout << "Error: division by zero";
                    std::cout << std::endl;
                    
                    i_flag = false;
                    
                }else{
                    double temp;
                    temp = immediate_interval[0];
                    immediate_interval[0] = 1/immediate_interval[1];
                    immediate_interval[1] = 1/temp;
                
                }
            }

        }
        
        else if (input == "ms" ){
            if (i_flag == true){
            memory_stored[0] = immediate_interval[0];
            memory_stored[1] = immediate_interval[1];
            mem_stored = true;
            }else{
                
            }
        }
        
        else if (input == "mr" ){
            if(i_flag == true && mem_stored == true){
            immediate_interval[0] = memory_stored[0] ;
            immediate_interval[1] = memory_stored[1] ;
            }
        }
        
        else if (input == "mc" ){
            if(i_flag == true ){
            
            mem_stored = false;
            }

        }
        
        else if (input == "m+"){
            if(i_flag == true && mem_stored == true){
                memory_stored[0] += input_interval[0];
                memory_stored[1] += input_interval[1];
            }
        }
        
        
        else if (input == "m-"){
            if(i_flag == true && mem_stored == true){
                memory_stored[0] -= input_interval[0];
                memory_stored[1] -= input_interval[1];
            }
        }
        
        
        
        
        else if(input == "scalar_add"){
            double c;
            std::cin >> c;
            immediate_interval[0] += c;
            immediate_interval[1] += c;

        }
        
        else if(input == "scalar_subtract"){
            double c;
            std::cin >> c;
            immediate_interval[0] -= c;
            immediate_interval[1] -= c;
            
        }
        
        else if (input == "scalar_multiply"){
            double c;
            std::cin >> c;
            if ( c >= 0){
                
                immediate_interval[0] *=c;
                immediate_interval[1] *=c;
                
            }else{
                
                immediate_interval[0] *=c;
                immediate_interval[1] *=c;
                
                double temp ;
                temp = immediate_interval [0];
                immediate_interval [0] = immediate_interval [1];
                immediate_interval [1] = temp;
                
            }
        }
        
        else if (input == "scalar_divide"){
            double c;
            std::cin >> c;
            
            if ( c == 0){
                std::cout << "Error: division by zero";
                std::cout << std::endl;
                i_flag = false;
            } else if ( c > 0 ){
                
                immediate_interval[0] /=c;
                immediate_interval[1] /=c;
                
            } else if ( c < 0 ){
                
                immediate_interval[0] /=c;
                immediate_interval[1] /=c;
                
                double temp ;
                temp = immediate_interval [0];
                immediate_interval [0] = immediate_interval [1];
                immediate_interval [1] = temp;
                
            }
            
        }
        
        else if (input == "scalar_divided_by"){
            double c;
            std::cin >> c;
            
            if ( i_flag == false){
                
            }
            
            else if ( immediate_interval[0] <= 0 && immediate_interval[1] >= 0 ){
                std::cout << "Error: division by zero";
                std::cout << std::endl;
                i_flag = false;
                
            } else if ( c > 0 ){
                
                double temp ;
                temp = immediate_interval [0];
                immediate_interval [0] = immediate_interval [1];
                immediate_interval [1] = temp;
                
                immediate_interval[0] = c / immediate_interval[0];
                immediate_interval[1] = c / immediate_interval[1];
                
            } else if ( c <= 0 ){
                
                immediate_interval[0] = c/immediate_interval[0];
                immediate_interval[1] = c/immediate_interval[1];
                
            }
            
        }
        
        else if (input == "interval_add"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            
            else {
                
                immediate_interval[0] += c;
                immediate_interval[1] += d;
                
            }
        }
        
        else if (input == "interval_subtract"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            
            else {
                
                immediate_interval[0] -= d;
                immediate_interval[1] -= c;
                
            }
        }
        
        
        else if (input == "interval_multiply"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            else{
                double temp_0;
                double temp_1;

                temp_0 = immediate_interval [0];
                temp_1 = immediate_interval [1];
                
                immediate_interval[0] = fmin( fmin (temp_0*c, temp_0*d),fmin (temp_1*c, temp_1*d));
                immediate_interval[1] = fmax( fmax (temp_0*c, temp_0*d),fmax (temp_1*c, temp_1*d));
            }
        }
        
        else if (input == "interval_multiply"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            else{
                double temp_0;
                double temp_1;
                
                temp_0 = immediate_interval [0];
                temp_1 = immediate_interval [1];
                
                immediate_interval[0] = fmin( fmin (temp_0*c, temp_0*d),fmin (temp_1*c, temp_1*d));
                immediate_interval[1] = fmax( fmax (temp_0*c, temp_0*d),fmax (temp_1*c, temp_1*d));
            }
        }
        
        
        else if (input == "interval_divide"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            else{
                
                if ( c <= 0 && d >= 0 ){
                    std::cout << "Error: division by zero";
                    std::cout << std::endl;
                    i_flag = false;
                }
                
                double temp_0;
                double temp_1;
                
                temp_0 = immediate_interval [0];
                temp_1 = immediate_interval [1];
                
                immediate_interval[0] = fmin( fmin (temp_0/c, temp_0/d),fmin (temp_1/c, temp_1/d));
                immediate_interval[1] = fmax( fmax (temp_0/c, temp_0/d),fmax (temp_1/c, temp_1/d));
            }
        }
        
        else if (input == "intersect"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            
            if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            
            else if (c > immediate_interval[1] || d < immediate_interval[0]){
                i_flag = false;
            }
            
            else {
                double temp_0 = immediate_interval[0];
                double temp_1 = immediate_interval[1];
                
                immediate_interval[0] = fmax(temp_0, c);
                immediate_interval[1] = fmin(temp_1, d);
                
            }
        }
        
        
        else if (input == "integers"){
            
            if(i_flag == false){
                
            }
            else{
      
    
                int low;
                int high;
                
                low = ceil(immediate_interval[0]);
                high = floor(immediate_interval[1]);
            
                while(low <= high){
                    
                    std::cout << low;
                    while(low < high){
                        std::cout << ", ";
                        break;
                    }
                    ++low;

                
            }
            std::cout << std::endl;
                 }
        }
        
        
        else if (input == "cartesian_integers"){
            double c;
            double d;
            std::cin >> c;
            std::cin >> d;
            
            if(ceil(immediate_interval[0])==floor(immediate_interval[1])==ceil(c)==floor(d)){
                std::cout << ", (" << ceil(c) << "," << ceil(c) << ")";
            }
            
            else if (floor(c) == floor(d)){
                
            }
            
            else if ( c > d ){
                std::cout << "Error: invalid interval as " << c << " > " << d ;
                std::cout << std::endl;
            }
            
            else if(i_flag == false){
                
                
            }
            
            else {
                
                
                int i = 0;
                int j = 0;
                int k = 0;
                int l = 0;
                int m = 0;
                int n = 0;
                int o = 0;
            
                
                
                
                
                i = ceil(immediate_interval[0]);
                j = floor(immediate_interval[1]);
                k = ceil(c);
                l = floor(d);

                
                std::cout << "(" << i << "," << k << ")";
                n = i;
                o = k;
                
                while( i <= j ){
                    m = k;
                    while ( m <= l ){
                        
                        if((i != n || o != n)){
                            std::cout << ", (" << i << "," << m << ")";
                        }
                        ++m;
                    }
                    ++i;
                
                }
                std::cout << std::endl;
            }
        
        
        
        } else {
            if(input != "exit"){
            std::cout << "Error: illegal command";
            std::cout << std::endl;
            }
            
        }
        
        

         if (i_flag == true && mc == false && input != "exit"){
            std::cout << "[" << immediate_interval[0] << ", " << immediate_interval[1] << "]";
            std::cout << std::endl;
             
        } else if (input != "exit") {
            std::cout << "--";
            std::cout << std::endl;
        }
    }

    while (input != "exit");

    std::cout << "Bye bye: Terminating interval calculator program.";
    std::cout << std::endl;

}



int main() {
    calculator();
    return 0;
}

