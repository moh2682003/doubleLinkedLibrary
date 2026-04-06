#pragma once
#include <iostream>
#include "clsMyQueue.h"

using namespace std; 

template <class T>
class clsMyDynamicArray 
{
protected:
	int _Size = 0;
	T* _TempArray;

public:

	T* OriginalArr;
	
	clsMyDynamicArray(int Size)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size ;

		OriginalArr = new T[_Size];
	}

	~clsMyDynamicArray()
	{
		delete[] OriginalArr;
	}

	bool SetItem(int index, T value)
	{
		if (_Size < 0 || index >= _Size)
			return false;
		OriginalArr[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void Print()
	{
		for (int i = 0; i < Size(); i++)
			cout << OriginalArr[i] << " ";
		cout << endl;
	}

	void Resize(int NewSize = 0)
	{
		if (NewSize < 0)
			NewSize = 0;

		if (NewSize < _Size)
			_Size = NewSize;

		_TempArray = new T[NewSize];

		for (int i = 0; i < _Size; i++)
			_TempArray[i] = OriginalArr[i];

		delete[] OriginalArr;
		_Size = NewSize;

		OriginalArr = _TempArray;
	}
	
	T GetItem(int Index)
	{
		return OriginalArr[Index];
	}

	void Clear()
	{
		if (OriginalArr != NULL)
		{
			delete OriginalArr;
			OriginalArr = NULL;
			_Size = 0;
		}
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArr[_Size - 1 - i];
		}

		delete[] OriginalArr;

		OriginalArr = _TempArray;
	}

	bool DeleteItem(int Index)
	{

		if (Index >= _Size || Index < 0)
			return false;

		_Size -- ;
		_TempArray = new T[_Size];
	
		// Copy Before Index 
		for (int i = 0; i < Index; i++)
			_TempArray[i] = OriginalArr[i];
		
		for (int i = Index +1 ; i <= _Size ; i++)
			_TempArray[i - 1] = OriginalArr[i];

		delete[] OriginalArr;
		OriginalArr = _TempArray;
		return true;
	}
	
	void DeleteFirstItem()
	{
		DeleteItem(0);
	}

	void DeleteLastItem()
	{
		DeleteItem(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
			if (GetItem(i) == value)
				return i;
		return -1;
	}

	bool DeleteValue(T value)
	{
		int Index = Find(value);

		if (Index == -1)
			return false;

		DeleteItem(Index);
		return true;
	}

	bool insertAt(int Index, T value)
	{
		if (Index > _Size || Index < 0)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
			_TempArray[i] = OriginalArr[i];

		_TempArray[Index] = value;

		for (int i = Index; i < _Size -1; i++)
		{
			_TempArray[i + 1] = OriginalArr[i];
		}
		 
		delete[] OriginalArr;
		OriginalArr = _TempArray;
		return true;
	}

	void InsertAtBegining(int value)
	{
		insertAt(0, value);
	}

	void InsertBefore(int index, T value)
	{
		if (index < 1)
			InsertAtBegining(value);
		else
			insertAt(index - 1, value);

	}

	void InsertAfter(int index, T value)
	{
		if (index >= _Size)
			insertAt(_Size - 1, value);
		else
			insertAt(index + 1, value);
	}

	void InsertAtEnd(T value)
	{

		insertAt(_Size, value);
	}

	
};

