*__Скачивание и запуск программы__*

- Скачиваем репозиторий:
```
git clone https://github.com/DmitryKrizhik/WordCounter
```
- Для запуска программы с подсчётом слов в уже созданном текстовом файле:
```
g++ -o wordcounterwithexternalfile wordcounterwithexternalfile.cpp
./wordcounterwithexternalfile 
```
- Для запуска программы с подсчётом слов в текстовом файле, созданном в процессе выполнения :
```
g++ -o wordcounterwithinnerfile wordcounterwithinnerfile.cpp 
./wordcounterwithinnerfile 
```
