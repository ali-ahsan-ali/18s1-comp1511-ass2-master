// intensity.c
// Assignment 2, COMP1511 18s1: Intensity
//
// This program by Ali Ali (z5207397) on 12-05-18
//
// Version 1.0.1: Minor changes to wording of comments.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <assert.h>

// SOME USEFUL #defines - YOU WILL NEED MORE

#define ACTION_PLAYER_NAME           0
#define ACTION_DISCARD               1
#define ACTION_PLAY_CARD             2
#define ACTION_UNIT_TESTS            3

#define N_CARDS                      40
#define N_CARDS_INITIAL_HAND         10
#define N_PLAYERS                    4
#define N_CARDS_DISCARDED            3
#define FULL_HAND                    10
#define LAST_CARD                    1
#define LAST_PLAYER_IN_ROUND         3
#define FIRST_PLAYER_IN_ROUND        0

#define CARD_MIN                     10
#define CARD_MAX                     49
#define TRUE                         99
#define FALSE                        98
#define NO_POSSIBLE_PLAY             97



// ADD EXTRA #defines HERE

void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);


// ADD PROTOTYPES FOR YOUR FUNCTIONS HERE


int optimal_play(int hand_size,int hand_number, int player_hand[hand_size],
                 int should_be_0,int array3[1]);

int play_buffalo(int hand_size, int hand_number, int player_hand[hand_size],
                 int should_be_0,int array3[1]);

int legal_move(int hand_size, int f_cards_played_current_round,
               int do_not_enter_legal_play_function, int counter_40,
               int counter_30, int counter_20, int counter_10,int hand_number,
               int player_hand[hand_size],int should_be_0,int array3[1],
               int cards_played[f_cards_played_current_round]);
int legal_move_last_player(int hand_size, int f_cards_played_current_round,
                           int do_not_enter_legal_play_function, int counter_40,
                           int counter_30, int counter_20, int counter_10,
                           int hand_number, int player_hand[hand_size],
                           int should_be_0, int array3[1],
                           int cards_played[f_cards_played_current_round]);
int legal_move_last_v2(int hand_size, int f_cards_played_current_round,int
                       do_not_enter_legal_play_function, int counter_40,
                       int counter_30,
                       int counter_20, int counter_10,int hand_number,
                       int player_hand[hand_size],int should_be_0, int array3[1],
                       int cards_played[f_cards_played_current_round]);

int check_if_calf_is_legal_move(int o,int previous_cards_played,
                                int array2[previous_cards_played]);

int reduce_highest_card(int hand_size, int hand_number,
                        int player_hand[hand_size],
                        int should_be_0,int array3[1]);

int optimal_play_calves(int hand_size,int array3[1],int hand_number,
                        int should_be_0,int player_hand[hand_size]);

int play_calf_highest(int hand_size,int hand_number,int should_be_0,
                      int player_hand[hand_size], int array3[1]);
int play_calf_lowest(int hand_size,int hand_number,int should_be_0,
                     int player_hand[hand_size], int array3[1]);

int check_if_point_card_has_been_played(int cards_played[3]);



int check_if_40_suit_round(int cards_played[1],int should_be_0);


int else_function(int hand_size, int f_cards_played_current_round,
                  int cards_played_current_round,int counter_30,int counter_20,
                  int do_not_enter_legal_play_function, int counter_40,
                  int counter_10,int hand_number, int player_hand[hand_size],
                  int should_be_0, int array3[1],int o,
                  int previous_cards_played, int array2[previous_cards_played],
                  int cards_played[f_cards_played_current_round]);

int if_last_function(int hand_size, int f_cards_played_current_round,
                     int cards_played_current_round,int counter_40,int o,
                     int counter_30,int do_not_enter_legal_play_function,
                     int counter_20, int counter_10,int hand_number,
                     int player_hand[hand_size],int should_be_0, int array3[1],
                     int cards_played[f_cards_played_current_round],
                     int previous_cards_played,
                     int array2[previous_cards_played]);

int if_first_function(int hand_size,int hand_number,int o,
                      int previous_cards_played,
                      int array2[previous_cards_played],
                      int f_cards_played_current_round, int array3[1],
                      int cards_played_current_round,
                      int do_not_enter_legal_play_function,
                      int player_hand[hand_size],int should_be_0);

int player_hand_card_count_10(int i,int hand_size,int player_hand[hand_size]);

int player_hand_card_count_20(int i,int hand_size,int player_hand[hand_size]);

int player_hand_card_count_30(int i,int hand_size,int player_hand[hand_size]);

int player_hand_card_count_40(int i,int hand_size,int player_hand[hand_size]);

int find_array4_10(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]);

int find_array4_20(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]);

int find_array4_30(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]);

int find_array4_40(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]);

int finding_optimal_array3_10(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_10, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]);

int finding_optimal_array3_20(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_20, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]);

int finding_optimal_array3_30(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_30, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]);

int finding_optimal_array3_40(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_40, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]);


int least_optimal_array3_10(int exit_while_loop,int move_available,
                            int array3[1], int counter_10,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]);

int least_optimal_array3_20(int exit_while_loop,int move_available,
                            int array3[1], int counter_20,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]);

int least_optimal_array3_30(int exit_while_loop,int move_available,
                            int array3[1], int counter_30,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]);

int least_optimal_array3_40(int exit_while_loop,int move_available,
                            int array3[1], int counter_40,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]);

int suit_10 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function);

int suit_20 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function);

int suit_30 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function);

int suit_40 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function);
int check_if_30_suit_hand(int hand_number, int hand_size,
                          int player_hand[hand_size]);


// You should not need to change this main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    } else {
        run_unit_tests();
    }
    
    return 0;
}

void print_player_name(void) {
    // CHANGE THIS PRINTF TO YOUR DESIRED PLAYER NAME
    printf("bilch");
    
}

