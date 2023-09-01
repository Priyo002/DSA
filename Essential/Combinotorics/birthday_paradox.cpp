#include<iostream>
using namespace std;


int main(){

	int people = 1;

	float num = 365;
	float denom = 365;

	float prob_diff_bday = 1;


	while(1){
		prob_diff_bday = prob_diff_bday * (num/denom);
		//cout<<"People "<<people <<" Prob : "<<prob_diff_bday <<endl;

		if(prob_diff_bday  < 0.5){
			break;
		}

		
		num = num - 1;
		people = people + 1;
	}

	cout<<"Final Ans " <<people<<endl; 

	return 0;
}