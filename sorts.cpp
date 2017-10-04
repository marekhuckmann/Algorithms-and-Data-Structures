#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;
int size = 13;
int heapSize;

void heapify(int *tab, int i)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int largest;

	if ((l <= heapSize) && (tab[l]>tab[i]))
		largest = l;
	else largest = i;

	if ((r <= heapSize) && (tab[r]>tab[largest])) largest = r;

	if (largest != i)
	{
		swap(tab[i], tab[largest]);
		heapify(tab, largest);
	}
}

void buildHeap(int *tab)
{
	heapSize = size;
	for (int i = size / 2; i >= 1; i--)
		heapify(tab, i);
}

void heapsort(int *tab)
{
	
	buildHeap(tab);
	for (int i = size; i >= 2; i--)
	{
		swap(tab[1], tab[i]);

		heapSize--;
		heapify(tab, 1);
	}
}

void bubblesort(int *tab)
{
	int n = size;
	do
	{
		for (int i = 0; i<n - 1; i++)
		{
			if (tab[i] > tab[i + 1]) swap(tab[i], tab[i + 1]);
		}
		n--;
	} while (n>1);
}

int partition(int *tab, int l, int r)
{
	int x = tab[r];
	int i = l - 1;

	for (int j = l; j<r; ++j)
	{
		if (tab[j] <= x)
		{
			i++;
			swap(tab[i], tab[j]);
		}
	}
	swap(tab[i + 1], tab[r]);
	return i + 1;
}

void quicksort(int *tab, int l, int r)
{
	if (l<r)
	{
		int p = partition(tab, l, r);
		quicksort(tab, l, p - 1);
		quicksort(tab, p + 1, r);
	}
}

void merge(int *tab, int l, int p, int r)
{
	int i, j, k;
	int n1 = p - l + 1;
	int n2 = r - p;
	int *L;
	L = new int[n1];
	int *R;
	R = new int[n2];

	for (i = 0; i<n1; i++)
		L[i] = tab[i + l];

	for (j = 0; j<n2; j++)
		R[j] = tab[p + j + 1];

	for (k = l, i = j = 0; k <= r; k++)
	{
		if (j >= n2 || (i < n1 && L[i] <= R[j]))
			tab[k] = L[i++];
		else tab[k] = R[j++];
	}
}

void mergesort(int *tab, int l, int r)
{
	if (l < r){
		int p = (l + r) / 2;
		mergesort(tab, l, p);
		mergesort(tab, p + 1, r);
		merge(tab, l, p, r);
	}
}

int main()
{
	int *tab;
	tab = new int[size];

	int *tab2;
	tab2 = new int[size];

	int *tab3;
	tab3 = new int[size];

	int *tab4;
	tab4 = new int[size];

	srand(time(NULL));
	for (int i = 0; i<size; i++)
	{
		tab[i] = 1 + rand() % 99;
		tab2[i] = 1 + rand() % 99;
		tab3[i] = 1 + rand() % 99;
	}

	for (int i = 1; i <= size; i++)    tab4[i] = 1 + rand() % 99;

	cout << "Unsorted arrays:" << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab2[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab3[i] << " ";
	}
	cout << endl << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << tab4[i] << " ";
	}
	cout << endl << endl;

	bubblesort(tab);
	quicksort(tab2, 0, size - 1);
	mergesort(tab3, 0, size - 1);
	heapsort(tab4);


	cout << "Sorted arrays:" << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab2[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i<size; i++)
	{
		cout << tab3[i] << " ";
	}
	cout << endl << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << tab4[i] << " ";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}