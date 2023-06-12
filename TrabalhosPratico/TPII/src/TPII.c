/* Nome: Yago Martins Pintos
   Matrícula: 20100404 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int minOperations(char **logs, int logsSize) {
    int folder = 0;
    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "../") == 0) {
            if (folder > 0) {
                folder--;
            }
        }
        else if (strcmp(logs[i], "./") != 0) {
            folder++;
        }
    }
    return folder;
}

int main() {
    char *logs1[] = {"d1/", "d2/", "../", "d21/", "./"};
    int size1 = sizeof(logs1) / sizeof(char *);
    printf("%d\n", minOperations(logs1, size1)); /* Output: 2 */ 
    
    char *logs2[] = {"d1/", "d2/", "./", "d3/", "../", "d31/","d42/","d45/"};
    int size2 = sizeof(logs2) / sizeof(char *);
    printf("%d\n", minOperations(logs2, size2)); /* Output: 5 */
    
    char *logs3[] = {"d1/", "d2/", "../", "../"};
    int size3 = sizeof(logs3) / sizeof(char *);
    printf("%d\n", minOperations(logs3, size3)); /* Output: 0 */
    
    return 0;
}
