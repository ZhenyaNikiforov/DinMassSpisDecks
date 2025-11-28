/*-- Задание на добавление в изменяемый
динамический массив (задача №2 в домашней работе) --*/

#include <iostream>
#include <Windows.h>
using namespace std;

void print_dynamic_array(int *arr, int logical_size, int actual_size) // подпрограмма выведения динамического массива;
{
  SetConsoleOutputCP(CP_UTF8);     // кириллич. симв.;
  cout << "Динамический массив: "; // Объявление;

  for (int i = 0; i < actual_size; ++i) // пробегаем фактический размер массива;
  {
    if (i < logical_size) // если текущий элемент меньше логического размера, то...;
    {
      cout << arr[i] << " "; //...отображаем этот элемент;
    }
    else // если цикл вышел из логического размера, то...;
    {
      cout << "_ "; //...отображаем нижнее подчёркивание;
    }
  };

  cout << endl; // сбрасываем строчку;
  return;       // прерываем подпрограмму;
};

int main() // основная подпрограмма;
{
  SetConsoleOutputCP(CP_UTF8); // кириллич. симв.;
  int factumSize = 0;          // задаём фактический размер;
  int logicSize = 0;           // задаём логический размер;
  cout << "Вводим фактич. размер: ";
  cin >> factumSize;
  cout << "Вводим логич. размер: ";
  cin >> logicSize;
  if (logicSize > factumSize) // если логич. размер больше фактич., то...;
  {
    cout << "Ошибка! Логический размер не может быть больше фактического." << endl; //...выводим сообщение,;
    return 0;                                                                       // прерываем подпрограмму;
  };
  int *dinamicNumbers = new int[factumSize]; // создаём массив для чисел;
  for (int i = 0; i < logicSize; ++i)        // пробегаемся по логической длине;
  {
    cout << "Вводим значение динамич. мас-в [" << i << "]: "; // даём сообщение;
    cin >> dinamicNumbers[i];                                 // вводим значение в текущ. элемент;
  };

  print_dynamic_array(dinamicNumbers, logicSize, factumSize); // показываем получившийся массив;
  int *timeArray;                                             // создаём указатель на временный массив;

  while (true) // циклическое звено подпрограммы;
  {
    int newSignum = 0;                  // новое число;
    cout << "Добавляем новый символ: "; // сообщение о нём;
    cin >> newSignum;                   // вводим новое число в переменную;
    if (newSignum == 0)                 // если новое число =0, то...;
    {
      cout << "Прерывание программы." << endl;                    //...сообщаем о прерывании цикла, ...;
      print_dynamic_array(dinamicNumbers, logicSize, factumSize); //...показываем массив, ...;
      break;                                                      //...прерываем цикл.;
    };
    if (logicSize == factumSize) // если логич. размер стал равен фактич. разм-ру, то...;
    {
      factumSize *= 2;                    //...удваиваем фактич. размер, ...;
      timeArray = new int[factumSize];    //...во временный указатель вносим массив удвой. разм-ра, ...;
      for (int i = 0; i < logicSize; ++i) // ... пробегаемся по логич. разм-ру, ...;
      {
        timeArray[i] = dinamicNumbers[i]; //... копируем старый массив во временный, ...;
      };
      delete[] dinamicNumbers;    //...очищаем память где был старый массив...;
      dinamicNumbers = timeArray; //...указатель старого массива переносим на временный;
    };
    dinamicNumbers[logicSize] = newSignum;                      // добавляем новый знак в массив;
    logicSize++;                                                // увеличиваем логич. размер на 1;
    print_dynamic_array(dinamicNumbers, logicSize, factumSize); // показываем получившийся массив;
  }; // дно цикла приращения массива;

  delete[] dinamicNumbers; // освобождаем память от старого массива;
  delete[] timeArray;      // освобождаем память от временного массива;

  return 0; // прерываем подпрограмму;
}