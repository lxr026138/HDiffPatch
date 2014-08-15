//suffix_string.h
//create by housisong
//后缀字符串的一个实现.
//
/*
 Copyright (c) 2012-2014 HouSisong All Rights Reserved.
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef __SUFFIX_STRING_H_
#define __SUFFIX_STRING_H_
#include <vector>

class TSuffixString{
public:
    typedef ptrdiff_t     TInt;
    
    TSuffixString(const char* src_begin,const char* src_end);
    const char*const    src_begin;//原字符串.
    const char*const    src_end;
    TInt SA(TInt i)const;//SA[]排好序的后缀字符串数组.
    TInt lower_bound(const char* str,const char* str_end)const;//return index in SA
private:
    typedef int TInt32;
    std::vector<TInt32>    m_SA_small;
    std::vector<TInt>      m_SA_large;
    inline bool isUseLarge()const{
        if (sizeof(TInt)<=sizeof(TInt32)) return  false;
        const TInt kMaxDataSize_small= (1<<30)-1 + (1<<30);//2G
        return (src_end-src_begin>kMaxDataSize_small);
    }
};

#endif //__SUFFIX_STRING_H_
