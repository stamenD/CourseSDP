TODO: ITERATION LLIST

Задача 1
---
Да се реалзиира клас Range, който позволява взимането на произволна поредица от елементи от списък (едно или двусвързан).
Конструктори:
  Range(LList<T>, int startIdx, int endIdx)
  Range(DLList<T>, int startIdx, int endIdx)
  взимат частта от списъка от между индексите startIdx и endIdx включително.

  Range(LList<T>, elem_link1<T>* startElement, int count)
  Range(DLList<T>, elem_link2<T>* startElement, int count)
  взимат частта от списъка с начало startElement и брой елемент count. Ако count е отрицателно число се взимат предходните елементи.

Ако елементите в списъка не са достатъчни, да се лимитира частта до съществуващи такива. Например:
Ако имаме списък с 5 елемента, а вземе Range(list, 0, 10), трябва да са достъпни елементите с индекси [0, 4].

Реализирайте следните функции:
  int size() - връща броят елементи в поредицата
  Iterator<T> iterator() - връща итератор за елементите в поредицата

Интерфейс за класа на итератора:
Iterator<T>
  bool hasNext()
  T next()



Задача 2
---
BinTree
 -> balanced
 -> perfect balanced
 -> levels

 Балансирано двоично дърво – двоично дърво, в което никое листо не е на "много по-голяма" дълбочина от всяко друго листо. Дефиницията на "много по-голяма" зависи от конкретната балансираща схема.
Идеално балансирано двоично дърво – двоично дърво, в което разликата в броя на върховете на лявото и дясното поддърво на всеки от върховете е най-много единица.

Без да навлизаме в детайли ще споменем, че ако дадено двоично дърво е балансирано, дори и да не е идеално балансирано, то операциите за добавяне, търсене и изтриване на елемент в него са с логаритмична сложност дори и в най-лошия случай
