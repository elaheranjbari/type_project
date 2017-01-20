#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
struct node
{
    char word[40];
    struct node *next;
};
struct info
{
    char * playername;
    int last_level;
    double score;
    struct info *next;
};
/*void p ( struct node * head)
{
    struct node * current = head;

    while (current != NULL)
    {
        printf("%s\n", current->word);
        current = current->next;
    }
}
*/
char* del_front (struct node ** head)
{
    char *value = (char *) malloc (sizeof(char));
    struct node * next_node = NULL;
    next_node = (*head)->next;
    strcpy(value, (*head)->word);
    free (*head);
    *head = next_node;
    return value;
}
char* del_end (struct node *head)
{
    struct node *current=head;
    char *value = (char *)malloc(sizeof(char));
    while (current->next->next != NULL)
        current = current->next;
    strcpy (value, current->next->word);
    free (current->next);
    current->next = NULL;
    return value;
}
char* del_by_index (struct node ** head, int n)
{
    int i;
    char *value = (char *) malloc(sizeof(char));
    struct node * current = *head;
    struct node * temp_node = NULL;
    for (i = 0; i < n - 1; i++)
    {
        current = current->next;
    }
    temp_node = current->next;
    strcpy (value, temp_node->word);
    current->next = temp_node->next;
    free (temp_node);
    return value;
}
struct node * creat_node (FILE * fp)
{
    struct node * a_tail ;
    struct node * a_head ;
    a_tail = (struct node *)malloc(sizeof(struct node));
    a_head = (struct node *)malloc(sizeof(struct node));
    a_head = a_tail;
    fscanf (fp, " %s", a_tail->word);
    while (feof(fp) == 0)
    {
        a_tail->next = (struct node *)malloc(sizeof(struct node));
        a_tail = a_tail->next;
        fscanf (fp, " %s", a_tail->word);
    }
    a_tail->next = NULL;
    return a_head;
}
struct info * creat_list (FILE * fp)
{
    struct info * a_tail ;
    struct info * a_head ;
    a_tail = (struct info *)malloc(sizeof (struct info));
    a_head = (struct info *)malloc(sizeof (struct info));
    a_head = a_tail;
    fscanf (fp, " %s %d %lf", a_tail->playername, &a_tail->last_level, &a_tail->score);
    while (feof (fp)==0)
    {
        a_tail->next = (struct info *)malloc(sizeof(struct info));
        a_tail = a_tail->next;
        fscanf (fp, " %s %d %lf", a_tail->playername, &a_tail->last_level, &a_tail->score);
    }
    a_tail->next = NULL;
    return a_head;
}
int find_upest_level(void)
{
    FILE *ff;
    int level_count = 0, y = 1, i;
    for(i=0; i<10; i++)
    {
        switch (y)
        {
        case 1:
            ff = fopen ("level-1.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 2:
            ff = fopen ("level-2.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 3:
            ff = fopen ("level-3.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 4:
            ff = fopen ("level-4.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 5:
            ff = fopen ("level-5.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 6:
            ff = fopen ("level-6.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 7:
            ff = fopen ("level-7.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 8:
            ff = fopen ("level-8.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 9:
            ff = fopen ("level-9.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        case 10:
            ff = fopen ("level-10.txt", "r");
            if (ff != NULL)
                level_count++;
            y++;
            break;
        }

    }
    return level_count;
}
FILE *opening_func (int y)
{
    FILE *ff;
    switch (y)
    {
    case 1:
        ff = fopen ("level-1.txt", "r");
        break;
    case 2:
        ff = fopen ("level-2.txt", "r");
        break;
    case 3:
        ff = fopen ("level-3.txt", "r");
        break;
    case 4:
        ff = fopen ("level-4.txt", "r");
        break;
    case 5:
        ff = fopen ("level-5.txt", "r");
        break;
    case 6:
        ff = fopen ("level-6.txt", "r");
        break;
    case 7:
        ff = fopen ("level-7.txt", "r");
        break;
    case 8:
        ff = fopen ("level-8.txt", "r");
        break;
    case 9:
        ff = fopen ("level-9.txt", "r");
        break;
    case 10:
        ff = fopen ("level-10.txt", "r");
        break;
    }
    return ff;
}
char * choose_word (struct node * list, int number)
{
    int a;
    char *meghdar = (char *)malloc(sizeof (char));
    time_t t = time (NULL);
    srand (t);
    a = (int)((rand() / (double)(RAND_MAX)) * number);
    if (number == 1)
    {
        strcpy (meghdar, list->word);
        free (list);
        return meghdar;
    }
    else if (a == 0)
        return del_front(&list);
    else if (a == number)
        return del_end (list);
    else
        return del_by_index (&list, a);
}
int num_of_list_word (struct node* list)
{
    struct node* current = list;
    int num = 0;
    while (current->next != NULL)
    {
        current = current->next;
        num++;
    }
    return num;
}
char make_upper (char w)
{
    return toupper (w);
}
int remind (char * name)
{
    FILE *fp2;
    int  a, marhale;
    char esm[40];
    fp2 = fopen ("player_info.txt", "r");
    if (fp2 == NULL)
    {
        printf ("could not open the file\n");
        return -1;
    }
    while (a != EOF)
    {
        a = fscanf(fp2, "%s", esm);
        if (strcmp(esm, name) == 0)
        {
            fscanf (fp2, "%d", &marhale);
            printf ("%d", marhale);
            return marhale;
        }
    }
    fclose (fp2);
    return 11;

}
double word_scoring (double duration, int alph_count, int wrong_count)
{
    double point;
    point = ((double) ((alph_count * 3) - wrong_count)) / duration;
    return point;
}
double level_scoring (double sum_word_point, int word_number)
{
    double level_point;
    level_point = sum_word_point / ((double) word_number);
    return level_point;
}
struct info * add ( char name[40], int level, double score)
{
    struct info * current ;
    current = (struct info *)malloc(sizeof(struct info));
    current->playername = name;
    current->last_level = level;
    current->score = score;
    current->next = NULL;
    return current;
}

void save_info (char name[40], int level, double score)
{
    FILE *fp1;
    struct info *player = NULL;
    struct info *tmp = (struct info *)malloc(sizeof (struct info));
    fp1 = fopen ("player_info.txt", "a");
    player = add ( name, level, score);
    while ( !feof (fp1))
    {
        fscanf (fp1, "%s %d %lf\n", tmp->playername, &tmp->last_level, &tmp->score);
        if (strcmp(tmp->playername, name) == 0) {
            fseek (fp1, -1 * sizeof(struct info), SEEK_CUR);
            fprintf (fp1, "%s %d %lf\n", player->playername, player->last_level, player->score);
            fclose (fp1);
            return;
        }
    }
    fprintf (fp1, " %s %d %lf\n", player->playername, player->last_level, player->score);
    fclose (fp1);
}
void sort (struct info *player)
{
    struct info *racer = player;
    struct info *swa = (struct info*)malloc(sizeof(struct info));
    while (racer->next != NULL) {
        if (racer->score < racer->next->score) {
            swa->playername = racer->playername;
            swa->last_level = racer->last_level;
            swa->score = racer->score;
            racer->playername = racer->next->playername;
            racer->last_level = racer->next->last_level;
            racer->score = racer->next->score;
            racer->next->playername = swa->next->playername;
            racer->next->last_level = swa->next->last_level;
            racer->next->score = swa->next->score;
            racer = racer->next;
        }
    }
    free (swa);
}
void first_10_user (void)
{
    int i;
    struct info *racer = (struct info *)malloc(sizeof(struct node));
    FILE *fp3 ;
    fp3 = fopen ("player_info.txt", "r");
    racer = creat_list(fp3);
    sort (racer);
    for (i=0; i<10; i++) {
        printf ("%s %d %lf\n", racer->playername, racer->last_level, racer->score);
        racer = racer->next;
    }
    free (racer);
    fclose (fp3);
}

int main()
{
    char  name[40];
    char kalame[40];
    FILE *fp;
    struct node *list = (struct node *)malloc(sizeof (struct node)) ;
    int x, y, i = 0, level, wrong = 0, number, op_fi;
    char alph, answer, javab;
    double word_score, level_score, duration, sum = 0.0;
    clock_t start, end;
    struct info *racer = (struct info *)malloc(sizeof (struct info));
    HANDLE hout = GetStdHandle (STD_OUTPUT_HANDLE);
    system ("color 74");
    printf ("please enter your name:D\n");
    scanf (" %s", name);
    system ("cls");
    printf ("Hi %s :-) \nAre you ready to play?\n", name);
    printf (" 1)Play a new game \n 2)Resume an old game\n");
    scanf ("%d", &x);
    while (x != 1 && x != 2) {
        system ("cls");
        printf ("wrong input,please try again\n 1)Play a new game \n 2)Resume an old game\n");
        scanf ("%d", &x);
    }
    op_fi = find_upest_level();
    if (x == 1) {
        system("cls");
        printf ("Please enter the level you want to play(you can choose at most level %d)\n", op_fi);
        scanf ("%d", &y);
        while ((y > op_fi) || (y < 1)) {
            system ("cls");
            printf ("wrong input,please try again\n");
            scanf ("%d", &y);
        }
    }
    if (x == 2) {
        level = remind (name);
        if(level == op_fi) {
            system ("cls");
            printf ("Dear player there is not any upper level\n");
            return -1;
        }
        else if (level == 11) {
            system("cls");
            printf("dear %s,you haven't play up to now", name);
            return -1;
        }
        else
            y = level+1;
    }
    while (1) {
        fp = opening_func (y);
        if (fp == NULL)
        {
            system ("cls");
            printf ("File didn't open:-|\n");
            return -1;
        }
        list = creat_node (fp);
        number = num_of_list_word (list);
        while (number != 0)
        {
            strcpy (kalame, choose_word (list, number));
            system ("cls");
            SetConsoleTextAttribute (hout, 252);
            printf (" %s\n", kalame);
            SetConsoleTextAttribute (hout, 15);
            start = clock ();
            while (kalame[i] != '\0') {
                do {
                    alph=getch();
                    if (alph == 'Q')
                        exit (0);
                    if (alph == 'P')
                        while (alph != 'R') {
                            alph = getch();
                            if (alph == 'R')
                                break;
                        }
                    if (alph != kalame[i])
                        wrong++;
                }
                while (kalame[i] != alph);

                kalame[i] = make_upper (kalame[i]);
                system ("cls");
                SetConsoleTextAttribute (hout, 252);
                printf (" %s\n", kalame);
                SetConsoleTextAttribute (hout,15);
                i++;
            }

            end = clock ();
            number--;
            duration = ( (double)(end - start)) / CLOCKS_PER_SEC;
            wrong = wrong - i;
            word_score = word_scoring (duration, i, wrong);
            sum += word_score;
            i = 0;
        }
        fclose (fp);
        level_score += level_scoring (sum, number);
        system ("cls");
        printf ("You'r level score is %lf\n", level_scoring (sum, number));
        printf ("Do you want to play next level?[Y/N]\n");
        scanf (" %c", &answer);
        if (answer ==  'N') {
            system ("cls");
            printf ("Do you want to save you'r score?:-)[Y/N]\n");
            scanf (" %c", &javab);
            if (javab == 'N') {
                system ("cls");
                printf ("If you want to see first 10 user press F,otherwise press A\n");
                alph = getch ();
                if (alph == 'F')
                    first_10_user ();
                return -1;
            }
            else if (javab == 'Y') {
                save_info ( name, y, level_score);
                system ("cls");
                printf ("If you want to see first 10 user press F,otherwise press A\n");
                alph = getch();
                if (alph == 'F')
                    first_10_user ();
                return -1;
            }
        }
        else if (answer == 'Y') {
            y++;
            if (y == 10) {
                system ("cls");
                printf ("There is no upper level");
                return 0;
            }
        }
    }
    free (list);
    free (racer);
    return 0;
}
