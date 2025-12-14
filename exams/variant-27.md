# Варіант 27

## Завдання 1
### Сума цифр числа (while)
Завдання: Ввести ціле невід'ємне число та знайти суму його цифр.

- Приклад вводу: `9025`
- Приклад виводу: `Сума цифр: 16`

---

## Завдання 2
### Вивід чисел із заданою цифрою
Реалізуйте `void PrintWithDigit(const int& limit, const int& digit, const int& max_count);`. Перебирайте числа від `0` до `limit`. Якщо число не містить цифру `digit`, пропускайте `continue`. Друкуйте знайдені значення. Коли надруковано `max_count` чисел — `break`.

Ввід:
```
80
3
5
```
Вивід:
```
Matches: 3 13 23 30 31
```

---

## Завдання 3
### Середнє арифметичне
Створіть функцію `double Average(const int* data, size_t length);`, яка обчислює середнє арифметичне елементів масиву.

Приклад вводу:
```
4
10 20 30 40
```
Приклад виводу:
```
Середнє: 25.0
```

---

## Завдання 4
### Клас Rectangle з конструктором
Реалізуйте клас `Rectangle` з приватними полями `width` та `height` типу `double`. Додайте:
- Конструктор `Rectangle(double w, double h)` — ініціалізація розмірів
- `double GetWidth() const` та `double GetHeight() const` — отримання розмірів
- `double CalculateArea() const` — обчислення площі
- `double CalculatePerimeter() const` — обчислення периметру

Приклад використання:
```cpp
Rectangle rect(5.0, 3.0);
std::cout << "Площа: " << rect.CalculateArea() << std::endl;
std::cout << "Периметр: " << rect.CalculatePerimeter() << std::endl;
```
Приклад виводу:
```
Площа: 15.0
Периметр: 16.0
```
