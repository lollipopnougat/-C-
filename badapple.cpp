#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib")


#define DATAFILE "BADAPPLE.txt"

#define FRAME_WIDTH        80
#define FRAME_HEIGHT    32

#define DATA_TOKEN_SIZE    ( 5 + 1 )    //    $0000\n
#define DATA_PITCH_SIZE    ( FRAME_WIDTH + 1 )        // ###...\n
#define DATA_FRAME_SIZE    ( DATA_TOKEN_SIZE + ( DATA_PITCH_SIZE * FRAME_HEIGHT ) )

#define FRAME_COUNT    3271

#define VIDEO_TIME    218000.0f    // 3:38 (218000ms)


int main(void)
{
    HANDLE hOutput;

    hOutput = GetStdHandle( STD_OUTPUT_HANDLE );

    CONSOLE_CURSOR_INFO coc = { 1, FALSE };
    COORD co = { FRAME_WIDTH, FRAME_HEIGHT };
    SMALL_RECT rc = { 0, 0, FRAME_WIDTH - 1, FRAME_HEIGHT - 1 };

    SetConsoleCursorInfo( hOutput, &coc );
    SetConsoleScreenBufferSize( hOutput, co );
    SetConsoleWindowInfo( hOutput, TRUE, &rc );

    SetConsoleTitle( "Bad Apple By Crsky @2016" );

    FILE    *fp;
    int        size;
    char    *buf;
    char    *cur;
    int        start;

    buf = NULL;

    fp = fopen( DATAFILE, "rb" );

    if ( !fp )
    {
        printf( "%s not found.\n", DATAFILE );
        goto err;
    }

    size = DATA_FRAME_SIZE * FRAME_COUNT;

    buf = new char[ size ];

    if ( fread( buf, size - 1, 1, fp ) != 1 )
    {
        printf( "Failed to read in data file.\n" );
        goto err;
    }

    buf[ size - 1 ] = '\0';

    fclose( fp );

    mciSendString( "open BADAPPLE.wma alias BGM", NULL, 0, NULL );
    mciSendString( "play BGM", NULL, 0, NULL );

    start = GetTickCount();

    while ( 1 )
    {
        int        time;
        float    percen;
        int        frame;
        COORD    xy = { 0, 0 };
        DWORD    written;

        if ( GetKeyState( VK_SPACE ) )
        {
            printf( "Stop play.\n" );
            break;
        }

        time = GetTickCount();
        percen = ( time - start ) / VIDEO_TIME;

        if ( percen > 1 )
        {
            printf( "End of play.\n" );
            break;
        }

        frame = percen * FRAME_COUNT;
        cur = &buf[ ( DATA_FRAME_SIZE * frame ) + DATA_TOKEN_SIZE ];

        for ( ; xy.Y < FRAME_HEIGHT; xy.Y++, cur += DATA_PITCH_SIZE )
            WriteConsoleOutputCharacter( hOutput, cur, DATA_PITCH_SIZE - 1, xy, &written );

        Sleep( 60 );
    }

    mciSendString( "stop", NULL, 0, NULL );
    mciSendString( "close", NULL, 0, NULL );

err:
    if ( buf )
        delete[] buf;

    Sleep( 500 );
    return 0;
}