void choose_discards() {
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARDS YOU WISH TO DISCARD
    int player_hand[N_CARDS_INITIAL_HAND];
    int discard_hand[N_CARDS_DISCARDED];
    int i = 0;
    int lol = 0;
    int hand_number = 0;
    int should_be_3 = 0;
    int hand_size = N_CARDS_INITIAL_HAND;
    int exit_while_loop = FALSE;
    
    // Scan in hand
    
    while (i < N_CARDS_INITIAL_HAND){
        scanf("%d", &player_hand[i]);
        i++;
    }
    //Discard the highest card excluding 30 suits and card 47.
    //Keep these play and make other poeple get points
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 19 && player_hand[hand_number] != 29
                && player_hand[hand_number] != 49)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
        exit_while_loop = FALSE;
        hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 18 && player_hand[hand_number] != 28
                && player_hand[hand_number] != 48)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
            (player_hand[hand_number] != 17 && player_hand[hand_number] != 27)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 16 && player_hand[hand_number] != 26
                && player_hand[hand_number] != 46)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 15 && player_hand[hand_number] != 25
                && player_hand[hand_number] != 45)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 14 && player_hand[hand_number] != 24
                && player_hand[hand_number] != 44)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 13 && player_hand[hand_number] != 23
                && player_hand[hand_number] != 43)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
           exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 12 && player_hand[hand_number] != 22
                && player_hand[hand_number] != 42)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED
           && exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 11 && player_hand[hand_number] != 21
                && player_hand[hand_number] != 41)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }
    exit_while_loop = FALSE;
    hand_number = 0;
    while (hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED
           && exit_while_loop == FALSE){
        while (  hand_number < hand_size && should_be_3 < N_CARDS_DISCARDED &&
               (player_hand[hand_number] != 10 && player_hand[hand_number] != 20
                && player_hand[hand_number] != 40)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   discard_hand[should_be_3] = player_hand[hand_number];
                   player_hand[hand_number] = 0;
                   should_be_3++;
               }else{
                   exit_while_loop++;
               }
    }

    
    while (lol < N_CARDS_DISCARDED){
        printf("%d ", discard_hand[lol]);
        lol++;
    }
}
void choose_card_to_play(void) {
    int hand_size  = 0;
    int cards_played_current_round = 0;
    int table_position = 0;
    scanf("%d %d %d", &hand_size, &cards_played_current_round, &table_position);
    int f_cards_played_current_round = cards_played_current_round;
    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int player_hand[N_CARDS_INITIAL_HAND];
    int i = 0;
    int counter_10 = 0;
    int counter_20 = 0;
    int counter_40 = 0;
    int counter_30 = 0;
    while ( i < hand_size){
        scanf("%d", &player_hand[i]);
        if(player_hand_card_count_10( i, hand_size,player_hand) == TRUE){
            counter_10++;
        }
        if (player_hand_card_count_20( i,hand_size, player_hand) == TRUE){
            counter_20++;
        }
        if (player_hand_card_count_30( i,hand_size, player_hand) == TRUE){
            counter_30++;
        }
        if (player_hand_card_count_40( i, hand_size, player_hand) == TRUE){
            counter_40++;
        }
        i++;
    }
    // ADD CODE TO READ THE CARDS PLAYED THIS ROUND INTO AN ARRAY USING SCANF
    int cards_played[N_CARDS_INITIAL_HAND];
    int l = 0;
    while(cards_played_current_round != 0 && l < cards_played_current_round){
        scanf("%d", &cards_played[l]);
        l++;
    }
    // ADD CODE TO READ THE CARDS PREVIOUS ROUND INTO AN ARRAY USING SCANF
    int previous_cards_played = (10 - hand_size) * 4;
    if (hand_size == 10){
        previous_cards_played = 1;
    }
    int array2[previous_cards_played];
    int o = 0;
    while ( o < previous_cards_played){
        scanf("%d", &array2[o]);
        o++;
    }
    
    // THEN ADD YOUR CODE HERE TO CHOOSE AND PRINT THE CARD YOU WISH TO PLAY
    int array3[1] = {1};
    int hand_number = 0;
    int should_be_0 = 0;
    int do_not_enter_legal_play_function = 0;
    int do_not_enter_else_function = TRUE;
    // logic to playing a round
    /* if you are going first, make a legal move if possible. Or else play the
     buffalo (unless its a 40 suit round). If you do not have the buffalo, or it
     is a 40 suit round then continue with the logic of being 2nd,3rd or 4th
     in the round. The logic will be explained below, above other functions*/
    if (hand_size == FULL_HAND &&
        f_cards_played_current_round != FIRST_PLAYER_IN_ROUND){
        array3[0]= legal_move( hand_size,  f_cards_played_current_round,
                              do_not_enter_legal_play_function,  counter_40,
                              counter_30, counter_20, counter_10,
                              hand_number,  player_hand, should_be_0,  array3,
                              cards_played);
        if (check_if_40_suit_round(cards_played, should_be_0) == FALSE
            && array3[0] == NO_POSSIBLE_PLAY){
            
            array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                      should_be_0, array3);
            if (array3[0] == NO_POSSIBLE_PLAY){
                if (f_cards_played_current_round == LAST_PLAYER_IN_ROUND){
                    array3[0] = if_last_function(hand_size,
                                                 f_cards_played_current_round
                                                 ,cards_played_current_round,
                                                 counter_40,o,counter_30,
                                                 do_not_enter_legal_play_function
                                                 ,counter_20, counter_10,
                                                 hand_number,player_hand,
                                                 should_be_0, array3,
                                                 cards_played,
                                                 previous_cards_played,
                                                 array2);
                }else{
                    array3[0] = else_function(hand_size,
                                              f_cards_played_current_round,
                                  cards_played_current_round,counter_30,
                                  counter_20,do_not_enter_legal_play_function,
                                  counter_40,counter_10,hand_number,
                                  player_hand,should_be_0, array3,o,
                                  previous_cards_played, array2,
                                  cards_played);
                }
                do_not_enter_else_function++;
            }
        }if (array3[0] == NO_POSSIBLE_PLAY) {
                if (f_cards_played_current_round == LAST_PLAYER_IN_ROUND){
                    array3[0] = if_last_function(hand_size,
                                                 f_cards_played_current_round
                                                 ,cards_played_current_round,
                                                 counter_40,o,counter_30,
                                                 do_not_enter_legal_play_function
                                                 ,counter_20, counter_10,
                                                 hand_number,player_hand,
                                                 should_be_0, array3,
                                                 cards_played,
                                                 previous_cards_played,
                                                 array2);
                }else{
                    else_function(hand_size, f_cards_played_current_round,
                                  cards_played_current_round,counter_30,
                                  counter_20,do_not_enter_legal_play_function,
                                  counter_40,counter_10,hand_number,
                                  player_hand,should_be_0, array3,o,
                                  previous_cards_played, array2,
                                  cards_played);
                }
        }
        //do_not_enter_else_function is to ensure that you do not override
        //the above by entering the else function
        do_not_enter_else_function++;
    }if (cards_played_current_round == FIRST_PLAYER_IN_ROUND){
        if_first_function(hand_size,hand_number,o,previous_cards_played,
                          array2,f_cards_played_current_round, array3,
                          cards_played_current_round,
                          do_not_enter_legal_play_function,
                          player_hand,should_be_0);
        do_not_enter_else_function++;
    }if (hand_size == LAST_CARD){
        array3[0] = player_hand[0];
        do_not_enter_else_function++;
    }if (f_cards_played_current_round == LAST_PLAYER_IN_ROUND){
        array3[0] =  if_last_function(hand_size,f_cards_played_current_round,
                                      cards_played_current_round,counter_40,o,
                                      counter_30,
                                      do_not_enter_legal_play_function,
                                      counter_20, counter_10,hand_number,
                                      player_hand,should_be_0, array3,
                                      cards_played,previous_cards_played,
                                    array2);
        do_not_enter_else_function++;
        //executes if none of the above is true(like an else statement)
    }if(do_not_enter_else_function == TRUE){
        array3[0] = else_function(hand_size, f_cards_played_current_round,
                      cards_played_current_round,counter_30,counter_20,
                      do_not_enter_legal_play_function, counter_40,
                      counter_10,hand_number, player_hand,
                      should_be_0, array3, o,previous_cards_played, array2,
                      cards_played);
    }
    // PLAY A CARD FROM YOUR HAND.
    printf("%d\n", array3[0]);
}


