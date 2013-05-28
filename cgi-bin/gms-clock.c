#include <stdio.h>
#include <cgic.h>
#include <string.h>
#include <stdlib.h>
#include "gms.h"
#include "gen_index.h"
#include "gen_clock.h"

int main() 
{
GMS_block_big_clock_head();
GMS_block_body_open();
GMS_block_logo();


GMS_block_big_clock();


GMS_block_body_close();


return 0;
}
