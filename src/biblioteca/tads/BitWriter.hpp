
#ifndef BIBLIOTECA_TADS_BITWRITER_HPP_
#define BIBLIOTECA_TADS_BITWRITER_HPP_

#include "../funciones/files.hpp"
#include<math.h>

using namespace std;

struct BitWriter
{
	FILE* f;
	int pos;
	int * arr;
};

BitWriter bitWriter(FILE* f){
	BitWriter bw;
	bw.f = f;
	bw.pos = 7;
	bw.arr = new int[7];
	return bw;
}

char crearChar (int arr[]){
	int c = 0;

	for(int i = 0; i<8 ;i++){
		if(arr[i]==1){
			c += pow(2,i);
		}
	}

	return (char) c;
}

void bitWriterWrite (BitWriter& bw , int bit){
	bw.arr[bw.pos] = bit;
	if(bw.pos==0){

		char c = crearChar(bw.arr);
		write<char>(bw.f,c);


		//cout<<"escribio"<<endl;
		bw.pos=7;
	}else{
		//cout<<bw.pos<<endl;
		bw.pos--;
	}
}

void bitWriterFlush(BitWriter& bw){
	while(bw.pos>=0){
		bw.arr[bw.pos] = 0;
		bw.pos--;
	}

	char c = crearChar(bw.arr);
	write<char>(bw.f,c);
	bw.pos=7;
}

#endif