/* TESTING STRATEGY
Check every function that doesn't involve legal_function.
I am not checking the legal_function as that is split up into too many parts to
accurately test and is the core of our program. i.e. finding_optimal_array3_10
will crash instead of NO_POSSIBLE_PLAY(as there is no legal_play && value of
 array4[0] is set to find_array4_X0(0 ,1 ,2 ,2 ,0 ,3 , cards_played),
 which returns an int into an array. Also if the function fails, it is set to
 1 and no player_hand[g] is less than 10. Hence, cannot be less than 1.
The intensity_referee or ./intensity commands are more accurate
in wholistically testing the function. This is also true for the logic
else/if_first/if_last functions. */
void run_unit_tests(void) {
    int player_hand[10] = {10,20,31,40,12,13,14,15,39,17};
    int cards_played[3] = {46,31,42};
    int array2[3] = {30,12,13};
    int array3[1] = {NO_POSSIBLE_PLAY};
    assert(player_hand_card_count_10(0, 10, &player_hand[0]) == TRUE);
    assert(player_hand_card_count_20(0, 10, &player_hand[1]) == TRUE);
    assert(player_hand_card_count_30(0, 10, &player_hand[2]) == TRUE);
    assert(player_hand_card_count_40(0, 10, &player_hand[3]) == TRUE);
    assert(check_if_40_suit_round(&cards_played[0],0) == TRUE);
    assert(check_if_point_card_has_been_played(&cards_played[0]) == TRUE);
    //both relay the highest card, one with and one without calves
    assert(reduce_highest_card( 10, 0, &player_hand[0], 0, array3) == 39);
    assert(check_if_calf_is_legal_move(2 ,0,&array2[3]) == TRUE);
    assert(suit_10(&cards_played[0], 0, 0,0) == FALSE);
    assert(suit_20(&cards_played[0], 0, 0,0) == FALSE);
    assert(suit_30(&cards_played[0], 0, 0,0) == FALSE);
    assert(suit_40(&cards_played[0], 0, 0,0) == TRUE);
    assert(find_array4_10(0 ,1 ,2 ,2 ,0 ,3 , cards_played) == 1);
    assert(find_array4_20(0 ,1 ,2 ,2 ,0 ,3 , cards_played) == 1);
    assert(find_array4_30(0 ,1 ,2 ,2 ,0 ,3 , cards_played) == 1);
    assert(find_array4_40(0 ,1 ,2 ,2 ,0 ,3 , cards_played) == 46);
    //returns 31 as it is the only calf in hand
    assert(play_calf_highest(10, 0, 0, player_hand, array3) == 39);
    //returns NO_POSSIBLE_PLAY rather than 31 due to
    //if(should_be_0  = 0){return NO_POSSIBLE_PLAY};
    assert(play_buffalo( 10,0,player_hand,0, array3) == NO_POSSIBLE_PLAY);
    //borth return the same value as 10 is the lowest card of the lowest suit
    assert(optimal_play(10,0, player_hand,0,array3) == 10);
    assert(optimal_play_calves(10,array3,0,0,player_hand) == 10 );
    
}

// ADD YOUR FUNCTIONS HERE
//4 functions below counts amount of cards in each suit
int player_hand_card_count_10( int i,int hand_size,int player_hand[hand_size]){
    if (player_hand[i] == 10 || player_hand[i] == 11 ||
        player_hand[i] == 12 || player_hand[i] == 13 ||
        player_hand[i] == 14 || player_hand[i] == 15 ||
        player_hand[i] == 16 || player_hand[i] == 18 ||
        player_hand[i] == 17 || player_hand[i] == 19){
        return TRUE;
    }
    return FALSE;
}
int player_hand_card_count_20(int i,int hand_size,int player_hand[hand_size]){
    if (player_hand[i] == 20 || player_hand[i] == 21 ||
        player_hand[i] == 22 || player_hand[i] == 23 ||
        player_hand[i] == 24 || player_hand[i] == 25 ||
        player_hand[i] == 26 || player_hand[i] == 28||
        player_hand[i] == 27 || player_hand[i] == 29){
        return TRUE;
    }
    return FALSE;
}
int player_hand_card_count_30(int i,int hand_size,int player_hand[hand_size]){
    if (player_hand[i] == 30 || player_hand[i] == 31 ||
        player_hand[i] == 32 || player_hand[i] == 33 ||
        player_hand[i] == 43 || player_hand[i] == 35 ||
        player_hand[i] == 36 || player_hand[i] == 38 ||
        player_hand[i] == 37 || player_hand[i] == 39){
        return TRUE;
    }
    return FALSE;
}
int player_hand_card_count_40(int i,int hand_size,int player_hand[hand_size]){
    if (player_hand[i] == 40 || player_hand[i] == 41 ||
        player_hand[i] == 42 || player_hand[i] == 43 ||
        player_hand[i] == 44 || player_hand[i] == 45 ||
        player_hand[i] == 46 || player_hand[i] == 48 ||
        player_hand[i] == 49){
        return TRUE;
    }
    return FALSE;
}

/* First make sure you do not enter the legal_play_function as
 that uses previously played cards (in the current round). This will set an
 array size to be 0, which will cause compiler issues.
 
 Next is to see if calves are allowed to be played as the first card, by
 checking if a calf has been previously played. If so play the lowest card
 possible, including calves.
 
 If a calf cannot be played, play the lowest possible
 excluding calves.
 
 If a calf cannot be played, but your hand only consists of calves,
 play the lowest card/calf including calves(obviously).
 
 If you cannot do any of the above, play a buffalo (as it is
 the only card unaccounted for within my code*/

int if_first_function(int hand_size,int hand_number,int o,
                     int previous_cards_played,
                     int array2[previous_cards_played],
                     int f_cards_played_current_round, int array3[1],
                     int cards_played_current_round,
                     int do_not_enter_legal_play_function,
                     int player_hand[hand_size],int should_be_0){
    f_cards_played_current_round = 1;
    do_not_enter_legal_play_function = 1;
    if(check_if_calf_is_legal_move( o,previous_cards_played, array2) == TRUE){
        array3[0] = optimal_play_calves(hand_size,array3,hand_number,
                                        should_be_0, player_hand);
        //hand is only cards of 30 and are forced to play calves
    }else if (check_if_calf_is_legal_move( o,previous_cards_played, array2)
              == FALSE && check_if_30_suit_hand( hand_number,  hand_size,
                                                 player_hand) == TRUE){
              array3[0] = optimal_play_calves(hand_size,array3,hand_number,
                                                  should_be_0, player_hand);
    }else{
        array3[0] =  optimal_play(hand_size, hand_number, player_hand,
                                  should_be_0,array3);
        
        if ( array3[0] == NO_POSSIBLE_PLAY){
            //rather play high card i.e 29
            //then start a round of 30 or play a 47 and gain 4/7 points
            //last resort. Don't  start a fight you cannot finish, or
            //dont blindly play a 47, but it is forced if a calf hasn't
            //been played before
            array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                          should_be_0,array3);
                
                if ( array3[0] == NO_POSSIBLE_PLAY){
                    array3[0] =   play_calf_lowest(hand_size,hand_number,
                                                    should_be_0,
                                                    player_hand,  array3);
                }
        }
    }
    int x = array3[0];
    return x;
}
/* If you are playing last, check to see if a calf/buffalo has been played in
 the round.
 
 If so, play a legal move with the highest possible number, as losing will
 incur in no points. If there is no legal play, then play calf/buffalo.
 If you cannot do the above then play the highest number card you have
 (19,29,49) and so on.
 
 If not, follow else_function logic
 (Play the lowest card needed(below the highest card already played)
 If no legal moves, play calf/buffalo or reduce the highest card in your hand)
 */
