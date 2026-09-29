#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[4] = {7, 3, 9, 4};
	int n = 4;

	cout << "Unsortiertes Array: ";
	printArray(arr, n);

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		cout << "\nEinfuegen von " << key << ":" << endl;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;

		cout << "Array nach Schritt " << i << ": ";
		printArray(arr, n);
	}

	cout << "\nSortiertes Array: ";
	printArray(arr, n);

	return 0;
}
