/* */
// Project: Instruction Decoder
//
// Date: November 11, 2021
//
// Contributers:
//
// Charles Gilmore,
// Benigno Digon,
// Callan Bailey
//
// Project Description:
//

/**************************************************************************************/

// Global Definitions
#define HALT_OPCODE 0x19

// Function Prototypes
void fetchNextInstruction(void);
void executeInstruction(void);

// Global Variables
unsigned char memory[65536];
unsigned char ACC = 0;
unsigned char IR = 0;
unsigned int MAR = 0;
unsigned int PC = 0;

void main(int argc, CHAR *argv[])
{

    while (memory[PC] != HALT_OPCODE)
        fetchNextInstruction();
    executeInstruction();
}