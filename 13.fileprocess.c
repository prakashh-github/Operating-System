#include <stdio.h>               
struct clientData 
{                              
    unsigned int acctNum; 
    char lastName[ 15 ];     
    char firstName[ 10 ];   
    double balance;   
};                  
int main( void )  
{ 
    FILE *cfPtr;
    struct clientData client = { 0, "", "", 0.0 };
    if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL ) 
	{
      puts( "File could not be opened." );
    } 
    else 
	{ 
    	printf( "%s", "Enter account number(0 to End Input )\n: " );
    	scanf( "%d", &client.acctNum );
    	while ( client.acctNum != 0 ) 
		{ 
    		printf( "%s", "Enter Firstname, Lastname, Balance\n: " );
    		fscanf( stdin, "%14s%9s%lf", client.firstName, client.lastName, &client.balance );
        	fseek( cfPtr, ( client.acctNum - 1 ) *              
        	sizeof( struct clientData ), SEEK_SET );                     
        	fwrite( &client, sizeof( struct clientData ), 1, cfPtr );
			printf( "%s", "Enter Account Number\n: " );
        	scanf( "%d", &client.acctNum );
    	}	 
      	fclose( cfPtr );
    }
} 

