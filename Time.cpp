#include "Time.h"
#include <cmath>
#include <iostream>


ITimeDiscretization::ITimeDiscretization(){;}

double ITimeDiscretization::get_time_init(){
	return time_init ;
};

double ITimeDiscretization::get_time_end(){
	return time_end ;
};

void ITimeDiscretization::compute_time(void ){
	time.resize(nb_points) ; 
	time[0] = time_init ; 
	double current_time = time_init ; 
	for (int i = 1 ; i < nb_points ; i++){
		dt = get_dt(current_time); 
		current_time += dt ; 
		time[i] =  current_time ; 
	}
};

int ITimeDiscretization::iteration(double t_n){

	int index = -1 ; 
	for (int i = 0 ; i < nb_points ; i++){

		if (abs(time[i] - t_n) < 10e-11){
			return i ; 
		};
	}
	return index ; 
};




//double ITimeDiscretization::get_dt(double time){
//	// suggestion : pas de discretisation constant 
//	double dt = (time_end - time_init)* (time + 0.01)/npas ; 	
//	return dt ;
//};

double UniformTimeDiscretization::get_dt(double time){
	double dt = (time_end - time_init)/npas;
	return dt;	
};

double SpecificTimeDiscretization::get_dt(double time){
	double dt = (time_end - time_init)* (time + 0.01)/npas ; 
	return dt;	
};

