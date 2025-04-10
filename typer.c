// typing game
#include <windows.h>
#include <stdio.h>
#include <time.h>

int main() {
    printf("\033[1;31m");
        char *wordBank[] = {
        "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli", "vanilla",
        "watermelon", "xigua", "yam", "zucchini", "avocado", "blueberry", "cantaloupe", "dragonfruit", "eggplant", "fennel",
        "guava", "hazelnut", "iceberg", "jackfruit", "kumquat", "lime", "mulberry", "nutmeg", "olive", "peach",
        "plum", "radish", "spinach", "tomato", "umbrella", "violet", "walnut", "xylophone", "yarrow", "zebra",
        "almond", "broccoli", "carrot", "daikon", "endive", "fennel", "garlic", "horseradish", "ivy", "jalapeno",
        "kale", "lettuce", "melon", "nectar", "okra", "parsley", "quinoa", "rutabaga", "sage", "thyme",
        "turnip", "ugli", "vanilla", "watercress", "xanadu", "yam", "zucchini", "artichoke", "beet", "cucumber",
        "dandelion", "elderflower", "fiddlehead", "ginger", "hibiscus", "iris", "jasmine", "kohlrabi", "lavender", "mint",
        "oregano", "pepper", "quail", "rose", "sunflower", "tulip", "violet", "wheat", "xenon", "yucca"
    };
    
    //start the game 
    printf("Welcome to type speed, get your fingers ready because your going to need it!\n");

    printf("\033[0m");
    char *selectedWord, *selectedWord2, *selectedWord3, *selectedWord4;
    char buff[50];
    BOOL isTyping = FALSE;
    srand(time(NULL));

    int randomnum = (rand() % 100) + 1;
    int randomnum2 = (rand() % 100) + 1;
    int randomnum3 = (rand() % 100) + 1;
    int randomnum4 = (rand() % 100) + 1;
        selectedWord = wordBank[randomnum];
        selectedWord2 = wordBank[randomnum2];
        selectedWord3 = wordBank[randomnum3];
        selectedWord4 = wordBank[randomnum4];
        printf("\033[0;35m");
        printf("%s %s %s %s\n", selectedWord, selectedWord2, selectedWord3, selectedWord4);
        char boolbuff[100];
        snprintf(boolbuff, sizeof(boolbuff), "%s %s %s %s\n", selectedWord, selectedWord2, selectedWord3, selectedWord4);
    printf("Press Enter to start...");
    if (getchar() == '\n') {
        LARGE_INTEGER freq, start, end;
        QueryPerformanceFrequency(&freq);
    
        QueryPerformanceCounter(&start);
    
        fgets(buff, sizeof(buff), stdin);
    
        
            QueryPerformanceCounter(&end);
            double endtime = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;

            printf("\nResults:\nTime: %f\nTyped Words: %s\n", endtime, selectedWord, buff);
        
            if (strcmp(buff, boolbuff) == 0) {
                printf("Correct: Y");
            } else {
                printf("Correct: N");
            }
    } else {
        printf("No, press enter\n");
        printf("\033[0m");
    }
return 0;
}
