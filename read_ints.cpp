// read_ints.cpp
// Чтение последовательности целых чисел неизвестного размера в динамический массив,
// организуемый средствами стандартной библиотеки C (malloc, realloc, free).
#include <cstdlib>
#include <iostream>
using namespace std;

// Возвращает число прочитанных чисел.
size_t read_ints(int **ints, size_t max_size = 1 << 20)
{
  size_t cap = max_size < 16 ? max_size : 16; // capacity
  auto a = (int*)malloc(cap * sizeof(int));
  *ints = a;

  if (!a)
    return 0;

  size_t i = 0; // size
  for (int x;; ++i)
  {
    if (i == cap)
    {
      if (cap == max_size)
        break;

      cap *= 2;
      if (max_size < cap)
        cap = max_size;

      if (auto r = (int*)realloc(a, cap * sizeof(int)))
        a = r;
      else
        break;
    }

    if (cin >> x)
      a[i] = x;
    else
      break;
  }

  return i;
}

/////////////////////////////////////////////////////////////////////
int main()
{
  while (true)
  {
    size_t mxs = 0;
    cin >> mxs;

    int *a = nullptr;
    size_t sz = read_ints(&a, mxs);
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cin.sync();

    for (size_t i = 0; i < sz; ++i)
      cout << a[i] << '\n';
    free(a);
  }
  
  return 0;
}
