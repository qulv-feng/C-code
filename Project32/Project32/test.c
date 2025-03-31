#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

//int main()
//{
//	int* p = (int*)malloc(20888888888);
//	if (p == NULL)
//	{
//		perror("malloc");
//	}
//	printf("OK!!!");
//	int b = 0;
//	scanf("%d", &b);
//	free(p);
//	p = NULL;
//	return 0;
//}


//1个数组中只有两个数字是出现一次，其他所有数字都出现了两次
//111
//101
//111

//void test(int arr[], int len,int*p1,int* p2)
//{
//	int i = 0;
//	int ret = arr[0];
//	for (i = 1; i < len;i++)
//	{
//		ret ^= arr[i];
//	}
//	int pos = 0;
//	for (pos = 0;pos < 32;pos++)
//	{
//		if ((ret >> pos) & 1 == 1)
//		{
//			break;
//		}
//	}
//	for (int i = 0;i < len;i++)
//	{
//		if ((arr[i] >> pos) & 1 == 1)
//		{
//			*p1 ^= arr[i];
//		}
//		else
//			*p2 ^= arr[i];
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,2,3,3,5,5,6,6,7,8,7,8,9 };
//	int dog1 = 0;
//	int dog2 = 0;
//	test(arr,sizeof(arr)/sizeof(arr[0]),&dog1,&dog2);
//	printf("%d %d", dog1, dog2);
//	return 0;
//}


// --- Simple Hash Map Implementation ---
// (Good enough for this problem, not a general-purpose robust hash map)

