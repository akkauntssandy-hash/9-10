#include <iostream>
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

    a[0] = { "HybridTheory", "LinkinPark", ROCK, 2000, 37, 15.0, 3,
        { {"Papercut",3}, {"InTheEnd",4}, {"Crawling",3} } };

    a[1] = { "Nevermind", "Nirvana", ROCK, 1991, 42, 20.0, 3,
        { {"SmellsLikeTeenSpirit",5}, {"ComeAsYouAre",3}, {"Lithium",4} } };

    a[2] = { "AM", "ArcticMonkeys", INDIE_ROCK, 2013, 41, 18.0, 3,
        { {"DoIWannaKnow",4}, {"RUMine",3}, {"Arabella",3} } };

    a[3] = { "DAMN", "KendrickLamar", HIP_HOP, 2017, 39, 22.0, 3,
        { {"HUMBLE",3}, {"DNA",3}, {"LOYALTY",3} } };

    a[4] = { "TheWall", "PinkFloyd", ROCK, 1979, 81, 25.0, 3,
        { {"AnotherBrick",3}, {"ComfortablyNumb",6}, {"HeyYou",4} } };

    a[5] = { "Currents", "TameImpala", INDIE_ROCK, 2015, 51, 23.0, 3,
        { {"TheLessIKnow",3}, {"LetItHappen",7}, {"Eventually",5} } };

    a[6] = { "Graduation", "KanyeWest", HIP_HOP, 2007, 51, 21.0, 3,
        { {"Stronger",5}, {"FlashingLights",4}, {"Homecoming",3} } };

    a[7] = { "AbbeyRoad", "TheBeatles", ROCK, 1969, 47, 30.0, 3,
        { {"ComeTogether",4}, {"Something",3}, {"HereComesTheSun",3} } };

    a[8] = { "FineLine", "HarryStyles", POP, 2019, 46, 19.0, 3,
        { {"AdoreYou",3}, {"WatermelonSugar",3}, {"Falling",4} } };

    a[9] = { "TestAlbum", "TestArtist", ROCK, 2020, 40, 10.0, 2,
        { {"Song1",3}, {"Song2",4} } };

    for (int i = 10; i < SIZE; i++) {
        a[i] = { "Default", "Artist", ROCK, 2000+i, 40, 10.0, 2,
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

// фильтр
int filter(album src[], album dst[]) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (src[i].genre == ROCK || src[i].genre == INDIE_ROCK) {
            dst[k++] = src[i];
        }
    }
    return k;
}

// сортировка пузырьком
void bubbleSort(album a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(a[j].artist, a[j + 1].artist) > 0) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// топ 5
void top5(album a[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (a[j].price < a[j + 1].price) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    cout << "\nТоп 5 самых популярных альбомов:\n";
    for (int i = 0; i < 5; i++) {
        printAlbum(a[i]);
    }
}

// 7 треков
int moreThan7(album src[], album dst[]) {
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        if (src[i].track_count > 7) {
            dst[k++] = src[i];
        }
    }
    return k;
}

// редактирование
void editAlbum(album &a) {
    strcpy(a.name, "Отредактировано");
    strcpy(a.artist, "НовыйИсполнитель");
}

int main() {
    album* albums = init();
    album filtered[SIZE];
    album many[SIZE];

    int fCount = filter(albums, filtered);
    bubbleSort(filtered, fCount);

    cout << "\nОтфильтрованные альбомы (рок и инди-рок):\n";
    printArray(filtered, fCount);

    int mCount = moreThan7(albums, many);

    cout << "\nАльбомы с более чем 7 треками:\n";
    printArray(many, mCount);

    cout << "\nТоп 5 самых популярных альбомов:\n";
    top5(albums);

    editAlbum(albums[0]);

    cout << "\nОтредактированный альбом:\n";
    printAlbum(albums[0]);

    delete[] albums;
    return 0;
}
