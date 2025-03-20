#include<fstream>
#include<iostream>
#include<iomanip>

double mappatore(double x){
	return -1.0+(x-1.0)*(3.0/4.0);
}

int main(){
	std::ifstream fstr("data.txt");
	std::ofstream fileresult("result.txt");
	if(fstr.fail()){ 
		std:: cerr << "File 'data.txt' not found" << std:: endl; 
		return 1; 
	}
	
	if(fileresult.fail()){ 
		std:: cerr << "File  'result.txt' not opened succesfully" << std:: endl; 
		return 2; 
	}
	double val,sum = 0.0;
	int i=0;
	double media;
	fileresult << "#N Mean"<<std::endl;
	fileresult << std::scientific << std::setprecision(16);
	while(fstr >> val){
		sum += mappatore(val); 
		media=sum/(i+1);
		fileresult << (i+1) << " " << media << std::endl;
		i++;
	}
	
	fstr.close();
	fileresult.close();
	
    return 0;
}