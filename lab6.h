#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
using namespace std;

template <typename T>
class dynamic_array
{
private:
    int m_size;
    T* m_data;

public:
    dynamic_array()
    {
        this->m_size = 0;
        this->m_data = NULL;
    }
    dynamic_array(const dynamic_array<T>& a)
    {
        this->m_size = a.m_size;
        this->m_data = new T[m_size];
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }
    dynamic_array(int size, T* ms)
    {
        this->m_size = size;
        m_data = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->m_data[i] = ms[i];
        }
    }
    ~dynamic_array()
    {
        delete[] m_data;
    }
    void push_back(T val)
    {
        this->m_size += 1;
        m_data[m_size - 1] = val;
    }
    int size()
    {
        return m_size;
    }
    T& operator[] (int i)
    {
        return m_data[i];
    }
    int search(T find)
    {
        int k;
        for (int i = 0; i < this->m_size; i++)
        {
            if (this->m_data[i] == find)
            {
                k = i;
                break;
            }
        }
        return k;
    }
    int Del(int m_index)
    {
        int k = m_index;
        for (int i = k; i < m_size; i++)
        {
            m_data[i] = m_data[i + 1];
        }
        m_size -= 1;
        return 1;
    }
};