#include <stdio.h>
#include <stdlib.h>

// extern: 他のモジュール（.oファイル）の関数を参照するときに必要な宣言
extern int fee_count, fie_count, foe_count, fum_count;
extern int yylex(void);

int main (int argc, char ** argv)
{
    // cat test.txt | ./count_words
    // で、文字列カウント
    yylex();
    printf("%d %d %d %d\n", fee_count, fie_count, foe_count, fum_count);
    exit(0);
}
