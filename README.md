# Users Database Project

**Users Database Project** to aplikacja napisana w języku C, która umożliwia zarządzanie bazą danych użytkowników. Projekt demonstruje podstawowe operacje na danych, takie jak dodawanie, usuwanie, edycja oraz wyszukiwanie użytkowników w bazie danych.

## Spis treści

- [Wymagania](#wymagania)
- [Instalacja](#instalacja)
- [Użycie](#użycie)
- [Struktura projektu](#struktura-projektu)
- [Contributing](#contributing)
- [Licencja](#licencja)
- [Autor](#autor)

## Wymagania

Aby skompilować i uruchomić ten projekt, potrzebujesz:

- Kompilatora języka C (np. GCC)
- Systemu operacyjnego zgodnego z POSIX (np. Linux, macOS)

## Instalacja

1. Sklonuj repozytorium na swój lokalny komputer:

   ```bash
   git clone https://github.com/TheNuRii/users-database-project.git
   ```


2. Przejdź do katalogu projektu:

   ```bash
   cd users-database-project
   ```


3. Skompiluj projekt za pomocą `Makefile`:

   ```bash
   make
   ```


   Polecenie to wygeneruje plik wykonywalny o nazwie `users-database`.

## Użycie

Aby uruchomić aplikację, wykonaj:


```bash
./users-database
```


Po uruchomieniu aplikacji dostępne są następujące opcje:

1. Dodaj nowego użytkownika
2. Usuń użytkownika
3. Edytuj dane użytkownika
4. Wyświetl listę użytkowników
5. Wyszukaj użytkownika
6. Zakończ program

Postępuj zgodnie z instrukcjami wyświetlanymi na ekranie, aby wykonywać poszczególne operacje.

## Struktura projektu

Projekt składa się z następujących katalogów i plików:

- `src/`: Zawiera kod źródłowy aplikacji.
- `include/`: Zawiera pliki nagłówkowe.
- `bin/`: Katalog przeznaczony na pliki wykonywalne (po kompilacji).
- `.vscode/`: Ustawienia środowiska Visual Studio Code.
- `.gitignore`: Plik określający, które pliki/katalogi powinny być ignorowane przez Git.
- `Makefile`: Skrypt do automatyzacji procesu kompilacji projektu.
- `README.md`: Niniejszy plik z informacjami o projekcie.

## Contributing

Jeśli chcesz przyczynić się do rozwoju tego projektu:

1. Sforkuj to repozytorium.
2. Utwórz nową gałąź (`git checkout -b feature/nazwa-funkcji`).
3. Wprowadź swoje zmiany i zatwierdź je (`git commit -m 'Dodano nową funkcję'`).
4. Wypchnij zmiany do swojego forka (`git push origin feature/nazwa-funkcji`).
5. Utwórz Pull Request, opisując wprowadzone zmiany.

Wszelkie sugestie i uwagi są mile widziane!

## Licencja

Ten projekt jest udostępniany na licencji MIT. Szczegółowe informacje znajdują się w pliku `LICENSE`.

## Autor

Projekt został stworzony przez [TheNuRii](https://github.com/TheNuRii).

---

Powyższy plik README dostarcza kompleksowych informacji na temat projektu, jego funkcjonalności, sposobu instalacji oraz użytkowania. Dzięki takiej strukturze, inni programiści oraz użytkownicy będą mogli łatwo zrozumieć cel projektu i w razie potrzeby przyczynić się do jego rozwoju. 