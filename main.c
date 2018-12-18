#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sortAndShuffle.h"

int main(void)
{
    srand(time(NULL));
    
    //The array containing artists names
    char artists[4][80];
    //The array containing the sorted artists
    char sortedArtists[4][80];
    //Songs for Artist 1
    char songsArtist1[3][80];
    //Songs for Artist 2
    char songsArtist2[3][80];
    //Songs for Artist 3
    char songsArtist3[3][80];
    //Songs for Artist 4
    char songsArtist4[3][80];
    //The total number of artists (Note it can be less than 4)
    int numOfArtists = 1;
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[4];
    //The names of the tracks and the artists. E.g. 'Artist - Song'
    char unsortedPlaylist[12][80];
    //The total number of songs for all artists
    int totalNumberOfSongs=0;

    /*
     * Use here functions that you should implement to insert artists and songs from the standard input.
     * Note that you also need to track the number of artists and the number of songs for each artist.
     */
    
    // ******************* Artist 1 input *******************
    printf("Enter artist/group name: \n");
    fgets(artists[0], 80, stdin);
    
    unsigned long int new_line_removal_artist1;
    unsigned long int k = strlen(artists[0]);
    
    if ( k > 0 && artists[0][k-1] == '\n')
    {
        artists[0][k-1] = '\0';
    }
    
    int counter1 = 0;
    for(int artist1_song_store = 0; artist1_song_store<3; artist1_song_store++)
    {
        
        printf("Insert song %d for %s\n", numSongsPerArtist[0]+1, artists[0]);
        fgets(songsArtist1[artist1_song_store], 80, stdin);
        
            // copying user's input into the empty 'unsortedPlaylist' array
            // which would be used for the 'shuffling playlist' part
            strcpy(unsortedPlaylist[counter1], artists[0]);
            strcat(unsortedPlaylist[counter1], " - ");
            strcat(unsortedPlaylist[counter1], songsArtist1[artist1_song_store]);
        
        if(songsArtist1[artist1_song_store][0]=='\n')
        {
            // remove '\n' character
            new_line_removal_artist1 = strlen(songsArtist1[artist1_song_store]);
            songsArtist1[artist1_song_store][new_line_removal_artist1-1] = '\0';
            
            goto artist2;
        }
        
        counter1++;
        numSongsPerArtist[0]++;
        totalNumberOfSongs++;
    }
    
artist2:
    
    // ******************* Artist 2 input *******************
    puts("");
    printf("Enter artist/group name: \n");
    fgets(artists[1], 80, stdin);
    
    if(artists[1][0]=='\n')
    {
        goto sorting;
    }
    
    // remove '\n' char
    unsigned long int k2 = strlen(artists[1]);
    if ( k2 > 0 && artists[1][k2-1] == '\n')
    {
        artists[1][k2-1] = '\0';
    }
    
    numOfArtists++;
    int counter2=counter1;
    unsigned long int new_line_removal_artist2;
    for(int artist2_song_store = 0; artist2_song_store<3;artist2_song_store++)
    {
        printf("Insert song %d for %s\n", numSongsPerArtist[1]+1, artists[1]);
        fgets(songsArtist2[artist2_song_store], 80, stdin);
        
        // copying user's input into the empty 'unsortedPlaylist' array
        // which would be used for the 'shuffling playlist' part
        strcpy(unsortedPlaylist[counter2], artists[1]);
        strcat(unsortedPlaylist[counter2], " - ");
        strcat(unsortedPlaylist[counter2], songsArtist2[artist2_song_store]);

        if(songsArtist2[artist2_song_store][0]=='\n')
        {
            // removing new line character
            new_line_removal_artist2 = strlen(songsArtist2[artist2_song_store]);
            songsArtist2[artist2_song_store][new_line_removal_artist2-1] = '\0';
            
            goto artist3;
        }
        counter2++;
        numSongsPerArtist[1]++;
        totalNumberOfSongs++;
    }
    
artist3:
    
    // ******************* Artist 3 input *******************
    puts("");
    printf("Enter artist/group name: \n");
    fgets(artists[2], 80, stdin);
    
    if(artists[2][0]=='\n')
    {
        goto sorting;
    }
    
    unsigned long int k3 = strlen(artists[2]);
    if ( k3 > 0 && artists[2][k3-1] == '\n')
    {
        artists[2][k3-1] = '\0';
    }
    
    int counter3=counter2;
    numOfArtists++;
    unsigned long int new_line_removal_artist3;
    for(int artist3_song_store = 0; artist3_song_store<3; artist3_song_store++)
    {
        printf("Insert song %d for %s\n", numSongsPerArtist[2]+1, artists[2]);
        fgets(songsArtist3[artist3_song_store], 80, stdin);
        
        // copying user's input into the empty 'unsortedPlaylist' array
        // which would be used for the 'shuffling playlist' part
        strcpy(unsortedPlaylist[counter3], artists[2]);
        strcat(unsortedPlaylist[counter3], " - ");
        strcat(unsortedPlaylist[counter3], songsArtist3[artist3_song_store]);
        
        if(songsArtist3[artist3_song_store][0]=='\n')
        {
            // removing new line character
            new_line_removal_artist3 = strlen(songsArtist3[artist3_song_store]);
            songsArtist3[artist3_song_store][new_line_removal_artist3-1] = '\0';
            
            goto artist4;
        }
        counter3++;
        numSongsPerArtist[2]++;
        totalNumberOfSongs++;
    }

artist4:
    
    // ******************* Artist 4 input *******************
    puts("");
    printf("Enter artist/group name: \n");
    fgets(artists[3], 80, stdin);
    

    if(artists[3][0]=='\n')
    {
        goto sorting;
    }
    
    unsigned long int k4 = strlen(artists[3]);
    
    // remove '\n' from artist
    if ( k4 > 0 && artists[3][k4-1] == '\n')
    {
        artists[3][k4-1] = '\0';
    }
    
    numOfArtists++;
    
    int counter4=counter3;
    unsigned long int new_line_removal_artist4;
    for (int artist4_song_store = 0; artist4_song_store<3; artist4_song_store++)
    {
        printf("Insert song %d for %s\n", numSongsPerArtist[3]+1, artists[3]);
        fgets(songsArtist4[artist4_song_store], 80, stdin);
        
        // copying user's input into the empty 'unsortedPlaylist' array
        // which would be used for the 'shuffling playlist' part
        strcpy(unsortedPlaylist[counter4], artists[3]);
        strcat(unsortedPlaylist[counter4], " - ");
        strcat(unsortedPlaylist[counter4], songsArtist4[artist4_song_store]);
        
        if(songsArtist4[artist4_song_store][0]=='\n')
        {
            // removing new line character
            new_line_removal_artist4 = strlen(songsArtist4[artist4_song_store]);
            songsArtist4[artist4_song_store][new_line_removal_artist4-1] = '\0';
            
            goto sorting;
        }
        
        counter4++;
        numSongsPerArtist[3]++;
        totalNumberOfSongs++;
    }
    
    /*
     * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
     * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
     */
    
sorting:
    // calling this function to sort artists
    sortArtists(artists, sortedArtists, numOfArtists);

    // passing information to the function 'sortSongs'
    // according to user's input and the number of
    // artists and songs he has typed in
    for(size_t i = 0; i<numOfArtists;i++)
    {
        switch(i)
        {
            case 0: sortSongs(songsArtist1, numSongsPerArtist[0]);
            case 1: sortSongs(songsArtist2, numSongsPerArtist[1]);
            case 2: sortSongs(songsArtist3, numSongsPerArtist[2]);
            case 3: sortSongs(songsArtist4, numSongsPerArtist[3]);
        }
    }
    
    puts("");
    printf("%s", "Sorted list of songs: ");
   
    // linking artists with songs
    int sorted, check, counter, equal;
    
   for(sorted = 0; sorted < numOfArtists; sorted++)
    {
        // comparing the arrays 'sortedArtists' with 'artists'
        // and checking if there's a change in position
        // if so, then link the songs corresponding to the artist
        // in array 'artists'
        puts("");
        printf("%s\n", sortedArtists[sorted]);
        
        for(check = 0; check < numOfArtists; check++)
        {
            equal = strcmp(sortedArtists[sorted], artists[check]);
            
            if(equal==0)
            {
                if(check==0)
                {
                    for (counter = 0; counter < numSongsPerArtist[0]; counter ++)
                    {
                       printf("    - %s", songsArtist1[counter]);
                    }
                        puts("");
                        break;
                }
                        
                if(check==1)
                {
                    for (counter = 0; counter < numSongsPerArtist[1]; counter ++)
                    {
                        printf("    - %s", songsArtist2[counter]);
                    }
                        puts("");
                        break;
                }
                        
                if(check==2)
                {
                    for (counter = 0; counter < numSongsPerArtist[2]; counter ++)
                    {
                        printf("    - %s", songsArtist3[counter]);
                    }
                        puts("");
                        break;
                }
                        
                 if(check==3)
                 {
                     for (counter = 0; counter < numSongsPerArtist[3]; counter ++)
                        {
                            printf("    - %s", songsArtist4[counter]);
                        }
                        puts("");
                     break;
                 }
                
                }
            }
        }
    
    /*
     * Use here the function shuffleSongs to shuffle all the songs
     * Print the list of shuffled songs
     */
    
    // calling the function 'shuffleSongs' 
    shuffleSongs(unsortedPlaylist, totalNumberOfSongs);
    
    // test: printing out the unshuffled playlist
    printf("Shuffled Playlist: \n");
    
    int song_number_shuffled_playlist=1; // variable to indicate song's number
    
    // for loop to loop two times
    for(int loop_twice = 0; loop_twice < 2; loop_twice++)
    {
        // print out the shuffled playlist
        for(int print_shuffled_playlist = 0; print_shuffled_playlist < totalNumberOfSongs; print_shuffled_playlist++)
        {
            printf("%.2d. %s",song_number_shuffled_playlist, unsortedPlaylist[print_shuffled_playlist]);
            song_number_shuffled_playlist++;
        }
    }
    return 0;
}
