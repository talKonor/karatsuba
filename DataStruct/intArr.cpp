#include "intArr.h"
intArr::intArr(int size,bool doinit, int init)
{
    log_size = size;
    real_size = size;
    if(doinit)
        arr = new int[size] {init};
    else
        arr = new int[size];
    owner = true;
}
intArr::intArr(const intArr& origin)
{
    log_size = origin.log_size;
    real_size = origin.real_size;
    owner = true;
    arr = origin.arr;
}
intArr::intArr() {
    log_size = 0;
    real_size = 0;
    arr = nullptr;
    owner = false;
}
intArr::intArr(int* slice, int slice_size)
{
    real_size = slice_size;
    log_size = slice_size;
    arr = slice;
    owner = false;
}

intArr::~intArr()
{
    if (owner) {
        delete[] arr;
    }
}

int intArr::size()
{
    return log_size;
}

void intArr::setlogSize(int new_size)
{
    log_size = new_size;
}

intArr& intArr::operator=(const intArr& int_arr)
{
    log_size = int_arr.log_size;
    real_size = int_arr.real_size;
    owner = true;
    arr = int_arr.arr;
    return *this;

}

int& intArr::operator[](int i)
{
    return arr[i];
}
void intArr::convertToInt(string number) {
    int size = number.length();

    for (int i = 0; i < size; i++) {
        arr[i]=(number[i] - '0');
    }

}

void intArr::upByTen(int power)
{
    real_size = log_size + power;
    int* temp = new int[real_size];

    memcpy(temp, arr, sizeof(int) * log_size);
    for (int i = log_size; i < real_size; i++)
    {
        temp[i] = 0;
    }
    log_size = real_size;
    if (owner)
        delete[]arr;
    owner = true;
    arr = temp;

}

void intArr::addLeadZeros(int zeroes) {
    
    real_size = log_size + zeroes;
    int* temp = new int[real_size];
    for (int i = 0; i < zeroes; i++)
    {
        temp[i] = 0;
    }
    memcpy(temp+zeroes, arr, sizeof(int) * log_size);

    log_size = real_size;
    if(owner)
        delete[]arr;
    owner = true;
    arr = temp;

    
}

void intArr::setOwner(bool set)
{
    owner = set;
}
