#include <stdio.h>

// Define the number of words and size of words
#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

// Define a struct to hold an array of double words
typedef struct {
    unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));

// Function to compare two arrays of data
int compare_data(arr_t data[], arr_t expected_data[]) {
    // Loop through each element in the array
    for (int i = 0; i < 8; i++) {
        // If the data does not match the expected data, return 0 (FAIL)
        if (data[i].double_word[0] != expected_data[i].double_word[0]) {
            return 0; // FAIL
        }
    }
    // If all data matches, return 1 (PASS)
    return 1; // PASS
}

arr_t store_byte_data[8] = {
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000},
    {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] = {
    // double_word0         double_word1
    {0x00000000000000EF, 0x0000000000000000},
    {0x000000000000BE00, 0x0000000000000000},
    {0x0000000000AD0000, 0x0000000000000000},
    {0x00000000DE000000, 0x0000000000000000},
    {0x000000EF00000000, 0x0000000000000000},
    {0x0000BE0000000000, 0x0000000000000000},
    {0x00AD000000000000, 0x0000000000000000},
    {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };

arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };

// Function to test storing bytes
int store_byte_test ( ) {
    // Define an array of bytes to store
    unsigned long long arr[] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE};

    // Loop through each byte in the array
    int k = 0;
    for ( int i = 0; i < 8 ; i++){
        for (int j = 0; j <= 1 ;j++){
            // Store the byte in the data array
            if ( j == 0 ){
                store_byte_data[i].double_word[j] = arr[i] << (i*8);
            }
            // Shift the byte to the right for the next iteration
            if ( j == 1 & i != 0){
                store_byte_data[i].double_word[j] = (arr[i] >> 64-(k*8));
            }
        }
        k++;
    }
    // Compare the stored data with the expected data
    return compare_data(store_byte_data, store_byte_expected_data);
}

// Function to test storing half words
int store_half_word_test ( ) {
   // Define an array of half words to store
   unsigned long long arr[] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};

   // Loop through each half word in the array
   int k = 0;
   for ( int i = 0; i < 8 ; i++){
      for (int j = 0; j <= 1 ;j++){
         // Store the half word in the data array
         if ( j == 0 ){
            store_half_word_data[i].double_word[j] = arr[i] << (i*8);
         }
         // Shift the half word to the right for the next iteration
         if ( j == 1 & i != 0){
            store_half_word_data[i].double_word[j] = (arr[i] >> 64-(k*8));
         }
      }
      k++;
   }
   // Compare the stored data with the expected data
   return compare_data(store_half_word_data, store_half_word_expected_data);
} // store_half_word_test

// Function to test storing words
int store_word_test ( ) {
   // Define an array of words to store
   unsigned long long arr[] = {0xDEADBEEF, 0xF00DC0DE};

   // Loop through each word in the array
   int k = 0;
   int x;
   for ( int i = 0; i < 8 ; i++){
      // Determine which word to store
      if ( i < 4 )
         x = 0;
      else
         x = 1;
      for (int j = 0; j < 2 ;j++){
         // Store the word in the data array
         if ( j == 0 ){
            store_word_data[i].double_word[j] = arr[x] << (i*8);
         }
         // Shift the word to the right for the next iteration
         if ( j == 1 & i != 0){
            store_word_data[i].double_word[j] = (arr[x] >> 64-(k*8));
         }
      }
      k++;
   }
   // Compare the stored data with the expected data
   return compare_data(store_word_data, store_word_expected_data);
} // store_word_test

// Function to test storing double words
int store_double_word_test ( ) {
   // Define an array of double words to store
   unsigned long long int arr[] = {0xDEADBEEFF00DC0DE};
   int k = 0;

   // Loop through each double word in the array
   for ( int i = 0; i < 8 ; i++){
      for (int j = 0; j < 2 ;j++){
         // Store the double word in the data array
         if ( j == 0){
            store_double_word_data[i].double_word[j] = arr[0] << (i*8);
         }
         // Shift the double word to the right for the next iteration
         if ( j == 1 & i != 0){
            store_double_word_data[i].double_word[j] = (arr[0] >> 64-(k*8));
         }
      }
      k++;
   } 
   // Compare the stored data with the expected data
   return compare_data(store_double_word_data, store_double_word_expected_data);
} // store_double_word_test

// Main function to run the tests
int main() {
    // Print the results of each test
    printf("store_byte_test:         %s\n", store_byte_test() ? "PASS" : "FAIL");
    printf("store_half_word_test:    %s\n", store_half_word_test() ? "PASS" : "FAIL");
    printf("store_word_test:         %s\n", store_word_test() ? "PASS" : "FAIL");
    printf("store_double_word_test:  %s\n", store_double_word_test() ? "PASS" : "FAIL");
    return 0;
}