//#define HASH_TABLE_SIZE 10007 // A prime number
//
//typedef struct HashNode {
//    char* key;
//    int value; // Count of the word
//    struct HashNode* next;
//} HashNode;
//
//typedef struct HashTable {
//    HashNode** buckets;
//    int size;
//} HashTable;
//
//// Basic string hash function (djb2)
//unsigned long hash_function(const char* str) {
//    unsigned long hash = 5381;
//    int c;
//    while ((c = *str++)) {
//        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//    }
//    return hash;
//}
//
//// Create a hash table
//HashTable* create_hash_table(int size) {
//    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
//    if (!table) return NULL;
//    table->size = size;
//    table->buckets = (HashNode**)calloc(size, sizeof(HashNode*)); // Initialize buckets to NULL
//    if (!table->buckets) {
//        free(table);
//        return NULL;
//    }
//    return table;
//}
//
//// Find a node in the hash table (returns node or NULL)
//HashNode* find_node(HashTable* table, const char* key) {
//    unsigned long hash_index = hash_function(key) % table->size;
//    HashNode* node = table->buckets[hash_index];
//    while (node != NULL) {
//        if (strcmp(node->key, key) == 0) {
//            return node;
//        }
//        node = node->next;
//    }
//    return NULL;
//}
//
//// Get value (count) from hash table, returns 0 if not found
//int hash_get(HashTable* table, const char* key) {
//    HashNode* node = find_node(table, key);
//    return (node != NULL) ? node->value : 0;
//}
//
//// Increment value for a key in the hash table. Creates node if key doesn't exist.
//// Returns 0 on success, -1 on memory allocation failure.
//int hash_increment(HashTable* table, const char* key, int increment) {
//    unsigned long hash_index = hash_function(key) % table->size;
//    HashNode* node = table->buckets[hash_index];
//    HashNode* prev = NULL;
//
//    // Search for existing key
//    while (node != NULL) {
//        if (strcmp(node->key, key) == 0) {
//            node->value += increment;
//            return 0; // Success
//        }
//        prev = node;
//        node = node->next;
//    }
//
//    // Key not found, create a new node if increment is positive
//    if (increment > 0) {
//        HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
//        if (!newNode) return -1; // Allocation failure
//        newNode->key = strdup(key); // Duplicate the key string
//        if (!newNode->key) {
//            free(newNode);
//            return -1; // Allocation failure
//        }
//        newNode->value = increment;
//        newNode->next = NULL;
//
//        // Add to bucket (chaining)
//        if (prev == NULL) { // First node in bucket
//            table->buckets[hash_index] = newNode;
//        }
//        else {
//            prev->next = newNode;
//        }
//        return 0; // Success
//    }
//    // If increment is not positive and key not found, do nothing (effectively count is 0)
//    return 0;
//}
//
//
//// Free the hash table and associated memory
//void free_hash_table(HashTable* table) {
//    if (!table) return;
//    for (int i = 0; i < table->size; ++i) {
//        HashNode* node = table->buckets[i];
//        while (node != NULL) {
//            HashNode* temp = node;
//            node = node->next;
//            free(temp->key); // Free the duplicated key
//            free(temp);
//        }
//    }
//    free(table->buckets);
//    free(table);
//}
//
//// Reset counts in a hash table (useful for the sliding window's 'seen' map)
//void reset_hash_table_counts(HashTable* table) {
//    if (!table) return;
//    for (int i = 0; i < table->size; ++i) {
//        HashNode* node = table->buckets[i];
//        while (node != NULL) {
//            node->value = 0; // Reset count
//            node = node->next;
//        }
//    }
//}
//
//
//// --- Main Logic ---
//
//int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
//    *returnSize = 0;
//    if (!s || !words || wordsSize == 0 || strlen(s) == 0) {
//        return NULL;
//    }
//
//    int sLen = strlen(s);
//    int wordLen = strlen(words[0]); // All words have the same length
//    int numWords = wordsSize;
//    int concatLen = wordLen * numWords;
//
//    if (sLen < concatLen) {
//        return NULL; // s is too short to contain the concatenation
//    }
//
//    // 1. Build frequency map for the words array
//    HashTable* wordsFreq = create_hash_table(HASH_TABLE_SIZE);
//    if (!wordsFreq) return NULL; // Memory allocation failed
//
//    for (int i = 0; i < numWords; ++i) {
//        // Use strdup to create a copy for the key if inserting new
//        // Our hash_increment handles insertion and strdup internally now
//        if (hash_increment(wordsFreq, words[i], 1) != 0) {
//            free_hash_table(wordsFreq);
//            return NULL; // Memory error
//        }
//    }
//
//    // 2. Allocate result array (start with a reasonable capacity)
//    int capacity = 10;
//    int* result = (int*)malloc(capacity * sizeof(int));
//    if (!result) {
//        free_hash_table(wordsFreq);
//        return NULL;
//    }
//
//    // 3. Sliding Window approach
//    // Create a hash table for the current window's word counts
//    HashTable* seenWords = create_hash_table(HASH_TABLE_SIZE);
//    if (!seenWords) {
//        free_hash_table(wordsFreq);
//        free(result);
//        return NULL;
//    }
//    // Pre-populate seenWords with keys from wordsFreq but counts set to 0.
//    // This simplifies the get/increment logic later.
//    for (int i = 0; i < wordsFreq->size; ++i) {
//        HashNode* node = wordsFreq->buckets[i];
//        while (node != NULL) {
//            if (hash_increment(seenWords, node->key, 0) != 0) { // Add key with count 0
//                free_hash_table(wordsFreq);
//                free_hash_table(seenWords);
//                free(result);
//                return NULL;
//            }
//            node = node->next;
//        }
//    }
//
//
//    // Iterate through all possible start positions, grouped by wordLen offset
//    for (int i = 0; i < wordLen; ++i) {
//        reset_hash_table_counts(seenWords); // Reset counts for this offset run
//        int left = i;      // Left boundary of the window
//        int count = 0;     // Number of valid words found in the current window
//
//        // Slide the window word by word
//        for (int j = i; j <= sLen - wordLen; j += wordLen) {
//            // Extract the word at the current position j
//            char currentWord[wordLen + 1];
//            strncpy(currentWord, s + j, wordLen);
//            currentWord[wordLen] = '\0';
//
//            int targetCount = hash_get(wordsFreq, currentWord);
//
//            if (targetCount > 0) { // It's a word we care about
//                hash_increment(seenWords, currentWord, 1);
//                int currentCount = hash_get(seenWords, currentWord);
//                count++;
//
//                // If we've seen too many of this word, shrink window from left
//                while (currentCount > targetCount) {
//                    char leftmostWord[wordLen + 1];
//                    strncpy(leftmostWord, s + left, wordLen);
//                    leftmostWord[wordLen] = '\0';
//
//                    // Decrement count of the word leaving the window
//                    hash_increment(seenWords, leftmostWord, -1);
//                    count--;
//                    left += wordLen; // Slide left boundary
//
//                    // Update currentCount for the check condition (only if the word removed was the same as currentWord)
//                    if (strcmp(leftmostWord, currentWord) == 0) {
//                        currentCount = hash_get(seenWords, currentWord);
//                    }
//                }
//
//                // Check if the window is complete
//                if (count == numWords) {
//                    // Found a valid concatenation!
//                    if (*returnSize >= capacity) {
//                        capacity *= 2;
//                        int* temp = (int*)realloc(result, capacity * sizeof(int));
//                        if (!temp) {
//                            // Handle realloc failure
//                            free_hash_table(wordsFreq);
//                            free_hash_table(seenWords);
//                            free(result);
//                            *returnSize = 0; // Indicate error or partial result
//                            return NULL;
//                        }
//                        result = temp;
//                    }
//                    result[*returnSize] = left;
//                    (*returnSize)++;
//
//                    // Slide window forward by one word after finding a match
//                    char leftmostWord[wordLen + 1];
//                    strncpy(leftmostWord, s + left, wordLen);
//                    leftmostWord[wordLen] = '\0';
//                    hash_increment(seenWords, leftmostWord, -1);
//                    count--;
//                    left += wordLen;
//                }
//            }
//            else {
//                // Current word is not in 'words', reset the window
//                reset_hash_table_counts(seenWords);
//                count = 0;
//                left = j + wordLen; // Start the next potential window after this invalid word
//            }
//        }
//        // Reset seenWords counts for the next offset 'i' (done at start of loop)
//    }
//
//    // 4. Clean up
//    free_hash_table(wordsFreq);
//    free_hash_table(seenWords);
//
//    // Adjust final result array size if needed (optional, but good practice)
//    if (*returnSize < capacity && *returnSize > 0) {
//        int* final_result = (int*)realloc(result, (*returnSize) * sizeof(int));
//        if (final_result) { // realloc might return NULL if shrinking fails, keep original
//            result = final_result;
//        }
//    }
//    else if (*returnSize == 0) {
//        free(result);
//        return NULL; // Return NULL for empty result as per LeetCode convention
//    }
//
//
//    return result;
//}
//
//// --- Example Usage (Optional main function for testing) ---
//
//int main() {
//    // Example 1
//    char s1[] = "barfoothefoobarman";
//    char *words1[] = {"foo", "bar"};
//    int returnSize1;
//    int *result1 = findSubstring(s1, words1, 2, &returnSize1);
//    printf("Example 1: [");
//    for (int i = 0; i < returnSize1; ++i) {
//        printf("%d%s", result1[i], (i == returnSize1 - 1) ? "" : ",");
//    }
//    printf("]\n"); // Expected: [0,9] or [9,0]
//    free(result1);
//
//    // Example 2
//    char s2[] = "wordgoodgoodgoodbestword";
//    char *words2[] = {"word", "good", "best", "word"};
//    int returnSize2;
//    int *result2 = findSubstring(s2, words2, 4, &returnSize2);
//    printf("Example 2: [");
//    for (int i = 0; i < returnSize2; ++i) {
//        printf("%d%s", result2[i], (i == returnSize2 - 1) ? "" : ",");
//    }
//    printf("]\n"); // Expected: []
//    free(result2);
//
//    // Example 3
//    char s3[] = "barfoofoobarthefoobarman";
//    char *words3[] = {"bar", "foo", "the"};
//    int returnSize3;
//    int *result3 = findSubstring(s3, words3, 3, &returnSize3);
//    printf("Example 3: [");
//    for (int i = 0; i < returnSize3; ++i) {
//        printf("%d%s", result3[i], (i == returnSize3 - 1) ? "" : ",");
//    }
//    printf("]\n"); // Expected: [6,9,12] in any order
//    free(result3);
//
//     // Example 4: Words with duplicates
//    char s4[] = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
//    char *words4[] = {"fooo","barr","wing","ding","wing"};
//    int returnSize4;
//    int *result4 = findSubstring(s4, words4, 5, &returnSize4);
//    printf("Example 4: [");
//    for (int i = 0; i < returnSize4; ++i) {
//        printf("%d%s", result4[i], (i == returnSize4 - 1) ? "" : ",");
//    }
//    printf("]\n"); // Expected: [13]
//    free(result4);
//
//
//    return 0;
//}
//

