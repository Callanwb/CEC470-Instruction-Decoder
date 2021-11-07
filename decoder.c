/*
CEC 470 Group Project
Decoder
Group Members: Callan Bailey, Benigno Digon, Charles Gilmore

*/

#define HALT_OPCODE 0x19

void fetchNextInstruction(void);
void executeNextInstruction(void);

unsigned char memory[65536];
unsigned char ACC = 0; //16 bit
unsigned char IR = 0;  //8 bit
unsigned char MAR = 0; //16 bit
unsigned char PC = 0;  //8 bit

int main(int argc, char *argv[])
{
    //load memory, maybe make it a function

    while (memory[PC] != HALT_OPCODE)
    {
        fetchNextInstruction();
        executeNextInstruction();
    }
    return 0;
}

void fetchNextInstruction()
{
    //store instruction in IR
    IR = memory[PC];

    //will need to incrememnt PC in this part depending on the instruction, will either increment by 1, 2, 3 bytes

    //using big endian check last spot first

    //math operator
    if ((IR & 0x80) == 0x80)
    {
        //one or two operand
        if ((IR & 0x70) >> 4 <= 4)
        {
            switch (IR & 0x0F)
            {
            //indirect MAR pointer indirect MAR pointer
            case (0b0000):
                PC++;
                break;
            //indirect MAR pointer accumulator ACC
            case (0b0001):
                PC++;
                break;
            //indirect MAR pointer constant
            case (0b0010):
                PC += 2;
                break;
            //indirect MAR pointer memory
            case (0b0011):
                PC += 3;
                break;
            //accumulator ACC indirect MAR pointer
            case (0b0100):
                PC++;
                break;
            //accumulator ACC accumulator ACC
            case (0b0101):
                PC++;
                break;
            //accumulator ACC constant
            case (0b0110):
                PC += 2;
                break;
            //accumulator ACC memory
            case (0b0111):
                PC += 3;
                break;
            //register MAR indirect MAR pointer
            case (0b1000):
                PC++;
                break;
            //register MAR accumulator ACC
            case (0b1001):
                PC++;
                break;
            //register MAR constant
            case (0b1010):
                PC += 2;
                break;
            //regiseter MAR memory
            case (0b1011):
                PC += 3;
                break;
            //memory indirect MAR pointer
            case (0b1100):
                PC += 3;
                break;
            //memory accumulator ACC
            case (0b1101):
                PC += 3;
                break;
            //memory constant
            case (0b1110):
                PC += 4;
                break;
            //memory memory
            case (0b1111):
                PC += 5;
                break;
            }
        }
        //not on register
        else if ((IR & 0x0C) != 0b1100){
            PC++;
        }
        //not on memory
        else{
            PC += 3;
        }
    }
    //memory
    else if ((IR & 0xF0) == 0x0)
    {

        //store
        //load
    }
    //branch function
    else if ((IR & 0xF8) == 0x10)
    {
        //increment PC
    }
    //special or illegal opcode
    else
    {
        //nop
        //halt
        //illegal opcode
    }
}
void executeNextInstruction()
{
    //code here
    //math operations
    // AND 000
    // OR 001
    // XOR 010
    // ADD 011
    // SUB 100
    // INC 101
    // DEC 110
    // NOT 111

    //indirect 00
    //ACC 01
    //MAR 10
    //memory 11

    //source
    //MAR 00
    //ACC 01
    //constant 10
    //memory 11

    //memory operations
    // STORE
    // LOAD

    //branch/jump
    // BRA
    // BRZ
    // BNE
    // BLT
    // BLE
    // BGT
    // BGE

    //special
    // NOP
    // HALT
    // OTHER
}