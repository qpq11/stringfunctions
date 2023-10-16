// Сортировка включением
void insert_sort(int*p, int n)
{	
	int i, j;	
	int t;
	for(i = 1; i < count; ++i)
	{	
		t = p[a];
		for(j=i-1; (j>=0)&&(t<p[j]); j--)
			p[j+1] = p[j];
		p[j+1] = t;
	}
}

// Сортировка вставками
void select_sort(int*p, int n)
{
	int i, j, k;
	int exchange;
	int t;
	for(i=0; i<n-1; ++i)
	{
		exchange = 0; k = i; t = p[i];
		for(j=i+1; j<n; ++j)
		{
			if(p[j] < t)
			{
				k = j;
				t =p[j];
				exchange = 1;
			}
		}
		if(exchange)
		{
			p[k] = p[i];
			p[i] = t;
		}
	}
}

// Сортировка обменная (пузырек)
void bubble_sort(int*p, int n)
{
	int i,j;
	int t;
	for(i=1; i<n; ++i)
	{
		for(j=n-1; j>=i; --j)
		{
		if(p[j-1]>p[j])
			{
			t = p[j-1];
			p[j-1] = p[j];
			p[j] = t;
			}
		}
	}
}


// Пирамидальная сортировка
#include <stdio.h>
#include <stdlib.h>

void siftDown(int* numbers, int root, int bottom);
void heapSort(int* numbers, int array_size);

int main()
{
    int a[10];
    // Заполнение массива случайными числами
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 20 - 10;
    // Вывод элементов массива до сортировки
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    heapSort(a, 10); // вызов функции сортировки
    // Вывод элементов массива после сортировки
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
        // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // иначе
            done = 1; // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int* numbers, int array_size)
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

// Последовательный поиск
#include <stdio.h>

int sequential_search(int*p, int size, int key);

void main()
{	int array[10] = {2,5,1,7,3,8,0,4,6,9};
	int key, r;
	printf("Введите целое число: ");
	scanf("%d", &key);
	if((r = sequential_search(array, 10, key)) == -1)
		printf("Этого числа нет в массиве");
	else
		printf("Это число есть массиве на %d позиции", r);
}

int sequential_search(int *p, int size, int key)
{
	for(int i = 0; i < size; ++i)
		if(p[i] == key)
			return i;
	return -1;
}

// Быстрая сортировка Хоара
#include <stdio.h>

void quicksort(int* mas, int size);

int main() {
    int ar[10] = { 3, 7, 2, 9, 1, 8, 4, 5, 0, 6 };
    for (int i = 0; i < 10; ++i)
        printf("%i ", ar[i]);
    printf("\n");
    quicksort(ar, 10);
    for (int i = 0; i < 10; ++i)
        printf("%i ", ar[i]);
    return 0;
}
void quicksort(int* mas, int size)
{
    // Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    // Опорный элемент массива
    int mid = mas[size / 2];

    // Делим массив
    do {
        // Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        // В левой части массива пропускаем (оставляем на месте) элементы,
        // которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        // В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    // Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {        // Сортируем "левый кусок"
        quicksort(mas, j + 1);
    }
    if (i < size) {      // Сртируем "правый кусок"
        quicksort(&mas[i], size - i);
    }
}

// Двоичный поиск
#include <stdio.h>

int binary_search(int*p, int n, int key);

void main()
{	
	int array[10] = {0,1,2,3,4,5,6,7,8,9}; 
	int key, r;
	printf("Введите целое число: "); 
	scanf("%d", &key);
	if((r = binary_search(array, 10, key)) == -1)
		printf("Числа нет в массиве");
	else
		printf("Число есть массиве на %d позиции", r);
}

	int binary_search(int*p, int n, int key)
	{	
		int low, high, mid;
		low = 0; 
		high = n – 1;
		while(low <= high) 
		{
			mid = (low + high)/2;
			if(key < p[mid]) 
				high = mid – 1;
			else if(key > p[mid]) 
			low = mid + 1;
			else 
			return mid; 
		}
	return -1;
	}
