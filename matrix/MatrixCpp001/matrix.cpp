#include "matrix.h"
#include <iostream>

using namespace std;

int Matrix::m_instanceCount = 0;
int Matrix::m_totalCount = 0;
int Matrix::m_valuesCount = 0;

Matrix::Matrix()
    :m_rowCount(0),m_columnCount(0),m_values(0)
{
    cout << "Matrix::Matrix()" << endl;
    m_instanceCount++;
    m_totalCount++;
}

Matrix::Matrix(unsigned rowCount,unsigned columnCount)
    :m_rowCount(rowCount),m_columnCount(columnCount),m_values(0)
{
    cout << "Matrix::Matrix(unsigned rowCount,unsigned columnCount)" << endl;
    m_values = new double[rowCount * columnCount];
    m_valuesCount++;
    for( unsigned row = 0; row < rowCount; row++ ){
        for( unsigned column  = 0; column < columnCount; column++ ){
            setValue(row,column,0);
        }
    }
    m_instanceCount++;
    m_totalCount++;
}

Matrix::Matrix( const Matrix &other )
    :m_rowCount(other.rowCount()),m_columnCount(other.columnCount()),m_values(0)
{
    cout << "Matrix::Matrix( Matrix &other )" << endl;
    m_values = new double[rowCount() * columnCount()];
    m_valuesCount++;
    for( unsigned row = 0; row < rowCount(); row++ ){
        for( unsigned column  = 0; column < columnCount(); column++ ){
            setValue(row,column, other.value(row,column));
        }
    }
    m_instanceCount++;
    m_totalCount++;
}

Matrix::~Matrix()
{
    cout << "Matrix::~Matrix()" << endl;
    if( m_values ){
        delete[] m_values;
        m_valuesCount--;
    }
    m_instanceCount--;
}

unsigned Matrix::rowCount() const
{
   return m_rowCount;
}

unsigned Matrix::columnCount() const
{
    return m_columnCount;
}

void Matrix::setValue(unsigned row, unsigned column, double value)
{
    m_values[index(row,column)] = value;
}

void Matrix::setValues(double value[])
{
    for( unsigned row = 0; row < m_rowCount; row++ ){
        for( unsigned column  = 0; column < m_columnCount; column++ ){
            setValue(row,column,value[index(row,column)]);
        }
    }
}

double Matrix::value(unsigned row, unsigned column) const
{
    return m_values[index(row,column)];
}

Matrix Matrix::operator+( const Matrix &other ) const
{
    Matrix m( rowCount(), columnCount() );
    for( unsigned row = 0; row < rowCount(); row++ ){
        for( unsigned column = 0; column < columnCount(); column++ ){
            m.setValue(row,column,value(row,column) + other.value(row,column));
        }
    }
    return m;
}

Matrix Matrix::operator*( const Matrix &other ) const
{
    Matrix m( rowCount(), columnCount() );
    for( unsigned row = 0; row < rowCount(); row++ ){
        for( unsigned column = 0; column < columnCount(); column++ ){
            m.setValue( row, column, multiplyOneValue( other, row, column ) );
        }
    }
    return m;
}

double Matrix::multiplyOneValue( const Matrix &other, unsigned row, unsigned column ) const
{
    double val = 0;
    for( unsigned i = 0; i < columnCount(); i++ ){
        val += (value( row, i ) * other.value( i, column) );
    }
    return val;
}

Matrix &Matrix::operator=( const Matrix &other)
{
    cout << "Matrix::operator=( const Matrix &other)" << endl;
    m_rowCount = other.rowCount();
    m_columnCount = other.columnCount();
    if( m_values ){
        delete[] m_values;
        m_valuesCount--;
    }
    m_values = new double[m_rowCount*m_columnCount];
    m_valuesCount++;
    for( unsigned row = 0; row < m_rowCount; row++ ){
        for( unsigned column = 0; column < m_columnCount; column++ ){
            setValue(row,column,other.value(row,column));
        }
    }
    return *this;
}

unsigned Matrix::index(unsigned row, unsigned column) const
{
    return m_columnCount * row + column;
}

int Matrix::instanceCount()
{
    return m_instanceCount;
}

int Matrix::totalCount()
{
    return m_totalCount;
}

int Matrix::valuesCount()
{
    return m_valuesCount;
}

void Matrix::resetCount()
{
    m_instanceCount = 0;
    m_totalCount = 0;
    m_valuesCount = 0;
}
