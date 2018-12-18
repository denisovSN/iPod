#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sortAndShuffle.h"
#define MAX_LENGTH 80

/*
 * This method sorts the artists alphabetically. It takes as input:
 * - sortedArtists: the array of artists that that should be sorted
 * - numOfArtists: the total number of artists
 *
 */
void sortArtists(char artists[][80], char sortedArtists[][80], int numOfArtists)
{
    char swap[MAX_LENGTH];
    int j = 0;
    int i = 0;
    int minIndex = 0;
    int minIndexChanged = 0;
    
    // copying the names from the array 'artists' to 'sortedArtists'
    for (size_t i = 0; i<numOfArtists; i++)
    {
    strcpy(sortedArtists[i], artists[i]);
    }
    
    // sorting the artists in an alphabetical order
    // using quick sort
    for(i=0; i< numOfArtists-1; i++)
    {
        minIndex = i;
        for(j = i+1; j<numOfArtists; j++)
        {
            if(strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged = 1;
            }
        }
        
        if(minIndexChanged ==1)
        {
            memset(swap, '$', MAX_LENGTH-2);
            swap[MAX_LENGTH -1] = '\0';
            strcpy(swap, sortedArtists[i]);
            strcpy(sortedArtists[i], sortedArtists[minIndex]);
            strcpy(sortedArtists[minIndex], swap);
            minIndexChanged = 0;
        }
    }
}

/*
 * This method sorts the songs of a specific artist alphabetically. It takes as input:
 * - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
 * - numOfArtists: the number of artists provided from the standard input
 */

void sortSongs(char songsOfAnArtist[][80], int numOfSongs)
{
    char swap[MAX_LENGTH];
    int j = 0;
    int i = 0;
    int minIndex = 0;
    int minIndexChanged = 0;
    
    // sorting the songs in an alphabetical order
    // using quick sort
    for(i = 0; i < numOfSongs-1; i++)
    {
        minIndex = i;
        for(j = i+1; j<numOfSongs; j++)
        {
            if(strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0)
            {
                minIndex = j;
                minIndexChanged = 1;
            }
        }
        
        if(minIndexChanged == 1)
        {
            memset(swap, '$', MAX_LENGTH-2);
            swap[MAX_LENGTH -1] = '\0';
            strcpy(swap, songsOfAnArtist[i]);
            strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
            strcpy(songsOfAnArtist[minIndex], swap);
            minIndexChanged = 0;
        }
    }
}

/*
 * This method shuffles a set of songs. It takes as input:
 * - songsToBeShuffled: the array of the songs that should be shuffled
 * - numOfSongs: the number of songs to be shuffled
 */
    void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
    {

    //unsigned long int i = strlen(songsToBeShuffled);
    int j, i;
    char temp[12][80];
    
    // implementing Fisher-Yates algorithm
    for(i=1; i < numOfSongs; i++)
    {
        j = rand()%(i+1);
        if(j!=i)
        {
            strcpy(temp[i], songsToBeShuffled[i]);
            strcpy(songsToBeShuffled[i], songsToBeShuffled[j]);
            strcpy(songsToBeShuffled[j], temp[i]);
        }
    }
    }

