#pragma once
#ifndef __PUBLIC_H_
#define __PUBLIC_H_
#include<iostream>
#define LOG(str) \
    std::cout<<__FILE__<<":"<<__FILE__<<" "<< \
    __TIMESTAMP__<<" : "<<str<<std::endl;

#endif
