# Простой скрипт проверки быстродействия PHP

Работает со всеми версиями ПХП: от 4.4 до 7.1

## Зависимости

Необходимы модули для php:

- pcre
- hash
- mbstring
- json

Обычно они уже установлены или "вкомпилированны" в php.

Проверить наличие:

- в консоли `php -m`
- или через вывод функции `phpinfo()`

## ChangeLog

@ 2017-05-18, v1.0.17

 * Попытка укладываться в max_execution_time
   Т.к. зависимость от hardware не линейная - много hack-ов.
   Может не всегда срабатывать.

@ 2017-05-18, v1.0.16

 * Сделали поиск доступных алгоритмов хеширования для crypt()
 * По-умолчанию считаем, что доступен для всех MD5

@ 2017-05-17, v1.0.15

 * Поправили работу скрипта с php-7.x - больше ограничений по памяти
 * Добавили вывод используемой памяти (@ryr)

@ 2017-05-06, v1.0.14

 * Изменили работу скрипта, если доступно памяти менее 256Мб

@ 2017-05-06, v1.0.13

 * Поправили немного code-style (@ryr)
 * Добавили больше данных в тесты сериализации

@ 2017-04-21, v1.0.12

 * Правильная конвертация значений в единицы SI.
 * Считаем операции в секунду на МГц.
 * Обновил вывод - добавил заголовок столбцам

@ 2017-04-20, v1.0.11

 * Нагружаем процессор, чтобы определить MHz только если разница между
   значениями 'cpu MHz' и 'bogomips/2' большая.

@ 2017-04-20, v1.0.10

 * Тесты массивов теперь всегда включены, они больше не съедают много памяти
 * Добавлено определение CPU на Linux-системах, добавлен вывод операций на МГц
 * В выводе uname осталена только необходимая для сравнения информация
 * Обновлен README

@ 2017-04-06, v1.0.9

 * Поправлен подсчет операций в секунду для теста массивов

@ 2017-04-06, v1.0.8

 * Тесты, которых нет в php-4.4 вынесены в отдельный подключаемый файл

@ 2017-04-06, v1.0.7

 * Изменены названия функций-тестов для сортировки перед запуском
 * Обновлено форматирование вывода результатов тестов
 * Добавлены и обновлены тесты:
   - образение к определенныи и неопределенным переменным/ключам массива
   - исключения (exceptions)
   - к хешированию добавлен тест crypt
   - тест массивов разбит на три уровня - время выполнения то же, памяти занимает меньше

@ 2015-07-16, v1.0.6

 * Добавлены тесты: preg & serialize

@ 2015-07-02, v1.0.5

 * Добавлен тест простейшего копирования строк

@ 2015-07-02, v1.0.4

 * Добавлено увеличение лимита по памяти и времени выполнения

@ 2015-07-02, v1.0.3

 * Исправлено определение доступных функций, сделан пропуск тестов для них

@ 2015-07-02, v1.0.2

 * Добавлено еще больше функций, теперь требуется наличие mbstring и json модулей
 * Потребление памяти увеличено из-за тестирования массивов - нужно более 1Гб

@ 2015-07-01, v1.0.1

 * Добавлен вывод потребления памяти
 * Добавлены новые функции, увеличен размер проверочной строки

## Пример вывода скрпита

```
<pre>
-------------------------------------------------------------------------------------------
|                                  PHP BENCHMARK SCRIPT                                   |
-------------------------------------------------------------------------------------------
Start:              : 2017-05-18 06:48:07
Server:             : Linux/4.4.0-78-generic x86_64
Platform:           : Linux
CPU:                :
              model : Intel(R) Core(TM) i5-6600K CPU @ 3.50GHz
              cores : 4
                MHz : 3766.601MHz
Memory              : 256 Mb available
Benchmark version:  : 1.0.17
PHP version:        : 7.0.14-Ubuntu/16.04-SergeyD/9.3.1
Max execution time: : 600 sec.
Crypt hash algo:    : MD5
-------------------------------------------------------------------------------------------
TEST NAME                       :     SECONDS |       OP/SEC |      OP/SEC/MHz |    MEMORY
-------------------------------------------------------------------------------------------
01_math                         :   3.091 sec | 452.99 kOp/s | 120.27  Ops/MHz |      2 Mb
02_string_concat                :   0.217 sec |  35.41 MOp/s |   9.40 kOps/MHz | 128.84 Mb
03_string_simple_functions      :   1.764 sec | 736.92 kOp/s | 195.65  Ops/MHz |      4 Mb
04_string_multibyte             :   4.052 sec |  32.08 kOp/s |   8.52  Ops/MHz |      4 Mb
05_string_manipulation          :   2.393 sec | 543.34 kOp/s | 144.25  Ops/MHz |      4 Mb
06_regex                        :   1.942 sec | 669.42 kOp/s | 177.72  Ops/MHz |      4 Mb
07_1_hashing                    :   2.049 sec | 634.37 kOp/s | 168.42  Ops/MHz |      4 Mb
07_2_crypt                      :   5.897 sec |   1.70 kOp/s |   0.45  Ops/MHz |      4 Mb
08_json_encode                  :   1.596 sec | 814.62 kOp/s | 216.27  Ops/MHz |      4 Mb
09_json_decode                  :   1.944 sec | 668.89 kOp/s | 177.59  Ops/MHz |      4 Mb
10_serialize                    :   1.208 sec |   1.08 MOp/s | 285.69  Ops/MHz |      4 Mb
11_unserialize                  :   1.747 sec | 744.11 kOp/s | 197.55  Ops/MHz |      4 Mb
12_array_fill                   :   1.242 sec |  38.66 MOp/s |  10.26 kOps/MHz |     10 Mb
13_array_unset                  :   1.802 sec |  26.64 MOp/s |   7.07 kOps/MHz |      4 Mb
14_loops                        :   1.813 sec | 209.59 MOp/s |  55.65 kOps/MHz |      4 Mb
15_loop_ifelse                  :   1.299 sec |  69.29 MOp/s |  18.40 kOps/MHz |      4 Mb
16_loop_ternary                 :   3.191 sec |  28.20 MOp/s |   7.49 kOps/MHz |      4 Mb
17_1_loop_defined_access        :   0.574 sec |  34.85 MOp/s |   9.25 kOps/MHz |      4 Mb
17_2_loop_undefined_access      :   3.810 sec |   5.25 MOp/s |   1.39 kOps/MHz |      4 Mb
18_loop_exceptiontrycatch       :   2.135 sec |   1.87 MOp/s | 497.52  Ops/MHz |      4 Mb
-------------------------------------------------------------------------------------------
Total time:                     : 43.765 sec.
Current memory usage:           : 512.82 kb.
Peak memory usage:              : 125.34 Mb.
</pre>
```