int if_last_function(int hand_size, int f_cards_played_current_round,
                     int cards_played_current_round,int counter_40,int o,
                     int counter_30,int do_not_enter_legal_play_function,
                     int counter_20, int counter_10,int hand_number,
                     int player_hand[hand_size],int should_be_0, int array3[1],
                     int cards_played[f_cards_played_current_round],
                     int previous_cards_played,
                     int array2[previous_cards_played]){
    if(check_if_point_card_has_been_played( cards_played) == FALSE){
        array3[0] =  legal_move_last_player( hand_size,
                                            f_cards_played_current_round,
                                            do_not_enter_legal_play_function,
                                            counter_40, counter_30, counter_20,
                                            counter_10,hand_number, player_hand,
                                            should_be_0,  array3, cards_played);
        if ( array3[0] == NO_POSSIBLE_PLAY){
            array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                      should_be_0,array3);
            if( array3[0] == NO_POSSIBLE_PLAY){
                array3[0] =   play_calf_highest(hand_size,hand_number,
                                                should_be_0,
                                                player_hand,  array3);
                if ( array3[0] == NO_POSSIBLE_PLAY){
                    array3[0] =  reduce_highest_card(hand_size,
                                                     hand_number, player_hand,
                                                     should_be_0, array3);
                }
            }
        }
        //Below is the else_function with the only change being legal_move_last_
        //v2, which plays the highest card from a suit if the program knows
        //you have lost the round
    }else{
        if (check_if_40_suit_round(cards_played, should_be_0) == TRUE){
            array3[0] =  legal_move( hand_size,  f_cards_played_current_round,
                                    do_not_enter_legal_play_function,
                                    counter_40,
                                    counter_30, counter_20, counter_10,
                                    hand_number,
                                    player_hand, should_be_0, array3,
                                    cards_played);
            if (array3[0] == NO_POSSIBLE_PLAY) {
                array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                          should_be_0, array3);
                if (array3[0] == NO_POSSIBLE_PLAY ){
                    array3[0] =  play_calf_highest( hand_size, hand_number,
                                                   should_be_0,
                                                   player_hand,  array3);
                    if (array3[0] == NO_POSSIBLE_PLAY){
                        array3[0] =  reduce_highest_card( hand_size,
                                                         hand_number,
                                                         player_hand,
                                                         should_be_0, array3);
                    }
                }
            }
        }else{
            array3[0] =  legal_move_last_v2( hand_size,
                                            f_cards_played_current_round,
                                            do_not_enter_legal_play_function,
                                            counter_40, counter_30, counter_20,
                                            counter_10,hand_number,player_hand,
                                            should_be_0, array3,cards_played);
            if ( array3[0] == NO_POSSIBLE_PLAY){
                array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                          should_be_0, array3);
                if (array3[0] == NO_POSSIBLE_PLAY ){
                    array3[0] =  play_calf_highest( hand_size, hand_number,
                                                   should_be_0,
                                                   player_hand, array3);
                    if (array3[0] == NO_POSSIBLE_PLAY){
                        array3[0] =  reduce_highest_card( hand_size,
                                                         hand_number,
                                                         player_hand,
                                                         should_be_0, array3);
                    }
                }
            }
        }
    }

    int x = array3[0];
    
    return x;
}
/*
 
 If you are 2nd or 3rd. Make a legal move, if not play a buffalo, or calf, or
 reduce the highest card in your hand
 
 If it is a 40 suit round, NEVER PLAY A 47 IF YOU HAVE ANOTHER CARD TO PLAY
 2
 6 2 0
 24 32 37 38 47 49
 45 41
 Program would play 47 here, and gain 7 points itself rather than playing the 49
 otherwise.
 */

int else_function(int hand_size, int f_cards_played_current_round,
                  int cards_played_current_round,int counter_30,int counter_20,
                  int do_not_enter_legal_play_function, int counter_40,
                  int counter_10,int hand_number, int player_hand[hand_size],
                  int should_be_0, int array3[1],int o,int previous_cards_played,
                  int array2[previous_cards_played],
                  int cards_played[f_cards_played_current_round]){
    if (check_if_40_suit_round(cards_played, should_be_0) == TRUE){
    array3[0] =  legal_move( hand_size,  f_cards_played_current_round,
                            do_not_enter_legal_play_function, counter_40,
                            counter_30, counter_20, counter_10,hand_number,
                            player_hand, should_be_0, array3, cards_played);
        if (array3[0] == NO_POSSIBLE_PLAY) {
            array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                      should_be_0, array3);
            if (array3[0] == NO_POSSIBLE_PLAY ){
                array3[0] =  play_calf_highest( hand_size, hand_number,
                                               should_be_0,
                                           player_hand,  array3);
                if (array3[0] == NO_POSSIBLE_PLAY){
                    array3[0] =  reduce_highest_card( hand_size,
                                                 hand_number, player_hand,
                                                 should_be_0, array3);
                }
            }
        }
    }else{
        array3[0] =  legal_move( hand_size,  f_cards_played_current_round,
                                do_not_enter_legal_play_function, counter_40,
                                counter_30, counter_20, counter_10,hand_number,
                                player_hand, should_be_0, array3, cards_played);
        if ( array3[0] == NO_POSSIBLE_PLAY){
            array3[0] =  play_buffalo( hand_size,hand_number,player_hand,
                                      should_be_0, array3);
            if (array3[0] == NO_POSSIBLE_PLAY ){
                array3[0] =  play_calf_highest( hand_size, hand_number,
                                               should_be_0,
                                               player_hand, array3);
                if (array3[0] == NO_POSSIBLE_PLAY){
                    array3[0] =  reduce_highest_card( hand_size,
                                                     hand_number, player_hand,
                                                     should_be_0, array3);
                }
            }
        }
    }
    int x = array3[0];
    return x;
}
//literal name
int check_if_40_suit_round(int cards_played[1],int should_be_0){
    
    if (should_be_0 == 0 && (cards_played[0] == 40 ||cards_played[0] == 41 ||
                            cards_played[0] == 42 ||cards_played[0] == 43 ||
                            cards_played[0] == 44 ||cards_played[0] == 45 ||
                            cards_played[0] == 46 ||cards_played[0] == 47 ||
                            cards_played[0] == 48 ||cards_played[0] == 49)){
        return TRUE;
    }else{
        return FALSE;
    }
    return 1;
}
int check_if_30_suit_hand(int hand_number, int hand_size,
                          int player_hand[hand_size]){
    while (hand_number < hand_size && player_hand[hand_number] % 30 >= 0
        && player_hand[hand_number] % 30 <= 9){
        hand_number++;
    }if(hand_size != hand_number){
        return FALSE;
    }else{
        return TRUE;
    }
    return 1;
}

