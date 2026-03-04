/*
 * File: main.c
 * Description: Program to demo usage of playlist
 */
#include "playlist.h"

/**
 * @brief exemplary usage of playlist
 *
 * @return int status code
 */
int main(void)
{
    printf("\nMaximum playlist size is set to %d songs.\n", MAX_SONGS);
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Move", "Adam Port");
    add_song(&myPlaylist, "Back outside", "Sosa La M");
    add_song(&myPlaylist, "Avant la douane", "Jul");
    add_song(&myPlaylist, "Banda", "Morad");
    add_song(&myPlaylist, "Meer", "Luciano");
    add_song(&myPlaylist, "Trappers Lullbaby", "Reezy");
    
    printf("Initial playlist:\n");
    print_playlist(&myPlaylist);

    //                      SECTION I                     //

    printf("\nIterative searching for song 'Move' :\n");
    Song *found = find_song_by_title(&myPlaylist, "Move");
    if (found)
        printf("Found: %s by %s\n", found->title, found->artist);
    else
        printf("Song not found\n");

    printf("\nRecursive searching for song 'Avant la douane' :\n");
    found = find_song_recursive(myPlaylist.p_head, "Avant la douane");
    if (found)
        printf("Found: %s by %s\n", found->title, found->artist);
    else
        printf("Song not found\n");


//                        SECTION II                       //
    int count = count_songs_recursive(myPlaylist.p_head);
    printf("\nNumber of songs (recursive): %d\n", count);



//                        SECTION III                      //

    printf("\nSorting playlist by title...\n");
    sort_playlist_by_title(&myPlaylist);

    printf("Playlist after sorting:\n");
    print_playlist(&myPlaylist);


    delete_playlist(&myPlaylist);

    return 0;
}
