# Bible Manuscript Search Program

This C++ program allows users to search for specific words in Bible manuscripts written in **Greek** or **Hebrew**. By providing a file containing Bible verses and another file containing words to search for, the program will find and display the verses that contain the given words. The program is designed to handle non-ASCII characters by setting the console to **UTF-8**, making it suitable for searching ancient manuscripts in original languages.

## Features

- **Search in Bible Manuscripts**: Easily search for Greek or Hebrew words in a file containing Bible verses.
- **UTF-8 Console Support**: The program configures the console for UTF-8 encoding, allowing it to handle characters from ancient languages like Greek and Hebrew.
- **File-Based Input**: Load Bible verses and words to search for from external text files, allowing for flexibility in data sources.
- **Word Search**: Finds and displays all verses that contain each word from the search list.
- **Simple Output**: Lists all the matching verses for each word, making it easy to see where each term appears in the manuscript.

## Technologies Used

- **C++**: The core programming language used to implement the search functionality.
- **UTF-8 Encoding**: Ensures support for non-Latin characters such as Greek and Hebrew.
- **File I/O**: The program reads input from text files, allowing for easy data input and management.

## Installation and Setup

1. **Clone the repository** or download the source files to your local machine.

2. **Prepare Your Input Files**:
   - Create a text file with Bible verses in Greek or Hebrew, with each verse on a new line (e.g., `bible_verses.txt`).
   - Create another text file with the Greek or Hebrew words you want to search for, each on a new line (e.g., `search_words.txt`).

3. **Compile the Program** using a C++ compiler like `g++`. In a terminal or command prompt, run the following command:

```bash
g++ -o bible_search bible_search.cpp
```

4. **Run the Program**:

```bash
./bible_search
```

5. When prompted, enter the filenames for your Bible verses and search words.

```bash
Enter the filename of the Bible verses: bible_verses.txt
Enter the filename of the words to search for: search_words.txt
```

6. The program will search the Bible verses for each word and display the results.

## How It Works

1. **UTF-8 Setup**: The program ensures the console can display non-ASCII characters like Greek or Hebrew by setting the console output to UTF-8.
   
2. **Input Handling**: Bible verses and search words are read from files and stored in separate vectors.

3. **Search Logic**: The program iterates through each verse and checks if any of the provided words are found. If a word is found, the verse is stored and later displayed.

4. **Output**: For each word, the program outputs the verses where the word appears. If no verses are found for a word, it indicates that no matches were found.

## Example

If your Bible verses file (`bible_verses.txt`) contains the following:

```
Ἐν ἀρχῇ ἦν ὁ λόγος
Καὶ ὁ λόγος ἦν πρὸς τὸν Θεόν
```

And your search words file (`search_words.txt`) contains:

```
λόγος
Θεόν
```

The output will be:

```
Verses containing the word "λόγος":
Ἐν ἀρχῇ ἦν ὁ λόγος
Καὶ ὁ λόγος ἦν πρὸς τὸν Θεόν

Verses containing the word "Θεόν":
Καὶ ὁ λόγος ἦν πρὸς τὸν Θεόν
```

## Debugging

The program includes debugging outputs that display the number of verses and search words loaded. It also prints the first verse and search word to verify that the data is being loaded correctly.

## Potential Future Enhancements

- **Regular Expressions**: Add support for more complex search patterns using regular expressions.
- **Search in Multiple Languages**: Allow users to search for words in different languages simultaneously.
- **Search for Word Stems**: Add functionality to search for word stems, especially for highly inflected languages like Greek and Hebrew.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

This program provides an efficient way to search Bible manuscripts for Greek or Hebrew words, making it useful for biblical scholars, linguists, and students studying ancient languages.
