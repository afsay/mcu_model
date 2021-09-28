/*
 * command_parser.h
 *
 *  Created on: Aug 22, 2021
 *      Author: user
 */

#ifndef COMMAND_PARSER_CPP_
#define COMMAND_PARSER_CPP_
/*
#include <string>

class Command{
	char *name;
	//char *args;
public:
	Command(const char* cmd_name){
		name = (char *)malloc(16);
		strcpy(name, cmd_name);
	}

};

#define CMD_COUNT = 5
Command cmd_list[CMD_COUNT] = {Command("help"), Command("")};

class CommandParser{
	Command *cmds = cmd_list;
public:

	void execute(char *cmd){
		return;
	}
};
*/
//Code Example C
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#include "microcontroller.h"
#include "global_vars.h"

char print_buffer[256];

//Type definitions
typedef union {
    char  *s;
    char   c;
    float  f;
} arg_t;

typedef struct {
    const char* name;
    void (*func)(arg_t*);
    const char* args;
    const char* doc;
} cmd_t;

#define MK_CMD(x) void cmd_ ## x (arg_t*)
//Functions definitions
MK_CMD(prompt);
MK_CMD(time);
MK_CMD(start);
MK_CMD(stop);
MK_CMD(reset);
MK_CMD(load);
MK_CMD(disp);
MK_CMD(add);
MK_CMD(mul);
MK_CMD(sqrt);
MK_CMD(exit);
MK_CMD(help);

arg_t *args_parse(const char *s);

//The dispatch table
#define CMD(func, params, help) {#func, cmd_ ## func, params, help}
#define CMDS 12
cmd_t dsp_table[CMDS] ={
    CMD(prompt,"s","Select the prompt for input"),
	CMD(time,"","Display timer counter."),
	CMD(start,"","Start SysTick timer."),
	CMD(stop,"","Stop SysTick timer."),
	CMD(reset,"","Reset timer counter."),
	CMD(load,"cf","Load into register float"),
    CMD(disp,"c","Display register"),
    CMD(add,"ff","Add two numbers"),
    CMD(mul,"ff","Multiply two numbers"),
    CMD(sqrt,"f","Take the square root of number"),
    CMD(exit,"","Exits the interpreter"),
    CMD(help,"","Display this help")};

const char *delim = " \n(,);";
void parse(char *cmd)
{
    const char* tok = strtok(cmd,delim);
    if(!tok)
        return;

    int i=CMDS;
    while(i--) {
        cmd_t cur = dsp_table[i];
        if(!strcmp(tok,cur.name)) {
            arg_t *args = args_parse(cur.args);
            if(args==NULL && strlen(cur.args))
                return;//Error in argument parsing
            cur.func(args);
            free(args);
            return;
        }
    }

    printf("Command Not Found");
}

#define ESCAPE {free(args); printf("Command Not Found"); return NULL;}
arg_t *args_parse(const char *s)
{
    int argc=strlen(s);
    arg_t *args=(arg_t*)malloc(sizeof(arg_t)*argc);
    int i;
    for(i=0;i<argc;++i) {
        char *tok;
        switch(s[i]) {
            case 's':
                args[i].s = strtok(NULL,delim);
                if(!args[i].s)
                    ESCAPE;
                break;
            case 'c':
                tok = strtok(NULL,delim);
                if(!tok)
                    ESCAPE;
                args[i].c = tok[0];
                if(!islower(args[i].c))
                    ESCAPE;
                break;
            case 'f':
                tok = strtok(NULL,delim);
                if(sscanf(tok,"%f", &args[i].f)!=1)
                    ESCAPE;
                break;
        }
    }
    return args;
}
#undef ESCAPE

//Global data
char prompt[200];
float regs['z'-'a'];
void set_reg(char c, float f) {regs[c-'a'] = f;}
float get_reg(char c) {return regs[c-'a'];}

void cmd_prompt(arg_t *args) {
	sprintf(prompt, "\r\n%s", args[0].s);
}

void cmd_time(arg_t *args) {
	hour = one_ms / 3600000;
	min = (one_ms - hour*3600000) / 60000;
	sec = (one_ms - hour*3600000 - min*60000) / 1000;
	milli = (one_ms - hour*3600000 - min*60000 - sec*1000);

	printf("%02d:%02d:%02d.%d", hour, min, sec, milli);
}

void cmd_start(arg_t *args) {
	SysTick->LOAD = 0xbb78u;
	SysTick->VAL = 0x0u;
	SysTick->CTRL = 0x07u;
}

void cmd_stop(arg_t *args) {
	SysTick->LOAD = 0xbb78u;
	SysTick->VAL = 0x0u;
	SysTick->CTRL = 0x06u;
}

void cmd_reset(arg_t *args) {
	one_ms = 0;
}

void cmd_load(arg_t *args) {set_reg(args[0].c,args[1].f);}

void cmd_disp(arg_t *args) {
	printf("%f", get_reg(args[0].c));
}
void cmd_add(arg_t *args) {
	printf("%f",args[0].f+args[1].f);
}
void cmd_mul(arg_t *args) {
	printf("%f",args[0].f*args[1].f);
}
void cmd_sqrt(arg_t *args) {
	printf("%f",sqrt(args[0].f));
}
void cmd_exit(arg_t *args) {
	printf("%s\r\n", "exiting!\r\n");
	_exit(0);
	printf("%s\r\n", "exited!");
}
void cmd_help(arg_t *args)
{
	printf("Available Commands:\r\n");
    int i=CMDS;
    while(i--) {
        cmd_t cmd=dsp_table[i];
        char tmp[100];//Formatting buffer
        snprintf(tmp,100,"%s(%s)",cmd.name,cmd.args);
        printf("%10s\t- %s\r\n",tmp,cmd.doc);
    }
}
#endif /* COMMAND_PARSER_CPP_ */
