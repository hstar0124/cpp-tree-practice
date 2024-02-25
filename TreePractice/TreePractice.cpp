#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

vector<int> numbers;

void BinarySearch(int N)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위 : " << left << " ~ " << right << endl;

		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾았음!" << endl;
			break;
		}
	}

}

int main()
{
	// 이진 탐색(Binary Search)

	// vector 이용
	// 탐색 : O(logN)
	numbers = { 1, 8 ,15 ,23 ,32, 44 ,56 ,63, 81, 91 };

	// 하지만 벡터는 중간 삽입 삭제가 어렵기 때문에 더 좋은 방법이 무엇인지 고민해보아야 한다.
	//BinarySearch(81);


	// 이진 탐색 트리(Binary Search Tree)
	// 데이터 추가 삭제는 부담되지 않는다. O(logN)
	// 하지만 이진 탐색 트리에도 문제점이 있다.
	// 들어오는 값이 순차적인 크기로 들어온다면 비대칭 트리가 되어 비효율적인 시간 복잡도가 나온다. (사향이진트리)
	// 이걸 해결 하려고 나온 것이 RedBlack Tree 이다.
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(10);

	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);

	bst.Delete(26);

	bst.Print();
}