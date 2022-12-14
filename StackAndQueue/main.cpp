#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		if (_size == _container.size())
		{
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);

			for (int i = 0; i < _size; ++i)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}
			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container;
	int _front;
	int _back;
	int _size;
};

int main()
{
	ArrayQueue<int> q;
	for (int i = 0; i < 100; ++i)
	{
		q.push(i);
	}

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
	return 0;
}