int my_atoi(char* str)
{
	assert(str);
	int len = 0;
	int flag = 1;
	if (*str <= '9' && *str >= '0')
	{
	    
	}
	else if(*str == '-')
	{
		str++;
		flag = -1;
	}
	else if (*str == '+')
	{
		str++;
	}
	else
	{
		fprintf(stderr, "Invalid input string!\n");
		return 0;  
	}
	int ret = 0;
	while(*str <= '9' && *str >= '0')
	{
		ret = ret * 10 + (int)(*str - '0');
		str++;
	}
	if (flag == 1)
		return ret;
	else
		return ret*flag;
}

int main()
{
	char str[] = "12134abc";
	int num = my_atoi(str);
	printf("%d", num);
	return 0;
}

//int my_atoi(char* str)
//{
//    assert(str);
//    int len = 0;
//    char* start = str;
//    int flag = 1;
//
//    // 调试输出
//    printf("Initial start: %c (ASCII: %d)\n", *start, *start);
//
//    if (*start >= '0' && *start <= '9')
//    {
//        printf("Entered if: *start = %c\n", *start);
//    }
//    else if (*start == '-')
//    {
//        str++;
//        flag = -1; // 正确的负号标记
//    }
//    else
//    {
//        fprintf(stderr, "Invalid input string!\n");
//        return 0;
//    }
//
//    while (*start >= '0' && *start <= '9')
//    {
//        start++;
//        len++;
//    }
//
//    int ret = 0;
//    while (len--)
//    {
//        ret += (*str - '0') * pow(10, len); // 修正转换错误
//        str++;
//    }
//
//    return ret * flag;
//}
//
//int main()
//{
//    char str[] = "-12134";
//    int num = my_atoi(str);
//    printf("Result: %d\n", num);
//    return 0;
//}


//int main()
//{
//	char s = '1';
//	printf("%d", (int)s);
//}