#include "monty.h"

/**
 * get_opcodes - selects correct opcode to run
 * @opc: opcode to run
 * Return: function that executes the opcode
 */

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mult},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	
	int a;

	for (a = 0; instruct[a].opcode; a++)
	{
		if (_strcmp(instruct[a].opcode, opc) == 0)
			break;
	}

	return (instruct[a].f);
}
