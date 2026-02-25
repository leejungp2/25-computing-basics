#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Song {
    char *title;       
    char *artist;      
    struct Song *next; 
} Song;


Song* CreateSong(char *title, char *artist) {
    // 메모리 할당
    Song *newSong = (Song*)malloc(sizeof(Song));
    if (!newSong) return NULL;

    // 문자열 복사 (heap에 저장)
    newSong->title = strdup(title);
    newSong->artist = strdup(artist);
    newSong->next = NULL;

    return newSong;
}



void AddSong(Song **head, char *title, char *artist) {
    Song *newSong = CreateSong(title, artist);

    // 리스트가 비어 있으면 head가 새 노드
    if (*head == NULL) {
        *head = newSong;
        return;
    }

    // 마지막 노드까지 이동
    Song *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newSong;
}



void RemoveSong(Song **head, char *title) {
    if (*head == NULL) return;

    Song *current = *head;
    Song *prev = NULL;

    // 첫 노드가 삭제 대상인 경우
    if (strcmp(current->title, title) == 0) {
        *head = current->next;
        free(current->title);
        free(current->artist);
        free(current);
        return;
    }

    // 중간 이후 노드 탐색
    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    // 못 찾은 경우
    if (current == NULL) return;

    // 연결 끊고 free
    prev->next = current->next;
    free(current->title);
    free(current->artist);
    free(current);
}


void ClearPlaylist(Song **head) {
    Song *current = *head;
    Song *next;

    while (current != NULL) {
        next = current->next;
        free(current->title);
        free(current->artist);
        free(current);
        current = next;
    }

    *head = NULL;
}

//Print the current playlist(DO NOT modify)
void PrintPlaylist(Song *head) {
    printf("\n--- Current Playlist ---\n");
    if (head == NULL) {
        printf("(Empty)\n");
        return;
    }
    
    Song *current = head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s - %s\n", index++, current->title, current->artist);
        current = current->next;
    }
    printf("------------------------\n");
}

int main() {
    //You can modify this part to test your code
    Song *playlist = NULL; 

    AddSong(&playlist, "Jaded", "Aerosmith");
    AddSong(&playlist, "Somebody to Love", "Queen");
    AddSong(&playlist, "Whatever", "Oasis");
    
    PrintPlaylist(playlist);


    RemoveSong(&playlist, "Somebody to Love");
    PrintPlaylist(playlist);

    ClearPlaylist(&playlist);
    PrintPlaylist(playlist);

    return 0;
}