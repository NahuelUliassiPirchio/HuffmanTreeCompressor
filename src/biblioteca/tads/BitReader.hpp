
#ifndef BIBLIOTECA_TADS_BITREADER_HPP_
#define BIBLIOTECA_TADS_BITREADER_HPP_

#include "../funciones/files.hpp"
#include<math.h>

using namespace std;

struct BitReader
{
	FILE* f;
	char c;
	int pos;

};

BitReader bitReader(FILE* f){
	BitReader br;

	br.f = f;
	br.pos = 7;
	br.c=read<char>(f);

	return br;
}

int bitReaderRead(BitReader& br){
	int bit = 0;

	if(br.pos>=0){
		int mask = pow(2,br.pos);
		bit= (br.c & mask)!=0?1:0;
		//cout<<bit<<endl;
		br.pos--;
	}else{
		br.pos = 7;
		br.c =read<char>(br.f);
		bit = bitReaderRead(br);
	}

	return bit;
}


#endif
