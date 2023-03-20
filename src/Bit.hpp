/*
 * Bit.hpp
 *
 *  Created on: Feb 4, 2022
 *      Author: pirxio
 */

#ifndef BIT_HPP_
#define BIT_HPP_

bool getBit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}



#endif /* BIT_HPP_ */