//checks if calf/buffalo has been played in current round
int check_if_point_card_has_been_played(int cards_played[3]){
    int previous_round_array_position = 0;
    while (previous_round_array_position < 3 &&
           (cards_played[previous_round_array_position] != 39 &&
            cards_played[previous_round_array_position] != 38 &&
            cards_played[previous_round_array_position] != 37 &&
            cards_played[previous_round_array_position] != 36 &&
            cards_played[previous_round_array_position] != 35 &&
            cards_played[previous_round_array_position] != 34 &&
            cards_played[previous_round_array_position] != 33 &&
            cards_played[previous_round_array_position] != 32 &&
            cards_played[previous_round_array_position] != 31 &&
            cards_played[previous_round_array_position] != 30 &&
            cards_played[previous_round_array_position] != 47)){
        previous_round_array_position ++;
    }if (previous_round_array_position != 3){
        return TRUE;
    }else{
        return FALSE;
    }
    return 1;
}
//literal name
int reduce_highest_card(int hand_size,int hand_number,
                        int player_hand[hand_size],
                        int should_be_0, int array3[1]){
    int x = NO_POSSIBLE_PLAY;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 9){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 8 ){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 7 ){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 6){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while ( hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 5 ){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while ( hand_number < hand_size &&  should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 4 ){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while ( hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 3){
            hand_number++;
        }if ( hand_number < hand_size && hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 2 ){
            hand_number++;
        }if (hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 1 ){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 0){
            hand_number++;
        }if ( hand_number != hand_size){
            x = player_hand[hand_number];
            should_be_0++;
        }
    }
    return x;
}
//function does its literal name, used for if 'bilch' goes first
//attempts to play the highest card available which is lower than
//other cards played in this round, otherwise just play the lowest card
int check_if_calf_is_legal_move(int o,int previous_cards_played,
                                int array2[previous_cards_played]){
    int previous_round_array_position = 0;
    while (previous_round_array_position < o &&
           (array2[previous_round_array_position] != 39 &&
            array2[previous_round_array_position] != 38 &&
            array2[previous_round_array_position] != 37 &&
            array2[previous_round_array_position] != 36 &&
            array2[previous_round_array_position] != 35 &&
            array2[previous_round_array_position] != 34 &&
            array2[previous_round_array_position] != 33 &&
            array2[previous_round_array_position] != 32 &&
            array2[previous_round_array_position] != 31 &&
            array2[previous_round_array_position] != 30)){
               previous_round_array_position ++;
           }if (previous_round_array_position != o){
               return TRUE;
           }else{
               return FALSE;
           }
    return 1;
}

/*Check what suit the first card played in the round was.
 
 Place highest card played in the round into array4[0].
 
 Check from the top of your hand downwards (using the fact that cards are sorted
 numerically) to find the first card which is below the value of array4[0]
 and in your hand.
 
 If you do not own a card which is lower than array4[0] value then play the
 first card from the suit in your hand accessed from 0 -> 10 (using the fact
 that cards are sorted numerically)
 
 array3[0] is the value of the card being played
 */

int legal_move(int hand_size, int f_cards_played_current_round,int
               do_not_enter_legal_play_function, int counter_40, int counter_30,
               int counter_20, int counter_10,int hand_number,
               int player_hand[hand_size],int should_be_0, int array3[1],
               int cards_played[f_cards_played_current_round]){
    int g = hand_size - 1;
    int array_size = f_cards_played_current_round - 1;
    int move_available = 0;
    int array4[1];
    int pos0 = 0;
    int pos1 = 1;
    int pos2 = 2;
    int biggest = 0;
    int exit_while_loop = 0;
    
    if (suit_10(cards_played, should_be_0,exit_while_loop,
                do_not_enter_legal_play_function) == TRUE){
        array4[0] = find_array4_10( pos0,  pos1,  pos2,  array_size,  biggest,
                                   f_cards_played_current_round, cards_played);
        
        array3[0] = finding_optimal_array3_10(array4,
                                              exit_while_loop, move_available,
                                              array3, counter_10, should_be_0,
                                              g,  hand_size, player_hand);
        
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
         should_be_0 == 0 && suit_20(cards_played, should_be_0,
                                    exit_while_loop,
                                    do_not_enter_legal_play_function) == TRUE){
             
            array4[0] = find_array4_20(pos0, pos1, pos2, array_size, biggest,
                                        f_cards_played_current_round,
                                        cards_played);
             
            array3[0] = finding_optimal_array3_20(array4,exit_while_loop,
                                                  move_available,
                                                  array3, counter_20,
                                                  should_be_0,g,  hand_size,
                                                  player_hand);
     }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
          should_be_0 == 0 && suit_30(cards_played, should_be_0,exit_while_loop,
                                     do_not_enter_legal_play_function) == TRUE){
              
            array4[0] = find_array4_30(pos0, pos1, pos2, array_size, biggest,
                                       f_cards_played_current_round,
                                       cards_played);
              
            array3[0] = finding_optimal_array3_30(array4,exit_while_loop,
                                                  move_available,array3,
                                                  counter_30, should_be_0,
                                                  g, hand_size, player_hand);
              
      }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
           should_be_0 == 0 && suit_40(cards_played, should_be_0,
                                      exit_while_loop,
                                      do_not_enter_legal_play_function)== TRUE){
               //find largest number played previously
            array4[0] = find_array4_40(pos0, pos1, pos2, array_size, biggest,
                                          f_cards_played_current_round,
                                          cards_played);
               
            array3[0] = finding_optimal_array3_40(array4,exit_while_loop,
                                                  move_available,
                                                  array3, counter_40,
                                                  should_be_0,
                                                  g,  hand_size, player_hand);
           }
    int x = array3[0];
    return x;
}
//if you have lost, might as well discard your highest card
int legal_move_last_v2(int hand_size, int f_cards_played_current_round,int
               do_not_enter_legal_play_function, int counter_40, int counter_30,
               int counter_20, int counter_10,int hand_number,
               int player_hand[hand_size],int should_be_0, int array3[1],
               int cards_played[f_cards_played_current_round]){
    int g = hand_size - 1;
    int array_size = f_cards_played_current_round - 1;
    int move_available = 0;
    int array4[1];
    int pos0 = 0;
    int pos1 = 1;
    int pos2 = 2;
    int biggest = 0;
    int exit_while_loop = 0;
    
    if (suit_10(cards_played, should_be_0,exit_while_loop,
                do_not_enter_legal_play_function) == TRUE){
        array4[0] = find_array4_10( pos0,  pos1,  pos2,  array_size,  biggest,
                                   f_cards_played_current_round, cards_played);
        
        array3[0] = finding_optimal_array3_10(array4,
                                              exit_while_loop, move_available,
                                              array3, counter_10, should_be_0,
                                              g,  hand_size, player_hand);
        if (array3[0] < array4[0]){
            array3[0] = least_optimal_array3_10(exit_while_loop,move_available,
                                                array3, counter_10,should_be_0,
                                                g, hand_size, player_hand);
        }
        
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
         should_be_0 == 0 && suit_20(cards_played, should_be_0,
                                     exit_while_loop,
                                     do_not_enter_legal_play_function) == TRUE){
             
         array4[0] = find_array4_20(pos0, pos1, pos2, array_size, biggest,
                                    f_cards_played_current_round,
                                    cards_played);
         
         array3[0] = finding_optimal_array3_20(array4,exit_while_loop,
                                               move_available,
                                               array3, counter_20,
                                               should_be_0,g,  hand_size,
                                               player_hand);
         if (array3[0] < array4[0]){
             array3[0] = least_optimal_array3_20(exit_while_loop,move_available,
                                                 array3, counter_20,should_be_0,
                                                 g, hand_size, player_hand);
         }
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && suit_30(cards_played, should_be_0,exit_while_loop,
                                    do_not_enter_legal_play_function) == TRUE){
                  
        array4[0] = find_array4_30(pos0, pos1, pos2, array_size, biggest,
                                         f_cards_played_current_round,
                                         cards_played);
            
        array3[0] = finding_optimal_array3_30(array4,exit_while_loop,
                                                move_available,array3,
                                                counter_30, should_be_0,
                                                g,hand_size, player_hand);
        if (array3[0] < array4[0]){
            array3[0] = least_optimal_array3_30(exit_while_loop,move_available,
                                                array3, counter_30,should_be_0,
                                                g, hand_size, player_hand);
        }
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && suit_40(cards_played, should_be_0,
                                    exit_while_loop,
                                    do_not_enter_legal_play_function)== TRUE){
                   //find largest number played previously
       array4[0] = find_array4_40(pos0, pos1, pos2, array_size, biggest,
                                  f_cards_played_current_round,
                                  cards_played);
            
       array3[0] = finding_optimal_array3_40(array4,exit_while_loop,
                                             move_available,
                                             array3, counter_40,
                                             should_be_0,
                                             g,  hand_size, player_hand);
        if (array3[0] < array4[0]){
        array3[0] = least_optimal_array3_40(exit_while_loop,move_available,
                                            array3, counter_40,should_be_0,
                                            g, hand_size, player_hand);
        }
   }
    
    int x = array3[0];
    return x;
}
//shows what suit the round started with
int suit_10 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function){
    if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && (cards_played[0] == 10 ||cards_played[0] == 11 ||
                            cards_played[0] == 12 ||cards_played[0] == 13 ||
                            cards_played[0] == 14 ||cards_played[0] == 15 ||
                            cards_played[0] == 16 ||cards_played[0] == 17 ||
                            cards_played[0] == 18 ||cards_played[0] == 19)){
            return TRUE;
        }
    return FALSE;
}
int suit_20 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function){
    if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && (cards_played[0] == 20 ||cards_played[0] == 21 ||
                            cards_played[0] == 22 ||cards_played[0] == 23 ||
                            cards_played[0] == 24 ||cards_played[0] == 25 ||
                            cards_played[0] == 26 ||cards_played[0] == 27 ||
                            cards_played[0] == 28 ||cards_played[0] == 29)){
            return TRUE;
        }
    return FALSE;
}
int suit_30 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function){
    if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && (cards_played[0] == 30 ||cards_played[0] == 31 ||
                            cards_played[0] == 32 ||cards_played[0] == 33 ||
                            cards_played[0] == 34 ||cards_played[0] == 35 ||
                            cards_played[0] == 36 ||cards_played[0] == 37 ||
                            cards_played[0] == 38 ||cards_played[0] == 39)){
            return TRUE;
        }
    return FALSE;
}
int suit_40 (int cards_played[1], int should_be_0, int exit_while_loop,
             int do_not_enter_legal_play_function){
    if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && (cards_played[0] == 40 ||cards_played[0] == 41 ||
                            cards_played[0] == 42 ||cards_played[0] == 43 ||
                            cards_played[0] == 44 ||cards_played[0] == 45 ||
                            cards_played[0] == 46 ||cards_played[0] == 47 ||
                            cards_played[0] == 48 ||cards_played[0] == 49)){
            return TRUE;
        }
    return FALSE;
}
//finds the value of array4[0] = the largest card played current round,
//prior to ur play
int find_array4_10(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]){
    int array4[1] = {1};
    int x = 1;
    if (1 <= array_size && cards_played[pos0] < cards_played[pos1] &&
        cards_played[pos1] >= 10 && cards_played[pos1] < 20){
        array4[0] = cards_played[pos1];
        biggest++;
        if (2 <= array_size && cards_played[pos1] < cards_played[pos2] &&
            cards_played[pos2] >= 10 && cards_played[pos2] < 20){
            array4[0] = cards_played[pos2];
            biggest++;
        }
    }if (biggest == 0 && pos2 <= array_size &&
         cards_played[pos0] < cards_played[pos2] && cards_played[pos2] >= 10
         && cards_played[pos2] < 20){
        array4[0] = cards_played[pos2];
        biggest++;
    }if (biggest == 0 && cards_played[pos0] > 10 && cards_played[pos0] < 20){
        array4[0] = cards_played[pos0];
    }
    x = array4[0];
    return x;
}
int find_array4_20(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]){
    int x = 1;
    int array4[1] = {1};
    if (1 <= array_size && cards_played[pos0] < cards_played[pos1] &&
        cards_played[pos1] >= 20 && cards_played[pos1] < 30){
        array4[0] = cards_played[pos1];
        biggest++;
        if (2 <= array_size && cards_played[pos1] < cards_played[pos2] &&
            cards_played[pos2] >= 20 && cards_played[pos2] < 30){
            array4[0] = cards_played[pos2];
            biggest++;
        }
    }if (biggest == 0 && pos2 <= array_size &&
         cards_played[pos0] < cards_played[pos2] && cards_played[pos2] >= 20
         && cards_played[pos2] < 30){
        array4[0] = cards_played[pos2];
        biggest++;
    }if (biggest == 0 && cards_played[pos0] >= 20 && cards_played[pos0] < 30){
        array4[0] = cards_played[pos0];
    }
    x = array4[0];
    return x;
}
int find_array4_30(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]){
    int x = 1;
    int array4[1] = {1};
    if (1 <= array_size && cards_played[pos0] < cards_played[pos1] &&
        cards_played[pos1] >= 30 && cards_played[pos1] < 40){
        array4[0] = cards_played[pos1];
        biggest++;
        if (2 <= array_size && cards_played[pos1] < cards_played[pos2] &&
            cards_played[pos2] >= 30 && cards_played[pos2] < 40){
            array4[0] = cards_played[pos2];
            biggest++;
        }
    }if (biggest == 0 && pos2 <= array_size &&
         cards_played[pos0] < cards_played[pos2] && cards_played[pos2] >= 30
         && cards_played[pos2] < 40){
        array4[0] = cards_played[pos2];
        biggest++;
    }if (biggest == 0 && cards_played[pos0] > 30 && cards_played[pos0] < 40){
        array4[0] = cards_played[pos0];
    }
    x = array4[0];
    return x;
}
int find_array4_40(int pos0, int pos1, int pos2, int array_size, int biggest,
                   int f_cards_played_current_round,
                   int cards_played[f_cards_played_current_round]){
    int array4[1] = {1};
    int x = 1;
    if (1 <= array_size && cards_played[pos0] < cards_played[pos1] &&
        cards_played[pos1] >= 40 && cards_played[pos1] < 50){
        array4[0] = cards_played[pos1];
        biggest++;
        if (2 <= array_size && cards_played[pos1] < cards_played[pos2] &&
            cards_played[pos2] >= 40 && cards_played[pos2] < 50){
            array4[0] = cards_played[pos2];
            biggest++;
        }
    }if (biggest == 0 && pos2 <= array_size &&
         cards_played[pos0] < cards_played[pos2] && cards_played[pos2] >= 40
         && cards_played[pos2] < 50){
        array4[0] = cards_played[pos2];
        biggest++;
    }if (biggest == 0 && cards_played[pos0] > 40 && cards_played[pos0] < 50){
        array4[0] = cards_played[pos0];
    }
    x = array4[0];
    return x;
}
//finds the highest card that can be played from current hand which is lower
//than array4[0]. If we do not hold that card, play the lowest card from suit
int finding_optimal_array3_10(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_10, int should_be_0,
                              int g, int hand_size,int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_10 && g > -1){
        while ( g > -1 && (player_hand[g] != 10 && player_hand[g] != 11 &&
                           player_hand[g] != 12 && player_hand[g] != 13 &&
                           player_hand[g] != 14 && player_hand[g] != 15 &&
                           player_hand[g] != 16 && player_hand[g] != 17 &&
                           player_hand[g] != 18 && player_hand[g] != 19)){
            g--;
        }if (g!= -1){
            move_available++;
            if (should_be_0 == 0 && player_hand[g] < array4[0]){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }else if (g == -1 && move_available == 0){
                exit_while_loop ++;
            }else {
                g--;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }while (move_available > 0 && should_be_0 == 0){
        g = 0;
        while ( g < hand_size && player_hand[g] != 10 &&
               player_hand[g] != 11 && player_hand[g] != 12 &&
               player_hand[g] != 13 && player_hand[g] != 14  &&
               player_hand[g] != 15 && player_hand[g] != 16  &&
               player_hand[g] != 17 && player_hand[g] != 18  &&
               player_hand[g] != 19){
            g++;
        }if (g!= hand_size){
            array3[should_be_0] = player_hand[g];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}
int finding_optimal_array3_20(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_20, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_20 && g > -1){
        while ( g > -1 && (player_hand[g] != 20 && player_hand[g] != 21 &&
                           player_hand[g] != 22 && player_hand[g] != 23 &&
                           player_hand[g] != 24 && player_hand[g] != 25 &&
                           player_hand[g] != 26 && player_hand[g] != 27 &&
                           player_hand[g] != 28 && player_hand[g] != 29)){
            g--;
        }if (g!= -1){
            move_available++;
            if (should_be_0 == 0 && player_hand[g] < array4[0]){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }else if (g == -1 && move_available == 0){
                exit_while_loop ++;
            }else {
                g--;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }while (move_available > 0 && should_be_0 == 0){
        g = 0;
        while ( g < hand_size && player_hand[g] != 20 &&
               player_hand[g] != 21 && player_hand[g] != 22 &&
               player_hand[g] != 23 && player_hand[g] != 24  &&
               player_hand[g] != 25 && player_hand[g] != 26  &&
               player_hand[g] != 27 && player_hand[g] != 28  &&
               player_hand[g] != 29){
            g++;
        }if (g!= hand_size){
            array3[should_be_0] = player_hand[g];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}
int finding_optimal_array3_30(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_30, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_30 && g > -1){
        while ( g > -1 && (player_hand[g] != 30 && player_hand[g] != 31 &&
                           player_hand[g] != 32 && player_hand[g] != 33 &&
                           player_hand[g] != 34 && player_hand[g] != 35 &&
                           player_hand[g] != 36 && player_hand[g] != 37 &&
                           player_hand[g] != 38 && player_hand[g] != 39)){
            g--;
        }if (g!= -1){
            move_available++;
            if (should_be_0 == 0 && player_hand[g] < array4[0]){
                
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }else if (g == -1 && move_available == 0){
                exit_while_loop ++;
            }else {
                g--;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }while (move_available > 0 && should_be_0 == 0){
        g = 0;
        while (g < hand_size && player_hand[g] != 30 &&
               player_hand[g] != 31 && player_hand[g] != 32 &&
               player_hand[g] != 33 && player_hand[g] != 34  &&
               player_hand[g] != 35 && player_hand[g] != 36  &&
               player_hand[g] != 37 && player_hand[g] != 38  &&
               player_hand[g] != 39){
            g++;
        }if (g!= hand_size){
            array3[should_be_0] = player_hand[g];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}
//excludes 47 as the logic immediately plays 47 after anyways
// and helps reduce use of 47 in 40 suit rounds if other 40 suit cards
//are avilable to play
int finding_optimal_array3_40(int array4[1],
                              int exit_while_loop,int move_available,
                              int array3[1], int counter_40, int should_be_0,
                              int g, int hand_size, int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_40 && g > -1){
        while ( g > -1 && (player_hand[g] != 40 && player_hand[g] != 41 &&
                           player_hand[g] != 42 && player_hand[g] != 43 &&
                           player_hand[g] != 44 && player_hand[g] != 45 &&
                           player_hand[g] != 46 &&
                           player_hand[g] != 48 && player_hand[g] != 49)){
            g--;
        }if (g!= -1){
            move_available++;
            if (should_be_0 == 0 && player_hand[g] < array4[0]){
                
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }else if (g == -1 && move_available == 0){
                exit_while_loop ++;
            }else {
                g--;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }while (move_available > 0 && should_be_0 == 0){
        g = 0;
        while ( g < hand_size && player_hand[g] != 40 &&
               player_hand[g] != 41 && player_hand[g] != 42  &&
               player_hand[g] != 43 && player_hand[g] != 44  &&
               player_hand[g] != 45 && player_hand[g] != 46  &&
               player_hand[g] != 48  && player_hand[g] != 49){
            g++;
        }if (g!= hand_size){
            array3[should_be_0] = player_hand[g];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}
// plays the highest possible card of the same suit as there are no points
//to be gained in current round

int legal_move_last_player(int hand_size, int f_cards_played_current_round,
                           int do_not_enter_legal_play_function, int counter_40,
                           int counter_30, int counter_20, int counter_10,
                           int hand_number, int player_hand[hand_size],
                           int should_be_0, int array3[1],
                           int cards_played[f_cards_played_current_round]){
    int g = hand_size - 1;
    int move_available = 0;
    int exit_while_loop = 0;
    
    if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
        should_be_0 == 0 && suit_10( cards_played, should_be_0,
                                   exit_while_loop,
                                   do_not_enter_legal_play_function) == TRUE){
        array3[0] = least_optimal_array3_10(exit_while_loop,move_available,
                                            array3, counter_10,should_be_0,
                                            g, hand_size, player_hand);
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
         should_be_0 == 0 && suit_20( cards_played, should_be_0,exit_while_loop,
                                    do_not_enter_legal_play_function) == TRUE){
         array3[0] = least_optimal_array3_20(exit_while_loop,move_available,
                                                 array3, counter_20,
                                                 should_be_0,
                                                 g, hand_size, player_hand);
     }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
          should_be_0 == 0 && suit_30( cards_played, should_be_0,exit_while_loop,
                                     do_not_enter_legal_play_function) == TRUE){
          array3[0] = least_optimal_array3_30(exit_while_loop,
                                                  move_available,
                                                  array3, counter_30,
                                                  should_be_0,
                                                  g, hand_size, player_hand);
    }if (exit_while_loop == 0 && do_not_enter_legal_play_function == 0 &&
         should_be_0 == 0 && suit_40(cards_played, should_be_0,exit_while_loop,
                                    do_not_enter_legal_play_function) == TRUE){
         array3[0] = least_optimal_array3_40(exit_while_loop,
                                                   move_available,
                                                   array3, counter_40,
                                                   should_be_0,
                                                   g, hand_size, player_hand);
           }
    int x = array3[0];
    return x;
}
//plays highest card from suit using the numerical ordering of the
//players hand
int least_optimal_array3_10(int exit_while_loop,int move_available,
                            int array3[1], int counter_10,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]){
    
    while (should_be_0 == 0 && move_available < counter_10 && g > -1){
        while ( g > -1 && (player_hand[g] != 10 && player_hand[g] != 11 &&
                           player_hand[g] != 12 &&player_hand[g] != 13  &&
                           player_hand[g] != 14 &&player_hand[g] != 15  &&
                           player_hand[g] != 16 && player_hand[g] != 17 &&
                           player_hand[g] != 18 && player_hand[g] != 19)){
            g--;
        }if (g!= -1){
            if (should_be_0 == 0){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}
int least_optimal_array3_20(int exit_while_loop,int move_available,
                            int array3[1], int counter_20,
                            int should_be_0,
                            int g, int hand_size,int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_20 && g > -1){
        while ( g > -1 && (player_hand[g] != 20 && player_hand[g] != 21 &&
                           player_hand[g] != 22 &&player_hand[g] != 23  &&
                           player_hand[g] != 24 &&player_hand[g] != 25  &&
                           player_hand[g] != 26 && player_hand[g] != 27 &&
                           player_hand[g] != 28 && player_hand[g] != 29)){
            g--;
        }if (g!= -1){
            if (should_be_0 == 0){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}
int least_optimal_array3_30(int exit_while_loop,int move_available,
                            int array3[1], int counter_30,
                            int should_be_0,
                            int g, int hand_size,int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_30 && g > -1){
        while ( g > -1 && (player_hand[g] != 30 && player_hand[g] != 31 &&
                           player_hand[g] != 32 &&player_hand[g] != 33  &&
                           player_hand[g] != 34 &&player_hand[g] != 35  &&
                           player_hand[g] != 36 && player_hand[g] != 37 &&
                           player_hand[g] != 38 && player_hand[g] != 39)){
            g--;
        }if (g!= -1){
            if (should_be_0 == 0){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}

int least_optimal_array3_40(int exit_while_loop,int move_available,
                            int array3[1], int counter_40,
                            int should_be_0,
                            int g, int hand_size, int player_hand[hand_size]){
    while (should_be_0 == 0 && move_available < counter_40 && g > -1){
        while ( g > -1 && (player_hand[g] != 40 && player_hand[g] != 41 &&
                           player_hand[g] != 42 &&player_hand[g] != 44  &&
                           player_hand[g] != 44 &&player_hand[g] != 45  &&
                           player_hand[g] != 46 &&
                           player_hand[g] != 48 && player_hand[g] != 49)){
            g--;
        }if (g!= -1){
            if (should_be_0 == 0){
                array3[should_be_0] = player_hand[g];
                should_be_0++;
            }
        }
    }if (move_available == 0 && should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}

//goes backwards to pick the highest calf(in order to have lower calves when a
//calve round is initiated)
int play_calf_highest(int hand_size,int hand_number,int should_be_0,
                      int player_hand[hand_size], int array3[1]){
    hand_number = hand_size - 1;
    while ( hand_number >= 0 && should_be_0 == 0){
        while (hand_number >= 0 && should_be_0 == 0 &&
               player_hand[hand_number] != 39 && player_hand[hand_number] != 38
               && player_hand[hand_number] != 37 &&
               player_hand[hand_number] != 36 && player_hand[hand_number] != 35
               && player_hand[hand_number] != 34 &&
               player_hand[hand_number] != 33 && player_hand[hand_number] != 32
               && player_hand[hand_number] != 31 &&
               player_hand[hand_number] != 30){
            hand_number--;
        }if ( hand_number != -1 ){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}
int play_calf_lowest(int hand_size,int hand_number,int should_be_0,
                      int player_hand[hand_size], int array3[1]){
    hand_number = 0;
    while ( hand_number >= 0 && should_be_0 == 0){
        while (hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] != 39 && player_hand[hand_number] != 38
               && player_hand[hand_number] != 37 &&
               player_hand[hand_number] != 36 && player_hand[hand_number] != 35
               && player_hand[hand_number] != 34 &&
               player_hand[hand_number] != 33 && player_hand[hand_number] != 32
               && player_hand[hand_number] != 31 &&
               player_hand[hand_number] != 30){
            hand_number++;
        }if ( hand_number != hand_size ){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    int x = array3[0];
    return x;
}

int play_buffalo(int hand_size, int hand_number, int player_hand[hand_size],
                 int should_be_0,int array3[1]){
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] != 47 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
        // If cannot play legal card and cannot play buffalo, play an optimal
        //card.
    }if (should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}



int optimal_play(int hand_size,int hand_number, int player_hand[hand_size],
                 int should_be_0,int array3[1]){
//play your lowest card as the most optimal move (excluding calves and buffalo)
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] != 10 && player_hand[hand_number] != 20
               && player_hand[hand_number] != 40){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] != 11 && player_hand[hand_number] != 21
               &&  player_hand[hand_number] != 41){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 12 && player_hand[hand_number] != 22
                && player_hand[hand_number] != 42)){
                   hand_number++;
               }if (hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 13 && player_hand[hand_number] != 23
                && player_hand[hand_number] != 43)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size &&  should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 14 && player_hand[hand_number] != 24
                && player_hand[hand_number] != 44)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 15 && player_hand[hand_number] != 25
                && player_hand[hand_number] != 45)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 16 && player_hand[hand_number] != 26
                && player_hand[hand_number] != 46)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 17 &&
                player_hand[hand_number] != 27)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 18 && player_hand[hand_number] != 28
                && player_hand[hand_number] != 48)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               (player_hand[hand_number] != 19 && player_hand[hand_number] != 29
                && player_hand[hand_number] != 49)){
                   hand_number++;
               }if ( hand_number != hand_size){
                   array3[should_be_0] = player_hand[hand_number];
                   should_be_0++;
               }
    }
    if (should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}
int optimal_play_calves(int hand_size,int array3[1],int hand_number,
                        int should_be_0,int player_hand[hand_size]){
//play your lowest card as the most optimal move (including calves and buffalo)
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 0 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 1 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 2 ){
            hand_number++;
        }if (hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while (hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 3 ){
            hand_number++;
        }if ( hand_number < hand_size && hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size &&  should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 4 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 5 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 6 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while ( hand_number < hand_size && should_be_0 == 0){
        while ( hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 7){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 8 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    hand_number = 0;
    while (  hand_number < hand_size && should_be_0 == 0){
        while (  hand_number < hand_size && should_be_0 == 0 &&
               player_hand[hand_number] % 10 != 9 ){
            hand_number++;
        }if ( hand_number != hand_size){
            array3[should_be_0] = player_hand[hand_number];
            should_be_0++;
        }
    }
    if (should_be_0 == 0){
        return NO_POSSIBLE_PLAY;
    }
    int x = array3[0];
    return x;
}


