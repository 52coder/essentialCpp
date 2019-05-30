#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
/*书中课后题答案中代码编译失败，需要调用max前加::用以指定是调用的全局域的max*/
using namespace std;

template <typename Type>
inline Type max(Type t1,Type t2)
{
    return t1 > t2 ? t1 : t2;
}

template <typename elemType>
inline elemType max(const vector<elemType> &vec)
{
    return *max_element(vec.begin(),vec.end());
}

template <typename arrayType>
inline arrayType max(const arrayType *parray,int size)
{
    return *max_element(parray,parray + size);
}

int main()
{
    int iarray[]={12,70,2,169,1,5,29};
    vector<int> ivec(iarray,iarray + 7);

    float farray[]={2.5,24.8,18.7,4.1,23.9};
    vector<float> fvec(farray,farray + 5);

    string sarray[]={"we","were","her","pride","of","ten"};
    vector<string> svec(sarray,sarray + 6);

    int imax=::max(::max(ivec),::max(iarray,7));
    float fmax=::max(::max(fvec),::max(farray,5));
    string smax=::max(::max(svec),::max(sarray,6));

    cout << "imax should be 169 -- found: "<<imax<<'\n'
         << "fmax should be 24.8 -- found: "<<fmax<<'\n'
         << "smax should be were -- found: "<<smax<<'\n';

    return 0;
}