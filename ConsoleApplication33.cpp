//Определить структурный тип, описывающий музыкальные альбомы (название
//альбома, исполнитель, стиль, год выпуска, длительность, стоимость, название и
//продолжительность композиций альбома). Заполнить структурный массив 20-ю
//записями. Переписать из исходного массива в другой массив, информацию только о
//тех альбомах, стиль которых рок или инди-рок. Затем новый массив отсортировать
//по исполнителю по алфавиту. Вывести все данные по конкретному альбому.
//Вывести 5 самых популярных альбомов. Реализовать функцию изменения альбома.
//В отдельный массив поместить все альбомы, имеющие более 7 композиций.
//Реализовать вывод отфильтрованных данных в виде оберточной функции.
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int SIZE = 20;
const int MAX_TRACKS = 10;

enum Genre {
    ROCK,
    INDIE_ROCK,
    HIP_HOP,
    POP
};

struct track {
    char title[30];
    int duration;
};

struct album {
    char name[30];
    char artist[30];
    Genre genre;
    int year;
    int duration;
    double price;
    int track_count;
    int flag;
    track songs[MAX_TRACKS];
};

const char* genreToStr(Genre g) {
    switch (g) {
        case ROCK: return "Рок";
        case INDIE_ROCK: return "Инди-рок";
        case HIP_HOP: return "Хип-хоп";
        case POP: return "Поп";
    }
    return "";
}

album* init() {
    album* a = new album[SIZE];

    a[0] = { "HybridTheory", "LinkinPark", ROCK, 2000, 37, 15.0, 3, 0,
        { {"Papercut",3}, {"InTheEnd",4}, {"Crawling",3} } };

    a[1] = { "Nevermind", "Nirvana", ROCK, 1991, 42, 20.0, 3, 0,
        { {"SmellsLikeTeenSpirit",5}, {"ComeAsYouAre",3}, {"Lithium",4} } };

    a[2] = { "AM", "ArcticMonkeys", INDIE_ROCK, 2013, 41, 18.0, 3, 0,
        { {"DoIWannaKnow",4}, {"RUMine",3}, {"Arabella",3} } };

    a[3] = { "DAMN", "KendrickLamar", HIP_HOP, 2017, 39, 22.0, 3, 0,
        { {"HUMBLE",3}, {"DNA",3}, {"LOYALTY",3} } };

    a[4] = { "TheWall", "PinkFloyd", ROCK, 1979, 81, 25.0, 3, 0,
        { {"AnotherBrick",3}, {"ComfortablyNumb",6}, {"HeyYou",4} } };

    a[5] = { "Currents", "TameImpala", INDIE_ROCK, 2015, 51, 23.0, 3, 0,
        { {"TheLessIKnow",3}, {"LetItHappen",7}, {"Eventually",5} } };

    a[6] = { "Graduation", "KanyeWest", HIP_HOP, 2007, 51, 21.0, 3, 0,
        { {"Stronger",5}, {"FlashingLights",4}, {"Homecoming",3} } };

    a[7] = { "AbbeyRoad", "TheBeatles", ROCK, 1969, 47, 30.0, 3, 0,
        { {"ComeTogether",4}, {"Something",3}, {"HereComesTheSun",3} } };

    a[8] = { "FineLine", "HarryStyles", POP, 2019, 46, 19.0, 3, 0,
        { {"AdoreYou",3}, {"WatermelonSugar",3}, {"Falling",4} } };

    a[9] = { "TestAlbum", "TestArtist", ROCK, 2020, 40, 10.0, 2, 0,
        { {"Song1",3}, {"Song2",4} } };

    for (int i = 10; i < SIZE; i++) {
        a[i] = { "Default", "Artist", ROCK, 2000+i, 40, 10.0, 2, 0,
            { {"Song1",3}, {"Song2",4} } };
    }

    return a;
}

void printAlbum(album a) {
    cout << "Название: " << a.name << endl;
    cout << "Исполнитель: " << a.artist << endl;
    cout << "Жанр: " << genreToStr(a.genre) << endl;
    cout << "Год: " << a.year << endl;
    cout << "Количество треков: " << a.track_count << endl;
    cout << "----------------------\n";
}

void printArray(album a[], int n) {
    for (int i = 0; i < n; i++) {
        printAlbum(a[i]);
    }
}

int filter(album src[], album dst[]) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (src[i].genre == ROCK || src[i].genre == INDIE_ROCK) {
            dst[k++] = src[i];
        }
    }
    return k;
}

void bubbleSort(album a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(a[j].artist, a[j + 1].artist) > 0) {
                album temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int moreThan7(album src[], album dst[]) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (src[i].track_count > 7) {
            dst[k++] = src[i];
        }
    }
    return k;
}

void top5(album a[]) {
    album temp[SIZE];

    for (int i = 0; i < SIZE; i++) {
        temp[i] = a[i];
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (temp[j].price < temp[j + 1].price) {
                album t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    cout << "\nТоп 5 самых популярных альбомов:\n";
    for (int i = 0; i < 5; i++) {
        printAlbum(temp[i]);
    }
}

void editAlbum(album &a) {
    strcpy(a.name, "Отредактировано");
    strcpy(a.artist, "НовыйИсполнитель");
}

void readFromText(album a[], int n, const char* filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    char artist[30];
    int value;

    while (file >> artist >> value) {
        for (int i = 0; i < n; i++) {
            if (strcmp(a[i].artist, artist) == 0) {
                a[i].flag = value;
            }
        }
    }

    file.close();
}

void writeBinary(album a[], int n, const char* filename) {
    ofstream file(filename, ios::binary);

    if (!file) {
        cout << "Ошибка записи файла!\n";
        return;
    }

    file.write((char*)a, sizeof(album) * n);
    file.close();
}

void readBinary(album a[], int n, const char* filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "Ошибка чтения файла!\n";
        return;
    }

    file.read((char*)a, sizeof(album) * n);
    file.close();
}

int main() {
    album* albums = init();

    readFromText(albums, SIZE, "data.txt");

    writeBinary(albums, SIZE, "albums.dat");

    album copy[SIZE];
    readBinary(copy, SIZE, "albums.dat");

    cout << "\nДанные из бинарного файла:\n";
    printArray(copy, SIZE);

    album filtered[SIZE];
    album many[SIZE];

    int fCount = filter(albums, filtered);
    bubbleSort(filtered, fCount);

    cout << "\nОтфильтрованные альбомы (рок и инди-рок):\n";
    printArray(filtered, fCount);

    int mCount = moreThan7(albums, many);

    cout << "\nАльбомы с более чем 7 треками:\n";
    printArray(many, mCount);

    top5(albums);

    editAlbum(albums[0]);

    cout << "\nОтредактированный альбом:\n";
    printAlbum(albums[0]);

    delete[] albums;
    return 0;
}



